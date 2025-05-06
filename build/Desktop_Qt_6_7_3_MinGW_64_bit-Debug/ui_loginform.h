/********************************************************************************
** Form generated from reading UI file 'loginform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFORM_H
#define UI_LOGINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginForm
{
public:
    QWidget *widget;
    QWidget *widget_6;
    QFrame *frame;
    QTextBrowser *textBrowser;
    QLabel *emailLineEdit;
    QLabel *passwordLineEdit;
    QCheckBox *checkBoxShowPassword;
    QPushButton *btnLogin;
    QLabel *labelMessage;
    QLineEdit *lineEditEmail;
    QLineEdit *lineEditMdp;

    void setupUi(QWidget *LoginForm)
    {
        if (LoginForm->objectName().isEmpty())
            LoginForm->setObjectName("LoginForm");
        LoginForm->resize(761, 444);
        LoginForm->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(LoginForm);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(50, 20, 691, 391));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 127);"));
        widget_6 = new QWidget(widget);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(310, 70, 361, 281));
        widget_6->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        frame = new QFrame(widget_6);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 10, 341, 261));
        frame->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        frame->setFrameShape(QFrame::Shape::NoFrame);
        textBrowser = new QTextBrowser(frame);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(30, 10, 271, 31));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        emailLineEdit = new QLabel(frame);
        emailLineEdit->setObjectName("emailLineEdit");
        emailLineEdit->setGeometry(QRect(20, 70, 101, 20));
        passwordLineEdit = new QLabel(frame);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(20, 140, 81, 20));
        checkBoxShowPassword = new QCheckBox(frame);
        checkBoxShowPassword->setObjectName("checkBoxShowPassword");
        checkBoxShowPassword->setGeometry(QRect(30, 210, 201, 20));
        btnLogin = new QPushButton(frame);
        btnLogin->setObjectName("btnLogin");
        btnLogin->setGeometry(QRect(210, 230, 75, 24));
        labelMessage = new QLabel(frame);
        labelMessage->setObjectName("labelMessage");
        labelMessage->setGeometry(QRect(110, 40, 221, 31));
        lineEditEmail = new QLineEdit(frame);
        lineEditEmail->setObjectName("lineEditEmail");
        lineEditEmail->setGeometry(QRect(20, 100, 271, 22));
        lineEditEmail->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        lineEditMdp = new QLineEdit(frame);
        lineEditMdp->setObjectName("lineEditMdp");
        lineEditMdp->setGeometry(QRect(20, 170, 261, 22));
        lineEditMdp->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));

        retranslateUi(LoginForm);

        QMetaObject::connectSlotsByName(LoginForm);
    } // setupUi

    void retranslateUi(QWidget *LoginForm)
    {
        LoginForm->setWindowTitle(QCoreApplication::translate("LoginForm", "Form", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("LoginForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700; font-style:italic; color:#0d0d04;\">Login To Your account</span></p></body></html>", nullptr));
        emailLineEdit->setText(QCoreApplication::translate("LoginForm", "Email Adress:", nullptr));
        passwordLineEdit->setText(QCoreApplication::translate("LoginForm", "password:", nullptr));
        checkBoxShowPassword->setText(QCoreApplication::translate("LoginForm", "afficher/masquer le mot de passe", nullptr));
        btnLogin->setText(QCoreApplication::translate("LoginForm", "Connecter", nullptr));
        labelMessage->setText(QCoreApplication::translate("LoginForm", "Afficher l erreur", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginForm: public Ui_LoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H
