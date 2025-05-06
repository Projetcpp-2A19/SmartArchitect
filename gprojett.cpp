#include "gprojett.h"
#include "ui_gprojett.h"
#include "emailsender.h"
#include <QMessageBox>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>
#include <QFileDialog>
#include <QSqlQuery>
#include <QTextCharFormat>
#include <QSqlError>
// 📌 Ajout des bibliothèques Qt Charts
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarCategoryAxis>

#include <QPdfWriter>
#include <QPainter>

GProjett::GProjett(QWidget *parent, Qt::WindowFlags flags)
    : QDialog(parent, flags)
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

    connect(ui->btnShowStats, &QPushButton::clicked, this, &GProjett::showBudgetGraph);
    connect(ui->btnEnvoyerEmail, &QPushButton::clicked, this, &GProjett::envoyerNotificationEmailAvecPJ);
    connect(ui->lineEditEmail, &QLineEdit::returnPressed, this, &GProjett::envoyerNotificationEmailAvecPJ);

    connect(ui->tableView, &QTableView::clicked, this, &GProjett::fillFieldsFromSelectedRow);

    // Initialiser l'onglet Finance si nécessaire
    initFinanceTab();
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
    // Set estimated_cost and actual_cost to -1 to trigger automatic calculation
    ProjetManager p(-1, nom, budget, debut.toString("yyyy-MM-dd"), fin.toString("yyyy-MM-dd"), client, status, -1, -1);
    if (p.ajouterProjet()) {
        QMessageBox::information(this, "Succès", "Projet ajouté !");
        proxyModel->setSourceModel(p.afficherProjets());  // Rafraîchir le modèle
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

    // Validation des champs
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

    // Récupération des données
    int id = proxyModel->data(proxyModel->index(index.row(), 0)).toInt();
    double estimated_cost = proxyModel->data(proxyModel->index(index.row(), 7)).toDouble();
    double actual_cost = proxyModel->data(proxyModel->index(index.row(), 8)).toDouble();

    // Création et modification du projet
    ProjetManager p(id, nom, budget,
                    debut.toString("yyyy-MM-dd"),
                    fin.toString("yyyy-MM-dd"),
                    client, status,
                    estimated_cost, actual_cost);

    if (p.modifierProjet()) {
        QMessageBox::information(this, "Succès", "Projet modifié !");
        proxyModel->setSourceModel(p.afficherProjets());
        showBudgetGraph();
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
            // Rafraîchir le graphique
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

void GProjett::on_btnExporterPDF_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "PDF Files (*.pdf)");
    if (fileName.isEmpty()) return;

    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setResolution(300);
    writer.setPageMargins(QMarginsF(15, 15, 15, 15));

    QPainter painter(&writer);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

    QTextDocument doc;
    QRectF contentRect = writer.pageLayout().paintRectPixels(writer.resolution());
    doc.setPageSize(contentRect.size());

    QTextCursor cursor(&doc);

    // Style du titre
    QTextBlockFormat titleFormat;
    titleFormat.setAlignment(Qt::AlignCenter);
    titleFormat.setTopMargin(10);
    titleFormat.setBottomMargin(20);

    QTextCharFormat titleCharFormat;
    titleCharFormat.setFont(QFont("Arial", 16, QFont::Bold));
    titleCharFormat.setForeground(Qt::darkBlue);

    cursor.insertBlock(titleFormat, titleCharFormat);
    cursor.insertText("Liste des Projets");

    // Configuration du tableau - maintenant avec 7 colonnes
    QTextTableFormat tableFormat;
    tableFormat.setBorder(1);
    tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
    tableFormat.setCellPadding(6);
    tableFormat.setCellSpacing(0);
    tableFormat.setAlignment(Qt::AlignCenter);
    tableFormat.setWidth(QTextLength(QTextLength::PercentageLength, 100));

    // Largeurs des colonnes (ajustées pour 7 colonnes)
    QVector<QTextLength> constraints;
    constraints << QTextLength(QTextLength::PercentageLength, 7)   // ID
                << QTextLength(QTextLength::PercentageLength, 15)  // Nom projet
                << QTextLength(QTextLength::PercentageLength, 15)  // Nom client
                << QTextLength(QTextLength::PercentageLength, 10)  // Budget
                << QTextLength(QTextLength::PercentageLength, 18)  // Date Début
                << QTextLength(QTextLength::PercentageLength, 18)  // Date Fin
                << QTextLength(QTextLength::PercentageLength, 17); // Status
    tableFormat.setColumnWidthConstraints(constraints);

    // Créer le tableau avec 7 colonnes
    QTextTable *table = cursor.insertTable(1, 7, tableFormat);

    // Style des en-têtes
    QTextCharFormat headerFormat;
    headerFormat.setFont(QFont("Arial", 10, QFont::Bold));
    headerFormat.setBackground(QColor(230, 230, 230));
    headerFormat.setForeground(Qt::black);
    headerFormat.setVerticalAlignment(QTextCharFormat::AlignMiddle);

    // Ajouter les en-têtes (avec la nouvelle colonne)
    QStringList headers = {"ID", "Nom Projet", "Nom Client", "Budget", "Date Début", "Date Fin", "Status"};
    for (int i = 0; i < headers.size(); ++i) {
        QTextTableCell cell = table->cellAt(0, i);
        QTextCursor cellCursor = cell.firstCursorPosition();
        cellCursor.insertText(headers[i], headerFormat);
    }

    // Style des cellules
    QTextCharFormat cellFormat;
    cellFormat.setFont(QFont("Arial", 9));
    cellFormat.setVerticalAlignment(QTextCharFormat::AlignMiddle);

    // Requête modifiée pour inclure le nom du client (jointure avec la table CLIENT)
    QSqlQuery query;
    query.prepare("SELECT p.ID_PROJET, p.NOM, c.NOM as NOM_CLIENT, p.BUDGET, "
                  "p.DATE_DEBUT, p.DATE_FIN, p.STATUS "
                  "FROM PROJET p "
                  "LEFT JOIN CLIENT c ON p.ID_CLIENT = c.ID_CLIENT "
                  "ORDER BY p.ID_PROJET");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Impossible d'exécuter la requête: " + query.lastError().text());
        return;
    }

    int rowsPerPage = 30; // Ajusté pour 7 colonnes

    while (query.next()) {
        if (table->rows() > rowsPerPage) {
            writer.newPage();
            table->appendRows(1);
        }

        table->appendRows(1);
        for (int col = 0; col < 7; ++col) {
            QTextTableCell cell = table->cellAt(table->rows()-1, col);
            QTextCursor cellCursor = cell.firstCursorPosition();
            cellCursor.insertText(query.value(col).toString(), cellFormat);
        }
    }

    doc.drawContents(&painter);
    QMessageBox::information(this, "Exportation réussie", "Le fichier PDF a été généré avec succès !");
}

