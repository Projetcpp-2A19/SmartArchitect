#include "mainarch.h"
#include "ui_mainarch.h"
#include "architecte.h"  // Include the architecte class
#include "mainwindow.h"  // Include MainWindow here
#include <QMessageBox>   // Include QMessageBox for message dialogs
#include <QSqlError>    // Required for lastError()
#include <QDebug>       // Required for qDebug() to output errors
#include <QSqlQuery>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QSqlQuery>
#include <QThread>
#include "arduino.h"
#include <QSqlError>
#include <QCoreApplication>
#include <QThread>

MainArch::MainArch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainArch),
    mainWindow(nullptr)  // Initialize mainWindow to nullptr
{
    ui->setupUi(this);

    // ✅ Initialize Arduino object
    arduino = new Arduino(this);
    if (arduino->connectToArduino()) {
        qDebug() << "Arduino connecté.";
    } else {
        qDebug() << "Échec de connexion Arduino.";
    }


    // ✅ Connect the dashboard button
    connect(ui->dashborad_btn_2, &QPushButton::clicked,
            this, &MainArch::on_dashborad_btn_2_clicked);
    connect(ui->arduino, &QPushButton::clicked,
            this, &MainArch::on_arduino_clicked);

    // ✅ Load table data from database
    QSqlQueryModel* model = Etmp.afficher();  // Fetch the data from the database
    if (model) {
        ui->tableView->setModel(model);  // Set the model to the table view
    } else {
        qDebug() << "Failed to load data for the table.";
    }
}

// Destructor
MainArch::~MainArch()
{
    delete mainWindow;
    delete arduino;  // Clean up Arduino object
    delete ui;  // Clean up UI components
}

void MainArch::on_pushButton_7_clicked()
{
    // Récupérer les valeurs depuis l'interface
    QString nom = ui->lineEdit_nom->text().trimmed();
    QString prenom = ui->lineEdit_prenom->text().trimmed();
    QString telephoneStr = ui->lineEdit_telephone->text().trimmed();
    QString email = ui->lineEdit_email->text().trimmed();
    QString experience = ui->lineEdit_experience->text().trimmed();

    // Contrôle de saisie : Nom et Prénom
    QRegularExpression regexNomPrenom("^[A-Za-zÀ-ÿ\\s'-]+$");  // Lettres, espaces, accents, tirets
    if (nom.isEmpty() || !regexNomPrenom.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un nom valide (lettres uniquement).");
        return;
    }

    if (prenom.isEmpty() || !regexNomPrenom.match(prenom).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un prénom valide (lettres uniquement).");
        return;
    }

    // Contrôle de saisie : Téléphone (exactement 8 chiffres)
    if (telephoneStr.length() != 8 || !telephoneStr.toUInt()) {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
        return;
    }

    // Contrôle de saisie : Email
    if (!email.contains('@') || !email.contains('.')) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une adresse email valide.");
        return;
    }

    // Contrôle de saisie : Expérience
    if (experience.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une expérience.");
        return;
    }

    // Convertir téléphone
    int telephone = telephoneStr.toInt();

    // Créer un objet architecte
    architecte unArchitecte(0, nom, prenom, telephone, email, experience);

    // Essayer d'ajouter à la base
    bool ajoutRéussi = unArchitecte.ajouter();

    if (ajoutRéussi) {
        ui->tableView->setModel(Etmp.afficher());  // Rafraîchir l'affichage
        QMessageBox::information(this, "Succès", "Architecte ajouté avec succès !");
    } else {
        QMessageBox::warning(this, "Erreur", "L'ajout de l'architecte a échoué.");
    }
}

void MainArch::on_pushButton_8_clicked()
{
    QString idStr = ui->lineEdit_supprimer->text();  // Retrieve the input from the line edit

    // Check if the input is empty or not numeric
    bool isNumeric;
    int id = idStr.toInt(&isNumeric);  // Convert the text to an integer and check if the conversion was successful

    if (!isNumeric || id <= 0) {  // Check if the ID is a valid number and greater than 0
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;  // Stop the execution if validation fails
    }

    // Proceed with the deletion if ID is valid
    bool test = Etmp.supprimer(id);

    if (test) {
        // Refresh the table view after deletion
        ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(this, "Succès", "Suppression effectuée !");
    } else {
        QMessageBox::critical(this, "Erreur", "Suppression non effectuée.");
    }
}

