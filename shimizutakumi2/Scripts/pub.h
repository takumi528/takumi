#pragma once
#include "Suken.h"
#include "scrol.h"
#include "map.h"

extern MCE mce;

class CPub {
private:
	int type; //0->�^�C�g��,1->������,2->�Q�[���I�[�o�[,3->�|�[�Y���,4->�Q�[���N���A
	bool retry;
	bool back;
	bool nextstage;
	int kakunin;//�f�o�b�O�p�A�l��������ƍ�����OK�Əo��
public:
	void Loop();
	void Draw();
	int GetType();
	bool GetRetry();
	bool GetBack();
	bool GetNextstage();
	//�ȉ��͊e�M���̐؂�ւ��A1��true�ɁA0��false��
	void Changeretry(int a);
	void Changeback(int a);
	void Changenextstage(int a);
	void Changetype(int a);
};