#include "chatbot.h"
#include "ui_chatbot.h"

chatbot::chatbot(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::chatbot)
{
    ui->setupUi(this);
}

chatbot::~chatbot()
{
    delete ui;
}
