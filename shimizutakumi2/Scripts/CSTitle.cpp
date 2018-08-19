#include "MyScene.h"

#include "Graphics.h"

void CSTitle::Start() {
	graph = "pho_test/swordEff_4.png";
}

void CSTitle::Loop() {
	if (Input.GetKeyEnter(Input.key.RETURN))
		Game.FlipScene(new CSHome());
}

void CSTitle::Draw() {
	float buf = 1;
	for (int i = 0; i < 10; ++i) {
		DrawBlendMode mode(DrawBlendMode::ADD, (int)(buf*255));
		graph(i * 40, 0);
		buf *= 192.f / 256.f;
	}
}

void CSTitle::End() {

}