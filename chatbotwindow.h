#ifndef CHATBOTWINDOW_H
#define CHATBOTWINDOW_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class ChatbotWindow; }
QT_END_NAMESPACE

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
