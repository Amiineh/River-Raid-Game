#include "health.h"
#include <QDebug>

Health::Health(QGraphicsItem* parent): QGraphicsTextItem(parent)
{
    amount = 100;
    setPlainText("health:" + QString::number(amount));
    setDefaultTextColor(Qt::red);
    setScale(2);
    setPos(0,20);
//    setFont(QFont("times", 16));
}

void Health::decrease(){
    qDebug() << "decrease";
    amount-=1;
    setPlainText("health:" + QString::number(amount));
//    if(getAmount() <= 0){
//        delete this;
//    }
}

void Health::fill(){
    setAmount(100);
    setPlainText("health:" + QString::number(amount));

}

int Health::getAmount() const
{
    return amount;
}

void Health::setAmount(int value)
{
    amount = value;
    setPlainText("health:" + QString::number(amount));

}
