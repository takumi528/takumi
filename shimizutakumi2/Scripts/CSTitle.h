#pragma once
#include "Suken.h"
#include "select.h"


class CSTitle :public CScene {
	Graph graph;

	//�������@�摜�̃��[�h�Ȃǂ�
	void Start();
	//�����@���t���[���Ă΂��
	void Loop();
	//�`��@���t���[���Ă΂��
	void Draw();
	//��Еt��	FlipScene���ꂽ���ɌĂяo�����
	void End();
};