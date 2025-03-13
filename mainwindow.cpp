#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlError>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), proxyModelFournisseurs(new QSortFilterProxyModel(this)) {
    ui->setupUi(this);

    // 📌 Initialisation du modèle et tri pour les fournisseurs
    proxyModelFournisseurs->setSourceModel(fournisseur.afficherFournisseurs());
    proxyModelFournisseurs->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxyModelFournisseurs->setFilterKeyColumn(-1);  // Recherche sur toutes les colonnes

    ui->tableViewFournisseurs->setModel(proxyModelFournisseurs);
    ui->tableViewFournisseurs->setSortingEnabled(true);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btnAjouterFournisseur_clicked() {
    QString nom = ui->lineEdit_nomFournisseur->text();
    QString telephone = ui->lineEdit_telephoneFournisseur->text();
    QString adresse = ui->lineEdit_adresseFournisseur->text();
    QString ville = ui->lineEdit_villeFournisseur->text();
    QString etat = ui->lineEdit_etatFournisseur->text();
    QString commande = ui->lineEdit_commandeFournisseur->text();
    QString email = ui->lineEdit_emailFournisseur->text();
    // 📌 Vérification que les champs obligatoires ne sont pas vides
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le champ 'Nom' est obligatoire !");
        return;
    }

    // 📌 Validation du numéro de téléphone (8 à 15 chiffres)
    QRegularExpression regexTel("^[0-9]{8,15}$");
    if (!telephone.isEmpty() && !regexTel.match(telephone).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Numéro de téléphone invalide ! (8-15 chiffres)");
        return;
    }

    // 📌 Validation de l'email
    QRegularExpression regexEmail("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,4}$");
    if (!email.isEmpty() && !regexEmail.match(email).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Email invalide !");
        return;
    }

    Fournisseur f(0, nom, telephone, adresse, ville, etat, commande, email);

    if (f.ajouterFournisseur()) {
        QMessageBox::information(this, "Succès", "Fournisseur ajouté !");
        proxyModelFournisseurs->setSourceModel(fournisseur.afficherFournisseurs());  // Rafraîchir la vue
    } else {
        QMessageBox::warning(this, "Erreur", "Ajout échoué !");
    }
}

void MainWindow::on_btnModifierFournisseur_clicked() {
    QModelIndex index = ui->tableViewFournisseurs->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Erreur", "Sélectionnez un fournisseur à modifier !");
        return;
    }

    int id = proxyModelFournisseurs->data(proxyModelFournisseurs->index(index.row(), 0)).toInt();
    QString nom = ui->lineEdit_nomFournisseur->text();
    QString telephone = ui->lineEdit_telephoneFournisseur->text();
    QString adresse = ui->lineEdit_adresseFournisseur->text();
    QString ville = ui->lineEdit_villeFournisseur->text();
    QString etat = ui->lineEdit_etatFournisseur->text();
    QString commande = ui->lineEdit_commandeFournisseur->text();
    QString email = ui->lineEdit_emailFournisseur->text();

    Fournisseur f(id, nom, telephone, adresse, ville, etat, commande, email);

    if (f.modifierFournisseur()) {
        QMessageBox::information(this, "Succès", "Fournisseur modifié !");
        proxyModelFournisseurs->setSourceModel(fournisseur.afficherFournisseurs());
    } else {
        QMessageBox::warning(this, "Erreur", "Modification échouée !");
    }
}

void MainWindow::on_btnSupprimerFournisseur_clicked() {
    QModelIndex index = ui->tableViewFournisseurs->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Erreur", "Sélectionnez un fournisseur à supprimer !");
        return;
    }

    int id = proxyModelFournisseurs->data(proxyModelFournisseurs->index(index.row(), 0)).toInt();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Suppression", "Voulez-vous vraiment supprimer ce fournisseur ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (fournisseur.supprimerFournisseur(id)) {
            QMessageBox::information(this, "Succès", "Fournisseur supprimé !");
            proxyModelFournisseurs->setSourceModel(fournisseur.afficherFournisseurs());
        } else {
            QMessageBox::warning(this, "Erreur", "Suppression échouée !");
        }
    }
}

void MainWindow::afficherFournisseurs() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM FOURNISSEURS");  // Charger les données

    if (model->lastError().isValid()) {
        qDebug() << "Erreur SQL :" << model->lastError().text();
    }

    ui->tableViewFournisseurs->setModel(model);  // Associer le modèle au QTableView
}

