#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

class Connection
{
private:
    QSqlDatabase db; // Base de données (membre privé)

public:
    Connection();  // Constructeur
    ~Connection(); // Destructeur pour fermer la connexion

    bool createconnect();   // Méthode pour ouvrir la connexion
    void closeConnection(); // Méthode pour fermer la connexion
};

#endif // CONNECTION_H
