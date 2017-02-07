#include <QtGui/QApplication>
#include "river.h"

River * river;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    river = new River();
    river->show();

    return app->exec();
}
