#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include "Fournisseur.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAjouterFournisseur_clicked();
    void on_btnModifierFournisseur_clicked();
    void on_btnSupprimerFournisseur_clicked();
    void afficherFournisseurs();

private:
    Ui::MainWindow *ui;
    Fournisseur fournisseur;
    QSortFilterProxyModel *proxyModelFournisseurs;
};

#endif // MAINWINDOW_H

