#ifndef CHARACTERS_H
#define CHARACTERS_H
#include <QGraphicsItem>
#include <QObject>


class Character: public QObject virtual { Q_OBJECT // characters is a virtual class

private:
    double health;
    // should the position of the character be an attribute as well?
public:
    Character();
    bool isAlive();
    double getHealth();
    void setHealth(double);

public slots:
    void keyPressEvent(QKeyEvent * event);
};


#endif // CHARACTERS_H



