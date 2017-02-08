#include "fuel.h"
#include "river.h"

extern River* river;

Fuel::Fuel(): QObject(), QGraphicsPixmapItem(){
    QString pic_name = ":/pictures/fuel.jpg";
    setPixmap(QPixmap(pic_name));
    setScale(0.3);
    this->setHitScore(river->fuelHitScore);
    int random_number = rand() % 700;
    setPos(random_number, 0);

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

}

void Fuel::move(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i ){
        if(typeid(*(colliding_items[i])) == typeid(Bullet)){
            river->score->increase(this->hitScore);
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
        if(typeid(*(colliding_items[i])) == typeid(Player)){
//            scene()->health->fill();
            scene()->removeItem(this);
            delete this;
            return;
        }

    }
    setPos(x(), y()+10);
    if(pos().y() > 600){
        scene()->removeItem(this);
        delete this;
    }
}

int Fuel::getHitScore() const
{
    return hitScore;
}

void Fuel::setHitScore(int value)
{
    hitScore = value;
}
