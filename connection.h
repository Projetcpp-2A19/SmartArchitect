#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>

class connection
{
    QSqlDatabase db;
public:
    connection();
    bool createconnect();
    void closeConnection();
};

#endif // CONNECTION_H



