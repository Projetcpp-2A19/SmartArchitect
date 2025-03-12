#include "projetmanager.h"
#include <QSqlQuery>
#include <QVariant>

// Constructeurs
ProjetManager::ProjetManager() {}

ProjetManager::ProjetManager(int id, QString nom, double budget, QString debut, QString fin, int client, QString status) {
    this->id_projet = id;
    this->nom = nom;
    this->budget = budget;
    this->date_debut = debut;
    this->date_fin = fin;
    this->id_client = client;
    this->status = status;
}

// Ajouter un projet
bool ProjetManager::ajouterProjet() {
    QSqlQuery query;
    query.prepare("INSERT INTO PROJETS (NOM, BUDGET, DATE_DEBUT, DATE_FIN, ID_CLIENT, STATUS) "
                  "VALUES (:nom, :budget, TO_DATE(:date_debut, 'YYYY-MM-DD'), TO_DATE(:date_fin, 'YYYY-MM-DD'), :id_client, :status)");
    query.bindValue(":nom", nom);
    query.bindValue(":budget", budget);
    query.bindValue(":date_debut", date_debut); // Assurez-vous que date_debut est au format YYYY-MM-DD
    query.bindValue(":date_fin", date_fin);     // Assurez-vous que date_fin est au format YYYY-MM-DD
    query.bindValue(":id_client", id_client);
    query.bindValue(":status", status);

    return query.exec();
}

// Afficher les projets
QSqlQueryModel *ProjetManager::afficherProjets() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM PROJETS");
    return model;
}

// Modifier un projet
bool ProjetManager::modifierProjet() {
    QSqlQuery query;
    query.prepare("UPDATE PROJETS SET NOM=:nom, BUDGET=:budget, DATE_DEBUT=TO_DATE(:date_debut, 'YYYY-MM-DD'), DATE_FIN=TO_DATE(:date_fin, 'YYYY-MM-DD'), "
                  "ID_CLIENT=:id_client, STATUS=:status WHERE ID_PROJET=:id");
    query.bindValue(":id", id_projet);
    query.bindValue(":nom", nom);
    query.bindValue(":budget", budget);
    query.bindValue(":date_debut", date_debut); // Assurez-vous que date_debut est au format YYYY-MM-DD
    query.bindValue(":date_fin", date_fin);     // Assurez-vous que date_fin est au format YYYY-MM-DD
    query.bindValue(":id_client", id_client);
    query.bindValue(":status", status);

    return query.exec();
}

// Supprimer un projet
bool ProjetManager::supprimerProjet(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM PROJETS WHERE ID_PROJET=:id");
    query.bindValue(":id", id);
    return query.exec();
}
