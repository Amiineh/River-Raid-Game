#ifndef ENEMY
#define ENEMY

#include <QObject>
#include<QGraphicsPixmapItem>
enum Enemys {balloon, jet, ship, helikopter};

class Enemy: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy(int Number);
    int get_type();
    int getHit_score() const;
    void setHit_score(int value);

public slots:
    void move();
private:
    int type;
    int hitScore;
};

#endif // ENEMY
