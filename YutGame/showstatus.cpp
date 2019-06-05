#include "showstatus.h"

ShowStatus::ShowStatus()
{

}

/*void ShowStatus::createPiece(){

    for(int i = 0; i<4; i++){
        for(int j = 0; j<5; j++){
            ui->gridLayout->itemAtPosition(i, j)->widget()->hide();
        }
    }

    for(int i = 0 ; i<player_num ; i++){
        for(int j = 0 ; j < piece_num ; j++){
            ui->gridLayout->itemAtPosition(i, j)->widget()->show();
        }
    }
}

void ShowStatus::createScoreBoard(){

    for(int i =0 ; i<8; i++){
        ui->horizontalLayout_score->itemAt(i)->widget()->hide();
    }
    for(int i= 0 ; i <player_num*2;i++){
        ui->horizontalLayout_score->itemAt(i)->widget()->show();
    }
}

void ShowStatus::showTurn(){

    switch(gamemanager.getTurn()){
    case 0:
        ui->label_turn->setStyleSheet("border-image: url(:red.png);");
        break;
    case 1:
        ui->label_turn->setStyleSheet("border-image: url(:orange.png);");
        break;
    case 2:
        ui->label_turn->setStyleSheet("border-image: url(:green.png);");
        break;
    case 3:
        ui->label_turn->setStyleSheet("border-image: url(:blue.png);");
        break;
    }
}

void ShowStatus::showScore(){

    QVector<QLabel *> score_label_list;
    score_label_list.push_back(ui->label_score1);
    score_label_list.push_back(ui->label_score2);
    score_label_list.push_back(ui->label_score3);
    score_label_list.push_back(ui->label_score4);

    for(int i = 0 ; i < gamemanager.getBoardStatus(29).size() ; i++ ){
        score_label_list[i]->setNum(gamemanager.getBoardStatus(29)[i]);
    }
}*/
