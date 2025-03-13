#include "architecte.h"
#include <QSqlError>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>


architecte::architecte(int id, QString nom, QString prenom, int telephone, QString email, QString experience) {
    this->id = id;
    this->nom = nom;
    this->prenom = prenom;
    this->telephone = telephone;
    this->email = email;
    this->experience = experience;
}


bool architecte::ajouter()
{
    QSqlQuery query;
    QString newID;

    // Step 1: Query the maximum existing ID in the table to generate a new ID
    query.prepare("SELECT MAX(ID) FROM ARCHITECTES");
    if (query.exec()) {
        if (query.next()) {
            int maxID = query.value(0).toInt();
            newID = QString::number(maxID + 1);  // Generate new ID by incrementing the maximum ID
        }
    } else {
        qDebug() << "Erreur de récupération du max ID : " << query.lastError().text();
        return false;
    }

    // Step 2: Prepare the query to insert a new architect with the new generated ID
    query.prepare("INSERT INTO ARCHITECTES (ID, PRENOM, NOM, TELEPHONE, EMAIL, EXPERIENCE) "
                  "VALUES (:id, :nom, :prenom, :telephone, :email, :experience)");

    query.bindValue(":id", newID);  // Use the newly generated ID
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":telephone", telephone);
    query.bindValue(":email", email);
    query.bindValue(":experience", experience);

    // Step 3: Execute the query to insert the new record
    if (query.exec()) {
        return true;  // Insertion successful
    } else {
        qDebug() << "Erreur d'ajout : " << query.lastError().text();
        return false;  // Insertion failed
    }
}



QSqlQueryModel * architecte::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from ARCHITECTES");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("telephone"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("experience"));

    return model;


}
bool architecte::supprimer(int id)
{
    QSqlQuery query;

    // Prepare the query to delete from the correct table (ARCHITECTES)
    query.prepare("DELETE FROM ARCHITECTES WHERE ID = :id");

    // Bind the integer value directly
    query.bindValue(":id", id);

    // Execute the query and return the result
    return query.exec();
}
bool architecte::mettreAJour()
{
    QSqlQuery query;

    // Prepare the query to update the architect's data in the database
    query.prepare("UPDATE ARCHITECTES SET NOM = :nom, PRENOM = :prenom, TELEPHONE = :telephone, "
                  "EMAIL = :email, EXPERIENCE = :experience WHERE ID = :id");

    // Bind the values to the query
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":telephone", telephone);
    query.bindValue(":email", email);
    query.bindValue(":experience", experience);

    // Execute the query and check if it was successful
    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur de mise à jour : " << query.lastError().text();
        return false;
    }
}

bool architecte::genererPDF(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM ARCHITECTES WHERE ID = :id");
    query.bindValue(":id", id);

    if (!query.exec() || !query.next()) {
        qDebug() << "Erreur: Aucun architecte trouvé avec cet ID.";
        return false;
    }

    QString nom = query.value("NOM").toString();
    QString prenom = query.value("PRENOM").toString();
    int telephone = query.value("TELEPHONE").toInt();
    QString email = query.value("EMAIL").toString();
    QString experience = query.value("EXPERIENCE").toString();

    QString filePath = QFileDialog::getSaveFileName(nullptr, "Enregistrer le PDF", "architecte.pdf", "PDF Files (*.pdf)");
    if (filePath.isEmpty()) {
        return false;
    }

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);

    QPainter painter(&printer);
    if (!painter.isActive()) {
        qDebug() << "Erreur lors de l'initialisation du fichier PDF.";
        return false;
    }

    painter.setFont(QFont("Arial", 14));
    painter.drawText(100, 100, "Fiche Architecte");
    painter.drawText(100, 600, "ID: " + QString::number(id));
    painter.drawText(100, 900, "Nom: " + nom);
    painter.drawText(100, 1200, "Prénom: " + prenom);
    painter.drawText(100, 1500, "Téléphone: " + QString::number(telephone));
    painter.drawText(100, 1800, "Email: " + email);
    painter.drawText(100, 2100, "Expérience: " + experience);

    painter.end();
    return true;
}

QSqlQueryModel* architecte::searchByName(const QString& name)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM ARCHITECTES WHERE NOM LIKE :name OR PRENOM LIKE :name");
    query.bindValue(":name", "%" + name + "%");  // Use % for partial matching

    QSqlQueryModel* model = new QSqlQueryModel();
    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Telephone"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Experience"));
    } else {
        qDebug() << "Erreur de recherche : " << query.lastError().text();
    }
    return model;
}

QSqlQueryModel* architecte::trierParNom()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM ARCHITECTES ORDER BY NOM ASC");  // Sorting alphabetically by NOM (ascending)

    QSqlQueryModel* model = new QSqlQueryModel();
    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Telephone"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Experience"));
    } else {
        qDebug() << "Erreur de tri : " << query.lastError().text();
    }
    return model;
}
