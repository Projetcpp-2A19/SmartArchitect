#include "connection.h"

Connection* Connection::instance = nullptr;

Connection::Connection() {
    db = QSqlDatabase::addDatabase("QODBC", "qt_sql_default_connection");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("chedi"); // Insert user name
    db.setPassword("esprit18"); // Insert password
}

Connection::~Connection() {
    closeConnection();
}

Connection* Connection::getInstance() {
    if (!instance) {
        instance = new Connection();
    }
    return instance;
}

bool Connection::createconnect() {
    if (db.isOpen()) {
        qDebug() << "Database already connected";
        return true;
    }

    qDebug() << "Attempting to connect with DSN:" << db.databaseName();
    qDebug() << "Driver:" << db.driverName();
    qDebug() << "Username:" << db.userName();

    if (db.open()) {
        qDebug() << "Connection successful!";
        return true;
    } else {
        qDebug() << "Database connection error:" << db.lastError().text();
        return false;
    }
}

void Connection::closeConnection() {
    if (db.isOpen()) {
        db.close();
        qDebug() << "Connection closed successfully";
    }
}

bool Connection::updateTemperature(int fournisseurId, double temperature) {
    if (!db.isOpen()) {
        if (!createconnect()) {
            return false;
        }
    }

    QSqlQuery query(db);
    query.prepare("UPDATE FOURNISSEURS SET TEMPERATURE = :temp WHERE IDF = :id");
    query.bindValue(":temp", temperature);
    query.bindValue(":id", fournisseurId);

    if (!query.exec()) {
        qDebug() << "Error updating temperature:" << query.lastError().text();
        return false;
    }

    return true;
}

QSqlDatabase Connection::getDB() {
    return db;
}
