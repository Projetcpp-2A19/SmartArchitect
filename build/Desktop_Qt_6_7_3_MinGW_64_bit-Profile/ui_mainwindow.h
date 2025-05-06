/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *full_menu_widget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *logo_label_4;
    QLabel *logo_label_5;
    QVBoxLayout *verticalLayout_3;
    QPushButton *home_btn_4;
    QPushButton *dashborad_btn_3;
    QPushButton *orders_btn_3;
    QPushButton *products_btn_3;
    QPushButton *customers_btn_4;
    QPushButton *customers_btn_5;
    QPushButton *home_btn_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *exit_btn_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *change_btn;
    QSpacerItem *horizontalSpacer;
    QPushButton *user_btn;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QTextBrowser *textBrowser;
    QWidget *widget_6;
    QFrame *frame;
    QLabel *label;
    QLabel *label_2;
    QTextBrowser *textBrowser_4;
    QLabel *label_46;
    QLabel *label_4;
    QLabel *label_42;
    QLabel *label_45;
    QPushButton *pushButton_2;
    QPushButton *btnAjouter;
    QLineEdit *lineEdit_poste;
    QLineEdit *lineEditPosition;
    QLineEdit *lineEditFirstName;
    QLineEdit *lineEditEmail;
    QLineEdit *lineEditSalary;
    QLineEdit *lineEditPassword;
    QLabel *label_5;
    QLineEdit *lineEditEmployeeId;
    QLineEdit *dateEditHireDate;
    QLineEdit *lineEditLastName;
    QLineEdit *lineEditRechercheIdNom;
    QLabel *label_37;
    QPushButton *btnStatsPoste;
    QLineEdit *lineEditBadgeUID;
    QPushButton *btnScanBadge;
    QTableView *tableView;
    QPushButton *btnSupprimer;
    QPushButton *btnModifier;
    QPushButton *btnTriSalaire;
    QPushButton *btnRechercheIdNom;
    QPushButton *btnAnnuler;
    QPushButton *btnExportPDF;
    QPushButton *btnOpenLogin;
    QTableWidget *tableWidgetLogs;
    QLineEdit *lineEdit_ID;
    QPushButton *btnAssocierBadge;
    QWidget *page_2;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_5;
    QFrame *card1;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_9;
    QLabel *label_6;
    QFrame *card2;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_7;
    QLabel *label_10;
    QFrame *card3;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_8;
    QLabel *label_11;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_6;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_12;
    QLabel *label_13;
    QFrame *frame_6;
    QGridLayout *gridLayout;
    QLabel *label_20;
    QLabel *label_23;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_17;
    QLabel *label_27;
    QLabel *label_19;
    QLabel *label_22;
    QLabel *label_26;
    QLabel *label_28;
    QLabel *label_25;
    QLabel *label_15;
    QLabel *label_18;
    QLabel *label_24;
    QLabel *label_14;
    QLabel *label_16;
    QLabel *label_21;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_10;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_29;
    QPushButton *pushButton;
    QLabel *label_31;
    QLabel *label_30;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QSpacerItem *verticalSpacer_4;
    QTextBrowser *textBrowser_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *search_input;
    QPushButton *search_btn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1391, 828);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        full_menu_widget = new QWidget(centralwidget);
        full_menu_widget->setObjectName("full_menu_widget");
        full_menu_widget->setGeometry(QRect(0, 20, 181, 701));
        full_menu_widget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_5 = new QVBoxLayout(full_menu_widget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        logo_label_4 = new QLabel(full_menu_widget);
        logo_label_4->setObjectName("logo_label_4");
        logo_label_4->setMinimumSize(QSize(40, 40));
        logo_label_4->setMaximumSize(QSize(40, 40));
        logo_label_4->setPixmap(QPixmap(QString::fromUtf8(":/icon/icon/Logo.png")));
        logo_label_4->setScaledContents(true);

        horizontalLayout_3->addWidget(logo_label_4);

        logo_label_5 = new QLabel(full_menu_widget);
        logo_label_5->setObjectName("logo_label_5");
        QFont font;
        font.setPointSize(15);
        logo_label_5->setFont(font);

        horizontalLayout_3->addWidget(logo_label_5);


        verticalLayout_5->addLayout(horizontalLayout_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        home_btn_4 = new QPushButton(full_menu_widget);
        home_btn_4->setObjectName("home_btn_4");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/icon/home-4-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon.addFile(QString::fromUtf8(":/icon/icon/home-4-48.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        home_btn_4->setIcon(icon);
        home_btn_4->setIconSize(QSize(14, 14));
        home_btn_4->setCheckable(true);
        home_btn_4->setAutoExclusive(true);

        verticalLayout_3->addWidget(home_btn_4);

        dashborad_btn_3 = new QPushButton(full_menu_widget);
        dashborad_btn_3->setObjectName("dashborad_btn_3");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/icon/dashboard-5-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon1.addFile(QString::fromUtf8(":/icon/icon/dashboard-5-48.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        dashborad_btn_3->setIcon(icon1);
        dashborad_btn_3->setIconSize(QSize(14, 14));
        dashborad_btn_3->setCheckable(true);
        dashborad_btn_3->setAutoExclusive(true);

        verticalLayout_3->addWidget(dashborad_btn_3);

        orders_btn_3 = new QPushButton(full_menu_widget);
        orders_btn_3->setObjectName("orders_btn_3");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/icon/activity-feed-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon2.addFile(QString::fromUtf8(":/icon/icon/activity-feed-48.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        orders_btn_3->setIcon(icon2);
        orders_btn_3->setIconSize(QSize(14, 14));
        orders_btn_3->setCheckable(true);
        orders_btn_3->setAutoExclusive(true);

        verticalLayout_3->addWidget(orders_btn_3);

        products_btn_3 = new QPushButton(full_menu_widget);
        products_btn_3->setObjectName("products_btn_3");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/icon/product-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon3.addFile(QString::fromUtf8(":/icon/icon/product-48.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        products_btn_3->setIcon(icon3);
        products_btn_3->setIconSize(QSize(14, 14));
        products_btn_3->setCheckable(true);
        products_btn_3->setAutoExclusive(true);

        verticalLayout_3->addWidget(products_btn_3);

        customers_btn_4 = new QPushButton(full_menu_widget);
        customers_btn_4->setObjectName("customers_btn_4");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/icon/group-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon4.addFile(QString::fromUtf8(":/icon/icon/group-48.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        customers_btn_4->setIcon(icon4);
        customers_btn_4->setIconSize(QSize(14, 14));
        customers_btn_4->setCheckable(true);
        customers_btn_4->setAutoExclusive(true);

        verticalLayout_3->addWidget(customers_btn_4);

        customers_btn_5 = new QPushButton(full_menu_widget);
        customers_btn_5->setObjectName("customers_btn_5");
        customers_btn_5->setIcon(icon4);
        customers_btn_5->setIconSize(QSize(14, 14));
        customers_btn_5->setCheckable(true);
        customers_btn_5->setAutoExclusive(true);

        verticalLayout_3->addWidget(customers_btn_5);

        home_btn_5 = new QPushButton(full_menu_widget);
        home_btn_5->setObjectName("home_btn_5");
        home_btn_5->setIcon(icon);
        home_btn_5->setIconSize(QSize(14, 14));
        home_btn_5->setCheckable(true);
        home_btn_5->setAutoExclusive(true);

        verticalLayout_3->addWidget(home_btn_5);

        horizontalSpacer_2 = new QSpacerItem(236, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(verticalLayout_3);

        exit_btn_3 = new QPushButton(full_menu_widget);
        exit_btn_3->setObjectName("exit_btn_3");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/icon/close-window-64.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        exit_btn_3->setIcon(icon5);
        exit_btn_3->setIconSize(QSize(14, 14));

        verticalLayout_5->addWidget(exit_btn_3);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(170, 30, 1191, 41));
        widget->setMinimumSize(QSize(0, 40));
        widget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 9, 0);
        change_btn = new QPushButton(widget);
        change_btn->setObjectName("change_btn");
        change_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icon/icon/menu-4-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        change_btn->setIcon(icon6);
        change_btn->setIconSize(QSize(14, 14));
        change_btn->setCheckable(true);

        horizontalLayout_4->addWidget(change_btn);

        horizontalSpacer = new QSpacerItem(236, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        horizontalLayout_4->addItem(horizontalSpacer);

        user_btn = new QPushButton(widget);
        user_btn->setObjectName("user_btn");
        user_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icon/icon/user-48.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        user_btn->setIcon(icon7);

        horizontalLayout_4->addWidget(user_btn);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(190, 80, 1211, 761));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        page = new QWidget();
        page->setObjectName("page");
        textBrowser = new QTextBrowser(page);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(-10, 0, 1141, 51));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        widget_6 = new QWidget(page);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(-1, 70, 1131, 261));
        widget_6->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        frame = new QFrame(widget_6);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 10, 1101, 241));
        frame->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        frame->setFrameShape(QFrame::Shape::NoFrame);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 60, 91, 16));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"rgb(170, 0, 127)\n"
"}"));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(570, 90, 131, 16));
        textBrowser_4 = new QTextBrowser(frame);
        textBrowser_4->setObjectName("textBrowser_4");
        textBrowser_4->setGeometry(QRect(290, 0, 471, 51));
        textBrowser_4->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        label_46 = new QLabel(frame);
        label_46->setObjectName("label_46");
        label_46->setGeometry(QRect(10, 90, 91, 16));
        label_46->setStyleSheet(QString::fromUtf8("QLabel{\n"
"rgb(170, 0, 127)\n"
"}"));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(570, 120, 49, 16));
        label_42 = new QLabel(frame);
        label_42->setObjectName("label_42");
        label_42->setGeometry(QRect(10, 150, 111, 21));
        label_45 = new QLabel(frame);
        label_45->setObjectName("label_45");
        label_45->setGeometry(QRect(570, 60, 71, 16));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(30, 200, 75, 24));
        btnAjouter = new QPushButton(frame);
        btnAjouter->setObjectName("btnAjouter");
        btnAjouter->setGeometry(QRect(130, 200, 75, 24));
        lineEdit_poste = new QLineEdit(frame);
        lineEdit_poste->setObjectName("lineEdit_poste");
        lineEdit_poste->setGeometry(QRect(100, 150, 191, 22));
        lineEdit_poste->setStyleSheet(QString::fromUtf8(""));
        lineEditPosition = new QLineEdit(frame);
        lineEditPosition->setObjectName("lineEditPosition");
        lineEditPosition->setGeometry(QRect(110, 120, 191, 22));
        lineEditPosition->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
