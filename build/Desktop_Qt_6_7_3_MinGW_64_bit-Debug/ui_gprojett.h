/********************************************************************************
** Form generated from reading UI file 'gprojett.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GPROJETT_H
#define UI_GPROJETT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GProjett
{
public:
    QWidget *centralwidget;
    QWidget *full_menu_widget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *logo_label_2;
    QLabel *logo_label_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *home_btn_2;
    QPushButton *dashborad_btn_2;
    QPushButton *orders_btn_2;
    QPushButton *products_btn_2;
    QPushButton *customers_btn_2;
    QPushButton *customers_btn_3;
    QPushButton *home_btn_3;
    QSpacerItem *verticalSpacer_2;
    QPushButton *exit_btn_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QTextBrowser *textBrowser;
    QWidget *widget_5;
    QTextBrowser *textBrowser_2;
    QLabel *label_65;
    QLineEdit *lineEditEmail;
    QPushButton *btnEnvoyerEmail;
    QWidget *widget_6;
    QFrame *frame;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *btnAnnuler;
    QPushButton *btnAjouter;
    QTextBrowser *textBrowser_4;
    QLineEdit *lineEdit_client;
    QLabel *label_37;
    QComboBox *comboBox_status;
    QDateEdit *dateEdit_debut;
    QDateEdit *dateEdit_fin;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_budget;
    QTableView *tableView;
    QPushButton *btnModifier;
    QPushButton *btnSupprimer;
    QPushButton *btnDesc;
    QPushButton *btnAsc;
    QPushButton *btnExporterPDF;
    QPushButton *btnShowStats;
    QWidget *gridLayoutWidget;
    QGridLayout *financeLayout;
    QLabel *lblTotalBudget;
    QLabel *lblTotalActual;
    QLabel *lblTotalEstimated;
    QLabel *lblDeviation;
    QPushButton *btnRefreshFinance;
    QPushButton *btnArduino;
    QWidget *page_2;
    QTextBrowser *textBrowser_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *change_btn;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLineEdit *searchBar;
    QPushButton *btnRechercher;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *user_btn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GProjett)
    {
        if (GProjett->objectName().isEmpty())
            GProjett->setObjectName("GProjett");
        GProjett->resize(1375, 737);
        centralwidget = new QWidget(GProjett);
        centralwidget->setObjectName("centralwidget");
        full_menu_widget = new QWidget(centralwidget);
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

        dashborad_btn_2 = new QPushButton(full_menu_widget);
        dashborad_btn_2->setObjectName("dashborad_btn_2");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../GProjett/icon/group-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        dashborad_btn_2->setIcon(icon1);
        dashborad_btn_2->setIconSize(QSize(14, 14));
        dashborad_btn_2->setCheckable(true);
        dashborad_btn_2->setAutoExclusive(true);

        verticalLayout_2->addWidget(dashborad_btn_2);

        orders_btn_2 = new QPushButton(full_menu_widget);
        orders_btn_2->setObjectName("orders_btn_2");
        orders_btn_2->setIcon(icon1);
        orders_btn_2->setIconSize(QSize(14, 14));
        orders_btn_2->setCheckable(true);
        orders_btn_2->setAutoExclusive(true);

        verticalLayout_2->addWidget(orders_btn_2);

        products_btn_2 = new QPushButton(full_menu_widget);
        products_btn_2->setObjectName("products_btn_2");
        products_btn_2->setIcon(icon1);
        products_btn_2->setIconSize(QSize(14, 14));
        products_btn_2->setCheckable(true);
        products_btn_2->setAutoExclusive(true);

        verticalLayout_2->addWidget(products_btn_2);

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

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(180, 40, 1211, 861));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        page = new QWidget();
        page->setObjectName("page");
        textBrowser = new QTextBrowser(page);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(30, 10, 1141, 51));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        widget_5 = new QWidget(page);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(350, 70, 291, 261));
        textBrowser_2 = new QTextBrowser(widget_5);
        textBrowser_2->setObjectName("textBrowser_2");
        textBrowser_2->setGeometry(QRect(0, 0, 291, 51));
        textBrowser_2->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        label_65 = new QLabel(widget_5);
        label_65->setObjectName("label_65");
        label_65->setGeometry(QRect(10, 60, 61, 61));
        lineEditEmail = new QLineEdit(widget_5);
        lineEditEmail->setObjectName("lineEditEmail");
        lineEditEmail->setGeometry(QRect(60, 80, 211, 20));
        btnEnvoyerEmail = new QPushButton(widget_5);
        btnEnvoyerEmail->setObjectName("btnEnvoyerEmail");
        btnEnvoyerEmail->setGeometry(QRect(190, 130, 84, 23));
        btnEnvoyerEmail->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}\n"
"\n"
""));
        widget_6 = new QWidget(page);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(-1, 70, 351, 321));
        widget_6->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        frame = new QFrame(widget_6);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 10, 331, 301));
        frame->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        frame->setFrameShape(QFrame::Shape::NoFrame);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 70, 91, 16));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"rgb(170, 0, 127)\n"
"}"));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 150, 61, 16));
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 110, 81, 16));
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 180, 49, 16));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 220, 49, 16));
        btnAnnuler = new QPushButton(frame);
        btnAnnuler->setObjectName("btnAnnuler");
        btnAnnuler->setGeometry(QRect(240, 260, 84, 23));
        btnAnnuler->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}\n"
""));
        btnAjouter = new QPushButton(frame);
        btnAjouter->setObjectName("btnAjouter");
        btnAjouter->setGeometry(QRect(240, 230, 84, 23));
        btnAjouter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}\n"
""));
        textBrowser_4 = new QTextBrowser(frame);
        textBrowser_4->setObjectName("textBrowser_4");
        textBrowser_4->setGeometry(QRect(0, 0, 331, 51));
        textBrowser_4->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        lineEdit_client = new QLineEdit(frame);
        lineEdit_client->setObjectName("lineEdit_client");
        lineEdit_client->setGeometry(QRect(70, 260, 151, 22));
        lineEdit_client->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	 border: 2px solid rgba(0, 0, 0, 100);  /* Bordure bleue */\n"
