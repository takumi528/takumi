#pragma once
#include "Suken.h"
#include "pub.h"
#include "player.h"
#include "enemy.h"
#include "weapon.h"
#include "possession.h"
#include "map.h"
#include "scrol.h"


class CItem {//宝箱
protected:
	int x,y;
	int R;
	bool deleteFlag;
	int drop;//アイテムのドロップ数
public:
	CItem();
	CItem(int x, int y, int R, int drop);
	virtual void Draw();
	bool Get();
	virtual void Loop();
	bool GetDeleteFlag();
	void Disappear();
};

class CItem2 :public CItem {
private:
public:
	CItem2(int x, int y, int R, int drop);
	void Draw();
	void Loop();
};

class CItem3 :public CItem {
private:
public:
	CItem3(int x, int y, int R, int drop);
	void Draw();
	void Loop();
};

class CItemManager {
private:
	std::list<CItem*> item;
public:
	CItemManager();
	void Draw();
	void Loop();
	void Set();
	void DIsappear();
};
