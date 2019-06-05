#include "gamemanager.h"

GameManager::GameManager()
{
}

void GameManager::setGameCondition(int player, int piece){
    this->num_of_player = player;
    this->num_of_piece = piece;
    this->board.setBoardStatus(player, piece);
    this->gamestate = THROW;
    this->winner = -1;
}

int GameManager::getGameState(){
    return this->gamestate;
}

void GameManager::setBoard(int clicked){
    if(gamestate == INIT_MOVE){
        if(board.setInitBoard(clicked)){
            //highlight 함
            gamestate = DEST_MOVE;
        }
    }
    else if(gamestate == DEST_MOVE){
        if(!yut_manager.isEmpty()){
            if(board.setDestBoard(yut_manager.getYutNum(0), clicked)){
                yut_manager.popYut();

                int move_state = board.move();

                if(move_state == GROUPING || move_state == MOVE){
                    if(yut_manager.isEmpty()){
                        gamestate = THROW;
                        board.changeTurn();
                    }
                    else if (!yut_manager.isEmpty()) {
                        gamestate = INIT_MOVE;
                    }
                    else{
                        cout << "error" << endl; //test용
                    }
                }

                else if(move_state == KILL){
                    gamestate = THROW;
                }

                if(board.gameOver() > -1){
                    cout << "game over" << endl;
                    //게임 종료 작업
                    winner = board.gameOver();
                }
            }
        }
    }
    else{
        cout << "can't click board" << endl;
    }
}

/*
void GameManager::setInitBoard(int clicked){
    this->init_board = clicked;
    if(board.getBoardStatus(clicked)[board.getTurn()] != 0){
        this->gamestate = DEST_MOVE;
        cout << "init : " << init_board << endl;
    }
    else{
        this->init_board = 99; //클릭 불가능한 판넬
    }
}
*/

/*
void GameManager::setDestBoard(int clicked){
    this->dest_board = clicked;

    if(!result_of_yuts.empty() && (init_board != dest_board)){
        if(this->board.isMovablePos(init_board, result_of_yuts.front(), dest_board)){
            cout << this->board.isMovablePos(init_board, result_of_yuts.front(), dest_board) << endl;
            board.move(board.getTurn(), init_board, dest_board);

            cout << "dest : " << dest_board << endl;

            result_of_yuts.pop();
            this->gamestate = WAIT;


            if(board.isKillingEventOccured())
            {
                cout << "killing event" << endl;
                this->gamestate = THROW;
                board.isKilledDone();
            }

            else if(board.gameOver() > -1){
                cout << "game over" << endl;
                //게임 종료 작업
                winner = board.gameOver();
            }

            else if(!result_of_yuts.empty()){
                cout << "click init_board again" << endl;
                this->gamestate = INIT_MOVE;
            }

            else{
                cout << "next turn" << endl;
                board.changeTurn();
                this->gamestate = THROW;
            }
        }
    }
}
*/

/*
void GameManager::throwYut(){
    cout << "turn : " << board.getTurn() << endl; //test

    //return값을 큐에 차례대로 저장, 윷이나 모가 나올경우 한번 더 진행

    //윷놀이의 평균 확률 = { 빽도 = 0.08, 도 = 0.15, 개 = 0.34, 걸 = 0.25, 윷 = 0.12, 모 = 0.02 }
    int probabilityOfYut[] = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                               3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5 };

    srand((unsigned int)time(0));
    int result = ((int)rand()) % 47;

    result_of_yuts.push(probabilityOfYut[result]);

    cout<<probabilityOfYut[result]<<endl;//test

    if(probabilityOfYut[result]<4){ //걸 이하이면 넘어감. 윷이상은 따로 설정 안해주면 그냥 반복 가능
        this->gamestate = INIT_MOVE;
    }
}
*/
void GameManager::throwYut(){
    cout << "turn : " << board.getTurn() << endl;

    if(gamestate == THROW){
        yut_manager.throwYut();
        if(yut_manager.getYutNum(1) < 4){
            gamestate = INIT_MOVE;
        }
    }
}


/*
void GameManager::testThrowYut(int yut){
    cout << "turn : "<< board.getTurn() << endl; //test
    result_of_yuts.push(yut);
    cout<<"yut : "<<yut<<endl; //test
    if(yut < 4){
        this->gamestate = INIT_MOVE;
    }
}
*/

void GameManager::testThrowYut(int yut){
    cout << "turn : "<< board.getTurn() << endl;

    if(gamestate == THROW){
        yut_manager.testThrowYut(yut);
        if(yut_manager.getYutNum(1) < 4){
            gamestate = INIT_MOVE;
        }
    }
}


int GameManager::getYutNum(int front_or_back){
    return yut_manager.getYutNum(front_or_back);
}


int GameManager::getBoardPiece(int clicked){
    return board.getBoardStatus(clicked)[board.getTurn()];
}

vector<int> GameManager::getBoardStatus(int clicked){
    return board.getBoardStatus(clicked);
}

int GameManager::getWinner(){
    return winner;
}

vector<int> GameManager::getMovablePos(int board, int yut){
    return this->board.getMovablePos(board, yut);
}

bool GameManager::isMovablePos(int init, int yut, int dest){
    return this->board.isMovablePos(init, yut, dest);
}

int GameManager::getTurn(){
    return board.getTurn();
}
