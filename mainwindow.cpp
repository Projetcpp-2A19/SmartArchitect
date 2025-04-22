#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chatbotwindow.h"
#include <QMessageBox>
#include <QSqlError>
#include <QRegularExpression>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QChartView>
#include <QPieSeries>
#include <QChart>
#include <QLegend>
#include "qrcodegen.hpp"
using namespace qrcodegen;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), proxyModelFournisseurs(new QSortFilterProxyModel(this)) {
    ui->setupUi(this);



    // 📌 Initialisation du modèle et tri pour les fournisseurs
    proxyModelFournisseurs->setSourceModel(fournisseur.afficherFournisseurs());
    proxyModelFournisseurs->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxyModelFournisseurs->setFilterKeyColumn(-1);  // Recherche sur toutes les colonnes

    ui->tableViewFournisseurs->setModel(proxyModelFournisseurs);
    ui->tableViewFournisseurs->setSortingEnabled(true);

    ui->comboBox_villeFournisseur->addItems(QStringList()
                                            << "Tunis" << "Ariana" << "Ben Arous" << "La Marsa" << "Le Kram" << "El Menzah"
                                            << "Manouba" << "Bizerte" << "Beja" << "Jendouba" << "Kef" << "Siliana"
                                            << "Nabeul" << "Hammamet" << "Zaghouan" << "Sousse" << "Monastir" << "Mahdia"
                                            << "Kairouan" << "Kasserine" << "Sidi Bouzid"
                                            << "Sfax" << "Gabès" << "Médenine" << "Tataouine"
                                            << "Gafsa" << "Tozeur" << "Kebili" << "Douz" << "Nefta"
                                            );
    ui->comboBox_etat->addItems(QStringList() << "Disponible" << "En réparation" << "Hors service" << "Obsolète");


}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btnAjouterFournisseur_clicked() {
    QString nom = ui->lineEdit_nomFournisseur->text();
    QString telephone = ui->lineEdit_telephoneFournisseur->text();
    QString adresse = ui->lineEdit_adresseFournisseur->text();
    QString ville = ui->comboBox_villeFournisseur->currentText();
    QString etat = ui->comboBox_etat->currentText();
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
    QString ville = ui->comboBox_villeFournisseur->currentText();
    QString etat = ui->comboBox_etat->currentText();
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


void MainWindow::on_btnRechercher_clicked()
{
    QString villeRecherchee = ui->searchBar->text();  // Champ QLineEdit à créer dans l'UI
    proxyModelFournisseurs->setFilterKeyColumn(4); // 4 = colonne "ville", à ajuster si besoin
    proxyModelFournisseurs->setFilterRegularExpression(QRegularExpression(villeRecherchee, QRegularExpression::CaseInsensitiveOption));
}

void MainWindow::on_btnExporterPDF_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");

    // Vérifier si l'utilisateur a annulé la sélection
    if (fileName.isEmpty())
        return;

    // Assurez-vous que l'extension ".pdf" est présente
    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive))
        fileName += ".pdf";

    // Vérifier si le chemin de fichier existe
    QFileInfo fileInfo(fileName);
    if (!fileInfo.dir().exists()) {
        QMessageBox::warning(this, "Erreur", "Le dossier spécifié n'existe pas.");
        return;
    }

    // Créer le HTML
    QString html = "<h2 style='text-align:center;'>Liste des Fournisseurs</h2>";
    html += "<table border='1' cellspacing='0' cellpadding='5' style='width:100%; font-size:10pt;'>";
    html += "<tr style='background-color:#f0f0f0;'>";
    html += "<th>ID</th><th>Nom</th><th>Téléphone</th><th>Adresse</th><th>Ville</th><th>État</th><th>Commande</th><th>Email</th>";
    html += "</tr>";

    QSqlQuery query("SELECT * FROM FOURNISSEURS");
    while (query.next()) {
        html += "<tr>";
        for (int i = 0; i < 8; ++i) {
            html += "<td>" + query.value(i).toString().toHtmlEscaped() + "</td>";
        }
        html += "</tr>";
    }

    html += "</table>";

    // Préparer le document HTML
    QTextDocument doc;
    doc.setHtml(html);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    // Appel direct à print sans vérifier le résultat
    doc.print(&printer);

    QMessageBox::information(this, "Exportation PDF", "Le fichier PDF a été généré avec succès !");
}

void MainWindow::on_btnStatistiques_clicked()
{
    // Créer un graphique en secteurs
    QPieSeries *series = new QPieSeries();
    // Récupérer les données de la base de données
    QSqlQuery query("SELECT VILLE, COUNT(*) FROM FOURNISSEURS GROUP BY VILLE");
    while (query.next()) {
        QString ville = query.value(0).toString();
        int count = query.value(1).toInt();
        series->append(ville, count);
    }

    // Créer le graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des fournisseurs par ville");
    chart->legend()->setVisible(true);

    // Afficher le graphique dans un QChartView
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Ajouter le graphique dans un layout
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(chartView);
    QWidget *chartWidget = new QWidget();
    chartWidget->setLayout(layout);
    chartWidget->show();
}

QImage generateQrCode(const QString &text, int size = 200) {
    QrCode qr = QrCode::encodeText(text.toUtf8().constData(), QrCode::Ecc::LOW);

    const int scale = size / qr.getSize();
    QImage image(qr.getSize() * scale, qr.getSize() * scale, QImage::Format_RGB32);
    image.fill(Qt::white);

    QPainter painter(&image);
    painter.setBrush(Qt::black);
    for (int y = 0; y < qr.getSize(); ++y) {
        for (int x = 0; x < qr.getSize(); ++x) {
            if (qr.getModule(x, y)) {
                painter.drawRect(x * scale, y * scale, scale, scale);
            }
        }
    }

    return image;
}
void MainWindow::on_btnAfficherQR_clicked() {
    QModelIndex index = ui->tableViewFournisseurs->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un fournisseur !");
        return;
    }

    int row = proxyModelFournisseurs->mapToSource(index).row();
    QAbstractItemModel *model = proxyModelFournisseurs->sourceModel();

    QString id = model->index(row, 0).data().toString();
    QString nom = model->index(row, 1).data().toString();
    QString telephone = model->index(row, 2).data().toString();
    QString adresse = model->index(row, 3).data().toString();
    QString ville = model->index(row, 4).data().toString();
    QString etat = model->index(row, 5).data().toString();
    QString commande = model->index(row, 6).data().toString();
    QString email = model->index(row, 7).data().toString();

    QString contenu = QString("ID: %1\nNom: %2\nTéléphone: %3\nAdresse: %4\nVille: %5\nÉtat: %6\nCommande: %7\nEmail: %8")
                          .arg(id, nom, telephone, adresse, ville, etat, commande, email);

    QImage qrImage = generateQrCode(contenu, 250);

    // Créer une fenêtre modale avec un layout
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("QR Code Fournisseur");
    dialog->setModal(true);
    dialog->setFixedSize(300, 350);

    QLabel *qrLabel = new QLabel;
    qrLabel->setPixmap(QPixmap::fromImage(qrImage));
    qrLabel->setAlignment(Qt::AlignCenter);

    QPushButton *btnFermer = new QPushButton("Fermer");
    connect(btnFermer, &QPushButton::clicked, dialog, &QDialog::accept);

    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(qrLabel);
    layout->addWidget(btnFermer, 0, Qt::AlignCenter);

    dialog->exec(); // Afficher la fenêtre modale
}

void MainWindow::on_btnChatbot_clicked() {
    ChatbotWindow *chat = new ChatbotWindow(this);
    chat->exec();
}













