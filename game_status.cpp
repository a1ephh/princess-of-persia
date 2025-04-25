#include "game_status.h"
#include <QDebug>

game_status::game_status(QObject *parent) : QObject(parent), currentLevel(1) {}

void game_status::startGame() {
    currentLevel = 1;
    emit levelChanged(currentLevel);
    qDebug() << "Game started. Current level:" << currentLevel;
}

void game_status::restartLevel() {
    emit levelChanged(currentLevel);
    qDebug() << "Restarting Level" << currentLevel;
}

int game_status::getCurrentLevel() const {
    return currentLevel;
}

void game_status::nextLevel() {
    currentLevel++;
    emit levelChanged(currentLevel);
    qDebug() << "Proceeding to Level" << currentLevel;
}
