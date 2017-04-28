#include "MyScene.h"

const bool autoMove = false;

void CSGame::Start() {
	kx = 1500;
	ky = 300;
	kx2 = 0;
	ky2 = 0;
	x = 375;
	y = 350;
	vy = 0;
	vx = 0;
	g = 1;//èdóÕ
	jumpf = 2;
	mce = "MCE/map.mce";
	chip = "MCE/chip.png";
	player = "stpic/player.png";
	killer = "stpic/killer.png";
	killer2 = "stpic/killer.png";

	scrolX = 0;
}

void CSGame::Loop() {
	y += vy;
	vy += g;
	if (vy > 15) {
		vy = 15;
	}
	x += vx;
	kx -= 5;
	kx2 -= 5;
	vx = 0;
	if (y > 600 - jHeight) {
		vy = 0;
		y = 600 - jHeight;
		jumpf = 2;
	}
	if (Input.GetKeyEnter(Input.key.UP) && jumpf > 0) {
		--jumpf;
		vy = -15;
	}

	if (autoMove) {
		vx = 5;
		scrolX += 5;
	}
	else {
		if (Input.GetKeyDown(Input.key.RIGHT)) {
			vx += 5;
			scrolX += 5;
		}
		if (Input.GetKeyDown(Input.key.LEFT)) {
			vx -= 5;
			scrolX -= 5;
		}
		
	}

	if (x+jWidth < scrolX) {
		Game.FlipScene(new CSOver(),Flip::CROSS_FADE,4);
	}
	if (((x > kx && x < kx + 50) || (x + jWidth > kx && x + jWidth < kx + 50)) && ((y > ky && y < ky + 30) || (y + jHeight > ky && y + jHeight < ky + 30))) {
		Game.FlipScene(new CSOver(), Flip::CROSS_FADE, 4);
	}
	if (((x > kx2 && x < kx2 + 50) || (x + jWidth > kx2 && x + jWidth < kx2 + 50)) && ((y > ky2 && y < ky2 + 30) || (y + jHeight > ky2 && y + jHeight < ky2 + 30))) {
		Game.FlipScene(new CSOver(), Flip::CROSS_FADE, 4);
	}
	

	if (x == 1000) {
		kx = 1550;
		ky = 90;
	}
	if (x == 1600) {
		kx = 2400;
		ky = 400;
	}
	if (x == 2400) {
		kx = 3200;
		ky = 90;
	}
	if (x == 3700) {
		kx = 4600;
		ky = 450;
	}
	if (x == 4800) {
		kx = 5600;
		ky = 450;
	}
	if (x == 1000) {
		kx2 = 1550;
		ky2 = 500;
	}
	if (x == 2100) {
		kx2 = 2900;
		ky2 = 400;
	}
	if (x == 3900) {
		kx2 = 4800;
		ky2 = 450;
	}
	if (x == 4800) {
		kx2 = 5600;
		ky2 = 290;
	}
	


   /*if (kx > 800) {
		kx = -50;
	}*/



	/*for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {

			if (mce.Get(mce.layer.A, i, j) == 1) {
				HitBlock(i * 40, j * 40);
			}
			
		}
	}*/

	
	for (int i = x/40, endI = (x + 50) / 40, endJ = (y + 30) / 40; i <= endI; ++i) {
		for (int j = y/40; j <= endJ; ++j) {
			if (mce.Get(mce.layer.A, i, j) == 1) {
				HitBlock(i, j);
			}
		}
	}
	
}

void CSGame::Draw() {
	killer(kx - scrolX, ky,true);
	killer2(kx2 - scrolX, ky2, true);

	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 1) {
				chip(i * 40 - scrolX, j * 40);
			}
		}
	}
	player(x - scrolX, y);
}

void CSGame::End() {

}

void CSGame::HitBlock(int x1, int y1) {
	bool ur = false, ul = false, dr = false, dl = false;
	bool right, left, top, bottom;

	if (x1 < mce.GetWidth() - 1 && mce.Get(mce.layer.A, x1 + 1, y1) != 0) {
		right = false;
	}
	else {
		right = true;
	}
	if (x1 > 0 && mce.Get(mce.layer.A, x1 - 1, y1) != 0) {
		left = false;
	}
	else {
		left = true;
	}
	if (y1< mce.GetHeight() - 1 && mce.Get(mce.layer.A, x1, y1 + 1) != 0) {
		bottom = false;
	}
	else {
		bottom = true;
	}
	if (y1 > 0 && mce.Get(mce.layer.A, x1, y1 - 1) != 0) {
		top = false;
	}
	else {
		top = true;
	}

	x1 *= 40;
	y1 *= 40;

	if (x<x1 + 40 && x>x1 && y > y1 && y < y1 + 40) {
		ul = true;
	}
	if (x + jWidth<x1 + 40 && x + jWidth>x1 && y > y1 && y < y1 + 40) {
		ur = true;
	}
	if (x<x1 + 40 && x>x1 && y + jHeight > y1 && y + jHeight < y1 + 40) {
		dl = true;
	}
	if (x + jWidth<x1 + 40 && x + jWidth>x1 && y + jHeight > y1 && y + jHeight < y1 + 40) {
		dr = true;
	}
	
	if (bottom && (ur || ul) && !dl && !dr && vy<0) {
		vy = 0;
		y = y1+40;
	}
	if (top && (dr || dl) && !ul && !ur && vy>=0) {
		vy = 0;
		y = y1 - jHeight;
		jumpf = 2;
	}
	if (left && (ur || dr) && !dl && !ul && vx>0 && vy != 0) {
		//ç∂Ç©ÇÁìñÇΩÇ¡ÇΩéû
		vx = 0;
		x = x1 - jWidth;
	}
	if (right && (ul || dl) && !dr && !ur && vx<0 && vy != 0) {
		//âEÇ©ÇÁìñÇΩÇ¡ÇΩéû
		vx = 0;
		x = x1+40;
	}
	
}