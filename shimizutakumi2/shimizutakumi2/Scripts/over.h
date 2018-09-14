#pragma once
#include "Suken.h"
#include "player.h"
#include "pub.h"


class COver {
private:
	Graph background,background2,redbar;
	int sentaku;
public:
	COver();
	void Load();
	void Loop();
	void Draw();
};
