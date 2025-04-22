#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Fournisseur {
private:
    int id_fournisseur;
    QString nom, telephone, adresse, ville, etat, commande, email;

public:
    Fournisseur();
    Fournisseur(int id, QString nom, QString telephone, QString adresse, QString ville, QString etat, QString commande, QString email);

    bool ajouterFournisseur();
    bool modifierFournisseur();
    bool supprimerFournisseur(int id);
    QSqlQueryModel *afficherFournisseurs();
};

#endif // FOURNISSEUR_H

