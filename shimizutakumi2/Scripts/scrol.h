#pragma once
#include "Suken.h"
#include "player.h"
#include "map.h"

//�Œ蒆��map�ŏ���

class CScrol {
private:
	bool fixset;//�X�N���[�����Œ肳��悤�Ƃ��Ă���Ƃ���true
public:
	CScrol();
	void Loop();
	bool GetFixset();
};