#ifndef PROJETMANAGER_H
#define PROJETMANAGER_H

#include <QString>
#include <QSqlQueryModel>

class ProjetManager {
public:
    ProjetManager();
    ProjetManager(int id, QString nom, double budget, QString debut,
                  QString fin, int client, QString status,
                  double estimated_cost = -1, double actual_cost = -1);
    bool ajouterProjet();
    QSqlQueryModel* afficherProjets();
    bool modifierProjet();
    bool supprimerProjet(int id);

private:
    QPair<double, double> calculateAutoCosts() const;

    int id_projet;
    QString nom;
    double budget;
    QString date_debut;
    QString date_fin;
    int id_client;
    QString status;
    double estimated_cost;
    double actual_cost;
};

#endif // PROJETMANAGER_H
