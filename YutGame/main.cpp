#include "mainwindow.h"
#include <QApplication>
#include "gamemanager.h"
#include "board.h"
#include "gameevent.h"
#include "firstscreen.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    //������ input����, ���� ����
    int input_player = 3;
    int input_piece_num = 3;

    //GameManager gm(input_player,input_piece_num);
    //gm.gameStart();

    QApplication a(argc, argv);
    FirstScreen s;
    s.show();

    return a.exec();
}
