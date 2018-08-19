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
����ȂƂ���ɏ������ǁA
�G�͑傫�������ē��ލ��΂����Ǝv���B

��ڂ͐l�^�̓G�B
����������Ă��āA�v���C���[�Ɠ�������N���X�𗬗p����B
�^�X�N�V�X�e���Ől����c�����āA�����ɖ��߂�^���邱�ƂŁA
�����̎�ꂽ����������B

��ڂ͔�l�^�̓G
�P����AI�œ����G�B��Œ�X�N���[���̏ꏊ�ɏo���G�Ƃ��ĕ֗�

Enemy���p�����āA���ꂼ��Ɋ�{�N���X�����΂����Ǝv��
*/

class Enemy {
public:
	Enemy();
	Enemy(int x, int y);
	~Enemy() = default;
	void Loop();
	void Move();
	virtual void Draw();//����ɏ�����������������p������

	virtual void DrawBase();//�������p�����āA����Ȃ񂩂���ɏ���������

	virtual Circle GetHitBody()const;
	
	//��Ԋ֐�
	virtual bool Normal() {
		return false;
	};


	//�`��p�֐�
	void Deco();//�G�t�F�N�g�͂����Ŋ|����
	virtual void NormalD();//Normal�̕`��

private:
	int x, y, vx, vy, cnt, r;
	float v;
	int direc;
	Drawing<Enemy> draw;//Set�ŕ`��֐���؂�ւ���
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
	int turn;//1�̎��E�Ɉړ��@-1�̎����Ɉړ�
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
	bool leftGo;//true�Ȃ炵�΂炭���ɒ��i�Afalse�Ȃ�E 
	bool upGo;//true�Ȃ炵�΂炭��ɒ��i�Afalse�Ȃ牺
	int Gocount;//���̃J�E���g
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