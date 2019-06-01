#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    buttonList.push_back(ui->Location0);
    buttonList.push_back(ui->Location1);
    buttonList.push_back(ui->Location2);
    buttonList.push_back(ui->Location3);
    buttonList.push_back(ui->Location4);
    buttonList.push_back(ui->Location5);
    buttonList.push_back(ui->Location6);
    buttonList.push_back(ui->Location7);
    buttonList.push_back(ui->Location8);
    buttonList.push_back(ui->Location9);
    buttonList.push_back(ui->Location10);
    buttonList.push_back(ui->Location11);
    buttonList.push_back(ui->Location12);
    buttonList.push_back(ui->Location13);
    buttonList.push_back(ui->Location14);
    buttonList.push_back(ui->Location15);
    buttonList.push_back(ui->Location16);
    buttonList.push_back(ui->Location17);
    buttonList.push_back(ui->Location18);
    buttonList.push_back(ui->Location19);
    buttonList.push_back(ui->Location20);
    buttonList.push_back(ui->Location21);
    buttonList.push_back(ui->Location22);
    buttonList.push_back(ui->Location23);
    buttonList.push_back(ui->Location24);
    buttonList.push_back(ui->Location25);
    buttonList.push_back(ui->Location26);
    buttonList.push_back(ui->Location28);
    buttonList.push_back(ui->Location29);
    buttonList.push_back(ui->Locationgoal);
    ui->label_turn->setStyleSheet("border-image: url(:red.png);");
    ui->label_3->hide();
    getBoardLocationNum();

}

void MainWindow::setGameManager(int player, int piece){
    this->player_num = player;
    this->piece_num = piece;
    this->gamemanager.setGameCondition(player, piece);
}

