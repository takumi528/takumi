#include "MyScene.h"

void CSComplete::Start() {
	if (stage == 23) {
		SetBackGround("stpic/completeend.png");
	}
	else {
		SetBackGround("stpic/complete.png");
	}
	CData save("stpic/save.txt");
	save.ReadAll();
	save.Set(stage,true);
	save.WriteAll();
}

void CSComplete::Loop() {
	if (stage == 18) {
		if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
			Game.FlipScene(new CSGame(100));
			Music.Play(M_SELECT);
		}
	}
	else if (stage == 9) {
		if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
			Game.FlipScene(new CSGame(101));
			Music.Play(M_SELECT);
		}
	}
	else if (stage == 12) {
		if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
			Game.FlipScene(new CSGame(102));
			Music.Play(M_SELECT);
		}
	}
	else if (stage == 21) {
		if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
			Game.FlipScene(new CSGame(103));
			Music.Play(M_SELECT);
		}
	}
	else if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
		Game.FlipScene(new CSGame(stage + 1));
		Music.Play(M_SELECT);
	}
	if (stage != 23) {
		if (Input.GetKeyEnter(Input.key.SPACE)) {
			Game.FlipScene(new CSTitle());
			Music.Play(M_SELECT);
		}
	}
	else {}
}

void CSComplete::Draw() {

}

void CSComplete::End() {

}