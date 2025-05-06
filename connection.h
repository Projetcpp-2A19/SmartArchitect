#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

class Connection
{
public:
    static Connection* getInstance();
    bool createconnect();
    void closeConnection();
    bool updateTemperature(int fournisseurId, double temperature);
    QSqlDatabase getDB();
    ~Connection();

private:
    Connection();
    static Connection* instance;
    QSqlDatabase db;
};

#endif // CONNECTION_H
