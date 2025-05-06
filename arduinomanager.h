#ifndef ARDUINOMANAGER_H
#define ARDUINOMANAGER_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class ArduinoManager : public QObject
{
    Q_OBJECT

public:
    explicit ArduinoManager(QObject *parent = nullptr);
    ~ArduinoManager();

    bool connectToArduino(const QString &portName);
    void disconnectFromArduino();
    bool connectToDatabase(const QString &dbType, const QString &hostName, const QString &dbName, const QString &userName, const QString &password);
    void setTemperatureThreshold(int sensorId, double threshold);
    QStringList getAvailablePorts();

signals:
    void temperatureReceived(double temperature);
    void humidityReceived(double humidity);
    void errorOccurred(const QString &error);

private slots:
    void handleReadyRead();
    void handleError(QSerialPort::SerialPortError error);

private:
    void parseData(const QByteArray &data);
    void insertTemperatureIntoDatabase(double temperature);
    void insertHumidityIntoDatabase(double humidity);

    QSerialPort *serialPort;
    QSqlDatabase db;
};

#endif // ARDUINOMANAGER_H