bool isUpdateMode = false;  // Flag to track whether we're in view or update mode

void MainArch::on_pushButton_pdf_clicked()
{
    int id = ui->lineEdit_supprimer->text().toInt();
    if (Etmp.genererPDF(id)) {
        QMessageBox::information(this, "Succès", "PDF généré avec succès !");
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible de générer le PDF.");
    }
}

void MainArch::on_pushButton_search_clicked()
{
    QString searchName = ui->lineEdit_search->text();  // Get the name from a text field

    // Check if the search term is not empty
    if (!searchName.isEmpty()) {
        QSqlQueryModel* model = Etmp.searchByName(searchName);
        ui->tableView->setModel(model);  // Set the search results to the table view
    } else {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un nom à rechercher.");
    }
}

void MainArch::on_pushButton_sort_clicked()
{
    // Call the sorting function to get the sorted list
    QSqlQueryModel* sortedModel = Etmp.trierParNom();
    ui->tableView->setModel(sortedModel);  // Display sorted results in the table view
}

void MainArch::on_pushButton_update_2_clicked()
{
    QString idStr = ui->lineEdit_supprimer->text();
    bool ok;
    int id = idStr.toInt(&ok);

    if (!ok || id <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }

    QDialog updateDialog(this);
    updateDialog.setWindowTitle("Mettre à jour l'architecte");

    QLineEdit *lineEditNom = new QLineEdit(&updateDialog);
    QLineEdit *lineEditPrenom = new QLineEdit(&updateDialog);
    QLineEdit *lineEditTelephone = new QLineEdit(&updateDialog);
    QLineEdit *lineEditEmail = new QLineEdit(&updateDialog);
    QLineEdit *lineEditExperience = new QLineEdit(&updateDialog);

    QSqlQuery query;
    query.prepare("SELECT * FROM ARCHITECTES WHERE ID = :id");
    query.bindValue(":id", id);
    if (!(query.exec() && query.next())) {
        QMessageBox::warning(this, "Erreur", "Impossible de charger les données.");
        return;
    }

    QString oldNom = query.value("NOM").toString();
    QString oldPrenom = query.value("PRENOM").toString();
    QString oldTel = query.value("TELEPHONE").toString();
    QString oldEmail = query.value("EMAIL").toString();
    QString oldExp = query.value("EXPERIENCE").toString();

    lineEditNom->setText(oldNom);
    lineEditPrenom->setText(oldPrenom);
    lineEditTelephone->setText(oldTel);
    lineEditEmail->setText(oldEmail);
    lineEditExperience->setText(oldExp);

    QPushButton *updateButton = new QPushButton("Mettre à jour", &updateDialog);
    QPushButton *cancelButton = new QPushButton("Annuler", &updateDialog);

    QFormLayout *formLayout = new QFormLayout();
    formLayout->addRow("Nom", lineEditNom);
    formLayout->addRow("Prénom", lineEditPrenom);
    formLayout->addRow("Téléphone", lineEditTelephone);
    formLayout->addRow("Email", lineEditEmail);
    formLayout->addRow("Expérience", lineEditExperience);
    formLayout->addRow(updateButton, cancelButton);

    updateDialog.setLayout(formLayout);

    QObject::connect(updateButton, &QPushButton::clicked, this, [this, &updateDialog, id, lineEditNom, lineEditPrenom, lineEditTelephone, lineEditEmail, lineEditExperience, oldNom, oldPrenom, oldTel, oldEmail, oldExp]() {
        QMap<QString, QVariant> updateFields;
        QRegularExpression regexNomPrenom("^[A-Za-zÀ-ÿ\\s'-]+$");

        QString newNom = lineEditNom->text().trimmed();
        if (newNom != oldNom && !newNom.isEmpty()) {
            if (!regexNomPrenom.match(newNom).hasMatch()) {
                QMessageBox::warning(&updateDialog, "Erreur", "Nom invalide (lettres uniquement).");
                return;
            }
            updateFields["NOM"] = newNom;
        }

        QString newPrenom = lineEditPrenom->text().trimmed();
        if (newPrenom != oldPrenom && !newPrenom.isEmpty()) {
            if (!regexNomPrenom.match(newPrenom).hasMatch()) {
                QMessageBox::warning(&updateDialog, "Erreur", "Prénom invalide (lettres uniquement).");
                return;
            }
            updateFields["PRENOM"] = newPrenom;
        }

        QString newTel = lineEditTelephone->text().trimmed();
        if (newTel != oldTel && !newTel.isEmpty()) {
            if (newTel.length() != 8 || !newTel.toUInt()) {
                QMessageBox::warning(&updateDialog, "Erreur", "Téléphone invalide (8 chiffres).");
                return;
            }
            updateFields["TELEPHONE"] = newTel;
        }

        QString newEmail = lineEditEmail->text().trimmed();
        if (newEmail != oldEmail && !newEmail.isEmpty()) {
            if (!newEmail.contains('@') || !newEmail.contains('.')) {
                QMessageBox::warning(&updateDialog, "Erreur", "Email invalide.");
                return;
            }
            updateFields["EMAIL"] = newEmail;
        }

        QString newExp = lineEditExperience->text().trimmed();
        if (newExp != oldExp && !newExp.isEmpty()) {
            updateFields["EXPERIENCE"] = newExp;
        }

        if (updateFields.isEmpty()) {
            QMessageBox::information(&updateDialog, "Info", "Aucune modification détectée ou tous les champs sont vides.");
            return;
        }

        QStringList setClauses;
        QSqlQuery updateQuery;
        for (auto it = updateFields.begin(); it != updateFields.end(); ++it) {
            setClauses << QString("%1 = :%1").arg(it.key());
        }

        QString queryString = "UPDATE ARCHITECTES SET " + setClauses.join(", ") + " WHERE ID = :id";
        updateQuery.prepare(queryString);

        for (auto it = updateFields.begin(); it != updateFields.end(); ++it) {
            updateQuery.bindValue(":" + it.key(), it.value());
        }
        updateQuery.bindValue(":id", id);

        if (updateQuery.exec()) {
            QMessageBox::information(&updateDialog, "Succès", "Mise à jour réussie !");
            updateDialog.accept();
            ui->tableView->setModel(Etmp.afficher());
        } else {
            QMessageBox::critical(&updateDialog, "Erreur", "Échec de la mise à jour.");
        }
    });

    QObject::connect(cancelButton, &QPushButton::clicked, &updateDialog, &QDialog::reject);

    updateDialog.exec();
}

