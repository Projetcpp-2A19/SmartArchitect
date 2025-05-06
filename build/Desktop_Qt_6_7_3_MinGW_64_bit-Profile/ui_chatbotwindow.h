/********************************************************************************
** Form generated from reading UI file 'chatbotwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATBOTWINDOW_H
#define UI_CHATBOTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_ChatbotWindow
{
public:
    QLineEdit *lineEditMessage;
    QPushButton *btnEnvoyer;
    QLabel *label_2;
    QTextBrowser *textBrowserChat;
    QLabel *label;

    void setupUi(QDialog *ChatbotWindow)
    {
        if (ChatbotWindow->objectName().isEmpty())
            ChatbotWindow->setObjectName("ChatbotWindow");
        ChatbotWindow->resize(1355, 883);
        lineEditMessage = new QLineEdit(ChatbotWindow);
        lineEditMessage->setObjectName("lineEditMessage");
        lineEditMessage->setGeometry(QRect(140, 50, 291, 26));
        btnEnvoyer = new QPushButton(ChatbotWindow);
        btnEnvoyer->setObjectName("btnEnvoyer");
        btnEnvoyer->setGeometry(QRect(220, 320, 93, 29));
        label_2 = new QLabel(ChatbotWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 180, 63, 20));
        textBrowserChat = new QTextBrowser(ChatbotWindow);
        textBrowserChat->setObjectName("textBrowserChat");
        textBrowserChat->setGeometry(QRect(140, 100, 256, 192));
        label = new QLabel(ChatbotWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 50, 63, 20));

        retranslateUi(ChatbotWindow);

        QMetaObject::connectSlotsByName(ChatbotWindow);
    } // setupUi

    void retranslateUi(QDialog *ChatbotWindow)
    {
        ChatbotWindow->setWindowTitle(QCoreApplication::translate("ChatbotWindow", "Dialog", nullptr));
        btnEnvoyer->setText(QCoreApplication::translate("ChatbotWindow", "Envoyer", nullptr));
        label_2->setText(QCoreApplication::translate("ChatbotWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("ChatbotWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatbotWindow: public Ui_ChatbotWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATBOTWINDOW_H
