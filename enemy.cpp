#include "characters.h"
#include "weapons.h"
#include "enemy.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>


Character::Character() {
    setRect(0,0,50,70);
    QPen greenPen(Qt::darkGreen);
    QBrush greenBrush(Qt::darkGreen);
    setPen(greenPen);
    setBrush(greenBrush);
}

bool isAlive::Character(){
    if (health>0) return true;
    else return false;
}


void keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_A){ //left
        if(x-10>=0){
            setPos(x()-10,y());
        }
    }
    if(event->key()==Qt::Key_D){ //right
        if(x+100<800){
            setPos(x()+10,y());
        }

    }
    if(event->key()==Qt::Key_W){ //up
        if(y<0){
            setPos(x(),y()-10);
        }

    }

    if(event->key()==Qt::Key_S){ //down
        if(y+10<600){
            setPos(x(),y()+10);
        }

    } /////// space, jump across, crouch, and attack isnt implemented
    if(event->key()==Qt::Key_Space){ //space only


    }
    if(event->key()==Qt::Key_W){ //space and left


    }
    if(event->key()==Qt::Key_W){ //space and right


    }
}


double getHealth::Character(){
    return health;
}

void setHealth::Character(double H){
    health=H;
    return;
}




