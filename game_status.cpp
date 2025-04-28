#include "game_status.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>

game_status::game_status(QWidget *parent)
    : QWidget(parent)
    , levelLabel(new QLabel(this))
    , startButton(new QPushButton("Start Game", this))
{

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(levelLabel,    0, Qt::AlignCenter);
    layout->addWidget(startButton,   0, Qt::AlignCenter);
    setLayout(layout);


    levelLabel->setText(QStringLiteral("Level: %1").arg(currentLevel));


    connect(this, &game_status::levelChanged, this, &game_status::updateLevelLabel);
    connect(startButton, &QPushButton::clicked, this, &game_status::on_startButton_clicked);
}

void game_status::startGame()
{
    currentLevel = 1;
    emit levelChanged(currentLevel);
    qDebug() << "Game started. Level =" << currentLevel;
}

void game_status::restartLevel()
{
    emit levelChanged(currentLevel);
    qDebug() << "Restart Level =" << currentLevel;
}

int game_status::getCurrentLevel() const
{
    return currentLevel;
}

void game_status::levelCompleted()
{
    ++currentLevel;
    emit levelChanged(currentLevel);
    qDebug() << "Level completed! New level =" << currentLevel;
}

void game_status::updateLevelLabel(int level)
{
    levelLabel->setText(QStringLiteral("Level: %1").arg(level));
}

void game_status::on_startButton_clicked()
{
    startGame();
}
