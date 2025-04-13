#include "characters.h"
#include "weapons.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>


Character::Character() {

}

bool isAlive::Character(){
        if (health<=0) return true;
        else return false;
    }


void keyPressEvent(QKeyEvent *event)=0; // pure virtual thus class is abstract. add keypress event handling here in implementation
/*
+moveLeft(): void
+moveRight(): void
+jumpUp(): void
+jumpAcross(): void
+jumpClimb(): void
+crouch(): void
+attack(): void
*/




