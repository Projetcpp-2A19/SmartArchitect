#include "mainwindow.h"
#include "loginform.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "mainarch.h"
#include "mainclient.h"
#include "mainequip.h"
#include "gprojett.h"  // Include GProjett
#include <QMessageBox>
#include <QSqlError>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTimer>
#include <QDebug>
#include "statspostewindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , proxyModel(new QSortFilterProxyModel(this))
    , mainArch(nullptr)
    , mainClient(nullptr)
    , mainEquip(nullptr)
    , gProjett(nullptr)  // Initialize gProjett to nullptr
{
    ui->setupUi(this);
    setupRFIDInterface();
    ui->tableView->setModel(nullptr);
    ui->lineEditPassword->setEchoMode(QLineEdit::Password);

    // Connect buttons
    connect(ui->btnTriSalaire, &QPushButton::clicked,
            this, &MainWindow::on_btnTriSalaire_clicked);
    connect(ui->btnExportPDF, &QPushButton::clicked,
            this, &MainWindow::on_btnExportPDF_clicked);
    connect(ui->home_btn_5, &QPushButton::clicked,
            this, &MainWindow::on_home_btn_5_clicked);
    connect(ui->customers_btn_4, &QPushButton::clicked,
            this, &MainWindow::on_customers_btn_4_clicked);
    connect(ui->orders_btn_3, &QPushButton::clicked,
            this, &MainWindow::on_orders_btn_3_clicked);
    connect(ui->products_btn_3, &QPushButton::clicked,
            this, &MainWindow::on_products_btn_3_clicked);  // Connect products_btn_3

    // Initialize the model
    QSqlQueryModel* sourceModel = emp.afficherEmployes();
    if (sourceModel) {
        proxyModel->setSourceModel(sourceModel);
        proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
        proxyModel->setFilterKeyColumn(-1);
        ui->tableView->setModel(proxyModel);
        ui->tableView->setSortingEnabled(true);

        // Set column headers explicitly
        proxyModel->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EMPLOYE"));
        proxyModel->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        proxyModel->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        proxyModel->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
        proxyModel->setHeaderData(4, Qt::Horizontal, QObject::tr("MDP"));
        proxyModel->setHeaderData(5, Qt::Horizontal, QObject::tr("POSTE"));
        proxyModel->setHeaderData(6, Qt::Horizontal, QObject::tr("SALAIRE"));
        proxyModel->setHeaderData(7, Qt::Horizontal, QObject::tr("DATEEMBOCHE"));

        // Sort by salary column (index 6)
        ui->tableView->sortByColumn(6, Qt::AscendingOrder);
    } else {
        QMessageBox::warning(this, "Error", "Failed to load employee data!");
    }

    // Set up logs table
    ui->tableWidgetLogs->setColumnCount(4);
    ui->tableWidgetLogs->setHorizontalHeaderLabels({"Date/Heure", "UID Badge", "Employé", "Statut"});
    ui->tableWidgetLogs->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete mainArch;
    delete mainClient;
    delete mainEquip;
    delete gProjett;  // Clean up gProjett
    delete ui;
}

void MainWindow::on_btnAjouter_clicked()
{
    int employeeId = ui->lineEditEmployeeId->text().toInt();
    QString lastName = ui->lineEditLastName->text();
    QString firstName = ui->lineEditFirstName->text();
    QString email = ui->lineEditEmail->text();
    QString password = ui->lineEditPassword->text();
    QString position = ui->lineEditPosition->text();
    QString salary = ui->lineEditSalary->text();
    QString hireDate = ui->dateEditHireDate->text();

    Employee e(employeeId, lastName, firstName, email, password, position, salary, hireDate);

    if (e.ajouterEmploye()) {
        QMessageBox::information(this, "Succès", "Employé ajouté !");
        updateTableView();
    } else {
        QMessageBox::warning(this, "Erreur", "Ajout échoué !");
    }
}

void MainWindow::on_btnModifier_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Erreur", "Sélectionnez un employé à modifier !");
        return;
    }

    int employeeId = proxyModel->data(proxyModel->index(index.row(), 0)).toInt();
    QString lastName = ui->lineEditLastName->text();
    QString firstName = ui->lineEditFirstName->text();
    QString email = ui->lineEditEmail->text();
    QString password = ui->lineEditPassword->text();
    QString position = ui->lineEditPosition->text();
    QString salary = ui->lineEditSalary->text();
    QString hireDate = ui->dateEditHireDate->text();

    if (emp.updateEmployee(employeeId, lastName, firstName, email, password, position, salary, hireDate)) {
        QMessageBox::information(this, "Succès", "Employé modifié !");
        updateTableView();
    } else {
        QMessageBox::warning(this, "Erreur", "Modification échouée !");
    }
}