""));
        lineEditFirstName = new QLineEdit(frame);
        lineEditFirstName->setObjectName("lineEditFirstName");
        lineEditFirstName->setGeometry(QRect(110, 90, 191, 22));
        lineEditFirstName->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
""));
        lineEditEmail = new QLineEdit(frame);
        lineEditEmail->setObjectName("lineEditEmail");
        lineEditEmail->setGeometry(QRect(700, 60, 191, 22));
        lineEditEmail->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
""));
        lineEditSalary = new QLineEdit(frame);
        lineEditSalary->setObjectName("lineEditSalary");
        lineEditSalary->setGeometry(QRect(700, 120, 191, 22));
        lineEditSalary->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
""));
        lineEditPassword = new QLineEdit(frame);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setGeometry(QRect(110, 150, 191, 22));
        lineEditPassword->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
""));
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(570, 150, 91, 16));
        label_5->setStyleSheet(QString::fromUtf8("QLabel{\n"
"rgb(170, 0, 127)\n"
"}"));
        lineEditEmployeeId = new QLineEdit(frame);
        lineEditEmployeeId->setObjectName("lineEditEmployeeId");
        lineEditEmployeeId->setGeometry(QRect(700, 150, 191, 22));
        lineEditEmployeeId->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
""));
        dateEditHireDate = new QLineEdit(frame);
        dateEditHireDate->setObjectName("dateEditHireDate");
        dateEditHireDate->setGeometry(QRect(700, 90, 191, 22));
        dateEditHireDate->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
