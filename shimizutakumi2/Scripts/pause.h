#pragma once
#include "Suken.h"
#include "pub.h"

#include "map.h"
#include "player.h"
#include "over.h"
#include "weapon.h"
#include "select.h"

class CPause {
private:
	Graph background, hpbar, background2, redbar, weaponiconFrame ,weaponicon1, weaponicon2, partsicon1;
	int sentaku;
public:
	CPause();
	void Load();
	void Loop();
	void Draw();
};
