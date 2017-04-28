#pragma once

/**
*	@file	MyScene.cpp
*	@brief	�V�[���N���X�̐錾�́A�����ł��܂��傤
*	@author	-
*/

#include "Suken.h"

#include "Addons\Window.h"

class CSTitle :public CScene {
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

class CSGame :public CScene {
	//�`�ϐ��錾�`
	Graph player;
	Graph killer,killer2, chip;
	int x, y, vy, vx, g, kx, ky, kx2, ky2;
	int scrolX;
	int jumpf;
	const int jWidth = 50, jHeight = 30;
	const int kWidth = 50, kHeight = 30;
	MCE mce;

	//�������@�摜�̃��[�h�Ȃǂ�
	void Start();
	//�����@���t���[���Ă΂��
	void Loop();
	//�`��@���t���[���Ă΂��
	void Draw();
	//��Еt��	�K�v�Ȃ�g����
	void End();

	void HitBlock(int x1, int y1);
};

class CSOver :public CScene {
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