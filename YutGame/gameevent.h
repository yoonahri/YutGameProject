#ifndef GAMEEVENT_H
#define GAMEEVENT_H
#include "board.h"


class GameEvent
{
private:
    Board board;
    vector<vector<vector<int>>> movable_pos;

public:
    GameEvent();
    bool IsMovablePos(int, int, int);
    void highlightMovablePos(int, int);
};

#endif // GAMEEVENT_H
