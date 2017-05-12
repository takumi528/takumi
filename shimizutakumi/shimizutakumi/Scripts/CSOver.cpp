#include"MyScene.h"

void CSOver::Start() {
	SetBackGround("stpic/over.png");
}

void CSOver::Loop() {
	if (Input.GetKeyEnter(Input.key.SPACE)) {
		Game.FlipScene(new CSTitle());
	}

	if (Input.GetKeyEnter(Input.key.NUMPADENTER) && stage == 1) {
		Game.FlipScene(new CSGame(1));
	}

	if (Input.GetKeyEnter(Input.key.NUMPADENTER) && stage == 2) {
		Game.FlipScene(new CSGame(2));
	}

	if (Input.GetKeyEnter(Input.key.NUMPADENTER) && stage == 3) {
		Game.FlipScene(new CSGame(3));
	}

}

void CSOver::Draw() {

}

void CSOver::End() {

}