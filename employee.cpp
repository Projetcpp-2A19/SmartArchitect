#include "employee.h"
#include "connexion.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QRegularExpression>

Employee::Employee() {}

Employee::Employee(int ID_EMPLOYE, QString NOM, QString PRENOM, QString EMAIL, QString MDP,
                   QString POSTE, QString SALAIRE, QString DATEEMBOCHE)
{
    this->ID_EMPLOYE = ID_EMPLOYE;
    this->NOM = NOM;
    this->PRENOM = PRENOM;
    this->EMAIL = EMAIL;
    this->MDP = MDP;
    this->POSTE = POSTE;
    this->SALAIRE = SALAIRE;
    this->DATEEMBOCHE = DATEEMBOCHE;
}

bool Employee::ajouterEmploye() {
    // Validation de l'ID
    if (ID_EMPLOYE <= 0 || ID_EMPLOYE > 99999) {
        QMessageBox::critical(nullptr, "Erreur de validation", "L'ID employé doit être entre 1 et 99999.");
        return false;
    }

    // Validation du nom (caractères alphabétiques)
    QRegularExpression nameRegex("^[A-Za-zÀ-ÿ\\s]+$");
    if (!nameRegex.match(NOM).hasMatch()) {
        QMessageBox::critical(nullptr, "Erreur de validation", "Le nom ne doit contenir que des lettres.");
        return false;
    }
    if (!nameRegex.match(PRENOM).hasMatch()) {
        QMessageBox::critical(nullptr, "Erreur de validation", "Le prénom ne doit contenir que des lettres.");
        return false;
    }

    // Validation de l'email
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    if (!emailRegex.match(EMAIL).hasMatch()) {
        QMessageBox::critical(nullptr, "Erreur de validation", "Veuillez entrer une adresse email valide.");
        return false;
    }

    // Validation du mot de passe
    if (MDP.length() < 8) {
        QMessageBox::critical(nullptr, "Erreur de validation", "Le mot de passe doit contenir au moins 8 caractères.");
        return false;
    }

    // Validation du poste
    if (POSTE.length() < 2 || POSTE.length() > 50) {
        QMessageBox::critical(nullptr, "Erreur de validation", "Le poste doit contenir entre 2 et 50 caractères.");
        return false;
    }

    // Validation du salaire
    bool ok;
    double salaire = SALAIRE.toDouble(&ok);
    if (!ok || salaire <= 0 || salaire > 1000000) {
        QMessageBox::critical(nullptr, "Erreur de validation", "Le salaire doit être un nombre valide entre 0 et 1,000,000.");
        return false;
    }

    // Validation de la date
    QRegularExpression dateRegex("^\\d{4}-(?:0[1-9]|1[0-2])-(?:0[1-9]|[12]\\d|3[01])$");
    if (!dateRegex.match(DATEEMBOCHE).hasMatch()) {
        QMessageBox::critical(nullptr, "Erreur de validation", "La date doit être au format YYYY-MM-DD.");
        return false;
    }

    // Connexion à la base de données
    QSqlDatabase db = Connection::getInstance()->getDB();
    if (!db.isOpen() && !Connection::getInstance()->createconnect()) {
        QMessageBox::critical(nullptr, "Erreur de base de données", "Connexion à la base de données échouée.");
        return false;
    }

    // Vérification des doublons d'ID
    QSqlQuery checkQuery(db);
    checkQuery.prepare("SELECT COUNT(*) FROM FIRAS.EMPLOYE WHERE ID_EMPLOYE = :id");
    checkQuery.bindValue(":id", ID_EMPLOYE);
    if (checkQuery.exec() && checkQuery.next() && checkQuery.value(0).toInt() > 0) {
        QMessageBox::critical(nullptr, "Erreur de validation", "Cet ID employé existe déjà.");
        return false;
    }

    // Insertion dans la base de données
    QSqlQuery query(db);
    query.prepare("INSERT INTO FIRAS.EMPLOYE (ID_EMPLOYE, NOM, PRENOM, EMAIL, MDP, POSTE, SALAIRE, DATEEMBOCHE) "
                  "VALUES (:idemployee, :nom, :prenom, :email, :mdp, :poste, :salaire, :date_embauche)");

    query.bindValue(":idemployee", ID_EMPLOYE);
    query.bindValue(":nom", NOM.toUpper());
    query.bindValue(":prenom", PRENOM.toUpper());
    query.bindValue(":email", EMAIL.toLower());
    query.bindValue(":mdp", MDP);
    query.bindValue(":poste", POSTE);
    query.bindValue(":salaire", SALAIRE);
    query.bindValue(":date_embauche", DATEEMBOCHE);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Erreur de base de données", "Échec de l'ajout de l'employé: " + query.lastError().text());
        return false;
    }

    QMessageBox::information(nullptr, "Succès", "Employé ajouté avec succès.");
    return true;
}
//-----------------------------------------------------------------------
bool Employee::modifierEmploye(int ID_EMPLOYE, const QString &nom, const QString &email) {
    QSqlDatabase db = Connection::getInstance()->getDB();
    if (!db.isOpen()) {
        qDebug() << "La base de données n'est pas ouverte!";
        if (!Connection::getInstance()->createconnect()) {
            return false;
        }
        db = Connection::getInstance()->getDB();
    }

    QSqlQuery query(db);
    query.prepare("UPDATE FIRAS.EMPLOYE SET NOM = :nom, EMAIL = :email WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", ID_EMPLOYE);
    query.bindValue(":nom", nom);
    query.bindValue(":email", email);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification:" << query.lastError().text();
        return false;
    }

    qDebug() << "Employé modifié avec succès!";
    return true;
}
//--------------------------------------------------------------------------
bool Employee::supprimerEmploye(int IDEMPLYEE) {
    QSqlDatabase db = Connection::getInstance()->getDB();
    if (!db.isOpen()) {
        qDebug() << "La base de données n'est pas ouverte!";
        if (!Connection::getInstance()->createconnect()) {
            return false;
        }
        db = Connection::getInstance()->getDB();
    }

    QSqlQuery query(db);
    query.prepare("DELETE FROM FIRAS.EMPLOYE WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", IDEMPLYEE);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression:" << query.lastError().text();
        return false;
    }

    qDebug() << "Employé supprimé avec succès!";
    return true;
}
//---------------------------------------------------------------------
QSqlQueryModel* Employee::afficherEmployes() {
    QSqlDatabase db = Connection::getInstance()->getDB();
    if (!db.isOpen()) {
        qDebug() << "La base de données n'est pas ouverte!";
        if (!Connection::getInstance()->createconnect()) {
            return nullptr;
        }
        db = Connection::getInstance()->getDB();
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM FIRAS.EMPLOYE", db);

    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de l'affichage:" << model->lastError().text();
        delete model;
        return nullptr;
    }

    return model;
}
//---------------------------------------------------------------
QSqlQueryModel* Employee::trierEmployesParSalaireCroissant() {
    QSqlDatabase db = Connection::getInstance()->getDB();
    if (!db.isOpen()) {
        qDebug() << "La base de données n'est pas ouverte!";
        if (!Connection::getInstance()->createconnect()) {
            return nullptr;
        }
        db = Connection::getInstance()->getDB();
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    QString queryStr = "SELECT * FROM FIRAS.EMPLOYE ORDER BY TO_NUMBER(SALAIRE) ASC";
    model->setQuery(queryStr, db);

    if (model->lastError().isValid()) {
        qDebug() << "Erreur SQL:" << model->lastError().text();
        delete model;
        return nullptr;
    }

    return model;
}
//-----------------------------------------------------------------------------
QSqlQueryModel* Employee::rechercherEmployee(const QString &idOuNom) {
    QSqlDatabase db = Connection::getInstance()->getDB();
    if (!db.isOpen() && !Connection::getInstance()->createconnect()) {
        return nullptr;
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    bool isNumber;
    int id = idOuNom.toInt(&isNumber);

    if (isNumber) {
        // Recherche par ID
        model->setQuery(QString("SELECT * FROM FIRAS.EMPLOYE WHERE ID_EMPLOYE = %1").arg(id), db);
    } else {
        // Recherche par nom
        QString queryStr = "SELECT * FROM FIRAS.EMPLOYE WHERE UPPER(NOM) LIKE UPPER('%"+idOuNom+"%') OR UPPER(PRENOM) LIKE UPPER('%"+idOuNom+"%')";
        model->setQuery(queryStr, db);
    }

    if (model->lastError().isValid()) {
        qDebug() << "Erreur de recherche:" << model->lastError().text();
        delete model;
        return nullptr;
    }

    return model;
}
//-----------------------------------------------------------------------------
bool Employee::updateEmployee(int id, const QString &nom, const QString &prenom,
                              const QString &email, const QString &mdp,
                              const QString &poste, const QString &salaire,
                              const QString &dateEmbauche) {
    QSqlDatabase db = Connection::getInstance()->getDB();
    if (!db.isOpen()) {
        if (!Connection::getInstance()->createconnect()) {
            return false;
        }
        db = Connection::getInstance()->getDB();
    }

    QSqlQuery query(db);
    query.prepare("UPDATE FIRAS.EMPLOYE SET NOM = :nom, PRENOM = :prenom, "
                  "EMAIL = :email, MDP = :mdp, POSTE = :poste, SALAIRE = :salaire, "
                  "DATEEMBOCHE = :dateEmbauche WHERE ID_EMPLOYE = :id");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom.toUpper());
    query.bindValue(":prenom", prenom.toUpper());
    query.bindValue(":email", email.toLower());
    query.bindValue(":mdp", mdp);
    query.bindValue(":poste", poste);
    query.bindValue(":salaire", salaire);
    query.bindValue(":dateEmbauche", dateEmbauche);

    if (!query.exec()) {
        qDebug() << "Erreur de mise à jour:" << query.lastError().text();
        return false;
    }

    return true;
}
//---------------------------------------------------------------------------------------
QMap<QString, int> Employee::getStatsByPoste() {
    QMap<QString, int> stats;
    QSqlDatabase db = Connection::getInstance()->getDB();

    if (!db.isOpen() && !Connection::getInstance()->createconnect()) {
        return stats;
    }

    QSqlQuery query(db);
    query.prepare("SELECT POSTE, COUNT(*) FROM FIRAS.EMPLOYE GROUP BY POSTE");

    if (query.exec()) {
        while (query.next()) {
            QString poste = query.value(0).toString();
            int count = query.value(1).toInt();
            stats.insert(poste, count);
        }
    } else {
        qDebug() << "Erreur lors de la récupération des statistiques:" << query.lastError().text();
    }

    return stats;
}
