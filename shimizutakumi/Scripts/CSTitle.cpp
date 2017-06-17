#include "MyScene.h"

void CSTitle::Start() {
	stage = 0;
	back[0] = "stpic/title0.png";
	back[1] = "stpic/title.png";
	back[2] = "stpic/title2.png";
	count = 0;
	number.Set(LoadDivGraph("stpic/number.png", 104, 104, 1, 64, 64),1);
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

	switch (stage)
	{
	case 0:
	default:
		version = 0;
		break;
	case 1:
		version = 1;
		break;
	case 2:
		version = 1;
		break;
	case 3:
		version = 1;
		break;
	case 4:
		version = 2;
		break;
	case 5:
		version = 2;
		break;
	case 6:
		version = 2;
		break;
	case 7:
		version = 3;
		break;
	case 8:
		version = 3;
		break;
	case 9:
		version = 3;
		break;
	case 10:
		version = 4;
		break;
	case 11:
		version = 4;
		break;
	case 12:
		version = 4;
		break;
	}


	if (Input.GetKeyEnter(Input.key.RIGHT) && stage < 12){
		stage += 1;
		count = 8;
	}
	

	if (Input.GetKeyEnter(Input.key.LEFT) && stage > 0){
		stage -= 1;
		count = -8;
	}
	

	if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
		Game.FlipScene(new CSGame(stage), Flip::FADE_OUT_IN);
	}

}
	
	


void CSTitle::Draw() {
	if (version == 3) {
		back[2]();
	}
	else {
		if (version == 0) {
			back[0]();
		}
		else {
			back[1]();
		}
	}

	/*if (stage == 0) {
		SetFontSize(40);
		DrawFormatString(350, 440, YELLOW, "チュートリアル");
	}

	if (stage == 0) {
		SetFontSize(70);
		DrawFormatString(560, 430, YELLOW, "0");
	}

	if (stage == 1){
		SetFontSize(70);
		DrawFormatString(560,430,YELLOW,"1");
	}

	if (stage == 2){
		SetFontSize(70);
		DrawFormatString(560,430,YELLOW,"2");
	}

	if (stage == 3){
		SetFontSize(70);
		DrawFormatString(560,430,YELLOW,"3");
	}

	if (stage == 4) {
		SetFontSize(70);
		DrawFormatString(560, 430, GREEN, "4");
	}
	if (stage == 5) {
		SetFontSize(70);
		DrawFormatString(560, 430, GREEN, "5");
	}
	if (stage == 6) {
		SetFontSize(70);
		DrawFormatString(560, 430, GREEN, "6");
	}
	if (stage == 7) {
		SetFontSize(70);
		DrawFormatString(560, 430, CYAN, "7");
	}
	if (stage == 8) {
		SetFontSize(70);
		DrawFormatString(560, 430, CYAN, "8");
	}
	if (stage == 9) {
		SetFontSize(70);
		DrawFormatString(560, 430, CYAN, "9");
	}*/
	
	number(550, 435, false, false);
}

void CSTitle::End() {

}