#ifndef PROJETMANAGER_H
#define PROJETMANAGER_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class ProjetManager {
public:
    ProjetManager();
    ProjetManager(int, QString, double, QString, QString, int, QString);

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
};

#endif // PROJETMANAGER_H


