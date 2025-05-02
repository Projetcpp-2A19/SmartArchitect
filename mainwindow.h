#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employee.h"  // 📌 Inclure la classe Employee
#include "loginform.h"
#include <QSortFilterProxyModel>
#include "statspostewindow.h"
#include "serialhandler.h"  // Nouvelle inclusion
#include <QLabel>
#include <QTableWidget>
#include <QInputDialog>

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
     void on_btnExportPDF_clicked();
    void on_btnOpenLogin_clicked();
    //void on_search_input_textChanged(const QString &arg1); // 🔎 Recherche
    // Nouveaux slots pour la gestion RFID
    void onAccessGranted(QString nom, QString prenom, QString poste);
    void onAccessDenied(QString uid);
    void on_btnAssocierBadge_clicked();  // Pour associer des badges aux employés
private:
    void afficherEmployes();
    void setupRFIDInterface();
    //void on_btnScanBadge_clicked();

    Ui::MainWindow *ui;
    Employee emp;  // 📌 Attribut pour la gestion des employés
    QSortFilterProxyModel *proxyModel;  // 📌 Modèle de tri et de recherche

    // Nouveaux membres pour la gestion RFID
    SerialHandler *serialHandler;
    QLabel *statusLabel;        // Pour afficher le statut d'accès
    QTableWidget *accessTable;  // Pour l'affichage des tentatives d'accès
    QString currentUid;
};

#endif // MAINWINDOW_H

