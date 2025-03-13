#ifndef UPDATEARCHITECTE_H
#define UPDATEARCHITECTE_H

#include <QDialog>

namespace Ui {
class UpdateArchitecte;
}

class UpdateArchitecte : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateArchitecte(QWidget *parent = nullptr);
    ~UpdateArchitecte();

private:
    Ui::UpdateArchitecte *ui;
};

#endif // UPDATEARCHITECTE_H
