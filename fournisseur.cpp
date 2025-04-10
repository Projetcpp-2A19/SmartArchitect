#include "Fournisseur.h"
#include <QSqlError>
#include <QDebug>

Fournisseur::Fournisseur() {}

Fournisseur::Fournisseur(int id, QString nom, QString telephone, QString adresse, QString ville, QString etat, QString commande, QString email)
    : id_fournisseur(id), nom(nom), telephone(telephone), adresse(adresse), ville(ville), etat(etat), commande(commande), email(email) {}

bool Fournisseur::ajouterFournisseur() {
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Erreur : Connexion à la base de données non ouverte.";
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO FOURNISSEURS (ID_FOURNISSEUR, NOM, TELEPHONE, ADRESSE, VILLE, ETAT, COMMANDE, EMAIL) "
                  "VALUES (FOURNISSEURS_SEQ.NEXTVAL, :nom, :telephone, :adresse, :ville, :etat, :commande, :email)");

    query.bindValue(":nom", nom);
    query.bindValue(":telephone", telephone);
    query.bindValue(":adresse", adresse);
    query.bindValue(":ville", ville);
    query.bindValue(":etat", etat);
    query.bindValue(":commande", commande);
    query.bindValue(":email", email);

    if (!query.exec()) {
        qDebug() << "Erreur d'insertion :" << query.lastError().text();
        return false;
    }
    return true;
}

bool Fournisseur::modifierFournisseur() {
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Erreur : Connexion à la base de données non ouverte.";
        return false;
    }

    QSqlQuery query;
    query.prepare("UPDATE FOURNISSEURS SET NOM=:nom, TELEPHONE=:telephone, ADRESSE=:adresse, "
                  "VILLE=:ville, ETAT=:etat, COMMANDE=:commande, EMAIL=:email WHERE ID_FOURNISSEUR=:id");

    query.bindValue(":id", id_fournisseur);
    query.bindValue(":nom", nom);
    query.bindValue(":telephone", telephone);
    query.bindValue(":adresse", adresse);
    query.bindValue(":ville", ville);
    query.bindValue(":etat", etat);
    query.bindValue(":commande", commande);
    query.bindValue(":email", email);

    if (!query.exec()) {
        qDebug() << "Erreur de mise à jour :" << query.lastError().text();
        return false;
    }
    return true;
}

bool Fournisseur::supprimerFournisseur(int id) {
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Erreur : Connexion à la base de données non ouverte.";
        return false;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM FOURNISSEURS WHERE ID_FOURNISSEUR=:id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur de suppression :" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQueryModel *Fournisseur::afficherFournisseurs() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_FOURNISSEUR, NOM, TELEPHONE, ADRESSE, VILLE, ETAT, COMMANDE, EMAIL FROM FOURNISSEURS");

    if (model->lastError().isValid()) {
        qDebug() << "Erreur affichage : " << model->lastError().text();
    }

    return model;
}
