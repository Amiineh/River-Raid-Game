#ifndef BULLET
#define BULLET

#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "enemy.h"
#include <typeinfo>
#include <QDebug>

class Bullet: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Bullet();
public slots:
    void move();
};

#endif // BULLET
