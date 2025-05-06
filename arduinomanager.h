#ifndef ARDUINOMANAGER_H
#define ARDUINOMANAGER_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonObject>

class ArduinoManager : public QObject
{
    Q_OBJECT

public:
    explicit ArduinoManager(QObject *parent = nullptr);
    ~ArduinoManager();

    // Serial port functions
    bool connectToArduino(const QString &portName = "COM3", int baudRate = 9600);
    void disconnectFromArduino();
    bool isConnected() const;
    QStringList getAvailablePorts();

    // Database functions
    bool connectToDatabase(const QString &dbType = "QSQLITE", const QString &hostName = "", const QString &dbName = "fournisseur.db", const QString &userName = "", const QString &password = "");

    // Monitoring functions
    bool isMonitoringActive() const;
    void startMonitoring(int intervalMs = 1000);
    void stopMonitoring();

    // Threshold and fan control
    void setTemperatureThreshold(float threshold); // For general threshold
    void setTemperatureThreshold(int id, double threshold); // For specific sensor/fournisseur
    float getTemperatureThreshold() const;
    double getTemperatureThreshold(int id);
    void setFanSpeed(int speed);

signals:
    void temperatureReceived(double temperature);
    void humidityReceived(double humidity);
    void temperatureChanged(float temperature);
    void humidityChanged(float humidity);
    void errorOccurred(const QString &errorMessage);
    void connectionStatusChanged(bool connected);
    void fanSpeedChanged(int speed);

private slots:
    void readData();
    void handleError(QSerialPort::SerialPortError error);
    void processData();
    void handleReadyRead();

private:
    void parseData(const QByteArray &data);
    void parseSensorData(const QByteArray &data);
    void sendCommand(const QString &command);
    void insertTemperatureIntoDatabase(double temperature);
    void insertHumidityIntoDatabase(double humidity);

    QSerialPort *serialPort;
    QTimer *monitoringTimer;
    QByteArray buffer;
    float temperatureThreshold;
    bool monitoringActive;
    QSqlDatabase db;
    bool fanOn;
};

#endif // ARDUINOMANAGER_H
