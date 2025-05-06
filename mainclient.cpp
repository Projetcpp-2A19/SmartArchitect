#include "mainclient.h"
#include "arduinomanager.h"
#include "cartefidelitedialog.h"
#include "qsqlerror.h"
#include "ui_mainclient.h"
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
#include <QDebug>
#include <QFileInfo>

MainClient::MainClient(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainClient)
    , arduinoManager(new ArduinoManager(this))
    , connection(Connection::getInstance())
    , pythonProcess(nullptr)
{
    ui->setupUi(this);

    // Initialisation de l'Arduino
    QStringList ports = arduinoManager->getAvailablePorts();
    ui->portComboBox->clear();
    ui->portComboBox->addItems(ports);

    // Connexion des signaux Arduino
    connect(arduinoManager, &ArduinoManager::temperatureReceived,
            this, &MainClient::onTemperatureReceived);
    connect(arduinoManager, &ArduinoManager::humidityReceived,
            this, &MainClient::onHumidityReceived);
    connect(arduinoManager, &ArduinoManager::errorOccurred,
            this, &MainClient::onErrorOccurred);
    connect(ui->connectButton, &QPushButton::clicked,
            this, &MainClient::onConnectButtonClicked);
    connect(ui->setThresholdButton, &QPushButton::clicked,
            this, &MainClient::onSetThresholdButtonClicked);


    // Initialisation des labels
    ui->temperatureLabel->setText("Température: -- °C");
    ui->humidityLabel->setText("Humidité: -- %");

    QStringList headersFidelite = {"ID", "Client", "Région", "Score"};
    ui->tableWidgetFidelite->setColumnCount(headersFidelite.size());
    ui->tableWidgetFidelite->setHorizontalHeaderLabels(headersFidelite);

    // Charger les données initiales
    chargerDonneesFidelite();
    connect(ui->actualiser_fidelite, &QPushButton::clicked,
            this, &MainClient::on_pb_actualiser_fidelite_clicked);
    // Initialisation de la base de données
    if (!connection->createconnect()) {
        qDebug() << "Erreur de connexion à la base de données";
    }

    // Configuration initiale
    currentFournisseurId = 1; // ID par défaut du fournisseur

    // Configurer le tableWidget
    QStringList headers = {"ID", "Nom", "Prénom", "Région", "Téléphone", "Email"};
    ui->tableWidget->setColumnCount(headers.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Charger les données initiales dans le tableau
    client.afficherDansTableWidget(ui->tableWidget);
    ui->tableView->setModel(client.afficher());

    // Remplir le comboBox des régions
    QSqlQuery query("SELECT DISTINCT REGION FROM clients");
    while (query.next()) {
        ui->comboBoxRegions->addItem(query.value(0).toString());
        qDebug() << "Bouton connecté :" << connect(
            ui->generer_carte, &QPushButton::clicked,
            this, &MainClient::on_pb_generer_carte_clicked
            );
    }

    // Connexion du bouton de température
    connect(ui->enregistrerTemperature, &QPushButton::clicked,
            this, &MainClient::on_enregistrerTemperature_clicked);

    // Connexion du bouton pour face recognition
    connect(ui->pushButton_11, &QPushButton::clicked,
            this, &MainClient::on_pushButton_11_clicked);

    // Initialisation du bouton face recognition
    ui->pushButton_11->setText("Start Face Recognition");
    ui->pushButton_11->setText("Start Face Recognition");

    // Set default paths (adjust these to your actual paths)
    pythonExecutable = "C:/Users/Marwen/AppData/Local/Programs/Python/Python313/python.exe";
    workingDirectory = "C:/Users/Marwen/Desktop/integgg/integgg/finalllllllllllllllllllllll(faceid+dashboard)/face 3 scripts/New folder";
    faceRecognitionScript = "face_recognition.py";
}



void MainClient::on_pb_ajouter_clicked()
{
    QString nom = ui->le_nom->text().trimmed();
    QString prenom = ui->le_prenom->text().trimmed();
    QString region = ui->le_region->text().trimmed();
    QString telephone = ui->le_telephone->text().trimmed();
    QString email = ui->le_email->text().trimmed();

    // Validation basique des champs
    if (nom.isEmpty() || prenom.isEmpty() || region.isEmpty() || telephone.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Tous les champs doivent être remplis");
        return;
    }

    // Validation email
    QRegularExpression emailRegex(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b)");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Email invalide", "Veuillez entrer une adresse email valide");
        return;
    }

    // Validation téléphone
    telephone.remove(" "); // Supprimer les espaces
    QRegularExpression phoneRegex(R"(\d{8,})");
    if (!phoneRegex.match(telephone).hasMatch()) {
        QMessageBox::warning(this, "Téléphone invalide", "Le numéro doit contenir au moins 8 chiffres");
        return;
    }

    // Ajout du client
    Client c(nom, prenom, region, telephone, email);
    if (c.ajouter()) {
        QMessageBox::information(this, "Succès", "Client ajouté avec succès avec l'ID: " + QString::number(c.getId()));

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

void MainClient::on_pb_modifier_clicked()
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
        ui->tableView->setModel(client.afficher());
        client.afficherDansTableWidget(ui->tableWidget);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du client");
    }
}

