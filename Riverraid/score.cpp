#include "score.h"

Score::Score(QGraphicsItem* parent): QGraphicsTextItem(parent){
    score = 0;
    setPlainText("score:" + QString::number(score));
    setDefaultTextColor(Qt::black);
    setScale(2);
    setPos(350,520);
//    setFont(QFont("times", 16));
}

void Score::increase(int value){
    score += value;
    setPlainText("score:" + QString::number(score));
}

int Score::getScore() const
{
    return score;
}

void Score::setScore(int value)
{
    score = value;
}
