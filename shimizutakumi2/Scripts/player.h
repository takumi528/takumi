#pragma once
#include "Suken.h"

#include "ClassState.h"
#include "Decorator.h"
#include "Collision.h"
#include "Coord.h"

#include "Effect.h"

struct PlayerParameter {//外部入力で設定したい
	float speed;
	float dushRate;
	float stepRate;
	int stepTime;
	int stopTime;
};

class Player {
private:
	Coord c;
	int cnt;
	float v;//処理段階では小数でいいと思う
	int direc, lastDirec;//direc * 45゜
	int life;
	static const int R = 10;
	int invincible;
	const PlayerParameter param;
	State state;
	Graph graph[48];
	GraphHolder draw;
	Drawing<Player> deco;
	Collision* weapon;

	Effect effect;
	SwingEff swing;//仮

	AbstractDrawing *drawBase, *drawDeco;

	int GetInputDirec();//負で未入力
	int GetRelativeDirec();//入力と現在の相対角度
	float GetRad();

	template<class T>
	bool SetNextState(T *const ptr, bool (T::* func)()) {
		if (state.SetNextState(ptr, func)) {
			lastDirec = direc;
		}
	}
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
	void Draw();

	void Deco();

	void HitWall();

	int GetX()const;
	int GetY()const;
	int GetR()const;
	int& GetVX();
	int& GetVY();

	virtual Circle GetHitBody()const;
};