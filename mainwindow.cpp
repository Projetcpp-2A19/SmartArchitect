#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include <QMessageBox>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , proxyModel(new QSortFilterProxyModel(this))
{
    ui->setupUi(this);

    ui->lineEditPassword->setEchoMode(QLineEdit::Password);

    // Initialize the model
    QSqlQueryModel* sourceModel = emp.afficherEmployes();
    if (sourceModel) {
        proxyModel->setSourceModel(sourceModel);
        proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
        proxyModel->setFilterKeyColumn(-1);
        ui->tableView->setModel(proxyModel);
        ui->tableView->setSortingEnabled(true);
    } else {
        QMessageBox::warning(this, "Error", "Failed to load employee data!");
    }
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
void MainWindow::on_btnModifier_clicked() {
    // Récupérer l'index de l'employé sélectionné dans la table
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Erreur", "Sélectionnez un employé à modifier !");
        return;
    }

    // Récupérer l'ID de l'employé sélectionné
    int employeeId = proxyModel->data(proxyModel->index(index.row(), 0)).toInt();

    // Récupérer les informations modifiées depuis l'interface utilisateur
    QString lastName = ui->lineEditLastName->text();
    QString firstName = ui->lineEditFirstName->text();
    QString email = ui->lineEditEmail->text();
    QString password = ui->lineEditPassword->text();
    QString position = ui->lineEditPosition->text();
    QString salary = ui->lineEditSalary->text();
    QString hireDate = ui->dateEditHireDate->text();

    // Créer un objet Employee avec les nouvelles valeurs
    Employee e(employeeId, lastName, firstName, email, password, position, salary, hireDate);

    // Appeler modifierEmploye() avec les bons arguments
    if (e.modifierEmploye(employeeId, lastName, email)) {  // Passer ID, Nom et Email
        QMessageBox::information(this, "Succès", "Employé modifié !");
        afficherEmployes();
        proxyModel->invalidate();
    } else {
        QMessageBox::warning(this, "Erreur", "Modification échouée !");
    }
}

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
    model->setQuery("SELECT * FROM NOUR.EMPLOYEE");  // Charger les données

    if (model->lastError().isValid()) {
        qDebug() << "Erreur SQL :" << model->lastError().text();
    }

    ui->tableView->setModel(model);  // Associer le modèle au QTableView
}
