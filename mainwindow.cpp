#include <QRegularExpressionValidator>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "equipement.h"
#include <QDate>
#include <QDateEdit>
#include <QSqlRecord>
#include <QFormLayout>
#include "chatbot.h"
#include <QPainter>
#include <QPdfWriter>
#include <QFileDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>
#include <QPdfWriter>
#include <QPixmap>
#include <QNetworkAccessManager>
#include <QNetworkReply>





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
    connect(ui->exporter, &QPushButton::clicked, this, &MainWindow::exporterPDF);
    connect(ui->pushButton_trier, &QPushButton::clicked, this, &MainWindow::on_pushButton_trier_clicked);



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








    // Générer le contenu du code-barres avec toutes les infos
    QString code_barre = QString("Nom: %1\nType: %2\nQuantité: %3\nDate: %4\nBudget: %5\nCaractéristiques: %6")
                             .arg(nom)
                             .arg(type)
                             .arg(quantite)
                             .arg(datedachat.toString("dd/MM/yyyy"))
                             .arg(budget)
                             .arg(caracteristiques);

    // Créer l'équipement avec ce contenu
    equipement e(nom, quantite, type, datedachat, budget, caracteristiques);
    e.setCode_barre(code_barre);  // ✅ Très important pour l’enregistrer dans la base


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
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    // Exécuter la requête
    QSqlQuery query("SELECT * FROM EQUIPEMENT");

    int columnCount = query.record().count();
    ui->tableWidget->setColumnCount(columnCount);



    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);

        for (int col = 0; col < columnCount; col++) {
            // Ne pas remplir la colonne 7 avec du texte (image à la place)
            if (col != 7) {
                ui->tableWidget->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
            }
        }

        QString code = query.value("CODE_BARRE").toString();

        // Vérifier s'il est déjà dans le cache
        if (barcodeCache.contains(code)) {
            QLabel* label = new QLabel();
            QPixmap cachedPix = barcodeCache[code];
            label->setPixmap(cachedPix.scaled(50, 20, Qt::KeepAspectRatio));
            label->setAlignment(Qt::AlignCenter);
            label->setCursor(Qt::PointingHandCursor);
            label->setProperty("fullPixmap", cachedPix);
            label->installEventFilter(this);
            ui->tableWidget->setCellWidget(row, 7, label);
        } else {
            QString codeBarrePath = query.value("CODE_BARRE_PATH").toString();

            if (QFile::exists(codeBarrePath)) {
                QPixmap pix(codeBarrePath);

                // Sauvegarde dans le cache si besoin
                barcodeCache[code] = pix;

                QLabel* label = new QLabel();
                QPixmap scaledPix = pix.scaled(50, 20, Qt::KeepAspectRatio);
                label->setPixmap(scaledPix);
                label->setAlignment(Qt::AlignCenter);
                label->setCursor(Qt::PointingHandCursor);
                label->setProperty("fullPixmap", pix);
                label->installEventFilter(this);
                ui->tableWidget->setCellWidget(row, 7, label);
            } else {
                ui->tableWidget->setItem(row, 7, new QTableWidgetItem("Image introuvable"));
            }

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



void MainWindow::on_pushButton_trouver_clicked()
{
    QString nom = ui->lineEdit_nomcherch->text();
    QString type = ui->lineEdit_typecherch->text();

    // Vérifier si les champs ne sont pas vides
    if (nom.isEmpty() || type.isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Veuillez remplir les champs Nom et Type.");
        return;
    }

    // 2. Préparer la requête SQL
    QSqlQuery query;
    query.prepare("SELECT * FROM EQUIPEMENT WHERE NOM = :nom AND TYPE = :type");
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);

    // 3. Exécuter la requête
    if (query.exec() && query.next()) {
        // L'équipement existe, on affiche ses informations
        int columnCount = query.record().count();
        ui->tableWidget->setRowCount(0); // Réinitialiser la table
        ui->tableWidget->setColumnCount(columnCount);

        // Insérer la ligne de l'équipement trouvé
        ui->tableWidget->insertRow(0);
        for (int col = 0; col < columnCount; col++) {
            ui->tableWidget->setItem(0, col, new QTableWidgetItem(query.value(col).toString()));
        }

        QMessageBox::information(this, "Succès", "Équipement trouvé et affiché.");
    } else {
        // Aucune correspondance trouvée
        QMessageBox::warning(this, "Non trouvé", "Aucun équipement ne correspond à votre recherche.");
    }

}
void MainWindow::on_commandLinkButton_chatbot_clicked()
{
    chatbot chatbot;
    chatbot.exec();  // Ouvrir la fenêtre en mode dialogue
}





