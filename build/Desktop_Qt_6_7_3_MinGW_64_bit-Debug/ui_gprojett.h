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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GProjett
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QTextBrowser *textBrowser;
    QWidget *widget_5;
    QTextBrowser *textBrowser_2;
    QLabel *label_65;
    QLineEdit *lineEditEmail;
    QTextEdit *textEdit;
    QPushButton *btnEnvoyerEmail;
    QPushButton *pushButton_12;
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
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_9;
    QFrame *frame_10;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_42;
    QLabel *label_45;
    QFrame *frame_11;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_15;
    QLabel *label_77;
    QPushButton *pushButton_13;
    QPushButton *pushButton_8;
    QLabel *label_73;
    QLabel *label_83;
    QPushButton *pushButton_16;
    QPushButton *pushButton_14;
    QLabel *label_79;
    QPushButton *pushButton_17;
    QLabel *label_59;
    QLabel *label_68;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_80;
    QLabel *label_78;
    QLabel *label_70;
    QLabel *label_69;
    QLabel *label_71;
    QTableView *tableView;
    QPushButton *btnModifier;
    QPushButton *btnSupprimer;
    QPushButton *btnDesc;
    QPushButton *btnAsc;
    QPushButton *btnExporterPDF;
    QPushButton *btnShowStats;
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

    void setupUi(QMainWindow *GProjett)
    {
        if (GProjett->objectName().isEmpty())
            GProjett->setObjectName("GProjett");
        GProjett->resize(1384, 701);
        GProjett->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(GProjett);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	 border: 2px solid rgba(0, 0, 0, 100);  /* Bordure bleue */\n"
"    border-radius: 5px;  /* Coins arrondis */\n"
"}"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(180, 50, 1211, 861));
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
        widget_5->setGeometry(QRect(350, 70, 401, 261));
        textBrowser_2 = new QTextBrowser(widget_5);
        textBrowser_2->setObjectName("textBrowser_2");
        textBrowser_2->setGeometry(QRect(0, 0, 401, 51));
        textBrowser_2->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        label_65 = new QLabel(widget_5);
        label_65->setObjectName("label_65");
        label_65->setGeometry(QRect(10, 60, 161, 61));
        lineEditEmail = new QLineEdit(widget_5);
        lineEditEmail->setObjectName("lineEditEmail");
        lineEditEmail->setGeometry(QRect(172, 80, 211, 20));
        textEdit = new QTextEdit(widget_5);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 120, 371, 61));
        btnEnvoyerEmail = new QPushButton(widget_5);
        btnEnvoyerEmail->setObjectName("btnEnvoyerEmail");
        btnEnvoyerEmail->setGeometry(QRect(310, 190, 84, 23));
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
        pushButton_12 = new QPushButton(widget_5);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(220, 190, 84, 23));
        pushButton_12->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        widget_7 = new QWidget(page);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(760, 70, 421, 331));
        widget_7->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        verticalLayout_9 = new QVBoxLayout(widget_7);
        verticalLayout_9->setObjectName("verticalLayout_9");
        frame_10 = new QFrame(widget_7);
        frame_10->setObjectName("frame_10");
        frame_10->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        frame_10->setFrameShape(QFrame::Shape::NoFrame);
        horizontalLayout_9 = new QHBoxLayout(frame_10);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_42 = new QLabel(frame_10);
        label_42->setObjectName("label_42");
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label_42->setFont(font);

        horizontalLayout_9->addWidget(label_42);

        label_45 = new QLabel(frame_10);
        label_45->setObjectName("label_45");

        horizontalLayout_9->addWidget(label_45);


        verticalLayout_9->addWidget(frame_10);

        frame_11 = new QFrame(widget_7);
        frame_11->setObjectName("frame_11");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_11->sizePolicy().hasHeightForWidth());
        frame_11->setSizePolicy(sizePolicy);
        frame_11->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        frame_11->setFrameShape(QFrame::Shape::NoFrame);
        gridLayout_3 = new QGridLayout(frame_11);
        gridLayout_3->setObjectName("gridLayout_3");
        pushButton_15 = new QPushButton(frame_11);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));

        gridLayout_3->addWidget(pushButton_15, 4, 2, 1, 1);

        label_77 = new QLabel(frame_11);
        label_77->setObjectName("label_77");

        gridLayout_3->addWidget(label_77, 3, 1, 1, 1);

        pushButton_13 = new QPushButton(frame_11);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
