#ifndef FUEL_H
#define FUEL_H

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
#include "river.h"

extern River* river;

class Fuel: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Fuel(int Number);
    int getHitScore() const;
    void setHitScore(int value);

public slots:
    void move();
private:
    int hitScore;
};

#endif // FUEL_H
