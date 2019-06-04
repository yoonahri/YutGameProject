#include "mainwindow.h"
#include <QApplication>
#include "gamemanager.h"
#include "board.h"
#include "gameevent.h"
#include "firstscreen.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FirstScreen s;
    s.show();

    return a.exec();
}
