#include "supprimerarchitecte.h"
#include "ui_supprimerarchitecte.h"

SupprimerArchitecte::SupprimerArchitecte(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SupprimerArchitecte)
{
    ui->setupUi(this);
}

SupprimerArchitecte::~SupprimerArchitecte()
{
    delete ui;
}
