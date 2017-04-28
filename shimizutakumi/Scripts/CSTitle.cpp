#include "MyScene.h"

void CSTitle::Start() {
	SetBackGround("stpic/title.png");
}

void CSTitle::Loop() {
	if (Input.GetKeyEnter()) {
		Game.FlipScene(new CSGame(),Flip::FADE_OUT_IN);
	}
}

void CSTitle::Draw() {

}

void CSTitle::End() {

}