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
	const int width = 50, height = 30;
};

struct Trap {
	int x, y;
	bool flag;
	const int width = 40, height = 40;
};

class CSGame :public CScene {
	//�`�ϐ��錾�`
	

	Graph player;
	Graph killer, chip,background,trap;
	int x, y, vy, vx, g;
	int scrolX;
	int jumpf;
	int stage;
	const int jWidth = 50, jHeight = 30;
	MCE mce;
	Killer  k,K[20];
	Trap t, T[50];
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

public:
	CSOver(int stage) :stage(stage) {}
};


class CSComplete :public CScene {
	//�`�ϐ��錾�`

	//�������@�摜�̃��[�h�Ȃǂ�
	void Start();
	//�����@���t���[���Ă΂��
	void Loop();
	//�`��@���t���[���Ă΂��
	void Draw();
	//��Еt��	�K�v�Ȃ�g����
	void End();
};
