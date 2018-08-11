#pragma once
#include "Suken.h"
#include "scrol.h"
#include "map.h"
#include "enemy.h"
#include "weapon.h"
#include "possession.h"
#include "obstacle.h"

//気にしなくていいよ。
class AbstractFuncHolder {
public:
	AbstractFuncHolder() = default;
	~AbstractFuncHolder() = default;
	virtual bool Main() = 0;
};

template<class T>
class FuncHolder:public AbstractFuncHolder {
public:
	typedef bool (T::* funcPtr)();
	FuncHolder(T* ptr, funcPtr func):ptr(ptr), func(func) {}
	~FuncHolder() = default;
	bool Main() {
		return (ptr->*func)();
	}
private:
	T*const ptr;
	funcPtr func;
};

class State {
public:
	template<class T>
	State(T *const ptr, bool (T::* func)()) :func(new FuncHolder<T>(ptr, func)), next(nullptr) {}

	~State() {
		if (func != nullptr)
			delete func;
		if (next != nullptr)
			delete next;
	}

	bool Main() {
		if (func->Main()) {
			if (func != nullptr && next != nullptr) {
				delete func;
				func = next;
				next = nullptr;
				return true;
			}
			else {
				throw "次の状態が設定されないまま状態関数でfalseが返されました";
			}
		}
		return false;
	}

	template<class T>
	bool SetNextState(T *const ptr, bool (T::* func)()) {//SetNextState(this, &Player::Normal)のように使う
		if (next == nullptr) {
			next = new FuncHolder<T>(ptr, func);
			return true;
		}
		return false;
	}
private:
	AbstractFuncHolder *func, *next;
};

struct PlayerParameter {//外部入力で設定したい
	float speed;
	float dushRate;
	float stepRate;
	int stepTime;
	int stopTime;
};

class CPlayer {
private:
	int x, y, cnt;
	float v;//処理段階では小数でいいと思う
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
	CPlayer();
	void Move();
	void Loop();
	void Draw();
	void Appear();
	//ステージごとにコンストラクタを呼び仕様のほうがいいので、Player()に機能を移行

	int GetX();
	int GetY();
	int GetV();
	int GetR();
	int GetLife();
	int Hit();

	bool GetItem(int x,int y,int R);
	bool EweaponDisappear(int x, int y, int R);
};