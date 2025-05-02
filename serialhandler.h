#ifndef SERIALHANDLER_H
#define SERIALHANDLER_H

#include <QObject>
#include <QSerialPort>
#include <QSqlQuery>

class SerialHandler : public QObject
{
    Q_OBJECT
public:
    explicit SerialHandler(QObject *parent = nullptr);
    bool connectToArduino();
    QString lastUid() const;
    void sendCommand(const QString &command);

signals:
    void accessGranted(QString nom, QString prenom, QString poste);
    void accessDenied(QString uid);
    void doorOpened();
    void badgeDetected(const QString &uid);

private slots:
    void readData();

private:
    QSerialPort *serial;
    QString currentUid;
};

#endif // SERIALHANDLER_H
