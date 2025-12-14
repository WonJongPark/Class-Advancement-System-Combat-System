#include "archer.h"
#include <iostream>

using namespace std;

Archer::Archer(string nickname) : Player(nickname) {
    job_name = "궁수";
    cout << "궁수로 전직했습니다." << endl;
    accuracy = 5;
}

void Archer::attack() {
    cout << "활로 화살을 발사한다." << endl;
}