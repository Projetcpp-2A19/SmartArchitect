#ifndef GPROJETT_H
#define GPROJETT_H

#include <QMainWindow>
#include <QtCharts>
#include <QSortFilterProxyModel>
#include "projetmanager.h"  // 📌 Inclusion de la classe ProjetManager


QT_BEGIN_NAMESPACE
namespace Ui {
class GProjett;
}
QT_END_NAMESPACE

class GProjett : public QMainWindow
{
    Q_OBJECT

public:
    GProjett(QWidget *parent = nullptr);
    ~GProjett();

private slots:
    void on_btnAjouter_clicked();  // 📌 Ajouter un projet
    void on_btnAnnuler_clicked();
    void on_btnModifier_clicked(); // 📌 Modifier un projet
    void on_btnSupprimer_clicked(); // 📌 Supprimer un projet
    void on_btnAsc_clicked();  // Trier en ordre ascendant
    void on_btnDesc_clicked(); // Trier en ordre descendant
    void on_btnRechercher_clicked();
    void on_btnExporterPDF_clicked();
    void envoyerNotificationEmailAvecPJ();
    void on_btnRefreshFinance_clicked();
    void refreshFinanceCharts();

private:
    Ui::GProjett *ui;
    ProjetManager p;  // 📌 Gestionnaire de projet
    QSortFilterProxyModel *proxyModel;  // Modèle de tri

    void showBudgetGraph();  // 📊 Affichage du graphique

    // Méthodes financières
    void initFinanceTab();
    void updateFinancialSummary();
    QChart* createBudgetDeviationChart();
    QChart* createCostEstimationChart();
    //MainWindow *r;
};

#endif // GPROJETT_H
