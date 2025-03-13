#ifndef FINDARCHITECTE_H
#define FINDARCHITECTE_H

#include <QDialog>

namespace Ui {
class FindArchitecte;
}

class FindArchitecte : public QDialog
{
    Q_OBJECT

public:
    explicit FindArchitecte(QWidget *parent = nullptr);
    ~FindArchitecte();

private:
    Ui::FindArchitecte *ui;
};

#endif // FINDARCHITECTE_H
