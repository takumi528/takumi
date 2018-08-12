#include "Map.h"

extern Player& GetPlayer();
extern CEnemyManager& GetEnemyManager();


Map::Map() {}

void Map::Set(const char* file, int &px, int &py) {
	LoadDivGraph("stpic/chip.png", 3, 3, 1, 40, 40, chipGraph);
	MCE mce(file);
	width = mce.GetWidth();
	height = mce.GetHeight();
	chipData = new int[width*height];
	int buf;
	Key k;
	for (k.x = 0; k.x < width; ++k.x) {
		for (k.y = 0; k.y < height; ++k.y) {
			buf = mce(mce.layer.A, k.x, k.y);
			if (buf != 0)
				enemy[k.index] = buf - 1;

			buf = mce(mce.layer.B, k.x, k.y);
			if (buf != 0) {
				if (buf == 1) {//自機の初期位置
					px = k.x * chipSize + chipSize / 2;
					py = k.y * chipSize + chipSize / 2;
				}
				else {
					trap[k.index] = buf - 1;
				}
			}

			buf = mce(mce.layer.C, k.x, k.y);
			if (buf != 0)
				chipData[Code(k.x, k.y)] = buf - 1;
		}
	}
}

void Map::Draw(int scrX, int scrY) {//和差積算と比べると除算は超重いのでこのほうがいい
	for (int x = max(0, -scrX / chipSize), endX = min(width, x + System.GetWindowX() / chipSize + 1); x < endX; ++x) {
		for (int y = max(0, -scrY / chipSize), endY = min(height, y + System.GetWindowY() / chipSize + 1); y < endY; ++y) {
			chipGraph[chipData[Code(x, y)]](x * chipSize, y * chipSize);
		}
	}
}

int Map::GetWidth()const {
	return width;
}

int Map::GetHeight()const {
	return height;
}

int Map::GetStageWidth()const {
	return width * chipSize;
}

int Map::GetStageHeight()const {
	return height * chipSize;
}

Map::IntMap& Map::GetTrapData() {
	return trap;
}

Map::IntMap& Map::GetEnemyData() {
	return enemy;
}

int Map::Code(int x, int y)const{
	return x + y*width;
}



int fixcount;//固定エリアの敵の数、0になるとfixを解く(enemyの出現時++)
int fixdelete;//fixdelete > 0　のとき　fixを解除

CMap::CMap() {
	fix = false;
	fixX = -1000;
	fixY = -1000;
	fixcount = 0;
}

void CMap::Load() {
	LoadDivGraph("stpic/chip.png", 3, 3, 1, 40, 40, chip);
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
	}
}

void CMap::Loop() {
	if (fixdelete > 0) {
		FixReset2();
		fixdelete--;
	}

	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.B, i, j) == 1) {
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
			if (mce.Get(mce.layer.B, i, j) == 1) {
				mce.Get(mce.layer.B, i, j) = 0;
			}
		}
	}
	fixX = -1000;
	fixY = -1000;
}

void CMap::Draw() {

	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			chip[mce.Get(mce.layer.C, i, j)-1](i * 40 - scrX, j * 40 - scrY);
		}
	}
	if (fix == true) {
		DrawFormatString(200, 0, WHITE, "aaaaa");
	}

	DrawFormatString(300, 300, RED, "%d", fixdelete);

	/*for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.C, i, j) == 1) {
				DrawCircle(i * 40 - scrX, j * 40 - scrY, 300, GREEN, true);
			}
		}
	}*/
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
