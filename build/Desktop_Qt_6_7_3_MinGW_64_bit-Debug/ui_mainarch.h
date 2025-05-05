/********************************************************************************
** Form generated from reading UI file 'mainarch.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINARCH_H
#define UI_MAINARCH_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainArch
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *home_btn_2;
    QPushButton *dashborad_btn_2;
    QPushButton *orders_btn_2;
    QPushButton *products_btn_2;
    QPushButton *customers_btn_2;
    QPushButton *customers_btn_3;
    QPushButton *home_btn_3;
    QLabel *label_4;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_8;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_37;
    QPushButton *pushButton_sort;
    QTableView *tableView;
    QTextBrowser *textBrowser;
    QPushButton *exit_btn_2;
    QWidget *widget_6;
    QFrame *frame;
    QLineEdit *lineEdit_nom;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_3;
    QPushButton *pushButton_9;
    QPushButton *pushButton_7;
    QTextBrowser *textBrowser_4;
    QLineEdit *lineEdit_prenom;
    QLineEdit *lineEdit_telephone;
    QLineEdit *lineEdit_email;
    QLabel *label_6;
    QLineEdit *lineEdit_experience;
    QWidget *widget_7;
    QFrame *frame_2;
    QLineEdit *lineEdit_supprimer;
    QLabel *label_7;
    QPushButton *pushButton_8;
    QTextBrowser *textBrowser_5;
    QPushButton *pushButton_pdf;
    QPushButton *pushButton_update_2;
    QLineEdit *lineEdit_search;
    QPushButton *pushButton_search;

    void setupUi(QDialog *MainArch)
    {
        if (MainArch->objectName().isEmpty())
            MainArch->setObjectName("MainArch");
        MainArch->resize(1315, 826);
        layoutWidget = new QWidget(MainArch);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 150, 221, 321));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        home_btn_2 = new QPushButton(layoutWidget);
        home_btn_2->setObjectName("home_btn_2");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/icon/home-4-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon.addFile(QString::fromUtf8(":/icon/icon/home-4-48.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        home_btn_2->setIcon(icon);
        home_btn_2->setIconSize(QSize(14, 14));
        home_btn_2->setCheckable(true);
        home_btn_2->setAutoExclusive(true);

        verticalLayout_2->addWidget(home_btn_2);

        dashborad_btn_2 = new QPushButton(layoutWidget);
        dashborad_btn_2->setObjectName("dashborad_btn_2");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/icon/dashboard-5-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon1.addFile(QString::fromUtf8(":/icon/icon/dashboard-5-48.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        dashborad_btn_2->setIcon(icon1);
        dashborad_btn_2->setIconSize(QSize(14, 14));
        dashborad_btn_2->setCheckable(true);
        dashborad_btn_2->setAutoExclusive(true);

        verticalLayout_2->addWidget(dashborad_btn_2);

        orders_btn_2 = new QPushButton(layoutWidget);
        orders_btn_2->setObjectName("orders_btn_2");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/icon/activity-feed-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon2.addFile(QString::fromUtf8(":/icon/icon/activity-feed-48.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        orders_btn_2->setIcon(icon2);
        orders_btn_2->setIconSize(QSize(14, 14));
        orders_btn_2->setCheckable(true);
        orders_btn_2->setAutoExclusive(true);

        verticalLayout_2->addWidget(orders_btn_2);

        products_btn_2 = new QPushButton(layoutWidget);
        products_btn_2->setObjectName("products_btn_2");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/icon/product-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon3.addFile(QString::fromUtf8(":/icon/icon/product-48.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        products_btn_2->setIcon(icon3);
        products_btn_2->setIconSize(QSize(14, 14));
        products_btn_2->setCheckable(true);
        products_btn_2->setAutoExclusive(true);

        verticalLayout_2->addWidget(products_btn_2);

        customers_btn_2 = new QPushButton(layoutWidget);
        customers_btn_2->setObjectName("customers_btn_2");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/icon/group-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon4.addFile(QString::fromUtf8(":/icon/icon/group-48.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        customers_btn_2->setIcon(icon4);
        customers_btn_2->setIconSize(QSize(14, 14));
        customers_btn_2->setCheckable(true);
        customers_btn_2->setAutoExclusive(true);

        verticalLayout_2->addWidget(customers_btn_2);

        customers_btn_3 = new QPushButton(layoutWidget);
        customers_btn_3->setObjectName("customers_btn_3");
        customers_btn_3->setIcon(icon4);
        customers_btn_3->setIconSize(QSize(14, 14));
        customers_btn_3->setCheckable(true);
        customers_btn_3->setAutoExclusive(true);

        verticalLayout_2->addWidget(customers_btn_3);

        home_btn_3 = new QPushButton(layoutWidget);
        home_btn_3->setObjectName("home_btn_3");
        home_btn_3->setIcon(icon);
        home_btn_3->setIconSize(QSize(14, 14));
        home_btn_3->setCheckable(true);
        home_btn_3->setAutoExclusive(true);

        verticalLayout_2->addWidget(home_btn_3);

        label_4 = new QLabel(MainArch);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(890, 480, 531, 271));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../../../hayder/Desktop/download-removebg-preview.png")));
        widget_4 = new QWidget(MainArch);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(240, 360, 701, 291));
        widget_4->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        verticalLayout_8 = new QVBoxLayout(widget_4);
        verticalLayout_8->setObjectName("verticalLayout_8");
        frame_8 = new QFrame(widget_4);
        frame_8->setObjectName("frame_8");
        frame_8->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        frame_8->setFrameShape(QFrame::Shape::NoFrame);
        horizontalLayout_8 = new QHBoxLayout(frame_8);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_37 = new QLabel(frame_8);
        label_37->setObjectName("label_37");
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label_37->setFont(font);

        horizontalLayout_8->addWidget(label_37);

        pushButton_sort = new QPushButton(frame_8);
        pushButton_sort->setObjectName("pushButton_sort");
        pushButton_sort->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));

        horizontalLayout_8->addWidget(pushButton_sort);


        verticalLayout_8->addWidget(frame_8);

        tableView = new QTableView(widget_4);
        tableView->setObjectName("tableView");
        tableView->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_8->addWidget(tableView);

        textBrowser = new QTextBrowser(MainArch);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(70, 40, 1141, 51));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        exit_btn_2 = new QPushButton(MainArch);
        exit_btn_2->setObjectName("exit_btn_2");
        exit_btn_2->setGeometry(QRect(40, 510, 159, 29));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/icon/close-window-64.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        exit_btn_2->setIcon(icon5);
        exit_btn_2->setIconSize(QSize(14, 14));
        widget_6 = new QWidget(MainArch);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(230, 100, 351, 261));
        widget_6->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        frame = new QFrame(widget_6);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 10, 331, 241));
        frame->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        frame->setFrameShape(QFrame::Shape::NoFrame);
        lineEdit_nom = new QLineEdit(frame);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setEnabled(true);
        lineEdit_nom->setGeometry(QRect(100, 60, 191, 22));
        lineEdit_nom->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        lineEdit_nom->setReadOnly(false);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 60, 91, 16));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"rgb(170, 0, 127)\n"
"}"));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 120, 81, 16));
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 90, 81, 16));
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 150, 49, 16));
        pushButton_9 = new QPushButton(frame);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(250, 210, 75, 23));
        pushButton_9->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        pushButton_7 = new QPushButton(frame);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(140, 210, 75, 23));
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
""));
        textBrowser_4 = new QTextBrowser(frame);
        textBrowser_4->setObjectName("textBrowser_4");
        textBrowser_4->setGeometry(QRect(0, 0, 331, 51));
        textBrowser_4->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        lineEdit_prenom = new QLineEdit(frame);
        lineEdit_prenom->setObjectName("lineEdit_prenom");
        lineEdit_prenom->setGeometry(QRect(100, 90, 191, 22));
        lineEdit_prenom->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        lineEdit_prenom->setReadOnly(false);
        lineEdit_telephone = new QLineEdit(frame);
        lineEdit_telephone->setObjectName("lineEdit_telephone");
        lineEdit_telephone->setGeometry(QRect(100, 120, 191, 22));
        lineEdit_telephone->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        lineEdit_telephone->setReadOnly(false);
        lineEdit_email = new QLineEdit(frame);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setGeometry(QRect(100, 150, 191, 22));
        lineEdit_email->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        lineEdit_email->setReadOnly(false);
        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 180, 91, 16));
        lineEdit_experience = new QLineEdit(frame);
        lineEdit_experience->setObjectName("lineEdit_experience");
        lineEdit_experience->setGeometry(QRect(100, 180, 191, 22));
        lineEdit_experience->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        lineEdit_experience->setReadOnly(false);
        widget_7 = new QWidget(MainArch);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(580, 100, 361, 261));
        widget_7->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        frame_2 = new QFrame(widget_7);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(10, 10, 331, 241));
        frame_2->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        frame_2->setFrameShape(QFrame::Shape::NoFrame);
        lineEdit_supprimer = new QLineEdit(frame_2);
        lineEdit_supprimer->setObjectName("lineEdit_supprimer");
        lineEdit_supprimer->setEnabled(true);
        lineEdit_supprimer->setGeometry(QRect(100, 110, 191, 22));
        lineEdit_supprimer->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        lineEdit_supprimer->setReadOnly(false);
        label_7 = new QLabel(frame_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 110, 91, 16));
        label_7->setStyleSheet(QString::fromUtf8("QLabel{\n"
"rgb(170, 0, 127)\n"
"}"));
        pushButton_8 = new QPushButton(frame_2);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(20, 190, 75, 23));
        pushButton_8->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
""));
        textBrowser_5 = new QTextBrowser(frame_2);
        textBrowser_5->setObjectName("textBrowser_5");
        textBrowser_5->setGeometry(QRect(0, 0, 331, 51));
        textBrowser_5->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        pushButton_pdf = new QPushButton(frame_2);
        pushButton_pdf->setObjectName("pushButton_pdf");
        pushButton_pdf->setGeometry(QRect(220, 190, 75, 23));
        pushButton_pdf->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
""));
        pushButton_update_2 = new QPushButton(frame_2);
        pushButton_update_2->setObjectName("pushButton_update_2");
        pushButton_update_2->setGeometry(QRect(110, 190, 91, 23));
        pushButton_update_2->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
""));
        lineEdit_search = new QLineEdit(MainArch);
        lineEdit_search->setObjectName("lineEdit_search");
        lineEdit_search->setGeometry(QRect(390, 10, 563, 26));
        lineEdit_search->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_search = new QPushButton(MainArch);
        pushButton_search->setObjectName("pushButton_search");
        pushButton_search->setGeometry(QRect(960, 10, 93, 29));

        retranslateUi(MainArch);

        QMetaObject::connectSlotsByName(MainArch);
    } // setupUi

    void retranslateUi(QDialog *MainArch)
    {
        MainArch->setWindowTitle(QCoreApplication::translate("MainArch", "Dialog", nullptr));
        home_btn_2->setText(QCoreApplication::translate("MainArch", "Home", nullptr));
        dashborad_btn_2->setText(QCoreApplication::translate("MainArch", "Gestion d'employee", nullptr));
        orders_btn_2->setText(QCoreApplication::translate("MainArch", "Gestion des equipements", nullptr));
        products_btn_2->setText(QCoreApplication::translate("MainArch", "Gestion de projet", nullptr));
        customers_btn_2->setText(QCoreApplication::translate("MainArch", "Gestion de client", nullptr));
        customers_btn_3->setText(QCoreApplication::translate("MainArch", "Gestion de fournisseur", nullptr));
        home_btn_3->setText(QCoreApplication::translate("MainArch", "Gestion d'architecture", nullptr));
        label_4->setText(QString());
        label_37->setText(QCoreApplication::translate("MainArch", "Listes de architectes", nullptr));
        pushButton_sort->setText(QCoreApplication::translate("MainArch", "Sort", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainArch", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:18pt; font-weight:600; font-style:italic; text-decoration: underline;\">Gestion d'architecte</span></p></body></html>", nullptr));
        exit_btn_2->setText(QCoreApplication::translate("MainArch", "Exit", nullptr));
        label->setText(QCoreApplication::translate("MainArch", "Nom  :", nullptr));
        label_2->setText(QCoreApplication::translate("MainArch", "T\303\251lephone :", nullptr));
        label_5->setText(QCoreApplication::translate("MainArch", "Prenom :", nullptr));
        label_3->setText(QCoreApplication::translate("MainArch", "Email :", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainArch", "Annuler", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainArch", "AJouter", nullptr));
        textBrowser_4->setHtml(QCoreApplication::translate("MainArch", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">Ajouter un architecte</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("MainArch", "Experience :", nullptr));
        label_7->setText(QCoreApplication::translate("MainArch", "ID  :", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainArch", "Supprimer", nullptr));
        textBrowser_5->setHtml(QCoreApplication::translate("MainArch", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">Architecte</span></p></body></html>", nullptr));
        pushButton_pdf->setText(QCoreApplication::translate("MainArch", "PDF", nullptr));
        pushButton_update_2->setText(QCoreApplication::translate("MainArch", "mise a jour", nullptr));
        lineEdit_search->setPlaceholderText(QCoreApplication::translate("MainArch", "Search...", nullptr));
        pushButton_search->setText(QCoreApplication::translate("MainArch", "search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainArch: public Ui_MainArch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINARCH_H
