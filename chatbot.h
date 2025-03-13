#ifndef CHATBOT_H
#define CHATBOT_H

#include <QDialog>

namespace Ui {
class chatbot;
}

class chatbot : public QDialog
{
    Q_OBJECT

public:
    explicit chatbot(QWidget *parent = nullptr);
    ~chatbot();

private:
    Ui::chatbot *ui;
};

#endif // CHATBOT_H
