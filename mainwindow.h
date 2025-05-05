#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include "employee.h"  // Assuming this is the header for the Employee class
#include "serialhandler.h"  // Assuming this is for RFID functionality

// Forward declaration of MainArch
class MainArch;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAjouter_clicked();
    void on_btnModifier_clicked();
    void on_btnSupprimer_clicked();
    void on_btnTriSalaire_clicked();
    void on_btnRechercheIdNom_clicked();
    void on_btnStatsPoste_clicked();
    void on_btnAnnuler_clicked();
    void on_btnExportPDF_clicked();
    void on_btnOpenLogin_clicked();
    void on_btnAssocierBadge_clicked();
    void onAccessGranted(QString nom, QString prenom, QString poste);
    void onAccessDenied(QString uid);
    void on_home_btn_5_clicked();  // Slot for home_btn_5

private:
    Ui::MainWindow *ui;
    Employee emp;
    QSortFilterProxyModel *proxyModel;
    QLabel *statusLabel;
    SerialHandler *serialHandler;
    MainArch *mainArch;  // Pointer to MainArch instance
    void updateTableView();
    void setupRFIDInterface();
};

#endif // MAINWINDOW_H
