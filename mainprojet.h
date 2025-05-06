#ifndef MAINPROJET_H
#define MAINPROJET_H

#include <QDialog>
#include <QSortFilterProxyModel>
#include "Fournisseur.h"
#include "arduinomanager.h"
#include "chatbotwindow.h"
#include "arduinomanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainProjet;
}
QT_END_NAMESPACE

class MainProjet : public QDialog {
    Q_OBJECT

public:
    MainProjet(QWidget *parent = nullptr);
    ~MainProjet();

private slots:
    void on_btnAjouterFournisseur_clicked();
    void on_btnModifierFournisseur_clicked();
    void on_btnSupprimerFournisseur_clicked();
    void on_btnRechercher_clicked();
    void on_btnExporterPDF_clicked();
    void on_btnStatistiques_clicked();
    void on_btnAfficherQR_clicked();
    void on_btnChatbot_clicked();

    // Slots pour Arduino
    void on_connectButton_clicked();
    void on_setThresholdButton_clicked();
    void updateTemperature(float temperature);
    void updateHumidity(float humidity);
    void handleArduinoError(const QString &error);
    void updatePortList();

private:
    Ui::MainProjet *ui;
    Fournisseur fournisseur;
    QSortFilterProxyModel *proxyModelFournisseurs;
    ArduinoManager *arduino;
    void setupArduinoUI();
};

#endif // MAINPROJET_H
