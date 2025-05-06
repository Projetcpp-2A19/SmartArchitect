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

    // Get the maximum ID and increment it
    QSqlQuery idQuery;
    idQuery.prepare("SELECT COALESCE(MAX(ID_FOURNISSEURS), 0) + 1 AS NEW_ID FROM FOURNISSEURS");
    if (!idQuery.exec() || !idQuery.next()) {
        qDebug() << "Erreur lors de la récupération du nouvel ID :" << idQuery.lastError().text();
        return false;
    }
    int newId = idQuery.value("NEW_ID").toInt();

    QSqlQuery query;
    query.prepare("INSERT INTO FOURNISSEURS (ID_FOURNISSEURS, NOM, TELEPHONE, ADRESSE, VILLE, ETAT, COMMANDE, EMAIL) "
                  "VALUES (:id, :nom, :telephone, :adresse, :ville, :etat, :commande, :email)");

    query.bindValue(":id", newId);
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
    id_fournisseur = newId; // Update the object's ID
    return true;
}

bool Fournisseur::modifierFournisseur() {
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Erreur : Connexion à la base de données non ouverte.";
        return false;
    }

    QSqlQuery query;
    query.prepare("UPDATE FOURNISSEURS SET NOM=:nom, TELEPHONE=:telephone, ADRESSE=:adresse, "
                  "VILLE=:ville, ETAT=:etat, COMMANDE=:commande, EMAIL=:email WHERE ID_FOURNISSEURS=:id");

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
    query.prepare("DELETE FROM FOURNISSEURS WHERE ID_FOURNISSEURS=:id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur de suppression :" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQueryModel *Fournisseur::afficherFournisseurs() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_FOURNISSEURS, NOM, TELEPHONE, ADRESSE, VILLE, ETAT, COMMANDE, EMAIL FROM FOURNISSEURS");

    if (model->lastError().isValid()) {
        qDebug() << "Erreur affichage : " << model->lastError().text();
    }

    return model;
}
