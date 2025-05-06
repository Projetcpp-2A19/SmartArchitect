#include "mainprojet.h"
#include "ui_mainprojet.h"
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
#include <QSerialPortInfo>
#include <QInputDialog>
using namespace qrcodegen;

MainProjet::MainProjet(QWidget *parent)
    : QDialog(parent), ui(new Ui::MainProjet), proxyModelFournisseurs(new QSortFilterProxyModel(this)) {
    ui->setupUi(this);
    setWindowTitle("Gestion des Fournisseurs");
    setModal(true); // Make the dialog modal

    // Initialisation de l'Arduino
    arduino = new ArduinoManager(this);
    setupArduinoUI();

    // Connexion des signaux Arduino
    connect(arduino, &ArduinoManager::temperatureChanged, this, &MainProjet::updateTemperature);
    connect(arduino, &ArduinoManager::humidityChanged, this, &MainProjet::updateHumidity);
    connect(arduino, &ArduinoManager::errorOccurred, this, &MainProjet::handleArduinoError);

    // Initialisation du modèle et tri pour les fournisseurs
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

MainProjet::~MainProjet() {
    delete ui;
}

void MainProjet::on_btnAjouterFournisseur_clicked() {
    QString nom = ui->lineEdit_nomFournisseur->text();
    QString telephone = ui->lineEdit_telephoneFournisseur->text();
    QString adresse = ui->lineEdit_adresseFournisseur->text();
    QString ville = ui->comboBox_villeFournisseur->currentText();
    QString etat = ui->comboBox_etat->currentText();
    QString commande = ui->lineEdit_commandeFournisseur->text();
    QString email = ui->lineEdit_emailFournisseur->text();
    // Vérification que les champs obligatoires ne sont pas vides
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le champ 'Nom' est obligatoire !");
        return;
    }

    // Validation du numéro de téléphone (8 à 15 chiffres)
    QRegularExpression regexTel("^[0-9]{8,15}$");
    if (!telephone.isEmpty() && !regexTel.match(telephone).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Numéro de téléphone invalide ! (8-15 chiffres)");
        return;
    }

    // Validation de l'email
    QRegularExpression regexEmail("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,4}$");
    if (!email.isEmpty() && !regexEmail.match(email).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Email invalide !");
        return;
    }

    Fournisseur f(-1, nom, telephone, adresse, ville, etat, commande, email);

    if (f.ajouterFournisseur()) {
        QMessageBox::information(this, "Succès", "Fournisseur ajouté !");
        proxyModelFournisseurs->setSourceModel(fournisseur.afficherFournisseurs());  // Rafraîchir la vue
    } else {
        QMessageBox::warning(this, "Erreur", "Ajout échoué !");
    }
}

void MainProjet::on_btnModifierFournisseur_clicked() {
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

void MainProjet::on_btnSupprimerFournisseur_clicked() {
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

void MainProjet::on_btnRechercher_clicked()
{
    QString villeRecherchee = ui->searchBar->text();
    proxyModelFournisseurs->setFilterKeyColumn(4); // 4 = colonne "ville"
    proxyModelFournisseurs->setFilterRegularExpression(QRegularExpression(villeRecherchee, QRegularExpression::CaseInsensitiveOption));
}

void MainProjet::on_btnExporterPDF_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");

    if (fileName.isEmpty())
        return;

    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive))
        fileName += ".pdf";

    QFileInfo fileInfo(fileName);
    if (!fileInfo.dir().exists()) {
        QMessageBox::warning(this, "Erreur", "Le dossier spécifié n'existe pas.");
        return;
    }

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

    QTextDocument doc;
    doc.setHtml(html);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    doc.print(&printer);

    // Explicitly cast 'this' to QWidget* to ensure compatibility
    QMessageBox::information(static_cast<QWidget*>(this), "Exportation PDF", "Le fichier PDF a été généré avec succès !");
}

void MainProjet::on_btnStatistiques_clicked()
{
    QPieSeries *series = new QPieSeries();
    QSqlQuery query("SELECT VILLE, COUNT(*) FROM FOURNISSEURS GROUP BY VILLE");
    while (query.next()) {
        QString ville = query.value(0).toString();
        int count = query.value(1).toInt();
        series->append(ville, count);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des fournisseurs par ville");
    chart->legend()->setVisible(true);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QDialog *chartDialog = new QDialog(this);
    chartDialog->setWindowTitle("Statistiques");
    QVBoxLayout *layout = new QVBoxLayout(chartDialog);
    layout->addWidget(chartView);
    chartDialog->setLayout(layout);
    chartDialog->show();
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

void MainProjet::on_btnAfficherQR_clicked() {
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

    dialog->exec();
}

void MainProjet::on_btnChatbot_clicked() {
    ChatbotWindow *chat = new ChatbotWindow(this);
    chat->exec();
}

void MainProjet::setupArduinoUI() {
    updatePortList();
    connect(ui->connectButton, &QPushButton::clicked, this, &MainProjet::on_connectButton_clicked);
    connect(ui->setThresholdButton, &QPushButton::clicked, this, &MainProjet::on_setThresholdButton_clicked);
    ui->temperatureLabel->setText("Température: --°C");
    ui->humidityLabel->setText("Humidité: --%");
}

void MainProjet::updatePortList() {
    ui->portComboBox->clear();
    for (const QSerialPortInfo &info : QSerialPortInfo::availablePorts()) {
        ui->portComboBox->addItem(info.portName());
    }
}

void MainProjet::on_connectButton_clicked()
{
    if (ui->portComboBox->count() == 0) {
        QMessageBox::warning(this, "Erreur Arduino", "Aucun port série disponible.");
        return;
    }

    if (!arduino->isConnected()) {
        QString portName = ui->portComboBox->currentText();
        if (!arduino->connectToArduino(portName)) {
            QMessageBox::warning(this, "Erreur Arduino", "Impossible de se connecter à l'Arduino sur le port sélectionné.");
            return;
        }
    }

    if (!arduino->isMonitoringActive()) {
        arduino->startMonitoring();
        ui->connectButton->setText("Arrêter la surveillance");
    } else {
        arduino->stopMonitoring();
        ui->connectButton->setText("Démarrer la surveillance");
    }
}

void MainProjet::on_setThresholdButton_clicked()
{
    bool ok = false;
    double threshold = ui->thresholdLineEdit->text().toDouble(&ok);
    if (ok && threshold > 0) {
        arduino->setTemperatureThreshold(threshold);
        QMessageBox::information(this, "Seuil de température",
                                 QString("Le seuil de température a été défini à %1°C").arg(threshold));
    } else {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une valeur numérique valide dans le champ du seuil.");
    }
}

void MainProjet::updateTemperature(float temperature)
{
    ui->temperatureLabel->setText(QString("Température: %1°C").arg(temperature, 0, 'f', 1));
}

void MainProjet::updateHumidity(float humidity)
{
    ui->temperatureLabel->setText(QString("Humidité: %1%").arg(humidity, 0, 'f', 1));
}

void MainProjet::handleArduinoError(const QString &error)
{
    QMessageBox::warning(this, "Erreur Arduino", error);
}
