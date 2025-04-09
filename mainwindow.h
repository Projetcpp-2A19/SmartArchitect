#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "architecte.h"  // Add this line to include the architecte header


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
    void on_pushButton_7_clicked();



    void on_pushButton_8_clicked();


    void on_pushButton_pdf_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_sort_clicked();

    void on_pushButton_update_2_clicked();

private:
    Ui::MainWindow *ui;
    architecte Etmp;
};

#endif // MAINWINDOW_H
