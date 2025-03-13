#ifndef SUPPRIMERARCHITECTE_H
#define SUPPRIMERARCHITECTE_H

#include <QDialog>

namespace Ui {
class SupprimerArchitecte;
}

class SupprimerArchitecte : public QDialog
{
    Q_OBJECT

public:
    explicit SupprimerArchitecte(QWidget *parent = nullptr);
    ~SupprimerArchitecte();

private:
    Ui::SupprimerArchitecte *ui;
};

#endif // SUPPRIMERARCHITECTE_H
