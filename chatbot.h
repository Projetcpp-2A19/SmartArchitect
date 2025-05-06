#ifndef CHATBOT_H
#define CHATBOT_H

#include <QDialog>
#include <QMap>
#include <QString>

namespace Ui {
class chatbot;
}

class chatbot : public QDialog
{
    Q_OBJECT

public:
    explicit chatbot(QWidget *parent = nullptr);
    ~chatbot();

private slots:
    void onSendMessage();

private:
    Ui::chatbot *ui;
    QMap<QString, QString> chatbotMemory;

    void initChatbotMemory();                      // Initialise les réponses dynamiques
    QString getDynamicResponse(const QString &);   // Retourne une réponse à partir du message
};

#endif // CHATBOT_H