"    border-radius: 5px;  /* Coins arrondis */\n"
"}"));
        label_37 = new QLabel(frame);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(0, 260, 49, 16));
        comboBox_status = new QComboBox(frame);
        comboBox_status->addItem(QString());
        comboBox_status->addItem(QString());
        comboBox_status->addItem(QString());
        comboBox_status->setObjectName("comboBox_status");
        comboBox_status->setGeometry(QRect(60, 220, 121, 31));
        comboBox_status->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: rgba(0, 0, 0, 100);\n"
"    border: 2px solid rgba(0, 0, 0, 100);\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"    color: white;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    background-color: rgba(0, 0, 0, 80); /* L\303\251ger \303\251claircissement au survol */\n"
"    border: 2px solid rgba(0, 0, 0, 120);\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 2px solid rgba(0, 0, 0, 150);\n"
"    background-color: rgba(0, 0, 0, 120);\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    width: 20px;\n"
"    border-left: 2px solid rgba(255, 255, 255, 50);\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(C:/Users/FK Info/Desktop/GProjett/icon/down1.png); /* Remplace par ton ic\303\264ne */\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: rgba(0, 0, 0, 100);\n"
"    border: 2px solid rgba(0, 0, 0, 150);\n"
"    selection-background-color: rgba(255, 255, 255, 50);\n"
"    selection-colo"
                        "r: white;\n"
"    color: white;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item {\n"
"    padding: 5px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item:hover {\n"
"    background-color: rgba(255, 255, 255, 50);\n"
"}\n"
""));
        dateEdit_debut = new QDateEdit(frame);
        dateEdit_debut->setObjectName("dateEdit_debut");
        dateEdit_debut->setGeometry(QRect(80, 100, 131, 31));
        dateEdit_debut->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    background-color: rgba(0, 0, 0, 100);\n"
"    border: 2px solid rgba(0, 0, 0, 100);\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"    selection-background-color: rgba(0, 0, 0, 100);\n"
"    selection-color: white;\n"
"    font-size: 14px;\n"
"    color: white; /* Texte blanc pour contraste */\n"
"}\n"
"\n"
"QDateEdit:hover {\n"
"    background-color: rgba(0, 0, 0, 80); /* L\303\251ger \303\251claircissement au survol */\n"
"    border: 2px solid rgba(0, 0, 0, 120);\n"
"}\n"
"\n"
"QDateEdit:focus {\n"
"    border: 2px solid rgba(0, 0, 0, 150); /* Plus intense en focus */\n"
"    background-color: rgba(0, 0, 0, 120);\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    width: 20px;\n"
"    border-left: 2px solid rgba(255, 255, 255, 50);\n"
"}\n"
"\n"
"QDateEdit::down-arrow {\n"
"    image: url(:/icons/down_arrow.png); /* Remplace par ton ic\303\264ne */\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QDateEdit::up-button, QDateEdit::down-button {\n"
"    width: 16px;\n"
"    height"
                        ": 16px;\n"
