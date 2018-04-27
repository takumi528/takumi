#include "pause.h"

extern CMap GetMap();
extern CPlayer GetPlayer();
extern CWeaponManager GetWeaponManager();
extern CSelect GetSelect();

extern int Pown1;
extern int Pown2;
extern int Pown3;
extern int Pown4;

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
	background(GetMap().GetWidth() * 40, 0);
	hpbar(GetMap().GetWidth() * 40 + 20, 30);
	DrawBox(GetMap().GetWidth() * 40 + 60, 30 + 1, GetMap().GetWidth() * 40 + 60 + GetPlayer().GetLife(), 50 - 1, RED, true);
	weaponicon1(GetMap().GetWidth() * 40 + 25, 60);
	DrawFormatString(GetMap().GetWidth() * 40 + 25, 60 + 30, BLACK, "%d", Pown1);
	weaponicon2(GetMap().GetWidth() * 40 + 65, 60);
	DrawFormatString(GetMap().GetWidth() * 40 + 65, 60 + 30, BLACK, "%d", Pown2);

	partsicon1(GetMap().GetWidth() * 40 + 25, 130);
	DrawFormatString(GetMap().GetWidth() * 40 + 25, 130 + 30, BLACK, "%d", parts[1]);

	weaponiconFrame(GetMap().GetWidth() * 40 + 25 + (GetWeaponManager().GetChange() - 1) * 40, 60);
	if (type == 3) {
		DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
		DrawBox(0, 0, GetMap().GetWidth() * 40, 600, BLACK, true);
		background2(150, 150);
		redbar(150, 150 + 100 * (sentaku - 1));
	}
}