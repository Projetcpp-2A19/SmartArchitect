#include <QMainWindow>
#include "gprojett.h"
#include "mainwindow.h"

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
    GProjett *projetPage;
    MainWindow *employePage;
};
