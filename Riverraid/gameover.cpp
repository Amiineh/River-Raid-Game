#include "gameover.h"
#include "ui_gameover.h"
#include "river.h"

extern River * river;
GameOver::GameOver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);
}

GameOver::~GameOver(){
    qDebug()<<"close game over ui";
    delete ui;
}

void GameOver::on_close_clicked(){
    qDebug()<< "click close";
    delete this;
}

void GameOver::on_try_again_clicked(){
    qDebug() << "Game start again";
    river = new River;
    river->show();
    delete this;
}
