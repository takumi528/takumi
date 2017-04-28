#include"MyScene.h"

void CSOver::Start() {
	SetBackGround("stpic/over.png");
}

void CSOver::Loop() {
	if (Input.GetKeyEnter()) {
		Game.FlipScene(new CSTitle());
	}
}

void CSOver::Draw() {

}

void CSOver::End() {

}