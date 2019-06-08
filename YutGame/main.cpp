#include <QApplication>
#include "firstscreen.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FirstScreen s;
    s.show();

    return a.exec();
}
