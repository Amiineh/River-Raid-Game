#include "river.h"

River::River(QWidget* parent)
{
    //creating a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 900, 600);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900, 600);
    //set background
    setBackgroundBrush(QBrush(QImage(":/pictures/background.jpg")));

    //create player
    player = new Player();
    player->setPixmap(QPixmap(":/pictures/player.jpg"));
    player->setScale(0.2);
    player->setPos(400,550);
    //make player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    //add player to scene
    scene->addItem(player);
    scene->addItem(player->getHealth());
    // create score
    score = new Score();
    scene->addItem(score);

    QTimer *timer_health = new QTimer();
    QObject::connect(timer_health,SIGNAL(timeout()), player, SLOT(decrease()));
    timer_health->start(200);

    // spawn enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()), player, SLOT(Spawn()));
    timer->start(2000);

    QTimer * timer_update_player = new QTimer();
    QObject::connect(timer_update_player,SIGNAL(timeout()), player, SLOT(update()));
    timer_update_player->start(50);
    show();
}
