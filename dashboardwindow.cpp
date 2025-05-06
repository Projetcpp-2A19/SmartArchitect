#include "dashboardwindow.h"
#include "ui_dashboardwindow.h"
#include "mainwindow.h" // Ensure this is included

DashboardWindow::DashboardWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DashboardWindow)
{
    ui->setupUi(this);
}

DashboardWindow::~DashboardWindow()
{
    delete ui;
}

void DashboardWindow::on_btnProjet_clicked()
{
    GProjett *w = new GProjett(this);
    w->show();
}

void DashboardWindow::on_btnEmploye_clicked()
{
    MainWindow *e = new MainWindow(this); // Create MainWindow instance
    e->show();
}
