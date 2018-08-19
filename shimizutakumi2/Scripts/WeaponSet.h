#pragma once

#include "Player.h"

struct WeaponParam {
	int attack;
	int knock;
	int speed;//振る時間
	int central;//当たり判定(扇形)の中心角
	int radius;//当たり判定(扇形)の半径
};

class AbstractSword {//横に振る系の武器はこれ一つで再現可能！特殊能力は継承して付け足そう！
public:
	AbstractSword(WeaponParam p): p(p) {}

	virtual ~AbstractSword() = default;
	
private:
	Graph graph, effect;
	Sector coll;
	const WeaponParam p;
};