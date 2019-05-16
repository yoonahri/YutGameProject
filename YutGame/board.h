#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include<iostream>
using namespace std;
#include <utility>


class Board
{
private:
    vector<vector<int>> board_status;
    size_t player_num;
    size_t piece_num;
    bool isKilled;
public:
    Board();
    void setBoardStatus(size_t, size_t);
    vector<vector<int>> getBoardStatus();
    void move(size_t, size_t, size_t);
    bool isKillingEventOccured();
    int gameOver();
};
#endif // BOARD_H
