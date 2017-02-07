#include "river.h"
River::River(QWidget* parent)
{
    //creating a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

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

    // create score
    score = new Score();
    scene->addItem(score);

    // spawn enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()), player, SLOT(Spawn()));
    timer->start(2000);

    show();
}
