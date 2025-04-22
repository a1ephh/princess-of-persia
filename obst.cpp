#include "obst.h"

Obst::Obst(QString imagePath, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), currentFrame(0) {

    setPixmap(QPixmap(imagePath));

    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &Obst::animate);
}

void Obst::setType(ObstacleType t) {
    type = t;
}

Obst::ObstacleType Obst::getType() const {
    return type;
}

void Obst::enableAnimation(bool enable) {
    if (enable) {
        frames = {
            QPixmap(":/sprites/blade1.png"),
            QPixmap(":/sprites/blade2.png"),
            QPixmap(":/sprites/blade3.png"),
            QPixmap(":/sprites/blade4.png")
        };
        animationTimer->start(100);
    } else {
        animationTimer->stop();
    }
}

void Obst::animate() {
    if (frames.isEmpty()) return;
    currentFrame = (currentFrame + 1) % frames.size();
    setPixmap(frames[currentFrame]);
}


