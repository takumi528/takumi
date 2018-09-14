#pragma once
#include "Suken.h"
#include "scrol.h"
#include "map.h"
#include "enemy.h"
#include "weapon.h"
#include "possession.h"
#include "obstacle.h"
#include "sword.h"

class CPlayer {
private:
	int x, y, v, vx, vy;
	int life;
	const int R = 10;
	int invincible;
	int stopcount;//回避中true
	int kaihiL, kaihiR, kaihiU, kaihiD;//回避時にx,yに足し引きする値、徐々に減っていく
	bool right, left, up, down;
	int state;//0->静止、1->移動中、2->回避中、3->攻撃一段回目、4->攻撃二段階目、5->攻撃三段階目
	int statecount;//stateを維持するためのカウント(falseになったらstate = 0)
	int rad;//角度(時計回り、90度で割った値)
public:
	CPlayer();
	void Move();
	void Loop();
	void Draw();
	void Appear();
	int GetX();
	int GetY();
	int GetV();
	int GetR();
	int GetLife();
	int Hit();
	int GetKaihiU();
	int GetKaihiD();
	bool GetItem(int x,int y,int R);
	bool EweaponDisappear(int x, int y, int R);
	int GetState();
	int GetRad(int a);//radからaを足した値を返す
};