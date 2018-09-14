#include "MyScene.h"

void CSTitle::Start() {
}

void CSTitle::Loop() {
	if (Input.GetKeyEnter()) {
		Game.FlipScene(new CSGame(100), Flip::FADE_OUT_IN);
	}
}
	

void CSTitle::Draw() {
}

void CSTitle::End() {

}