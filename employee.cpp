#include "employee.h"
#include "connexion.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QRegularExpression>

Employee::Employee() {}

Employee::Employee(int IDEMPLOYEE, QString NOM, QString PRENOM, QString EMAIL, QString MDP,
                   QString POSTE, QString SALAIRE, QString DATEEMBOCHE)
{
    this->IDEMPLYEE = IDEMPLOYEE;
    this->NOM= NOM;
    this->PRENOM = PRENOM;
    this->EMAIL = EMAIL;
    this->MDP = MDP;
    this->POSTE= POSTE;
    this->SALAIRE = SALAIRE;
    this->DATEEMBOCHE = DATEEMBOCHE;
}
bool Employee::ajouterEmploye() {
    // ID validation
    if (IDEMPLYEE <= 0 || IDEMPLYEE > 99999) {
        QMessageBox::critical(nullptr, "Validation Error", "Employee ID must be between 1 and 99999.");
        return false;
    }

    // Name validation (alphabetic characters)
    QRegularExpression nameRegex("^[A-Za-zÀ-ÿ\\s]+$");
    if (!nameRegex.match(NOM).hasMatch()) {
        QMessageBox::critical(nullptr, "Validation Error", "Name must contain only letters.");
        return false;
    }
    if (!nameRegex.match(PRENOM).hasMatch()) {
        QMessageBox::critical(nullptr, "Validation Error", "First name must contain only letters.");
        return false;
    }

    // Email validation (improved regex for email format)
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    if (!emailRegex.match(EMAIL).hasMatch()) {
        QMessageBox::critical(nullptr, "Validation Error", "Please enter a valid email address.");
        return false;
    }

    // Password validation (minimum 8 characters)
    if (MDP.length() < 8) {
        QMessageBox::critical(nullptr, "Validation Error",
                              "Password must be at least 8 characters long");
        return false;
    }


    // Position validation
    if (POSTE.length() < 2 || POSTE.length() > 50) {
        QMessageBox::critical(nullptr, "Validation Error", "Position must be between 2 and 50 characters.");
        return false;
    }

    // Salary validation (positive number with max 2 decimal places)
    bool ok;
    double salaire = SALAIRE.toDouble(&ok);
    if (!ok || salaire <= 0 || salaire > 1000000) {
        QMessageBox::critical(nullptr, "Validation Error", "Salary must be a valid number between 0 and 1,000,000.");
        return false;
    }

    // Date validation (YYYY-MM-DD format)
    QRegularExpression dateRegex("^\\d{4}-(?:0[1-9]|1[0-2])-(?:0[1-9]|[12]\\d|3[01])$");
    if (!dateRegex.match(DATEEMBOCHE).hasMatch()) {
        QMessageBox::critical(nullptr, "Validation Error", "Date must be in YYYY-MM-DD format.");
        return false;
    }

    // Database connection check
    QSqlDatabase db = Connection::getInstance()->getDB();
    if (!db.isOpen() && !Connection::getInstance()->createconnect()) {
        QMessageBox::critical(nullptr, "Database Error", "Could not connect to database.");
        return false;
    }

    // Check for duplicate employee ID
    QSqlQuery checkQuery(db);
    checkQuery.prepare("SELECT COUNT(*) FROM NOUR.EMPLOYEE WHERE IDEMPLYEE = :id");
    checkQuery.bindValue(":id", IDEMPLYEE);
    if (checkQuery.exec() && checkQuery.next() && checkQuery.value(0).toInt() > 0) {
        QMessageBox::critical(nullptr, "Validation Error", "Employee ID already exists.");
        return false;
    }

    // Insert query
    QSqlQuery query(db);
    query.prepare("INSERT INTO NOUR.EMPLOYEE (IDEMPLYEE, NOM, PRENOM, EMAIL, MDP, POSTE, SALAIRE, DATEEMBOCHE) "
                  "VALUES (:idemployee, :nom, :prenom, :email, :mdp, :poste, :salaire, :date_embauche)");

    query.bindValue(":idemployee", IDEMPLYEE);
    query.bindValue(":nom", NOM.toUpper());  // Store names in uppercase
    query.bindValue(":prenom", PRENOM.toUpper());
    query.bindValue(":email", EMAIL.toLower());  // Store email in lowercase
    query.bindValue(":mdp", MDP);
    query.bindValue(":poste", POSTE);
    query.bindValue(":salaire", SALAIRE);
    query.bindValue(":date_embauche", DATEEMBOCHE);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Database Error",
                              "Failed to add employee: " + query.lastError().text());
        return false;
    }

    QMessageBox::information(nullptr, "Success", "Employee added successfully.");
    return true;
}
//----------------------------------------------------------------------------------------
bool Employee::modifierEmploye(int IDEMPLYEE, const QString &nom, const QString &email) {
    QSqlDatabase db = Connection::getInstance()->getDB();
    if (!db.isOpen()) {
        qDebug() << "Database is not open!";
        if (!Connection::getInstance()->createconnect()) {
            return false;
        }
        db = Connection::getInstance()->getDB();
    }

    QSqlQuery query(db);
    query.prepare("UPDATE NOUR.EMPLOYEE SET NOM = :nom, EMAIL = :email WHERE IDEMPLYEE = :id");
    query.bindValue(":id", IDEMPLYEE);
    query.bindValue(":nom", nom);
    query.bindValue(":email", email);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification de l'employé:" << query.lastError().text();
        return false;
    }

    qDebug() << "Employé modifié avec succès !";
    return true;
}
//--------------------------------------------------------------------------------------
bool Employee::supprimerEmploye(int IDEMPLYEE) {
    QSqlDatabase db = Connection::getInstance()->getDB();
    if (!db.isOpen()) {
        qDebug() << "Database is not open!";
        if (!Connection::getInstance()->createconnect()) {
            return false;
        }
        db = Connection::getInstance()->getDB();
    }

    QSqlQuery query(db);
    query.prepare("DELETE FROM NOUR.EMPLOYEE WHERE IDEMPLYEE = :id");
    query.bindValue(":id", IDEMPLYEE);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression:" << query.lastError().text();
        return false;
    }

    qDebug() << "Employé supprimé avec succès !";
    return true;
}
//---------------------------------------------------------------------------------------
QSqlQueryModel* Employee::afficherEmployes() {
    QSqlDatabase db = Connection::getInstance()->getDB();
    if (!db.isOpen()) {
        qDebug() << "Database is not open!";
        if (!Connection::getInstance()->createconnect()) {
            return nullptr;
        }
        db = Connection::getInstance()->getDB();
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM NOUR.EMPLOYEE", db);

    if (model->lastError().isValid()) {
        qDebug() << "Error in afficherEmployes:" << model->lastError().text();
        delete model;
        return nullptr;
    }

    return model;
}

bool Employee::updateEmployee(int id, const QString &nom, const QString &prenom,
                              const QString &email, const QString &poste,
                              const QString &salaire, const QString &dateEmbauche) {
    QSqlDatabase db = Connection::getInstance()->getDB();
    if (!db.isOpen()) {
        if (!Connection::getInstance()->createconnect()) {
            return false;
        }
        db = Connection::getInstance()->getDB();
    }

    QSqlQuery query(db);
    query.prepare("UPDATE NOUR.EMPLOYEE SET NOM = :nom, PRENOM = :prenom, "
                  "EMAIL = :email, POSTE = :poste, SALAIRE = :salaire, "
                  "DATEEMBOCHE = :dateEmbauche WHERE IDEMPLYEE = :id");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom.toUpper());
    query.bindValue(":prenom", prenom.toUpper());
    query.bindValue(":email", email.toLower());
    query.bindValue(":poste", poste);
    query.bindValue(":salaire", salaire);
    query.bindValue(":dateEmbauche", dateEmbauche);

    if (!query.exec()) {
        qDebug() << "Update error:" << query.lastError().text();
        return false;
    }

    return true;
}
