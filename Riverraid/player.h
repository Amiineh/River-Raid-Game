#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>

class Player: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent *event);
};

#endif // PLAYER_H
