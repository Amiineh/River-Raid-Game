#include "enemy.h"
#include <QTime>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

Enemy::Enemy(): QObject(), QGraphicsRectItem(){
    int random_number = rand() % 700;
    setPos(random_number, 0);

    setRect(0,0,0,0);
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

}

void Enemy::move(){
    setPos(x(), y()+10);
    if(pos.y()+ rect().height() < 0)
        scene()->removeItem(this);
        delete this;

}

