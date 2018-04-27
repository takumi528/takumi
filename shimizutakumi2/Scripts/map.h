#pragma once
#include "Suken.h"
#include "scrol.h"
#include "player.h"
#include "enemy.h"
#include "pub.h"

extern int ex[1000];
extern int ey[1000];

class CMap {
public:
	CMap();
	void Load();
	void Set(int stage);
	void Draw();
	int GetWidth();
	int GetHeight();
	Graph chip1, chip2;
	int Ecount;
};