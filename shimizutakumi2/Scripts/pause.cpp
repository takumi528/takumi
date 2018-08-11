#include "pause.h"

extern CMap& GetMap();
extern CPlayer& GetPlayer();
extern CWeaponManager& GetWeaponManager();
extern CSelect& GetSelect();

extern int parts[30];

CPause::CPause() {
	sentaku = 1;
}

void CPause::Load() {
	background = "stpic/pause.png";
	hpbar = "stpic/HPbar.png";
	background2 = "stpic/pause2.png";
	redbar = "stpic/redbar.png";
	weaponiconFrame = "stpic/weaponiconFrame.png";
	weaponicon1 = "stpic/weaponicon1.png";
	weaponicon2 = "stpic/weaponicon2.png";
	partsicon1 = "stpic/partsicon1.png";
}
void CPause::Loop() {
		if (Input.GetKeyEnter(Input.key.P)) {
			switch (type) {
			case 0:
				break;
			case 1:
			default:
				type = 3;
				break;
			case 2:
				break;
			case 3:
				type = 1;
			}
		}
	if (type == 3) {
		if (sentaku < 3) {
			if (Input.GetKeyEnter(Input.key.DOWN)) {
				sentaku++;
			}
		}
		if (sentaku > 1) {
			if (Input.GetKeyEnter(Input.key.UP)) {
				sentaku--;
			}
		}
	}
	if(type == 3){
		if (Input.GetKeyEnter(Input.key.RETURN)) {
			switch (sentaku) {
			case 1:
			default:
				type = 1;
				break;
			case 2:
				retry = true;
				break;
			case 3:
				back = true;
			}
		}
	}
}

void CPause::Draw() {
	SetFontSize(20);
	background(600, 0);
	hpbar(600 + 20, 30);
	DrawBox(600 + 60, 30 + 1, 600 + 60 + GetPlayer().GetLife(), 50 - 1, RED, true);

	partsicon1(600 + 25, 130);
	DrawFormatString(600 + 25, 130 + 30, BLACK, "%d", parts[1]);

	if (type == 3) {
		DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
		DrawBox(0, 0, 600, 600, BLACK, true);
		background2(150, 150);
		redbar(150, 150 + 100 * (sentaku - 1));
	}
}