#include "MyScene.h"

void CSTitle::Start() {
}

void CSTitle::Loop() {
	if (Input.GetKeyEnter(Input.key.RETURN))
		Game.FlipScene(new CSHome());
}

void CSTitle::Draw() {
}

void CSTitle::End() {

}