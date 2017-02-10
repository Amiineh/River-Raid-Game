#include "bridge.h"
#include "river.h"

extern River* river;

Bridge::Bridge(): QObject(), QGraphicsPixmapItem(){

    QString pic_name = ":/pictures/bridge.png";
    setPixmap(QPixmap(pic_name));
    setScale(0.9);
    level++;

    setPos(0, 0);

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

}

void Bridge::move(){

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i ){
        if(typeid(*(colliding_items[i])) == typeid(Player)){
            river->player->level_up();
            scene()->removeItem(this);
            qDebug()<<"player hit bridge";
            delete this;
        }
    }

    setPos(x(), y()+10);
}

int Bridge::getLevel() const{
    return level;
}

void Bridge::setLevel(int value){
    level = value;
}

Bridge::~Bridge(){
    qDebug()<<"delete bridge";
}
