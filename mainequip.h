#ifndef MAINEQUIP_H
#define MAINEQUIP_H

#include <QDialog>
#include "connection.h"
#include "equipement.h"
#include "codebarres.h"
#include "chatbot.h"
#include "mainclient.h"  // For MainClient
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include "arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainEquip;
}
QT_END_NAMESPACE

class MainEquip : public QDialog
{
    Q_OBJECT

public:
    MainEquip(QWidget *parent = nullptr);
    ~MainEquip();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();  // For customers_btn_4
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
    Ui::MainEquip *ui;
    chatbot *ptrchatbot;
    bool eventFilter(QObject* obj, QEvent* event) override;
    void afficherCodeBarreZoom(QPixmap pixmap);
    QMap<QString, QPixmap> barcodeCache;
    Arduino *arduino;
};

#endif // MAINEQUIP_H
