#pragma once
#include "Suken.h"
#include "player.h"
#include "map.h"

//固定中はmapで処理

class CScrol {
private:
	bool fixset;//スクロールが固定されようとしているときはtrue
	int scrX;
	int scrY;
public:
	CScrol();
	void Loop();
	void ScrSet();//CSGameでscrを初期化
	bool GetFixset();
	int GetScrX();
	int GetScrY();
};