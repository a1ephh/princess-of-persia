#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class game_status;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;

private:
    game_status *statusWidget;
};

#endif // MAINWINDOW_H
