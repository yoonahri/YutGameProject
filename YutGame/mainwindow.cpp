#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

void MainWindow::setGameManager(int player, int piece){
    this->player_num = player;
    this->piece_num = piece;
    this->gamemanager.setGameCondition(player, piece);

    //테스트용 라벨
    ui->label->setNum(player_num);
}

MainWindow::~MainWindow()
{
    delete ui;
}
