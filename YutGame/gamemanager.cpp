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

void GameManager::throwYut(){
    cout << "turn : " << board.getTurn() << endl;

    if(gamestate == THROW){
        yut_manager.throwYut();
        if(yut_manager.getYutNum(1) < 4){
            gamestate = INIT_MOVE;
        }
    }
}


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
