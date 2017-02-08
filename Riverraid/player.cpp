#include "player.h"

Player::Player()
{
    //draw graphic
   setPixmap(QPixmap(":/pictures/player.jpg"));
}

void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        if (pos().x() > 0)
            setPos(x() - 10, y());
    }
    else if (event->key() == Qt::Key_Right) {
        if (pos().x() + 100 < 800)
            setPos(x() + 10, y());
    }
    else if (event->key() == Qt::Key_Space) {
        // create bullet
        Bullet *bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
    }
}

void Player::Spawn(){
    int random_number = rand() % 4;
    Enemy *enemy = new Enemy(random_number+1);
    scene()->addItem(enemy);

    Fuel *fuel = new Fuel();
    scene()->addItem(fuel);
}
