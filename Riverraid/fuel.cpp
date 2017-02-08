#include "fuel.h"

fuel::fuel() {
    score = 0;
    setPlainText("score:" + QString::number(score));
    setDefaultTextColor(Qt::black);
    setScale(2);
}

void Score::increase(int value){
    score += value;
    setPlainText("score:" + QString::number(score));
}
