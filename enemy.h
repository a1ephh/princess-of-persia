#ifndef ENEMY_H
#define ENEMY_H
class Enemy: public Character { Q_OBJECT

private:

public:
    Enemy();
    bool isAlive();
    double getHealth();
    void setHealth(double);

public slots:
    void keyPressEvent(QKeyEvent * event) override;
};


#endif // ENEMY_H
