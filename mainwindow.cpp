#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "architecte.h"  // Include the architecte class
#include <QMessageBox>   // Include QMessageBox for message dialogs
#include <QSqlError>    // Required for lastError()
#include <QDebug>        // Required for qDebug() to output errors


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Ensure that the table is populated as soon as the window is created
    QSqlQueryModel* model = Etmp.afficher();  // Fetch the data from the database
    if (model) {
        ui->tableView->setModel(model);  // Set the model to the table view
    } else {
        qDebug() << "Failed to load data for the table.";
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_7_clicked()
{
    // Retrieve values from UI
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString telephoneStr = ui->lineEdit_telephone->text();
    QString email = ui->lineEdit_email->text();
    QString experience = ui->lineEdit_experience->text();

    // Validate telephone: should be exactly 8 digits
    if (telephoneStr.length() != 8 || !telephoneStr.toInt()) {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
        return;  // Stop the execution if validation fails
    }

    // Validate email: should contain '@'
    if (!email.contains('@')) {
        QMessageBox::warning(this, "Erreur", "L'adresse email doit contenir '@'.");
        return;  // Stop the execution if validation fails
    }

    // Convert telephone string to integer for the architect object
    int telephone = telephoneStr.toInt();

    // Create architect object (ID is auto-incremented, so pass 0)
    architecte unArchitecte(0, nom, prenom, telephone, email, experience);

    // Try to insert the new architect
    bool ajoutRéussi = unArchitecte.ajouter();

    // Show success or failure message
    if (ajoutRéussi) {
        // Refresh the table view after successful insertion
        ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(this, "Succès", "Architecte ajouté avec succès !");
    } else {
        QMessageBox::warning(this, "Erreur", "L'ajout de l'architecte a échoué.");
    }
}





void MainWindow::on_pushButton_8_clicked()
{
    QString idStr = ui->lineEdit_supprimer->text();  // Retrieve the input from the line edit

    // Check if the input is empty or not numeric
    bool isNumeric;
    int id = idStr.toInt(&isNumeric);  // Convert the text to an integer and check if the conversion was successful

    if (!isNumeric || id <= 0) {  // Check if the ID is a valid number and greater than 0
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;  // Stop the execution if validation fails
    }

    // Proceed with the deletion if ID is valid
    bool test = Etmp.supprimer(id);

    if (test) {
        // Refresh the table view after deletion
        ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(this, "Succès", "Suppression effectuée !");
    } else {
        QMessageBox::critical(this, "Erreur", "Suppression non effectuée.");
    }
}




bool isUpdateMode = false;  // Flag to track whether we're in view or update mode

void MainWindow::on_pushButton_update_clicked()
{
    int id = ui->lineEdit_update->text().toInt();

    if (!isUpdateMode) {
        // Check if the ID exists in the database
        QSqlQuery query;
        query.prepare("SELECT * FROM ARCHITECTES WHERE ID = :id");
        query.bindValue(":id", id);
        if (query.exec()) {
            if (query.next()) {
                // Populate the fields with the existing architect details
                ui->lineEdit_nomu->setText(query.value("NOM").toString());
                ui->lineEdit_prenomu->setText(query.value("PRENOM").toString());
                ui->lineEdit_telephoneu->setText(QString::number(query.value("TELEPHONE").toInt()));
                ui->lineEdit_emailu->setText(query.value("EMAIL").toString());
                ui->lineEdit_experienceu->setText(query.value("EXPERIENCE").toString());

                // Enable fields for update
                ui->lineEdit_nomu->setEnabled(true);
                ui->lineEdit_prenomu->setEnabled(true);
                ui->lineEdit_telephoneu->setEnabled(true);
                ui->lineEdit_emailu->setEnabled(true);
                ui->lineEdit_experienceu->setEnabled(true);

                // Change button text to "Mettre à jour"
                ui->pushButton_update->setText("Mettre à jour");

                QMessageBox::information(this, "Succès", "Architecte trouvé ! Vous pouvez maintenant mettre à jour.");
                isUpdateMode = true;
            } else {
                QMessageBox::warning(this, "Erreur", "Aucun architecte trouvé avec cet ID.");
            }
        } else {
            qDebug() << "Erreur de récupération des données : " << query.lastError().text();
        }
    } else {
        // Retrieve values from UI for update
        QString nom = ui->lineEdit_nomu->text();
        QString prenom = ui->lineEdit_prenomu->text();
        QString telephoneStr = ui->lineEdit_telephoneu->text();
        QString email = ui->lineEdit_emailu->text();
        QString experience = ui->lineEdit_experienceu->text();

        // Validate telephone: should be exactly 8 digits
        if (telephoneStr.length() != 8 || !telephoneStr.toInt()) {
            QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
            return;  // Stop the execution if validation fails
        }

        // Validate email: should contain '@'
        if (!email.contains('@')) {
            QMessageBox::warning(this, "Erreur", "L'adresse email doit contenir '@'.");
            return;  // Stop the execution if validation fails
        }

        // Convert telephone string to integer
        int telephone = telephoneStr.toInt();

        // Update the architect in the database
        QSqlQuery query;
        query.prepare("UPDATE ARCHITECTES SET NOM = :nom, PRENOM = :prenom, TELEPHONE = :telephone, EMAIL = :email, EXPERIENCE = :experience WHERE ID = :id");

        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":telephone", telephone);
        query.bindValue(":email", email);
        query.bindValue(":experience", experience);
        query.bindValue(":id", id);

        if (query.exec()) {
            // Refresh the table view after update
            ui->tableView->setModel(Etmp.afficher());

            // Reset UI state
            ui->lineEdit_nomu->setEnabled(false);
            ui->lineEdit_prenomu->setEnabled(false);
            ui->lineEdit_telephoneu->setEnabled(false);
            ui->lineEdit_emailu->setEnabled(false);
            ui->lineEdit_experienceu->setEnabled(false);
            ui->pushButton_update->setText("Mettre à jour");

            QMessageBox::information(this, "Succès", "Architecte mis à jour avec succès !");
            isUpdateMode = false;
        } else {
            QMessageBox::warning(this, "Erreur", "La mise à jour a échoué.");
        }
    }
}




void MainWindow::on_pushButton_pdf_clicked() {
    int id = ui->lineEdit_supprimer->text().toInt();
    if (Etmp.genererPDF(id)) {
        QMessageBox::information(this, "Succès", "PDF généré avec succès !");
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible de générer le PDF.");
    }
}


void MainWindow::on_pushButton_search_clicked()
{
    QString searchName = ui->lineEdit_search->text();  // Get the name from a text field

    // Check if the search term is not empty
    if (!searchName.isEmpty()) {
        QSqlQueryModel* model = Etmp.searchByName(searchName);
        ui->tableView->setModel(model);  // Set the search results to the table view
    } else {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un nom à rechercher.");
    }
}


void MainWindow::on_pushButton_sort_clicked()
{
    // Call the sorting function to get the sorted list
    QSqlQueryModel* sortedModel = Etmp.trierParNom();
    ui->tableView->setModel(sortedModel);  // Display sorted results in the table view
}

