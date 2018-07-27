#pragma once
#include "Suken.h"
#include "scrol.h"
#include "map.h"
#include "enemy.h"
#include "weapon.h"
#include "possession.h"
#include "obstacle.h"

class CPlayer {
private:
	int x, y, v, vx, vy;
	int life;
	const int R = 10;
	int invincible;
	int stopcount;
	int kaihiL, kaihiR, kaihiU, kaihiD;//�������x,y�ɑ�����������l�A���X�Ɍ����Ă���
	bool right, left, up, down;
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
	int GetKaihiU();
	int GetKaihiD();
	bool GetItem(int x,int y,int R);
};