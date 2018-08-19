#pragma once
#include "Suken.h"

#include "ClassState.h"
#include "Decorator.h"
#include "Collision.h"

#include "weapon.h"
#include "sword.h"
#include "scrol.h"
#include "map.h"
#include "player.h"
#include "pub.h"
#include "item.h"
#include "possession.h"

/*
こんなところに書くけど、
敵は大きく分けて二種類作ればいいと思う。

一つ目は人型の敵。
武器を持っていて、プレイヤーと同じ武器クラスを流用する。
タスクシステムで人数を把握して、同時に命令を与えることで、
統率の取れた動きをする。

二つ目は非人型の敵
単純なAIで動く敵。非固定スクロールの場所に出す敵として便利

Enemyを継承して、それぞれに基本クラスを作ればいいと思う
*/

class Enemy {
public:
	Enemy();
	Enemy(int x, int y);
	~Enemy() = default;
	void Loop();
	void Move();
	virtual void Draw();//さらに書き加えたかったら継承する

	virtual void DrawBase();//こいつを継承して、武器なんかを上に書き加える

	virtual Circle GetHitBody()const;
	
	//状態関数
	virtual bool Normal() {
		return false;
	};


	//描画用関数
	void Deco();//エフェクトはここで掛ける
	virtual void NormalD();//Normalの描画

private:
	int x, y, vx, vy, cnt, r;
	float v;
	int direc;
	Drawing<Enemy> draw;//Setで描画関数を切り替える
	int life;
	int maxLife;
	State state;

	float GetRad();
};

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