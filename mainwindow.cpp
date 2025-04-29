#include "mainwindow.h"
#include "game_status.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , statusWidget(new game_status(this))
{
    setCentralWidget(statusWidget);

}
