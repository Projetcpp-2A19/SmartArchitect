#ifndef MAINCLIENT_H
#define MAINCLIENT_H

#include <QDialog>
#include "arduinomanager.h"
#include "client.h"
#include "fidelite.h"
#include "connection.h"

namespace Ui {
class MainClient;
}

class MainClient : public QDialog
{
    Q_OBJECT

public:
    explicit MainClient(QWidget *parent = nullptr);
    ~MainClient();

private slots:
    void on_pb_ajouter_clicked();
    void on_pb_modifier_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_chercher_nom_clicked();
    void on_pushButton_10_clicked();
    void on_tableWidget_cellClicked(int row, int column);
    void on_tableView2_clicked(const QModelIndex &index);
    void on_pushButton_9_clicked();
    void on_employee_pb_stat_clicked();
    void on_pb_export_pdf_clicked();
    void on_pb_tri_clicked();
    void on_client_pb_stat_clicked();
    void on_pb_actualiser_fidelite_clicked();
    void on_pb_generer_carte_clicked();
    void onTemperatureReceived(double temperature);
    void on_enregistrerTemperature_clicked();
    void onHumidityReceived(double humidity);
    void onErrorOccurred(const QString &error);
    void onConnectButtonClicked();
    void onSetThresholdButtonClicked();
    void updateTemperature();

private:
    void chargerDonneesFidelite();
    void afficherTableauFidelite();

    Ui::MainClient *ui;
    ArduinoManager *arduinoManager;
    Client client;
    FideliteManager fideliteManager;
    Connection* connection;
    int currentFournisseurId;
    double lastTemperature;
};

#endif // MAINCLIENT_H
