#pragma once
#include "Suken.h"

#include "pub.h"
#include "possession.h"
class CSelect {
private:
	Graph background,background3,background31_1,background31_2,background4,background41_1,background41_2,background51,background52,redbar,redbar2,redbar3,blackbox,blackbox2,sozai,seinou,mybag,swordicons,gunicons,armaricons;
	int stage;
	int count;
	int scene;//1:�z�[���A2:�X�e�[�W�I���A3:�J�X�^�}�C�Y�A4:�A�C�e�������A5:�w���v
	int sentaku,sentaku3,sentaku31,sentaku4,sentaku41,sentaku5;
	int count2;//�L�[�{�[�h�̏������A������̂�}����
	bool mybagflag;
public:
	CSelect();
	void Load();
	void Loop();
	void Draw();
	int GetStage();
	int GetScene();
	int GetCount2();
};