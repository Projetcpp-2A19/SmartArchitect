#include "arduinomanager.h"
#include <QRegularExpression>
#include <QDebug>

ArduinoManager::ArduinoManager(QObject *parent)
    : QObject(parent)
    , serialPort(new QSerialPort(this))
    , monitoringTimer(new QTimer(this))
    , temperatureThreshold(30.0f)
    , monitoringActive(false)
    , fanOn(false)
{
    connect(serialPort, &QSerialPort::readyRead, this, &ArduinoManager::readData);
    connect(serialPort, &QSerialPort::errorOccurred, this, &ArduinoManager::handleError);
    connect(monitoringTimer, &QTimer::timeout, this, &ArduinoManager::processData);
}

ArduinoManager::~ArduinoManager()
{
    disconnectFromArduino();
    if (db.isOpen()) {
        db.close();
    }
}

bool ArduinoManager::connectToArduino(const QString &portName, int baudRate)
{
    if (serialPort->isOpen()) {
        serialPort->close();
    }

    serialPort->setPortName(portName);
    serialPort->setBaudRate(baudRate);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (serialPort->open(QIODevice::ReadWrite)) {
        qDebug() << "Connecté à Arduino sur le port" << portName;
        emit connectionStatusChanged(true);
        return true;
    } else {
        QString errorMessage = tr("Impossible d'ouvrir le port %1: %2").arg(portName).arg(serialPort->errorString());
        qDebug() << errorMessage;
        emit errorOccurred(errorMessage);
        emit connectionStatusChanged(false);
        return false;
    }
}

void ArduinoManager::disconnectFromArduino()
{
    if (serialPort->isOpen()) {
        stopMonitoring();
        serialPort->close();
        qDebug() << "Déconnecté d'Arduino";
        emit connectionStatusChanged(false);
    }
}

bool ArduinoManager::isConnected() const
{
    return serialPort->isOpen();
}

QStringList ArduinoManager::getAvailablePorts()
{
    QStringList ports;
    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &portInfo : serialPortInfos) {
        ports << portInfo.portName();
    }
    return ports;
}

bool ArduinoManager::connectToDatabase(const QString &dbType, const QString &hostName, const QString &dbName, const QString &userName, const QString &password)
{
    if (db.isOpen()) {
        db.close();
    }

    db = QSqlDatabase::addDatabase(dbType);
    db.setHostName(hostName);
    db.setDatabaseName(dbName);
    db.setUserName(userName);
    db.setPassword(password);

    if (!db.open()) {
        qDebug() << "Erreur de connexion à la base de données:" << db.lastError().text();
        emit errorOccurred("Erreur DB: " + db.lastError().text());
        return false;
    }

    qDebug() << "Connexion à la base de données réussie.";
    return true;
}

bool ArduinoManager::isMonitoringActive() const
{
    return monitoringActive;
}

void ArduinoManager::startMonitoring(int intervalMs)
{
    if (!serialPort->isOpen()) {
        emit errorOccurred(tr("Impossible de démarrer la surveillance: port non connecté"));
        return;
    }

    monitoringTimer->start(intervalMs);
    monitoringActive = true;
}

void ArduinoManager::stopMonitoring()
{
    monitoringTimer->stop();
    monitoringActive = false;
}

void ArduinoManager::setFanSpeed(int speed)
{
    if (!serialPort->isOpen()) {
        emit errorOccurred(tr("Impossible de définir la vitesse du ventilateur: port non connecté"));
        return;
    }

    speed = qBound(0, speed, 255);
    QString command = QString("FAN:%1\n").arg(speed, 3, 10, QChar('0'));
    sendCommand(command);
    emit fanSpeedChanged(speed);
}

void ArduinoManager::setTemperatureThreshold(float threshold)
{
    temperatureThreshold = threshold;
    QString command = QString("SET_THRESHOLD:1:%1\n").arg(threshold);
    sendCommand(command);
    qDebug() << "Nouveau seuil de température défini:" << temperatureThreshold;
}

void ArduinoManager::setTemperatureThreshold(int id, double threshold)
{
    if (serialPort->isOpen()) {
        QString command = QString("T:%1:%2\n").arg(id).arg(threshold);
        sendCommand(command);
    }

    if (db.isOpen()) {
        QSqlQuery query(db);
        query.prepare("UPDATE FOURNISSEUR SET TEMPERATURE_THRESHOLD = :threshold WHERE IDFOURNISSEUR = :id");
        query.bindValue(":threshold", threshold);
        query.bindValue(":id", id);

        if (!query.exec()) {
            qDebug() << "Erreur lors de la mise à jour du seuil de température:" << query.lastError().text();
            emit errorOccurred("Erreur DB: " + query.lastError().text());
        }
    }
}

float ArduinoManager::getTemperatureThreshold() const
{
    return temperatureThreshold;
}

double ArduinoManager::getTemperatureThreshold(int id)
{
    if (db.isOpen()) {
        QSqlQuery query(db);
        query.prepare("SELECT TEMPERATURE_THRESHOLD FROM FOURNISSEUR WHERE IDFOURNISSEUR = :id");
        query.bindValue(":id", id);

        if (query.exec() && query.next()) {
            return query.value(0).toDouble();
        }
    }
    return 30.0; // Default value
}

