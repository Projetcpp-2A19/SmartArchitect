#include "serialhandler.h"
#include <QSerialPortInfo>
#include <QDebug>

SerialHandler::SerialHandler(QObject *parent) : QObject(parent)
{
    serial = new QSerialPort(this);
    connect(serial, &QSerialPort::readyRead, this, &SerialHandler::readData);
}

bool SerialHandler::connectToArduino()
{
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if (info.description().contains("Arduino")) {
            serial->setPortName(info.portName());
            if (serial->open(QIODevice::ReadWrite)) {
                serial->setBaudRate(QSerialPort::Baud9600);
                serial->setDataBits(QSerialPort::Data8);
                serial->setParity(QSerialPort::NoParity);
                serial->setStopBits(QSerialPort::OneStop);
                return true;
            }
        }
    }
    return false;
}

void SerialHandler::readData()
{
    while (serial->canReadLine()) {
        QString line = serial->readLine().trimmed();

        if (line.startsWith("#") && line.endsWith("#")) {
            currentUid = line.mid(1, line.length()-2);
            emit badgeDetected(currentUid);

            QSqlQuery query;
            query.prepare("SELECT ID_EMPLOYE, NOM, PRENOM, POSTE FROM EMPLOYE WHERE BADGE_UID = :uid");
            query.bindValue(":uid", currentUid);

            if (query.exec() && query.next()) {
                // Envoyer la commande d'ouverture
                sendCommand("OPEN\n");

                emit accessGranted(
                    query.value("NOM").toString(),
                    query.value("PRENOM").toString(),
                    query.value("POSTE").toString()
                    );
                emit doorOpened(); // Nouveau signal
            } else {
                emit accessDenied(currentUid);
                // NE PAS envoyer la commande OPEN
            }
        }
        else if (line == "DOOR_OPENED") {
            qDebug() << "Porte ouverte avec succès";
        }
    }
}


QString SerialHandler::lastUid() const
{
    return currentUid;
}

void SerialHandler::sendCommand(const QString &command)
{
    if (serial && serial->isOpen()) {
        serial->write(command.toUtf8());
        serial->flush();
    }
}
