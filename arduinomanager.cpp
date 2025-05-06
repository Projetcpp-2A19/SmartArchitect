#include "arduinomanager.h"
#include <QRegularExpression>
#include <QSqlQuery>
#include <QSqlError>

ArduinoManager::ArduinoManager(QObject *parent)
    : QObject(parent)
    , serialPort(new QSerialPort(this))
{
    // Connecter les signaux
    connect(serialPort, &QSerialPort::readyRead, this, &ArduinoManager::handleReadyRead);
    connect(serialPort, &QSerialPort::errorOccurred, this, &ArduinoManager::handleError);
}

ArduinoManager::~ArduinoManager()
{
    if (serialPort->isOpen()) {
        serialPort->close();
    }
    if (db.isOpen()) {
        db.close();
    }
}

bool ArduinoManager::connectToArduino(const QString &portName)
{
    if (serialPort->isOpen()) {
        serialPort->close();
    }

    serialPort->setPortName(portName);
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (serialPort->open(QIODevice::ReadWrite)) {
        qDebug() << "Connecté à Arduino sur le port" << portName;
        return true;
    } else {
        qDebug() << "Erreur de connexion à Arduino:" << serialPort->errorString();
        emit errorOccurred("Erreur de connexion: " + serialPort->errorString());
        return false;
    }
}

void ArduinoManager::disconnectFromArduino()
{
    if (serialPort->isOpen()) {
        serialPort->close();
        qDebug() << "Déconnecté d'Arduino";
    }
}

bool ArduinoManager::connectToDatabase(const QString &dbType, const QString &hostName, const QString &dbName, const QString &userName, const QString &password)
{
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

void ArduinoManager::setTemperatureThreshold(int sensorId, double threshold)
{
    if (!serialPort->isOpen()) {
        emit errorOccurred("Arduino non connecté");
        return;
    }

    // Format: "T:ID:VALUE\n"
    QString command = QString("T:%1:%2\n").arg(sensorId).arg(threshold);
    serialPort->write(command.toUtf8());
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

void ArduinoManager::handleReadyRead()
{
    QByteArray data = serialPort->readAll();
    qDebug() << "\n=== DONNÉES REÇUES DE L'ARDUINO ===";
    qDebug() << "Données brutes:" << data;
    parseData(data);
}

void ArduinoManager::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::NoError) {
        return;
    }

    QString errorMessage = "Erreur de communication: " + serialPort->errorString();
    qDebug() << errorMessage;
    emit errorOccurred(errorMessage);
}

void ArduinoManager::parseData(const QByteArray &data)
{
    QString dataStr = QString::fromUtf8(data);
    qDebug() << "\n=== ANALYSE DES DONNÉES ===";
    qDebug() << "Données converties en texte:" << dataStr;

    QStringList lines = dataStr.split('\n', Qt::SkipEmptyParts);
    qDebug() << "Nombre de lignes à analyser:" << lines.size();

    for (const QString &line : lines) {
        qDebug() << "\nAnalyse de la ligne:" << line;

        // Pour la température
        if (line.contains("Température:")) {
            qDebug() << "Ligne contient 'Température:'";
            QRegularExpression rx("Température:\\s*([0-9.]+)\\s*°C");
            QRegularExpressionMatch match = rx.match(line);
            if (match.hasMatch()) {
                QString valueStr = match.captured(1);
                qDebug() << "Valeur extraite:" << valueStr;
                bool ok;
                double temperature = valueStr.toDouble(&ok);
                if (ok) {
                    qDebug() << "Température convertie avec succès:" << temperature;
                    emit temperatureReceived(temperature);
                    insertTemperatureIntoDatabase(temperature);  // On met à jour pour l'ID 1
                } else {
                    qDebug() << "Erreur de conversion de la température";
                }
            } else {
                qDebug() << "Format de température non reconnu";
            }
        }
        // Pour l'humidité
        else if (line.contains("Humidité:")) {
            qDebug() << "Ligne contient 'Humidité:'";
            QRegularExpression rx("Humidité:\\s*([0-9.]+)\\s*%");
            QRegularExpressionMatch match = rx.match(line);
            if (match.hasMatch()) {
                QString valueStr = match.captured(1);
                qDebug() << "Valeur extraite:" << valueStr;
                bool ok;
                double humidity = valueStr.toDouble(&ok);
                if (ok) {
                    qDebug() << "Humidité convertie avec succès:" << humidity;
                    emit humidityReceived(humidity);
                    insertHumidityIntoDatabase(humidity);  // On met à jour pour l'ID 1
                } else {
                    qDebug() << "Erreur de conversion de l'humidité";
                }
            } else {
                qDebug() << "Format d'humidité non reconnu";
            }
        }
    }
}

void ArduinoManager::insertTemperatureIntoDatabase(double temperature)
{
    // Utiliser la connexion par défaut déjà ouverte par Connection
    QSqlDatabase db = QSqlDatabase::database();

    if (!db.isOpen()) {
        qDebug() << "Erreur : Base de données non ouverte.";
        return;
    }

    QSqlQuery query(db); // Important : passer 'db' ici

    // Afficher la température qui va être insérée pour plus de clarté
    qDebug() << "Tentative de mise à jour de la température:" << temperature;

    // Essayer d'abord de faire un UPDATE
    query.prepare("UPDATE FOURNISSEUR SET TEMPERATURE = :temp WHERE IDFOURNISSEUR = :id");
    query.bindValue(":temp", temperature);
    query.bindValue(":id", 1); // Par exemple ID=1 (à adapter si nécessaire)

    if (!query.exec()) {
        qDebug() << "Erreur SQL (UPDATE échoué) :" << query.lastError().text();

        // Si UPDATE échoue (par exemple ID n'existe pas), essayer un INSERT
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
        qDebug() << "Erreur : Base de données non ouverte.";
        return;
    }

    QSqlQuery query(db); // Passer la connexion ici

    // Mise à jour de l'humidité pour l'IDFOURNISSEUR = 1
    query.prepare("UPDATE FOURNISSEUR SET HUMIDITE = :humidity WHERE IDFOURNISSEUR = 1");
    query.bindValue(":humidity", humidity);

    if (!query.exec()) {
        qDebug() << "Erreur SQL (UPDATE échoué) :" << query.lastError().text();
    } else {
        qDebug() << "Humidité mise à jour dans la base avec succès.";
    }
}