void ArduinoManager::readData()
{
    if (!serialPort->isOpen()) {
        return;
    }

    QByteArray data = serialPort->readAll();
    buffer.append(data);
    qDebug() << "Données brutes reçues:" << buffer;

    int newlineIndex = buffer.indexOf('\n');
    while (newlineIndex != -1) {
        QByteArray line = buffer.left(newlineIndex);
        buffer = buffer.mid(newlineIndex + 1);
        parseSensorData(line);
        newlineIndex = buffer.indexOf('\n');
    }
}

void ArduinoManager::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::NoError) {
        return;
    }

    QString errorMessage = tr("Erreur de communication: %1").arg(serialPort->errorString());
    qDebug() << errorMessage;
    emit errorOccurred(errorMessage);

    if (serialPort->isOpen()) {
        serialPort->close();
        emit connectionStatusChanged(false);
    }
}

void ArduinoManager::processData()
{
    if (!serialPort->isOpen()) {
        return;
    }

    sendCommand("READ\n");
}

void ArduinoManager::handleReadyRead()
{
    QByteArray data = serialPort->readAll();
    qDebug() << "Données brutes reçues (handleReadyRead):" << data;
    parseData(data);
}

void ArduinoManager::sendCommand(const QString &command)
{
    if (!serialPort->isOpen()) {
        return;
    }

    serialPort->write(command.toUtf8());
}

void ArduinoManager::parseData(const QByteArray &data)
{
    QString dataStr = QString::fromUtf8(data);
    QStringList lines = dataStr.split('\n', Qt::SkipEmptyParts);

    for (const QString &line : lines) {
        if (line.contains("Température:")) {
            QRegularExpression rx("Température:\\s*([0-9.]+)\\s*°C");
            QRegularExpressionMatch match = rx.match(line);
            if (match.hasMatch()) {
                bool ok;
                double temperature = match.captured(1).toDouble(&ok);
                if (ok) {
                    emit temperatureReceived(temperature);
                    insertTemperatureIntoDatabase(temperature);
                }
            }
        } else if (line.contains("Humidité:")) {
            QRegularExpression rx("Humidité:\\s*([0-9.]+)\\s*%");
            QRegularExpressionMatch match = rx.match(line);
            if (match.hasMatch()) {
                bool ok;
                double humidity = match.captured(1).toDouble(&ok);
                if (ok) {
                    emit humidityReceived(humidity);
                    insertHumidityIntoDatabase(humidity);
                }
            }
        }
    }
}

void ArduinoManager::parseSensorData(const QByteArray &data)
{
    // Try JSON format first
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);

    if (parseError.error == QJsonParseError::NoError) {
        QJsonObject obj = doc.object();
        if (obj.contains("temperature")) {
            float temperature = obj["temperature"].toDouble();
            emit temperatureChanged(temperature);
            insertTemperatureIntoDatabase(temperature);
            if (temperature > temperatureThreshold) {
                setFanSpeed(255);
            } else {
                setFanSpeed(0);
            }
        }
        if (obj.contains("humidity")) {
            float humidity = obj["humidity"].toDouble();
            emit humidityChanged(humidity);
            insertHumidityIntoDatabase(humidity);
        }
        return;
    }

    // Fallback to text-based parsing
    QString strLine = QString::fromUtf8(data).trimmed();
    QRegularExpression tempRx("Temp[ée]rature\\s*:\\s*([\\d\\.]+)");
    QRegularExpression humRx("Humidit[ée]\\s*:\\s*([\\d\\.]+)");

    QRegularExpressionMatch matchTemp = tempRx.match(strLine);
    if (matchTemp.hasMatch()) {
        float temperature = matchTemp.captured(1).toFloat();
        emit temperatureChanged(temperature);
        insertTemperatureIntoDatabase(temperature);
        if (temperature > temperatureThreshold) {
            setFanSpeed(255);
        } else {
            setFanSpeed(0);
        }
        return;
    }

    QRegularExpressionMatch matchHum = humRx.match(strLine);
    if (matchHum.hasMatch()) {
        float humidity = matchHum.captured(1).toFloat();
        emit humidityChanged(humidity);
        insertHumidityIntoDatabase(humidity);
        return;
    }
}

void ArduinoManager::insertTemperatureIntoDatabase(double temperature)
{
    if (!db.isOpen()) {
        connectToDatabase();
    }

    QSqlQuery query(db);
    query.prepare("UPDATE FOURNISSEUR SET TEMPERATURE = :temp WHERE IDFOURNISSEUR = :id");
    query.bindValue(":temp", temperature);
    query.bindValue(":id", 1);

    if (!query.exec()) {
        query.prepare("INSERT INTO FOURNISSEUR (IDFOURNISSEUR, TEMPERATURE) VALUES (:id, :temp)");
        query.bindValue(":id", 1);
        query.bindValue(":temp", temperature);
        if (!query.exec()) {
            qDebug() << "Erreur SQL (INSERT échoué) :" << query.lastError().text();
        } else {
            qDebug() << "Succès : Température insérée dans la base.";
        }
    } else {
        qDebug() << "Succès : Température mise à jour dans la base.";
    }
}

void ArduinoManager::insertHumidityIntoDatabase(double humidity)
{
    if (!db.isOpen()) {
        connectToDatabase();
    }

    QSqlQuery query(db);
    query.prepare("UPDATE FOURNISSEUR SET HUMIDITE = :humidity WHERE IDFOURNISSEUR = 1");
    query.bindValue(":humidity", humidity);

    if (!query.exec()) {
        qDebug() << "Erreur SQL (UPDATE échoué) :" << query.lastError().text();
    } else {
        qDebug() << "Succès : Humidité mise à jour dans la base.";
    }
}
