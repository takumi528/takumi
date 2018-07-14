#pragma once
#include "Suken.h"
#include "scrol.h"
#include "map.h"

extern MCE mce;

extern int type;
extern bool retry;
extern bool back;
extern bool nextstage;
extern int kakunin;
extern int kakunincount;
extern int scrY;
extern int scrX;

class CPub {
private:
public:
	void Loop();
	void Draw();
};