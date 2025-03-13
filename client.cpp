#include "client.h"
#include <QString>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>  // Ajout de l'en-tête pour QSqlError
#include <QSqlQuery>

Client::Client() {}

Client::Client(QString nom, QString prenom, QString region, QString telephone, QString email)
{
    this->nom = nom;
    this->prenom = prenom;
    this->region = region;
    this->telephone = telephone;
    this->email = email;
}
void Client::afficherDansTableWidget(QTableWidget *tableWidget)
{
    tableWidget->clearContents();
    tableWidget->setRowCount(0); // Réinitialise

    QSqlQuery query("SELECT * FROM clients");
    int row = 0;
    while (query.next()) {
        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("ID").toString()));
        tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("NOM").toString()));
        tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("PRENOM").toString()));
        tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("REGION").toString()));
        tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("TELEPHONE").toString()));
        tableWidget->setItem(row, 5, new QTableWidgetItem(query.value("EMAIL").toString()));
        row++;
    }
}

Client Client::recupererClient(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM clients WHERE ID=:id");
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
        return Client(
            id,
            query.value("NOM").toString(),
            query.value("PRENOM").toString(),
            query.value("REGION").toString(),
            query.value("TELEPHONE").toString(),
            query.value("EMAIL").toString()
            );
    }
    return Client(); // Retourne vide si rien trouvé
}

Client::Client(int id, QString nom, QString prenom, QString region, QString telephone, QString email)
{
    this->id = id;
    this->nom = nom;
    this->prenom = prenom;
    this->region = region;
    this->telephone = telephone;
    this->email = email;
}

bool Client::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO clients (NOM, PRENOM, REGION, TELEPHONE, EMAIL) "
                  "VALUES (:nom, :prenom, :region, :telephone, :email)");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":region", region);
    query.bindValue(":telephone", telephone);
    query.bindValue(":email", email);

    // Exécution de la requête
    if (query.exec()) {
        return true;  // Si l'insertion réussit
    } else {
        qDebug() << "Erreur SQL : " << query.lastError().text();  // Affiche l'erreur si l'insertion échoue
        return false;
    }
}

bool Client::modifier(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE clients SET NOM=:nom, PRENOM=:prenom, REGION=:region, TELEPHONE=:telephone, EMAIL=:email WHERE ID=:id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":region", region);
    query.bindValue(":telephone", telephone);
    query.bindValue(":email", email);
    return query.exec();
}

bool Client::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM clients WHERE ID=:id");
    query.bindValue(":id", id);
    return query.exec();
}

QSqlQueryModel * Client::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM clients");
    return model;
}



