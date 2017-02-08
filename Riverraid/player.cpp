#include "player.h"

Player::Player()
{
    //draw graphic
//   setPixmap(QPixmap(":/pictures/player.jpg"));
     health = new Health();
     speed = 0;
//   scene()->addItem(health);
//   health->setPos(0, 30);
}

void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        this->speed = -10;
    }
    else if (event->key() == Qt::Key_Right) {
        this->speed = 10;
    }
    else if (event->key() == Qt::Key_Space) {
        // create bullet
        Bullet *bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
    }
}

void Player::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left && this->speed < 0) {
        this->speed = 0;
    }
    else if (event->key() == Qt::Key_Right && this->speed > 0) {
        this->speed = 0;
    }}

void Player::Spawn_enemy(){
    int random_number = rand() % 4;
    Enemy *enemy = new Enemy(random_number+1);
    scene()->addItem(enemy);
}


void Player::Spawn_fuel(){
    Fuel *fuel = new Fuel();
    scene()->addItem(fuel);
}


Health *Player::getHealth() const
{
    return health;
}

void Player::setHealth(Health *value)
{
    health = value;
}


void Player::decrease(){
    health->decrease();
}

void Player::update(){
    qDebug()<<"update";
    if (190 < pos().x() + this->speed && pos().x() + this->speed < 700)
       setPos(x() + this->speed, y());
}
