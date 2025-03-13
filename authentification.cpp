#include "authentification.h"
#include "ui_authentification.h"
#include <QMessageBox>
#include "employee.h"
#include "mainwindow.h"
#include "directeur.h"


authentification::authentification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authentification)
{
    ui->setupUi(this);
}

authentification::~authentification()
{
    delete ui;
}

void authentification::on_pushButton_connecter_clicked()
{
    QString username = ui->employe_username->text();
    QString password = ui->employe_password->text();
    employee emp;
    QString PostEMP;

    if (username == "admin" && password == "admin") {
        // Correct credentials, open directeur.ui
        directeur* directeurInterface = new directeur();
               directeurInterface->show();
               this->close();
           } else if (emp.authentifier(username, password, PostEMP)) {
               // Cas 1: Affichez l'interface correspondante au PostEMP
               if (PostEMP == "gestion employe") {
                   MainWindow *mainWindow = new MainWindow();
                   mainWindow->show();
                   this->close();
           } else if (PostEMP == "gestion audit") {
                   // Cas 2: Affichez gestion_client.ui
               //    audit *auditInterface = new audit();
               //    auditInterface->show();
                   this->close();
           } else if (PostEMP == "gestion enterpise") {
                   // Cas 3: Affichez gestion_enterpise.ui
               //    enterprise *enterpriseInterface = new enterprise();
               //    enterpriseInterface->show();
                   this->close();
           } else if (PostEMP == "gestion incident") {
                   // Cas 4: Affichez gestion_incident.ui
               //    incident *incidentInterface = new incident();
               //    incidentInterface->show();
                   this->close();
                 } else {
                           // Cas par défaut: Accès refusé
                           QMessageBox::warning(this, "Accès refusé", "Vous n'avez pas l'accès.");
                       }
                   } else {
                       // Cas par défaut: Informations d'identification incorrectes
                       QMessageBox::warning(this, "Échec de la connexion", "Nom d'utilisateur ou mot de passe incorrect.");
                   }
               }
