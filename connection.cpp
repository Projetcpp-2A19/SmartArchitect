#include "connection.h"

Connection::Connection() {
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A"); // Nom de la source de données
    db.setUserName("hayder"); // Nom d'utilisateur
    db.setPassword("esprit18"); // Mot de passe
}

Connection::~Connection() {
    closeConnection(); // Assurez-vous que la connexion est bien fermée lors de la destruction
}

bool Connection::createconnect() {
    if (db.open()) {
        qDebug() << "Connexion réussie à la base de données";
        return true;
    } else {
        qDebug() << "Erreur: Connexion à la base de données échouée" << db.lastError().text();
        return false;
    }
}

void Connection::closeConnection() {
    if (db.isOpen()) {
        db.close();
        qDebug() << "Connexion fermée avec succès";
    }
}
