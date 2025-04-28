#include "game_status.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QDebug>

game_status::game_status(QWidget *parent)
    : QWidget(parent)
{
    // --- Start Page ---
    startPage   = new QWidget(this);
    playButton  = new QPushButton(tr("Play"), startPage);
    auto *startLayout = new QVBoxLayout(startPage);
    auto *titleLabel  = new QLabel(tr("My Awesome Game"), startPage);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 32px; font-weight: bold;");
    startLayout->addStretch();
    startLayout->addWidget(titleLabel);
    startLayout->addSpacing(20);
    startLayout->addWidget(playButton, 0, Qt::AlignCenter);
    startLayout->addStretch();

    connect(playButton, &QPushButton::clicked,
            this, &game_status::on_playButton_clicked);

    // --- Game Page ---
    gamePage      = new QWidget(this);
    levelLabel    = new QLabel(gamePage);
    restartButton = new QPushButton(tr("Restart Level"), gamePage);
    auto *gameLayout = new QVBoxLayout(gamePage);
    levelLabel->setAlignment(Qt::AlignCenter);
    levelLabel->setText(QStringLiteral("Level: %1").arg(currentLevel));
    gameLayout->addWidget(levelLabel);
    gameLayout->addWidget(restartButton, 0, Qt::AlignCenter);

    connect(restartButton, &QPushButton::clicked,
            this, &game_status::restartLevel);

    connect(this, &game_status::levelChanged,
            this, &game_status::updateLevelLabel);

    // --- Stacked Layout to switch pages ---
    stackLayout = new QStackedLayout(this);
    stackLayout->addWidget(startPage); // index 0
    stackLayout->addWidget(gamePage);  // index 1
    setLayout(stackLayout);
}

void game_status::on_playButton_clicked()
{
    // Switch to game page and start at level 1
    stackLayout->setCurrentIndex(1);
    startGame();
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
    qDebug() << "Restarting level =" << currentLevel;
}

int game_status::getCurrentLevel() const
{
    return currentLevel;
}

void game_status::levelCompleted()
{
    ++currentLevel;
    emit levelChanged(currentLevel);
    qDebug() << "Completed! New level =" << currentLevel;
}

void game_status::updateLevelLabel(int level)
{
    levelLabel->setText(QStringLiteral("Level: %1").arg(level));
}

void game_status::on_startButton_clicked()
{
    // not used anymore—left for backward compatibility
    on_playButton_clicked();
}
