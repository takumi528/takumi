#pragma once

#include "Suken.h"
#include "player.h"
#include "weapon.h"
#include "enemy.h"
#include "sword.h"
#include "map.h"
#include "scrol.h"
#include "pause.h"
#include "over.h"
#include "select.h"
#include "pub.h"
#include "clear.h"
#include "item.h"
#include "possession.h"
#include "obstacle.h"

class CS_Game :public CScene {
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
//	CS_Game(int stage):stage(stage) {}
};