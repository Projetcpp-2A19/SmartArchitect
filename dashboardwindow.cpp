#include "dashboardwindow.h"
#include "ui_dashboardwindow.h"

DashboardWindow::DashboardWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DashboardWindow),
    projetPage(new GProjett(this)),
    employePage(new MainWindow(this))
{
    ui->setupUi(this);

    // Injecter les widgets dans les pages du QStackedWidget
    ui->stackedWidget->insertWidget(1, projetPage);
    ui->stackedWidget->insertWidget(2, employePage);
}

DashboardWindow::~DashboardWindow()
{
    delete ui;
}

void DashboardWindow::on_btnProjet_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);  // Afficher la page projet
}

void DashboardWindow::on_btnEmploye_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);  // Afficher la page employé
}
