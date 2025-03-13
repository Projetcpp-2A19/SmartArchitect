#include <QRegularExpressionValidator>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "equipement.h"
#include <QDate>
#include <QDateEdit>
#include <QSqlRecord>
#include <QFormLayout>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrAjouterArchitecte = new AjouterArchitecte();
    ptrSupprimerArchitecte = new SupprimerArchitecte();
    ptrFindArchitecte = new FindArchitecte ();
    ptrUpdateArchitecte= new UpdateArchitecte();
    ptrchatbot= new chatbot();
    connect(ui->pushButton_ajouter, &QPushButton::clicked, this, &MainWindow::on_pushButton_ajouter_clicked);
    connect(ui->pushButton_Afficher, &QPushButton::clicked, this, &MainWindow::on_pushButton_Afficher_clicked);

}

MainWindow::~MainWindow()
{
    delete ptrAjouterArchitecte;
    delete ptrFindArchitecte;
    delete ptrSupprimerArchitecte;
    delete ptrUpdateArchitecte;
    delete ptrchatbot;
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    ptrUpdateArchitecte->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    ptrSupprimerArchitecte->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    ptrFindArchitecte->show();
}



void MainWindow::on_pushButton_ajouter_clicked()
{
    qDebug() << "Bouton Ajouter cliqué !";

    int quantite = ui->lineEdit_quantite->text().toInt();
    int budget = ui->lineEdit_budget->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString type = ui->lineEdit_type->text();  // Correction ici (text() au lieu de textt())

    QDate datedachat = ui->dateEdit_datedachat->date();  // Conversion correcte
    QString caracteristiques = ui->lineEdit_caracteristiques->text();

    // Expression régulière pour valider les champs texte
    QRegularExpression nomRegex("^[A-Za-z\\s]{3,}$");  // Nom : Lettres + espaces (min 3 caractères)
    QRegularExpression typeRegex("^[A-Za-z\\s]+$");    // Type : Lettres + espaces uniquement
    QRegularExpression caractRegex("^.{5,}$");         // Caractéristiques : min 5 caractères

    // Vérification des champs
    if (nom.isEmpty() || type.isEmpty() || caracteristiques.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Tous les champs doivent être remplis !");
        return;
    }
    if (!nomRegex.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le nom doit contenir au moins 3 lettres !");
        return;
    }
    if (!typeRegex.match(type).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le type ne doit contenir que des lettres et espaces !");
        return;
    }
    if (!caractRegex.match(caracteristiques).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Les caractéristiques doivent contenir au moins 5 caractères !");
        return;
    }
    if (quantite <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "La quantité doit être un entier positif !");
        return;
    }
    if (budget <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "Le budget doit être un entier positif !");
        return;
    }

    equipement e(nom, quantite, type, datedachat, budget, caracteristiques);

    //bool test = e.ajouter();
    if (e.ajouter()) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\nCliquez sur Annuler pour quitter."),
                                 QMessageBox::Cancel);
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Ajout non effectué.\nCliquez sur Annuler pour quitter."),
                              QMessageBox::Cancel);
    }
}
void MainWindow::on_pushButton_Afficher_clicked() {
    // Créer un objet de la classe equipement
    equipement e;

    // Exécuter la requête et récupérer les données
    QSqlQuery query("SELECT * FROM EQUIPEMENT");

    // Vérifier si la requête est valide


    // Récupérer le nombre de colonnes
    int columnCount = query.record().count();

    // Définir le nombre de lignes et de colonnes dans le QTableWidget
    ui->tableWidget->setRowCount(0); // Réinitialiser le QTableWidget
    ui->tableWidget->setColumnCount(columnCount);

    // Remplir le tableau avec les données
    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);

        for (int col = 0; col < columnCount; col++) {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++;
    }
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    // Récupérer l'ID entré dans le champ lineEdit_idsupp
    int id = ui->lineEdit_idsupp->text().toInt();


    equipement e;


    // Afficher un message de confirmation ou d'erreur
    if (e.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Équipement supprimé avec succès !");

    } else {
        QMessageBox::critical(this, "Erreur", "La suppression a échoué !");
    }
}


