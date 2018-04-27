#pragma once

#include "Suken.h"
#include "player.h"
#include "scrol.h"
#include "map.h"
#include "pub.h"

class CSword {
private:
	int x, y;
	int R = 70;
	const int power = 1;
	const int knock = 10;
public:
	CSword();
	void Appear(int x,int y);
	void PAttack();
	void Set(int x, int y);
	void Loop();
	void Draw();
	int count;
	int damage;
	bool flag;
	bool Hit(int x, int y, int r);
	int GetPower();
	int GetKnock();
};
