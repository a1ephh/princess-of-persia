#ifndef GAME_STATUS_H
#define GAME_STATUS_H

#include <QObject>

class game_status : public QObject {
    Q_OBJECT

private:
    int currentLevel;

public:
    explicit game_status(QObject *parent = nullptr);

    void startGame();
    void restartLevel();
    int getCurrentLevel() const;
    void nextLevel();
    void levelCompleted();

signals:
    void levelChanged(int newLevel);
};

#endif
