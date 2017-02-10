#include "health.h"
#include <QDebug>
#include "river.h"
extern River* river;

Health::Health(QGraphicsItem* parent): QGraphicsTextItem(parent){
    amount = 100;
    setPlainText("health:" + QString::number(amount));
    setDefaultTextColor(Qt::green);
    setScale(2);
    setPos(260,450);
}

void Health::decrease(){
    if(getAmount() > 0)
        amount-=1;
    //\qDebug()<<"Your heath is"<<amount;
    setPlainText("health:" + QString::number(amount));
    if(getAmount() == 0){
        river->Game_Over();
    }
}

void Health::fill(){
    setAmount(100);
    qDebug()<<"Your health full";
    setPlainText("health: " + QString::number(amount));

}

int Health::getAmount() const{
    return amount;
}

void Health::setAmount(int value){
    amount = value;
    setPlainText("health: " + QString::number(amount));

}

Health::~Health(){
    qDebug()<<"Delete health";
}
