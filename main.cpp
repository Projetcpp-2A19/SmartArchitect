#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;
    bool test=c.createconnect();
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


    QSqlQuery query;
    query.prepare("INSERT INTO FOURNISSEURS (NOM, TELEPHONE, ADRESSE, VILLE, ETAT, COMMANDE, EMAIL) "
                  "VALUES (:nom, :telephone, :adresse, :ville, :etat, :commande, :email)");

    query.bindValue(":nom", "Fournisseur Qt");
    query.bindValue(":telephone", "0987654321");
    query.bindValue(":adresse", "456 Avenue Test");
    query.bindValue(":ville", "Lyon");
    query.bindValue(":etat", "Rhône-Alpes");
    query.bindValue(":commande", "Cmd456");
    query.bindValue(":email", "qt@test.com");

    if (!query.exec()) {
        qDebug() << "Erreur d'insertion :" << query.lastError().text();
    } else {
        qDebug() << "Insertion réussie !";
    }

    return a.exec();
}


