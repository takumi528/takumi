#pragma once
#include "Suken.h"
#include "player.h"
#include "map.h"

//固定中はmapで処理

class CScrol {
private:
	bool fixset;//スクロールが固定されようとしているときはtrue
public:
	CScrol();
	void Loop();
	bool GetFixset();
};