#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "board.h"
#include "gameevent.h"
#include "ctime"

class GameManager
{
private:
    int num_of_player;
    int num_of_piece;
    int curr_turn;
    vector<int> result_of_yuts;
    Board board;
    GameEvent gameevent;
public:
    GameManager();
    void setGameCondition(int, int);
    void gameStart();
    void turnChanger();
    void throwYut();
};

#endif // GAMEMANAGER_H
