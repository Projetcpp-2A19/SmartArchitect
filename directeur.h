#ifndef DIRECTEUR_H
#define DIRECTEUR_H

#include <QDialog>

namespace Ui {
class directeur;
}

class directeur : public QDialog
{
    Q_OBJECT

public:
    explicit directeur(QWidget *parent = nullptr);
    ~directeur();

private slots:

    void on_Gestion_employe_clicked();


private:
    Ui::directeur *ui;
};

#endif // DIRECTEUR_H
