#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
#include <iostream>

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

    //�׽�Ʈ�� ����
    ui->label->setNum(player_num);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_throwButton_clicked()
{
    //throw possible 할 때 + 눌렀을 때
    if(gamemanager.getIsThrowPossible()){
        this->gamemanager.throwYut();
    }
    else {
        cout << "cannot throw yut" << endl;
    }
}

void MainWindow::on_Location0_clicked() //0번을 출발지로 놓고 테스트햇는데 바꿔야 함
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(0);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(0);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location1_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(1);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(1);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location2_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(2);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(2);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}


void MainWindow::on_Location3_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(3);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(3);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location4_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(4);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(4);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location5_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(5);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(5);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location6_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(6);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(6);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}


void MainWindow::on_Location7_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(7);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(7);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location8_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(8);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(8);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location9_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(9);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(9);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location10_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(10);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(10);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location11_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(11);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(11);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location12_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(12);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(12);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location13_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(13);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(13);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location14_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(14);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(14);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location15_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(15);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(15);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location16_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(16);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(16);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location17_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(17);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(17);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location18_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(18);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(18);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location19_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(19);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(19);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location20_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(20);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(20);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location21_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(21);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(21);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location22_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(22);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(22);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location23_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(23);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(23);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location24_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(24);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(24);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location25_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(25);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(25);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location26_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(26);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(26);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location28_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(28);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(28);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}

void MainWindow::on_Location29_clicked()
{
    if(this->gamemanager.getInitBoardClickable()){
        this->gamemanager.setInitBoard(29);
    }
    else if(this->gamemanager.getDestBoardClickable()){
        this->gamemanager.setDestBoard(29);
    }
    else {
        cout << "cannot click this btn" << endl;
    }
}
