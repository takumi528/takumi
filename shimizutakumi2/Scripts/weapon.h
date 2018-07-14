#pragma once
#include "Suken.h"
#include "player.h"
#include "enemy.h"
#include "scrol.h"
#include "pub.h"
#include "item.h"
#include "possession.h"



class CWeapon {
protected:
	int x, y, v;
	const int R = 3;
	bool deleteFlag;
	int power;
	int direction;//0:直進、1:右斜め前、2:左斜め前
public:
	CWeapon();
	CWeapon(int x,int y,int v, int power, int direction);
	void Move();
	void Loop();
	virtual void Draw();
	bool Disappear();
	int GetX();
	int GetY();
	int GetR();
	bool GetDeleteFlag();
	int GetPower();
};

class CWeaponManager {
private:
	std::list<CWeapon*> weapon;
public:
	CWeaponManager();
	void Appear(int x,int y);
	void Move();
	void Draw();
	void Loop();
	int count;
	bool Hit(int x, int y,int r);
	void PAttack();
	int GetPower();

};