"    background-color: rgba(255, 255, 255, 50); /* Gris clair semi-transparent */\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QDateEdit::up-button:hover, QDateEdit::down-button:hover {\n"
"    background-color: rgba(255, 255, 255, 100);\n"
"}\n"
"\n"
"QDateEdit::up-arrow {\n"
"    image: url(C:/Users/FK Info/Desktop/GProjett/icon/down.png); /* Remplace par ton ic\303\264ne */\n"
"    width: 10px;\n"
"    height: 10px;\n"
"}\n"
"\n"
"QDateEdit::down-arrow {\n"
"    image: url(C:/Users/FK Info/Desktop/GProjett/icon/down1.png); /* Remplace par ton ic\303\264ne */\n"
"    width: 10px;\n"
"    height: 10px;\n"
"}\n"
""));
        dateEdit_fin = new QDateEdit(frame);
        dateEdit_fin->setObjectName("dateEdit_fin");
        dateEdit_fin->setGeometry(QRect(80, 140, 131, 31));
        dateEdit_fin->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    background-color: rgba(0, 0, 0, 100);\n"
"    border: 2px solid rgba(0, 0, 0, 100);\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"    selection-background-color: rgba(0, 0, 0, 100);\n"
"    selection-color: white;\n"
"    font-size: 14px;\n"
"    color: white; /* Texte blanc pour contraste */\n"
"}\n"
"\n"
"QDateEdit:hover {\n"
"    background-color: rgba(0, 0, 0, 80); /* L\303\251ger \303\251claircissement au survol */\n"
"    border: 2px solid rgba(0, 0, 0, 120);\n"
"}\n"
"\n"
"QDateEdit:focus {\n"
"    border: 2px solid rgba(0, 0, 0, 150); /* Plus intense en focus */\n"
"    background-color: rgba(0, 0, 0, 120);\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    width: 20px;\n"
"    border-left: 2px solid rgba(255, 255, 255, 50);\n"
"}\n"
"\n"
"QDateEdit::down-arrow {\n"
"    image: url(:/icons/down_arrow.png); /* Remplace par ton ic\303\264ne */\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QDateEdit::up-button, QDateEdit::down-button {\n"
"    width: 16px;\n"
"    height"
                        ": 16px;\n"
"    background-color: rgba(255, 255, 255, 50); /* Gris clair semi-transparent */\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QDateEdit::up-button:hover, QDateEdit::down-button:hover {\n"
"    background-color: rgba(255, 255, 255, 100);\n"
"}\n"
"\n"
"QDateEdit::up-arrow {\n"
"    image: url(C:/Users/FK Info/Desktop/GProjett/icon/down.png); /* Remplace par ton ic\303\264ne */\n"
"    width: 10px;\n"
"    height: 10px;\n"
"}\n"
"\n"
"QDateEdit::down-arrow {\n"
"    image: url(C:/Users/FK Info/Desktop/GProjett/icon/down1.png); /* Remplace par ton ic\303\264ne */\n"
"    width: 10px;\n"
"    height: 10px;\n"
"}\n"
""));
        lineEdit_nom = new QLineEdit(frame);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(100, 71, 151, 21));
        lineEdit_nom->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	 border: 2px solid rgba(0, 0, 0, 100);  /* Bordure bleue */\n"
"    border-radius: 5px;  /* Coins arrondis */\n"
"}"));
        lineEdit_budget = new QLineEdit(frame);
        lineEdit_budget->setObjectName("lineEdit_budget");
        lineEdit_budget->setGeometry(QRect(70, 180, 131, 22));
        lineEdit_budget->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	 border: 2px solid rgba(0, 0, 0, 100);  /* Bordure bleue */\n"
"    border-radius: 5px;  /* Coins arrondis */\n"
"}"));
        tableView = new QTableView(page);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 410, 661, 231));
        tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: rgba(0, 0, 0, 100);\n"
