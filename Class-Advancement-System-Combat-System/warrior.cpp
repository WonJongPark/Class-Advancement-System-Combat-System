#include "warrior.h"
#include <iostream>

using namespace std;

Warrior::Warrior(string nickname) : Player(nickname) {
    job_name = "전사";
    cout << "전사로 전직했습니다." << endl;
    power += 1;
}

void Warrior::attack() {
    cout << "대검을 휘두른다." << endl;
}