#include "map.h"

extern CPlayer GetPlayer();
extern CEnemyManager GetEnemyManager();

int ex[1000];
int ey[1000];

CMap::CMap() {
	Ecount = 0;
}

void CMap::Load() {
	for (int i = 0; i < 1000; i++) {
		ex[i] = 0;
		ey[i] = 0;
	}
	chip1 = "stpic/chip1.png";
	chip2 = "stpic/chip2.png";
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

void CMap::Draw() {

	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 1) {
				chip1(i * 40, j * 40 + mapY);
			}
		}
	}
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 2) {
				chip2(i * 40, j * 40 + mapY);
			}
		}
	}

}

int CMap::GetWidth() {
	return mce.GetWidth();
}

int CMap::GetHeight() {
	return mce.GetHeight();
}

/*void CMap::GetEnemy() {
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.B, i, j) == 1) {
				ex[Ecount] = i * 40;
				ey[Ecount] = j * 40;
				Ecount += 1;
			}
		}
	}
}*/
