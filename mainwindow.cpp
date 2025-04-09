#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "architecte.h"  // Include the architecte class
#include <QMessageBox>   // Include QMessageBox for message dialogs
#include <QSqlError>    // Required for lastError()
#include <QDebug>        // Required for qDebug() to output errors

#include <QSqlQuery>

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>


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
    // Récupérer les valeurs depuis l'interface
    QString nom = ui->lineEdit_nom->text().trimmed();
    QString prenom = ui->lineEdit_prenom->text().trimmed();
    QString telephoneStr = ui->lineEdit_telephone->text().trimmed();
    QString email = ui->lineEdit_email->text().trimmed();
    QString experience = ui->lineEdit_experience->text().trimmed();

    // Contrôle de saisie : Nom et Prénom
    QRegularExpression regexNomPrenom("^[A-Za-zÀ-ÿ\\s'-]+$");  // Lettres, espaces, accents, tirets
    if (nom.isEmpty() || !regexNomPrenom.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un nom valide (lettres uniquement).");
        return;
    }

    if (prenom.isEmpty() || !regexNomPrenom.match(prenom).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un prénom valide (lettres uniquement).");
        return;
    }

    // Contrôle de saisie : Téléphone (exactement 8 chiffres)
    if (telephoneStr.length() != 8 || !telephoneStr.toUInt()) {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
        return;
    }

    // Contrôle de saisie : Email
    if (!email.contains('@') || !email.contains('.')) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une adresse email valide.");
        return;
    }

    // Contrôle de saisie : Expérience
    if (experience.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une expérience.");
        return;
    }

    // Convertir téléphone
    int telephone = telephoneStr.toInt();

    // Créer un objet architecte
    architecte unArchitecte(0, nom, prenom, telephone, email, experience);

    // Essayer d'ajouter à la base
    bool ajoutRéussi = unArchitecte.ajouter();

    if (ajoutRéussi) {
        ui->tableView->setModel(Etmp.afficher());  // Rafraîchir l'affichage
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
void MainWindow::on_pushButton_update_2_clicked()
{
    QString idStr = ui->lineEdit_supprimer->text();
    bool ok;
    int id = idStr.toInt(&ok);

    if (!ok || id <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }

    QDialog updateDialog(this);
    updateDialog.setWindowTitle("Mettre à jour l'architecte");

    QLineEdit *lineEditNom = new QLineEdit(&updateDialog);
    QLineEdit *lineEditPrenom = new QLineEdit(&updateDialog);
    QLineEdit *lineEditTelephone = new QLineEdit(&updateDialog);
    QLineEdit *lineEditEmail = new QLineEdit(&updateDialog);
    QLineEdit *lineEditExperience = new QLineEdit(&updateDialog);

    QSqlQuery query;
    query.prepare("SELECT * FROM ARCHITECTES WHERE ID = :id");
    query.bindValue(":id", id);
    if (!(query.exec() && query.next())) {
        QMessageBox::warning(this, "Erreur", "Impossible de charger les données.");
        return;
    }

    QString oldNom = query.value("NOM").toString();
    QString oldPrenom = query.value("PRENOM").toString();
    QString oldTel = query.value("TELEPHONE").toString();
    QString oldEmail = query.value("EMAIL").toString();
    QString oldExp = query.value("EXPERIENCE").toString();

    lineEditNom->setText(oldNom);
    lineEditPrenom->setText(oldPrenom);
    lineEditTelephone->setText(oldTel);
    lineEditEmail->setText(oldEmail);
    lineEditExperience->setText(oldExp);

    QPushButton *updateButton = new QPushButton("Mettre à jour", &updateDialog);
    QPushButton *cancelButton = new QPushButton("Annuler", &updateDialog);

    QFormLayout *formLayout = new QFormLayout();
    formLayout->addRow("Nom", lineEditNom);
    formLayout->addRow("Prénom", lineEditPrenom);
    formLayout->addRow("Téléphone", lineEditTelephone);
    formLayout->addRow("Email", lineEditEmail);
    formLayout->addRow("Expérience", lineEditExperience);
    formLayout->addRow(updateButton, cancelButton);

    updateDialog.setLayout(formLayout);

    QObject::connect(updateButton, &QPushButton::clicked, this, [this, &updateDialog, id, lineEditNom, lineEditPrenom, lineEditTelephone, lineEditEmail, lineEditExperience, oldNom, oldPrenom, oldTel, oldEmail, oldExp]() {
        QMap<QString, QVariant> updateFields;
        QRegularExpression regexNomPrenom("^[A-Za-zÀ-ÿ\\s'-]+$");

        QString newNom = lineEditNom->text().trimmed();
        if (newNom != oldNom && !newNom.isEmpty()) {
            if (!regexNomPrenom.match(newNom).hasMatch()) {
                QMessageBox::warning(&updateDialog, "Erreur", "Nom invalide (lettres uniquement).");
                return;
            }
            updateFields["NOM"] = newNom;
        }

        QString newPrenom = lineEditPrenom->text().trimmed();
        if (newPrenom != oldPrenom && !newPrenom.isEmpty()) {
            if (!regexNomPrenom.match(newPrenom).hasMatch()) {
                QMessageBox::warning(&updateDialog, "Erreur", "Prénom invalide (lettres uniquement).");
                return;
            }
            updateFields["PRENOM"] = newPrenom;
        }

        QString newTel = lineEditTelephone->text().trimmed();
        if (newTel != oldTel && !newTel.isEmpty()) {
            if (newTel.length() != 8 || !newTel.toUInt()) {
                QMessageBox::warning(&updateDialog, "Erreur", "Téléphone invalide (8 chiffres).");
                return;
            }
            updateFields["TELEPHONE"] = newTel;
        }

        QString newEmail = lineEditEmail->text().trimmed();
        if (newEmail != oldEmail && !newEmail.isEmpty()) {
            if (!newEmail.contains('@') || !newEmail.contains('.')) {
                QMessageBox::warning(&updateDialog, "Erreur", "Email invalide.");
                return;
            }
            updateFields["EMAIL"] = newEmail;
        }

        QString newExp = lineEditExperience->text().trimmed();
        if (newExp != oldExp && !newExp.isEmpty()) {
            updateFields["EXPERIENCE"] = newExp;
        }

        if (updateFields.isEmpty()) {
            QMessageBox::information(&updateDialog, "Info", "Aucune modification détectée ou tous les champs sont vides.");
            return;
        }

        QStringList setClauses;
        QSqlQuery updateQuery;
        for (auto it = updateFields.begin(); it != updateFields.end(); ++it) {
            setClauses << QString("%1 = :%1").arg(it.key());
        }

        QString queryString = "UPDATE ARCHITECTES SET " + setClauses.join(", ") + " WHERE ID = :id";
        updateQuery.prepare(queryString);

        for (auto it = updateFields.begin(); it != updateFields.end(); ++it) {
            updateQuery.bindValue(":" + it.key(), it.value());
        }
        updateQuery.bindValue(":id", id);

        if (updateQuery.exec()) {
            QMessageBox::information(&updateDialog, "Succès", "Mise à jour réussie !");
            updateDialog.accept();
            ui->tableView->setModel(Etmp.afficher());
        } else {
            QMessageBox::critical(&updateDialog, "Erreur", "Échec de la mise à jour.");
        }
    });

    QObject::connect(cancelButton, &QPushButton::clicked, &updateDialog, &QDialog::reject);

    updateDialog.exec();
}
