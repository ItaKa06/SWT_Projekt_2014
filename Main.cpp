#include "mainwindow.h"
#include <QApplication>
#include <controller.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.resize(1400,768);
    w.show();

    return a.exec();
}
