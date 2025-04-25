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
    ui->levelLabel->setText("Level: " + QString::number(level));
}

void MainWindow::on_startButton_clicked() {
    gameStatus->startGame();
}

void MainWindow::on_nextLevelButton_clicked() {
    gameStatus->nextLevel();
}
