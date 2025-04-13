#include "mainwindow.h"

#include <QApplication>
#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QString>

class Obstacle {
private:
    QString name;
    bool lethal;
    bool solid;

public:
    // Constructor
    Obstacle(QString name, bool lethal, bool solid)
        : name(name), lethal(lethal), solid(solid) {}

    // Getters
    QString getName() const { return name; }
    bool isLethal() const { return lethal; }
    bool isSolid() const { return solid; }

    // Setters (if needed)
    void setName(QString n) { name = n; }
    void setLethal(bool l) { lethal = l; }
    void setSolid(bool s) { solid = s; }

    // Example behavior method
    QString interact() const {
        if (lethal)
            return "You died!";
        else if (solid)
            return "You can't pass!";
        else
            return "You pass safely.";
    }
};

#endif // OBSTACLE_H

int main(int argc, char *argv[])
{
    // hello this is a comment
    // hellooooo
    //janna was here
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    //jana
}
