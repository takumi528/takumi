#pragma once

#include "Task.h"

#include "scrol.h"
#include "Player.h"
#include "Map.h"

class ScrolTask :public Task {
public:
	ScrolTask(Scrol *scrol, Player const *player, Map const *map):scrol(scrol), player(player), map(map) {
		lastX = 0;
		lastY = 0;
		int wx = System.GetWindowX();
		int wy = System.GetWindowY();
		int mx = map->GetStageWidth();
		int my = map->GetStageHeight();
		scrol->scrX = wx / 2 - player->GetX();// px + sx = wx/2
		scrol->scrY = wy / 2 - player->GetY();// px + sx = wx/2
		if (scrol->scrX >= 0)
			scrol->scrX = 0;
		if (scrol->scrX + mx <= wx)
			scrol->scrX = wx - mx;
		if (scrol->scrY >= 0)
			scrol->scrY = 0;
		if (scrol->scrY + my <= wy)
			scrol->scrY = wy - my;
		scrol->fixX = scrol->scrX;
		scrol->fixX = scrol->scrY;
	}

	~ScrolTask() = default;

	void Main() {
		int sx = scrol->scrX;//変数に移しておくと、コードが読みやすくなる
		int sy = scrol->scrY;
		int px = player->GetX();
		int py = player->GetY();
		int mx = map->GetStageWidth();
		int my = map->GetStageHeight();
		int wx = System.GetWindowX();
		int wy = System.GetWindowY();
		int fx = scrol->fixX;
		int fy = scrol->fixY;
		int sp = Scrol::scrolSpeed;

		if (scrol->cnt == 0) {
			lastX = scrol->scrX;
			lastY = scrol->scrY;
		}

		if (!scrol->isFixed) {
			if (px + sx < Scrol::scrolRangeX) {
				scrol->fixX = Scrol::scrolRangeX - px;
			}
			if (px + sx > wx - Scrol::scrolRangeX) {
				scrol->fixX = wx - Scrol::scrolRangeX - px;
			}
			if (py + sy < Scrol::scrolRangeY) {
				scrol->fixY = Scrol::scrolRangeY - py;
			}
			if (py + sy > wy - Scrol::scrolRangeY) {
				scrol->fixY = wy - Scrol::scrolRangeY - py;
			}
			fx = scrol->fixX;
			fy = scrol->fixY;
		}

		if (scrol->cnt <= Scrol::fixTime) {
			float buf = easing::InCubic(scrol->cnt, Scrol::fixTime);
			scrol->scrX = lastX + (fx - lastX) * buf;
			scrol->scrY = lastY + (fy - lastY) * buf;
			++scrol->cnt;
		}
		else {
			scrol->scrX = fx;
			scrol->scrY = fy;
		}

		if (scrol->scrX >= 0)
			scrol->scrX = 0;
		if (scrol->scrX + mx <= wx)
			scrol->scrX = wx - mx;
		if (scrol->scrY >= 0)
			scrol->scrY = 0;
		if (scrol->scrY + my <= wy)
			scrol->scrY = wy - my;
	}
private:
	int lastX, lastY;
	Scrol *scrol;
	Player const *player;
	Map const *map;
};