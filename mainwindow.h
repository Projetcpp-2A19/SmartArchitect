#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employee.h"  // 📌 Inclure la classe Employee
#include "loginform.h"
#include <QSortFilterProxyModel>
#include "statspostewindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAjouter_clicked();
    void on_btnModifier_clicked();
    void on_btnSupprimer_clicked();
    void on_btnTriSalaire_clicked();
    void on_btnRechercheIdNom_clicked();
    void on_btnStatsPoste_clicked();
     void on_btnAnnuler_clicked();
    void afficherEmployes();
     void on_btnExportPDF_clicked();
    void on_btnOpenLogin_clicked();
    //void on_search_input_textChanged(const QString &arg1); // 🔎 Recherche

private:
    Ui::MainWindow *ui;
    Employee emp;  // 📌 Attribut pour la gestion des employés
    QSortFilterProxyModel *proxyModel;  // 📌 Modèle de tri et de recherche
};

#endif // MAINWINDOW_H

