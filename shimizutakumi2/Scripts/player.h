#pragma once
#include "Suken.h"
#include "scrol.h"
#include "map.h"
#include "enemy.h"
#include "weapon.h"
#include "possession.h"

class CPlayer {
private:
	int x, y, v;
	int life;
	const int R = 10;
	int invincible;
public:
	CPlayer();
	void Move();
	void Loop();
	void Draw();
	void Appear();
	int GetX();
	int GetY();
	int GetV();
	int GetLife();
	int Hit();
	bool GetItem(int x,int y,int R);
};