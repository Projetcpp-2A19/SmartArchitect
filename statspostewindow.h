#ifndef STATSPOSTEWINDOW_H
#define STATSPOSTEWINDOW_H

#include <QDialog>
#include <QMap>

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>

class StatsPosteWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StatsPosteWindow(const QMap<QString, int>& stats, QWidget *parent = nullptr);

private:
    void createChart(const QMap<QString, int>& stats);
};

#endif // STATSPOSTEWINDOW_H
