#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include<iostream>
using namespace std;
#include <utility>

enum MOVESTATE {MOVE, GROUPING, KILL};

class Board
{
private:
    vector<vector<int>> board_status;
    size_t player_num;
    size_t piece_num;
    vector<vector<vector<int>>> movable_pos;
    bool isKilled;
    bool isEmpty;
    int curr_turn;
public:
    Board();
    void setBoardStatus(size_t, size_t);
    void changeTurn();
    vector<int> getBoardStatus(int);
    bool isMovablePos(int, int, int);
    void move(size_t, size_t, size_t);
    bool isKillingEventOccured();
    void isKilledDone();
    int gameOver();
    vector<int> getMovablePos(int, int);
    int getTurn();
};
#endif // BOARD_H
