#ifndef TROUVERARCHITECTE_H
#define TROUVERARCHITECTE_H

#include <QDialog>

namespace Ui {
class TrouverArchitecte;
}

class TrouverArchitecte : public QDialog
{
    Q_OBJECT

public:
    explicit TrouverArchitecte(QWidget *parent = nullptr);
    ~TrouverArchitecte();

private:
    Ui::TrouverArchitecte *ui;
};

#endif // TROUVERARCHITECTE_H
