#include "map.h"

extern CPlayer GetPlayer();
extern CEnemyManager GetEnemyManager();

int fixcount;//固定エリアの敵の数、0になるとfixを解く(enemyの出現時++)
int fixdelete;//fixdelete > 0　のとき　fixを解除

CMap::CMap() {
	fix = false;
	fixX = -1000;
	fixY = -1000;
	fixcount = 0;
}

void CMap::Load() {
	chip1 = "stpic/chip1.png";
	chip2 = "stpic/chip2.png";
	chip3 = "stpic/chip3.png";
}

void CMap::Set(int stage) {
	switch (stage) {
	case 0:
	default:
		mce = "MCE/stage0.mce";
		break;
	case 1:
		mce = "MCE/stage1.mce";
		break;
	case 2:
		mce = "MCE/stage2.mce";
		break;
	case 3:
		mce = "MCE/stage3.mce";
	}
}

void CMap::Loop() {
	if (fixdelete > 0) {
		FixReset2();
		fixdelete--;
	}

	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.C, i, j) == 1) {
				if (GetPlayer().GetX() > i * 40 + 20 - 300 && GetPlayer().GetX() < i * 40 + 20 + 300 && GetPlayer().GetY() > j * 40 + 20 - 300 && GetPlayer().GetY() < j * 40 + 20 + 300) {
					fixX = i * 40 + 20 - 300;
					fixY = j * 40 + 20 - 300;
				}
			}
		}
	}

	if (GetPlayer().GetLife() > 0) {
		if (GetPlayer().GetX() > fixX && GetPlayer().GetX() < fixX + 600 && GetPlayer().GetY() > fixY && GetPlayer().GetY() < fixY + 600) {
			fix = true;
		}
		else {
			fix = false;
		}
	}
	else {
		fix = false;
	}
}

void CMap::FixReset() {//リトライ、別ステージへの移動の時にfixをfalseにする、CSGameで使用
	fix = false;
	fixX = -1000;
	fixY = -1000;
}

void CMap::FixReset2() {//固定エリアの敵をすべて倒した時にfixをfalseにする
	for (int i = (GetPlayer().GetX() / 40) - 8; i <= (GetPlayer().GetX() / 40) + 8; i++) {
		for (int j = (GetPlayer().GetY() / 40) - 8; j <= (GetPlayer().GetY() / 40) + 8; j++) {
			if (mce.Get(mce.layer.C, i, j) == 1) {
				mce.Get(mce.layer.C, i, j) = 0;
			}
		}
	}
	fixX = -1000;
	fixY = -1000;
}

void CMap::Draw() {

	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 1) {
				chip1(i * 40 - scrX, j * 40 - scrY);
			}
		}
	}
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 2) {
				chip2(i * 40 - scrX, j * 40 - scrY);
			}
		}
	}
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 3) {
				chip3(i * 40 - scrX, j * 40 - scrY);
			}
		}
	}
	if (fix == true) {
		DrawFormatString(200, 0, WHITE, "aaaaa");
	}

	DrawFormatString(300, 300, RED, "%d", fixcount);
}

int CMap::GetWidth() {
	return mce.GetWidth();
}

int CMap::GetHeight() {
	return mce.GetHeight();
}

bool CMap::GetFix() {
	return fix;
}

int CMap::GetFixX() {
	return fixX;
}

int CMap::GetFixY() {
	return fixY;
}
