#pragma once
#include "Suken.h"
#include "scrol.h"
#include "player.h"
#include "enemy.h"
#include "pub.h"

//ŒÅ’è‚ÌƒZƒbƒg‚Íscrol‚Åˆ—


class CMap {
private:
	bool fix;
	int fixX, fixY;
	Graph chip1, chip2,chip3;
public:
	CMap();
	void Load();
	void Loop();
	void Set(int stage);
	void Draw();
	int GetWidth();
	int GetHeight();
	bool GetFix();
	int GetFixX();
	int GetFixY();
	void FixReset();
	void FixReset2();
};