#ifndef ARDUINO_H
#define ARDUINO_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

class Arduino : public QObject
{
    Q_OBJECT

public:
    explicit Arduino(QObject *parent = nullptr);
    ~Arduino();
    int connectArduino();
    QString readFromArduino();
    int writeToArduino(const QByteArray &data);
    bool connectToArduino();
    int writeToArduino(const QString &data);



private:
    QSerialPort *serial;

signals:
    void idReceived(const QString &id); // <-- C'est bien ici dans "signals"
};

#endif // ARDUINO_H
