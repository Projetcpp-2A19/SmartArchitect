#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

Connection* Connection::instance = nullptr;

Connection::Connection()
{
}

Connection* Connection::getInstance()
{
    if (!instance)
    {
        instance = new Connection();
    }
    return instance;
}

bool Connection::createconnect()
{
    // Add the QODBC driver
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        db = QSqlDatabase::addDatabase("QODBC", "qt_sql_default_connection");

        // Option 1: Use a pre-configured DSN (Data Source Name)
        db.setDatabaseName("Source_Projet2A"); // Your DSN name

        // Option 2: Use a DSN-less connection string (uncomment and configure if DSN fails)
        // Example for SQL Server:
        // db.setDatabaseName("Driver={ODBC Driver 18 for SQL Server};Server=localhost;Database=Projet2A;Uid=ines;Pwd=zamankii;");
        // Example for MySQL:
        // db.setDatabaseName("Driver={MySQL ODBC 8.0 Unicode Driver};Server=localhost;Database=Projet2A;User=ines;Password=zamankii;");

        // Set username and password (required for SQL Server authentication with DSN, or DSN-less)
        db.setUserName("ines");
        db.setPassword("zamankii");

        // Optionally set host (uncomment if using DSN-less and needed)
        // db.setHostName("localhost");
    }

    // Debug: Print connection details
    qDebug() << "Attempting to connect with DSN:" << db.databaseName();
    qDebug() << "Driver:" << db.driverName();
    qDebug() << "Username:" << db.userName();

    // Attempt to open the database
    if (db.open())
    {
        qDebug() << "Connection successful!";
        return true;
    }
    else
    {
        qDebug() << "Database connection error:" << db.lastError().text();
        return false;
    }
}

QSqlDatabase Connection::getDB()
{
    return db;
}
