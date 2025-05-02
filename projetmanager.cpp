#include "projetmanager.h"
#include <QSqlQuery>
#include <QVariant>
#include <QRandomGenerator>
#include <QDebug>
#include <QSqlError>
// Constructeur par défaut
ProjetManager::ProjetManager() {}

// Constructeur avec paramètres
ProjetManager::ProjetManager(int id, QString nom, double budget, QString debut,
                             QString fin, int client, QString status,
                             double estimated_cost, double actual_cost) :
    id_projet(id),
    nom(nom),
    budget(budget),
    date_debut(debut),
    date_fin(fin),
    id_client(client),
    status(status),
    estimated_cost(estimated_cost),
    actual_cost(actual_cost)
{}

// Méthode privée de calcul automatique
QPair<double, double> ProjetManager::calculateAutoCosts() const {
    // Estimation = 75-85% du budget
    double estimated = budget * (0.75 + QRandomGenerator::global()->generateDouble() * 0.1);

    // Coût réel = 85-115% du budget
    double actual = budget * (0.85 + QRandomGenerator::global()->generateDouble() * 0.3);

    return {estimated, actual};
}

bool ProjetManager::ajouterProjet() {
    // Calcul automatique si valeurs négatives
    auto [finalEstimated, finalActual] = (estimated_cost < 0 || actual_cost < 0)
                                             ? calculateAutoCosts()
                                             : qMakePair(estimated_cost, actual_cost);

    QSqlQuery query;
    query.prepare("INSERT INTO PROJET (NOM, BUDGET, DATE_DEBUT, DATE_FIN, ID_CLIENT, STATUS, ESTIMATED_COST, ACTUAL_COST) "
                  "VALUES (:nom, :budget, TO_DATE(:date_debut, 'YYYY-MM-DD'), TO_DATE(:date_fin, 'YYYY-MM-DD'), "
                  ":id_client, :status, :estimated, :actual)");

    query.bindValue(":nom", nom);
    query.bindValue(":budget", budget);
    query.bindValue(":date_debut", date_debut);
    query.bindValue(":date_fin", date_fin);
    query.bindValue(":id_client", id_client);
    query.bindValue(":status", status);
    query.bindValue(":estimated", finalEstimated);
    query.bindValue(":actual", finalActual);

    if(!query.exec()) {
        qCritical() << "Erreur d'ajout:" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQueryModel *ProjetManager::afficherProjets() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_PROJET, NOM, BUDGET, "
                    "TO_CHAR(DATE_DEBUT, 'YYYY-MM-DD') as DATE_DEBUT, "
                    "TO_CHAR(DATE_FIN, 'YYYY-MM-DD') as DATE_FIN, "
                    "ID_CLIENT, STATUS, ESTIMATED_COST, ACTUAL_COST "
                    "FROM PROJET");
    return model;
}

bool ProjetManager::modifierProjet() {
    QSqlQuery query;
    query.prepare("UPDATE PROJET SET "
                  "NOM = :nom, "
                  "BUDGET = :budget, "
                  "DATE_DEBUT = TO_DATE(:date_debut, 'YYYY-MM-DD'), "
                  "DATE_FIN = TO_DATE(:date_fin, 'YYYY-MM-DD'), "
                  "ID_CLIENT = :id_client, "
                  "STATUS = :status, "
                  "ESTIMATED_COST = :estimated, "
                  "ACTUAL_COST = :actual "
                  "WHERE ID_PROJET = :id");

    query.bindValue(":id", id_projet);
    query.bindValue(":nom", nom);
    query.bindValue(":budget", budget);
    query.bindValue(":date_debut", date_debut);
    query.bindValue(":date_fin", date_fin);
    query.bindValue(":id_client", id_client);
    query.bindValue(":status", status);
    query.bindValue(":estimated", estimated_cost);
    query.bindValue(":actual", actual_cost);

    return query.exec();
}

bool ProjetManager::supprimerProjet(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM PROJET WHERE ID_PROJET = :id");
    query.bindValue(":id", id);
    return query.exec();
}
