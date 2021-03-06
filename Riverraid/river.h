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
#include <QBrush>
#include <QImage>
#include "score.h"
#include "health.h"
#include <QObject>
#include "gameover.h"
#include "bridge.h"
#include <QList>

class River : public QGraphicsView{
public:
    const int shipHitScore = 30;
    const int helikopterHitScore = 60;
    const int jetHitScore = 100;
    const int balloonHitScore = 60;
    const int fuelHitScore = 150;
    const int maxFuel = 100;

    const int enemySpeedLevel[5] = {0, 10, 20, 30, 40};

    River(QWidget* parent = 0);
    ~River();
    QGraphicsScene *scene;
    Player *player;
    Score * score;
    Bridge * bridge;
    void Game_Over();
};

#endif // RIVER_H
