#include "mainwindow.h"
#include "cartefidelitedialog.h"
#include "qsqlerror.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QFileDialog>
#include <QChart>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QHBoxLayout>
#include <connection.h>
#include <QTableWidgetItem>
#include <QPrinter>
#include <QPageLayout>
#include <QPageSize>
#include <QPainter>
#include <QStandardPaths>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList headersFidelite = {"ID", "Client", "Région", "Score"};
    ui->tableWidgetFidelite->setColumnCount(headersFidelite.size());
    ui->tableWidgetFidelite->setHorizontalHeaderLabels(headersFidelite);

    // Charger les données initiales
    chargerDonneesFidelite();
    connect(ui->actualiser_fidelite, &QPushButton::clicked,
            this, &MainWindow::on_pb_actualiser_fidelite_clicked);
    // Initialisation de la base de données
    connection c;
    c.createconnect();

    // Configuration initiale
    ui->tableView->setModel(client.afficher());

    // Configurer le tableWidget
    QStringList headers = {"ID", "Nom", "Prénom", "Région", "Téléphone", "Email"};
    ui->tableWidget->setColumnCount(headers.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Remplir le comboBox des régions
    QSqlQuery query("SELECT DISTINCT REGION FROM clients");
    while (query.next()) {
        ui->comboBoxRegions->addItem(query.value(0).toString());
        qDebug() << "Bouton connecté :" << connect(
            ui->generer_carte, &QPushButton::clicked,
            this, &MainWindow::on_pb_generer_carte_clicked
            );
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    QString nom = ui->le_nom->text().trimmed();
    QString prenom = ui->le_prenom->text().trimmed();
    QString region = ui->le_region->text().trimmed();
    QString telephone = ui->le_telephone->text().trimmed();
    QString email = ui->le_email->text().trimmed();

    // Validation basique des champs
    if(nom.isEmpty() || prenom.isEmpty() || region.isEmpty() || telephone.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Tous les champs doivent être remplis");
        return;
    }

    // Validation email (optionnelle)
    QRegularExpression emailRegex(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b)");
    if(!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Email invalide", "Veuillez entrer une adresse email valide");
        return;
    }

    // Validation téléphone (optionnelle)
    telephone.remove(" "); // Supprimer les espaces
    QRegularExpression phoneRegex(R"(\d{8,})");
    if(!phoneRegex.match(telephone).hasMatch()) {
        QMessageBox::warning(this, "Téléphone invalide", "Le numéro doit contenir au moins 8 chiffres");
        return;
    }

    // Ajout du client (même s'il existe déjà)
    Client c(nom, prenom, region, telephone, email);
    if(c.ajouter()) {
        QMessageBox::information(this, "Succès", "Client ajouté avec succès");

        // Actualiser les affichages
        ui->tableView->setModel(client.afficher());
        client.afficherDansTableWidget(ui->tableWidget);

        // Actualiser la fidélité
        chargerDonneesFidelite();

        // Réinitialiser les champs
        ui->le_nom->clear();
        ui->le_prenom->clear();
        ui->le_region->clear();
        ui->le_telephone->clear();
        ui->le_email->clear();
    } else {
         QMessageBox::critical(this, "Erreur", "Échec : " + c.getLastError());
    }
}

void MainWindow::on_pb_modifier_clicked()
{
    // Vérifier qu'un ID est bien sélectionné
    if (ui->le_id_2->text().isEmpty()) {
        QMessageBox::warning(this, "Avertissement", "Veuillez sélectionner un client à modifier");
        return;
    }

    int id = ui->le_id_2->text().toInt();
    QString nom = ui->le_nom->text().trimmed();
    QString prenom = ui->le_prenom->text().trimmed();
    QString region = ui->le_region->text().trimmed();
    QString telephone = ui->le_telephone->text().trimmed();
    QString email = ui->le_email->text().trimmed();

    // Validation des champs
    if (nom.isEmpty() || prenom.isEmpty() || region.isEmpty() || telephone.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Avertissement", "Tous les champs doivent être remplis");
        return;
    }

    Client c(nom, prenom, region, telephone, email);
    if (c.modifier(id)) {
        QMessageBox::information(this, "Succès", "Client modifié avec succès");
        ui->tableView->setModel(client.afficher()); // Rafraîchir l'affichage
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du client");
    }
}

void MainWindow::on_pb_supprimer_clicked()
{
    int id = ui->le_idsupp->text().toInt();
    if (client.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Client supprimé avec succès");
        ui->tableView->setModel(client.afficher());
        client.afficherDansTableWidget(ui->tableWidget);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression du client");
    }
}

void MainWindow::on_pb_chercher_nom_clicked()
{
    QString nom = ui->lineEditNom->text();  // Assure-toi que c'est un QLineEdit
    QSqlQueryModel *model = client.chercherParNom(nom);

    if (model) {
        ui->tableViewNom->setModel(model);
        ui->tableViewNom->resizeColumnsToContents();
    } else {
        QMessageBox::warning(this, "Avertissement", "Aucun résultat trouvé pour le nom spécifié.");
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    client.afficherDansTableWidget(ui->tableWidget);
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    Q_UNUSED(column);
    int id = ui->tableWidget->item(row, 0)->text().toInt();
    Client c = client.recupererClient(id);

    ui->le_nom->setText(c.getNom());
    ui->le_prenom->setText(c.getPrenom());
    ui->le_region->setText(c.getRegion());
    ui->le_telephone->setText(c.getTelephone());
    ui->le_email->setText(c.getEmail());
    ui->le_id_2->setText(QString::number(c.getId()));
}
void MainWindow::on_tableView2_clicked(const QModelIndex &index)
{
    int row = index.row();

    // Récupérer les données de la ligne sélectionnée
    QAbstractItemModel *model = ui->tableView->model();

    int id = model->data(model->index(row, 0)).toInt(); // Supposant que l'ID est dans la colonne 0
    QString nom = model->data(model->index(row, 1)).toString(); // Colonne 1 pour le nom
    QString prenom = model->data(model->index(row, 2)).toString(); // Colonne 2 pour le prénom
    QString region = model->data(model->index(row, 3)).toString(); // Colonne 3 pour la région
    QString telephone = model->data(model->index(row, 4)).toString(); // Colonne 4 pour le téléphone
    QString email = model->data(model->index(row, 5)).toString(); // Colonne 5 pour l'email

    // Remplir les champs de saisie
    ui->le_id_2->setText(QString::number(id));
    ui->le_nom->setText(nom);
    ui->le_prenom->setText(prenom);
    ui->le_region->setText(region);
    ui->le_telephone->setText(telephone);
    ui->le_email->setText(email);
}

void MainWindow::on_pushButton_9_clicked()
{
    int id = ui->le_id_2->text().toInt();
    Client c = client.recupererClient(id);

    if (c.getId() != 0) {
        ui->le_nom->setText(c.getNom());
        ui->le_prenom->setText(c.getPrenom());
        ui->le_region->setText(c.getRegion());
        ui->le_telephone->setText(c.getTelephone());
        ui->le_email->setText(c.getEmail());
    } else {
        QMessageBox::critical(this, "Erreur", "Client introuvable");
    }
}

void MainWindow::on_employee_pb_stat_clicked()
{
    QMessageBox::information(this, "Statistiques", "Fonctionnalité à implémenter");
}
void MainWindow::on_pb_export_pdf_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Exporter vers PDF", "", "PDF Files (*.pdf)");

    if (!filePath.isEmpty()) {
        if (client.exporterPDF(filePath)) {
            QMessageBox::information(this, "Succès", "Données exportées avec succès dans le fichier PDF");
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de l'exportation vers le PDF");
        }
    }
}
void MainWindow::on_pb_tri_clicked()
{
    static bool ascending = true;

    QSqlQueryModel *model = new QSqlQueryModel();

    // Utilisation de move pour éviter la copie
    QSqlQuery query;
    query.prepare("SELECT * FROM clients ORDER BY NOM " + QString(ascending ? "ASC" : "DESC"));

    if (query.exec()) {
        model->setQuery(std::move(query));  // Correction ici - utilisation de std::move

        // Définir les en-têtes de colonnes
        model->setHeaderData(0, Qt::Horizontal, tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, tr("Prénom"));
        model->setHeaderData(3, Qt::Horizontal, tr("Région"));
        model->setHeaderData(4, Qt::Horizontal, tr("Téléphone"));
        model->setHeaderData(5, Qt::Horizontal, tr("Email"));

        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();

        // Trier aussi le tableWidget
        client.afficherTrieDansTableWidget(ui->tableWidget, ascending);

        // Inverser et mettre à jour le bouton
        ascending = !ascending;
        ui->pb_tri->setText(ascending ? "Tri (A-Z)" : "Tri (Z-A)");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec du tri : " + query.lastError().text());
        delete model;
    }
}

void MainWindow::on_client_pb_stat_clicked()
{
    // Récupérer les statistiques
    QMap<QString, int> stats = client.getStatsByRegion();

    if (stats.isEmpty()) {
        QMessageBox::information(this, "Statistiques", "Aucune donnée disponible");
        return;
    }

    // Créer un widget pour afficher le graphique
    QWidget *statWindow = new QWidget();
    statWindow->setWindowTitle("Statistiques par région");
    statWindow->resize(800, 600);

    // Créer le graphique
    QChart *chart = new QChart();
    chart->setTitle("Répartition des clients par région");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Créer les séries de données
    QBarSeries *series = new QBarSeries();
    QBarSet *set = new QBarSet("Nombre de clients");

    // Remplir les données
    QStringList categories;
    for (auto it = stats.begin(); it != stats.end(); ++it) {
        *set << it.value();
        categories << it.key();
    }

    series->append(set);
    chart->addSeries(series);

    // Configurer les axes
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%d");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Créer la vue du graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Mettre en page
    QHBoxLayout *layout = new QHBoxLayout(statWindow);
    layout->addWidget(chartView);
    statWindow->setLayout(layout);

    // Afficher la fenêtre
    statWindow->show();
}

// Après avoir chargé les clients
void MainWindow::chargerDonneesFidelite()
{
    QVector<QVector<QString>> clientsData;
    QSqlQuery query("SELECT ID, NOM, PRENOM, REGION, TELEPHONE, EMAIL FROM clients");

    while (query.next()) {
        QVector<QString> client;
        for (int i = 0; i < 6; ++i) {
            client.append(query.value(i).toString());
        }
        clientsData.append(client);
    }

    // 🔍 Debug : vérifier les clients récupérés
    qDebug() << "Nombre de clients chargés:" << clientsData.size();
    for (const auto& client : clientsData) {
        qDebug() << "Client:" << client;
    }

    fideliteManager.analyserClients(clientsData);
    afficherTableauFidelite();
}


void MainWindow::on_pb_actualiser_fidelite_clicked()
{
    // 1. Récupérer les données clients depuis la base
    QVector<QVector<QString>> clientsData;
    QSqlQuery query("SELECT ID, NOM, PRENOM, REGION, TELEPHONE, EMAIL FROM clients");

    while (query.next()) {
        QVector<QString> client;
        for (int i = 0; i < 6; ++i) {
            client.append(query.value(i).toString());
        }
        clientsData.append(client);
    }

    // 2. Analyser la fidélité
    fideliteManager.analyserClients(clientsData);

    // 3. Afficher les résultats
    afficherTableauFidelite();

    QMessageBox::information(this, "Actualisation", "Les données de fidélité ont été actualisées");
}

void MainWindow::afficherTableauFidelite()
{
    ui->tableWidgetFidelite->setRowCount(0);
    auto scores = fideliteManager.getScoresFidelite();

    for (const auto& score : scores) {
        int row = ui->tableWidgetFidelite->rowCount();
        ui->tableWidgetFidelite->insertRow(row);

        ui->tableWidgetFidelite->setItem(row, 0, new QTableWidgetItem(QString::number(score.id)));
        ui->tableWidgetFidelite->setItem(row, 1, new QTableWidgetItem(score.nomComplet));
        ui->tableWidgetFidelite->setItem(row, 2, new QTableWidgetItem(score.region));
        ui->tableWidgetFidelite->setItem(row, 3, new QTableWidgetItem(QString::number(score.score)));
    }
}


void MainWindow::on_pb_generer_carte_clicked()
{

        // Vérifier la sélection
        int currentRow = ui->tableWidgetFidelite->currentRow();
        if (currentRow < 0) {
            QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un client");
            return;
        }

        // Récupérer les données
        int id = ui->tableWidgetFidelite->item(currentRow, 0)->text().toInt();
        QString nom = ui->tableWidgetFidelite->item(currentRow, 1)->text();
        int score = ui->tableWidgetFidelite->item(currentRow, 3)->text().toInt();

        // Afficher la carte
        CarteFideliteDialog carteDialog(id, nom, score, this);
        carteDialog.exec();
    }


