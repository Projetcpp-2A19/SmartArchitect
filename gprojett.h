#ifndef GPROJETT_H
#define GPROJETT_H

#include <QDialog>
#include <QSortFilterProxyModel>
#include "projetmanager.h"
#include "qchart.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

namespace Ui {
class GProjett;
}

class GProjett : public QDialog
{
    Q_OBJECT

public:
    explicit GProjett(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    ~GProjett();

private slots:
    void on_btnAjouter_clicked();
    void on_btnAnnuler_clicked();
    void on_btnModifier_clicked();
    void on_btnSupprimer_clicked();
    void on_btnAsc_clicked();
    void on_btnDesc_clicked();
    void on_btnRechercher_clicked();
    void on_btnExporterPDF_clicked();
    void on_btnRefreshFinance_clicked();

    void showBudgetGraph();
    void envoyerNotificationEmailAvecPJ();
    void fillFieldsFromSelectedRow(const QModelIndex &index);

private:
    Ui::GProjett *ui;
    QSortFilterProxyModel *proxyModel;
    ProjetManager p;

    void initFinanceTab();
    void updateFinancialSummary();
    void refreshFinanceCharts();
    QChart* createBudgetDeviationChart();
    QChart* createCostEstimationChart();
};

#endif // GPROJETT_H
