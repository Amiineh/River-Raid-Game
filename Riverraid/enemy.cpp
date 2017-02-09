#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QDebug>
#include "player.h"
#include <QString>
#include "river.h"

extern River* river;

Enemy::Enemy(int Number): QObject(), QGraphicsPixmapItem(){

    QString str;
    str.setNum(Number);
    QString pic_name = ":/pictures/enemy_" + str + ".png";
    setPixmap(QPixmap(pic_name));
    setScale(0.3);

    switch (Number) {
    case 1:
        this->setHit_score(river->helikopterHitScore);
        break;
    case 2:
        this->setHit_score(river->shipHitScore);
        break;
    case 3:
        this->setHit_score(river->balloonHitScore);
        break;
    case 4:
        this->setHit_score(river->jetHitScore);
        break;
    }

    qDebug() << "create enemy";
    int random_number = rand() % 550;
    setPos(random_number+100, 0);

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

}

void Enemy::move(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i ){
        if(typeid(*(colliding_items[i])) == typeid(Bullet)){
            river->score->increase(this->getHit_score());
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            qDebug()<<"delete enemy and bullet";
            delete colliding_items[i];
            delete this;
            return;
        }
        if(typeid(*(colliding_items[i])) == typeid(Player)){
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            qDebug()<<"delete player";
            delete colliding_items[i];
            river->Game_Over();
            delete this;
            return;
        }

    }
    qDebug() << "move enemy";
    setPos(x(), y()+10+2*river->player->getLevel());
    if(pos().y() > 400){
        scene()->removeItem(this);
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
