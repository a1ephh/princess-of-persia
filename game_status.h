#ifndef GAME_STATUS_H
#define GAME_STATUS_H

#include <QWidget>

class QLabel;
class QPushButton;
class QStackedLayout;

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
    void on_playButton_clicked();

private:
    // internal state
    int               currentLevel{1};

    // UI elements
    QStackedLayout   *stackLayout;
    QWidget          *startPage;
    QPushButton      *playButton;
    QWidget          *gamePage;
    QLabel           *levelLabel;
    QPushButton      *restartButton;
};

#endif // GAME_STATUS_H
