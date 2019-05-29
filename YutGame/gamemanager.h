#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "board.h"
#include "gameevent.h"
#include "ctime"
#include "queue"

class GameManager
{
private:
    int num_of_player;
    int num_of_piece;
    int curr_turn;
    bool isThrowPossible; //이름 수정
    int init_board;
    int dest_board;
    bool init_board_clickable;
    bool dest_board_clickable;
    //vector<int> result_of_yuts;
    queue<int> result_of_yuts;
    Board board;
    GameEvent gameevent;
public:
    GameManager();
    void setGameCondition(int, int);
    void gameStart();
    void turnChanger();
    bool getIsThrowPossible();
    void setInitBoard(int);
    void setDestBoard(int);
    bool getInitBoardClickable();
    bool getDestBoardClickable();
    void throwYut();
};

#endif // GAMEMANAGER_H