void MainWindow::on_btnSupprimer_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Erreur", "Sélectionnez un employé à supprimer !");
        return;
    }

    int id = proxyModel->data(proxyModel->index(index.row(), 0)).toInt();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Suppression", "Voulez-vous vraiment supprimer cet employé ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (emp.supprimerEmploye(id)) {
            QMessageBox::information(this, "Succès", "Employé supprimé !");
            updateTableView();
        } else {
            QMessageBox::warning(this, "Erreur", "Suppression échouée !");
        }
    }
}

void MainWindow::updateTableView()
{
    QSqlQueryModel* newModel = emp.afficherEmployes();
    if (newModel) {
        delete proxyModel->sourceModel();
        proxyModel->setSourceModel(newModel);
        ui->tableView->setModel(proxyModel);

        proxyModel->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EMPLOYE"));
        proxyModel->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        proxyModel->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        proxyModel->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
        proxyModel->setHeaderData(4, Qt::Horizontal, QObject::tr("MDP"));
        proxyModel->setHeaderData(5, Qt::Horizontal, QObject::tr("POSTE"));
        proxyModel->setHeaderData(6, Qt::Horizontal, QObject::tr("SALAIRE"));
        proxyModel->setHeaderData(7, Qt::Horizontal, QObject::tr("DATEEMBOCHE"));

        ui->tableView->sortByColumn(6, Qt::AscendingOrder);
    } else {
        QMessageBox::warning(this, "Error", "Failed to load employee data!");
    }
}

void MainWindow::on_btnTriSalaire_clicked()
{
    qDebug() << "Bouton de tri cliqué";
    QSqlQueryModel* newModel = emp.trierEmployesParSalaireCroissant();
    if (newModel) {
        delete proxyModel->sourceModel();
        proxyModel->setSourceModel(newModel);
        ui->tableView->setModel(proxyModel);
        ui->tableView->sortByColumn(6, Qt::AscendingOrder);
        qDebug() << "Affichage des données triées";
    } else {
        qDebug() << "Échec du tri";
        QMessageBox::warning(this, "Erreur", "Le tri a échoué");
    }
}

void MainWindow::on_btnRechercheIdNom_clicked()
{
    QString recherche = ui->lineEditRechercheIdNom->text().trimmed();

    if (recherche.isEmpty()) {
        updateTableView();
        return;
    }

    QSqlQueryModel* resultModel = emp.rechercherEmployee(recherche);
    if (resultModel && resultModel->rowCount() > 0) {
        delete proxyModel->sourceModel();
        proxyModel->setSourceModel(resultModel);
        ui->tableView->setModel(proxyModel);
    } else {
        QMessageBox::information(this, "Recherche", "Aucun résultat trouvé");
        delete resultModel;
    }
}

void MainWindow::on_btnStatsPoste_clicked()
{
    QMap<QString, int> stats = emp.getStatsByPoste();

    if (stats.isEmpty()) {
        QMessageBox::information(this, "Statistiques", "Aucune donnée disponible");
        return;
    }

    StatsPosteWindow *statsWindow = new StatsPosteWindow(stats, this);
    statsWindow->setAttribute(Qt::WA_DeleteOnClose);
    statsWindow->show();
}

void MainWindow::on_btnAnnuler_clicked()
{
    ui->lineEditEmployeeId->clear();
    ui->lineEditLastName->clear();
    ui->lineEditFirstName->clear();
    ui->lineEditEmail->clear();
    ui->lineEditPassword->clear();
    ui->lineEditPosition->clear();
    ui->lineEditSalary->clear();
    ui->dateEditHireDate->setText(QDate::currentDate().toString("yyyy-MM-dd"));
    ui->tableView->clearSelection();
    QMessageBox::information(this, "Annulation", "Tous les champs ont été réinitialisés.");
}

void MainWindow::on_btnExportPDF_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", QDir::homePath(), "Fichiers PDF (*.pdf)");

    if (fileName.isEmpty())
        return;

    if (!fileName.endsWith(".pdf"))
        fileName += ".pdf";

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QString html = "<h1 align='center'>Liste des Employés</h1>"
                   "<table border='1' cellspacing='0' cellpadding='3' width='100%'>"
                   "<tr bgcolor='#f2f2f2'>";

    QAbstractItemModel *model = ui->tableView->model();
    for (int col = 0; col < model->columnCount(); ++col) {
        html += "<th>" + model->headerData(col, Qt::Horizontal).toString() + "</th>";
    }
    html += "</tr>";

    for (int row = 0; row < model->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 0; col < model->columnCount(); ++col) {
            QModelIndex index = model->index(row, col);
            html += "<td>" + model->data(index).toString() + "</td>";
        }
        html += "</tr>";
    }
    html += "</table>"
            "<p align='right'><small>Exporté le: " + QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm") + "</small></p>";

    doc.setHtml(html);
    doc.setPageSize(printer.pageRect(QPrinter::DevicePixel).size());
    doc.print(&printer);

    QMessageBox::information(this, "Export PDF", "La liste a été exportée dans:\n" + fileName);
}

