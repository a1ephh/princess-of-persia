#include "mainwindow.h"
#include <QApplication>
#include "obst.h"
#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create MainWindow
    MainWindow w;
    w.show();

    // Set up scene and view
    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsView* view = new QGraphicsView(scene);
    view->setFixedSize(800, 600);
    scene->setSceneRect(0, 0, 800, 600);

    // Example use: create obstacle
    Obst* spike = new Obst(":/sprites/spike.png");
    spike->setType(Obst::Spike);
    spike->setPos(200, 300);
    scene->addItem(spike);

    view->show();

    // Create an obstacle
    Obst* bladeObstacle = new Obst(":/sprites/blade1.png");
    bladeObstacle->setType(Obst::Blade);
    bladeObstacle->enableAnimation(true);
    bladeObstacle->setPos(300, 150);
    scene->addItem(bladeObstacle);

    Obst* spikeObstacle = new Obst(":/sprites/spike.png");
    spikeObstacle->setType(Obst::Spike);
    spikeObstacle->setPos(500, 400);
    scene->addItem(spikeObstacle);

    return a.exec();
}
