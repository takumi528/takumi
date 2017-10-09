#include "MyScene.h"

void CSTitle::Start() {
	stage = 0;
	back[0] = "stpic/title0.png";
	back[1] = "stpic/title1.png";
	back[2] = "stpic/title2.png";
	count = 0;
	number.Set(LoadDivGraph("stpic/number.png", 201, 201, 1, 64, 64),1);//ステージ数
	}

void CSTitle::Loop() {
	if (count > 0) {
		number.PlusCount();
		--count;
	}

	if (count < 0) {
		number.MinusCount();
		++count;
	}

	switch (stage)//ステージ数
	{
	case 0:
	default:
		ver = 0;
		break;
	case 1:
	case 2:
	case 3:
		ver = 1;
		break;
	case 4:
	case 5:
	case 6:
		ver = 2;
		break;
	case 7:
	case 8:
	case 9:
		ver = 3;
		break;
	case 10:
	case 11:
	case 12:
		ver = 4;
		break;
	case 13:
	case 14:
	case 15:
		ver = 5;
		break;
	case 16:
	case 17:
	case 18:
		ver = 6;
		break;
	case 19:
	case 20:
	case 21:
		ver = 7;
		break;
	case 22:
	case 23:
	case 24:
		ver = 8;
		break;
	}


	if (Input.GetKeyDown(Input.key.RIGHT) && stage < 24 && count == 0){//ステージ数
		stage += 1;
		count = 8;
	}
	

	if (Input.GetKeyDown(Input.key.LEFT) && stage > 0 && count == 0){
		stage -= 1;
		count = -8;
	}
	
	if (stage == 19) {
		if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
			Game.FlipScene(new CSGame(100), Flip::FADE_OUT_IN);
		}
	}
	else if (stage == 10) {
		if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
			Game.FlipScene(new CSGame(101), Flip::FADE_OUT_IN);
		}
	}
	else if (stage == 13) {
		if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
			Game.FlipScene(new CSGame(102), Flip::FADE_OUT_IN);
		}
	}
	else if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
		Game.FlipScene(new CSGame(stage), Flip::FADE_OUT_IN);
	}

}
	
	


void CSTitle::Draw() {
	if (ver >=7) {
		back[2]();
	}
	else {
		if (ver == 0) {
			back[0]();
		}
		else {
			back[1]();
		}
	}
	
	number(550, 435, false, false);
}

void CSTitle::End() {

}