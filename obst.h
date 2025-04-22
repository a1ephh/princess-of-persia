#ifndef OBST_H
#define OBST_H
#include <QGraphicsPixmapItem>
#include <QTimer>
class Obst : public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

public:
    enum ObstacleType { Spike, Blade };
    Obst(QString imagePath, QGraphicsItem *parent = nullptr);
    void setType(ObstacleType type);
    ObstacleType getType() const;
    void enableAnimation(bool enable = true);

signals:
    void playerHit();

private slots:
    void animate();

private:
    ObstacleType type;
    QTimer *animationTimer;
    QList<QPixmap> frames;
    int currentFrame;
};


#endif // OBST_H
