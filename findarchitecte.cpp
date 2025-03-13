#include "findarchitecte.h"
#include "ui_findarchitecte.h"

FindArchitecte::FindArchitecte(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FindArchitecte)
{
    ui->setupUi(this);
}

FindArchitecte::~FindArchitecte()
{
    delete ui;
}