void MainWindow::on_pushButton_modifier_clicked() {
    int id = ui->lineEdit_idmodif->text().toInt(); // Récupérer l'ID

    QSqlQuery query;
    query.prepare("SELECT NOM, QUANTITE, TYPE, DATEDACHAT, BUDGET, CARACTERISTIQUES FROM EQUIPEMENT WHERE ID_EQUIPEMENT = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        // Récupérer les valeurs actuelles
        QString nom = query.value("NOM").toString();
        int quantite = query.value("QUANTITE").toInt();
        QString type = query.value("TYPE").toString();
        QDate datedachat = query.value("DATEDACHAT").toDate();
        int budget = query.value("BUDGET").toInt();
        QString caracteristiques = query.value("CARACTERISTIQUES").toString();

        // Créer une boîte de dialogue modifiable
        QDialog dialog(this);
        dialog.setWindowTitle("Modifier l'équipement");
        QFormLayout form(&dialog);

        // Champs modifiables
        QLineEdit nomEdit(nom, &dialog);
        QLineEdit quantiteEdit(QString::number(quantite), &dialog);
        QLineEdit typeEdit(type, &dialog);
        QDateEdit dateEdit(&dialog);
        dateEdit.setDate(datedachat);
        QLineEdit budgetEdit(QString::number(budget), &dialog);
        QLineEdit caracteristiquesEdit(caracteristiques, &dialog);

        QRegularExpressionValidator nomValidator(QRegularExpression("^[A-Za-z\\s]{3,}$"), &nomEdit); // Nom : lettres uniquement, min 3 caractères
        nomEdit.setValidator(&nomValidator);

        QRegularExpressionValidator quantiteValidator(QRegularExpression("^[1-9][0-9]*$"), &quantiteEdit); // Quantité : entier positif
        quantiteEdit.setValidator(&quantiteValidator);

        QRegularExpressionValidator typeValidator(QRegularExpression("^[A-Za-z\\s]+$"), &typeEdit); // Type : lettres uniquement
        typeEdit.setValidator(&typeValidator);

        QRegularExpressionValidator budgetValidator(QRegularExpression("^[1-9][0-9]*$"), &budgetEdit); // Budget : entier positif
        budgetEdit.setValidator(&budgetValidator);

        QRegularExpressionValidator caracteristiquesValidator(QRegularExpression("^.{5,}$"), &caracteristiquesEdit); // Caractéristiques : min 5 caractères
        caracteristiquesEdit.setValidator(&caracteristiquesValidator);


        // Ajouter les champs au formulaire
        form.addRow("Nom :", &nomEdit);
        form.addRow("Quantité :", &quantiteEdit);
        form.addRow("Type :", &typeEdit);
        form.addRow("Date d'achat :", &dateEdit);
        form.addRow("Budget :", &budgetEdit);
        form.addRow("Caractéristiques :", &caracteristiquesEdit);

        // Boutons "Annuler" et "Enregistrer"
        QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &dialog);
        form.addRow(&buttonBox);

        QObject::connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
        QObject::connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

        // Ouvrir la boîte de dialogue
        if (dialog.exec() == QDialog::Accepted) {
            // Mise à jour avec les nouvelles valeurs
            equipement e;
            if (e.modifier(id, nomEdit.text(), quantiteEdit.text().toInt(), typeEdit.text(),
                           dateEdit.date(), budgetEdit.text().toInt(), caracteristiquesEdit.text())) {
                QMessageBox::information(this, "Succès", "Équipement modifié avec succès !");
                on_pushButton_Afficher_clicked(); // Rafraîchir l'affichage
            } else {
                QMessageBox::critical(this, "Erreur", "Échec de la modification !");
            }
        }
    } else {
        QMessageBox::warning(this, "Erreur", "Aucun équipement trouvé avec cet ID.");
    }
}


