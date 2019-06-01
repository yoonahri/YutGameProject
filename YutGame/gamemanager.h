#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "board.h"
#include "ctime"
#include "queue"

class GameManager
{
private:
    int num_of_player;
    int num_of_piece;
    int curr_turn;
    bool isThrowPossible;
    int init_board;
    int dest_board;
    bool init_board_clickable;
    bool dest_board_clickable;
    int winner;
    vector<vector<vector<int>>> movable_pos;
    queue<int> result_of_yuts;
    Board board;

public:
    GameManager();
    void setGameCondition(int, int);
    void gameStart();
    void turnChanger();
    bool getIsThrowPossible();
    void setInitBoard(int);
    void setDestBoard();
    bool getInitBoardClickable(int);
    bool getDestBoardClickable(int);
    bool isMovablePos(int, int, int);
    void throwYut();
    void testThrowYut(int);
    vector<int> getMovablePos(int, int);
    int getYutNum();
    int getBackYutNum();
    int getTurn();
    int getBoardPiece(int);
    vector<int> getBoardStatus(int);
    int getWinner();
};

#endif // GAMEMANAGER_H
