#include "arduino.h"
#include <QDebug>

Arduino::Arduino()
{
    serialPort = new QSerialPort();
}

Arduino::~Arduino()
{
    if (serialPort->isOpen()) {
        serialPort->close();
    }
    delete serialPort;
}

bool Arduino::connectToArduino()
{
    // Check available ports and connect to Arduino
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        qDebug() << "Checking port: " << info.portName();
        if (info.description().contains("Arduino")) {
            serialPort->setPort(info);
            serialPort->setBaudRate(QSerialPort::Baud9600);
            serialPort->setDataBits(QSerialPort::Data8);
            serialPort->setParity(QSerialPort::NoParity);
            serialPort->setStopBits(QSerialPort::OneStop);
            serialPort->setFlowControl(QSerialPort::NoFlowControl);

            if (serialPort->open(QIODevice::WriteOnly)) {
                qDebug() << "Connected to Arduino on port: " << info.portName();
                return true;
            } else {
                qDebug() << "Failed to open serial port.";
            }
        }
    }
    return false;
}


void Arduino::sendArchitectData(const QString& data)
{
    if (serialPort->isOpen()) {
        serialPort->write(data.toUtf8());
        serialPort->write("\n");  // Send newline to signify end of data
    } else {
        qWarning() << "Serial port not open!";
    }
}

void Arduino::closeConnection()
{
    if (serialPort->isOpen()) {
        serialPort->close();
    }
}
