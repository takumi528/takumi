#include"MyScene.h"

void CSOver::Start() {
	SetBackGround("stpic/over.png");
}

void CSOver::Loop() {
	if (Input.GetKeyEnter(Input.key.SPACE)) {
		Game.FlipScene(new CSTitle());
	}

	
		if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
			Game.FlipScene(new CSGame(1));
		}

}

void CSOver::Draw() {

}

void CSOver::End() {

}