#ifndef GAME_STATUS_H
#define GAME_STATUS_H

#include <QWidget>

class QLabel;
class QPushButton;
class QVBoxLayout;

class game_status : public QWidget
{
    Q_OBJECT

public:
    explicit game_status(QWidget *parent = nullptr);
    ~game_status() override = default;

    void startGame();
    void restartLevel();
    int  getCurrentLevel() const;
    void levelCompleted();

signals:
    void levelChanged(int newLevel);

private slots:
    void updateLevelLabel(int level);
    void on_startButton_clicked();

private:
    int            currentLevel{1};
    QLabel        *levelLabel;
    QPushButton   *startButton;
};

#endif // GAME_STATUS_H
