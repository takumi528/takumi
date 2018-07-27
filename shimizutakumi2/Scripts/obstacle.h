#pragma once
#include "Suken.h"
#include "pub.h"
#include "map.h"

class CObstacle {
private:
	int x, y, R;
	bool deleteFlag;
public:
	CObstacle();
	CObstacle(int x, int y, int r);
	virtual void Draw();
	void Loop();
	void Disappear();
	bool GetDeleteFlag();
	int GetX();
	int GetY();
	int GetR();
};

class CObstacleManager {
private:
	std::list<CObstacle*> obstacle;
public:
	CObstacleManager();
	void Appear();
	void Draw();
	void Loop();
	void Disappear();
	bool Hit(int x, int y, int R);
};