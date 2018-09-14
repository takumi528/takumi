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
	int stopcount;//���true
	int kaihiL, kaihiR, kaihiU, kaihiD;//�������x,y�ɑ�����������l�A���X�Ɍ����Ă���
	bool right, left, up, down;
	int state;//0->�Î~�A1->�ړ����A2->��𒆁A3->�U����i��ځA4->�U����i�K�ځA5->�U���O�i�K��
	int statecount;//state���ێ����邽�߂̃J�E���g(false�ɂȂ�����state = 0)
	int rad;//�p�x(���v���A90�x�Ŋ������l)
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
	int GetRad(int a);//rad����a�𑫂����l��Ԃ�
};