void MainArch::on_dashborad_btn_2_clicked()
{
    if (!mainWindow) {
        mainWindow = new MainWindow();  // Or pass 'this->parent()' if needed
    }
    mainWindow->show();
    this->accept();  // Close the dialog (if modal)
}


void MainArch::on_arduino_clicked()
{
    // ✅ Step 1: Check if Arduino object is initialized
    if (!arduino) {
        qDebug() << "Erreur : Objet Arduino non initialisé.";
        return;
    }

    // ✅ Step 2: Prepare and execute the SQL query
    QSqlQuery query;
    query.prepare("SELECT NOM, PRENOM FROM ARCHITECTES");

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
        return;
    }

    // ✅ Step 3: Send each architect to the Arduino
    while (query.next()) {
        QString nom = query.value(0).toString();
        QString prenom = query.value(1).toString();
        QString data = nom + " " + prenom;

        // ✅ Send data to Arduino
        if (arduino->writeToArduino(data) == 0) {
            qDebug() << "Données envoyées à Arduino:" << data;
        } else {
            qWarning() << "Erreur lors de l'envoi à Arduino.";
        }

        // ✅ Pause courte pour laisser Arduino traiter
        QThread::msleep(500);  // 500ms pause (ne bloque pas totalement l'UI)
        QCoreApplication::processEvents();  // Laisse Qt traiter les événements (évite blocage interface)
    }
}


