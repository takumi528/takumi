#include "MyScene.h"

const bool autoMove = false;

void CSGame::Start() {
	x = 375;
	y = 350;
	vy = 0;
	vx = 0;
	g = 1;//èdóÕ
	jumpf = 2;
	switch (stage) {
	case 1:
	default:
		mce = "MCE/stage1.mce";
		break;
	case 2:
		mce = "MCE/stage2.mce";
		break;
	case 3:
		mce = "MCE/stage3.mce";
		break;
	}

	switch (stage)
	{
	case 1:
	default:
		background = "stpic/background1.png";
		break;
	case 2:
		background = "stpic/background2.png";
		break;
	case 3:
		background = "stpic/background3.png";
		break;
	}
	
	chip = "MCE/chip.png";
	player = "stpic/player.png";
	killer = "stpic/killer.png";
	trap = "stpic/trap.png";
	


	for (int i=0; i < 20; i++) {
		K[i].x = 800;
		K[i].y = 800;
		K[i].flag = false;
	}

	for (int i = 0; i < 50; i++) {
		T[i].x = 800;
		T[i].y = 800;
		T[i].flag = false;
	}

	scrolX = 0;
}

void CSGame::Loop() {
	y += vy;
	vy += g;
	if (vy > 15) {
		vy = 15;
	}
	x += vx;
	k.x -= 5;
	for (int i=0; i < 20; i++) {
		K[i].x -= 5;
	}

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

	if (x+jWidth < scrolX && stage == 1) {
		Game.FlipScene(new CSOver(1),Flip::CROSS_FADE,12);
	}

	if (x + jWidth < scrolX && stage == 2) {
		Game.FlipScene(new CSOver(2), Flip::CROSS_FADE, 12);
	}

	if (x + jWidth < scrolX && stage == 3) {
		Game.FlipScene(new CSOver(3), Flip::CROSS_FADE, 12);
	}

	for (int i = 0; i < 20; i++) {
		if (stage == 1 && ((x > K[i].x && x < K[i].x + k.width) || (x + jWidth > K[i].x && x + jWidth < K[i].x + k.width)) && ((y > K[i].y && y < K[i].y + k.height) || (y + jHeight > K[i].y && y + jHeight < K[i].y + k.height))) {
			Game.FlipScene(new CSOver(1), Flip::CROSS_FADE, 12);
		}
	}


	for (int i = 0; i < 20; i++) {
		if (stage == 2 && ((x > K[i].x && x < K[i].x + k.width) || (x + jWidth > K[i].x && x + jWidth < K[i].x + k.width)) && ((y > K[i].y && y < K[i].y + k.height) || (y + jHeight > K[i].y && y + jHeight < K[i].y + k.height))) {
			Game.FlipScene(new CSOver(2), Flip::CROSS_FADE, 12);
		}
	}


	for (int i = 0; i < 20; i++) {
		if (stage == 3 && ((x > K[i].x && x < K[i].x + k.width) || (x + jWidth > K[i].x && x + jWidth < K[i].x + k.width)) && ((y > K[i].y && y < K[i].y + k.height) || (y + jHeight > K[i].y && y + jHeight < K[i].y + k.height))) {
			Game.FlipScene(new CSOver(3), Flip::CROSS_FADE, 12);
		}
	}

	for (int i = 0; i < 50; i++) {
		if (stage == 1 && ((x > T[i].x && x < T[i].x + t.width) || (x + jWidth > T[i].x && x + jWidth < T[i].x + t.width)) && ((y > T[i].y && y < T[i].y + t.height) || (y + jHeight > T[i].y && y + jHeight < T[i].y + t.height))) {
			Game.FlipScene(new CSOver(1), Flip::CROSS_FADE, 12);
		}
	}

	for (int i = 0; i < 50; i++) {
		if (stage == 2 && ((x > T[i].x && x < T[i].x + t.width) || (x + jWidth > T[i].x && x + jWidth < T[i].x + t.width)) && ((y > T[i].y && y < T[i].y + t.height) || (y + jHeight > T[i].y && y + jHeight < T[i].y + t.height))) {
			Game.FlipScene(new CSOver(2), Flip::CROSS_FADE, 12);
		}
	}

	for (int i = 0; i < 50; i++) {
		if (stage == 3 && ((x > T[i].x && x < T[i].x + t.width) || (x + jWidth > T[i].x && x + jWidth < T[i].x + t.width)) && ((y > T[i].y && y < T[i].y + t.height) || (y + jHeight > T[i].y && y + jHeight < T[i].y + t.height))) {
			Game.FlipScene(new CSOver(3), Flip::CROSS_FADE, 12);
		}
	}

	if (x + jWidth == 6400) {
		Game.FlipScene(new CSComplete(), Flip::CROSS_FADE, 8);
	}




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

	for (int i = 0; i < 20; i++) {
		if (K[i].x + K[i].width < scrolX) {
			K[i].flag = false;
		}
	}

	
	for (int ki = 0; ki < mce.GetWidth(); ki++) {
		for (int kj = 0; kj < mce.GetHeight(); kj++) {
			if (mce.Get(mce.layer.B, ki, kj) == 1 && ki * 40 - scrolX >= 800 && ki * 40 - scrolX <= 800 + 5) {
				for (int i = 0; i < 20; i++) {
					if (K[i].flag == false) {
						K[i].x = ki * 40;
						K[i].y = kj * 40;
						K[i].flag = true;
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i < 50; i++) {
		if (T[i].x + T[i].width < scrolX) {
			T[i].flag = false;
		}
	}

	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.C, i, j) == 1 && i * 40 - scrolX >= 800 && i * 40 - scrolX <= 800 + 5) {
				for (int I = 0; I < 50; I++) {
					if (T[I].flag == false) {
						T[I].x = i * 40;
						T[I].y = j * 40;
						T[I].flag = true;
						break;
					}
				}
			}
		}
	}

	

}

void CSGame::Draw() {

	background(0, 0);

	for (int i = 0; i < 50; i++) {
		if (T[i].flag == true) {
			trap(T[i].x - scrolX, T[i].y);
		}
	}

	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 1) {
				chip(i * 40 - scrolX, j * 40);
			}
		}
	}
	

	

	/*for (int ki = 0; ki < mce.GetWidth(); ki++) {
		for (int kj = 0; kj < mce.GetHeight(); kj++) {
			if (mce.Get(mce.layer.B, ki, kj) == 1 && ki * 40 - scrolX >= 800  && ki * 40 - scrolX <= 800 + 5) {
				k.x = ki * 40;
				k.y = kj * 40;
			}
		}
	}*/

		
		

	//killer(k.x - scrolX, k.y, true);

	for (int i = 0; i < 20; i++) {
		if (K[i].flag == true) {
			killer(K[i].x - scrolX, K[i].y, true);
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


/*	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 1 && mce.Get(mce.layer.A, i + 1, j) != 1 && mce.Get(mce.layer.A, i - 1, j) != 1) {
				if (i * 40 >= x && i * 40 <= x + jWidth && (i + 1) * 40 >= x && (i + 1) * 40 == x + jWidth && (y + jHeight >= j *40 && y + jHeight <= (j + 1)* 40) || (y >= j * 40 && y <= (j + 1)* 40)) {
					y = j * 40;
				}
			}
		}
	}*/

	/*if (x1 * 40 > x && (x1 + 1) * 40 < x + jWidth && y + jHeight > y1 * 40 && y+ jHeight < (y1 + 1) * 40) {
		y = y1 * 40;
	}*/

}