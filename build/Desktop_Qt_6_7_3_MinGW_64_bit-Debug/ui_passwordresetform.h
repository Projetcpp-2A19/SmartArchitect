/********************************************************************************
** Form generated from reading UI file 'passwordresetform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDRESETFORM_H
#define UI_PASSWORDRESETFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PasswordResetForm
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLineEdit *lineEditNewPassword;
    QLineEdit *lineEditConfirmPassword;
    QLineEdit *lineEditEmail;
    QLineEdit *lineEditCode;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *btnRequestCode;
    QPushButton *btnReset;
    QPushButton *btnResendCode;
    QWidget *page_2;

    void setupUi(QWidget *PasswordResetForm)
    {
        if (PasswordResetForm->objectName().isEmpty())
            PasswordResetForm->setObjectName("PasswordResetForm");
        PasswordResetForm->resize(762, 551);
        stackedWidget = new QStackedWidget(PasswordResetForm);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(100, 50, 591, 411));
        page = new QWidget();
        page->setObjectName("page");
        lineEditNewPassword = new QLineEdit(page);
        lineEditNewPassword->setObjectName("lineEditNewPassword");
        lineEditNewPassword->setGeometry(QRect(80, 90, 191, 22));
        lineEditConfirmPassword = new QLineEdit(page);
        lineEditConfirmPassword->setObjectName("lineEditConfirmPassword");
        lineEditConfirmPassword->setGeometry(QRect(110, 140, 191, 22));
        lineEditEmail = new QLineEdit(page);
        lineEditEmail->setObjectName("lineEditEmail");
        lineEditEmail->setGeometry(QRect(80, 40, 191, 22));
        lineEditCode = new QLineEdit(page);
        lineEditCode->setObjectName("lineEditCode");
        lineEditCode->setGeometry(QRect(80, 200, 121, 22));
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 40, 49, 16));
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 90, 49, 16));
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 140, 81, 16));
        label_4 = new QLabel(page);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 200, 49, 16));
        btnRequestCode = new QPushButton(page);
        btnRequestCode->setObjectName("btnRequestCode");
        btnRequestCode->setGeometry(QRect(240, 200, 75, 24));
        btnReset = new QPushButton(page);
        btnReset->setObjectName("btnReset");
        btnReset->setGeometry(QRect(240, 250, 75, 24));
        btnResendCode = new QPushButton(page);
        btnResendCode->setObjectName("btnResendCode");
        btnResendCode->setGeometry(QRect(240, 290, 75, 24));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        retranslateUi(PasswordResetForm);

        QMetaObject::connectSlotsByName(PasswordResetForm);
    } // setupUi

    void retranslateUi(QWidget *PasswordResetForm)
    {
        PasswordResetForm->setWindowTitle(QCoreApplication::translate("PasswordResetForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("PasswordResetForm", "email", nullptr));
        label_2->setText(QCoreApplication::translate("PasswordResetForm", "N mdp", nullptr));
        label_3->setText(QCoreApplication::translate("PasswordResetForm", "confirm mdp", nullptr));
        label_4->setText(QCoreApplication::translate("PasswordResetForm", "code", nullptr));
        btnRequestCode->setText(QCoreApplication::translate("PasswordResetForm", "Code", nullptr));
        btnReset->setText(QCoreApplication::translate("PasswordResetForm", "Reset", nullptr));
        btnResendCode->setText(QCoreApplication::translate("PasswordResetForm", "Renvoyer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PasswordResetForm: public Ui_PasswordResetForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDRESETFORM_H
