#include "arduino.h"
#include <QDebug>

Arduino::Arduino(QObject *parent) : QObject(parent)
{
    serial = new QSerialPort(this);
    connect(serial, &QSerialPort::readyRead, this, [this]() {
        QString id = QString::fromUtf8(serial->readAll()).trimmed();
        if (!id.isEmpty()) {
            emit idReceived(id); // <--- Émettre le signal quand on reçoit un ID
        }
    });
}

Arduino::~Arduino()
{
    if (serial->isOpen()) {
        serial->close();
    }
}

int Arduino::connectArduino()
{
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if (info.vendorIdentifier() && info.productIdentifier()) {
            serial->setPort(info);
            if (serial->open(QIODevice::ReadWrite)) {
                serial->setBaudRate(QSerialPort::Baud9600);
                serial->setDataBits(QSerialPort::Data8);
                serial->setParity(QSerialPort::NoParity);
                serial->setStopBits(QSerialPort::OneStop);
                serial->setFlowControl(QSerialPort::NoFlowControl);
                return 0; // connecté
            } else {
                return 1; // échec
            }
        }
    }
    return -1; // pas trouvé
}

QString Arduino::readFromArduino()
{
    if (serial->isReadable()) {
        return QString::fromUtf8(serial->readAll());
    }
    return "";
}

int Arduino::writeToArduino(const QByteArray &data)
{
    if (serial->isWritable()) {
        serial->write(data);
        return 0;
    }
    return 1;
}
