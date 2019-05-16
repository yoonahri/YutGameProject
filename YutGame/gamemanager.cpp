#include "gamemanager.h"

GameManager::GameManager(int player, int piece)
{
    this->num_of_player = player;
    this->num_of_piece = piece;
    this->curr_turn = 0;
    this->board.setBoardStatus(player, piece);
}

void GameManager::gameStart(){

    /*
     * �������ư.setOnClickListener(), Ŭ������ ��,
     * if(clicked) //���̳� �� ������ ��쿡 ��� ���� �� �ְ� ��
     */


    throwYut();

    while(board.gameOver() < 0){

        while(result_of_yuts.size() != 0){ //���� ���� ��� �Һ��� ������ �ݺ��Ѵ�

     /*
     * ������ �ϳ��� �ǳ��� Ŭ������ ��
     * Ŭ���� ������ ��ȣ�� ���޹���
     * �ϴ� �װ� int num_of_board_init �̶� ����, �Ŀ� �ݵ�� ����
     */

            int num_of_board_init = 0;

            if(board.getBoardStatus()[num_of_board_init][curr_turn] != 0){
                gameevent.highlightMovablePos(num_of_board_init, result_of_yuts[0]);//�� �� �ִ� ���� ��ȣ�� ���̶���Ʈ���ش�
            }
        /*
        * ���� ���尡 Ŭ���� ���·� �ٸ� �ǳ��� Ŭ������ ��
        * Ŭ���� ���� ��ȣ�� num_of_board_clicked�� ����
        * �Ŀ� �ݵ�� ����
        */

            int num_of_board_clicked = 2;

            // ���� ���� ���� ���� ������ ���� ����� ���� ������ �� �ִ� ������ �Ǵ�, ���� �´ٸ� ������ ���͸� �����Ѵ�.
            if(gameevent.IsMovablePos(num_of_board_init, result_of_yuts[0], num_of_board_clicked)){
                board.move(curr_turn, num_of_board_init, num_of_board_clicked);

                //����� ���� ����� �����Ѵ�
                auto used_yut = result_of_yuts.begin();
                result_of_yuts.erase(used_yut);
            }



            if(board.isKillingEventOccured() == true){ //���� ����� ���
                throwYut();//������ ��ư�� ������ ��
            }
        }
        turnChanger();
    }

    //���Ƿ� �������� �������� ��, ���� ����
    cout<<"winning team is  "<<board.gameOver();

}

void GameManager::turnChanger(){
    //�� ����
    this->curr_turn += 1;

    if(curr_turn == num_of_player - 1){
        curr_turn = 0;
    }
}

void GameManager::throwYut(){
    //return���� ���Ϳ� ���ʴ�� ����, ���̳� �� ���ð�� �ѹ� �� ����

    //�������� ��� Ȯ�� = { ���� = 0.08, �� = 0.15, �� = 0.34, �� = 0.25, �� = 0.12, �� = 0.02 }
    int probabilityOfYut[] = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5 };

    srand((unsigned int)time(0));
    int result = ((int)rand()) % 47;
    result_of_yuts.push_back(probabilityOfYut[11]);
    //result_of_yuts.push_back(probabilityOfYut[result]);
    cout<<probabilityOfYut[11]<<endl;
    //if(probabilityOfYut[result] == 4 || probabilityOfYut[result] == 5 ){
      //  throwYut();
    //}


}
