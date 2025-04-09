#include "emailsender.h"
#include <QDebug>
#include <QSslSocket>
#include <QFile>
#include <QFileInfo>
#include <QByteArray>
#include <QMessageBox>

EmailSender::EmailSender(QObject *parent) : QObject(parent) {}

bool EmailSender::sendEmail(const QString &to, const QString &subject, const QString &body, const QString &attachmentPath) {
    QSslSocket socket;

    // Connexion SSL
    socket.connectToHostEncrypted(smtpServer, smtpPort);

    if (!socket.waitForConnected(3000)) {
        qDebug() << "Erreur de connexion au serveur SMTP";
        return false;
    }

    if (!socket.waitForEncrypted(3000)) {
        qDebug() << "Erreur lors de l'établissement de la connexion SSL";
        return false;
    }

    QTextStream stream(&socket);

    // Vérification des réponses SMTP
    auto waitForResponse = [&socket](const QString &errorMsg) -> bool {
        if (!socket.waitForReadyRead(3000)) {
            qDebug() << errorMsg;
            return false;
        }
        QString response = socket.readAll();
        qDebug() << "SMTP Response:" << response;
        if (!response.startsWith("2") && !response.startsWith("3")) {
            qDebug() << "Erreur SMTP:" << response;
            return false;
        }
        return true;
    };

    // Séquence SMTP
    stream << "EHLO localhost\r\n";
    stream.flush();
    if (!waitForResponse("Erreur EHLO")) return false;

    stream << "AUTH LOGIN\r\n";
    stream.flush();
    if (!waitForResponse("Erreur AUTH LOGIN")) return false;

    stream << QByteArray(senderEmail.toUtf8().toBase64()) + "\r\n";
    stream.flush();
    if (!waitForResponse("Erreur email base64")) return false;

    stream << QByteArray(senderPassword.toUtf8().toBase64()) + "\r\n";
    stream.flush();
    if (!waitForResponse("Erreur mot de passe base64")) return false;

    stream << "MAIL FROM:<" + senderEmail + ">\r\n";
    stream.flush();
    if (!waitForResponse("Erreur MAIL FROM")) return false;

    stream << "RCPT TO:<" + to + ">\r\n";
    stream.flush();
    if (!waitForResponse("Erreur RCPT TO")) return false;

    stream << "DATA\r\n";
    stream.flush();
    if (!waitForResponse("Erreur DATA")) return false;

    // Construction du message MIME
    QString boundary = "----QtMailBoundary";
    stream << "MIME-Version: 1.0\r\n";
    stream << "Content-Type: multipart/mixed; boundary=\"" + boundary + "\"\r\n";
    stream << "Subject: " + subject + "\r\n";
    stream << "From: " + senderEmail + "\r\n";
    stream << "To: " + to + "\r\n";
    stream << "\r\n";

    // Partie texte
    stream << "--" + boundary + "\r\n";
    stream << "Content-Type: text/plain; charset=\"UTF-8\"\r\n";
    stream << "\r\n" + body + "\r\n\r\n";

    // Pièce jointe
    if (!attachmentPath.isEmpty()) {
        QFile file(attachmentPath);
        if (file.open(QIODevice::ReadOnly)) {
            QByteArray fileData = file.readAll();
            QString fileName = QFileInfo(file).fileName();
            QString base64File = fileData.toBase64();

            stream << "--" + boundary + "\r\n";
            stream << "Content-Type: application/octet-stream; name=\"" + fileName + "\"\r\n";
            stream << "Content-Transfer-Encoding: base64\r\n";
            stream << "Content-Disposition: attachment; filename=\"" + fileName + "\"\r\n";
            stream << "\r\n";

            // Envoi par blocs de 76 caractères (standard SMTP)
            for (int i = 0; i < base64File.size(); i += 76) {
                stream << base64File.mid(i, 76) + "\r\n";
            }
            stream << "\r\n";
        } else {
            qDebug() << "Impossible d'ouvrir le fichier en pièce jointe.";
            return false;
        }
    }

    // Fin du message
    stream << "--" + boundary + "--\r\n";
    stream << ".\r\n";
    stream.flush();
    if (!waitForResponse("Erreur lors de l'envoi du message")) return false;

    stream << "QUIT\r\n";
    stream.flush();
    socket.waitForReadyRead();

    socket.close();
    return true;
}
