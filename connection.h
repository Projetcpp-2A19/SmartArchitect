#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>

class Connection
{
public:
    static Connection* getInstance();
    bool createconnect();
    QSqlDatabase getDB();

private:
    Connection();
    static Connection* instance;
    QSqlDatabase db;
};

#endif // CONNECTION_H