void MainClient::on_pb_supprimer_clicked()
{
    int id = ui->le_idsupp->text().toInt();
    if (client.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Client supprimé avec succès");
        ui->tableView->setModel(client.afficher());
        client.afficherDansTableWidget(ui->tableWidget);

        // Actualiser la fidélité après suppression
        chargerDonneesFidelite();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression du client");
    }
}

void MainClient::on_pb_chercher_nom_clicked()
{
    QString nom = ui->lineEditNom->text();
    QSqlQueryModel *model = client.chercherParNom(nom);

    if (model) {
        ui->tableViewNom->setModel(model);
        ui->tableViewNom->resizeColumnsToContents();
    } else {
        QMessageBox::warning(this, "Avertissement", "Aucun résultat trouvé pour le nom spécifié.");
    }
}

void MainClient::on_pushButton_10_clicked()
{
    client.afficherDansTableWidget(ui->tableWidget);
}

void MainClient::on_tableWidget_cellClicked(int row, int column)
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

void MainClient::on_tableView2_clicked(const QModelIndex &index)
{
    int row = index.row();

    // Récupérer les données de la ligne sélectionnée
    QAbstractItemModel *model = ui->tableView->model();

    int id = model->data(model->index(row, 0)).toInt();
    QString nom = model->data(model->index(row, 1)).toString();
    QString prenom = model->data(model->index(row, 2)).toString();
    QString region = model->data(model->index(row, 3)).toString();
    QString telephone = model->data(model->index(row, 4)).toString();
    QString email = model->data(model->index(row, 5)).toString();

    // Remplir les champs de saisie
    ui->le_id_2->setText(QString::number(id));
    ui->le_nom->setText(nom);
    ui->le_prenom->setText(prenom);
    ui->le_region->setText(region);
    ui->le_telephone->setText(telephone);
    ui->le_email->setText(email);
}

void MainClient::on_pushButton_9_clicked()
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

void MainClient::on_employee_pb_stat_clicked()
{
    QMessageBox::information(this, "Statistiques", "Fonctionnalité à implémenter");
}

void MainClient::on_pb_export_pdf_clicked()
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

void MainClient::on_pb_tri_clicked()
{
    static bool ascending = true;

    QSqlQueryModel *model = new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("SELECT ID_CLIENT, NOM, PRENOM, REGION, TELEPHONE, EMAIL FROM clients ORDER BY NOM " + QString(ascending ? "ASC" : "DESC"));

    if (query.exec()) {
        model->setQuery(std::move(query));

        model->setHeaderData(0, Qt::Horizontal, tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, tr("Prénom"));
        model->setHeaderData(3, Qt::Horizontal, tr("Région"));
        model->setHeaderData(4, Qt::Horizontal, tr("Téléphone"));
        model->setHeaderData(5, Qt::Horizontal, tr("Email"));

        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();

        client.afficherTrieDansTableWidget(ui->tableWidget, ascending);

        ascending = !ascending;
        ui->pb_tri->setText(ascending ? "Tri (A-Z)" : "Tri (Z-A)");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec du tri : " + query.lastError().text());
        delete model;
    }
}

