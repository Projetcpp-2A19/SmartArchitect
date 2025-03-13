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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
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
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *change_btn;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLineEdit *searchBar;
    QPushButton *btnRechercher;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *user_btn;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QTextBrowser *textBrowser;
    QWidget *widget_6;
    QFrame *frame;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_9;
    QPushButton *btnAjouterFournisseur;
    QTextBrowser *textBrowser_4;
    QLineEdit *lineEdit_client;
    QLabel *label_37;
    QLineEdit *lineEdit_nomFournisseur;
    QLineEdit *lineEdit_budget;
    QLineEdit *lineEdit_telephoneFournisseur;
    QLineEdit *lineEdit_adresseFournisseur;
    QLineEdit *lineEdit_villeFournisseur;
    QLineEdit *lineEdit_etatFournisseur;
    QLineEdit *lineEdit_commandeFournisseur;
    QLabel *label_38;
    QLineEdit *lineEdit_emailFournisseur;
    QTableView *tableViewFournisseurs;
    QPushButton *btnModifierFournisseur;
    QPushButton *btnSupprimerFournisseur;
    QWidget *page_2;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_5;
    QFrame *card1;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_9;
    QLabel *label_6;
    QFrame *card2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_7;
    QLabel *label_10;
    QFrame *card3;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_8;
    QLabel *label_11;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_6;
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
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_7;
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
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1374, 744);
        centralwidget = new QWidget(MainWindow);
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
        icon.addFile(QString::fromUtf8("../../Bureau/GProjett/icon/home-4-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        home_btn_2->setIcon(icon);
        home_btn_2->setIconSize(QSize(14, 14));
        home_btn_2->setCheckable(true);
        home_btn_2->setAutoExclusive(true);

        verticalLayout_2->addWidget(home_btn_2);

        dashborad_btn_2 = new QPushButton(full_menu_widget);
        dashborad_btn_2->setObjectName("dashborad_btn_2");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../Bureau/GProjett/icon/group-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
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
        icon3.addFile(QString::fromUtf8("../../Bureau/GProjett/icon/menu-4-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
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
        icon4.addFile(QString::fromUtf8("../../Bureau/GProjett/icon/search-13-48.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnRechercher->setIcon(icon4);

        horizontalLayout->addWidget(btnRechercher);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(236, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        user_btn = new QPushButton(widget);
        user_btn->setObjectName("user_btn");
        user_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../../Bureau/GProjett/icon/user-48.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        user_btn->setIcon(icon5);

        horizontalLayout_4->addWidget(user_btn);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(180, 40, 1191, 761));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        page = new QWidget();
        page->setObjectName("page");
        textBrowser = new QTextBrowser(page);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(30, 10, 1141, 51));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        widget_6 = new QWidget(page);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(-1, 70, 1171, 291));
        widget_6->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        frame = new QFrame(widget_6);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 10, 1151, 271));
        frame->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        frame->setFrameShape(QFrame::Shape::NoFrame);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 70, 111, 21));
        QFont font1;
        font1.setBold(true);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"rgb(0, 0, 0)\n"
"}"));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 140, 81, 31));
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 110, 81, 21));
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(300, 70, 49, 21));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(310, 130, 49, 21));
        pushButton_9 = new QPushButton(frame);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(940, 210, 75, 23));
        pushButton_9->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        btnAjouterFournisseur = new QPushButton(frame);
        btnAjouterFournisseur->setObjectName("btnAjouterFournisseur");
        btnAjouterFournisseur->setGeometry(QRect(940, 180, 75, 23));
        btnAjouterFournisseur->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
""));
        textBrowser_4 = new QTextBrowser(frame);
        textBrowser_4->setObjectName("textBrowser_4");
        textBrowser_4->setGeometry(QRect(0, 0, 1151, 51));
        textBrowser_4->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        lineEdit_client = new QLineEdit(frame);
        lineEdit_client->setObjectName("lineEdit_client");
        lineEdit_client->setGeometry(QRect(80, 230, 151, 22));
        label_37 = new QLabel(frame);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(580, 70, 91, 21));
        lineEdit_nomFournisseur = new QLineEdit(frame);
        lineEdit_nomFournisseur->setObjectName("lineEdit_nomFournisseur");
        lineEdit_nomFournisseur->setGeometry(QRect(120, 60, 151, 31));
        lineEdit_nomFournisseur->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	 border: 2px solid rgba(0, 0, 0, 100);  /* Bordure bleue */\n"
