#ifndef LOGIN_H
#define LOGIN_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Login
{
public:
    Login(); // Constructeur

    bool verifierUtilisateur(const QString &email, const QString &mdp); // Vérifier login
    bool demanderReinitialisationMDP(const QString &email);
    bool reinitialiserMDP(const QString &email, const QString &nouveauMDP, const QString &codeVerif);
    QString genererCodeVerification();
private:
    QString email;
    QString mdp;
    QString codeVerificationEnvoye;
};

#endif // LOGIN_H