void MainClient::on_client_pb_stat_clicked()
{
    QMap<QString, int> stats = client.getStatsByRegion();

    if (stats.isEmpty()) {
        QMessageBox::information(this, "Statistiques", "Aucune donnée disponible");
        return;
    }

    QWidget *statWindow = new QWidget();
    statWindow->setWindowTitle("Statistiques par région");
    statWindow->resize(800, 600);

    QChart *chart = new QChart();
    chart->setTitle("Répartition des clients par région");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarSeries *series = new QBarSeries();
    QBarSet *set = new QBarSet("Nombre de clients");

    QStringList categories;
    for (auto it = stats.begin(); it != stats.end(); ++it) {
        *set << it.value();
        categories << it.key();
    }

    series->append(set);
    chart->addSeries(series);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%d");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QHBoxLayout *layout = new QHBoxLayout(statWindow);
    layout->addWidget(chartView);
    statWindow->setLayout(layout);

    statWindow->show();
}

void MainClient::chargerDonneesFidelite()
{
    QVector<QVector<QString>> clientsData;
    QSqlQuery query("SELECT ID_CLIENT, NOM, PRENOM, REGION, TELEPHONE, EMAIL FROM clients");

    while (query.next()) {
        QVector<QString> client;
        for (int i = 0; i < 6; ++i) {
            client.append(query.value(i).toString());
        }
        clientsData.append(client);
    }

    qDebug() << "Nombre de clients chargés:" << clientsData.size();
    for (const auto& client : clientsData) {
        qDebug() << "Client:" << client;
    }

    fideliteManager.analyserClients(clientsData);
    afficherTableauFidelite();
}

void MainClient::on_pb_actualiser_fidelite_clicked()
{
    QVector<QVector<QString>> clientsData;
    QSqlQuery query("SELECT ID_CLIENT, NOM, PRENOM, REGION, TELEPHONE, EMAIL FROM clients");

    while (query.next()) {
        QVector<QString> client;
        for (int i = 0; i < 6; ++i) {
            client.append(query.value(i).toString());
        }
        clientsData.append(client);
    }

    fideliteManager.analyserClients(clientsData);
    afficherTableauFidelite();

    QMessageBox::information(this, "Actualisation", "Les données de fidélité ont été actualisées");
}

void MainClient::afficherTableauFidelite()
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

void MainClient::on_pb_generer_carte_clicked()
{
    int currentRow = ui->tableWidgetFidelite->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un client");
        return;
    }

    int id = ui->tableWidgetFidelite->item(currentRow, 0)->text().toInt();
    QString nom = ui->tableWidgetFidelite->item(currentRow, 1)->text();
    int score = ui->tableWidgetFidelite->item(currentRow, 3)->text().toInt();

    CarteFideliteDialog carteDialog(id, nom, score, this);
    carteDialog.exec();
}

void MainClient::onTemperatureReceived(double temperature)
{
    qDebug() << "\n=== RÉCEPTION DE LA TEMPÉRATURE ===";
    qDebug() << "Température reçue:" << temperature;

    if (temperature < -273.15) {
        qDebug() << "Température invalide (inférieure au zéro absolu)";
        ui->temperatureLabel->setText("Erreur");
        return;
    }

    lastTemperature = temperature;

    QString tempText = QString("Température: %1 °C").arg(temperature, 0, 'f', 1);
    qDebug() << "Mise à jour du label avec:" << tempText;
    ui->temperatureLabel->setText(tempText);

    if (connection->updateTemperature(1, temperature)) {
        qDebug() << "Température mise à jour dans la base de données:" << temperature;
    } else {
        qDebug() << "Erreur lors de la mise à jour de la température dans la base de données";
    }

    bool ok;
    double seuil = ui->thresholdLineEdit->text().toDouble(&ok);
    if (ok && temperature > seuil) {
        QMessageBox::warning(this, "Alerte Température",
                             QString("La température (%1 °C) dépasse le seuil (%2 °C) !")
                                 .arg(temperature, 0, 'f', 1)
                                 .arg(seuil, 0, 'f', 1));
    }
}

