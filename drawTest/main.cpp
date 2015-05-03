#include "mainwindow.h"
#include <QApplication>
#include "funwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /*FunWidget w;
    w.show();*/
    return a.exec();
}
