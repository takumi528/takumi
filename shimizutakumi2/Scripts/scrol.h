#pragma once
#include "Suken.h"
#include <memory>

#include "Easing.h"

//固定中はmapで処理

//スクロールクラス。
class Scrol {
public:
	Scrol() {
		cnt = fixTime;
		scrX = 0;
		scrY = 0;
		fixX = 0;
		fixY = 0;
		isFixed = false;
	}

	bool SetFix(int fixX, int fixY) {
		if (isFixed) {
			return false;
		}
		else {
			this->fixX = System.GetWindowX() / 2 - fixX;//fx + sx = wx / 2
			this->fixY = System.GetWindowY() / 2 - fixY;
			isFixed = true;
			cnt = 0;
		}
		return true;
	}

	void RemoveFix() {
		cnt = 0;
		isFixed = false;
	}

	int GetScrX() {
		if (isFixed) {

		}
		return scrX;
	}
	int GetScrY() {
		if (isFixed) {

		}
		return scrY;
	}

private:
	int cnt;
	int scrX, scrY;
	int fixX, fixY;
	bool isFixed;
	static const int scrolSpeed = 5;
	static const int scrolRangeX = 300;
	static const int scrolRangeY = 200;
	static const int fixTime = 30;

	friend class ScrolTask;
};

class CScrol {
private:
	bool fixset;//スクロールが固定されようとしているときはtrue
public:
	CScrol();
	void Loop();
	bool GetFixset();
};