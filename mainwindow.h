#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();
    void on_pb_modifier_clicked();
    void on_pb_supprimer_clicked();
    void on_employee_pb_stat_clicked();

    void on_pushButton_9_clicked();
    void on_tableWidget_cellClicked(int row, int column);  // Slot pour gérer le clic sur tableWidget

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
    Client client;  // Instance globale de client
};

#endif // MAINWINDOW_H
