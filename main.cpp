#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "loginform.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    bool test = Connection::getInstance()->createconnect();
    if(!test) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur de base de données"),
                              QObject::tr("Connexion échouée à la base de données."), QMessageBox::Cancel);
        return 1;
    }

    LoginForm loginForm;
    loginForm.show();

    return a.exec();
}
