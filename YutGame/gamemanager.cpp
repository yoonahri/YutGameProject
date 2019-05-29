#include "gamemanager.h"

GameManager::GameManager()
{
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


void GameManager::gameStart(){

    /*
     * �������ư.setOnClickListener(), Ŭ������ ��,
     * if(clicked) //���̳� �� ������ ��쿡 ��� ���� �� �ְ� ��
     */
/*
    IsThrowPossible = true;
    if(!IsThrowPossible){ //���� ��
        if(result_of_yuts[result_of_yuts.size()] >= 4){
            do{
                IsThrowPossible = true;
            }while(result_of_yuts[result_of_yuts.size()] < 4
                   || IsThrowPossible == false);
        }
*/
        while(board.gameOver() < 0){
            while(result_of_yuts.size() != 0){ //���� ���� ��� �Һ��� ������ �ݺ��Ѵ�

             /*
             * ������ �ϳ��� �ǳ��� Ŭ������ ��
             * Ŭ���� ������ ��ȣ�� ���޹���
             * �ϴ� �װ� int num_of_board_init �̶� ����, �Ŀ� �ݵ�� ����
             */
                int num_of_board_init = 0;

//                if(board.getBoardStatus()[num_of_board_init][curr_turn] != 0){
//                    gameevent.highlightMovablePos(num_of_board_init, result_of_yuts.front());//�� �� �ִ� ���� ��ȣ�� ���̶���Ʈ���ش�
//                }
            /*
            * ���� ���尡 Ŭ���� ���·� �ٸ� �ǳ��� Ŭ������ ��
            * Ŭ���� ���� ��ȣ�� num_of_board_clicked�� ����
            * �Ŀ� �ݵ�� ����
            */

                int num_of_board_clicked = 2;

                // ���� ���� ���� ���� ������ ���� ����� ���� ������ �� �ִ� ������ �Ǵ�, ���� �´ٸ� ������ ���͸� �����Ѵ�.
//                if(gameevent.IsMovablePos(num_of_board_init, result_of_yuts[0], num_of_board_clicked)){
//                    board.move(curr_turn, num_of_board_init, num_of_board_clicked);

                    //����� ���� ����� �����Ѵ�
//                    auto used_yut = result_of_yuts.begin();
//                    result_of_yuts.erase(used_yut);
//                }

                if(board.isKillingEventOccured() == true){ //���� ����� ���
                    throwYut();//������ ��ư�� ������ ��
                }
            }
            turnChanger();
       }

    //���Ƿ� �������� �������� ��, ���� ����
    cout << "winning team is  " << board.gameOver();
}

void GameManager::turnChanger(){
    //�� ����
    this->curr_turn+=1;

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
        gameevent.highlightMovablePos(init_board, result_of_yuts.front());
        this->init_board_clickable = false;
        this->dest_board_clickable = true;
        cout << "init : " << init_board << endl;
    }
    else{
        this->init_board = 99; //Ŭ�� �Ұ����� �ǳ�
    }
}

void GameManager::setDestBoard(int clicked){
    this->dest_board = clicked;

    cout << "a" << endl;

    if(this->gameevent.IsMovablePos(init_board, result_of_yuts.front(), dest_board)){
        cout << this->gameevent.IsMovablePos(init_board, result_of_yuts.front(), dest_board) << endl;

        board.move(curr_turn, init_board, dest_board);

        cout << "dest : " << dest_board << endl;
/*
        if(result_of_yuts.size()>1){
            vector<int>::iterator used_yut = result_of_yuts.begin();
            used_yut = result_of_yuts.erase(used_yut);
        }
        else{
            cout << "num of yut = 1" << endl;
            result_of_yuts.clear();
        }
*/
        result_of_yuts.pop();

        //erase�ϰ��� iterator�� ���� ���Ҹ� �����Ѽ� �����߻�
//       auto used_yut = result_of_yuts.begin();
//       result_of_yuts.erase(useyd_yut);

        this->dest_board_clickable = false;

        if(board.isKillingEventOccured())
        {
            cout << "killing event" << endl;
            isThrowPossible = true;
            board.isKilledDone();
        }
//        else if(board.gameOver() > -1){
//            cout << "game over" << endl;
            //���� ���� �۾�
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
    else{
        this->dest_board = 99;
    }
}

bool GameManager::getInitBoardClickable(){
    return this->init_board_clickable;
}

bool GameManager::getDestBoardClickable(){
    return this->dest_board_clickable;
}

void GameManager::throwYut(){
    cout << "turn : " << curr_turn << endl;

    //return���� ���Ϳ� ���ʴ�� ����, ���̳� �� ���ð�� �ѹ� �� ����

    //�������� ��� Ȯ�� = { ���� = 0.08, �� = 0.15, �� = 0.34, �� = 0.25, �� = 0.12, �� = 0.02 }
    int probabilityOfYut[] = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5 };

    srand((unsigned int)time(0));
    int result = ((int)rand()) % 47;
    //result_of_yuts.push_back(probabilityOfYut[11]);
    //result_of_yuts.push_back(probabilityOfYut[result]);
    result_of_yuts.push(probabilityOfYut[result]);
    cout<<probabilityOfYut[result]<<endl;

    if(probabilityOfYut[result]<4){ //�� �����̸� �Ѿ. ���̻��� ���� ���� �����ָ� �׳� �ݺ� ����
        this->isThrowPossible = false;
        this->init_board_clickable = true;
    }
}
