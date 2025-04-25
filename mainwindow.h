#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateLevelLabel(int level);

    void on_startButton_clicked();
    void on_nextLevelButton_clicked();

private:
    Ui::MainWindow *ui;
    game_status *gameStatus;
};
#endif // MAINWINDOW_H
