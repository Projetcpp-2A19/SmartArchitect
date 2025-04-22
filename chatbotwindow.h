#ifndef CHATBOTWINDOW_H
#define CHATBOTWINDOW_H

#include <QDialog>

namespace Ui {
class ChatbotWindow;
}

class ChatbotWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ChatbotWindow(QWidget *parent = nullptr);
    ~ChatbotWindow();

private slots:
    void on_btnEnvoyer_clicked();

private:
    Ui::ChatbotWindow *ui;
    QString getChatbotResponse(const QString &message);
};

#endif // CHATBOTWINDOW_H