"    border-radius: 5px;  /* Coins arrondis */\n"
"}"));
        lineEdit_budget = new QLineEdit(frame);
        lineEdit_budget->setObjectName("lineEdit_budget");
        lineEdit_budget->setGeometry(QRect(80, 160, 131, 22));
        lineEdit_telephoneFournisseur = new QLineEdit(frame);
        lineEdit_telephoneFournisseur->setObjectName("lineEdit_telephoneFournisseur");
        lineEdit_telephoneFournisseur->setGeometry(QRect(120, 100, 151, 31));
        lineEdit_telephoneFournisseur->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	 border: 2px solid rgba(0, 0, 0, 100);  /* Bordure bleue */\n"
"    border-radius: 5px;  /* Coins arrondis */\n"
"}"));
        lineEdit_adresseFournisseur = new QLineEdit(frame);
        lineEdit_adresseFournisseur->setObjectName("lineEdit_adresseFournisseur");
        lineEdit_adresseFournisseur->setGeometry(QRect(120, 140, 151, 31));
        lineEdit_adresseFournisseur->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	 border: 2px solid rgba(0, 0, 0, 100);  /* Bordure bleue */\n"
"    border-radius: 5px;  /* Coins arrondis */\n"
"}"));
        lineEdit_villeFournisseur = new QLineEdit(frame);
        lineEdit_villeFournisseur->setObjectName("lineEdit_villeFournisseur");
        lineEdit_villeFournisseur->setGeometry(QRect(360, 60, 151, 31));
        lineEdit_villeFournisseur->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	 border: 2px solid rgba(0, 0, 0, 100);  /* Bordure bleue */\n"
"    border-radius: 5px;  /* Coins arrondis */\n"
"}"));
        lineEdit_etatFournisseur = new QLineEdit(frame);
        lineEdit_etatFournisseur->setObjectName("lineEdit_etatFournisseur");
        lineEdit_etatFournisseur->setGeometry(QRect(360, 120, 151, 31));
        lineEdit_etatFournisseur->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	 border: 2px solid rgba(0, 0, 0, 100);  /* Bordure bleue */\n"
"    border-radius: 5px;  /* Coins arrondis */\n"
"}"));
        lineEdit_commandeFournisseur = new QLineEdit(frame);
        lineEdit_commandeFournisseur->setObjectName("lineEdit_commandeFournisseur");
        lineEdit_commandeFournisseur->setGeometry(QRect(680, 60, 151, 31));
        lineEdit_commandeFournisseur->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	 border: 2px solid rgba(0, 0, 0, 100);  /* Bordure bleue */\n"
"    border-radius: 5px;  /* Coins arrondis */\n"
"}"));
        label_38 = new QLabel(frame);
        label_38->setObjectName("label_38");
        label_38->setGeometry(QRect(590, 130, 61, 21));
        lineEdit_emailFournisseur = new QLineEdit(frame);
        lineEdit_emailFournisseur->setObjectName("lineEdit_emailFournisseur");
        lineEdit_emailFournisseur->setGeometry(QRect(670, 120, 151, 31));
        lineEdit_emailFournisseur->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	 border: 2px solid rgba(0, 0, 0, 100);  /* Bordure bleue */\n"
"    border-radius: 5px;  /* Coins arrondis */\n"
"}"));
        tableViewFournisseurs = new QTableView(page);
        tableViewFournisseurs->setObjectName("tableViewFournisseurs");
        tableViewFournisseurs->setGeometry(QRect(20, 410, 731, 221));
        tableViewFournisseurs->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: #f0f0f0;  /* Couleur de fond de la table */\n"
"    alternate-background-color: #e0e0e0;  /* Couleur de fond des lignes altern\303\251es */\n"
"    gridline-color: #c0c0c0;  /* Couleur des lignes de la grille */\n"
"    border: 1px solid #a0a0a0;  /* Bordure de la table */\n"
"    border-radius: 5px;  /* Coins arrondis */\n"
"    font-family: \"Arial\";  /* Police de caract\303\250res */\n"
"    font-size: 12px;  /* Taille de la police */\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 5px;  /* Espacement interne des cellules */\n"
"    color: #333333;  /* Couleur du texte */\n"
"    background-color: #ffffff;  /* Couleur de fond des cellules */\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color:rgba(0, 0, 0, 100);  /* Couleur de fond des cellules s\303\251lectionn\303\251es */\n"
"    color: #ffffff;  /* Couleur du texte des cellules s\303\251lectionn\303\251es */\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color:rgba(0, 0, 0, 100);  /* C"
                        "ouleur de fond des en-t\303\252tes de colonnes */\n"
