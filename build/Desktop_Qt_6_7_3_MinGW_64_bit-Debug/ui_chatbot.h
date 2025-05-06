/********************************************************************************
** Form generated from reading UI file 'chatbot.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATBOT_H
#define UI_CHATBOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_chatbot
{
public:
    QLabel *label_2;
    QPushButton *sendButton;
    QLabel *label;
    QLineEdit *messageInput;
    QTextEdit *chatBox;

    void setupUi(QDialog *chatbot)
    {
        if (chatbot->objectName().isEmpty())
            chatbot->setObjectName("chatbot");
        chatbot->resize(519, 366);
        label_2 = new QLabel(chatbot);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 60, 111, 16));
        sendButton = new QPushButton(chatbot);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(150, 260, 75, 24));
        label = new QLabel(chatbot);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 20, 51, 21));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);"));
        messageInput = new QLineEdit(chatbot);
        messageInput->setObjectName("messageInput");
        messageInput->setGeometry(QRect(50, 100, 141, 151));
        messageInput->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(145, 145, 145);"));
        chatBox = new QTextEdit(chatbot);
        chatBox->setObjectName("chatBox");
        chatBox->setGeometry(QRect(270, 80, 131, 141));

        retranslateUi(chatbot);

        QMetaObject::connectSlotsByName(chatbot);
    } // setupUi

    void retranslateUi(QDialog *chatbot)
    {
        chatbot->setWindowTitle(QCoreApplication::translate("chatbot", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("chatbot", "taper votre question", nullptr));
        sendButton->setText(QCoreApplication::translate("chatbot", "Envoyer", nullptr));
        label->setText(QCoreApplication::translate("chatbot", "Chatbot", nullptr));
        messageInput->setText(QCoreApplication::translate("chatbot", "vos questions......", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chatbot: public Ui_chatbot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATBOT_H
