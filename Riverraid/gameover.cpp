#include "gameover.h"
#include "ui_gameover.h"
#include "river.h"

GameOver::GameOver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);
}

GameOver::~GameOver()
{
    delete ui;
}

void GameOver::on_close_clicked()
{
    delete this;
}

void GameOver::on_try_again_clicked()
{
    River *river = new River;
    river->show();
}
