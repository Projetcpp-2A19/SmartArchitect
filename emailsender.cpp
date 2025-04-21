#include "emailsender.h"
#include <QTextStream>
#include <QDebug>

EmailSender::EmailSender(QObject *parent) : QObject(parent) {}

bool EmailSender::sendEmail(const QString &to, const QString &subject, const QString &body)
{
    QSslSocket socket;
    socket.connectToHostEncrypted(smtpServer, smtpPort);

    if (!socket.waitForConnected(5000)) {
        qDebug() << "Erreur de connexion au serveur SMTP.";
        return false;
    }

    QTextStream stream(&socket);
    stream.setAutoDetectUnicode(true);

    stream << "EHLO localhost\r\n";
    stream.flush(); socket.waitForReadyRead();

    stream << "AUTH LOGIN\r\n";
    stream.flush(); socket.waitForReadyRead();

    stream << QByteArray(senderEmail.toUtf8()).toBase64() << "\r\n";
    stream.flush(); socket.waitForReadyRead();

    stream << QByteArray(senderPassword.toUtf8()).toBase64() << "\r\n";
    stream.flush(); socket.waitForReadyRead();

    stream << "MAIL FROM:<" << senderEmail << ">\r\n";
    stream.flush(); socket.waitForReadyRead();

    stream << "RCPT TO:<" << to << ">\r\n";
    stream.flush(); socket.waitForReadyRead();

    stream << "DATA\r\n";
    stream.flush(); socket.waitForReadyRead();

    stream << "From: " << senderEmail << "\r\n";
    stream << "To: " << to << "\r\n";
    stream << "Subject: " << subject << "\r\n";
    stream << "\r\n" << body << "\r\n.\r\n";
    stream.flush(); socket.waitForReadyRead();

    stream << "QUIT\r\n";
    stream.flush(); socket.waitForReadyRead();

    qDebug() << "Email envoyé à" << to;
    qDebug() << "Connexion à Gmail...";
    qDebug() << "Objet : " << subject;
    qDebug() << "Contenu : " << body;
    return true;
}

