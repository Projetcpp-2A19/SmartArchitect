#include "updatearchitecte.h"
#include "ui_updatearchitecte.h"

UpdateArchitecte::UpdateArchitecte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateArchitecte)
{
    ui->setupUi(this);
}

UpdateArchitecte::~UpdateArchitecte()
{
    delete ui;
}
