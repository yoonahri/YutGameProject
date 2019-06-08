#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "board.h"
#include "gamestate.h"
#include "yutmanager.h"

class GameManager
{
private:
    int num_of_player;
    int num_of_piece;
    int winner;
    int gamestate;
    Board board;
    YutManager yut_manager;

public:
    GameManager();
    void setGameCondition(int, int);
    void gameStart();
    int getGameState();
    void setBoard(int);
    void setInitBoard(int);
    void setDestBoard(int);
    bool isMovablePos(int, int, int);
    void throwYut();
    void testThrowYut(int);
    vector<int> getMovablePos(int, int);
    int getYutNum(int);
    int getBoardPiece(int);
    vector<int> getBoardStatus(int);
    int getWinner();
    int getTurn();
};

#endif // GAMEMANAGER_H
