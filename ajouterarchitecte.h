#ifndef AJOUTERARCHITECTE_H
#define AJOUTERARCHITECTE_H

#include <QDialog>

namespace Ui {
class AjouterArchitecte;
}

class AjouterArchitecte : public QDialog
{
    Q_OBJECT

public:
    explicit AjouterArchitecte(QWidget *parent = nullptr);
    ~AjouterArchitecte();

private:
    Ui::AjouterArchitecte *ui;
};

#endif // AJOUTERARCHITECTE_H
