#include "bullet.h"
#include"river.h"
extern River * river;

Bullet::Bullet(): QObject(), QGraphicsRectItem(){
    //draw graphic
    setPixmap(QPixmap(":/pictures/bullet.jpg"));

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
