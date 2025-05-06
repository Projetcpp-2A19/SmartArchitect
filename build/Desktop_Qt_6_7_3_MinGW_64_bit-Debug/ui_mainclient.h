/********************************************************************************
** Form generated from reading UI file 'mainclient.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINCLIENT_H
#define UI_MAINCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainClient
{
public:
    QTabWidget *tabWidget_2;
    QWidget *tab_4;
    QStackedWidget *QGoupBox;
    QWidget *QGoupBoxPage1;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *le_nom;
    QLineEdit *le_prenom;
    QLineEdit *le_region;
    QPushButton *pb_ajouter;
    QPushButton *pb_modifier;
    QLabel *label;
    QLineEdit *le_telephone;
    QLabel *label_3;
    QLineEdit *le_email;
    QPushButton *pushButton_9;
    QWidget *widget;
    QWidget *widget_3;
    QWidget *widget_6;
    QWidget *widget_7;
    QLabel *label_23;
    QPushButton *enregistrerTemperature;
    QWidget *tab_5;
    QTableView *tableView;
    QPushButton *client_pb_stat;
    QWidget *tab_6;
    QLabel *label_9;
    QLineEdit *le_idsupp;
    QPushButton *pb_supprimer;
    QWidget *tab_7;
    QPushButton *pb_chercher_nom;
    QPushButton *pb_tri;
    QTableView *tableViewNom;
    QPushButton *pb_export_pdf;
    QLabel *label_2;
    QLineEdit *lineEditNom;
    QComboBox *comboBoxRegions;
    QLabel *label_temperature;
    QWidget *widget_4;
    QWidget *widget_8;
    QWidget *widget_9;
    QLabel *label_26;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_11;
    QLineEdit *le_id_2;
    QPushButton *pushButton_8;
    QLineEdit *le_nom_2;
    QSpinBox *spinBox;
    QLabel *label_10;
    QLineEdit *le_prenom_2;
    QTextEdit *textEdit_2;
    QLabel *label_12;
    QLabel *label_25;
    QTableWidget *tableWidgetFidelite;
    QPushButton *actualiser_fidelite;
    QPushButton *generer_carte;
    QLabel *label_4;
    QLabel *label_24;
    QFrame *arduinoFrame;
    QVBoxLayout *verticalLayout_arduino;
    QComboBox *portComboBox;
    QPushButton *connectButton;
    QLabel *temperatureLabel;
    QLabel *humidityLabel;
    QLineEdit *thresholdLineEdit;
    QPushButton *setThresholdButton;
    QLineEdit *le_temperature;
    QTextEdit *textEdit;
    QGroupBox *QGoupBox_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QWidget *widget_10;
    QWidget *widget_12;
    QLabel *label_28;
    QTableWidget *tableWidget;
    QPushButton *pushButton_10;

    void setupUi(QDialog *MainClient)
    {
        if (MainClient->objectName().isEmpty())
            MainClient->setObjectName("MainClient");
        MainClient->resize(1312, 841);
        tabWidget_2 = new QTabWidget(MainClient);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(290, 100, 461, 381));
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        QGoupBox = new QStackedWidget(tab_4);
        QGoupBox->setObjectName("QGoupBox");
        QGoupBox->setGeometry(QRect(20, 20, 431, 311));
        QGoupBoxPage1 = new QWidget();
        QGoupBoxPage1->setObjectName("QGoupBoxPage1");
        label_5 = new QLabel(QGoupBoxPage1);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 70, 47, 14));
        label_6 = new QLabel(QGoupBoxPage1);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 120, 61, 16));
        label_7 = new QLabel(QGoupBoxPage1);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 20, 31, 16));
        label_8 = new QLabel(QGoupBoxPage1);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 170, 47, 14));
        le_nom = new QLineEdit(QGoupBoxPage1);
        le_nom->setObjectName("le_nom");
        le_nom->setGeometry(QRect(120, 70, 113, 20));
        le_prenom = new QLineEdit(QGoupBoxPage1);
        le_prenom->setObjectName("le_prenom");
        le_prenom->setGeometry(QRect(120, 120, 113, 20));
        le_region = new QLineEdit(QGoupBoxPage1);
        le_region->setObjectName("le_region");
        le_region->setGeometry(QRect(120, 170, 113, 20));
        pb_ajouter = new QPushButton(QGoupBoxPage1);
        pb_ajouter->setObjectName("pb_ajouter");
        pb_ajouter->setGeometry(QRect(270, 20, 75, 23));
        pb_ajouter->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 0);\n"
""));
        pb_modifier = new QPushButton(QGoupBoxPage1);
        pb_modifier->setObjectName("pb_modifier");
        pb_modifier->setGeometry(QRect(270, 60, 75, 23));
        pb_modifier->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 0);\n"
"background-color: rgb(255, 58, 23);"));
        label = new QLabel(QGoupBoxPage1);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 220, 47, 14));
        le_telephone = new QLineEdit(QGoupBoxPage1);
        le_telephone->setObjectName("le_telephone");
        le_telephone->setGeometry(QRect(120, 220, 113, 20));
        label_3 = new QLabel(QGoupBoxPage1);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 270, 47, 14));
        le_email = new QLineEdit(QGoupBoxPage1);
        le_email->setObjectName("le_email");
        le_email->setGeometry(QRect(120, 260, 113, 20));
        pushButton_9 = new QPushButton(QGoupBoxPage1);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(270, 110, 93, 29));
        widget = new QWidget(QGoupBoxPage1);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, -10, 431, 331));
        widget->setMouseTracking(false);
        widget->setAutoFillBackground(false);
        widget_3 = new QWidget(widget);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(-30, 10, 471, 301));
        widget_3->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(162, 162, 162);"));
        widget_6 = new QWidget(widget_3);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(30, 0, 431, 311));
        widget_6->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(162, 162, 162);"));
        widget_7 = new QWidget(widget_6);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(10, 10, 411, 281));
        widget_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:10px;"));
        label_23 = new QLabel(widget_7);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(10, 10, 231, 41));
        QFont font;
        font.setPointSize(15);
        label_23->setFont(font);
        label_23->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(162, 162, 162);\n"
"border-radius:10px;"));
        enregistrerTemperature = new QPushButton(widget_7);
        enregistrerTemperature->setObjectName("enregistrerTemperature");
        enregistrerTemperature->setGeometry(QRect(270, 220, 100, 23));
        enregistrerTemperature->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 0);"));
        QGoupBox->addWidget(QGoupBoxPage1);
        widget->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        le_nom->raise();
        le_prenom->raise();
        le_region->raise();
        pb_ajouter->raise();
        pb_modifier->raise();
        label->raise();
        le_telephone->raise();
        label_3->raise();
        le_email->raise();
        pushButton_9->raise();
        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        tableView = new QTableView(tab_5);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(0, 50, 481, 171));
        client_pb_stat = new QPushButton(tab_5);
        client_pb_stat->setObjectName("client_pb_stat");
        client_pb_stat->setGeometry(QRect(190, 260, 75, 23));
        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        label_9 = new QLabel(tab_6);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(40, 50, 61, 20));
        le_idsupp = new QLineEdit(tab_6);
        le_idsupp->setObjectName("le_idsupp");
        le_idsupp->setGeometry(QRect(130, 50, 113, 20));
        pb_supprimer = new QPushButton(tab_6);
        pb_supprimer->setObjectName("pb_supprimer");
        pb_supprimer->setGeometry(QRect(280, 50, 75, 23));
        tabWidget_2->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        pb_chercher_nom = new QPushButton(tab_7);
        pb_chercher_nom->setObjectName("pb_chercher_nom");
        pb_chercher_nom->setGeometry(QRect(300, 100, 75, 23));
        pb_tri = new QPushButton(tab_7);
        pb_tri->setObjectName("pb_tri");
        pb_tri->setGeometry(QRect(300, 50, 75, 23));
        tableViewNom = new QTableView(tab_7);
        tableViewNom->setObjectName("tableViewNom");
        tableViewNom->setGeometry(QRect(20, 170, 381, 161));
        pb_export_pdf = new QPushButton(tab_7);
        pb_export_pdf->setObjectName("pb_export_pdf");
        pb_export_pdf->setGeometry(QRect(300, 140, 111, 23));
        label_2 = new QLabel(tab_7);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 60, 47, 14));
        lineEditNom = new QLineEdit(tab_7);
        lineEditNom->setObjectName("lineEditNom");
        lineEditNom->setGeometry(QRect(100, 60, 113, 20));
        comboBoxRegions = new QComboBox(tab_7);
        comboBoxRegions->setObjectName("comboBoxRegions");
        comboBoxRegions->setGeometry(QRect(155, 15, 131, 31));
        tabWidget_2->addTab(tab_7, QString());
        label_temperature = new QLabel(MainClient);
        label_temperature->setObjectName("label_temperature");
        label_temperature->setGeometry(QRect(140, 530, 80, 20));
        widget_4 = new QWidget(MainClient);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(800, 130, 521, 321));
        widget_4->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(162, 162, 162);"));
        widget_8 = new QWidget(widget_4);
        widget_8->setObjectName("widget_8");
        widget_8->setGeometry(QRect(20, -40, 501, 371));
        widget_8->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(162, 162, 162);"));
        widget_9 = new QWidget(widget_8);
        widget_9->setObjectName("widget_9");
        widget_9->setGeometry(QRect(0, 50, 481, 301));
        widget_9->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:10px;"));
        label_26 = new QLabel(widget_9);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(10, 10, 231, 41));
        label_26->setFont(font);
        label_26->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(162, 162, 162);\n"
"border-radius:10px;"));
        scrollArea = new QScrollArea(widget_9);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(-10, 0, 481, 281));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 481, 281));
        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(290, 170, 63, 20));
        le_id_2 = new QLineEdit(scrollAreaWidgetContents);
        le_id_2->setObjectName("le_id_2");
        le_id_2->setGeometry(QRect(130, 170, 113, 20));
        le_id_2->setTabletTracking(false);
        pushButton_8 = new QPushButton(scrollAreaWidgetContents);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(370, 240, 93, 29));
        pushButton_8->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 0);\n"
""));
        le_nom_2 = new QLineEdit(scrollAreaWidgetContents);
        le_nom_2->setObjectName("le_nom_2");
        le_nom_2->setGeometry(QRect(340, 170, 113, 20));
        spinBox = new QSpinBox(scrollAreaWidgetContents);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(270, 250, 31, 16));
        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(70, 170, 63, 20));
        le_prenom_2 = new QLineEdit(scrollAreaWidgetContents);
        le_prenom_2->setObjectName("le_prenom_2");
        le_prenom_2->setGeometry(QRect(180, 250, 113, 20));
        textEdit_2 = new QTextEdit(scrollAreaWidgetContents);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(130, 10, 261, 31));
        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(40, 250, 151, 20));
        label_25 = new QLabel(scrollAreaWidgetContents);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(170, 10, 181, 41));
        label_25->setFont(font);
        label_25->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(162, 162, 162);\n"
"border-radius:10px;"));
        tableWidgetFidelite = new QTableWidget(scrollAreaWidgetContents);
        tableWidgetFidelite->setObjectName("tableWidgetFidelite");
        tableWidgetFidelite->setGeometry(QRect(30, 80, 441, 192));
        actualiser_fidelite = new QPushButton(scrollAreaWidgetContents);
        actualiser_fidelite->setObjectName("actualiser_fidelite");
        actualiser_fidelite->setGeometry(QRect(390, 20, 93, 29));
        generer_carte = new QPushButton(scrollAreaWidgetContents);
        generer_carte->setObjectName("generer_carte");
        generer_carte->setGeometry(QRect(30, 20, 81, 29));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label_4 = new QLabel(MainClient);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 30, 171, 61));
        label_4->setMinimumSize(QSize(26, 8));
        label_4->setMaximumSize(QSize(171, 61));
        label_24 = new QLabel(MainClient);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(370, 30, 571, 41));
        label_24->setFont(font);
        label_24->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(162, 162, 162);\n"
"border-radius:10px;"));
        arduinoFrame = new QFrame(MainClient);
        arduinoFrame->setObjectName("arduinoFrame");
        arduinoFrame->setGeometry(QRect(20, 550, 300, 200));
        arduinoFrame->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100);\n"
"border-radius:15px;\n"
"border: 1px solid #ffffff;"));
        arduinoFrame->setFrameShape(QFrame::Shape::NoFrame);
        verticalLayout_arduino = new QVBoxLayout(arduinoFrame);
        verticalLayout_arduino->setObjectName("verticalLayout_arduino");
        portComboBox = new QComboBox(arduinoFrame);
        portComboBox->setObjectName("portComboBox");
        portComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid rgba(0, 0, 0, 100);\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}"));

        verticalLayout_arduino->addWidget(portComboBox);

        connectButton = new QPushButton(arduinoFrame);
        connectButton->setObjectName("connectButton");
        connectButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(0, 0, 0, 100);\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}"));

        verticalLayout_arduino->addWidget(connectButton);

        temperatureLabel = new QLabel(arduinoFrame);
        temperatureLabel->setObjectName("temperatureLabel");
        temperatureLabel->setStyleSheet(QString::fromUtf8("color: white;"));

        verticalLayout_arduino->addWidget(temperatureLabel);

        humidityLabel = new QLabel(arduinoFrame);
        humidityLabel->setObjectName("humidityLabel");
        humidityLabel->setStyleSheet(QString::fromUtf8("color: white;"));

        verticalLayout_arduino->addWidget(humidityLabel);

        thresholdLineEdit = new QLineEdit(arduinoFrame);
        thresholdLineEdit->setObjectName("thresholdLineEdit");
        thresholdLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid rgba(0, 0, 0, 100);\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}"));

        verticalLayout_arduino->addWidget(thresholdLineEdit);

        setThresholdButton = new QPushButton(arduinoFrame);
        setThresholdButton->setObjectName("setThresholdButton");
        setThresholdButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(0, 0, 0, 100);\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}"));

        verticalLayout_arduino->addWidget(setThresholdButton);

        le_temperature = new QLineEdit(MainClient);
        le_temperature->setObjectName("le_temperature");
        le_temperature->setGeometry(QRect(230, 530, 113, 20));
        textEdit = new QTextEdit(MainClient);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(370, 40, 241, 31));
        QGoupBox_2 = new QGroupBox(MainClient);
        QGoupBox_2->setObjectName("QGoupBox_2");
        QGoupBox_2->setGeometry(QRect(10, 100, 201, 421));
        pushButton = new QPushButton(QGoupBox_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 30, 171, 29));
        pushButton_2 = new QPushButton(QGoupBox_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 80, 171, 29));
        pushButton_3 = new QPushButton(QGoupBox_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 130, 171, 29));
        pushButton_4 = new QPushButton(QGoupBox_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(20, 180, 171, 29));
        pushButton_5 = new QPushButton(QGoupBox_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(20, 240, 171, 29));
        pushButton_6 = new QPushButton(QGoupBox_2);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(20, 300, 171, 29));
        pushButton_7 = new QPushButton(QGoupBox_2);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(20, 360, 171, 29));
        widget_10 = new QWidget(MainClient);
        widget_10->setObjectName("widget_10");
        widget_10->setGeometry(QRect(370, 500, 841, 261));
        widget_10->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(162, 162, 162);"));
        widget_12 = new QWidget(widget_10);
        widget_12->setObjectName("widget_12");
        widget_12->setGeometry(QRect(10, 10, 821, 241));
        widget_12->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:10px;"));
        label_28 = new QLabel(widget_12);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(10, 10, 231, 41));
        label_28->setFont(font);
        label_28->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(162, 162, 162);\n"
"border-radius:10px;"));
        tableWidget = new QTableWidget(widget_12);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
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
        if (tableWidget->rowCount() < 3)
            tableWidget->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem8);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 80, 809, 151));
        tableWidget->setMinimumSize(QSize(809, 0));
        pushButton_10 = new QPushButton(widget_12);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(280, 20, 93, 29));

        retranslateUi(MainClient);

        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainClient);
    } // setupUi

    void retranslateUi(QDialog *MainClient)
    {
        MainClient->setWindowTitle(QCoreApplication::translate("MainClient", "Dialog", nullptr));
        label_5->setText(QCoreApplication::translate("MainClient", "nom", nullptr));
        label_6->setText(QCoreApplication::translate("MainClient", "prenom", nullptr));
        label_7->setText(QString());
        label_8->setText(QCoreApplication::translate("MainClient", "region", nullptr));
        pb_ajouter->setText(QCoreApplication::translate("MainClient", "Ajouter", nullptr));
        pb_modifier->setText(QCoreApplication::translate("MainClient", "modifier", nullptr));
        label->setText(QCoreApplication::translate("MainClient", "telephone", nullptr));
        label_3->setText(QCoreApplication::translate("MainClient", "Email", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainClient", "sauv", nullptr));
        label_23->setText(QCoreApplication::translate("MainClient", "  Ajouter un client", nullptr));
        enregistrerTemperature->setText(QCoreApplication::translate("MainClient", "Enregistrer", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QCoreApplication::translate("MainClient", "Ajouter", nullptr));
        client_pb_stat->setText(QCoreApplication::translate("MainClient", "Stat", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QCoreApplication::translate("MainClient", "Afficher", nullptr));
        label_9->setText(QCoreApplication::translate("MainClient", "id_client", nullptr));
        pb_supprimer->setText(QCoreApplication::translate("MainClient", "Supprimer", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QCoreApplication::translate("MainClient", "Supprimer", nullptr));
        pb_chercher_nom->setText(QCoreApplication::translate("MainClient", "Chercher", nullptr));
        pb_tri->setText(QCoreApplication::translate("MainClient", "Trier", nullptr));
        pb_export_pdf->setText(QCoreApplication::translate("MainClient", "Export as PDF", nullptr));
        label_2->setText(QCoreApplication::translate("MainClient", "nom", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QCoreApplication::translate("MainClient", "Chercher", nullptr));
        label_temperature->setText(QCoreApplication::translate("MainClient", "Temp\303\251rature", nullptr));
        label_26->setText(QCoreApplication::translate("MainClient", "  Ajouter un client", nullptr));
        label_11->setText(QCoreApplication::translate("MainClient", "id ", nullptr));
        le_id_2->setText(QString());
        pushButton_8->setText(QCoreApplication::translate("MainClient", "Augmenter", nullptr));
        label_10->setText(QCoreApplication::translate("MainClient", "Nom ", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("MainClient", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">fidelite simple </span></p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("MainClient", "compteur de point ", nullptr));
        label_25->setText(QCoreApplication::translate("MainClient", "   fidilite simple ", nullptr));
        actualiser_fidelite->setText(QCoreApplication::translate("MainClient", "actuialiser", nullptr));
        generer_carte->setText(QCoreApplication::translate("MainClient", "carte", nullptr));
        label_4->setText(QCoreApplication::translate("MainClient", "<html><head/><body><p><span style=\" font-size:20pt;\">Architexia</span></p></body></html>", nullptr));
        label_24->setText(QCoreApplication::translate("MainClient", "  Ajouter un client", nullptr));
        connectButton->setText(QCoreApplication::translate("MainClient", "Connecter Arduino", nullptr));
        temperatureLabel->setText(QCoreApplication::translate("MainClient", "Temp\303\251rature: -- \302\260C", nullptr));
        humidityLabel->setText(QCoreApplication::translate("MainClient", "Humidit\303\251: -- %", nullptr));
        thresholdLineEdit->setPlaceholderText(QCoreApplication::translate("MainClient", "Seuil de temp\303\251rature", nullptr));
        setThresholdButton->setText(QCoreApplication::translate("MainClient", "D\303\251finir le seuil", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainClient", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#000000;\">Ajouter un client </span></p></body></html>", nullptr));
        QGoupBox_2->setTitle(QString());
        pushButton->setText(QCoreApplication::translate("MainClient", "Acceuil", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainClient", "Gestion d'employee", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainClient", "Gestion de client", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainClient", "Gestion de projet ", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainClient", "Gestion des equipement", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainClient", "Gestion des fournisseurs", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainClient", "Gestion des architectes", nullptr));
        label_28->setText(QCoreApplication::translate("MainClient", "tableau affichage", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainClient", "id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainClient", "nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainClient", "prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainClient", "telephone", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainClient", "region", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainClient", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainClient", "user", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainClient", "user", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainClient", "user", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainClient", "afficher", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainClient: public Ui_MainClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCLIENT_H