""));

        gridLayout_3->addWidget(pushButton_13, 4, 3, 1, 1);

        pushButton_8 = new QPushButton(frame_11);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));

        gridLayout_3->addWidget(pushButton_8, 3, 2, 1, 1);

        label_73 = new QLabel(frame_11);
        label_73->setObjectName("label_73");

        gridLayout_3->addWidget(label_73, 2, 1, 1, 1);

        label_83 = new QLabel(frame_11);
        label_83->setObjectName("label_83");
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        label_83->setFont(font1);

        gridLayout_3->addWidget(label_83, 0, 2, 1, 1);

        pushButton_16 = new QPushButton(frame_11);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
""));

        gridLayout_3->addWidget(pushButton_16, 2, 3, 1, 1);

        pushButton_14 = new QPushButton(frame_11);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
""));

        gridLayout_3->addWidget(pushButton_14, 3, 3, 1, 1);

        label_79 = new QLabel(frame_11);
        label_79->setObjectName("label_79");

        gridLayout_3->addWidget(label_79, 4, 1, 1, 1);

        pushButton_17 = new QPushButton(frame_11);
        pushButton_17->setObjectName("pushButton_17");
        pushButton_17->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));

        gridLayout_3->addWidget(pushButton_17, 2, 2, 1, 1);

        label_59 = new QLabel(frame_11);
        label_59->setObjectName("label_59");
        label_59->setFont(font1);

        gridLayout_3->addWidget(label_59, 0, 1, 1, 1);

        label_68 = new QLabel(frame_11);
        label_68->setObjectName("label_68");

        gridLayout_3->addWidget(label_68, 4, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 373, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_6, 6, 1, 1, 1);

        label_80 = new QLabel(frame_11);
        label_80->setObjectName("label_80");

        gridLayout_3->addWidget(label_80, 3, 0, 1, 1);

        label_78 = new QLabel(frame_11);
        label_78->setObjectName("label_78");

        gridLayout_3->addWidget(label_78, 2, 0, 1, 1);

        label_70 = new QLabel(frame_11);
        label_70->setObjectName("label_70");
        label_70->setFont(font1);

        gridLayout_3->addWidget(label_70, 0, 0, 1, 1);


        verticalLayout_9->addWidget(frame_11);

        label_69 = new QLabel(widget_7);
        label_69->setObjectName("label_69");
        QFont font2;
        font2.setPointSize(11);
        label_69->setFont(font2);
        label_69->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));

        verticalLayout_9->addWidget(label_69);

        label_71 = new QLabel(widget_7);
        label_71->setObjectName("label_71");
        label_71->setFont(font2);
        label_71->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));

        verticalLayout_9->addWidget(label_71);

        tableView = new QTableView(page);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 410, 751, 231));
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
        btnShowStats->setGeometry(QRect(870, 490, 241, 24));
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
        QFont font3;
        font3.setPointSize(14);
        font3.setUnderline(true);
        label_9->setFont(font3);

        verticalLayout_5->addWidget(label_9);

        label_6 = new QLabel(card1);
        label_6->setObjectName("label_6");
        QFont font4;
        font4.setPointSize(12);
        label_6->setFont(font4);

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
        label_7->setFont(font3);
        label_7->setAcceptDrops(false);

        verticalLayout_6->addWidget(label_7);

        label_10 = new QLabel(card2);
        label_10->setObjectName("label_10");
        label_10->setFont(font4);

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
        label_8->setFont(font3);

        verticalLayout_7->addWidget(label_8);

        label_11 = new QLabel(card3);
        label_11->setObjectName("label_11");
        label_11->setFont(font4);

        verticalLayout_7->addWidget(label_11);


        horizontalLayout_5->addWidget(card3);

        frame_4 = new QFrame(page_2);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(10, 160, 741, 371));
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
        label_12->setFont(font);

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
        label_15->setFont(font1);

        gridLayout->addWidget(label_15, 0, 1, 1, 1);

        label_18 = new QLabel(frame_6);
        label_18->setObjectName("label_18");

        gridLayout->addWidget(label_18, 2, 1, 1, 1);

        label_24 = new QLabel(frame_6);
        label_24->setObjectName("label_24");

        gridLayout->addWidget(label_24, 4, 1, 1, 1);

        label_14 = new QLabel(frame_6);
        label_14->setObjectName("label_14");
        label_14->setFont(font1);

        gridLayout->addWidget(label_14, 0, 0, 1, 1);

        label_16 = new QLabel(frame_6);
        label_16->setObjectName("label_16");
        label_16->setFont(font1);

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
        label_29->setFont(font);

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
        QFont font5;
        font5.setPointSize(15);
        logo_label_3->setFont(font5);

        horizontalLayout_2->addWidget(logo_label_3);


        verticalLayout_4->addLayout(horizontalLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        home_btn_2 = new QPushButton(full_menu_widget);
        home_btn_2->setObjectName("home_btn_2");
        QIcon icon;
        icon.addFile(QString::fromUtf8("icon/home-4-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        home_btn_2->setIcon(icon);
        home_btn_2->setIconSize(QSize(14, 14));
        home_btn_2->setCheckable(true);
        home_btn_2->setAutoExclusive(true);

        verticalLayout_2->addWidget(home_btn_2);

        dashborad_btn_2 = new QPushButton(full_menu_widget);
        dashborad_btn_2->setObjectName("dashborad_btn_2");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("icon/group-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
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
        widget->setGeometry(QRect(180, 9, 1191, 41));
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
        icon3.addFile(QString::fromUtf8("icon/menu-4-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
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
        icon4.addFile(QString::fromUtf8("icon/search-13-48.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnRechercher->setIcon(icon4);

        horizontalLayout->addWidget(btnRechercher);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(236, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        user_btn = new QPushButton(widget);
        user_btn->setObjectName("user_btn");
        user_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("icon/user-48.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        user_btn->setIcon(icon5);

        horizontalLayout_4->addWidget(user_btn);

        GProjett->setCentralWidget(centralwidget);

        retranslateUi(GProjett);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GProjett);
    } // setupUi

    void retranslateUi(QMainWindow *GProjett)
    {
        GProjett->setWindowTitle(QCoreApplication::translate("GProjett", "GProjett", nullptr));
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
        label_65->setText(QCoreApplication::translate("GProjett", "Mail ou numero de telephone:", nullptr));
        btnEnvoyerEmail->setText(QCoreApplication::translate("GProjett", "Envoyer", nullptr));
        pushButton_12->setText(QCoreApplication::translate("GProjett", "Annuler", nullptr));
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
        label_42->setText(QCoreApplication::translate("GProjett", "Budget", nullptr));
        label_45->setText(QCoreApplication::translate("GProjett", "voir plus", nullptr));
        pushButton_15->setText(QCoreApplication::translate("GProjett", "Update", nullptr));
        label_77->setText(QCoreApplication::translate("GProjett", "150.000", nullptr));
        pushButton_13->setText(QCoreApplication::translate("GProjett", "Supprimer", nullptr));
        pushButton_8->setText(QCoreApplication::translate("GProjett", "Update", nullptr));
        label_73->setText(QCoreApplication::translate("GProjett", "100.000", nullptr));
        label_83->setText(QCoreApplication::translate("GProjett", "Action", nullptr));
        pushButton_16->setText(QCoreApplication::translate("GProjett", "Supprimer", nullptr));
        pushButton_14->setText(QCoreApplication::translate("GProjett", "Supprimer", nullptr));
        label_79->setText(QCoreApplication::translate("GProjett", "400.000", nullptr));
        pushButton_17->setText(QCoreApplication::translate("GProjett", "Update", nullptr));
        label_59->setText(QCoreApplication::translate("GProjett", "d\303\251penses ", nullptr));
        label_68->setText(QCoreApplication::translate("GProjett", "600.500", nullptr));
        label_80->setText(QCoreApplication::translate("GProjett", "200.000", nullptr));
        label_78->setText(QCoreApplication::translate("GProjett", "187.000", nullptr));
        label_70->setText(QCoreApplication::translate("GProjett", "Budget de projet", nullptr));
        label_69->setText(QCoreApplication::translate("GProjett", "Total Budget:100.000.000", nullptr));
        label_71->setText(QCoreApplication::translate("GProjett", "Total de deponses:100.000.000", nullptr));
        btnModifier->setText(QCoreApplication::translate("GProjett", "Modifier", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("GProjett", "Supprimer", nullptr));
        btnDesc->setText(QCoreApplication::translate("GProjett", "DESC", nullptr));
        btnAsc->setText(QCoreApplication::translate("GProjett", "ASC", nullptr));
        btnExporterPDF->setText(QCoreApplication::translate("GProjett", "Exportation PDF", nullptr));
        btnShowStats->setText(QCoreApplication::translate("GProjett", "Statistique", nullptr));
        label_9->setText(QCoreApplication::translate("GProjett", "Nombre de projet:", nullptr));
        label_6->setText(QCoreApplication::translate("GProjett", "200", nullptr));
        label_7->setText(QCoreApplication::translate("GProjett", "Nombre d'employee", nullptr));
        label_10->setText(QCoreApplication::translate("GProjett", "200", nullptr));
        label_8->setText(QCoreApplication::translate("GProjett", "Nombre de Fournisseur", nullptr));
        label_11->setText(QCoreApplication::translate("GProjett", "200", nullptr));
        label_12->setText(QCoreApplication::translate("GProjett", "Listes", nullptr));
        label_13->setText(QCoreApplication::translate("GProjett", "voir plus", nullptr));
        label_20->setText(QCoreApplication::translate("GProjett", "TextLabel", nullptr));
        label_23->setText(QCoreApplication::translate("GProjett", "TextLabel", nullptr));
        label_17->setText(QCoreApplication::translate("GProjett", "TextLabel", nullptr));
        label_27->setText(QCoreApplication::translate("GProjett", "TextLabel", nullptr));
        label_19->setText(QCoreApplication::translate("GProjett", "TextLabel", nullptr));
        label_22->setText(QCoreApplication::translate("GProjett", "TextLabel", nullptr));
        label_26->setText(QCoreApplication::translate("GProjett", "TextLabel", nullptr));
        label_28->setText(QCoreApplication::translate("GProjett", "TextLabel", nullptr));
        label_25->setText(QCoreApplication::translate("GProjett", "TextLabel", nullptr));
        label_15->setText(QCoreApplication::translate("GProjett", "Nom de Client", nullptr));
        label_18->setText(QCoreApplication::translate("GProjett", "TextLabel", nullptr));
        label_24->setText(QCoreApplication::translate("GProjett", "TextLabel", nullptr));
        label_14->setText(QCoreApplication::translate("GProjett", "Projet", nullptr));
        label_16->setText(QCoreApplication::translate("GProjett", "Fournissuer", nullptr));
        label_21->setText(QCoreApplication::translate("GProjett", "TextLabel", nullptr));
        label_29->setText(QCoreApplication::translate("GProjett", "Notre equipe", nullptr));
        pushButton->setText(QCoreApplication::translate("GProjett", "Voir plus", nullptr));
        label_31->setText(QCoreApplication::translate("GProjett", "Firas", nullptr));
        label_30->setText(QCoreApplication::translate("GProjett", "Wsssem", nullptr));
        label_32->setText(QCoreApplication::translate("GProjett", "Hadyder", nullptr));
        label_33->setText(QCoreApplication::translate("GProjett", "TextLabel", nullptr));
        label_34->setText(QCoreApplication::translate("GProjett", "TextLabel", nullptr));
        label_35->setText(QCoreApplication::translate("GProjett", "TextLabel", nullptr));
        label_36->setText(QCoreApplication::translate("GProjett", "TextLabel", nullptr));
        textBrowser_3->setHtml(QCoreApplication::translate("GProjett", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:696; font-style:italic;\">Home</span></p></body></html>", nullptr));
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
