#pragma once
#include "Suken.h"
#include "weapon.h"
#include "sword.h"
#include "scrol.h"
#include "map.h"
#include "player.h"
#include "pub.h"
#include "item.h"
#include "possession.h"

class CEnemy {
protected:
	int x, y, v, R;
	bool deleteFlag;
	int power;
	int knock;
	int drop;
	int life;
	int maxlife;
public:
	CEnemy();
	CEnemy(int x,int y,int v,int R,int power,int knock,int life);
	virtual void Move();
	virtual void Loop();
	virtual void Draw();
	void Disappear();
	bool WHit();
	bool SHit();
	int GetX();
	int GetY();
	int GetR();
	bool GetDeleteFlag();
	int GetPower();
	int GetKnock();
	int GetDrop();
};

class CEnemy0 :public CEnemy {
private:
public:
	CEnemy0(int x, int y, int v, int R, int power, int knock, int life);
	void Move();
	void Loop();
	void Draw();
};

class CEnemy2 :public CEnemy {
private:
	bool turn;
public:
	CEnemy2(int x, int y, int v, int R, int power, int knock, int life);
	void Move();
	void Loop();
	void Draw();
};

class CEnemy3 :public CEnemy {
private:
	int vx, vy;
	bool leftGo;//trueならしばらく左に直進、falseなら右 
	bool upGo;//trueならしばらく上に直進、falseなら下
	int Gocount;//↑のカウント
public:
	CEnemy3(int x, int y, int v, int R, int power, int knock, int life);
	void Move();
	void Loop();
	void Draw();
};

class CEnemyManager {
private:
	std::list<CEnemy*> enemy;
public:
	CEnemyManager();
	void Appear();
	void Move();
	void Draw();
	void Loop();
	void Disappear();
	bool WeaponDisappear(int x,int y,int r);
	int PHit(int x, int y, int r);
	int GerPower();
	int GetKnock();
};