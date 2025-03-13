#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "connection.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connection c;
    c.createconnect();  // Assurez-vous que la connexion à la base de données est correcte
    ui->tableView->setModel(client.afficher());  // Affiche les clients dès l'ouverture de la fenêtre
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    QString nom = ui->le_nom->text();
    QString prenom = ui->le_prenom->text();
    QString region = ui->le_region->text();
    QString telephone = ui->le_telephone->text();
    QString email = ui->le_email->text();

    Client c(nom, prenom, region, telephone, email); // Constructeur sans id car auto-incrémenté
    if (c.ajouter()) {
        QMessageBox::information(this, "Succès", "Client ajouté avec succès");
        ui->tableView->setModel(client.afficher());  // Rafraîchit l'affichage
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du client");
    }
}

void MainWindow::on_pb_modifier_clicked()
{
    int id = ui->le_id_2->text().toInt();
    QString nom = ui->le_nom->text();
    QString prenom = ui->le_prenom->text();
    QString region = ui->le_region->text();
    QString telephone = ui->le_telephone->text();
    QString email = ui->le_email->text();

    Client c(id, nom, prenom, region, telephone, email);
    if (c.modifier(id)) {
        QMessageBox::information(this, "Succès", "Client modifié avec succès");
        ui->tableView->setModel(client.afficher());  // Rafraîchit l'affichage
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du client");
    }
}

void MainWindow::on_pb_supprimer_clicked()
{
    int id = ui->le_idsupp->text().toInt();
    if (client.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Client supprimé avec succès");
        ui->tableView->setModel(client.afficher());  // Rafraîchit l'affichage
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression du client");
    }
}

void MainWindow::on_employee_pb_stat_clicked()
{
    // Si vous avez des statistiques ou autres fonctionnalités à ajouter
}

void MainWindow::on_pushButton_9_clicked()
{
    int id = ui->le_id_2->text().toInt(); // Récupérer l'ID à partir du champ texte
    Client c = client.recupererClient(id); // Récupérer les données du client

    // Vérifier si un client a été trouvé
    if (c.getId() != 0) {

        // Afficher les informations du client dans les champs en utilisant les getters
        ui->le_nom->setText(c.getNom());
        ui->le_prenom->setText(c.getPrenom());
        ui->le_region->setText(c.getRegion());
        ui->le_telephone->setText(c.getTelephone());
        ui->le_email->setText(c.getEmail());
    } else {
        QMessageBox::critical(this, "Erreur", "Client introuvable");
    }
}




void MainWindow::on_pushButton_10_clicked()
{
    client.afficherDansTableWidget(ui->tableWidget);  // Assurez-vous que tableWidget est bien défini dans l'UI

}


void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    if (column == 0) {  // Si l'utilisateur clique sur la colonne ID
        int id = ui->tableWidget->item(row, 0)->text().toInt();  // Récupérer l'ID
        Client c = client.recupererClient(id);  // Récupérer le client

        // Remplir les champs avec les infos du client
        ui->le_nom->setText(c.getNom());
        ui->le_prenom->setText(c.getPrenom());
        ui->le_region->setText(c.getRegion());
        ui->le_telephone->setText(c.getTelephone());
        ui->le_email->setText(c.getEmail());
        ui->le_id_2->setText(QString::number(c.getId())); // Affiche aussi l'ID si besoin
    }
}

