#include "MyScene.h"

void CSTitle::Start() {
	stage = 1;
}

void CSTitle::Loop() {

	if (Input.GetKeyEnter(Input.key.RIGHT) && stage < 3){
	stage += 1;
	}

	if (Input.GetKeyEnter(Input.key.LEFT) && stage > 1){
	stage -= 1;
	}

	if (Input.GetKeyEnter(Input.key.NUMPADENTER) && stage == 1) {
		Game.FlipScene(new CSGame(1), Flip::FADE_OUT_IN);
	}

	if (Input.GetKeyEnter(Input.key.NUMPADENTER) && stage == 2) {
		Game.FlipScene(new CSGame(2), Flip::FADE_OUT_IN);
	}


	if (Input.GetKeyEnter(Input.key.NUMPADENTER) && stage == 3) {
		Game.FlipScene(new CSGame(3), Flip::FADE_OUT_IN);
	}

}
	
	


void CSTitle::Draw() {
	if (stage == 3) {
		SetBackGround("stpic/title2.png");
	}
	else { SetBackGround("stpic/title.png");
	}

	//ステ数　変更２

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
	DrawFormatString(560,430,CYAN,"3");
	}


}

void CSTitle::End() {

}