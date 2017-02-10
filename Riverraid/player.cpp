#include "player.h"
#include "river.h"

extern River* river;

Player::Player(){
    qDebug()<<"Add Player";
    //draw graphic
     health = new Health();
     speed = 0;
}

void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        qDebug()<<"Press left key";
        this->speed = -10;
    }
    else if (event->key() == Qt::Key_Right) {
        qDebug()<<"Press right key";
        this->speed = 10;
    }
    else if (event->key() == Qt::Key_Space) {
        qDebug()<<"Press space key";
        // create bullet
        Bullet *bullet = new Bullet();
        bullet->setPos(x() + 18, y());
        scene()->addItem(bullet);
    }
}

void Player::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left && this->speed < 0) {
        this->speed = 0;
    }
    else if (event->key() == Qt::Key_Right && this->speed > 0) {
        this->speed = 0;
    }
}

void Player::Spawn_enemy(){
    int random_number = rand() % 4;
    Enemy *enemy = new Enemy(random_number+1, river->enemySpeedLevel[level]);
    qDebug()<<"Add enemy";
    scene()->addItem(enemy);
}


void Player::Spawn_fuel(){
    qDebug()<<"Add fuel";
    Fuel *fuel = new Fuel();
    scene()->addItem(fuel);
}

void Player::Spawn_bridge(){
    qDebug()<<"Add bridge";
    if(level < 6){
        Bridge * bridge = new Bridge();
        scene()->addItem(bridge);
    }
}


Health *Player::getHealth() const{
    return health;
}

void Player::setHealth(Health *value){
    health = value;
}


void Player::decrease(){
    health->decrease();
}

void Player::update(){
    if (100 < pos().x() + this->speed && pos().x() + this->speed < 660)
       setPos(x() + this->speed, y());
    else {
        scene()->removeItem(this);
        river->Game_Over();
        delete this;
        return;
    }
}

int Player::getLevel() const{
    return level;
}

void Player::level_up(){
    qDebug()<< "Level up";
    if(level < 5)
        level += 1;
    // spawn enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()), this, SLOT(Spawn_enemy()));
    timer->start(2000-level*100);

}

Player::~Player(){
    qDebug()<<"Delete player";
    delete health;
}
