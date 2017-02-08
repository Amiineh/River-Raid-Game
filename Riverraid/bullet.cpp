#include "bullet.h"
#include"river.h"
extern River * river;

Bullet::Bullet(): QObject(), QGraphicsRectItem(){
    int random_number = rand() % 700;
    setPos(random_number, 0);

    setRect(0,0,10, 10);
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bullet::move(){
    setPos(x(), y() - 10);
    if(pos().y()+ rect().height() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}

int Bullet::hit(){
    return 10;
}
