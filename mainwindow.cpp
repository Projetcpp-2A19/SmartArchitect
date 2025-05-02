#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include <QMessageBox>
#include <QSqlError>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , proxyModel(new QSortFilterProxyModel(this))
{
    ui->setupUi(this);
    setupRFIDInterface();
    ui->tableView->setModel(nullptr);
    ui->lineEditPassword->setEchoMode(QLineEdit::Password);
    connect(ui->btnTriSalaire, &QPushButton::clicked,
            this, &MainWindow::on_btnTriSalaire_clicked);
    // Nouvelle connexion pour l'export PDF (à ajouter ici)
    connect(ui->btnExportPDF, &QPushButton::clicked,
            this, &MainWindow::on_btnExportPDF_clicked);

    // Initialize the model
    QSqlQueryModel* sourceModel = emp.afficherEmployes();
    if (sourceModel) {
        proxyModel->setSourceModel(sourceModel);
        proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
        proxyModel->setFilterKeyColumn(-1);
        ui->tableView->setModel(proxyModel);
        ui->tableView->setSortingEnabled(true);

        // Permettre le tri par colonnes
        ui->tableView->sortByColumn(7, Qt::AscendingOrder);  // 6 est l'index de la colonne salaire
    } else {
        QMessageBox::warning(this, "Error", "Failed to load employee data!");
    }

    // Créez les colonnes avant d'ajouter des données
    ui->tableWidgetLogs->setColumnCount(4);
    ui->tableWidgetLogs->setHorizontalHeaderLabels({"Date/Heure", "UID Badge", "Employé", "Statut"});
    ui->tableWidgetLogs->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
MainWindow::~MainWindow()
{
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
        proxyModel->setSourceModel(emp.afficherEmployes());  // Rafraîchir la vue
    } else {
        QMessageBox::warning(this, "Erreur", "Ajout échoué !");
    }
    afficherEmployes();  // Rafraîchir la table
}
//-----------------------------------------------------------------------------------------------------
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
    QString hireDate = ui->dateEditHireDate->text(); // Utilisation du bon nom de widget

    if (emp.updateEmployee(employeeId, lastName, firstName, email,
                           password, position, salary, hireDate)) {
        QMessageBox::information(this, "Succès", "Employé modifié !");
        afficherEmployes();
    } else {
        QMessageBox::warning(this, "Erreur", "Modification échouée !");
    }
}

//-------------------------------------------------------------------------------------------------
/*void MainWindow::on_btnAnnuler_clicked()
{
    ui->lineEditEmployeeId->clear();
    ui->lineEditLastName->clear();
    ui->lineEditFirstName->clear();
    ui->lineEditEmail->clear();
    ui->lineEditPassword->clear();
    ui->lineEditPosition->clear();
    ui->lineEditSalary->clear();
    ui->dateEditHireDate->setText(QDate::currentDate().toString("yyyy-MM-dd")); // Utilisation du bon nom de widget

    ui->tableView->clearSelection();
    QMessageBox::information(this, "Annulation", "Tous les champs ont été réinitialisés.");
}*/
//-----------------------------------------------------------------------------------------------------
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
            afficherEmployes();
            proxyModel->invalidate();
        } else {
            QMessageBox::warning(this, "Erreur", "Suppression échouée !");
        }
    }
}
// Exemple d'une méthode dans mainwindow.cpp
/*void MainWindow::on_btnModifier_clicked() {
    // Récupérer les informations à partir de ton interface (par exemple QLineEdit)
    int id = ui->lineEditId->text().toInt(); // Récupère l'ID de l'employé depuis un QLineEdit
    QString NOM = ui->lineEditNom->text();  // Récupère le nom
    QString EMAIL= ui->lineEditEmail->text();  // Récupère l'email

    // Appeler la fonction modifierEmploye() avec les arguments appropriés
    if (e.modifierEmploye(IDEMPLOYEE, NOM, EMAIL)){
        // Faire quelque chose si la modification est réussie
        qDebug() << "Employé modifié avec succès!";
    } else {
        // Faire quelque chose si la modification échoue
        qDebug() << "Échec de la modification de l'employé!";
    }
}*/