void MainWindow::on_btnOpenLogin_clicked()
{
    LoginForm *login = new LoginForm(this);
    login->show();
}

void MainWindow::onAccessGranted(QString nom, QString prenom, QString poste)
{
    QString uid = serialHandler->lastUid();

    statusLabel->setText("Accès autorisé: " + prenom + " " + nom);
    statusLabel->setStyleSheet("color: green; font-weight: bold;");

    int row = ui->tableWidgetLogs->rowCount();
    ui->tableWidgetLogs->insertRow(row);
    ui->tableWidgetLogs->setItem(row, 0, new QTableWidgetItem(QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm")));
    ui->tableWidgetLogs->setItem(row, 1, new QTableWidgetItem(uid));
    ui->tableWidgetLogs->setItem(row, 2, new QTableWidgetItem(prenom + " " + nom));
    ui->tableWidgetLogs->setItem(row, 3, new QTableWidgetItem("Autorisé"));
    ui->tableWidgetLogs->scrollToBottom();
}

void MainWindow::onAccessDenied(QString uid)
{
    statusLabel->setText("Accès refusé - Badge: " + uid);
    statusLabel->setStyleSheet("color: red; font-weight: bold;");

    int row = ui->tableWidgetLogs->rowCount();
    ui->tableWidgetLogs->insertRow(row);
    ui->tableWidgetLogs->setItem(row, 0, new QTableWidgetItem(QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm")));
    ui->tableWidgetLogs->setItem(row, 1, new QTableWidgetItem(uid));
    ui->tableWidgetLogs->setItem(row, 2, new QTableWidgetItem("Inconnu"));
    ui->tableWidgetLogs->setItem(row, 3, new QTableWidgetItem("Refusé"));

    for (int col = 0; col < 4; ++col) {
        ui->tableWidgetLogs->item(row, col)->setBackground(QBrush(QColor(255, 200, 200)));
    }
}

void MainWindow::on_btnAssocierBadge_clicked()
{
    int id = ui->lineEdit_ID->text().toInt();
    if (id <= 0) {
        QMessageBox::warning(this, "Erreur", "ID employé invalide");
        return;
    }

    QDialog dialog(this);
    dialog.setWindowTitle("Association de Badge");
    QVBoxLayout layout(&dialog);

    QLabel label("Scannez le badge RFID...", &dialog);
    QLineEdit lineEdit(&dialog);
    lineEdit.setReadOnly(true);

    QPushButton btnCancel("Annuler", &dialog);

    layout.addWidget(&label);
    layout.addWidget(&lineEdit);
    layout.addWidget(&btnCancel);

    auto connection = connect(serialHandler, &SerialHandler::badgeDetected, [&](const QString &uid) {
        lineEdit.setText(uid);
        QTimer::singleShot(1000, &dialog, &QDialog::accept);
    });

    connect(&btnCancel, &QPushButton::clicked, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted && !lineEdit.text().isEmpty()) {
        QString uid = lineEdit.text();

        QSqlQuery query;
        query.prepare("UPDATE EMPLOYE SET BADGE_UID = ? WHERE ID_EMPLOYE = ?");
        query.addBindValue(uid);
        query.addBindValue(id);

        if (query.exec()) {
            QMessageBox::information(this, "Succès", QString("Badge %1 associé à l'employé %2").arg(uid).arg(id));
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de l'association: " + query.lastError().text());
        }
    }

    disconnect(connection);
}

void MainWindow::setupRFIDInterface()
{
    statusLabel = new QLabel(this);
    statusLabel->setAlignment(Qt::AlignCenter);
    statusLabel->setStyleSheet("font-size: 16px; padding: 10px;");
    ui->statusbar->addPermanentWidget(statusLabel);

    serialHandler = new SerialHandler(this);
    if (serialHandler->connectToArduino()) {
        connect(serialHandler, &SerialHandler::accessGranted,
                this, &MainWindow::onAccessGranted);
        connect(serialHandler, &SerialHandler::accessDenied,
                this, &MainWindow::onAccessDenied);
    }
}

void MainWindow::on_home_btn_5_clicked()
{
    MainArch *dialog = new MainArch(this);
    dialog->exec();
}

void MainWindow::on_customers_btn_4_clicked()
{
    MainClient *dialog = new MainClient(this);
    dialog->exec();
}

void MainWindow::on_orders_btn_3_clicked()
{
    MainEquip *dialog = new MainEquip(this);
    dialog->exec();
}

void MainWindow::on_products_btn_3_clicked()
{
    GProjett *dialog = new GProjett(this);
    dialog->exec();
}