"    color: #ffffff;  /* Couleur du texte des en-t\303\252tes de colonnes */\n"
"    padding: 5px;  /* Espacement interne des en-t\303\252tes */\n"
"    border: 1px solid #005bb5;  /* Bordure des en-t\303\252tes */\n"
"    font-weight: bold;  /* Texte en gras */\n"
"}\n"
"\n"
"QHeaderView::section:checked {\n"
"   background-color:rgba(0, 0, 0, 100);  /* Couleur de fond des en-t\303\252tes s\303\251lectionn\303\251s */\n"
"}\n"
"\n"
"QTableView QTableCornerButton::section {\n"
"   background-color:rgba(0, 0, 0, 100);  /* Couleur de fond du coin de la table */\n"
"    border: 1px solid #005bb5;  /* Bordure du coin de la table */\n"
"}"));
        btnModifierFournisseur = new QPushButton(page);
        btnModifierFournisseur->setObjectName("btnModifierFournisseur");
        btnModifierFournisseur->setGeometry(QRect(570, 380, 84, 24));
        btnModifierFournisseur->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        btnSupprimerFournisseur = new QPushButton(page);
        btnSupprimerFournisseur->setObjectName("btnSupprimerFournisseur");
        btnSupprimerFournisseur->setGeometry(QRect(470, 380, 84, 24));
        btnSupprimerFournisseur->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        verticalLayout_5 = new QVBoxLayout(card1);
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_9 = new QLabel(card1);
        label_9->setObjectName("label_9");
        QFont font2;
        font2.setPointSize(14);
        font2.setUnderline(true);
        label_9->setFont(font2);

        verticalLayout_5->addWidget(label_9);

        label_6 = new QLabel(card1);
        label_6->setObjectName("label_6");
        QFont font3;
        font3.setPointSize(12);
        label_6->setFont(font3);

        verticalLayout_5->addWidget(label_6);


        horizontalLayout_5->addWidget(card1);

        card2 = new QFrame(frame_3);
        card2->setObjectName("card2");
        card2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        card2->setFrameShape(QFrame::Shape::NoFrame);
        verticalLayout_6 = new QVBoxLayout(card2);
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_7 = new QLabel(card2);
        label_7->setObjectName("label_7");
        label_7->setFont(font2);
        label_7->setAcceptDrops(false);

        verticalLayout_6->addWidget(label_7);

        label_10 = new QLabel(card2);
        label_10->setObjectName("label_10");
        label_10->setFont(font3);

        verticalLayout_6->addWidget(label_10);


        horizontalLayout_5->addWidget(card2);

        card3 = new QFrame(frame_3);
        card3->setObjectName("card3");
        card3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        card3->setFrameShape(QFrame::Shape::NoFrame);
        verticalLayout_7 = new QVBoxLayout(card3);
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_8 = new QLabel(card3);
        label_8->setObjectName("label_8");
        label_8->setFont(font2);

        verticalLayout_7->addWidget(label_8);

        label_11 = new QLabel(card3);
        label_11->setObjectName("label_11");
        label_11->setFont(font3);

        verticalLayout_7->addWidget(label_11);


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
        horizontalLayout_3 = new QHBoxLayout(frame_4);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        widget_2 = new QWidget(frame_4);
        widget_2->setObjectName("widget_2");
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName("verticalLayout");
        frame_5 = new QFrame(widget_2);
        frame_5->setObjectName("frame_5");
        frame_5->setStyleSheet(QString::fromUtf8(""));
        frame_5->setFrameShape(QFrame::Shape::NoFrame);
        horizontalLayout_6 = new QHBoxLayout(frame_5);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_12 = new QLabel(frame_5);
        label_12->setObjectName("label_12");
        QFont font4;
        font4.setPointSize(20);
        font4.setBold(true);
        label_12->setFont(font4);

        horizontalLayout_6->addWidget(label_12);

        label_13 = new QLabel(frame_5);
        label_13->setObjectName("label_13");

        horizontalLayout_6->addWidget(label_13);


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
        QFont font5;
        font5.setPointSize(13);
        font5.setBold(true);
        label_15->setFont(font5);

        gridLayout->addWidget(label_15, 0, 1, 1, 1);

        label_18 = new QLabel(frame_6);
        label_18->setObjectName("label_18");

        gridLayout->addWidget(label_18, 2, 1, 1, 1);

        label_24 = new QLabel(frame_6);
        label_24->setObjectName("label_24");

        gridLayout->addWidget(label_24, 4, 1, 1, 1);

        label_14 = new QLabel(frame_6);
        label_14->setObjectName("label_14");
        label_14->setFont(font5);

        gridLayout->addWidget(label_14, 0, 0, 1, 1);

        label_16 = new QLabel(frame_6);
        label_16->setObjectName("label_16");
        label_16->setFont(font5);

        gridLayout->addWidget(label_16, 0, 2, 1, 1);

        label_21 = new QLabel(frame_6);
        label_21->setObjectName("label_21");

        gridLayout->addWidget(label_21, 3, 1, 1, 1);


        verticalLayout->addWidget(frame_6);


        horizontalLayout_3->addWidget(widget_2);

        widget_3 = new QWidget(frame_4);
        widget_3->setObjectName("widget_3");
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        frame_7 = new QFrame(widget_3);
        frame_7->setObjectName("frame_7");
        frame_7->setStyleSheet(QString::fromUtf8(""));
        frame_7->setFrameShape(QFrame::Shape::NoFrame);
        horizontalLayout_7 = new QHBoxLayout(frame_7);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_29 = new QLabel(frame_7);
        label_29->setObjectName("label_29");
        label_29->setFont(font4);

        horizontalLayout_7->addWidget(label_29);

        pushButton = new QPushButton(frame_7);
        pushButton->setObjectName("pushButton");

        horizontalLayout_7->addWidget(pushButton);


        verticalLayout_3->addWidget(frame_7);

        label_31 = new QLabel(widget_3);
        label_31->setObjectName("label_31");

        verticalLayout_3->addWidget(label_31);

        label_30 = new QLabel(widget_3);
        label_30->setObjectName("label_30");

        verticalLayout_3->addWidget(label_30);

        label_32 = new QLabel(widget_3);
        label_32->setObjectName("label_32");

        verticalLayout_3->addWidget(label_32);

        label_33 = new QLabel(widget_3);
        label_33->setObjectName("label_33");

        verticalLayout_3->addWidget(label_33);

        label_34 = new QLabel(widget_3);
        label_34->setObjectName("label_34");

        verticalLayout_3->addWidget(label_34);

        label_35 = new QLabel(widget_3);
        label_35->setObjectName("label_35");

        verticalLayout_3->addWidget(label_35);

        label_36 = new QLabel(widget_3);
        label_36->setObjectName("label_36");

        verticalLayout_3->addWidget(label_36);

        verticalSpacer_4 = new QSpacerItem(20, 373, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);


        horizontalLayout_3->addWidget(widget_3);

        textBrowser_3 = new QTextBrowser(page_2);
        textBrowser_3->setObjectName("textBrowser_3");
        textBrowser_3->setGeometry(QRect(120, 0, 511, 41));
        textBrowser_3->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1374, 25));
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
        logo_label_2->setText(QString());
        logo_label_3->setText(QCoreApplication::translate("MainWindow", "Architexia", nullptr));
        home_btn_2->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        dashborad_btn_2->setText(QCoreApplication::translate("MainWindow", "Gestion d'employee", nullptr));
        orders_btn_2->setText(QCoreApplication::translate("MainWindow", "Gestion des equipements", nullptr));
        products_btn_2->setText(QCoreApplication::translate("MainWindow", "Gestion de projet", nullptr));
        customers_btn_2->setText(QCoreApplication::translate("MainWindow", "Gestion de client", nullptr));
        customers_btn_3->setText(QCoreApplication::translate("MainWindow", "Gestion de fournisseur", nullptr));
        home_btn_3->setText(QCoreApplication::translate("MainWindow", "Gestion d'architecture", nullptr));
        exit_btn_2->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        change_btn->setText(QString());
        searchBar->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search...", nullptr));
        btnRechercher->setText(QString());
        user_btn->setText(QString());
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:18pt; font-weight:600; font-style:italic; text-decoration: underline;\">Gestion de fourniseur</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ff0000;\">Nom du fourniseur :</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#ff1100;\">Adresse:</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#ff0000;\">Telephone:</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#ff0000;\">Ville:</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#ff0000;\">Etat:</span></p></body></html>", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        btnAjouterFournisseur->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        textBrowser_4->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">Ajouter un fourniseur</span></p></body></html>", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#ff0000;\">Commande:</span></p></body></html>", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#ff0000;\">Email:</span></p></body></html>", nullptr));
        btnModifierFournisseur->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        btnSupprimerFournisseur->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
