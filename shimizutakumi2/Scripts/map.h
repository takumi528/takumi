#pragma once
#include "Suken.h"
#include "scrol.h"
#include "player.h"
#include "enemy.h"
#include "pub.h"

//ŒÅ’è‚ÌƒZƒbƒg‚Íscrol‚Åˆ—

class Map {
public:
	typedef std::map<int, int> intMap;
	Map();
	~Map() = default;
	void Set(const char* file, int &px, int &py);
	void Draw(int scrX = 0, int scrY = 0);

	int GetStageWidth()const;
	int GetStageHeight()const;
	intMap& GetTrapData();
	intMap& GetEnemyData();
	int Code(int x, int y)const;

	static const int chipSize = 40;
private:
	static const int chipNum = 3;
	int width, height;
	int *chipData;
	Graph chipGraph[chipNum];
	std::map<int, int> trap, enemy;
};

class CMap {
private:
	bool fix;
	int fixX, fixY;
	Graph chip[3];
public:
	CMap();
	void Load();
	void Loop();
	void Set(int stage);
	void Draw();
	int GetWidth();
	int GetHeight();
	bool GetFix();
	int GetFixX();
	int GetFixY();
	void FixReset();
	void FixReset2();
};