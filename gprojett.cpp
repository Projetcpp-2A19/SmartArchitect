#include "gprojett.h"
#include "ui_gprojett.h"
#include <QMessageBox>

// 📌 Ajout des bibliothèques Qt Charts
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarCategoryAxis>

GProjett::GProjett(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GProjett)
    , proxyModel(new QSortFilterProxyModel(this))  // Créer le modèle de tri
{
    ui->setupUi(this);

    // Configurer le modèle de tri
    proxyModel->setSourceModel(p.afficherProjets());  // Associer le modèle de données
    ui->tableView->setModel(proxyModel);  // Associer le modèle de tri à la vue

    // Activer le tri par colonnes
    ui->tableView->setSortingEnabled(true);


    ui->btnRechercher->setIcon(QIcon("C:/Users/benha/OneDrive/Bureau/GProjett/icon/search-13-48.ico"));
    ui->user_btn->setIcon(QIcon("C:/Users/benha/OneDrive/Bureau/GProjett/icon/user-48.ico"));
}

GProjett::~GProjett()
{
    delete ui;
}

void GProjett::on_btnAjouter_clicked() {
    QString nom = ui->lineEdit_nom->text().trimmed();
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le champ 'Nom' ne peut pas être vide !");
        return;
    }

    bool budgetOk;
    double budget = ui->lineEdit_budget->text().toDouble(&budgetOk);
    if (!budgetOk || budget <= 0) {
        QMessageBox::warning(this, "Erreur", "Le budget doit être un nombre positif !");
        return;
    }

    QDate debut = ui->dateEdit_debut->date();
    QDate fin = ui->dateEdit_fin->date();
    if (fin < debut) {
        QMessageBox::warning(this, "Erreur", "La date de fin ne peut pas être avant la date de début !");
        return;
    }

    bool clientOk;
    int client = ui->lineEdit_client->text().toInt(&clientOk);
    if (!clientOk || client <= 0) {
        QMessageBox::warning(this, "Erreur", "L'ID client doit être un entier positif !");
        return;
    }

    QString status = ui->comboBox_status->currentText();
    if (status.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le champ 'Statut' ne peut pas être vide !");
        return;
    }

    // ✅ Si tout est bon, on ajoute le projet
    ProjetManager p(0, nom, budget, debut.toString("yyyy-MM-dd"), fin.toString("yyyy-MM-dd"), client, status);
    if (p.ajouterProjet()) {
        QMessageBox::information(this, "Succès", "Projet ajouté !");
        proxyModel->setSourceModel(p.afficherProjets());  // Rafraîchir le modèle
        showBudgetGraph();  // Rafraîchir le graphique
    } else {
        QMessageBox::warning(this, "Erreur", "Ajout échoué !");
    }
}

void GProjett::on_btnAnnuler_clicked()
{
    // Réinitialiser les champs de saisie
    ui->lineEdit_nom->clear();
    ui->lineEdit_budget->clear();
    ui->dateEdit_debut->setDate(QDate::currentDate());
    ui->dateEdit_fin->setDate(QDate::currentDate());
    ui->lineEdit_client->clear();
    ui->comboBox_status->setCurrentIndex(0);


    QMessageBox::information(this, "Annulation", "Les champs ont été réinitialisés.");
}


void GProjett::on_btnModifier_clicked() {
    // Récupérer l'ID du projet sélectionné
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Erreur", "Sélectionnez un projet à modifier !");
        return;
    }

    int id = proxyModel->data(proxyModel->index(index.row(), 0)).toInt();  // Colonne 0 = ID_PROJET
    QString nom = ui->lineEdit_nom->text().trimmed();
    double budget = ui->lineEdit_budget->text().toDouble();
    QString debut = ui->dateEdit_debut->date().toString("yyyy-MM-dd");
    QString fin = ui->dateEdit_fin->date().toString("yyyy-MM-dd");
    int client = ui->lineEdit_client->text().toInt();
    QString status = ui->comboBox_status->currentText();

    ProjetManager p(id, nom, budget, debut, fin, client, status);
    if (p.modifierProjet()) {
        QMessageBox::information(this, "Succès", "Projet modifié !");
        proxyModel->setSourceModel(p.afficherProjets());  // Rafraîchir le modèle
        showBudgetGraph();  // Rafraîchir le graphique
    } else {
        QMessageBox::warning(this, "Erreur", "Modification échouée !");
    }
}

void GProjett::on_btnSupprimer_clicked() {
    // Récupérer l'ID du projet sélectionné
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Erreur", "Sélectionnez un projet à supprimer !");
        return;
    }

    int id = proxyModel->data(proxyModel->index(index.row(), 0)).toInt();  // Colonne 0 = ID_PROJET

    // Demander une confirmation avant de supprimer
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Suppression", "Voulez-vous vraiment supprimer ce projet ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        ProjetManager p;
        if (p.supprimerProjet(id)) {
            QMessageBox::information(this, "Succès", "Projet supprimé !");
            proxyModel->setSourceModel(p.afficherProjets());  // Rafraîchir le modèle
            showBudgetGraph();  // Rafraîchir le graphique
        } else {
            QMessageBox::warning(this, "Erreur", "Suppression échouée !");
        }
    }
}

void GProjett::on_btnAsc_clicked() {
    // Trier en ordre ascendant sur la colonne 0 (ID_PROJET)
    proxyModel->sort(0, Qt::AscendingOrder);
}

void GProjett::on_btnDesc_clicked() {
    // Trier en ordre descendant sur la colonne 0 (ID_PROJET)
    proxyModel->sort(0, Qt::DescendingOrder);
}

void GProjett::on_btnRechercher_clicked()
{
    QString searchText = ui->searchBar->text().trimmed();
    proxyModel->setFilterKeyColumn(1);  // Colonne 1 = Nom du projet
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxyModel->setFilterFixedString(searchText);
}

// 📊 Affichage du graphique Budget vs Dépenses
void GProjett::showBudgetGraph()
{
    QBarSet *budgetSet = new QBarSet("Budget Alloué");
    QBarSet *spentSet = new QBarSet("Dépenses Actuelles");

    *budgetSet << 50000;
    *spentSet << 42000;

    QBarSeries *series = new QBarSeries();
    series->append(budgetSet);
    series->append(spentSet);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Comparaison Budget vs Dépenses");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "Projet A";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 60000);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    ui->chartWidget->setChart(chart);
    ui->chartWidget->setRenderHint(QPainter::Antialiasing);
}
