#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>
#include "bullet.h"
#include "enemy.h"
#include "fuel.h"
#include <QGraphicsScene>
#include"health.h"
#include <QGraphicsTextItem>

class Player: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    Health *getHealth() const;
    void setHealth(Health *value);

public slots:
    void Spawn();
        void decrease();
        void update();
private:
    Health * health;
    int speed;
};

#endif // PLAYER_H