"    border: 2px solid rgba(0, 0, 0, 150);\n"
"    gridline-color: rgba(255, 255, 255, 50);\n"
"    color: white;\n"
"    selection-background-color: rgba(255, 255, 255, 50);\n"
"    selection-color: black;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: rgba(0, 0, 0, 150);\n"
"    padding: 8px;\n"
"    border: 1px solid rgba(255, 255, 255, 50);\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 8px;\n"
"    border: 1px solid rgba(255, 255, 255, 30);\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: rgba(255, 255, 255, 50);\n"
"    color: black;\n"
"}\n"
"\n"
"QTableView::item:hover {\n"
"    background-color: rgba(255, 255, 255, 30);\n"
"}\n"
""));
        btnModifier = new QPushButton(page);
        btnModifier->setObjectName("btnModifier");
        btnModifier->setGeometry(QRect(480, 340, 84, 24));
        btnModifier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}\n"
""));
        btnSupprimer = new QPushButton(page);
        btnSupprimer->setObjectName("btnSupprimer");
        btnSupprimer->setGeometry(QRect(390, 340, 84, 24));
        btnSupprimer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}\n"
""));
        btnDesc = new QPushButton(page);
        btnDesc->setObjectName("btnDesc");
        btnDesc->setGeometry(QRect(530, 380, 84, 24));
        btnDesc->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}\n"
""));
        btnAsc = new QPushButton(page);
        btnAsc->setObjectName("btnAsc");
        btnAsc->setGeometry(QRect(430, 380, 84, 24));
        btnAsc->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}\n"
""));
        btnExporterPDF = new QPushButton(page);
        btnExporterPDF->setObjectName("btnExporterPDF");
        btnExporterPDF->setGeometry(QRect(570, 340, 101, 24));
        btnExporterPDF->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}\n"
