#ifndef PROJETMANAGER_H
#define PROJETMANAGER_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPair>  // Ajout pour QPair

class ProjetManager {
public:
    ProjetManager();
    ProjetManager(int, QString, double, QString, QString, int, QString,
                  double estimated_cost = -1, double actual_cost = -1);  // Valeurs par défaut

    bool ajouterProjet();
    QSqlQueryModel *afficherProjets();
    bool modifierProjet();
    bool supprimerProjet(int id);

private:
    int id_projet;
    QString nom;
    double budget;
    QString date_debut;
    QString date_fin;
    int id_client;
    QString status;
    double estimated_cost;
    double actual_cost;

    // Ajout de la déclaration de la méthode privée
    QPair<double, double> calculateAutoCosts() const;
};

#endif // PROJETMANAGER_H
