#include "gprojett.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GProjett w;
    Connection c;

    // Tentative de connexion à la base de données
    bool test = c.createconnect();
    if (test) {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                 QObject::tr("Connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("Connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }


    return a.exec();
}
