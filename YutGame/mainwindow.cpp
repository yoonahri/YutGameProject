#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->player_num = firstscreen.getPlayerNum();
    this->piece_num = firstscreen.getPieceNum();

}

MainWindow::~MainWindow()
{
    delete ui;
}
