#include "ajouterarchitecte.h"
#include "ui_ajouterarchitecte.h"

AjouterArchitecte::AjouterArchitecte(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AjouterArchitecte)
{
    ui->setupUi(this);
}

AjouterArchitecte::~AjouterArchitecte()
{
    delete ui;
}