""));
        lineEditLastName = new QLineEdit(frame);
        lineEditLastName->setObjectName("lineEditLastName");
        lineEditLastName->setGeometry(QRect(110, 60, 191, 22));
        lineEditLastName->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
""));
        lineEditRechercheIdNom = new QLineEdit(frame);
        lineEditRechercheIdNom->setObjectName("lineEditRechercheIdNom");
        lineEditRechercheIdNom->setGeometry(QRect(700, 180, 191, 22));
        lineEditRechercheIdNom->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
""));
        label_37 = new QLabel(frame);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(500, 180, 191, 20));
        label_37->setStyleSheet(QString::fromUtf8("QLabel{\n"
"rgb(170, 0, 127)\n"
"}"));
        btnStatsPoste = new QPushButton(frame);
        btnStatsPoste->setObjectName("btnStatsPoste");
        btnStatsPoste->setGeometry(QRect(0, 120, 75, 24));
        lineEditBadgeUID = new QLineEdit(frame);
        lineEditBadgeUID->setObjectName("lineEditBadgeUID");
        lineEditBadgeUID->setGeometry(QRect(700, 210, 191, 22));
        lineEditBadgeUID->setStyleSheet(QString::fromUtf8("border: 1px solid black;"));
        btnScanBadge = new QPushButton(frame);
        btnScanBadge->setObjectName("btnScanBadge");
        btnScanBadge->setGeometry(QRect(920, 210, 75, 24));
        tableView = new QTableView(page);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 390, 741, 211));
        btnSupprimer = new QPushButton(page);
        btnSupprimer->setObjectName("btnSupprimer");
        btnSupprimer->setGeometry(QRect(100, 350, 75, 24));
        btnModifier = new QPushButton(page);
        btnModifier->setObjectName("btnModifier");
        btnModifier->setGeometry(QRect(210, 350, 75, 24));
        btnTriSalaire = new QPushButton(page);
        btnTriSalaire->setObjectName("btnTriSalaire");
        btnTriSalaire->setGeometry(QRect(310, 350, 111, 24));
        btnRechercheIdNom = new QPushButton(page);
        btnRechercheIdNom->setObjectName("btnRechercheIdNom");
        btnRechercheIdNom->setGeometry(QRect(450, 350, 131, 24));
        btnAnnuler = new QPushButton(page);
        btnAnnuler->setObjectName("btnAnnuler");
        btnAnnuler->setGeometry(QRect(910, 350, 75, 24));
        btnExportPDF = new QPushButton(page);
        btnExportPDF->setObjectName("btnExportPDF");
        btnExportPDF->setGeometry(QRect(600, 350, 131, 24));
        btnOpenLogin = new QPushButton(page);
        btnOpenLogin->setObjectName("btnOpenLogin");
        btnOpenLogin->setGeometry(QRect(10, 350, 75, 24));
        tableWidgetLogs = new QTableWidget(page);
        tableWidgetLogs->setObjectName("tableWidgetLogs");
        tableWidgetLogs->setGeometry(QRect(775, 420, 351, 192));
        lineEdit_ID = new QLineEdit(page);
        lineEdit_ID->setObjectName("lineEdit_ID");
        lineEdit_ID->setGeometry(QRect(1010, 390, 113, 22));
        btnAssocierBadge = new QPushButton(page);
        btnAssocierBadge->setObjectName("btnAssocierBadge");
        btnAssocierBadge->setGeometry(QRect(844, 390, 141, 24));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        frame_3 = new QFrame(page_2);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(30, 40, 711, 111));
        frame_3->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        frame_3->setFrameShape(QFrame::Shape::NoFrame);
        horizontalLayout_5 = new QHBoxLayout(frame_3);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        card1 = new QFrame(frame_3);
        card1->setObjectName("card1");
        card1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        card1->setFrameShape(QFrame::Shape::NoFrame);
        verticalLayout_6 = new QVBoxLayout(card1);
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_9 = new QLabel(card1);
        label_9->setObjectName("label_9");
        QFont font1;
        font1.setPointSize(14);
        font1.setUnderline(true);
        label_9->setFont(font1);

        verticalLayout_6->addWidget(label_9);

        label_6 = new QLabel(card1);
        label_6->setObjectName("label_6");
        QFont font2;
        font2.setPointSize(12);
        label_6->setFont(font2);

        verticalLayout_6->addWidget(label_6);


        horizontalLayout_5->addWidget(card1);

        card2 = new QFrame(frame_3);
        card2->setObjectName("card2");
        card2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        card2->setFrameShape(QFrame::Shape::NoFrame);
        verticalLayout_7 = new QVBoxLayout(card2);
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_7 = new QLabel(card2);
        label_7->setObjectName("label_7");
        label_7->setFont(font1);
        label_7->setAcceptDrops(false);

        verticalLayout_7->addWidget(label_7);

        label_10 = new QLabel(card2);
        label_10->setObjectName("label_10");
        label_10->setFont(font2);

        verticalLayout_7->addWidget(label_10);


        horizontalLayout_5->addWidget(card2);

        card3 = new QFrame(frame_3);
        card3->setObjectName("card3");
        card3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        card3->setFrameShape(QFrame::Shape::NoFrame);
        verticalLayout_9 = new QVBoxLayout(card3);
        verticalLayout_9->setObjectName("verticalLayout_9");
        label_8 = new QLabel(card3);
        label_8->setObjectName("label_8");
        label_8->setFont(font1);

        verticalLayout_9->addWidget(label_8);

        label_11 = new QLabel(card3);
        label_11->setObjectName("label_11");
        label_11->setFont(font2);

        verticalLayout_9->addWidget(label_11);


        horizontalLayout_5->addWidget(card3);

        frame_4 = new QFrame(page_2);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(10, 160, 741, 371));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        frame_4->setFrameShape(QFrame::Shape::NoFrame);
        horizontalLayout_6 = new QHBoxLayout(frame_4);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        widget_2 = new QWidget(frame_4);
        widget_2->setObjectName("widget_2");
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName("verticalLayout");
        frame_5 = new QFrame(widget_2);
        frame_5->setObjectName("frame_5");
        frame_5->setStyleSheet(QString::fromUtf8(""));
        frame_5->setFrameShape(QFrame::Shape::NoFrame);
        horizontalLayout_7 = new QHBoxLayout(frame_5);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_12 = new QLabel(frame_5);
        label_12->setObjectName("label_12");
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        label_12->setFont(font3);

        horizontalLayout_7->addWidget(label_12);

        label_13 = new QLabel(frame_5);
        label_13->setObjectName("label_13");

        horizontalLayout_7->addWidget(label_13);


        verticalLayout->addWidget(frame_5);

        frame_6 = new QFrame(widget_2);
        frame_6->setObjectName("frame_6");
        sizePolicy.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy);
        frame_6->setStyleSheet(QString::fromUtf8(""));
        frame_6->setFrameShape(QFrame::Shape::NoFrame);
        gridLayout = new QGridLayout(frame_6);
        gridLayout->setObjectName("gridLayout");
        label_20 = new QLabel(frame_6);
        label_20->setObjectName("label_20");

        gridLayout->addWidget(label_20, 3, 0, 1, 1);

        label_23 = new QLabel(frame_6);
        label_23->setObjectName("label_23");

        gridLayout->addWidget(label_23, 4, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 373, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 6, 1, 1, 1);

        label_17 = new QLabel(frame_6);
        label_17->setObjectName("label_17");

        gridLayout->addWidget(label_17, 2, 0, 1, 1);

        label_27 = new QLabel(frame_6);
        label_27->setObjectName("label_27");

        gridLayout->addWidget(label_27, 5, 1, 1, 1);

        label_19 = new QLabel(frame_6);
        label_19->setObjectName("label_19");

        gridLayout->addWidget(label_19, 2, 2, 1, 1);

        label_22 = new QLabel(frame_6);
        label_22->setObjectName("label_22");

        gridLayout->addWidget(label_22, 3, 2, 1, 1);

        label_26 = new QLabel(frame_6);
        label_26->setObjectName("label_26");

        gridLayout->addWidget(label_26, 5, 0, 1, 1);

        label_28 = new QLabel(frame_6);
        label_28->setObjectName("label_28");

        gridLayout->addWidget(label_28, 5, 2, 1, 1);

        label_25 = new QLabel(frame_6);
        label_25->setObjectName("label_25");

        gridLayout->addWidget(label_25, 4, 2, 1, 1);

        label_15 = new QLabel(frame_6);
        label_15->setObjectName("label_15");
        QFont font4;
        font4.setPointSize(13);
        font4.setBold(true);
        label_15->setFont(font4);

        gridLayout->addWidget(label_15, 0, 1, 1, 1);

        label_18 = new QLabel(frame_6);
        label_18->setObjectName("label_18");

        gridLayout->addWidget(label_18, 2, 1, 1, 1);

        label_24 = new QLabel(frame_6);
        label_24->setObjectName("label_24");

        gridLayout->addWidget(label_24, 4, 1, 1, 1);

        label_14 = new QLabel(frame_6);
        label_14->setObjectName("label_14");
        label_14->setFont(font4);

        gridLayout->addWidget(label_14, 0, 0, 1, 1);

        label_16 = new QLabel(frame_6);
        label_16->setObjectName("label_16");
        label_16->setFont(font4);

        gridLayout->addWidget(label_16, 0, 2, 1, 1);

        label_21 = new QLabel(frame_6);
        label_21->setObjectName("label_21");

        gridLayout->addWidget(label_21, 3, 1, 1, 1);


        verticalLayout->addWidget(frame_6);


        horizontalLayout_6->addWidget(widget_2);

        widget_3 = new QWidget(frame_4);
        widget_3->setObjectName("widget_3");
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        verticalLayout_10 = new QVBoxLayout(widget_3);
        verticalLayout_10->setObjectName("verticalLayout_10");
        frame_7 = new QFrame(widget_3);
        frame_7->setObjectName("frame_7");
        frame_7->setStyleSheet(QString::fromUtf8(""));
        frame_7->setFrameShape(QFrame::Shape::NoFrame);
        horizontalLayout_9 = new QHBoxLayout(frame_7);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_29 = new QLabel(frame_7);
        label_29->setObjectName("label_29");
        label_29->setFont(font3);

        horizontalLayout_9->addWidget(label_29);

        pushButton = new QPushButton(frame_7);
        pushButton->setObjectName("pushButton");

        horizontalLayout_9->addWidget(pushButton);


        verticalLayout_10->addWidget(frame_7);

        label_31 = new QLabel(widget_3);
        label_31->setObjectName("label_31");

        verticalLayout_10->addWidget(label_31);

        label_30 = new QLabel(widget_3);
        label_30->setObjectName("label_30");

        verticalLayout_10->addWidget(label_30);

        label_32 = new QLabel(widget_3);
        label_32->setObjectName("label_32");

        verticalLayout_10->addWidget(label_32);

        label_33 = new QLabel(widget_3);
        label_33->setObjectName("label_33");

        verticalLayout_10->addWidget(label_33);

        label_34 = new QLabel(widget_3);
        label_34->setObjectName("label_34");

        verticalLayout_10->addWidget(label_34);

        label_35 = new QLabel(widget_3);
        label_35->setObjectName("label_35");

        verticalLayout_10->addWidget(label_35);

        label_36 = new QLabel(widget_3);
        label_36->setObjectName("label_36");

        verticalLayout_10->addWidget(label_36);

        verticalSpacer_4 = new QSpacerItem(20, 373, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_4);


        horizontalLayout_6->addWidget(widget_3);

        textBrowser_3 = new QTextBrowser(page_2);
        textBrowser_3->setObjectName("textBrowser_3");
        textBrowser_3->setGeometry(QRect(120, 0, 511, 41));
        textBrowser_3->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        stackedWidget->addWidget(page_2);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(440, 0, 620, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        search_input = new QLineEdit(layoutWidget);
        search_input->setObjectName("search_input");
        search_input->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(search_input);

        search_btn = new QPushButton(layoutWidget);
        search_btn->setObjectName("search_btn");
        search_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icon/icon/search-13-48.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        search_btn->setIcon(icon8);

        horizontalLayout->addWidget(search_btn);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1391, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        logo_label_4->setText(QString());
        logo_label_5->setText(QCoreApplication::translate("MainWindow", "Architexia", nullptr));
        home_btn_4->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        dashborad_btn_3->setText(QCoreApplication::translate("MainWindow", "Gestion d'employee", nullptr));
        orders_btn_3->setText(QCoreApplication::translate("MainWindow", "Gestion des equipements", nullptr));
        products_btn_3->setText(QCoreApplication::translate("MainWindow", "Gestion de fournisseur", nullptr));
        customers_btn_4->setText(QCoreApplication::translate("MainWindow", "Gestion de client", nullptr));
        customers_btn_5->setText(QCoreApplication::translate("MainWindow", "Gestion de projet", nullptr));
        home_btn_5->setText(QCoreApplication::translate("MainWindow", "Gestion d'architecture", nullptr));
        exit_btn_3->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        change_btn->setText(QString());
        user_btn->setText(QString());
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:18pt; font-weight:600; font-style:italic; text-decoration: underline;\">Gestion d'employee</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Date d'embauche ", nullptr));
        textBrowser_4->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">Ajouter d'un employee</span></p></body></html>", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "prenom", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "salaire:", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "mot de pass", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "Email:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        btnAjouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        lineEditLastName->setText(QString());
        label_37->setText(QCoreApplication::translate("MainWindow", "tappez ici pour rechercher!", nullptr));
        btnStatsPoste->setText(QCoreApplication::translate("MainWindow", "poste", nullptr));
        btnScanBadge->setText(QCoreApplication::translate("MainWindow", "Scan", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        btnModifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        btnTriSalaire->setText(QCoreApplication::translate("MainWindow", " tri par salaire", nullptr));
        btnRechercheIdNom->setText(QCoreApplication::translate("MainWindow", "recherche", nullptr));
        btnAnnuler->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        btnExportPDF->setText(QCoreApplication::translate("MainWindow", "exporter pdf", nullptr));
        btnOpenLogin->setText(QCoreApplication::translate("MainWindow", "Connexion", nullptr));
        btnAssocierBadge->setText(QCoreApplication::translate("MainWindow", "Modifier UID badge", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Nombre de projet:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "200", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Nombre d'employee", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "200", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Nombre de Fournisseur", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "200", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Listes", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "voir plus", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Nom de Client", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Projet", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Fournissuer", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Notre equipe", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Voir plus", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "Firas", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "Wsssem", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "Hadyder", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        textBrowser_3->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:696; font-style:italic;\">Home</span></p></body></html>", nullptr));
        search_input->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search...", nullptr));
        search_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
