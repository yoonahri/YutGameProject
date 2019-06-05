#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include<iostream>
using namespace std;
#include <utility>
#include "gamestate.h"

enum MOVESTATE {MOVE, GROUPING, KILL};

class Board
{
private:
    vector<vector<int>> board_status;
    size_t player_num;
    size_t piece_num;
    vector<vector<vector<int>>> movable_pos;
//    bool isKilled;
//    bool isEmpty;
    int curr_turn;
    size_t init_board;
    size_t dest_board;

public:
    Board();
    void setBoardStatus(size_t, size_t);
    void changeTurn();
    vector<int> getBoardStatus(int);
    bool isMovablePos(int, int, int);
    int move();
    //void move(size_t, size_t, size_t);
    //bool isKillingEventOccured();
    //void isKilledDone();
    int gameOver();
    vector<int> getMovablePos(int, int);
    int getTurn();

    bool setInitBoard(size_t);
    bool setDestBoard(int, size_t);
};
#endif // BOARD_H
