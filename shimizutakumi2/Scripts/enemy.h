#pragma once
#include "Suken.h"
#include <list>
#include <memory>
#include "weapon.h"
#include "sword.h"
#include "scrol.h"
#include "map.h"
#include "player.h"
#include "pub.h"
#include "item.h"
#include "possession.h"

template<class T>
class AbstractFactory {
public:
	AbstractFactory() = default;
	~AbstractFactory() = default;
	T* Create(std::vector<int>& index) = 0;
};

//汎用オブジェクト管理クラス
template<class T>
class ObjectManager {
public:
	typedef std::shared_ptr<T> TPtr;
	typedef std::list<TPtr> TList;
	ObjectManager() :factory(nullptr) {}
	~ObjectManager() {
		if (this->factory != nullptr)
			delete this->factory;
	}

	void SetFactory(AbstractFactory* factory) {
		if (this->factory != nullptr)
			delete this->factory;
		this->factory = factory;
	}

	void Create(std::vector<int>& request) {
		buffer.push_back(factory->Create(request));
	}

	void Create(T* ptr) {
		buffer.push_back(ptr);
	}

	TList& GetList() {
		return list;
	}

	TList& GetRecent() {
		return recent;
	}

	void Update() {
		for (auto it = list.begin(), end = list.end(); it != end;) {
			if (it->use_count() == 1) {
				it = list.erase(it);
			}
			else {
				++it;
			}
		}
		recent = buffer;
		if (!buffer.empty()) {
			list.splice(list.end(), buffer);
			buffer.clear();
		}
	}

private:
	TList list, buffer, recent;
	AbstractFactory* factory;
};

class CEnemy {
protected:
	int x, y, v, R;
	bool deleteFlag;
	int power;
	int knock;
	int drop;
	int life;
	int maxlife;
public:
	CEnemy();
	CEnemy(int x,int y,int v,int R,int power,int knock,int life);
	virtual void Move();
	virtual void Loop();
	virtual void Draw();
	void Disappear();
	bool WHit();
	bool SHit();
	int GetX();
	int GetY();
	int GetR();
	bool GetDeleteFlag();
	int GetPower();
	int GetKnock();
	int GetDrop();
};

class CEnemy0 :public CEnemy {
private:
public:
	CEnemy0(int x, int y, int v, int R, int power, int knock, int life);
	void Move();
	void Loop();
	void Draw();
};

class CEnemy2 :public CEnemy {
private:
	int turn;//1の時右に移動　-1の時左に移動
	int turncount;
public:
	CEnemy2(int x, int y, int v, int R, int power, int knock, int life);
	void Move();
	void Loop();
	void Draw();
};

class CEnemy3 :public CEnemy {
private:
	int vx, vy;
	bool leftGo;//trueならしばらく左に直進、falseなら右 
	bool upGo;//trueならしばらく上に直進、falseなら下
	int Gocount;//↑のカウント
public:
	CEnemy3(int x, int y, int v, int R, int power, int knock, int life);
	void Move();
	void Loop();
	void Draw();
};

class CEnemyManager {
private:
	std::list<CEnemy*> enemy;
public:
	CEnemyManager();
	void Appear();
	void Move();
	void Draw();
	void Loop();
	void Disappear();
	bool WeaponDisappear(int x,int y,int r);
	int PHit(int x, int y, int r);
	int GerPower();
	int GetKnock();
};