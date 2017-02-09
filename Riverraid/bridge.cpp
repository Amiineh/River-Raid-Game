#include "bridge.h"
#include "river.h"

extern River* river;

Bridge::Bridge(): QObject(), QGraphicsPixmapItem(){
    QString pic_name = ":/pictures/bridge.png";
    setPixmap(QPixmap(pic_name));
    setScale(0.9);
    level++;
    qDebug() << "current level: " << level;
    setPos(0, 0);

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

}

void Bridge::move(){
//    QList<QGraphicsItem *> colliding_items = collidingItems();
//    for (int i = 0, n = colliding_items.size(); i < n; ++i ){
//        if(typeid(*(colliding_items[i])) == typeid(Player)){
//            // level up
//        }

//    }
    setPos(x(), y()+10);
    if(pos().y() > 398){
        scene()->removeItem(this);
        delete this;
    }
}

int Bridge::getLevel() const
{
    return level;
}

void Bridge::setLevel(int value)
{
    level = value;
}
