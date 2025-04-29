#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "ajouterarchitecte.h"
#include "connection.h"
#include "equipement.h"
#include "codebarres.h"
#include "chatbot.h"
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include "arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();



    void on_pushButton_ajouter_clicked();
    void on_pushButton_Afficher_clicked();


    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_trouver_clicked();
    void on_commandLinkButton_chatbot_clicked();


    void exporterPDF();


    void on_pushButton_trier_clicked();
    void onIdReceived(const QString &id);

private:
    Ui::MainWindow *ui;

    chatbot *ptrchatbot;
    bool eventFilter(QObject* obj, QEvent* event) override;
    void afficherCodeBarreZoom(QPixmap pixmap);  // La fonction qu'on appelle
    QMap<QString, QPixmap> barcodeCache;
    Arduino *arduino;





};






#endif // MAINWINDOW_H
