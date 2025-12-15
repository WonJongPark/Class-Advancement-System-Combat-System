#include "monster.h"
#include "player.h"
#include <iostream>

using namespace std;

Monster::Monster(string name) : name(name) {
    HP = 10;
    power = 30;
    defence = 10;
    speed = 10;
}

void Monster::attack(Player* player) {
    int damage = power - player->getDefence();
    
    if (damage <= 0) {
        damage = 1;
    }
    
    cout << getName() << "이(가) 플레이어에게 입힌 데미지 : " << damage << endl;
    player->setHP(player->getHP() - damage);

    if (player->getHP() > 0) {
        cout << player->getNickname() << "(" << player->getJobName() << ")의 남은 HP : " << player->getHP() << endl;
    }
    else {
        player->setHP(0);
        cout << "플레이어가 사망하였습니다." << endl;
    }
}

int Monster::getDefence() {
    return defence;
}

int Monster::getHP() {
    return HP;
}

void Monster::setHP(int HP) {
    this->HP = HP;
}

string Monster::getName() {
    return name;
}

int Monster::getSpeed() {
    return speed;
}