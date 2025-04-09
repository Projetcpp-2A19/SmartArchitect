#ifndef EMAILSENDER_H
#define EMAILSENDER_H

#include <QObject>
#include <QTcpSocket>
#include <QSslSocket>
#include <QTextStream>

class EmailSender : public QObject {
    Q_OBJECT
public:
    explicit EmailSender(QObject *parent = nullptr);
    bool sendEmail(const QString &to, const QString &subject, const QString &body, const QString &attachmentPath = "");

private:
    QString smtpServer = "smtp.gmail.com";  // Serveur SMTP de Gmail
    int smtpPort = 465;  // Port sécurisé SSL
    QString senderEmail = "benhamoudafiras19@gmail.com";
    QString senderPassword = "pkqh sqeo rggi yerc";  // ⚠️ Utiliser un mot de passe d'application

    bool sendAttachment(QSslSocket &socket, const QString &filePath);
};

#endif // EMAILSENDER_H


