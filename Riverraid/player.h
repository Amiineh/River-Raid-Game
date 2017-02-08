#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>
#include "bullet.h"
#include "enemy.h"
//#include "fuel.h"
#include <QGraphicsScene>
#include"health.h"
#include <QGraphicsTextItem>

class Player: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent *event);
    Health *getHealth() const;
    void setHealth(Health *value);

public slots:
    void Spawn();
        void decrease();
private:
    Health * health;
};

#endif // PLAYER_H
