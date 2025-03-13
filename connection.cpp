#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

connection::connection() {}

bool connection::createconnect() {
    bool test = false;
    QString connectionName = "qt_sql_default_connection";

    // Check if the connection already exists
    if (QSqlDatabase::contains(connectionName)) {
        QSqlDatabase db = QSqlDatabase::database(connectionName);

        // Close the existing connection
        db.close();

        // Remove the connection from the database connection list
        QSqlDatabase::removeDatabase(connectionName);
        qDebug() << "Old connection removed.";
    }

    // Create a new connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", connectionName);
    db.setDatabaseName("Source_export");
    db.setUserName("wissem"); // Insert user name
    db.setPassword("esprit18"); // Insert password

    // Open the new connection
    if (db.open()) {
        test = true;
        qDebug() << "Database connected successfully!";
    } else {
        qDebug() << "Error: connection with database failed";
        qDebug() << db.lastError().text();
    }

    return test;
}
