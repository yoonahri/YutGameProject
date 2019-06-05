#ifndef YUTMANAGER_H
#define YUTMANAGER_H

#include "iostream"
#include "queue"
#include "ctime"
using namespace std;

class YutManager
{
private:
    static int probabilityOfYut[47];
    queue<int> result_of_yuts;

public:
    YutManager();
    void throwYut();
    void testThrowYut(int);
    void popYut();
    bool isEmpty();
    int getYutNum(int);
};

#endif // YUTMANAGER_H
