#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include "fidelite.h"

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
    void on_tableWidget_cellClicked(int row, int column);
    void on_tableView2_clicked(const QModelIndex &index);
    void on_pb_chercher_nom_clicked();
    void on_pushButton_10_clicked();
    void on_pb_export_pdf_clicked();
    void on_pb_tri_clicked();
    void on_client_pb_stat_clicked();
    void on_pb_actualiser_fidelite_clicked();  // Déclaration unique ici
    void on_pb_generer_carte_clicked();

private:
    Ui::MainWindow *ui;
    Client client;
    FideliteManager fideliteManager;

    void chargerDonneesClients();
    void chargerDonneesFidelite();
    void afficherTableauFidelite();
    void initialiserTableaux();
    void mettreAJourStatistiques();
    // Supprimer la déclaration redondante de on_pb_actualiser_fidelite_clicked()
     void genererCarteSpecialiste(int clientId, const QString& nom, int score);
};

#endif // MAINWINDOW_H
