#ifndef RIVER_H
#define RIVER_H

#include <QtGui/QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "player.h"

class River {
    QGraphicsScene *scene;
    Player *player;
public:
    River();

};

#endif // RIVER_H
