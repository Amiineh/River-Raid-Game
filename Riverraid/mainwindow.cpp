#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "river.h"
River * river;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startgame_clicked()
{
    river = new River();
    river->show();
    hide();
}
