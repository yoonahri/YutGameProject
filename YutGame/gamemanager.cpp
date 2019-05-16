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
     * 던지기버튼.setOnClickListener(), 클릭됐을 때,
     * if(clicked) //윷이나 모가 나왔을 경우에 계속 누를 수 있게 함
     */


    throwYut();

    while(board.gameOver() < 0){

        while(result_of_yuts.size() != 0){ //던진 윷을 모두 소비할 때까지 반복한다

     /*
     * 보드중 하나의 판넬이 클릭됐을 때
     * 클릭된 보드의 번호를 전달받음
     * 일단 그게 int num_of_board_init 이라 가정, 후에 반드시 수정
     */

            int num_of_board_init = 0;

            if(board.getBoardStatus()[num_of_board_init][curr_turn] != 0){
                gameevent.highlightMovablePos(num_of_board_init, result_of_yuts[0]);//갈 수 있는 보드 번호를 하이라이트해준다
            }
        /*
        * 이전 보드가 클릭된 상태로 다른 판넬이 클릭됐을 때
        * 클릭된 보드 번호를 num_of_board_clicked라 가정
        * 후에 반드시 수정
        */

            int num_of_board_clicked = 2;

            // 누른 보드 판이 윷을 던졌을 때의 결과에 따라 움직일 수 있는 곳인지 판단, 만약 맞다면 보드의 벡터를 갱신한다.
            if(gameevent.IsMovablePos(num_of_board_init, result_of_yuts[0], num_of_board_clicked)){
                board.move(curr_turn, num_of_board_init, num_of_board_clicked);

                //사용한 윷의 결과를 제거한다
                auto used_yut = result_of_yuts.begin();
                result_of_yuts.erase(used_yut);
            }



            if(board.isKillingEventOccured() == true){ //말을 잡았을 경우
                throwYut();//누르기 버튼을 눌렀을 때
            }
        }
        turnChanger();
    }

    //임의로 종료조건 설정했을 때, 삭제 예정
    cout<<"winning team is  "<<board.gameOver();

}

void GameManager::turnChanger(){
    //턴 변경
    this->curr_turn += 1;

    if(curr_turn == num_of_player - 1){
        curr_turn = 0;
    }
}

void GameManager::throwYut(){
    //return값을 벡터에 차례대로 저장, 윷이나 모가 나올경우 한번 더 진행

    //윷놀이의 평균 확률 = { 빽도 = 0.08, 도 = 0.15, 개 = 0.34, 걸 = 0.25, 윷 = 0.12, 모 = 0.02 }
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
