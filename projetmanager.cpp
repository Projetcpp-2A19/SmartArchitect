#include "projetmanager.h"
#include <QSqlQuery>
#include <QVariant>
#include <QRandomGenerator>
#include <QDebug>
#include <QSqlError>

// Constructeur par défaut
ProjetManager::ProjetManager() : id_projet(-1), nom(""), budget(0), date_debut(""), date_fin(""), id_client(0), status(""), estimated_cost(0), actual_cost(0) {}

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
    // Get the maximum ID and increment it
    QSqlQuery idQuery;
    idQuery.prepare("SELECT COALESCE(MAX(ID_PROJET), 0) + 1 AS NEW_ID FROM PROJET");
    if (!idQuery.exec() || !idQuery.next()) {
        qCritical() << "Erreur lors de la récupération du nouvel ID :" << idQuery.lastError().text();
        return false;
    }
    int newId = idQuery.value("NEW_ID").toInt();

    // Calcul automatique si valeurs négatives
    auto [finalEstimated, finalActual] = (estimated_cost < 0 || actual_cost < 0)
                                             ? calculateAutoCosts()
                                             : qMakePair(estimated_cost, actual_cost);

    QSqlQuery query;
    query.prepare("INSERT INTO PROJET (ID_PROJET, NOM, BUDGET, DATE_DEBUT, DATE_FIN, ID_CLIENT, STATUS, ESTIMATED_COST, ACTUAL_COST) "
                  "VALUES (:id, :nom, :budget, TO_DATE(:date_debut, 'YYYY-MM-DD'), TO_DATE(:date_fin, 'YYYY-MM-DD'), "
                  ":id_client, :status, :estimated, :actual)");

    query.bindValue(":id", newId);
    query.bindValue(":nom", nom);
    query.bindValue(":budget", budget);
    query.bindValue(":date_debut", date_debut);
    query.bindValue(":date_fin", date_fin);
    query.bindValue(":id_client", id_client);
    query.bindValue(":status", status);
    query.bindValue(":estimated", finalEstimated);
    query.bindValue(":actual", finalActual);

    if (!query.exec()) {
        qCritical() << "Erreur d'ajout:" << query.lastError().text();
        return false;
    }

    id_projet = newId; // Update the object's ID
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