void MainArch::on_sms_clicked(){
    // Créer un QDialog pour demander l'ID et le message
    QDialog smsDialog(this);
    smsDialog.setWindowTitle("Envoyer un SMS");

    // Champs pour entrer l'ID et le message
    QLineEdit *lineEditId = new QLineEdit(&smsDialog);
    QLineEdit *lineEditMessage = new QLineEdit(&smsDialog);

    QPushButton *sendButton = new QPushButton("Envoyer", &smsDialog);
    QPushButton *cancelButton = new QPushButton("Annuler", &smsDialog);

    QFormLayout *layout = new QFormLayout();
    layout->addRow("ID Architecte :", lineEditId);
    layout->addRow("Message à envoyer :", lineEditMessage);
    layout->addRow(sendButton, cancelButton);
    smsDialog.setLayout(layout);

    connect(sendButton, &QPushButton::clicked, [&]() {
        QString idStr = lineEditId->text().trimmed();
        QString message = lineEditMessage->text().trimmed();

        bool ok;
        int id = idStr.toInt(&ok);
        if (!ok || id <= 0) {
            QMessageBox::warning(&smsDialog, "Erreur", "ID invalide.");
            return;
        }

        if (message.isEmpty()) {
            QMessageBox::warning(&smsDialog, "Erreur", "Le message ne peut pas être vide.");
            return;
        }

        // Vérifier si l'ID existe et récupérer le numéro de téléphone
        QSqlQuery query;
        query.prepare("SELECT TELEPHONE FROM ARCHITECTES WHERE ID = :id");
        query.bindValue(":id", id);
        if (!query.exec() || !query.next()) {
            QMessageBox::warning(&smsDialog, "Erreur", "ID non trouvé dans la base de données.");
            return;
        }

        QString numero = query.value("TELEPHONE").toString();

        // Construire la commande cURL pour Twilio
        QString sid = "AC1089e2a313a9b34a2979014471159dca";
        QString token = "4cd03f468454e4ae46800a8466a312d7";
        QString from = "+19704254162"; // Exemple: "+1415xxxxxxx"
        QString to = "+21626875995" ;

        QString command = QString("curl -X POST https://api.twilio.com/2010-04-01/Accounts/%1/Messages.json "
                                  "--data-urlencode \"Body=%2\" "
                                  "--data-urlencode \"From=%3\" "
                                  "--data-urlencode \"To=%4\" "
                                  "-u %1:%5")
                              .arg(sid, message, from, to, token);

        int result = system(command.toStdString().c_str());

        if (result == 0) {
            QMessageBox::information(&smsDialog, "Succès", "SMS envoyé !");
        } else {
            QMessageBox::critical(&smsDialog, "Erreur", "Échec de l'envoi du SMS.");
        }

        smsDialog.accept();
    });

    connect(cancelButton, &QPushButton::clicked, &smsDialog, &QDialog::reject);

    smsDialog.exec();
}
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSlice>
#include <QDialog>
#include <QVBoxLayout>

void MainArch::on_stat_clicked()
{
    QSqlQuery query;
    int faible = 0, moyenne = 0, excellente = 0;

    if (query.exec("SELECT EXPERIENCE, COUNT(*) FROM ARCHITECTES GROUP BY EXPERIENCE")) {
        while (query.next()) {
            QString exp = query.value(0).toString().toLower();
            int count = query.value(1).toInt();

            if (exp == "faible")
                faible = count;
            else if (exp == "moyenne")
                moyenne = count;
            else if (exp == "excellente")
                excellente = count;
        }

        // Création de la série de données
        QPieSeries *series = new QPieSeries();
        QPieSlice *sliceFaible = series->append("Faible", faible);
        QPieSlice *sliceMoyenne = series->append("Moyenne", moyenne);
        QPieSlice *sliceExcellente = series->append("Excellente", excellente);

        // Couleurs personnalisées
        sliceFaible->setBrush(QColor(255, 99, 71));     // Rouge
        sliceMoyenne->setBrush(QColor(255, 223, 0));    // Jaune
        sliceExcellente->setBrush(QColor(34, 139, 34)); // Vert

        // Affichage des labels personnalisés avec message
        sliceFaible->setLabelVisible(true);
        sliceFaible->setLabel(QString("Faible : %1%").arg(sliceFaible->percentage() * 100, 0, 'f', 1));

        sliceMoyenne->setLabelVisible(true);
        sliceMoyenne->setLabel(QString("Moyenne : %1%").arg(sliceMoyenne->percentage() * 100, 0, 'f', 1));

        sliceExcellente->setLabelVisible(true);
        sliceExcellente->setLabel(QString("Excellente : %1%").arg(sliceExcellente->percentage() * 100, 0, 'f', 1));

        // Création du graphique
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Répartition des Architectes par Expérience");
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        // Affichage dans une fenêtre
        QDialog *dialog = new QDialog(this);
        dialog->setWindowTitle("Statistiques des Architectes");
        QVBoxLayout *layout = new QVBoxLayout(dialog);
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        layout->addWidget(chartView);
        dialog->setLayout(layout);
        dialog->resize(400, 300);
        dialog->exec();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec lors de la récupération des statistiques.");
    }
}

