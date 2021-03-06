#include "clear.h"

extern CPlayer& GetPlayer();
extern CMap& GetMap();
extern CScrol& GetScrol();
extern CPub& GetPub();

void CClear::Load() {
	sentaku = 1;
	background = "stpic/clear.png";
	background2 = "stpic/clear2.png";
	redbar = "stpic/redbar2.png";
}

void CClear::Loop() {
	if (GetPlayer().GetY() <= 0) {
		GetPub().Changetype(4);
	}
	if (GetPub().GetType() == 4) {
		if (Input.GetKeyEnter(Input.key.DOWN)) {
			if (sentaku < 2) {
				sentaku++;
			}
		}
		if (Input.GetKeyEnter(Input.key.UP)) {
			if (sentaku > 1) {
				sentaku--;
			}
		}

		if (Input.GetKeyEnter(Input.key.RETURN)) {
			switch (sentaku) {
			case 1:
			default:
				GetPub().Changenextstage(1);
				break;
			case 2:
				GetPub().Changeback(1);
			}
		}
	}
}

void CClear::Draw() {
	DrawBox(0, 300 - GetScrol().GetScrY(), GetMap().GetWidth() * 40, 300 - GetScrol().GetScrY() + 5, RED, true);
	if (GetPub().GetType() == 4) {
		background(0, 0);
		background2(200, 200);
		redbar(200, 200 + 100 * (sentaku - 1));
	}
}