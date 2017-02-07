#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QKeyEvent>
#include "bullet.h"
#include "enemy.h"
#include <QGraphicsScene>

class Player: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent *event);
public slots:
    void Spawn();
};

#endif // PLAYER_H
