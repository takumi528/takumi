#pragma once

#include "Task.h"

#include "MyObject.h"

class HitTask: public Task {
public:
	HitTask(Player *p, OM<Enemy> *e, Map* map) :p(p), e(e), map(map) {}

	~HitTask() = default;

	void Main() {
		{
			int &vx = p->GetVX();
			int &vy = p->GetVY();
			int x = p->GetX();
			int y = p->GetY();
			int r = p->GetR();
			int size = map->chipSize;
			int bx = 0;
			int by = 0;

			for (int mxB = (x + vx - r) / size, mx = mxB, mxE = (x + vx + r) / size; mx <= mxE; ++mx) {
				for (int myB = (y + vy - r) / size, my = myB, myE = (y + vy + r) / size; my <= myE; ++my) {
					if (vx > 0 && mx != mxB) {
						if (map->IsWall(mx, my) && !map->IsWall(mx - 1, my) && x + vx + r > mx*size) {
							bx = min(bx, mx*size - x - r - vx);
						}
					}
					else if (vx < 0 && mx != mxE) {
						if (map->IsWall(mx, my) && !map->IsWall(mx + 1, my) && x + vx - r < mx*size + size) {
							bx = max(bx, mx*size + size - x + r - vx);
						}
					}
					if (vy > 0 && my != myB) {
						if (map->IsWall(mx, my) && !map->IsWall(mx, my - 1) && y + vy + r > my*size) {
							by = min(bx, my*size - y - r - vy);
						}
					}
					else if (vy < 0 && my != myE) {
						if (map->IsWall(mx, my) && !map->IsWall(mx, my + 1) && y + vy - r < my*size + size) {
							by = max(by, my*size + size - y + r - vy);
						}
					}
				}
				if (bx != 0 && by == 0) {
					vx += bx;
				}
				else if (by != 0 && bx == 0) {
					vy += by;
				}
				else {
					if (std::abs(bx) <= std::abs(by)) {
						vx += bx;
					}
					else {
						vy += by;
					}
				}
			}
		}
		{
			OM<Enemy>::TList& eList = e->GetList();
			Circle c1, c2;
			c1 = p->GetHitBody();
			for (auto it = eList.begin(), itEnd = eList.end(); it != itEnd; ++it) {
				c2 = it->get()->GetHitBody();
				if (JudgeHitE(c1, c2)) {

				}
			}
		}
	}

private:
	Player *p;
	OM<Enemy> *e;
	Map *map;
};