void MainWindow::createPiece(){
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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getBoardLocationNum(){


    for (int i = 0; i < buttonList.size(); i++) {
        QPushButton* button = buttonList[i];
        connect(button, &QPushButton::clicked, [this, button, i](){
            if(this->gamemanager.getInitBoardClickable(i)){
                this->gamemanager.setInitBoard(i);
                this->highlightMovablePos(this->gamemanager.getYutNum(), i, true);
                this->init_board = i;
                button->setText("");
                if(i == 0 || i == 5 || i == 10 || i == 15 || i == 22){
                    button->setStyleSheet("border-image: url(:doublecircle.png);");
                }
                else{
                    button->setStyleSheet("border-image: url(:circle.png);");
                }
            }
            else if(this->gamemanager.getDestBoardClickable(i)){
                this->highlightMovablePos(this->gamemanager.getYutNum(), this->init_board, false);
                this->movePiece(i, this->init_board);
                this->gamemanager.setDestBoard();
                this->showTurn();

            }
            else {
                cout << "cannot click this btn" << endl;
            }
        });
    }
}

void MainWindow::highlightMovablePos(int num_of_yut, int clicked_board, bool visible) {

    if(visible){
        for(size_t m = 0 ; m < gamemanager.getMovablePos(clicked_board,num_of_yut).size() ; m++){
            buttonList[gamemanager.getMovablePos(clicked_board,num_of_yut)[m]]->setText("");
            buttonList[gamemanager.getMovablePos(clicked_board,num_of_yut)[m]]->setStyleSheet("border-image: url(:highlightcircle.png);");
        }

    }

    else{
        for(size_t m = 0 ; m < gamemanager.getMovablePos(clicked_board, num_of_yut).size() ; m++){
            int i = gamemanager.getMovablePos(clicked_board,num_of_yut)[m];
            bool isEmpty = true;
            size_t existedPiece = 10;
            for(size_t j = 0 ; j < gamemanager.getBoardStatus(i).size() ; j++ ){
                if(gamemanager.getBoardStatus(i)[j] != 0){
                    cout<<gamemanager.getBoardStatus(i)[j]<<endl;
                    isEmpty = false;
                    existedPiece = j;
                    break;
                }
                else{
                    isEmpty  = true;
                }
            }
            if(isEmpty){
                if(i == 0 || i == 5 || i == 10 || i == 15 || i == 22){
                    buttonList[i]->setStyleSheet("border-image: url(:doublecircle.png);");
                }
                else{
                    buttonList[i]->setStyleSheet("border-image: url(:circle.png);");
                }
            }
            else{
                switch(existedPiece){
                case 0:
                    buttonList[i]->setStyleSheet("border-image: url(:red.png);");
                    break;
                case 1:
                    buttonList[i]->setStyleSheet("border-image: url(:orange.png);");
                    break;
                case 2:
                    buttonList[i]->setStyleSheet("border-image: url(:green.png);");
                    break;
                case 3:
                    buttonList[i]->setStyleSheet("border-image: url(:blue.png);");
                    break;
                }
                buttonList[i]->setText(QString::number(this->gamemanager.getBoardStatus(i)[existedPiece]));
            }
        }
    }
}

void MainWindow::movePiece(int clicked_piece, int init_piece){

    if(clicked_piece != 29){
        switch(gamemanager.getTurn()){
        case 0:
            buttonList[clicked_piece]->setStyleSheet("border-image: url(:red.png);");
            break;
        case 1:
            buttonList[clicked_piece]->setStyleSheet("border-image: url(:orange.png);");
            break;
        case 2:
            buttonList[clicked_piece]->setStyleSheet("border-image: url(:green.png);");
            break;
        case 3:
            buttonList[clicked_piece]->setStyleSheet("border-image: url(:blue.png);");
            break;
        }
        if(init_piece != 0){

            if(gamemanager.getBoardPiece(init_piece) > 1){
                buttonList[clicked_piece]->setText(QString::number(this->gamemanager.getBoardPiece(init_piece)));
            }
        }

        if(gamemanager.getBoardPiece(clicked_piece) >=1){

            if(init_piece == 0){
                buttonList[clicked_piece]->setText(QString::number(1 + this->gamemanager.getBoardPiece(clicked_piece)));
            }
            else{
                buttonList[clicked_piece]->setText(QString::number(this->gamemanager.getBoardPiece(init_piece)
                                                                   + this->gamemanager.getBoardPiece(clicked_piece)));
            }
        }

        for(size_t i = 0 ; i < gamemanager.getBoardStatus(clicked_piece).size() ; i++ ){
            if(gamemanager.getBoardStatus(clicked_piece)[i] != 0 && gamemanager.getTurn() != i){
                ui->label_3->show();
                ui->gridLayout->itemAtPosition(i, (gamemanager.getBoardStatus(clicked_piece)[i]+gamemanager.getBoardStatus(0)[i])-1)->widget()->show();
            }

        }
    }
}



void MainWindow::on_throwButton_clicked()
{
    if(gamemanager.getIsThrowPossible()){
        this->gamemanager.throwYut();

        switch (this->gamemanager.getBackYutNum()) {
        case 0:
            ui->label_3->hide();
            ui->label->setStyleSheet("border-image: url(:pig1.png);");
            break;
        case 1:
            ui->label_3->hide();
            ui->label->setStyleSheet("border-image: url(:pig.png);");
            break;
        case 2:
            ui->label_3->hide();
            ui->label->setStyleSheet("border-image: url(:dog.png);");
            break;
        case 3:
            ui->label_3->hide();
            ui->label->setStyleSheet("border-image: url(:sheep.png);");
            break;
        case 4:
            ui->label->setStyleSheet("border-image: url(:cow.png);");
            ui->label_3->show();
            break;
        case 5:
            ui->label->setStyleSheet("border-image: url(:horse.png);");
            ui->label_3->show();
            break;
        }

    }
    else {
        cout << "cannot throw yut" << endl;
    }
}


void MainWindow::on_testButton_clicked()
{
    if(gamemanager.getIsThrowPossible()){

        gamemanager.testThrowYut(this->ui->testYutBox->currentIndex());

        switch (this->gamemanager.getBackYutNum()) {
        case 0:
            ui->label->setStyleSheet("border-image: url(:pig1.png);");
            break;
        case 1:
            ui->label->setStyleSheet("border-image: url(:pig.png);");
            break;
        case 2:
            ui->label->setStyleSheet("border-image: url(:dog.png);");
            break;
        case 3:
            ui->label->setStyleSheet("border-image: url(:sheep.png);");
            break;
        case 4:
            ui->label->setStyleSheet("border-image: url(:cow.png);");
            break;
        case 5:
            ui->label->setStyleSheet("border-image: url(:horse.png);");
            break;
        }
    }
    else {
        cout << "cannot throw yut" << endl;
    }
}

void MainWindow::on_Location0_clicked()
{
    ui->gridLayout->itemAtPosition(gamemanager.getTurn(),gamemanager.getBoardPiece(0)-1)->widget()->hide();
}

void MainWindow::showTurn()
{
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