// 📊 Affichage du graphique Budget vs Dépenses
void GProjett::showBudgetGraph() {
    QSqlQuery query("SELECT NOM, BUDGET FROM PROJET");

    QBarSeries *series = new QBarSeries();

    while (query.next()) {
        QString nomProjet = query.value(0).toString();
        double budget = query.value(1).toDouble();

        QBarSet *set = new QBarSet(nomProjet);
        *set << budget;
        series->append(set);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des Budgets des Projets");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append("Budgets");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 100000);  // Ajuste selon ton budget max
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(600, 400);

    // Pour un QDialog, nous pouvons créer une nouvelle fenêtre pour afficher le graphique
    QDialog *chartDialog = new QDialog(this);
    chartDialog->setWindowTitle("Statistiques des Budgets");
    QVBoxLayout *layout = new QVBoxLayout(chartDialog);
    layout->addWidget(chartView);
    chartDialog->setLayout(layout);
    chartDialog->resize(650, 450);
    chartDialog->exec();
}

void GProjett::envoyerNotificationEmailAvecPJ() {
    // Récupérer l'email depuis le QLineEdit
    QString clientEmail = ui->lineEditEmail->text().trimmed();

    QString message = "Bonjour,\n\nVeuillez trouver ci-joint le rapport de votre projet.\n\nCordialement.";

    QString filePath = QFileDialog::getOpenFileName(this, "Choisir une pièce jointe", "", "PDF Files (*.pdf);;All Files (*)");
    if (filePath.isEmpty()) return;

    EmailSender email;
    bool success = email.sendEmail(clientEmail, "Rapport de Projet", message, filePath);

    if (success) {
        QMessageBox::information(this, "Email", "Email avec pièce jointe envoyé avec succès !");
        ui->lineEditEmail->clear(); // Optionnel: vider le champ après envoi
    }
    else {
        QMessageBox::warning(this, "Email", "Erreur lors de l'envoi de l'email.");
    }
}

// Initialisation de l'onglet Finance
void GProjett::initFinanceTab()
{
    // Configuration des graphiques
    QChartView *deviationChartView = new QChartView(createBudgetDeviationChart());
    deviationChartView->setRenderHint(QPainter::Antialiasing);
    ui->financeLayout->addWidget(deviationChartView, 0, 0);

    QChartView *estimationChartView = new QChartView(createCostEstimationChart());
    estimationChartView->setRenderHint(QPainter::Antialiasing);
    ui->financeLayout->addWidget(estimationChartView, 0, 1);

    // Connecter le bouton de rafraîchissement
    connect(ui->btnRefreshFinance, &QPushButton::clicked, this, &GProjett::updateFinancialSummary);

    // Premier chargement des données
    updateFinancialSummary();
}

// Mise à jour du résumé financier
void GProjett::updateFinancialSummary()
{
    QSqlQuery query;
    query.exec("SELECT SUM(BUDGET), SUM(ESTIMATED_COST), SUM(ACTUAL_COST) FROM PROJET");

    if (query.next()) {
        double totalBudget = query.value(0).toDouble();
        double totalEstimated = query.value(1).toDouble();
        double totalActual = query.value(2).toDouble();

        ui->lblTotalBudget->setText(QString("Budget Total: %1 €").arg(totalBudget, 0, 'f', 2));
        ui->lblTotalEstimated->setText(QString("Coût Estimé: %1 €").arg(totalEstimated, 0, 'f', 2));
        ui->lblTotalActual->setText(QString("Coût Réel: %1 €").arg(totalActual, 0, 'f', 2));

        double deviation = totalActual - totalEstimated;
        QString deviationText = QString("Écart: %1 €").arg(deviation, 0, 'f', 2);
        if (deviation > 0) {
            deviationText += " (Dépassement)";
            ui->lblDeviation->setStyleSheet("color: red;");
        } else {
            deviationText += " (Économie)";
            ui->lblDeviation->setStyleSheet("color: green;");
        }
        ui->lblDeviation->setText(deviationText);
    }
}

// Graphique des écarts budgétaires
QChart* GProjett::createBudgetDeviationChart()
{
    QBarSeries *series = new QBarSeries();

    QSqlQuery query;
    query.exec("SELECT NOM, (ACTUAL_COST - ESTIMATED_COST) AS DEVIATION FROM PROJET");

    QBarSet *deviationSet = new QBarSet("Écart budgétaire");
    QStringList categories;

    while (query.next()) {
        *deviationSet << query.value(1).toDouble();
        categories << query.value(0).toString();
    }

    series->append(deviationSet);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Écarts Budgétaires par Projet");

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    return chart;
}

// Graphique d'estimation des coûts
QChart* GProjett::createCostEstimationChart()
{
    QLineSeries *budgetSeries = new QLineSeries();
    budgetSeries->setName("Budget");

    QLineSeries *estimatedSeries = new QLineSeries();
    estimatedSeries->setName("Estimé");

    QLineSeries *actualSeries = new QLineSeries();
    actualSeries->setName("Réel");

    QSqlQuery query;
    query.exec("SELECT NOM, BUDGET, ESTIMATED_COST, ACTUAL_COST FROM PROJET ORDER BY DATE_DEBUT");

    int index = 0;
    QStringList categories;

    while (query.next()) {
        *budgetSeries << QPointF(index, query.value(1).toDouble());
        *estimatedSeries << QPointF(index, query.value(2).toDouble());
        *actualSeries << QPointF(index, query.value(3).toDouble());
        categories << query.value(0).toString();
        index++;
    }

    QChart *chart = new QChart();
    chart->addSeries(budgetSeries);
    chart->addSeries(estimatedSeries);
    chart->addSeries(actualSeries);
    chart->setTitle("Comparaison Budget/Estimé/Réel");

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    budgetSeries->attachAxis(axisX);
    estimatedSeries->attachAxis(axisX);
    actualSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    budgetSeries->attachAxis(axisY);
    estimatedSeries->attachAxis(axisY);
    actualSeries->attachAxis(axisY);

    return chart;
}

void GProjett::on_btnRefreshFinance_clicked()
{
    // Mettre à jour les données financières
    updateFinancialSummary();

    // Rafraîchir les graphiques
    refreshFinanceCharts();

    QMessageBox::information(this, "Rafraîchissement", "Les données financières ont été mises à jour.");
}

void GProjett::refreshFinanceCharts()
{
    // Supprimer les anciens graphiques
    QLayoutItem* item;
    while ((item = ui->financeLayout->takeAt(0))) {
        delete item->widget();
        delete item;
    }

    // Recréer les graphiques
    initFinanceTab();
}
void GProjett::fillFieldsFromSelectedRow(const QModelIndex &index) {
    if (!index.isValid()) return;

    // Récupérer le modèle source si vous utilisez un proxy
    QAbstractItemModel *model = ui->tableView->model();

    // Remplir les champs avec les données de la ligne sélectionnée
    ui->lineEdit_nom->setText(model->data(model->index(index.row(), 1)).toString()); // NOM
    ui->lineEdit_budget->setText(model->data(model->index(index.row(), 2)).toString()); // BUDGET
    ui->dateEdit_debut->setDate(QDate::fromString(model->data(model->index(index.row(), 3)).toString(), "yyyy-MM-dd")); // DATE_DEBUT
    ui->dateEdit_fin->setDate(QDate::fromString(model->data(model->index(index.row(), 4)).toString(), "yyyy-MM-dd")); // DATE_FIN
    ui->lineEdit_client->setText(model->data(model->index(index.row(), 5)).toString()); // CLIENT
    ui->comboBox_status->setCurrentText(model->data(model->index(index.row(), 6)).toString()); // STATUS
}
