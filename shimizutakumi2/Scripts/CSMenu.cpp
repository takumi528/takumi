#include "MyScene.h"

bool Yes() {
	return Input.GetKeyEnter(Input.key.RETURN) || Input.GetKeyEnter(Input.key.Z);
}

bool No() {
	return Input.GetKeyEnter(Input.key.BACK) || Input.GetKeyEnter(Input.key.X);
}

bool Right() {
	return Input.GetKeyEnter(Input.key.RIGHT);
}

bool Left() {
	return Input.GetKeyEnter(Input.key.LEFT);
}

bool Up() {
	return Input.GetKeyEnter(Input.key.UP);
}

bool Down() {
	return Input.GetKeyEnter(Input.key.DOWN);
}

CSHome::CSHome() {

}

void CSHome::Start() {
	back = "stpic/home.png";
	chose = 0;
}

void CSHome::Loop() {
	if (Down()) {
		if (chose < 3) {
			chose++;
		}
	}
	if (Up()) {
		if (chose > 0) {
			chose--;
		}
	}
	if (Yes()) {
		switch (chose) {
		case 0:
		default:
			Game.FlipScene(new CSStageSelect());
			break;
		case 1:

			break;/*
		case 2:
			count2 = 5;
			scene = 4;
			break;*/
		case 3:
			Game.FlipScene(new CSHelp());
			break;
		}
	}
}

void CSHome::Draw() {
	back();
	DrawBox(0, 100 + 100 * chose, 400, 200 + 100 * chose, RED, false);
}

void CSHome::End() {

}



CSStageSelect::CSStageSelect() {

}

void CSStageSelect::Start() {
	select = 0;
}

void CSStageSelect::Loop() {
	if (Right() && select < 3) {
		++select;
	}
	if (Left() && select > 0) {
		--select;
	}
	if (Yes())
		Game.FlipScene(new CSGame(select));
	if (No())
		Game.FlipScene(new CSHome());
}

void CSStageSelect::Draw() {
	DrawFormatString(400, 300, RED, "%d", select);
}

void CSStageSelect::End() {

}

CSHelp::CSHelp() {
	num = 0;
	back[0] = "stpic/help1.png";
	back[1] = "stpic/help2.png";
}

void CSHelp::Start() {
	
}

void CSHelp::Loop() {
	if (Left() && num > 0)
		--num;
	if (Right() && num < 1)
		++num;
	if (No()) {
		Game.FlipScene(new CSHome());
	}
}

void CSHelp::Draw() {
	back[num]();
}

void CSHelp::End() {

}