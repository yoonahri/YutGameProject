#include "firstscreen.h"
#include "ui_firstscreen.h"

FirstScreen::FirstScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FirstScreen)
{
    ui->setupUi(this);
}

FirstScreen::~FirstScreen()
{
    delete ui;
}

void FirstScreen::on_pushButton_start_clicked()
{
    player_num = ui->comboBox_player_num->currentText().toInt();
    piece_num = ui->comboBox_piece_num->currentText().toInt();
    this->hide();
    MainWindow * mainwindow = new MainWindow(this);
    mainwindow->setGameManager(player_num, piece_num);
    mainwindow->show();
}

