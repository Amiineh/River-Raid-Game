#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>
#include "bullet.h"
#include "enemy.h"
#include "fuel.h"
#include "bridge.h"
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

    int getLevel() const;

public slots:
    void Spawn_enemy();
    void Spawn_fuel();
    void Spawn_bridge();
    void decrease();
    void update();
    void level_up();
private:
    Health * health;
    int speed;
    int level = 0;
};

#endif // PLAYER_H
