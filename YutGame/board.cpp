#include "board.h"

Board::Board(){

    this->movable_pos =  {
        { {19}, {1}, {2}, {3}, {4}, {5} },
        { {29}, {2}, {3}, {4}, {5}, {6} },
        { {1}, {3}, {4}, {5}, {6}, {7} },
        { {2}, {4}, {5}, {6}, {7}, {8} },
        { {3}, {5}, {6}, {7}, {8}, {9} },
        { {4}, {6, 20}, {7, 21}, {8, 22}, {9, 23}, {10, 24} },
        { {5}, {7}, {8}, {9}, {10}, {11} },
        { {6}, {8}, {9}, {10}, {11}, {12} },
        { {7}, {9}, {10}, {11}, {12}, {13} },
        { {8}, {10}, {11}, {12}, {13}, {14} },
        { {9}, {11, 25}, {12, 26}, {13, 22}, {14, 27}, {15, 28} },
        { {10}, {12}, {13}, {14}, {15}, {16} },
        { {11}, {13}, {14}, {15}, {16}, {17} },
        { {12}, {14}, {15}, {16}, {17}, {18} },
        { {13}, {15}, {16}, {17}, {18}, {19} },
        { {14}, {16}, {17}, {18}, {19}, {29} },
        { {15}, {17}, {18}, {19}, {29}, {29} },
        { {16}, {18}, {19}, {29}, {29}, {29} },
        { {17}, {19}, {29}, {29}, {29}, {29} },
        { {18}, {29}, {29}, {29}, {29}, {29} },
        { {5}, {21}, {22}, {23}, {24}, {15} },
        { {20}, {22}, {23}, {24}, {15}, {16} },
        { {26}, {23, 27}, {24, 28}, {15, 29}, {16, 29}, {17, 29} },
        { {22}, {24}, {15}, {16}, {17}, {18} },
        { {23}, {15}, {16}, {17}, {18}, {19} },
        { {10}, {26}, {22}, {27}, {28}, {29} },
        { {25}, {22}, {27}, {28}, {29}, {29} },
        { {22}, {28}, {29}, {29}, {29}, {29} },
        { {27}, {29}, {29}, {29}, {29}, {29} },
    };

    for(size_t i = 0; i < 30; i++){
        board_status.push_back(vector<int>());
    }
    this->isKilled = false;
}

void Board::changeTurn(){
    //턴 변경
    this->curr_turn += 1;

    if(curr_turn == player_num){
        curr_turn = 0;
    }
}

void Board::setBoardStatus(size_t player, size_t piece){
    this->player_num = player;
    this->piece_num = piece;
    this->curr_turn = 0;

    for(size_t i = 0; i < 30; i++){
        for(size_t j = 0; j < player_num; j++){
            if(i == 0){
                this->board_status[i].push_back(piece_num);
            }
            else{
                this->board_status[i].push_back(0);
            }
        }
    }
}

vector<int> Board::getBoardStatus(int init_board){
    return board_status[init_board];
}

void Board::move(size_t turn, size_t init_board, size_t clicked_board){

    /*
     * 말이 처음 위치에 있는지 구분해줄 필요가 있음,
     * 만약 처음 위치에 있다면 그 위치에 있는 내 말들중 단 하나의 말만 이동시킬 위치로 이동
     * 이동 할 경우 처음위치의 말은 -1 시켜줌
     * 처음위치가 아니라면 그 위치에 있는 내말(업은 말 포함) 전부가 이동시킬 위치로 이동
     * 이동 할 경우 처음 위치의 말은 0이 됨
    */

    size_t searchClickedBoardTurn = 99;

    for(size_t i = 0; i < player_num; i++){
        if(board_status[clicked_board][i] != 0){
            searchClickedBoardTurn = i;
        }
    }

    if(init_board == 0){ //초기상태의 말 일때
        if(searchClickedBoardTurn == turn){ //업는 경우
            board_status[clicked_board][searchClickedBoardTurn] += 1;
        }

        else if(searchClickedBoardTurn == 99){ //빈 공간에 이동하는 경우
            board_status[clicked_board][turn] = 1;
        }

        else { //죽이는 경우
            board_status[0][searchClickedBoardTurn] += board_status[clicked_board][searchClickedBoardTurn];
            board_status[clicked_board][searchClickedBoardTurn] = 0;
            board_status[clicked_board][turn] += 1;
            this->isKilled = true;
        }
        board_status[init_board][turn] -= 1;
    }

    else{ //이미 이동했던 말 일때
        if(searchClickedBoardTurn == turn){ //업는 경우
            board_status[clicked_board][searchClickedBoardTurn] += board_status[init_board][turn];
        }
        else if(searchClickedBoardTurn == 99){ //빈 공간에 이동하는 경우
            board_status[clicked_board][turn] += board_status[init_board][turn];
        }
        else { //죽이는 경우
            if(clicked_board != 0){
                board_status[0][searchClickedBoardTurn] += board_status[clicked_board][searchClickedBoardTurn];
                board_status[clicked_board][searchClickedBoardTurn] = 0;
                board_status[clicked_board][turn] += board_status[init_board][turn];
                this->isKilled = true;
            }
            else{
                board_status[clicked_board][turn] += board_status[init_board][turn];
            }
        }
        board_status[init_board][turn] = 0;
    }

    //벡터 확인용 코드, 삭제 예정
    for(size_t i = 0; i < 30; i++){
        for(size_t j = 0; j < board_status[i].size(); j++){
            cout<<i<<":"<<board_status[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<int> Board::getMovablePos(int num_of_board, int num_of_yut){
    return movable_pos[num_of_board][num_of_yut];
}

bool Board::isMovablePos(int num_of_board_init, int num_of_yut, int num_of_board_des){
    for(auto m = this->movable_pos[num_of_board_init][num_of_yut].begin()
        ; m != movable_pos[num_of_board_init][num_of_yut].end() ; m++ ){
        if(*m == num_of_board_des){
            return true;
        }
    }
    return false;
}

bool Board::isKillingEventOccured(){
    return isKilled;
}

void Board::isKilledDone(){
    isKilled = false;
}

int Board::gameOver(){

    for(size_t i = 0; i < player_num; i++){
        if(board_status[29][i] == piece_num){ //30...아니야...
            return i;
        }
    }
    return -1;

    /*
    if(board_status[2][0] == 1){
        return 1;
    }
    else{
        return -1;
    }
    */
}

int Board::getTurn(){
    return curr_turn;
}



