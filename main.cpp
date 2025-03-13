#include "mainwindow.h"
#include <QApplication>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection c;
    bool test = c.createconnect();
    MainWindow w;
    if (test)
        w.show();
    return a.exec();
}
