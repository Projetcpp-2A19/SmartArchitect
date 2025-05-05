#ifndef MAINARCH_H
#define MAINARCH_H

#include <QDialog>
#include "architecte.h"  // Include the architecte header

// Forward declaration of MainWindow
class MainWindow;

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
    void on_dashborad_btn_2_clicked();  // Slot for dashborad_btn_2

private:
    Ui::MainArch *ui;
    architecte Etmp;
    MainWindow *mainWindow;  // Pointer to MainWindow instance
};

#endif // MAINARCH_H
