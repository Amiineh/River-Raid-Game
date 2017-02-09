#ifndef BRIDGE_H
#define BRIDGE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>

class Bridge: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    Bridge();
    int getLevel() const;
    void setLevel(int value);

public slots:
    void move();

private:
    int level = 1;

};

#endif // BRIDGE_H
