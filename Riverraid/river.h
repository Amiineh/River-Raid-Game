#ifndef RIVER_H
#define RIVER_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include <QTimer>
#include <QWidget>

class River : public QGraphicsView{
public:
    River(QWidget* parent = 0);
    QGraphicsScene *scene;
    Player *player;
};

#endif // RIVER_H
