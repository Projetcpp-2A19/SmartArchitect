#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QMainWindow>
#include "mainwindow.h" // Already included
#include "gprojett.h"

namespace Ui {
class DashboardWindow;
}

class DashboardWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DashboardWindow(QWidget *parent = nullptr);
    ~DashboardWindow();

private slots:
    void on_btnProjet_clicked();
    void on_btnEmploye_clicked();

private:
    Ui::DashboardWindow *ui;
};

#endif // DASHBOARDWINDOW_H
