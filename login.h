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

private:
    QString email;
    QString mdp;
};

#endif // LOGIN_H

