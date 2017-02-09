#include <QApplication>
#include "river.h"
#include "mainwindow.h"
MainWindow* mainwindow;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainwindow = new MainWindow;
    mainwindow->show();

    return a.exec();
}

