#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // hello this is a comment
    // hellooooo
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