void MainClient::on_enregistrerTemperature_clicked()
{
    QString temperatureStr = ui->le_temperature->text().trimmed();
    bool ok;
    double temperature = temperatureStr.toDouble(&ok);

    if (!ok) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une température valide");
        return;
    }

    if (connection->updateTemperature(1, temperature)) {
        QMessageBox::information(this, "Succès", "Température mise à jour avec succès");
        ui->le_temperature->clear();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la mise à jour de la température");
    }
}

void MainClient::onHumidityReceived(double humidity)
{
    qDebug() << "Humidité reçue:" << humidity;
    ui->humidityLabel->setText(QString::number(humidity, 'f', 1) + " %");
    qDebug() << "Humidité affichée:" << QString::number(humidity, 'f', 1) + " %";
}

void MainClient::onErrorOccurred(const QString &error)
{
    QMessageBox::critical(this, "Erreur", error);
}

void MainClient::onConnectButtonClicked()
{
    QString portName = ui->portComboBox->currentText();
    qDebug() << "\n=== TENTATIVE DE CONNEXION ===";
    qDebug() << "Port sélectionné:" << portName;

    if (!connection->createconnect()) {
        QMessageBox::critical(this, "Erreur", "Impossible de se connecter à la base de données");
        return;
    }

    if (arduinoManager->connectToArduino(portName)) {
        qDebug() << "Connexion réussie au port" << portName;
        QMessageBox::information(this, "Connexion", "Connecté à " + portName);
        ui->connectButton->setText("Déconnecter");
        currentFournisseurId = 1;
    } else {
        qDebug() << "Échec de la connexion au port" << portName;
        QMessageBox::warning(this, "Connexion", "Échec de la connexion");
    }
}

void MainClient::onSetThresholdButtonClicked()
{
    bool ok;
    double threshold = ui->thresholdLineEdit->text().toDouble(&ok);
    if (ok) {
        QMessageBox::information(this, "Seuil", "Nouveau seuil défini: " + QString::number(threshold) + " °C");

        QString currentTemp = ui->temperatureLabel->text();
        currentTemp = currentTemp.replace("Température: ", "").replace(" °C", "");
        double currentTemperature = currentTemp.toDouble(&ok);

        if (ok && currentTemperature > threshold) {
            QMessageBox::information(this, "Ventilateur",
                                     "La température actuelle (" + QString::number(currentTemperature) + " °C) dépasse le nouveau seuil (" +
                                         QString::number(threshold) + " °C) !\nLe ventilateur est en marche.");
        }

        arduinoManager->setTemperatureThreshold(0, threshold);
    } else {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une valeur numérique valide !");
    }
}

void MainClient::updateTemperature()
{
    arduinoManager->connectToArduino(ui->portComboBox->currentText());
}

