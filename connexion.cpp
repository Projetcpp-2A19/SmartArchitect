#include "connexion.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

Connection* Connection::instance = nullptr;

Connection::Connection()
{
}

Connection* Connection::getInstance()
{
    if(!instance)
    {
        instance = new Connection();
    }
    return instance;
}

bool Connection::createconnect()
{
    bool test = false;

    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("Source_Projet2A");
        db.setUserName("Firas");
        db.setPassword("Firas19503");
    }

    if (db.isOpen()) {
        test = true;
    } else {
        test = db.open();
    }

    if(test) {
        qDebug() << "Connexion réussie!";
    } else {
        qDebug() << "Erreur de connexion: " << db.lastError().text();
    }

    return test;
}
