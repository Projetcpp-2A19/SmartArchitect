#ifndef ARDUINO_H
#define ARDUINO_H

#include <QSerialPort>
#include <QSerialPortInfo>

class Arduino
{
public:
    Arduino();
    ~Arduino();

    // Methods to connect to Arduino and send data
    bool connectToArduino();
    void sendArchitectData(const QString& data);
    void closeConnection();

private:
    QSerialPort* serialPort;
};

#endif // ARDUINO_H
