#include "MyScene.h"

void CSComplete::Start() {
	SetBackGround("stpic/complete.png");
}

void CSComplete::Loop() {
	if (stage == 18) {
		if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
			Game.FlipScene(new CSGame(100));
		}
	}
	else if (stage == 9) {
		if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
			Game.FlipScene(new CSGame(101));
		}
	}
	else if (stage == 12) {
		if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
			Game.FlipScene(new CSGame(102));
		}
	}
	else if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
		Game.FlipScene(new CSGame(stage + 1));
	}

	if (Input.GetKeyEnter(Input.key.SPACE)) {
		Game.FlipScene(new CSTitle());
	}
}

void CSComplete::Draw() {

}

void CSComplete::End() {

}