#include "river.h"

River::River()
{
    //creating a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    SetFixedSize(800, 600);

    //create player
    player = new player();
    player->setRect(0,0,100,100);
    player->setPos(400,500);
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
