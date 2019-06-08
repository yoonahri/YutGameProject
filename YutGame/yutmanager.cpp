#include "yutmanager.h"

YutManager::YutManager()
{}

//return값을 큐에 차례대로 저장, 윷이나 모가 나올경우 한번 더 진행

//윷놀이의 평균 확률 = { 빽도 = 0.08, 도 = 0.15, 개 = 0.34, 걸 = 0.25, 윷 = 0.12, 모 = 0.02 }
void YutManager::throwYut(){
    int probabilityOfYut[47] = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                             3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5 };
    srand((unsigned int)time(0));
    int result = ((int)rand()) % 47;

    result_of_yuts.push(probabilityOfYut[result]);
}

void YutManager::testThrowYut(int yut){
    result_of_yuts.push(yut);
}

void YutManager::popYut(){
    result_of_yuts.pop();
}

bool YutManager::isEmpty(){
    return result_of_yuts.empty();
}

int YutManager::getYutNum(int front_or_back){
    if(front_or_back == 0){
    return result_of_yuts.front();
    }
    else{
        return result_of_yuts.back();
    }
}

