#pragma once
#include "Suken.h"

#include "ClassState.h"
#include "Decorator.h"
#include "Collision.h"
#include "Coord.h"

#include "Effect.h"

struct PlayerParameter {//�O�����͂Őݒ肵����
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
	float v;//�����i�K�ł͏����ł����Ǝv��
	int direc, lastDirec;//direc * 45�K
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
	SwingEff swing;//��

	AbstractDrawing *drawBase, *drawDeco;

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

	void Deco();

	void HitWall();

	int GetX()const;
	int GetY()const;
	int GetR()const;
	int& GetVX();
	int& GetVY();

	virtual Circle GetHitBody()const;
};