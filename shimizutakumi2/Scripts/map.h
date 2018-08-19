#pragma once
#include "Suken.h"
#include "scrol.h"
#include "player.h"
#include "enemy.h"
#include "pub.h"

//å≈íËÇÃÉZÉbÉgÇÕscrolÇ≈èàóù

class Map {
public:
	union Key {
		int index;
		struct {
			short x;
			short y;
		};
		Key() :index(0) {}
		Key(short x, short y) :x(x), y(y) {}
	};
	typedef std::map<int, int> IntMap;
	
	Map();
	~Map() = default;
	void Set(const char* file, int &px, int &py);
	void Draw(int scrX, int scrY);

	int GetWidth()const;
	int GetHeight()const;
	int GetStageWidth()const;
	int GetStageHeight()const;
	IntMap& GetTrapData();
	IntMap& GetEnemyData();

	bool IsWall(int x, int y)const;

	int Code(int x, int y)const;

	static const int chipSize = 40;
private:
	static const int chipNum = 3;
	int width, height;
	int *chipData;
	Graph chipGraph[chipNum];
	IntMap trap, enemy;
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