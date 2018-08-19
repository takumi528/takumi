#pragma once

struct Coord {
	Coord() = default;
	Coord(int x, int y, int vx, int vy) :x(x), y(y), vx(vx), vy(vy) {};
	int x,  y,  vx,  vy;
};