//-----------------------------------------------------------------------------------------------------
void MainWindow::afficherEmployes()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM FIRAS.EMPLOYE");  // Charger les données

    if (model->lastError().isValid()) {
        qDebug() << "Erreur SQL :" << model->lastError().text();
    }

    ui->tableView->setModel(model);  // Associer le modèle au QTableView
}
//--------------------------------------------
void MainWindow::on_btnTriSalaire_clicked()
{
    qDebug() << "Bouton de tri cliqué";
    QSqlQueryModel* newModel = emp.trierEmployesParSalaireCroissant();
    if (newModel) {
        proxyModel->setSourceModel(newModel);
        ui->tableView->setModel(proxyModel);
        ui->tableView->sortByColumn(7, Qt::AscendingOrder); // 6 = index colonne salaire
        qDebug() << "Affichage des données triées";
    } else {
        qDebug() << "Échec du tri";
        QMessageBox::warning(this, "Erreur", "Le tri a échoué");
    }
}
//-------------------------------------------------
void MainWindow::on_btnRechercheIdNom_clicked()
{
    QString recherche = ui->lineEditRechercheIdNom->text().trimmed();

    if (recherche.isEmpty()) {
        // Si le champ est vide, afficher tous les employés
        afficherEmployes();
        return;
    }

    QSqlQueryModel* resultModel = emp.rechercherEmployee(recherche);
    if (resultModel && resultModel->rowCount() > 0) {
        proxyModel->setSourceModel(resultModel);
        ui->tableView->setModel(proxyModel);
    } else {
        QMessageBox::information(this, "Recherche", "Aucun résultat trouvé");
        delete resultModel;
    }
}
//--------------------------------------------------------------
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
//---------------------------------------------------------------------
void MainWindow::on_btnAnnuler_clicked()
{
    // Réinitialiser les champs texte
    ui->lineEditEmployeeId->clear();
    ui->lineEditLastName->clear();
    ui->lineEditFirstName->clear();
    ui->lineEditEmail->clear();
    ui->lineEditPassword->clear();
    ui->lineEditPosition->clear();
    ui->lineEditSalary->clear();

    // Réinitialiser le champ date (en utilisant le bon nom de widget)
    ui->dateEditHireDate->setText(QDate::currentDate().toString("yyyy-MM-dd"));

    // Effacer la sélection dans la table
    ui->tableView->clearSelection();

    QMessageBox::information(this, "Annulation", "Tous les champs ont été réinitialisés.");
}
//-------------------------------------------------------------------------
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

    // En-têtes de colonnes
    QAbstractItemModel *model = ui->tableView->model();
    for (int col = 0; col < model->columnCount(); ++col) {
        html += "<th>" + model->headerData(col, Qt::Horizontal).toString() + "</th>";
    }
    html += "</tr>";

    // Données des lignes
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

    // 1. Mise à jour de l'interface
    statusLabel->setText("Accès autorisé: " + prenom + " " + nom);
    statusLabel->setStyleSheet("color: green; font-weight: bold;");

    // 2. Journalisation
    int row = ui->tableWidgetLogs->rowCount();
    ui->tableWidgetLogs->insertRow(row);
    ui->tableWidgetLogs->setItem(row, 0, new QTableWidgetItem(QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm")));
    ui->tableWidgetLogs->setItem(row, 1, new QTableWidgetItem(uid));
    ui->tableWidgetLogs->setItem(row, 2, new QTableWidgetItem(prenom + " " + nom));
    ui->tableWidgetLogs->setItem(row, 3, new QTableWidgetItem("Autorisé"));
    ui->tableWidgetLogs->scrollToBottom();

    // 3. La commande OPEN est maintenant envoyée par SerialHandler après la vérification
}

void MainWindow::onAccessDenied(QString uid)
{
    // 1. Mise à jour de l'interface
    statusLabel->setText("Accès refusé - Badge: " + uid);
    statusLabel->setStyleSheet("color: red; font-weight: bold;");

    // 2. Journalisation
    int row = ui->tableWidgetLogs->rowCount();
    ui->tableWidgetLogs->insertRow(row);
    ui->tableWidgetLogs->setItem(row, 0, new QTableWidgetItem(QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm")));
    ui->tableWidgetLogs->setItem(row, 1, new QTableWidgetItem(uid));
    ui->tableWidgetLogs->setItem(row, 2, new QTableWidgetItem("Inconnu"));
    ui->tableWidgetLogs->setItem(row, 3, new QTableWidgetItem("Refusé"));

    for (int col = 0; col < 4; ++col) {
        ui->tableWidgetLogs->item(row, col)->setBackground(QBrush(QColor(255, 200, 200)));
    }

    // 3. Pas d'envoi de commande OPEN
}

void MainWindow::on_btnAssocierBadge_clicked()
{
    int id = ui->lineEdit_ID->text().toInt();
    if (id <= 0) {
        QMessageBox::warning(this, "Erreur", "ID employé invalide");
        return;
    }

    // Créer une boîte de dialogue personnalisée
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

    // Connecter le signal RFID
    auto connection = connect(serialHandler, &SerialHandler::badgeDetected, [&](const QString &uid) {
        lineEdit.setText(uid);
        QTimer::singleShot(1000, &dialog, &QDialog::accept); // Ferme après 1s
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

    disconnect(connection); // Nettoyer la connexion
}

void MainWindow::setupRFIDInterface()
{
    // Configuration du label de statut
    statusLabel = new QLabel(this);
    statusLabel->setAlignment(Qt::AlignCenter);
    statusLabel->setStyleSheet("font-size: 16px; padding: 10px;");
    ui->statusbar->addPermanentWidget(statusLabel);

    // Initialisation du handler RFID
    serialHandler = new SerialHandler(this);
    if(serialHandler->connectToArduino()) {
        connect(serialHandler, &SerialHandler::accessGranted,
                this, &MainWindow::onAccessGranted);
        connect(serialHandler, &SerialHandler::accessDenied,
                this, &MainWindow::onAccessDenied);
    }
}
