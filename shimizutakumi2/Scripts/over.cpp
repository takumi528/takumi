#include "over.h"

extern Player& GetPlayer();
//
//COver::COver() {
//	sentaku = 1;
//}
//
//void COver::Load() {
//	background = "stpic/gameover1.png";
//	background2 = "stpic/gameover2.png";
//	redbar = "stpic/redbar.png";
//}
//
//void COver::Loop() {
//	if (type == 1) {
//		if (GetPlayer().GetLife() <= 0) {
//			type = 2;
//		}
//	}
//	if (type == 2) {
//		if (Input.GetKeyEnter(Input.key.DOWN)) {
//			if (sentaku < 2) {
//				sentaku++;
//			}
//		}
//		if (Input.GetKeyEnter(Input.key.UP)) {
//			if (sentaku > 1) {
//				sentaku--;
//			}
//		}
//		if (Input.GetKeyEnter(Input.key.RETURN)) {
//			switch (sentaku) {
//			case 1:
//			default:
//				retry = true;
//				break;
//			case 2:
//				back = true;
//			}
//		}
//	}
//}
//
//void COver::Draw() {
//	DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
//	DrawBox(0, 0, 800, 600, BLACK, true);
//
//	background(0, 0);
//	background2(250, 150);
//	redbar(250, 150 + 100 * (sentaku - 1));
//}