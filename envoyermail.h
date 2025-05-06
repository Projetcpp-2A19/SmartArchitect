#ifndef ENVOYERMAIL_H
#define ENVOYERMAIL_H

#include <QObject>
#include <QSslSocket>

class EnvoyerMail : public QObject
{
    Q_OBJECT
public:
    explicit EnvoyerMail(QObject *parent = nullptr);
    bool sendEmail(const QString &to, const QString &subject, const QString &body);

private:
    QString smtpServer = "smtp.gmail.com";
    int smtpPort = 465; // SSL
    QString senderEmail = "benhamoudafiras19@gmail.com";
    QString senderPassword = "iwti bbvu tutl uqty";
};

#endif // ENVOYERMAIL_H
