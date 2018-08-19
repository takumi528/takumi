#pragma once

/**
*	@file	Collision.h
*	@brief	できるだけシンプルに
*	@author Photon
*/

#include <cmath>

#include "Suken.h"


#define DTR(deg) (DX_PI * deg / 180.f)


struct Circle;//要る
struct Sector;

interface Collision {
	Collision() = default;
	virtual ~Collision() = default;

	virtual bool Hit(Collision* c) {}//ダブルディスパッチです (用意してるだけなので使わなくてもよい)
	virtual bool Hit(Circle* c) {}
	virtual bool Hit(Sector* c) {}
};

struct Circle {
	Circle() :x(0), y(0), r(0) {}
	Circle(int x, int y, int r) :x(x), y(y), r(r) {}

	void Set(int x, int y, int r) {
		this->x = x;
		this->y = y;
		this->r = r;
	}

	int x, y, r;
};

struct Sector {//扇形
	Sector() :x(0), y(0), r(0), central(0), rad(0) {};
	Sector(int r, int central) :x(0), y(0), r(r), central((float)DTR(central/2)), rad(0) {};//処理上の都合でcentralは中心角の半分

	void Reset(int r, int central) {
		x = 0;
		y = 0;
		rad = 0;
		this->r = r;
		this->central = (float)DTR(central / 2);
	}

	void Set(int x, int y, float rad) {//radは回転角
		this->x = x;
		this->y = y;
		this->rad = rad;
	}

	void Draw() {//確認用 三角で表示
		suken::DrawTriangle(x, y, x + (int)(cosf(rad + central) * r), x + (int)(sinf(rad + central) * r), x + (int)(cosf(rad - central) * r), x + (int)(sinf(rad - central) * r), WHITE, false);
	}

	bool Hit(Circle* c);

	int x, y, r;
	float central, rad;
};

inline bool JudgeHit(Circle& c1, Circle& c2) {
	return (c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y) < (c1.r + c2.r) * (c1.r + c2.r);
}

inline bool JudgeHitE(Circle& c1, Circle& c2) {
	return (c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y) <= (c1.r + c2.r) * (c1.r + c2.r);
}

inline bool JudgeHit(Circle& c, Sector& s) {
	if ((c.x - s.x) * (c.x - s.x) + (c.y - s.y) * (c.y - s.y) < (c.r + s.r) * (c.r + s.r)) {
		float rad = s.rad - s.central;
		if (c.x*sinf(rad) - c.y*cosf(rad) < c.r) {//外積で直線との距離を判定
			rad = s.rad + s.central;
			if (c.y*cosf(rad) - c.x*sinf(rad) < c.r) {//外積で直線との距離を判定
				return true;
			}
		}
	}
	return false;
}