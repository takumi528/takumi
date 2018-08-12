#pragma once

#include "Suken.h"
#include <memory>

#include "Task.h"
#include "ObjectManager.h"

#include "MyObject.h"

class CSGame :public CScene {
	//�`�ϐ��錾�`
	int stage;
	TaskManager task;
	std::unique_ptr<Player> player;//���j�[�N�Q�|�C���^���g���Ă��܂�
	ObjectManager<Enemy> enemy;
	Map map;
	Scrol scrol;

	//�������@�摜�̃��[�h�Ȃǂ�
	void Start();
	//�����@���t���[���Ă΂��
	void Loop();
	//�`��@���t���[���Ă΂��
	void Draw();
	//��Еt��	�K�v�Ȃ�g����
	void End();

public:
	CSGame(int stage);
};