void MainClient::on_pushButton_11_clicked()
{
    // Initialize paths
    pythonExecutable = "C:/Users/Marwen/AppData/Local/Programs/Python/Python313/python.exe";
    workingDirectory = "C:/Users/Marwen/Desktop/integgg/integgg/finalllllllllllllllllllllll(faceid+dashboard)/face 3 scripts/New folder";
    faceRecognitionScript = "face_recognition.py";

    // Validate paths
    QFileInfo pythonFile(pythonExecutable);
    QFileInfo scriptFile(workingDirectory + "/" + faceRecognitionScript);
    if (!pythonFile.exists() || !pythonFile.isFile()) {
        QMessageBox::critical(this, "Error", "Python executable not found at: " + pythonExecutable);
        return;
    }
    if (!scriptFile.exists() || !scriptFile.isFile()) {
        QMessageBox::critical(this, "Error", "Face recognition script not found at: " + scriptFile.absoluteFilePath());
        return;
    }

    // Check if process is running and stop it
    if (pythonProcess && pythonProcess->state() == QProcess::Running) {
        cleanupPythonProcess(false); // Try graceful termination
        ui->pushButton_11->setText("Start Face Recognition");
        return;
    }

    // Create new process
    pythonProcess = new QProcess(this);

    // Connect signals
    connect(pythonProcess, &QProcess::readyReadStandardOutput,
            this, &MainClient::readPythonOutput);
    connect(pythonProcess, &QProcess::readyReadStandardError,
            this, &MainClient::readPythonError);
    connect(pythonProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, [this](int exitCode, QProcess::ExitStatus exitStatus) {
                qDebug() << "Python process finished with code:" << exitCode << "Status:" << exitStatus;
                ui->pushButton_11->setText("Start Face Recognition");
                cleanupPythonProcess(false); // Clean up after process finishes
            });
    connect(pythonProcess, &QProcess::errorOccurred,
            this, [this](QProcess::ProcessError error) {
                qDebug() << "Python process error:" << error << pythonProcess->errorString();
                QMessageBox::critical(this, "Error", "Process error: " + pythonProcess->errorString());
                cleanupPythonProcess(true); // Force cleanup on error
            });

    // Set up environment
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    env.remove("PYTHONHOME");
    env.remove("PYTHONPATH");
    pythonProcess->setProcessEnvironment(env);
    pythonProcess->setWorkingDirectory(workingDirectory);

    // Start the process
    QStringList arguments;
    arguments << faceRecognitionScript;
    pythonProcess->start(pythonExecutable, arguments);

    if (!pythonProcess->waitForStarted(5000)) {
        QMessageBox::critical(this, "Error",
                              "Failed to start face recognition:\n" + pythonProcess->errorString());
        cleanupPythonProcess(true);
    } else {
        ui->pushButton_11->setText("Stop Recognition");
        qDebug() << "Face recognition process started successfully";
    }
}

void MainClient::cleanupPythonProcess(bool force)
{
    if (!pythonProcess) {
        qDebug() << "No Python process to clean up";
        return;
    }

    // Disconnect all signals to prevent callbacks during cleanup
    pythonProcess->disconnect();

    if (pythonProcess->state() == QProcess::Running) {
        qDebug() << "Terminating Python process (force =" << force << ")";
        if (force) {
            pythonProcess->kill(); // Force kill if necessary
        } else {
            pythonProcess->terminate(); // Try graceful termination
        }

        // Wait for the process to finish with a longer timeout
        if (!pythonProcess->waitForFinished(10000)) { // Increased to 5 seconds
            qDebug() << "Process did not terminate gracefully, forcing kill";
            pythonProcess->kill();
            if (!pythonProcess->waitForFinished(10000)) { // Additional 2 seconds after kill
                qDebug() << "Process still running after kill, proceeding with cleanup";
            } else {
                qDebug() << "Process terminated successfully after kill";
            }
        } else {
            qDebug() << "Process terminated gracefully";
        }
    } else {
        qDebug() << "Python process is not running, state:" << pythonProcess->state();
    }

    qDebug() << "Deleting Python process object";
    delete pythonProcess;
    pythonProcess = nullptr;
}

void MainClient::readPythonOutput()
{
    if (!pythonProcess) return;

    while (pythonProcess->canReadLine()) {
        QString line = QString::fromUtf8(pythonProcess->readLine()).trimmed();
        qDebug() << "Python Output:" << line;

        if (line.startsWith("RESULT|GRANTED|")) {
            QStringList parts = line.split("|");
            if (parts.size() >= 4) {
                QString name = parts[2];
                QString confidence = parts[3];

                QMessageBox::information(this, "Access Granted",
                                         QString("Welcome %1\nConfidence: %2").arg(name).arg(confidence));
                cleanupPythonProcess(false); // Graceful cleanup after success
                ui->pushButton_11->setText("Start Face Recognition");
            }
        }
    }
}

void MainClient::readPythonError()
{
    if (!pythonProcess) return;

    QString error = QString::fromUtf8(pythonProcess->readAllStandardError()).trimmed();
    if (!error.isEmpty()) {
        qDebug() << "Python Error:" << error;
        QMessageBox::warning(this, "Error", "Python script error:\n" + error);
        cleanupPythonProcess(true); // Force cleanup on error
        ui->pushButton_11->setText("Start Face Recognition");
    }
}

MainClient::~MainClient()
{
    cleanupPythonProcess(false); // Try graceful cleanup first
    delete ui;
}
