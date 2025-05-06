#ifndef MAINARCH_H
#define MAINARCH_H

#include <QDialog>
#include "architecte.h"
#include "arduino.h"
#include "serialhandler.h"

class MainWindow;  // forward declaration

namespace Ui {
class MainArch;
}

class MainArch : public QDialog
{
    Q_OBJECT

public:
    explicit MainArch(QWidget *parent = nullptr);
    ~MainArch();

private slots:
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_pdf_clicked();
    void on_pushButton_search_clicked();
    void on_pushButton_sort_clicked();
    void on_pushButton_update_2_clicked();
    void on_dashborad_btn_2_clicked();
    void on_arduino_clicked();

    void on_sms_clicked();

    void on_stat_clicked();

private:
    Ui::MainArch *ui;
    architecte Etmp;
    MainWindow *mainWindow;
    Arduino *arduino;
    SerialHandler serialHandler;  // Handles badge scanning
};

#endif // MAINARCH_H
