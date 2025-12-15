#include "warrior.h"
#include "monster.h"
#include <iostream>

using namespace std;

Warrior::Warrior(string nickname) : Player(nickname) {
    job_name = "전사";
    cout << "전사로 전직했습니다." << endl;
    power += 10;
    defence += 10;
}

void Warrior::attack() {
    cout << "대검을 휘두른다." << endl;
}

void Warrior::attack(Monster* monster) {
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
	cout << monster->getName() << "에게 대검으로 " << damage << "의 피해를 입혔다!" << endl;


	// 몬스터의 setHP를 호출하여 몬스터의 HP-데미지를 계산한 값을 매개변수로 전달합니다.
	// 몬스터의 getHP를 호출 분기문이 실행됩니다.
	// 몬스터가 생존했을 경우 몬스터의 남은 HP 출력
	// 몬스터가 생존하지 못했을 경우 플레이어의 승리 문구 출력
	monster->setHP(monster->getHP() - damage);

	if (monster->getHP() > 0) {
		cout << monster->getName() << "의 남은 체력 : " << monster->getHP() << endl;
	}
	else {
		monster->setHP(0);
		cout << "플레이어가 승리하였습니다." << endl;
	}
}