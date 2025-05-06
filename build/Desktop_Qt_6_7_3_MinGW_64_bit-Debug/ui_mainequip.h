/********************************************************************************
** Form generated from reading UI file 'mainequip.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINEQUIP_H
#define UI_MAINEQUIP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainEquip
{
public:
    QPushButton *exit_btn_3;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QTextBrowser *textBrowser;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_8;
    QTableWidget *tableWidget;
    QPushButton *pushButton_trier;
    QPushButton *exporter;
    QWidget *widget_6;
    QFrame *frame;
    QLineEdit *lineEdit_nom;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTextBrowser *textBrowser_4;
    QLabel *label_46;
    QLineEdit *lineEdit_quantite;
    QLabel *label_4;
    QLineEdit *lineEdit_budget;
    QLineEdit *lineEdit_type;
    QPushButton *pushButton_ajouter;
    QPushButton *pushButton_7;
    QPushButton *pushButton_Afficher;
    QLineEdit *lineEdit_caracteristiques;
    QLabel *label_75;
    QDateEdit *dateEdit_datedachat;
    QWidget *widget_7;
    QFrame *frame_2;
    QLineEdit *lineEdit_nomcherch;
    QLabel *label_74;
    QLabel *label_77;
    QTextBrowser *textBrowser_8;
    QLineEdit *lineEdit_typecherch;
    QPushButton *pushButton_trouver;
    QDateTimeEdit *dateTimeEdit_ff_5;
    QLabel *label_78;
    QPushButton *pushButton_25;
    QDial *dial;
    QCommandLinkButton *commandLinkButton_chatbot;
    QFrame *frame_8;
    QLineEdit *lineEdit_idsupp;
    QLabel *label_76;
    QTextBrowser *textBrowser_9;
    QPushButton *pushButton_supprimer;
    QPushButton *pushButton_27;
    QFrame *frame_9;
    QLineEdit *lineEdit_idmodif;
    QLabel *label_79;
    QTextBrowser *textBrowser_10;
    QPushButton *pushButton_modifier;
    QPushButton *pushButton_28;
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

    void setupUi(QDialog *MainEquip)
    {
        if (MainEquip->objectName().isEmpty())
            MainEquip->setObjectName("MainEquip");
        MainEquip->resize(1397, 760);
        exit_btn_3 = new QPushButton(MainEquip);
        exit_btn_3->setObjectName("exit_btn_3");
        exit_btn_3->setGeometry(QRect(10, 630, 163, 24));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/icon/close-window-64.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        exit_btn_3->setIcon(icon);
        exit_btn_3->setIconSize(QSize(14, 14));
        stackedWidget = new QStackedWidget(MainEquip);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(180, 40, 1211, 651));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        page = new QWidget();
        page->setObjectName("page");
        textBrowser = new QTextBrowser(page);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(-10, 0, 1141, 51));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        widget_4 = new QWidget(page);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(0, 330, 731, 311));
        widget_4->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        verticalLayout_8 = new QVBoxLayout(widget_4);
        verticalLayout_8->setObjectName("verticalLayout_8");
        tableWidget = new QTableWidget(widget_4);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidget->setObjectName("tableWidget");

        verticalLayout_8->addWidget(tableWidget);

        pushButton_trier = new QPushButton(widget_4);
        pushButton_trier->setObjectName("pushButton_trier");

        verticalLayout_8->addWidget(pushButton_trier);

        exporter = new QPushButton(widget_4);
        exporter->setObjectName("exporter");
        exporter->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 0);"));

        verticalLayout_8->addWidget(exporter);

        widget_6 = new QWidget(page);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(-1, 70, 721, 261));
        widget_6->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        frame = new QFrame(widget_6);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 10, 701, 241));
        frame->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        frame->setFrameShape(QFrame::Shape::NoFrame);
        lineEdit_nom = new QLineEdit(frame);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(120, 60, 191, 22));
        lineEdit_nom->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        lineEdit_nom->setReadOnly(false);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 60, 111, 16));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"rgb(170, 0, 127)\n"
"}"));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(410, 60, 81, 16));
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 120, 49, 16));
        textBrowser_4 = new QTextBrowser(frame);
        textBrowser_4->setObjectName("textBrowser_4");
        textBrowser_4->setGeometry(QRect(120, 0, 471, 51));
        textBrowser_4->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        label_46 = new QLabel(frame);
        label_46->setObjectName("label_46");
        label_46->setGeometry(QRect(0, 90, 91, 16));
        label_46->setStyleSheet(QString::fromUtf8("QLabel{\n"
"rgb(170, 0, 127)\n"
"}"));
        lineEdit_quantite = new QLineEdit(frame);
        lineEdit_quantite->setObjectName("lineEdit_quantite");
        lineEdit_quantite->setGeometry(QRect(120, 90, 191, 22));
        lineEdit_quantite->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        lineEdit_quantite->setReadOnly(false);
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 150, 49, 16));
        lineEdit_budget = new QLineEdit(frame);
        lineEdit_budget->setObjectName("lineEdit_budget");
        lineEdit_budget->setGeometry(QRect(120, 150, 191, 22));
        lineEdit_budget->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        lineEdit_budget->setReadOnly(false);
        lineEdit_type = new QLineEdit(frame);
        lineEdit_type->setObjectName("lineEdit_type");
        lineEdit_type->setGeometry(QRect(120, 120, 191, 22));
        lineEdit_type->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        lineEdit_type->setReadOnly(false);
        pushButton_ajouter = new QPushButton(frame);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(390, 190, 75, 24));
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 158, 96);"));
        pushButton_7 = new QPushButton(frame);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(610, 190, 75, 24));
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 158, 96);"));
        pushButton_Afficher = new QPushButton(frame);
        pushButton_Afficher->setObjectName("pushButton_Afficher");
        pushButton_Afficher->setGeometry(QRect(500, 190, 75, 24));
        pushButton_Afficher->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 158, 96);"));
        lineEdit_caracteristiques = new QLineEdit(frame);
        lineEdit_caracteristiques->setObjectName("lineEdit_caracteristiques");
        lineEdit_caracteristiques->setGeometry(QRect(420, 110, 191, 22));
        lineEdit_caracteristiques->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        lineEdit_caracteristiques->setReadOnly(false);
        label_75 = new QLabel(frame);
        label_75->setObjectName("label_75");
        label_75->setGeometry(QRect(410, 90, 81, 16));
        dateEdit_datedachat = new QDateEdit(frame);
        dateEdit_datedachat->setObjectName("dateEdit_datedachat");
        dateEdit_datedachat->setGeometry(QRect(510, 60, 110, 22));
        widget_7 = new QWidget(page);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(720, 70, 351, 221));
        widget_7->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        frame_2 = new QFrame(widget_7);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(10, 10, 321, 201));
        frame_2->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        frame_2->setFrameShape(QFrame::Shape::NoFrame);
        lineEdit_nomcherch = new QLineEdit(frame_2);
        lineEdit_nomcherch->setObjectName("lineEdit_nomcherch");
        lineEdit_nomcherch->setGeometry(QRect(120, 60, 191, 22));
        lineEdit_nomcherch->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        lineEdit_nomcherch->setReadOnly(false);
        label_74 = new QLabel(frame_2);
        label_74->setObjectName("label_74");
        label_74->setGeometry(QRect(0, 60, 111, 16));
        label_74->setStyleSheet(QString::fromUtf8("QLabel{\n"
"rgb(170, 0, 127)\n"
"}"));
        label_77 = new QLabel(frame_2);
        label_77->setObjectName("label_77");
        label_77->setGeometry(QRect(30, 100, 49, 16));
        textBrowser_8 = new QTextBrowser(frame_2);
        textBrowser_8->setObjectName("textBrowser_8");
        textBrowser_8->setGeometry(QRect(70, 0, 231, 51));
        textBrowser_8->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        lineEdit_typecherch = new QLineEdit(frame_2);
        lineEdit_typecherch->setObjectName("lineEdit_typecherch");
        lineEdit_typecherch->setGeometry(QRect(120, 100, 191, 22));
        lineEdit_typecherch->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        lineEdit_typecherch->setReadOnly(false);
        pushButton_trouver = new QPushButton(frame_2);
        pushButton_trouver->setObjectName("pushButton_trouver");
        pushButton_trouver->setGeometry(QRect(150, 170, 75, 24));
        pushButton_trouver->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 158, 96);"));
        dateTimeEdit_ff_5 = new QDateTimeEdit(frame_2);
        dateTimeEdit_ff_5->setObjectName("dateTimeEdit_ff_5");
        dateTimeEdit_ff_5->setGeometry(QRect(120, 130, 194, 22));
        dateTimeEdit_ff_5->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);"));
        dateTimeEdit_ff_5->setReadOnly(true);
        label_78 = new QLabel(frame_2);
        label_78->setObjectName("label_78");
        label_78->setGeometry(QRect(18, 130, 81, 20));
        pushButton_25 = new QPushButton(frame_2);
        pushButton_25->setObjectName("pushButton_25");
        pushButton_25->setGeometry(QRect(240, 170, 75, 24));
        pushButton_25->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 158, 96);"));
        dial = new QDial(page);
        dial->setObjectName("dial");
        dial->setGeometry(QRect(1090, 510, 50, 64));
        commandLinkButton_chatbot = new QCommandLinkButton(page);
        commandLinkButton_chatbot->setObjectName("commandLinkButton_chatbot");
        commandLinkButton_chatbot->setGeometry(QRect(1090, 570, 111, 31));
        frame_8 = new QFrame(page);
        frame_8->setObjectName("frame_8");
        frame_8->setGeometry(QRect(740, 290, 321, 161));
        frame_8->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        frame_8->setFrameShape(QFrame::Shape::NoFrame);
        lineEdit_idsupp = new QLineEdit(frame_8);
        lineEdit_idsupp->setObjectName("lineEdit_idsupp");
        lineEdit_idsupp->setGeometry(QRect(120, 60, 191, 22));
        lineEdit_idsupp->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        lineEdit_idsupp->setReadOnly(false);
        label_76 = new QLabel(frame_8);
        label_76->setObjectName("label_76");
        label_76->setGeometry(QRect(0, 60, 111, 16));
        label_76->setStyleSheet(QString::fromUtf8("QLabel{\n"
"rgb(170, 0, 127)\n"
"}"));
        textBrowser_9 = new QTextBrowser(frame_8);
        textBrowser_9->setObjectName("textBrowser_9");
        textBrowser_9->setGeometry(QRect(70, 0, 231, 51));
        textBrowser_9->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        pushButton_supprimer = new QPushButton(frame_8);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(110, 120, 75, 24));
        pushButton_supprimer->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 158, 96);"));
        pushButton_27 = new QPushButton(frame_8);
        pushButton_27->setObjectName("pushButton_27");
        pushButton_27->setGeometry(QRect(210, 120, 75, 24));
        pushButton_27->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 158, 96);"));
        frame_9 = new QFrame(page);
        frame_9->setObjectName("frame_9");
        frame_9->setGeometry(QRect(740, 460, 321, 161));
        frame_9->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        frame_9->setFrameShape(QFrame::Shape::NoFrame);
        lineEdit_idmodif = new QLineEdit(frame_9);
        lineEdit_idmodif->setObjectName("lineEdit_idmodif");
        lineEdit_idmodif->setGeometry(QRect(120, 60, 191, 22));
        lineEdit_idmodif->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        lineEdit_idmodif->setReadOnly(false);
        label_79 = new QLabel(frame_9);
        label_79->setObjectName("label_79");
        label_79->setGeometry(QRect(0, 60, 111, 16));
        label_79->setStyleSheet(QString::fromUtf8("QLabel{\n"
"rgb(170, 0, 127)\n"
"}"));
        textBrowser_10 = new QTextBrowser(frame_9);
        textBrowser_10->setObjectName("textBrowser_10");
        textBrowser_10->setGeometry(QRect(70, 0, 231, 51));
        textBrowser_10->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
" border: 1px solid #ffffff; "));
        pushButton_modifier = new QPushButton(frame_9);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(110, 120, 75, 24));
        pushButton_modifier->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 158, 96);"));
        pushButton_28 = new QPushButton(frame_9);
        pushButton_28->setObjectName("pushButton_28");
        pushButton_28->setGeometry(QRect(210, 120, 75, 24));
        pushButton_28->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 158, 96);"));
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
        QFont font;
        font.setPointSize(14);
        font.setUnderline(true);
        label_9->setFont(font);

        verticalLayout_6->addWidget(label_9);

        label_6 = new QLabel(card1);
        label_6->setObjectName("label_6");
        QFont font1;
        font1.setPointSize(12);
        label_6->setFont(font1);

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
        label_7->setFont(font);
        label_7->setAcceptDrops(false);

        verticalLayout_7->addWidget(label_7);

        label_10 = new QLabel(card2);
        label_10->setObjectName("label_10");
        label_10->setFont(font1);

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
        label_8->setFont(font);

        verticalLayout_9->addWidget(label_8);

        label_11 = new QLabel(card3);
        label_11->setObjectName("label_11");
        label_11->setFont(font1);

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
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        label_12->setFont(font2);

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
        QFont font3;
        font3.setPointSize(13);
        font3.setBold(true);
        label_15->setFont(font3);

        gridLayout->addWidget(label_15, 0, 1, 1, 1);

        label_18 = new QLabel(frame_6);
        label_18->setObjectName("label_18");

        gridLayout->addWidget(label_18, 2, 1, 1, 1);

        label_24 = new QLabel(frame_6);
        label_24->setObjectName("label_24");

        gridLayout->addWidget(label_24, 4, 1, 1, 1);

        label_14 = new QLabel(frame_6);
        label_14->setObjectName("label_14");
        label_14->setFont(font3);

        gridLayout->addWidget(label_14, 0, 0, 1, 1);

        label_16 = new QLabel(frame_6);
        label_16->setObjectName("label_16");
        label_16->setFont(font3);

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
        label_29->setFont(font2);

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
        layoutWidget = new QWidget(MainEquip);
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/icon/search-13-48.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        search_btn->setIcon(icon1);

        horizontalLayout->addWidget(search_btn);

        full_menu_widget = new QWidget(MainEquip);
        full_menu_widget->setObjectName("full_menu_widget");
        full_menu_widget->setGeometry(QRect(0, 20, 181, 621));
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
        QFont font4;
        font4.setPointSize(15);
        logo_label_5->setFont(font4);

        horizontalLayout_3->addWidget(logo_label_5);


        verticalLayout_5->addLayout(horizontalLayout_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        home_btn_4 = new QPushButton(full_menu_widget);
        home_btn_4->setObjectName("home_btn_4");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/icon/home-4-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon2.addFile(QString::fromUtf8(":/icon/icon/home-4-48.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        home_btn_4->setIcon(icon2);
        home_btn_4->setIconSize(QSize(14, 14));
        home_btn_4->setCheckable(true);
        home_btn_4->setAutoExclusive(true);

        verticalLayout_3->addWidget(home_btn_4);

        dashborad_btn_3 = new QPushButton(full_menu_widget);
        dashborad_btn_3->setObjectName("dashborad_btn_3");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/icon/dashboard-5-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon3.addFile(QString::fromUtf8(":/icon/icon/dashboard-5-48.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        dashborad_btn_3->setIcon(icon3);
        dashborad_btn_3->setIconSize(QSize(14, 14));
        dashborad_btn_3->setCheckable(true);
        dashborad_btn_3->setAutoExclusive(true);

        verticalLayout_3->addWidget(dashborad_btn_3);

        orders_btn_3 = new QPushButton(full_menu_widget);
        orders_btn_3->setObjectName("orders_btn_3");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/icon/activity-feed-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon4.addFile(QString::fromUtf8(":/icon/icon/activity-feed-48.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        orders_btn_3->setIcon(icon4);
        orders_btn_3->setIconSize(QSize(14, 14));
        orders_btn_3->setCheckable(true);
        orders_btn_3->setAutoExclusive(true);

        verticalLayout_3->addWidget(orders_btn_3);

        products_btn_3 = new QPushButton(full_menu_widget);
        products_btn_3->setObjectName("products_btn_3");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/icon/product-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon5.addFile(QString::fromUtf8(":/icon/icon/product-48.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        products_btn_3->setIcon(icon5);
        products_btn_3->setIconSize(QSize(14, 14));
        products_btn_3->setCheckable(true);
        products_btn_3->setAutoExclusive(true);

        verticalLayout_3->addWidget(products_btn_3);

        customers_btn_4 = new QPushButton(full_menu_widget);
        customers_btn_4->setObjectName("customers_btn_4");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icon/icon/group-32.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon6.addFile(QString::fromUtf8(":/icon/icon/group-48.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        customers_btn_4->setIcon(icon6);
        customers_btn_4->setIconSize(QSize(14, 14));
        customers_btn_4->setCheckable(true);
        customers_btn_4->setAutoExclusive(true);

        verticalLayout_3->addWidget(customers_btn_4);

        customers_btn_5 = new QPushButton(full_menu_widget);
        customers_btn_5->setObjectName("customers_btn_5");
        customers_btn_5->setIcon(icon6);
        customers_btn_5->setIconSize(QSize(14, 14));
        customers_btn_5->setCheckable(true);
        customers_btn_5->setAutoExclusive(true);

        verticalLayout_3->addWidget(customers_btn_5);

        home_btn_5 = new QPushButton(full_menu_widget);
        home_btn_5->setObjectName("home_btn_5");
        home_btn_5->setIcon(icon2);
        home_btn_5->setIconSize(QSize(14, 14));
        home_btn_5->setCheckable(true);
        home_btn_5->setAutoExclusive(true);

        verticalLayout_3->addWidget(home_btn_5);


        verticalLayout_5->addLayout(verticalLayout_3);


        retranslateUi(MainEquip);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainEquip);
    } // setupUi

    void retranslateUi(QDialog *MainEquip)
    {
        MainEquip->setWindowTitle(QCoreApplication::translate("MainEquip", "Dialog", nullptr));
        exit_btn_3->setText(QCoreApplication::translate("MainEquip", "Sortir", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainEquip", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700;\">Gestion des equipements</span></p></body></html>", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainEquip", "ID_EQUIPEMENT", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainEquip", "NOM", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainEquip", "QUANTITE", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainEquip", "TYPE", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainEquip", "DATEDACHAT", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainEquip", "BUDGET", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainEquip", "CARACTERISTIQUES", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainEquip", "code_barre", nullptr));
        pushButton_trier->setText(QCoreApplication::translate("MainEquip", "trier ", nullptr));
        exporter->setText(QCoreApplication::translate("MainEquip", "Exporter", nullptr));
        label->setText(QCoreApplication::translate("MainEquip", "Nom d'equipement", nullptr));
        label_2->setText(QCoreApplication::translate("MainEquip", "Date d'achat", nullptr));
        label_3->setText(QCoreApplication::translate("MainEquip", "Type", nullptr));
        textBrowser_4->setHtml(QCoreApplication::translate("MainEquip", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">Ajouter un equipement</span></p></body></html>", nullptr));
        label_46->setText(QCoreApplication::translate("MainEquip", "Quantit\303\251", nullptr));
        label_4->setText(QCoreApplication::translate("MainEquip", "Budget", nullptr));
        pushButton_ajouter->setText(QCoreApplication::translate("MainEquip", "Ajouter", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainEquip", "Annuler", nullptr));
        pushButton_Afficher->setText(QCoreApplication::translate("MainEquip", "Afficher", nullptr));
        label_75->setText(QCoreApplication::translate("MainEquip", "carcteristiques", nullptr));
        label_74->setText(QCoreApplication::translate("MainEquip", "Nom d'equipement", nullptr));
        label_77->setText(QCoreApplication::translate("MainEquip", "Type", nullptr));
        textBrowser_8->setHtml(QCoreApplication::translate("MainEquip", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">Trouver un equipement</span></p></body></html>", nullptr));
        pushButton_trouver->setText(QCoreApplication::translate("MainEquip", "Trouver", nullptr));
        label_78->setText(QCoreApplication::translate("MainEquip", "date d'achat", nullptr));
        pushButton_25->setText(QCoreApplication::translate("MainEquip", "Annuler", nullptr));
        commandLinkButton_chatbot->setText(QCoreApplication::translate("MainEquip", "chatbot??", nullptr));
        label_76->setText(QCoreApplication::translate("MainEquip", "id d'equipement", nullptr));
        textBrowser_9->setHtml(QCoreApplication::translate("MainEquip", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">supprimer un equipement</span></p></body></html>", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("MainEquip", "supprimer", nullptr));
        pushButton_27->setText(QCoreApplication::translate("MainEquip", "Annuler", nullptr));
        label_79->setText(QCoreApplication::translate("MainEquip", "id d'equipement", nullptr));
        textBrowser_10->setHtml(QCoreApplication::translate("MainEquip", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">modifier un equipement</span></p></body></html>", nullptr));
        pushButton_modifier->setText(QCoreApplication::translate("MainEquip", "modifier", nullptr));
        pushButton_28->setText(QCoreApplication::translate("MainEquip", "Annuler", nullptr));
        label_9->setText(QCoreApplication::translate("MainEquip", "Nombre de projet:", nullptr));
        label_6->setText(QCoreApplication::translate("MainEquip", "200", nullptr));
        label_7->setText(QCoreApplication::translate("MainEquip", "Nombre d'employee", nullptr));
        label_10->setText(QCoreApplication::translate("MainEquip", "200", nullptr));
        label_8->setText(QCoreApplication::translate("MainEquip", "Nombre de Fournisseur", nullptr));
        label_11->setText(QCoreApplication::translate("MainEquip", "200", nullptr));
        label_12->setText(QCoreApplication::translate("MainEquip", "Listes", nullptr));
        label_13->setText(QCoreApplication::translate("MainEquip", "voir plus", nullptr));
        label_20->setText(QCoreApplication::translate("MainEquip", "TextLabel", nullptr));
        label_23->setText(QCoreApplication::translate("MainEquip", "TextLabel", nullptr));
        label_17->setText(QCoreApplication::translate("MainEquip", "TextLabel", nullptr));
        label_27->setText(QCoreApplication::translate("MainEquip", "TextLabel", nullptr));
        label_19->setText(QCoreApplication::translate("MainEquip", "TextLabel", nullptr));
        label_22->setText(QCoreApplication::translate("MainEquip", "TextLabel", nullptr));
        label_26->setText(QCoreApplication::translate("MainEquip", "TextLabel", nullptr));
        label_28->setText(QCoreApplication::translate("MainEquip", "TextLabel", nullptr));
        label_25->setText(QCoreApplication::translate("MainEquip", "TextLabel", nullptr));
        label_15->setText(QCoreApplication::translate("MainEquip", "Nom de Client", nullptr));
        label_18->setText(QCoreApplication::translate("MainEquip", "TextLabel", nullptr));
        label_24->setText(QCoreApplication::translate("MainEquip", "TextLabel", nullptr));
        label_14->setText(QCoreApplication::translate("MainEquip", "Projet", nullptr));
        label_16->setText(QCoreApplication::translate("MainEquip", "Fournissuer", nullptr));
        label_21->setText(QCoreApplication::translate("MainEquip", "TextLabel", nullptr));
        label_29->setText(QCoreApplication::translate("MainEquip", "Notre equipe", nullptr));
        pushButton->setText(QCoreApplication::translate("MainEquip", "Voir plus", nullptr));
        label_31->setText(QCoreApplication::translate("MainEquip", "Firas", nullptr));
        label_30->setText(QCoreApplication::translate("MainEquip", "Wsssem", nullptr));
        label_32->setText(QCoreApplication::translate("MainEquip", "Hadyder", nullptr));
        label_33->setText(QCoreApplication::translate("MainEquip", "TextLabel", nullptr));
        label_34->setText(QCoreApplication::translate("MainEquip", "TextLabel", nullptr));
        label_35->setText(QCoreApplication::translate("MainEquip", "TextLabel", nullptr));
        label_36->setText(QCoreApplication::translate("MainEquip", "TextLabel", nullptr));
        textBrowser_3->setHtml(QCoreApplication::translate("MainEquip", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:696; font-style:italic;\">Home</span></p></body></html>", nullptr));
        search_input->setPlaceholderText(QCoreApplication::translate("MainEquip", "Search...", nullptr));
        search_btn->setText(QString());
        logo_label_4->setText(QString());
        logo_label_5->setText(QCoreApplication::translate("MainEquip", "Architexia", nullptr));
        home_btn_4->setText(QCoreApplication::translate("MainEquip", "Accueil", nullptr));
        dashborad_btn_3->setText(QCoreApplication::translate("MainEquip", "Gestion des employees", nullptr));
        orders_btn_3->setText(QCoreApplication::translate("MainEquip", "Gestion des equipements", nullptr));
        products_btn_3->setText(QCoreApplication::translate("MainEquip", "Gestion des projets", nullptr));
        customers_btn_4->setText(QCoreApplication::translate("MainEquip", "Gestion des clients", nullptr));
        customers_btn_5->setText(QCoreApplication::translate("MainEquip", "Gestion des fournisseurs", nullptr));
        home_btn_5->setText(QCoreApplication::translate("MainEquip", "Gestion des architectes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainEquip: public Ui_MainEquip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINEQUIP_H
