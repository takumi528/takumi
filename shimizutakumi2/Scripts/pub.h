#pragma once
#include "Suken.h"
#include "scrol.h"
#include "map.h"

extern MCE mce;

extern int type;
extern bool retry;
extern bool back;
extern bool nextstage;
extern int mapY;
extern int kakunin;
extern int kakunincount;

class CPub {
private:
public:
	void Loop();
	void Draw();
};