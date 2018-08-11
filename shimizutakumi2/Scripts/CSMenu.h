#pragma once

#include "Suken.h"

bool Yes();
bool No();
bool Right();
bool Left();
bool Up();
bool Down();

class CSHome :public CScene {
	//�`�ϐ��錾�`
	Graph back;
	int chose;

	//�������@�摜�̃��[�h�Ȃǂ�
	void Start();
	//�����@���t���[���Ă΂��
	void Loop();
	//�`��@���t���[���Ă΂��
	void Draw();
	//��Еt��	�K�v�Ȃ�g����
	void End();

public:
	CSHome();
};

class CSStageSelect :public CScene {
	//�`�ϐ��錾�`
	int select;

	//�������@�摜�̃��[�h�Ȃǂ�
	void Start();
	//�����@���t���[���Ă΂��
	void Loop();
	//�`��@���t���[���Ă΂��
	void Draw();
	//��Еt��	�K�v�Ȃ�g����
	void End();

public:
	CSStageSelect();
};

class CSHelp :public CScene {
	//�`�ϐ��錾�`
	int num;
	Graph back[2];

	//�������@�摜�̃��[�h�Ȃǂ�
	void Start();
	//�����@���t���[���Ă΂��
	void Loop();
	//�`��@���t���[���Ă΂��
	void Draw();
	//��Еt��	�K�v�Ȃ�g����
	void End();

public:
	CSHelp();
};