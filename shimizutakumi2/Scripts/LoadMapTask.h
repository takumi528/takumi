#pragma once

#include "Task.h"
#include "ObjectManager.h"

#include "MyObject.h"

class LoadMapTask:public Task {
public:
	LoadMapTask(Map *m,Scrol *s, OM<Enemy> *e) :m(m), s(s), e(e) {
		Load();
	}

	void Main() {
		Load();
	}

	void Load() {
		int size = m->chipSize;
		int x = m->GetWidth();
		int y = m->GetHeight();
		Map::IntMap& eData = m->GetEnemyData();
		int l = -s->GetScrX() / size;
		int u = -s->GetScrY() / size;
		int r = min(x, l + x + 2);//最低値画面右端+60
		int d = min(y, u + y + 2);//最低値画面下端+60
		l = max(0, l - 1);//最大値画面左端+60
		u = max(0, u - 1);//最大値画面上端+60

		le = l*size + size / 2;
		ue = u*size + size / 2;
		re = r*size + size / 2;
		de = d*size + size / 2;

		Map::Key k;
		for (auto it = eData.begin(), itEnd = eData.end(); it != itEnd; ++it) {
			k.index = it->first;
			if (k.x >= l && k.x <= r && k.y >= u && k.y <= d) {
				e->Create(std::vector<int>{it->second, k.x * size + size/2, k.y * size + size / 2});
			}
		}
	}

	void Delete() {
		auto l = e->GetList();
		for (auto it = l.begin(), itEnd = l.end(); it != itEnd; ++it) {

		}
	}

	bool checkDelete(int l, int u, int r, int d) {
		return (l < le && u < ue && r > re && d > de);
	}
private:
	Map *m;
	Scrol *s;
	OM<Enemy> *e;
	int le, re, ue, de;//オブジェクト消去範囲の端
};