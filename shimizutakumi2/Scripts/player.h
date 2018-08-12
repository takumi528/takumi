#pragma once
#include "Suken.h"
#include "ClassState.h"

struct PlayerParameter {//外部入力で設定したい
	float speed;
	float dushRate;
	float stepRate;
	int stepTime;
	int stopTime;
};

class Player {
private:
	int x, y, cnt;
	float v, vx, vy;//処理段階では小数でいいと思う
	int direc, lastDirec;//direc * 45゜
	int life;
	const int R = 10;
	int invincible;
	const PlayerParameter param;
	State state;

	int GetInputDirec();//負で未入力
	int GetRelativeDirec();//入力と現在の相対角度
	float GetRad();
	//以下自機の状態関数　描画や攻撃判定もこの中で設定できるようにする
	bool Normal();//trueを返すと次の状態に移行。以下も同じ
	bool Step();
	bool Clear();
	virtual bool AttackZN();//Zキー攻撃二ュートラル
	virtual bool AttackXN();//Xキー攻撃二ュートラル
	virtual bool AttackZD();//Zキー攻撃ダッシュ
	virtual bool AttackXD();//Xキー攻撃ダッシュ

public:
	Player(int x, int y);
	void Move();
	void Loop();
	void Draw(int scrX=0, int scrY=0);

	int GetX()const;
	int GetY()const;
	int GetV()const;
	int GetR()const;
	int GetLife()const;
	int Hit();

	bool GetItem(int x,int y,int R);
	bool EweaponDisappear(int x, int y, int R);
};