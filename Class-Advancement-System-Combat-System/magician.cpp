#include "magician.h"
#include <iostream>

using namespace std;

Magician::Magician(string nickname) : Player(nickname) {
    job_name = "마법사";
    cout << "마법사로 전직했습니다." << endl;
    MP = 100;
}

void Magician::attack() {
    cout << "파이어 볼을 발사한다." << endl;
}