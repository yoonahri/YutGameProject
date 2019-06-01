#include "gamemanager.h"

GameManager::GameManager()
{
    this->movable_pos =  {
        { {19}, {1}, {2}, {3}, {4}, {5} },
        { {0}, {2}, {3}, {4}, {5}, {6} },
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
        { {26}, {23, 27}, {24, 28}, {15, 29}, {16, 29}, {17, 29} },
        { {26}, {28}, {29}, {29}, {29}, {29} },
    };
}

void GameManager::setGameCondition(int player, int piece){
    this->num_of_player = player;
    this->num_of_piece = piece;
    this->curr_turn = 0;
    this->board.setBoardStatus(player, piece);

    this->isThrowPossible = true;
    this->init_board_clickable = false;
    this->dest_board_clickable = false;
}

void GameManager::turnChanger(){
    //턴 변경
    this->curr_turn += 1;

    if(curr_turn == num_of_player){
        curr_turn = 0;
    }
}

bool GameManager::getIsThrowPossible(){
    return this->isThrowPossible;
}

void GameManager::setInitBoard(int clicked){
    this->init_board = clicked;
    if(board.getBoardStatus()[init_board][curr_turn] != 0){
        this->init_board_clickable = false;
        this->dest_board_clickable = true;
        cout << "init : " << init_board << endl;
    }
    else{
        this->init_board = 99; //클릭 불가능한 판넬
    }
}

void GameManager::setDestBoard(){

        board.move(curr_turn, init_board, dest_board);

        cout << "dest : " << dest_board << endl;


        result_of_yuts.pop();
        this->dest_board_clickable = false;

        if(board.isKillingEventOccured())
        {
            cout << "killing event" << endl;
            isThrowPossible = true;
            board.isKilledDone();
        }
//        else if(board.gameOver() > -1){
//            cout << "game over" << endl;
            //게임 종료 작업
//        }
        else if(!result_of_yuts.empty()){
            cout << "click init_board again" << endl;
            isThrowPossible = false; //?
            init_board_clickable = true;
        }

        else{
            cout << "next turn" << endl;
            turnChanger();
            isThrowPossible = true;
        }

}


bool GameManager::getInitBoardClickable(int clicked){
    if(board.getBoardStatus()[clicked][curr_turn] == 0){ // 보드가 비어있을 때
        init_board_clickable = false;
    }
    /* 이 부분 때문에 업을 때 오류생김
    else{
        cout<<"problem!";
        init_board_clickable = true;
    }
    */
    return this->init_board_clickable;
}

bool GameManager::getDestBoardClickable(int clicked){
    this->dest_board = clicked;
    if(this->gameevent.IsMovablePos(init_board, result_of_yuts.front(), dest_board)){
        cout << this->gameevent.IsMovablePos(init_board, result_of_yuts.front(), dest_board) << endl;
        dest_board_clickable = true;
    }
    else{
        dest_board_clickable = false;
    }
    return this->dest_board_clickable;
}

void GameManager::throwYut(){
    cout << "turn : " << curr_turn << endl; //test

    //return값을 큐에 차례대로 저장, 윷이나 모가 나올경우 한번 더 진행

    //윷놀이의 평균 확률 = { 빽도 = 0.08, 도 = 0.15, 개 = 0.34, 걸 = 0.25, 윷 = 0.12, 모 = 0.02 }
    int probabilityOfYut[] = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5 };

    srand((unsigned int)time(0));
    int result = ((int)rand()) % 47;

    result_of_yuts.push(probabilityOfYut[result]);

    cout<<probabilityOfYut[result]<<endl;//test

    if(probabilityOfYut[result]<4){ //걸 이하이면 넘어감. 윷이상은 따로 설정 안해주면 그냥 반복 가능
        this->isThrowPossible = false;
        this->init_board_clickable = true;
    }
}

void GameManager::testThrowYut(int yut){
    cout << "turn : " << curr_turn << endl; //test

    result_of_yuts.push(yut);

    cout<<yut<<endl; //test

    if(yut<4){
        this->isThrowPossible = false;
        this->init_board_clickable = true;
    }
}

vector<int> GameManager::getMovablePos(int num_of_board, int num_of_yut){
    return movable_pos[num_of_board][num_of_yut];
}

int GameManager::getYutNum(){
    return result_of_yuts.front();
}

int GameManager::getTurn(){
    return curr_turn;
}

int GameManager::getBoardPiece(int clicked){
    return board.getBoardStatus()[clicked][curr_turn];
}

vector<int> GameManager::getBoardStatus(int clicked){
    return board.getBoardStatus()[clicked];
}
