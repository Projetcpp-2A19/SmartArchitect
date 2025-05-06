#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QLabel>
#include "employee.h"
#include "serialhandler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainArch;
class MainClient;
class MainEquip;
class MainProjet;
class GProjett; // Include GProjett

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
    void on_home_btn_5_clicked();
    void on_customers_btn_4_clicked();
    void on_orders_btn_3_clicked();
    void on_products_btn_3_clicked();
    void on_customers_btn_5_clicked(); // New slot for customers_btn_5
    void fillFieldsFromSelectedRow(const QModelIndex &index);

private:
    void updateTableView();
    void setupRFIDInterface();

    Ui::MainWindow *ui;
    QSortFilterProxyModel *proxyModel;
    Employee emp;
    SerialHandler *serialHandler;
    QLabel *statusLabel;
    MainArch *mainArch;
    MainClient *mainClient;
    MainEquip *mainEquip;
    MainProjet *mainProjet;
    GProjett *gProjett; // Pointer for GProjett
};

#endif // MAINWINDOW_H
