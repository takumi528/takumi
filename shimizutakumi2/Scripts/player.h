#pragma once
#include "Suken.h"
#include "ClassState.h"

struct PlayerParameter {//�O�����͂Őݒ肵����
	float speed;
	float dushRate;
	float stepRate;
	int stepTime;
	int stopTime;
};

class Player {
private:
	int x, y, cnt;
	float v, vx, vy;//�����i�K�ł͏����ł����Ǝv��
	int direc, lastDirec;//direc * 45�K
	int life;
	const int R = 10;
	int invincible;
	const PlayerParameter param;
	State state;

	int GetInputDirec();//���Ŗ�����
	int GetRelativeDirec();//���͂ƌ��݂̑��Ίp�x
	float GetRad();

	template<class T>
	bool SetNextState(T *const ptr, bool (T::* func)()) {
		if (state.SetNextState(ptr, func)) {
			lastDirec = direc;
		}
	}
	//�ȉ����@�̏�Ԋ֐��@�`���U����������̒��Őݒ�ł���悤�ɂ���
	bool Normal();//true��Ԃ��Ǝ��̏�ԂɈڍs�B�ȉ�������
	bool Step();
	bool Clear();
	virtual bool AttackZN();//Z�L�[�U���񃅁[�g����
	virtual bool AttackXN();//X�L�[�U���񃅁[�g����
	virtual bool AttackZD();//Z�L�[�U���_�b�V��
	virtual bool AttackXD();//X�L�[�U���_�b�V��

public:
	Player(int x, int y);
	void Move();
	void Loop();
	void Draw();

	int GetX()const;
	int GetY()const;
	int GetV()const;
	int GetR()const;
	int GetLife()const;
	int Hit();

	bool GetItem(int x,int y,int R);
	bool EweaponDisappear(int x, int y, int R);
};