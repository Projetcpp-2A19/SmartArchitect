#include "directeur.h"
#include "ui_directeur.h"
#include "mainwindow.h"  // Assurez-vous d'inclure le fichier d'en-tête de MainWindowemploye

directeur::directeur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::directeur)
{
    ui->setupUi(this);

}

directeur::~directeur()
{
    delete ui;
}

void directeur::on_Gestion_employe_clicked()
{
    MainWindow *mainwindowInterface = new MainWindow();
        mainwindowInterface->show();
}
