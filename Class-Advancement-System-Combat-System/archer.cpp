#include "archer.h"
#include "monster.h"
#include <iostream>

using namespace std;



Archer::Archer(string nickname) : Player(nickname) {
    job_name = "궁수";
    cout << "궁수로 전직했습니다." << endl;
    accuracy = 15;
}

void Archer::attack() {
    cout << "활로 화살을 발사한다." << endl;
}

void Archer::attack(Monster* monster) {
    // 플레이어의 공격력-몬스터의 방어력을 계산하여 데미지로 정의합니다.
    // 계산된 데미지가 0 이하일 경우, 데미지를 1로 정의합니다.
    int damage = power - monster->getDefence();
    if (damage <= 0) {
        damage = 1;
    }

    // 공격 문장을 출력합니다.
    // - 전사, 마법사: 계산된 데미지로 1회 공격
    // - 궁수: 계산된 데미지/3으로 3회 공격 (소수점 생략)
    // - 도적: 계산된 데미지/5으로 5회 공격 (소수점 생략)
    // - 궁수와 도적의 경우, 3과 5로 나눈 결과가 0이라면 1로 정의합니다.
    // ex) * 슬라임에게 화살로 3의 피해를 입혔다! 3번 출력
    int finaldamage = damage / 3;
    if (finaldamage == 0) {
        finaldamage = 1;
    }
    for (int i = 0; i < 3; i++) {
        cout << monster->getName() << "에게 활로 화살을쏴서 " << finaldamage << "의 피해를 입혔다!" << endl;
    }

    // 몬스터의 setHP를 호출하여 몬스터의 HP-데미지를 계산한 값을 매개변수로 전달합니다.
    // 몬스터의 getHP를 호출 분기문이 실행됩니다.
    // 몬스터가 생존했을 경우 몬스터의 남은 HP 출력
    // 몬스터가 생존하지 못했을 경우 플레이어의 승리 문구 출력
    monster->setHP(monster->getHP() - finaldamage * 3);

    if (monster->getHP() > 0) {
        cout << monster->getName() << "의 남은 체력 : " << monster->getHP() << endl;
    }
    else {
        monster->setHP(0);
        cout << "플레이어가 승리하였습니다." << endl;
    }
}