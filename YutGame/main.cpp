#include "mainwindow.h"
#include <QApplication>
#include "gamemanager.h"
#include "board.h"
#include "gameevent.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    //������ input����, ���� ����
    int input_player = 3;
    int input_piece_num = 3;

    cout<<"gitingore file test";
    GameManager gm(input_player,input_piece_num);
    gm.gameStart();

    //git push test

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
