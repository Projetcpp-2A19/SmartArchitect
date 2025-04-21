#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
public:
    static Connection* getInstance();
    bool createconnect();
    QSqlDatabase getDB() { return db; }

private:
    Connection();
    static Connection* instance;
    QSqlDatabase db;
};
#endif // CONNEXION_H
