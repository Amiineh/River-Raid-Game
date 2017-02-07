#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QDebug>
#include "player.h"
#include <QString>

Enemy::Enemy(int Number): QObject(), QGraphicsPixmapItem(){
    QString str;
    str.setNum(Number);
    QString pic_name = ":/pictures/enemy_" + str + ".jpg";
    setPixmap(QPixmap(pic_name));
    setScale(0.3);
    qDebug() << "create enemy";
    int random_number = rand() % 700;
    setPos(random_number, 0);

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

}

void Enemy::move(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i ){
        if(typeid(*(colliding_items[i])) == typeid(Player)){
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            qDebug()<<"delete";
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    qDebug() << "move enemy";
    setPos(x(), y()+10);
    if(pos().y() > 600){
        scene()->removeItem(this);
//        qDebug
        delete this;
    }

}
int Enemy::getHit_score() const
{
    return hitScore;
}

void Enemy::setHit_score(int value)
{
    hitScore = value;
}


int Enemy::get_type(){
    return this->type;
}
