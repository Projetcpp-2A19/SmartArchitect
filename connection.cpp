#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("GArchitect");//inserer le nom de la source de données
    db.setUserName("Firas");//inserer nom de l'utilisateur
    db.setPassword("adem1234");//inserer mot de passe de cet utilisateur

    if (db.open())
        test=true;





    return  test;
}
