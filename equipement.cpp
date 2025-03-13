#include "equipement.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QSqlError>
#include "equipement.h"
#include <QDate>

equipement::equipement(QString nom, int quantite, QString type, QDate datedachat, int budget, QString caracteristiques) {

    this->nom = nom;
    this->quantite = quantite;
    this->type = type;
    this->datedachat = datedachat;
    this->budget = budget;
    this->caracteristiques = caracteristiques;
}

bool equipement::ajouter() {
    QSqlQuery query;



    query.prepare("INSERT INTO EQUIPEMENT (NOM,QUANTITE,TYPE,DATEDACHAT,BUDGET,CARACTERISTIQUES) "
                  "VALUES (:nom,:quantite,:type,:datedachat,:budget,:caracteristiques)");


    query.bindValue(":nom", nom);
    query.bindValue(":quantite", quantite, QSql::In | QSql::In);
    //query.bindValue(":quantité",QVariant (quantite).toInt());
    query.bindValue(":type", type);
    query.bindValue(":datedachat", datedachat);
    //query.bindValue(":budget",QVariant (budget).toDouble());
    query.bindValue(":budget", budget, QSql::In | QSql::In);
    query.bindValue(":caracteristiques", caracteristiques);

    qDebug() << "🔍 Requête SQL préparée :" << query.lastQuery();
    qDebug() << "🔢 Valeurs bindées :";
    qDebug() << "   - Nom           :" << nom;
    qDebug() << "   - Quantité      :" << quantite;
    qDebug() << "   - Type          :" << type;
    qDebug() << "   - Date d'achat  :" << datedachat.toString("yyyy-MM-dd");
    qDebug() << "   - Budget        :" << budget;
    qDebug() << "   - Caractéristiques :" << caracteristiques;
    qDebug() << "Type de datedachat envoyé :" << datedachat;
    qDebug() << "Requête SQL préparée :" << query.lastQuery();


    if (!query.exec()) {
        qDebug() << "❌ Erreur d'insertion :" << query.lastError().text();
        return false;
    }

    qDebug() << "✅ Insertion réussie !";
    return true;

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout dans la base:" << query.lastError().text();
        return false;
    }

    return true;

    return query.exec();
}


bool equipement::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM EQUIPEMENT WHERE ID_EQUIPEMENT = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "❌ Erreur de suppression : " << query.lastError().text();
        return false;
    }

    qDebug() << "✅ Suppression réussie de l'équipement avec ID :" << id;
    return true;

}
QSqlQueryModel* equipement::afficher() {
    // Création d'un modèle pour la requête SQL
    QSqlQueryModel* model = new QSqlQueryModel();

    // Exécution de la requête SQL pour récupérer toutes les lignes de la table EQUIPEMENT
    model->setQuery("SELECT * FROM EQUIPEMENT");

    // Vérification si la requête a échoué
    if (model->lastError().isValid()) {
        qDebug() << "Erreur de la requête : " << model->lastError().text();
        return nullptr;  // Retourne nullptr en cas d'erreur
    }

    // Définir les en-têtes des colonnes (optionnel mais utile pour avoir des titres visibles)
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EQUIPEMENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEDACHAT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("BUDGET"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("CARACTERISTIQUES"));

    return model;  // Retourne le modèle avec les données récupérées
}
bool equipement::modifier(int id, QString nom, int quantite, QString type, QDate datedachat, int budget, QString caracteristiques) {
    QSqlQuery query;
    query.prepare("UPDATE EQUIPEMENT SET NOM = :nom, QUANTITE = :quantite, TYPE = :type, "
                  "DATEDACHAT = :datedachat, BUDGET = :budget, CARACTERISTIQUES = :caracteristiques "
                  "WHERE ID_EQUIPEMENT = :id");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":quantite", quantite);
    query.bindValue(":type", type);
    query.bindValue(":datedachat", datedachat);
    query.bindValue(":budget", budget);
    query.bindValue(":caracteristiques", caracteristiques);

    if (!query.exec()) {
        qDebug() << "❌ Erreur de mise à jour :" << query.lastError().text();
        return false;
    }

    qDebug() << "✅ Mise à jour réussie !";
    return true;
}