""));
        btnShowStats = new QPushButton(page);
        btnShowStats->setObjectName("btnShowStats");
        btnShowStats->setGeometry(QRect(830, 580, 241, 24));
        btnShowStats->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        gridLayoutWidget = new QWidget(page);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(680, 70, 491, 331));
        financeLayout = new QGridLayout(gridLayoutWidget);
        financeLayout->setObjectName("financeLayout");
        financeLayout->setContentsMargins(0, 0, 0, 0);
        lblTotalBudget = new QLabel(page);
        lblTotalBudget->setObjectName("lblTotalBudget");
        lblTotalBudget->setGeometry(QRect(710, 430, 141, 20));
        lblTotalActual = new QLabel(page);
        lblTotalActual->setObjectName("lblTotalActual");
        lblTotalActual->setGeometry(QRect(890, 430, 141, 20));
        lblTotalEstimated = new QLabel(page);
        lblTotalEstimated->setObjectName("lblTotalEstimated");
        lblTotalEstimated->setGeometry(QRect(710, 470, 141, 20));
        lblDeviation = new QLabel(page);
        lblDeviation->setObjectName("lblDeviation");
        lblDeviation->setGeometry(QRect(890, 470, 191, 20));
        btnRefreshFinance = new QPushButton(page);
        btnRefreshFinance->setObjectName("btnRefreshFinance");
        btnRefreshFinance->setGeometry(QRect(830, 510, 91, 24));
        btnRefreshFinance->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        btnArduino = new QPushButton(page);
        btnArduino->setObjectName("btnArduino");
        btnArduino->setGeometry(QRect(690, 540, 131, 24));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        textBrowser_3 = new QTextBrowser(page_2);
        textBrowser_3->setObjectName("textBrowser_3");
        textBrowser_3->setGeometry(QRect(120, 0, 511, 41));
        textBrowser_3->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        stackedWidget->addWidget(page_2);
        widget = new QWidget(centralwidget);
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

        GProjett->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GProjett);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1375, 22));
        GProjett->setMenuBar(menubar);
        statusbar = new QStatusBar(GProjett);
        statusbar->setObjectName("statusbar");
        GProjett->setStatusBar(statusbar);

        retranslateUi(GProjett);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GProjett);
    } // setupUi

    void retranslateUi(QMainWindow *GProjett)
    {
        GProjett->setWindowTitle(QCoreApplication::translate("GProjett", "MainWindow", nullptr));
        logo_label_2->setText(QString());
        logo_label_3->setText(QCoreApplication::translate("GProjett", "Architexia", nullptr));
        home_btn_2->setText(QCoreApplication::translate("GProjett", "Home", nullptr));
        dashborad_btn_2->setText(QCoreApplication::translate("GProjett", "Gestion d'employee", nullptr));
        orders_btn_2->setText(QCoreApplication::translate("GProjett", "Gestion des equipements", nullptr));
        products_btn_2->setText(QCoreApplication::translate("GProjett", "Gestion de projet", nullptr));
        customers_btn_2->setText(QCoreApplication::translate("GProjett", "Gestion de client", nullptr));
        customers_btn_3->setText(QCoreApplication::translate("GProjett", "Gestion de fournisseur", nullptr));
        home_btn_3->setText(QCoreApplication::translate("GProjett", "Gestion d'architecture", nullptr));
        exit_btn_2->setText(QCoreApplication::translate("GProjett", "Exit", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("GProjett", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:18pt; font-weight:600; font-style:italic; text-decoration: underline;\">Gestion de projet</span></p></body></html>", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("GProjett", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:10pt; font-weight:600; font-style:italic;\">Notification</span></p></body></html>", nullptr));
        label_65->setText(QCoreApplication::translate("GProjett", "E-Mail :", nullptr));
        btnEnvoyerEmail->setText(QCoreApplication::translate("GProjett", "Envoyer", nullptr));
        label->setText(QCoreApplication::translate("GProjett", "Nom du projet :", nullptr));
        label_2->setText(QCoreApplication::translate("GProjett", "Date Fin :", nullptr));
        label_5->setText(QCoreApplication::translate("GProjett", "Date Debut :", nullptr));
        label_3->setText(QCoreApplication::translate("GProjett", "Budget:", nullptr));
        label_4->setText(QCoreApplication::translate("GProjett", "Status:", nullptr));
        btnAnnuler->setText(QCoreApplication::translate("GProjett", "Annuler", nullptr));
        btnAjouter->setText(QCoreApplication::translate("GProjett", "Ajouter", nullptr));
        textBrowser_4->setHtml(QCoreApplication::translate("GProjett", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">Ajouter un projet</span></p></body></html>", nullptr));
        lineEdit_client->setPlaceholderText(QCoreApplication::translate("GProjett", "L'id de client", nullptr));
        label_37->setText(QCoreApplication::translate("GProjett", "id client:", nullptr));
        comboBox_status->setItemText(0, QCoreApplication::translate("GProjett", "oui", nullptr));
        comboBox_status->setItemText(1, QCoreApplication::translate("GProjett", "non", nullptr));
        comboBox_status->setItemText(2, QCoreApplication::translate("GProjett", "pas encore", nullptr));

        lineEdit_nom->setText(QString());
        lineEdit_nom->setPlaceholderText(QCoreApplication::translate("GProjett", "Nom du projet", nullptr));
        lineEdit_budget->setPlaceholderText(QCoreApplication::translate("GProjett", "Budget de projet", nullptr));
        btnModifier->setText(QCoreApplication::translate("GProjett", "Modifier", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("GProjett", "Supprimer", nullptr));
        btnDesc->setText(QCoreApplication::translate("GProjett", "DESC", nullptr));
        btnAsc->setText(QCoreApplication::translate("GProjett", "ASC", nullptr));
        btnExporterPDF->setText(QCoreApplication::translate("GProjett", "Exportation PDF", nullptr));
        btnShowStats->setText(QCoreApplication::translate("GProjett", "Statistique", nullptr));
        lblTotalBudget->setText(QCoreApplication::translate("GProjett", "Total budget", nullptr));
        lblTotalActual->setText(QCoreApplication::translate("GProjett", "Total actual", nullptr));
        lblTotalEstimated->setText(QCoreApplication::translate("GProjett", "Total estimation", nullptr));
        lblDeviation->setText(QCoreApplication::translate("GProjett", "Deviation", nullptr));
        btnRefreshFinance->setText(QCoreApplication::translate("GProjett", "Finance", nullptr));
        btnArduino->setText(QCoreApplication::translate("GProjett", " Ouvrir Contr\303\264le RFID", nullptr));
        textBrowser_3->setHtml(QCoreApplication::translate("GProjett", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:696; font-style:italic;\">Home</span></p></body></html>", nullptr));
        change_btn->setText(QString());
        searchBar->setPlaceholderText(QCoreApplication::translate("GProjett", "Search...", nullptr));
        btnRechercher->setText(QString());
        user_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GProjett: public Ui_GProjett {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GPROJETT_H
