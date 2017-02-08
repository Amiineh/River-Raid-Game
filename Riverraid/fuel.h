#ifndef FUEL_H
#define FUEL_H
#include<QObject>
#include<QGraphicsPixmapItem>

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QDebug>
#include <QString>
#include <QList>
#include <stdlib.h>
#include "player.h"

class Fuel: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Fuel();
    int getHitScore() const;
    void setHitScore(int value);
public slots:
    void move();
private:
    int hitScore;

};

#endif // FUEL_H
