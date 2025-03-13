#include "trouverarchitecte.h"
#include "ui_trouverarchitecte.h"

TrouverArchitecte::TrouverArchitecte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrouverArchitecte)
{
    ui->setupUi(this);
}

TrouverArchitecte::~TrouverArchitecte()
{
    delete ui;
}
