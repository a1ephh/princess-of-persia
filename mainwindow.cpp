#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gameStatus = new game_status(this);

    connect(gameStatus, &game_status::levelChanged,
            this, &MainWindow::updateLevelLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateLevelLabel(int level) {
    qDebug() << "Label update called with level:" << level;
    ui->levelLabel->setText("Level: " + QString::number(level));
}

void MainWindow::on_startButton_clicked() {
    gameStatus->startGame();
}

// void MainWindow::on_restartButton_clicked() {
//     gameStatus->restartLevel();
// }


// void MainWindow:: {

//     if (character->isAlive) {
//         gameStatus->levelCompleted();
//
// }
// will be implemented when we work on level two

