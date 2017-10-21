#include "MyScene.h"

CSTitle::CSTitle() :save("stpic/save.txt") {}

void CSTitle::Start() {
	stage = 0;
	select = 1;
	count = 0;
	back = "stpic/title.png";
	number.Set(LoadDivGraph("stpic/number.png", 201, 201, 1, 64, 64),1);//ステージ数
	player.Set(LoadDivGraph("stpic/player.png", 2, 2, 1, 50, 30), 10);
	save.ReadAll();
	clear = -1;
	if (save.GetInt(0)) clear = 0;
	int buf = 0;
	for (int i = 1; i <= 7; i++) {
		buf = 0;
		buf += save.GetInt(3 * i - 2);
		buf += save.GetInt(3 * i - 1);
		buf += save.GetInt(3 * i);
		if (buf >= 2) {
			clear = i;
		}
	}
}

void CSTitle::Loop() {
	player.PlusCount();

	if (select == 1) {
		if (Input.GetKeyEnter(Input.key.SPACE)) {
			select = 2;
			back = "stpic/stageselect.png";
		}
	}

	if (select == 2) {
		if (count > 0) {
			number.PlusCount();
			--count;
		}

		if (count < 0) {
			number.MinusCount();
			++count;
		}

		switch (stage)//ステージ数
		{
		case 0:
		default:
			ver = 0;
			break;
		case 1:
		case 2:
		case 3:
			ver = 1;
			break;
		case 4:
		case 5:
		case 6:
			ver = 2;
			break;
		case 7:
		case 8:
		case 9:
			ver = 3;
			break;
		case 10:
		case 11:
		case 12:
			ver = 4;
			break;
		case 13:
		case 14:
		case 15:
			ver = 5;
			break;
		case 16:
		case 17:
		case 18:
			ver = 6;
			break;
		case 19:
		case 20:
		case 21:
			ver = 7;
			break;
		case 22:
		case 23:
		case 24:
			ver = 8;
			break;
		}

			if (Input.GetKeyDown(Input.key.RIGHT) && stage < 23 && count == 0 && (stage < clear * 3 + 3)) {//ステージ数
				count = 8;
				stage += 1;
			}
			if (Input.GetKeyDown(Input.key.LEFT) && stage > 0 && count == 0) {
				count = -8;
				stage -= 1;
			}
			
			if (Input.GetKeyEnter(Input.key.NUM0) && count == 0) {
				count = (0 - stage) * 8;
				stage = 0;
			}
			if (Input.GetKeyEnter(Input.key.NUM1) && count == 0 && clear >= 0) {
				count = (1 - stage) * 8;
				stage = 1;
			}
			else if (Input.GetKeyEnter(Input.key.NUM2) && count == 0 && clear >= 1) {
				count = (4 - stage) * 8;
				stage = 4;
			}
			else if (Input.GetKeyEnter(Input.key.NUM3) && count == 0 && clear >= 2) {
				count = (7 - stage) * 8;
				stage = 7;
			}
			else if (Input.GetKeyEnter(Input.key.NUM4) && count == 0 && clear >= 3) {
				count = (10 - stage) * 8;
				stage = 10;
			}
			else if (Input.GetKeyEnter(Input.key.NUM5) && count == 0 && clear >= 4) {
				count = (13 - stage) * 8;
				stage = 13;
			}
			else if (Input.GetKeyEnter(Input.key.NUM6) && count == 0 && clear >= 5) {
				count = (16 - stage) * 8;
				stage = 16;
			}
			else if (Input.GetKeyEnter(Input.key.NUM7) && count == 0 && clear >= 6) {
				count = (19 - stage) * 8;
				stage = 19;
			}

		if (stage == 19) {
			if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
				Game.FlipScene(new CSGame(100), Flip::FADE_OUT_IN);
			}
		}
		else if (stage == 10) {
			if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
				Game.FlipScene(new CSGame(101), Flip::FADE_OUT_IN);
			}
		}
		else if (stage == 13) {
			if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
				Game.FlipScene(new CSGame(102), Flip::FADE_OUT_IN);
			}
		}
		else if (stage == 22) {
			if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
				Game.FlipScene(new CSGame(103), Flip::FADE_OUT_IN);
			}
		}
		else if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
			Game.FlipScene(new CSGame(stage), Flip::FADE_OUT_IN);
		}
	}
}
	
	


void CSTitle::Draw() {
	back(0, 0);

	if (select == 2) {
		number(375, 200, false, false);
		switch (ver)
		{
		case 0:
		case 1:
		default:
			player(118, 350, false, false);
			break;
		case 2:
			player(204, 350, false, false);
			break;
		case 3:
			player(290, 350, false, false);
			break;
		case 4:
			player(376, 350, false, false);
			break;
		case 5:
			player(462, 350, false, false);
			break;
		case 6:
			player(548, 350, false, false);
			break;
		case 7:
		case 8:
			player(634, 350, false, false);
		}
		DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
		if (clear != 7) {
			DrawBox(98 + 86 * (clear < 0 ? 0 : 1 + clear), 385, 98 + 86 * 7, 535, BLACK, true);
		}
		DxLib::SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
}

void CSTitle::End() {

}