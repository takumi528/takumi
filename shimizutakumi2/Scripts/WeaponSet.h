#pragma once

#include "Player.h"

struct WeaponParam {
	int attack;
	int knock;
	int speed;//�U�鎞��
	int central;//�����蔻��(��`)�̒��S�p
	int radius;//�����蔻��(��`)�̔��a
};

class AbstractSword {//���ɐU��n�̕���͂����ōČ��\�I����\�͂͌p�����ĕt���������I
public:
	AbstractSword(WeaponParam p): p(p) {}

	virtual ~AbstractSword() = default;
	
private:
	Graph graph, effect;
	Sector coll;
	const WeaponParam p;
};