#include "board.h"

Board::Board(){
    for(size_t i = 0; i < 30; i++){
        board_status.push_back(vector<int>());
    }
    this->isKilled = false;
}

void Board::setBoardStatus(size_t player, size_t piece){
    this->player_num = player;
    this->piece_num = piece;

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

vector<vector<int>> Board::getBoardStatus(){
    return board_status;
}

void Board::move(size_t turn, size_t init_board, size_t clicked_board){

    /*
     * 말이 처음 위치에 있는지 구분해줄 필요가 있음,
     * 만약 처음 위치에 있다면 그 위치에 있는 내 말들중 단 하나의 말만 이동시킬 위치로 이동
     * 이동 할 경우 처음위치의 말은 -1 시켜줌
     * 처음위치가 아니라면 그 위치에 있는 내말(업은 말 포함) 전부가 이동시킬 위치로 이동
     * 이동 할 경우 처음 위치의 말은 0이 됨
    */

    if(init_board == 0){ //초기상태의 말 일때

        for(size_t i = 0; i < player_num; i++){
            if(board_status[clicked_board][i] != 0){
                if(i == turn){ //업는 경우
                    board_status[clicked_board][i] += 1;
                }
                else{ //죽이는 경우
                    board_status[0][i] = board_status[clicked_board][i];
                    board_status[clicked_board][i] = 0;
                    board_status[clicked_board][turn] += 1;
                    this->isKilled = true;
                }
            }
            else{ //빈 공간에 이동하는 경우
                board_status[clicked_board][turn] = 1;
            }
        }
        board_status[init_board][turn] -= 1;
    }

    else{ //이미 이동했던 말 일때
        for(size_t i = 0; i < player_num; i++){
            if(board_status[clicked_board][i] != 0){
                if(i == turn){ //업는 경우
                    board_status[clicked_board][i] += board_status[init_board][turn];
                }
                else{ //죽이는 경우
                    board_status[0][i] = board_status[clicked_board][i];
                    board_status[clicked_board][i] = 0;
                    board_status[clicked_board][turn] += board_status[init_board][turn];
                    this->isKilled = true;
                }
            }
            else{ //빈 공간에 이동하는 경우
                board_status[clicked_board][turn] += board_status[init_board][turn];
            }
        }
        board_status[init_board][turn] = 0;
    }

    //벡터 확인용 코드, 삭제 예정
    for(size_t i = 0; i < 30; i++){
        for(size_t j = 0; j < board_status[i].size(); j++){
            cout<<board_status[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool Board::isKillingEventOccured(){
    return isKilled;
}

int Board::gameOver(){
    /* 이게 원래 코드
    for(size_t i = 0; i < player_num; i++){
        if(board_status[30][i] == piece_num){
            return i;
        }
    }
    return -1;
    */
    if(board_status[2][0] == 1){
        return 1;
    }
    else{
        return -1;
    }
}



