#ifndef BULLET
#define BULLET

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "enemy.h"
#include <typeinfo>
#include <QDebug>
#include "score.h"
<<<<<<< HEAD
#include <QGraphicsPixmapItem>
=======

>>>>>>> master
class Bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet();
    int hit();
public slots:
    void move();
};

#endif // BULLET
