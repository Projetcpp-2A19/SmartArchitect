#ifndef EMAILSENDER_H
#define EMAILSENDER_H

#include <QObject>
#include <QSslSocket>

class EmailSender : public QObject
{
    Q_OBJECT
public:
    explicit EmailSender(QObject *parent = nullptr);
    bool sendEmail(const QString &to, const QString &subject, const QString &body);

private:
    QString smtpServer = "smtp.gmail.com";
    int smtpPort = 465; // SSL
    QString senderEmail = "nourhajji297@gmail.com";             // ✅ Ton adresse Gmail
    QString senderPassword = "sszb vrla gmkt vhhc";        // ✅ Mot de passe d'application Gmail
};

#endif // EMAILSENDER_H

