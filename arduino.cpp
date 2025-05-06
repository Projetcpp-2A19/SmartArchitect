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
bool Arduino::connectToArduino()
{
    if (!serial) {
        serial = new QSerialPort(this);
    }

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        qDebug() << "Port trouvé: " << info.portName();
        qDebug() << "Description: " << info.description();
        qDebug() << "Fabricant: " << info.manufacturer();
        qDebug() << "Identifiant Produit: " << info.productIdentifier();
        qDebug() << "Identifiant Vendeur: " << info.vendorIdentifier();

        // Vérifie si c'est probablement un Arduino
        if (info.description().toLower().contains("arduino") ||
            info.manufacturer().toLower().contains("arduino") ||
            info.vendorIdentifier() == 0x2341 || // Arduino LLC
            info.vendorIdentifier() == 0x1A86 || // WCH (CH340/341)
            info.vendorIdentifier() == 0x10C4)   // Silicon Labs (CP210x)
        {
            serial->setPort(info);
            if (serial->open(QIODevice::ReadWrite)) {
                serial->setBaudRate(QSerialPort::Baud9600);
                serial->setDataBits(QSerialPort::Data8);
                serial->setParity(QSerialPort::NoParity);
                serial->setStopBits(QSerialPort::OneStop);
                serial->setFlowControl(QSerialPort::NoFlowControl);

                qDebug() << "Connexion réussie avec Arduino sur le port:" << info.portName();
                return true;
            } else {
                qDebug() << "Échec de l'ouverture du port série:" << serial->errorString();
                return false;
            }
        }
    }

    qDebug() << "Aucun Arduino détecté automatiquement.";
    return false;
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
int Arduino::writeToArduino(const QString &data)
{
    if (serial->isWritable()) {
        serial->write((data + "\n").toUtf8());  // Important: ajouter \n ici
        return 0;
    }
    return 1;
}
