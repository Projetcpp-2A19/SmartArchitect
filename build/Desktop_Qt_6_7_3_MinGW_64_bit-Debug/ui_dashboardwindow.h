/********************************************************************************
** Form generated from reading UI file 'dashboardwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARDWINDOW_H
#define UI_DASHBOARDWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DashboardWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *full_menu_widget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *logo_label_2;
    QLabel *logo_label_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *home_btn_2;
    QPushButton *btnEmploye;
    QPushButton *orders_btn_2;
    QPushButton *btnProjet;
    QPushButton *customers_btn_2;
    QPushButton *customers_btn_3;
    QPushButton *home_btn_3;
    QSpacerItem *verticalSpacer_2;
    QPushButton *exit_btn_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *change_btn;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLineEdit *searchBar;
    QPushButton *btnRechercher;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *user_btn;
    QTextBrowser *textBrowser;
    QWidget *page_3;
    QWidget *page_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DashboardWindow)
    {
        if (DashboardWindow->objectName().isEmpty())
            DashboardWindow->setObjectName("DashboardWindow");
        DashboardWindow->resize(1410, 763);
        centralwidget = new QWidget(DashboardWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 1391, 711));
        page = new QWidget();
        page->setObjectName("page");
        full_menu_widget = new QWidget(page);
        full_menu_widget->setObjectName("full_menu_widget");
        full_menu_widget->setGeometry(QRect(0, 0, 181, 701));
        full_menu_widget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_4 = new QVBoxLayout(full_menu_widget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        logo_label_2 = new QLabel(full_menu_widget);
        logo_label_2->setObjectName("logo_label_2");
        logo_label_2->setMinimumSize(QSize(40, 40));
        logo_label_2->setMaximumSize(QSize(40, 40));
        logo_label_2->setPixmap(QPixmap(QString::fromUtf8(":/icon/icon/Logo.png")));
        logo_label_2->setScaledContents(true);

        horizontalLayout_2->addWidget(logo_label_2);

        logo_label_3 = new QLabel(full_menu_widget);
        logo_label_3->setObjectName("logo_label_3");
        QFont font;
        font.setPointSize(15);
        logo_label_3->setFont(font);

        horizontalLayout_2->addWidget(logo_label_3);


        verticalLayout_4->addLayout(horizontalLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        home_btn_2 = new QPushButton(full_menu_widget);
        home_btn_2->setObjectName("home_btn_2");
        QIcon icon;
        icon.addFile(QString::fromUtf8("../GProjett/icon/home-4-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        home_btn_2->setIcon(icon);
        home_btn_2->setIconSize(QSize(14, 14));
        home_btn_2->setCheckable(true);
        home_btn_2->setAutoExclusive(true);

        verticalLayout_2->addWidget(home_btn_2);

        btnEmploye = new QPushButton(full_menu_widget);
        btnEmploye->setObjectName("btnEmploye");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../GProjett/icon/group-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnEmploye->setIcon(icon1);
        btnEmploye->setIconSize(QSize(14, 14));
        btnEmploye->setCheckable(true);
        btnEmploye->setAutoExclusive(true);

        verticalLayout_2->addWidget(btnEmploye);

        orders_btn_2 = new QPushButton(full_menu_widget);
        orders_btn_2->setObjectName("orders_btn_2");
        orders_btn_2->setIcon(icon1);
        orders_btn_2->setIconSize(QSize(14, 14));
        orders_btn_2->setCheckable(true);
        orders_btn_2->setAutoExclusive(true);

        verticalLayout_2->addWidget(orders_btn_2);

        btnProjet = new QPushButton(full_menu_widget);
        btnProjet->setObjectName("btnProjet");
        btnProjet->setIcon(icon1);
        btnProjet->setIconSize(QSize(14, 14));
        btnProjet->setCheckable(true);
        btnProjet->setAutoExclusive(true);

        verticalLayout_2->addWidget(btnProjet);

        customers_btn_2 = new QPushButton(full_menu_widget);
        customers_btn_2->setObjectName("customers_btn_2");
        customers_btn_2->setIcon(icon1);
        customers_btn_2->setIconSize(QSize(14, 14));
        customers_btn_2->setCheckable(true);
        customers_btn_2->setAutoExclusive(true);

        verticalLayout_2->addWidget(customers_btn_2);

        customers_btn_3 = new QPushButton(full_menu_widget);
        customers_btn_3->setObjectName("customers_btn_3");
        customers_btn_3->setIcon(icon1);
        customers_btn_3->setIconSize(QSize(14, 14));
        customers_btn_3->setCheckable(true);
        customers_btn_3->setAutoExclusive(true);

        verticalLayout_2->addWidget(customers_btn_3);

        home_btn_3 = new QPushButton(full_menu_widget);
        home_btn_3->setObjectName("home_btn_3");
        home_btn_3->setIcon(icon1);
        home_btn_3->setIconSize(QSize(14, 14));
        home_btn_3->setCheckable(true);
        home_btn_3->setAutoExclusive(true);

        verticalLayout_2->addWidget(home_btn_3);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 373, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        exit_btn_2 = new QPushButton(full_menu_widget);
        exit_btn_2->setObjectName("exit_btn_2");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        exit_btn_2->setIcon(icon2);
        exit_btn_2->setIconSize(QSize(14, 14));

        verticalLayout_4->addWidget(exit_btn_2);

        widget = new QWidget(page);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(180, 0, 1191, 41));
        widget->setMinimumSize(QSize(0, 40));
        widget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 9, 0);
        change_btn = new QPushButton(widget);
        change_btn->setObjectName("change_btn");
        change_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../GProjett/icon/menu-4-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        change_btn->setIcon(icon3);
        change_btn->setIconSize(QSize(14, 14));
        change_btn->setCheckable(true);

        horizontalLayout_4->addWidget(change_btn);

        horizontalSpacer = new QSpacerItem(236, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        searchBar = new QLineEdit(widget);
        searchBar->setObjectName("searchBar");
        searchBar->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(searchBar);

        btnRechercher = new QPushButton(widget);
        btnRechercher->setObjectName("btnRechercher");
        btnRechercher->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../GProjett/icon/search-13-48.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnRechercher->setIcon(icon4);

        horizontalLayout->addWidget(btnRechercher);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(236, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        user_btn = new QPushButton(widget);
        user_btn->setObjectName("user_btn");
        user_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../GProjett/icon/user-48.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        user_btn->setIcon(icon5);

        horizontalLayout_4->addWidget(user_btn);

        textBrowser = new QTextBrowser(page);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(180, 40, 1141, 51));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        stackedWidget->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);
        DashboardWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DashboardWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1410, 22));
        DashboardWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DashboardWindow);
        statusbar->setObjectName("statusbar");
        DashboardWindow->setStatusBar(statusbar);

        retranslateUi(DashboardWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DashboardWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DashboardWindow)
    {
        DashboardWindow->setWindowTitle(QCoreApplication::translate("DashboardWindow", "MainWindow", nullptr));
        logo_label_2->setText(QString());
        logo_label_3->setText(QCoreApplication::translate("DashboardWindow", "Architexia", nullptr));
        home_btn_2->setText(QCoreApplication::translate("DashboardWindow", "Home", nullptr));
        btnEmploye->setText(QCoreApplication::translate("DashboardWindow", "Gestion d'employee", nullptr));
        orders_btn_2->setText(QCoreApplication::translate("DashboardWindow", "Gestion des equipements", nullptr));
        btnProjet->setText(QCoreApplication::translate("DashboardWindow", "Gestion de projet", nullptr));
        customers_btn_2->setText(QCoreApplication::translate("DashboardWindow", "Gestion de client", nullptr));
        customers_btn_3->setText(QCoreApplication::translate("DashboardWindow", "Gestion de fournisseur", nullptr));
        home_btn_3->setText(QCoreApplication::translate("DashboardWindow", "Gestion d'architecture", nullptr));
        exit_btn_2->setText(QCoreApplication::translate("DashboardWindow", "Exit", nullptr));
        change_btn->setText(QString());
        searchBar->setPlaceholderText(QCoreApplication::translate("DashboardWindow", "Search...", nullptr));
        btnRechercher->setText(QString());
        user_btn->setText(QString());
        textBrowser->setHtml(QCoreApplication::translate("DashboardWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; font-weight:700; font-style:italic; text-decoration: underline;\">Accueil</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DashboardWindow: public Ui_DashboardWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARDWINDOW_H
