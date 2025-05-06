#include "login.h"
#include <QSqlQuery>
#include <QRandomGenerator>
#include <QMessageBox>
#include <QDateTime>
#include <QCryptographicHash>

Login::Login() : codeVerificationEnvoye("") {}

bool Login::verifierUtilisateur(const QString &email, const QString &mdp)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYE WHERE EMAIL = :email AND MDP = :mdp");
    query.bindValue(":email", email);
    query.bindValue(":mdp", mdp);

    if (query.exec() && query.next()) {
        return true; // Utilisateur trouvé, login réussi
    }
    return false; // Identifiants incorrects
}

bool Login::demanderReinitialisationMDP(const QString &email) {
    QSqlQuery query;
    query.prepare("SELECT EMAIL FROM EMPLOYE WHERE EMAIL = :email");
    query.bindValue(":email", email);

    if (!query.exec() || !query.next()) {
        return false; // Email non trouvé
    }

    // Générer et stocker un code de vérification
    codeVerificationEnvoye = genererCodeVerification();

    // Envoyer le code par email (simulation)
    qDebug() << "Code de vérification envoyé à" << email << ":" << codeVerificationEnvoye;

    return true;
}

bool Login::reinitialiserMDP(const QString &email, const QString &nouveauMDP, const QString &codeVerif) {
    if (codeVerif != codeVerificationEnvoye) {
        return false;
    }

    // Hashage du mot de passe
    QString mdpHash = QString(QCryptographicHash::hash(nouveauMDP.toUtf8(), QCryptographicHash::Sha256).toHex());

    QSqlQuery query;
    query.prepare("UPDATE EMPLOYE SET MDP = :mdp WHERE EMAIL = :email");
    query.bindValue(":mdp", mdpHash);
    query.bindValue(":email", email);

    if (query.exec()) {
        codeVerificationEnvoye.clear(); // Invalider le code après utilisation
        return query.numRowsAffected() > 0;
    }
    return false;
}

QString Login::genererCodeVerification() {
    const QString possibleChars = "ABCDEFGHJKLMNPQRSTUVWXYZ23456789";
    QString code;
    for (int i = 0; i < 6; ++i) {
        code += possibleChars.at(QRandomGenerator::global()->bounded(possibleChars.length()));
    }
    return code;
}

