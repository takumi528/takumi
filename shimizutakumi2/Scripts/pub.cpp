#include "pub.h"

extern CMap GetMap();

MCE mce;

int type; //0->�^�C�g��,1->������,2->�Q�[���I�[�o�[,3->�|�[�Y���,4->�Q�[���N���A
bool retry;
bool back;
bool nextstage;
int mapY;
int kakunin;//�f�o�b�O�p�A�l��������ƍ�����OK�Əo��

void CPub::Loop() {
	mapY = scr - (GetMap().GetHeight() * 40 - 600);
	if (kakunin > 0) {
		kakunin--;
	}
}

void CPub::Draw() {
	if (kakunin > 0) {
		DrawFormatString(0, 500, RED, "OK");
	}
}
