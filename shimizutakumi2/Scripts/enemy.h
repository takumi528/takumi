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
#include "CSGame.h"

class CEnemy {
protected:
	int x, y, v, R;
	bool deleteFlag;
	int power;
	int knock;
	int drop;
	int life;
	int maxlife;
	bool koflag;//固定の敵ならtrue,それ以外はfalse
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
	int GetLife();
	bool GetKoflag();
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
	int turn;//1の時右に移動　-1の時左に移動
	int turncount;
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
	int fixcount;//固定エリア内の敵の数
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
	//以下死んだときの座標とドロップ情報(アイテムドロップ時に使用)
	int GetDx();
	int GetDy();
	int GetDdrop();
	bool GetDkoflag();//倒した敵が固定かどうか
	int GetFixcount();
	void ReduceFixcount();
};