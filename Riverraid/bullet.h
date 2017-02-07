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
#include "score.h"

class Bullet: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Bullet();
    int hit();
public slots:
    void move();
};

#endif // BULLET
