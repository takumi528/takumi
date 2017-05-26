#include "MyScene.h"

const bool autoMove = true;

void CSGame::Start() {
	life = true;
	x = 375;
    y = 285;

	vy = 0;
	vx = 0;
	g = 1;//重力
	d = 0;//中心からの距離
	jumpf = 2;

	switch (stage) {
	case 1:
	default:
		mce = "MCE/stage1.mce";
		background = "stpic/background1.png";
		space = false;
		break;
	case 2:
		mce = "MCE/stage2.mce";
		background = "stpic/background2.png";
		break;
		space = false;
		break;
	case 3:
		mce = "MCE/stage3.mce";
		background = "stpic/background3.png";
		break;
		space = true;
		break;
	}

	
	chip = "MCE/chip.png";
	chip2 = "MCE/chip2.png";
	player = "stpic/player.png";
	killer = "stpic/killer.png";
	trap = "stpic/trap.png";
	stone = "stpic/stone.png";
	gameover = "stpic/over.png";
	


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

	for (int i = 0; i < 50; i++) {
		S[i].x = 800;
		S[i].y = 800;
		S[i].flag = false;
	}

	scrolX = 0;
}

void CSGame::Loop() {
	d = 375 - (x - scrolX);

	y += vy;

	if (space = false) {
		vy += g;
	}


	if (vy > 15) {
		vy = 15;
	}

	x += vx;

	for (int i = 0; i < 20; i++) {
		K[i].x -= 5;
	}

	vx = 0;
	if (y > 600 - jHeight && space == false) {
		vy = 0;
		y = 600 - jHeight;
		jumpf = 2;
	}


	if (Input.GetKeyEnter(Input.key.UP) && jumpf > 0 && space == false) {
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


	if (x + jWidth == 6400) {
		Game.FlipScene(new CSComplete(), Flip::CROSS_FADE, 8);
	}

	for (int i = x / 40, endI = (x + 50) / 40, endJ = (y + 30) / 40; i <= endI; ++i) {
		for (int j = y / 40; j <= endJ; ++j) {
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
			if (mce.Get(mce.layer.B, ki, kj) == 1 && ki * 40 - scrolX >= 1200 - d && ki * 40 - scrolX <= 1200 + 5 - d && space == false) {
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
			if (mce.Get(mce.layer.C, i, j) == 1 && i * 40 - scrolX >= 800 && i * 40 - scrolX <= 800) {
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

	for (int i = 0; i < 50; i++) {
		if (S[i].x + S[i].width < scrolX) {
			S[i].flag = false;
		}
	}

	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.B, i, j) == 1 && i * 40 - scrolX >= 800 && i * 40 - scrolX <= 800 && space == true) {
				for (int I = 0; I < 50; I++) {
					if (S[I].flag == false) {
						S[I].x = i * 40;
						S[I].y = j * 40;
						S[I].flag = true;
						break;
					}
				}
			}
		}
	}

	//ステージ３
	if (space == true) {
		g = 0;
	}

	if (space == true) {
		if (Input.GetKeyDown(Input.key.UP)) {
			vy = -8;
		}

		if (Input.GetKeyDown(Input.key.DOWN)) {
			vy = 8;
		}

	}

	if (x + jWidth < scrolX) {
		life = false;
	}


	for (int i = 0; i < 20; i++) {
		if ((x > K[i].x && x < K[i].x + k.width) || (x + jWidth > K[i].x && x + jWidth < K[i].x + k.width) && (y > K[i].y && y < K[i].y + k.height) || (y + jHeight > K[i].y && y + jHeight < K[i].y + k.height)) {
			life = false;
		}
	}

	for (int i = 0; i < 50; i++) {
		if ((x > T[i].x && x < T[i].x + t.width) || (x + jWidth > T[i].x && x + jWidth < T[i].x + t.width) && (y > T[i].y && y < T[i].y + t.height) || (y + jHeight > T[i].y && y + jHeight < T[i].y + t.height)) {
			life = false;
		}
	}

	for (int i = 0; i < 50; i++) {
		if ((x > S[i].x && x < S[i].x + s.width) || (x + jWidth > S[i].x && x + jWidth < S[i].x + s.width) && (y > S[i].y && y < S[i].y + s.height) || (y + jHeight > S[i].y && y + jHeight < S[i].y + s.height)) {
			life = false;
		}
	}


//ゲームオーバー
	if (life = false && Input.GetKeyEnter(Input.key.SPACE)) {
		Game.FlipScene(new CSTitle(), Flip::CROSS_FADE, 8);
	}

	if (life = false && Input.GetKeyEnter(Input.key.NUMPADENTER)) {
		life = true;
		x = 375;
		y = 285;
	}
	
}

void CSGame::Draw() {
	if (life = true) {
	background(0, 0);
	}
	else {
		gameover(0, 0);
	}

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
	
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 1 && stage == 3) {
				chip2(i * 40 - scrolX, j * 40);
			}
		}
	}

	for (int i = 0; i < 20; i++) {
		if (K[i].flag == true) {
			killer(K[i].x - scrolX, K[i].y, true);
		}
	}

	for (int i = 0; i < 50; i++) {
		if (S[i].flag == true) {
			stone(S[i].x - scrolX, S[i].y);
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
	if (y1 < mce.GetHeight() - 1 && mce.Get(mce.layer.A, x1, y1 + 1) != 0) {
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

	if (x < x1 && x + jWidth >x1 + 40) {
		dr = true;
		dl = true;
	}
	

	if (bottom && (ur || ul) && !dl && !dr && vy < 0) {
		vy = 0;
		y = y1 + 40;
	}
	if (top && (dr || dl) && !ul && !ur && vy >= 0) {
		vy = 0;
		y = y1 - jHeight;
		jumpf = 2;
	}
	if (left && (ur || dr) && !dl && !ul && vx > 0 && vy != 0) {
		//左から当たった時
		vx = 0;
		x = x1 - jWidth;
	}
	if (right && (ul || dl) && !dr && !ur && vx < 0 && vy != 0) {
		//右から当たった時
		vx = 0;
		x = x1 + 40;
	}



}