void MainWindow::exporterPDF()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty())
        return;

    // Préparer la requête SQL
    QSqlQuery query;
    query.prepare("SELECT ID_EQUIPEMENT, NOM, QUANTITE, TYPE, DATEDACHAT, BUDGET, CARACTERISTIQUES FROM EQUIPEMENT");

    if (!query.exec()) {
        qDebug() << "❌ Erreur SQL (ODBC):" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'exécution de la requête.\n" + query.lastError().text());
        return;
    }

    // Construction HTML du tableau
    QString html = R"(
        <html>
        <head>
            <style>
                table { border-collapse: collapse; width: 100%; }
                th, td { border: 1px solid black; padding: 8px; font-size: 10pt; text-align: left; }
                th { background-color: #f2f2f2; }
                h2 { text-align: center; font-family: Arial; }
            </style>
        </head>
        <body>
            <h2>Liste des Équipements</h2>
            <table>
                <tr>
                    <th>ID</th>
                    <th>Nom</th>
                    <th>Quantité</th>
                    <th>Type</th>
                    <th>Date d'achat</th>
                    <th>Budget</th>
                    <th>Caractéristiques</th>
                </tr>
    )";

    // Ajouter les lignes du tableau à partir de la base de données
    while (query.next()) {
        html += "<tr>";
        html += "<td>" + query.value(0).toString() + "</td>";
        html += "<td>" + query.value(1).toString() + "</td>";
        html += "<td>" + query.value(2).toString() + "</td>";
        html += "<td>" + query.value(3).toString() + "</td>";
        html += "<td>" + query.value(4).toDate().toString("dd/MM/yyyy") + "</td>";
        html += "<td>" + query.value(5).toString() + "</td>";
        html += "<td>" + query.value(6).toString() + "</td>";
        html += "</tr>";
    }

    html += "</table></body></html>";

    // Création du PDF avec QTextDocument
    QTextDocument document;
    document.setHtml(html);

    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize::A4);
    writer.setPageMargins(QMarginsF(15, 15, 15, 15));

    document.print(&writer);

    QMessageBox::information(this, "Succès", "Le fichier PDF a été généré avec succès.");
}





void MainWindow::on_pushButton_trier_clicked() {
    QSqlQuery query;
    query.prepare("SELECT ID_EQUIPEMENT, NOM, QUANTITE, TYPE, DATEDACHAT, BUDGET, CARACTERISTIQUES FROM EQUIPEMENT ORDER BY DATEDACHAT DESC");

    if (!query.exec()) {
        qDebug() << "❌ Erreur lors du tri :" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Impossible de trier les équipements !");
        return;
    }

    int columnCount = query.record().count();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(columnCount);

    // Ajoute les entêtes si nécessaire
    QStringList headers = {"ID", "Nom", "Quantité", "Type", "Date d'achat", "Budget", "Caractéristiques"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);
        for (int col = 0; col < columnCount; ++col) {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++;
    }

    qDebug() << "✅ Tri effectué avec succès.";
}
void MainWindow::afficherCodeBarreZoom(QPixmap pixmap) {
    // Création de la boîte de dialogue zoom
    QDialog* zoomDialog = new QDialog(this);
    zoomDialog->setWindowTitle("Code-barres (Zoom)");

    // Création d'un QLabel pour afficher l'image
    QLabel* zoomLabel = new QLabel(zoomDialog);
    // Zoomer l'image dans une taille très grande
    zoomLabel->setPixmap(pixmap.scaled(800, 600, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    zoomLabel->setAlignment(Qt::AlignCenter);

    // Créer une disposition verticale pour la boîte de dialogue
    QVBoxLayout* layout = new QVBoxLayout(zoomDialog);
    layout->addWidget(zoomLabel);

    // Appliquer la disposition à la boîte de dialogue
    zoomDialog->setLayout(layout);

    // Option : Maximiser la boîte de dialogue
    zoomDialog->showMaximized(); // Afficher en mode maximisé

    // Exécuter la boîte de dialogue
    zoomDialog->exec();
}

bool MainWindow::eventFilter(QObject* watched, QEvent* event) {
    if (event->type() == QEvent::MouseButtonPress) {
        QLabel* label = qobject_cast<QLabel*>(watched);
        if (label) {
            // Récupérer l'image complète associée à l'étiquette
            QPixmap fullPixmap = label->property("fullPixmap").value<QPixmap>();

            // Créer une boîte de dialogue pour afficher l'image en grand
            QDialog* popup = new QDialog(this);
            popup->setWindowTitle("Code-barres (Zoom)");

            // Définir la taille de la fenêtre
            popup->resize(600, 700); // Taille plus grande et lisible

            // Créer un QLabel pour afficher l'image zoomée
            QLabel* imageLabel = new QLabel(popup);
            imageLabel->setPixmap(fullPixmap.scaled(800, 600, Qt::KeepAspectRatio, Qt::SmoothTransformation)); // Très grande taille
            imageLabel->setAlignment(Qt::AlignCenter);

            // Créer la disposition pour le popup
            QVBoxLayout* layout = new QVBoxLayout(popup);
            layout->addWidget(imageLabel);
            popup->setLayout(layout);

            // Option : Maximiser ou afficher en plein écran
            popup->showMaximized(); // Ou showFullScreen() si tu veux prendre tout l'écran

            // Exécuter la boîte de dialogue
            popup->exec();
            return true;
        }
    }
    return false;
}





