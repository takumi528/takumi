#pragma once

/**
*	@file	MyScene.cpp
*	@brief	�V�[���N���X�̐錾�́A�����ł��܂��傤
*	@author	-
*/


#include "Suken.h"

#include "Addons\Window.h"





class CSTitle :public CScene {
	int stage;
	int version;
	int count;
	Graph back[3];
	Anim number;

	//�������@�摜�̃��[�h�Ȃǂ�
	void Start();
	//�����@���t���[���Ă΂��
	void Loop();
	//�`��@���t���[���Ă΂��
	void Draw();
	//��Еt��	FlipScene���ꂽ���ɌĂяo�����
	void End();
};

struct Rect {
	int left, right, top, bottom;
	Rect(int left, int right, int top, int bottom):
	left(left),
	right(right),
	top(top),
	bottom(bottom){}
};

struct Killer {
	int x, y;
	bool flag;
	static const int width = 50, height = 30;
};

struct Bird {
	int x, y;
	bool flag;
	static const int width = 40, height = 20;
};

struct Trap {
	int x, y;
	bool flag;
	static const int width = 30, height = 30;
};

struct Stone {
	int x, y;
	bool flag;
	static const int width = 30, height = 30;
};

struct Fat {
	int x, y;
	bool flag;
	static const int width = 70, height = 40;
};

struct Bat {
	int x, y;
	bool flag;
	bool turn;
	static const int width = 30, height = 30;
};

struct Ufo {
	int x, y;
	bool flag;
	bool turn;
	static const int width = 30, height = 20;
};

struct Fish {
	int x, y;
	bool flag;
	static const int width = 40, height = 20;
};

struct Urchin {
	int x, y;
	bool flag;
	static const int width = 35, height = 35;
};

struct Bone {
	int x, y;
	bool flag;
	static const int width = 30, height = 48;
};

struct Eel {
	int x, y;
	bool flag;
	static const int width = 150, height = 40;
};


class CSGame :public CScene {
	//�`�ϐ��錾�`
	

	Graph killer, chip1_1,chip1_2,chip2_1,chip2_2,chip3,chip4,chip5,background1,background2,background3,background4,background5,stone,gameover,fat,urchin,one_two,one_two_two,two_three,three_four,three_four_two;
	Anim bird,trap,bat,player,ufo,fish,bubble,bone,eel;
	int x, y, vy, vx, g, d;
	int scrolX;
	int jumpf;
	int stage;
	int version;
	static const int jWidth = 50, jHeight = 30;
	bool life;
	bool space;
	MCE mce;
	Killer k,K[20];
	Trap t, T[50];
	Stone s, S[50];
	Ufo u, U[50];
	Fat f, F[20];
	Bird b, B[20];
	Bat b2, B2[20];
	Fish f2, F2[20];
	Urchin u2, U2[50];
	Bone b3, B3[20];
	Eel e, E[20];
	int test[10];

	//�������@�摜�̃��[�h�Ȃǂ�
	void Start();
	//�����@���t���[���Ă΂��
	void Loop();
	//�`��@���t���[���Ă΂��
	void Draw();
	//��Еt��	�K�v�Ȃ�g����
	void End();

	void HitBlock(int x1, int y1);
	public:
		CSGame(int stage):stage(stage){}
};

class CSOver :public CScene {
	//�`�ϐ��錾�`
	int stage;

	//�������@�摜�̃��[�h�Ȃǂ�
	void Start();
	//�����@���t���[���Ă΂��
	void Loop();
	//�`��@���t���[���Ă΂��
	void Draw();
	//��Еt��	�K�v�Ȃ�g����
	void End();
};


class CSComplete :public CScene {
	//�`�ϐ��錾�`

	int stage;

	//�������@�摜�̃��[�h�Ȃǂ�
	void Start();
	//�����@���t���[���Ă΂��
	void Loop();
	//�`��@���t���[���Ă΂��
	void Draw();
	//��Еt��	�K�v�Ȃ�g����
	void End();
public:
	CSComplete(int stage) :stage(stage) {}
};
