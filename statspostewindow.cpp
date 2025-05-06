#include "statspostewindow.h"
#include <QVBoxLayout>

StatsPosteWindow::StatsPosteWindow(const QMap<QString, int>& stats, QWidget *parent)
    : QDialog(parent)
{
    createChart(stats);
    setWindowTitle("Statistiques par poste");
    resize(800, 600);
}

void StatsPosteWindow::createChart(const QMap<QString, int>& stats)
{
    QChartView *chartView = new QChartView(this);
    QPieSeries *series = new QPieSeries();

    for (auto it = stats.begin(); it != stats.end(); ++it) {
        QPieSlice *slice = series->append(it.key() + " (" + QString::number(it.value()) + ")", it.value());
        slice->setLabelVisible();
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des employés par poste");
    chart->legend()->setAlignment(Qt::AlignRight);

    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(chartView);
}
