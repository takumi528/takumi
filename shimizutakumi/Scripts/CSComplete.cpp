#include "MyScene.h"

void CSComplete::Start() {
	SetBackGround("stpic/complete.png");
}

void CSComplete::Loop() {
	if (Input.GetKeyEnter()) {
		Game.FlipScene(new CSTitle());

	}
}

void CSComplete::Draw() {

}

void CSComplete::End() {

}