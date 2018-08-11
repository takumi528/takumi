#pragma once
#include "Suken.h"
#include "scrol.h"
#include "map.h"
#include "enemy.h"
#include "weapon.h"
#include "possession.h"
#include "obstacle.h"

//�C�ɂ��Ȃ��Ă�����B
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
				throw "���̏�Ԃ��ݒ肳��Ȃ��܂܏�Ԋ֐���false���Ԃ���܂���";
			}
		}
		return false;
	}

	template<class T>
	bool SetNextState(T *const ptr, bool (T::* func)()) {//SetNextState(this, &Player::Normal)�̂悤�Ɏg��
		if (next == nullptr) {
			next = new FuncHolder<T>(ptr, func);
			return true;
		}
		return false;
	}
private:
	AbstractFuncHolder *func, *next;
};

struct PlayerParameter {//�O�����͂Őݒ肵����
	float speed;
	float dushRate;
	float stepRate;
	int stepTime;
	int stopTime;
};

class CPlayer {
private:
	int x, y, cnt;
	float v;//�����i�K�ł͏����ł����Ǝv��
	int direc, lastDirec;//direc * 45�K
	int life;
	const int R = 10;
	int invincible;
	const PlayerParameter param;
	State state;

	int GetInputDirec();//���Ŗ�����
	int GetRelativeDirec();//���͂ƌ��݂̑��Ίp�x
	float GetRad();
	//�ȉ����@�̏�Ԋ֐��@�`���U����������̒��Őݒ�ł���悤�ɂ���
	bool Normal();//true��Ԃ��Ǝ��̏�ԂɈڍs�B�ȉ�������
	bool Step();
	bool Clear();
	virtual bool AttackZN();//Z�L�[�U���񃅁[�g����
	virtual bool AttackXN();//X�L�[�U���񃅁[�g����
	virtual bool AttackZD();//Z�L�[�U���_�b�V��
	virtual bool AttackXD();//X�L�[�U���_�b�V��

public:
	CPlayer();
	void Move();
	void Loop();
	void Draw();
	void Appear();
	//�X�e�[�W���ƂɃR���X�g���N�^���Ăюd�l�̂ق��������̂ŁAPlayer()�ɋ@�\���ڍs

	int GetX();
	int GetY();
	int GetV();
	int GetR();
	int GetLife();
	int Hit();

	bool GetItem(int x,int y,int R);
	bool EweaponDisappear(int x, int y, int R);
};