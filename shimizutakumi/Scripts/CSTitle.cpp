#include "MyScene.h"

void CSTitle::Start() {
	stage = 1;
}

void CSTitle::Loop() {



	if (stage >= 1 && stage <= 2 && Input.GetKeyEnter(Input.key.DOWN)) {
		stage += 1;
	}

	if (stage >= 2 && stage <= 3 && Input.GetKeyEnter(Input.key.UP)) {
		stage -= 1;
	}


	if (stage == 1) {
		SetBackGround("stpic/title.png");
	}

	if (stage == 2) {
		SetBackGround("stpic/title2.png");
	}

	if (stage == 3) {
		SetBackGround("stpic/title3.png");
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

}

void CSTitle::End() {

}