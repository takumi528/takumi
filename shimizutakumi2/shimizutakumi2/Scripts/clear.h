#pragma once
#include "Suken.h"
#include "pub.h"
#include "player.h"
#include "map.h"
#include "scrol.h"

class CClear {
private:
	Graph background, background2, redbar;
	int sentaku;
public:
	void Load();
	void Loop();
	void Draw();
};