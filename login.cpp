#include "login.h"

Login::Login() {}

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

