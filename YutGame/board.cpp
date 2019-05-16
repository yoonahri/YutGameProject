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
     * ���� ó�� ��ġ�� �ִ��� �������� �ʿ䰡 ����,
     * ���� ó�� ��ġ�� �ִٸ� �� ��ġ�� �ִ� �� ������ �� �ϳ��� ���� �̵���ų ��ġ�� �̵�
     * �̵� �� ��� ó����ġ�� ���� -1 ������
     * ó����ġ�� �ƴ϶�� �� ��ġ�� �ִ� ����(���� �� ����) ���ΰ� �̵���ų ��ġ�� �̵�
     * �̵� �� ��� ó�� ��ġ�� ���� 0�� ��
    */

    if(init_board == 0){ //�ʱ������ �� �϶�

        for(size_t i = 0; i < player_num; i++){
            if(board_status[clicked_board][i] != 0){
                if(i == turn){ //���� ���
                    board_status[clicked_board][i] += 1;
                }
                else{ //���̴� ���
                    board_status[0][i] = board_status[clicked_board][i];
                    board_status[clicked_board][i] = 0;
                    board_status[clicked_board][turn] += 1;
                    this->isKilled = true;
                }
            }
            else{ //�� ������ �̵��ϴ� ���
                board_status[clicked_board][turn] = 1;
            }
        }
        board_status[init_board][turn] -= 1;
    }

    else{ //�̹� �̵��ߴ� �� �϶�
        for(size_t i = 0; i < player_num; i++){
            if(board_status[clicked_board][i] != 0){
                if(i == turn){ //���� ���
                    board_status[clicked_board][i] += board_status[init_board][turn];
                }
                else{ //���̴� ���
                    board_status[0][i] = board_status[clicked_board][i];
                    board_status[clicked_board][i] = 0;
                    board_status[clicked_board][turn] += board_status[init_board][turn];
                    this->isKilled = true;
                }
            }
            else{ //�� ������ �̵��ϴ� ���
                board_status[clicked_board][turn] += board_status[init_board][turn];
            }
        }
        board_status[init_board][turn] = 0;
    }

    //���� Ȯ�ο� �ڵ�, ���� ����
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
    /* �̰� ���� �ڵ�
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



