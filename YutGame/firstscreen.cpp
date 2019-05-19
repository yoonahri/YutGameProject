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

void FirstScreen::setGameManager(){
    this->main_game_manager.setGameCondition(player_num, piece_num);
}

void FirstScreen::on_pushButton_start_clicked()
{
    player_num = ui->comboBox_player_num->currentText().toInt();
    piece_num = ui->comboBox_piece_num->currentText().toInt();
    setGameManager();

}

int FirstScreen::getPlayerNum(){
    return player_num;
}

int FirstScreen::getPieceNum(){
    return piece_num;
}
