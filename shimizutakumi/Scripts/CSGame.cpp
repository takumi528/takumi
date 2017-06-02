#include "MyScene.h"

const bool autoMove = true;

void CSGame::Start() {
	life = true;
	x = 375;
    y = 285;

	vy = 0;
	vx = 0;

	d = 0;//中心からの距離
	jumpf = 2;

	switch (stage) {
	case 0:
	default:
		mce = "MCE/stage0.mce";
		background = "stpic/background1.png";
		version = 1;
		break;
	case 1:
		mce = "MCE/stage1.mce";
		background = "stpic/background1.png";
		version = 1;
		break;
	case 2:
		mce = "MCE/stage2.mce";
		background = "stpic/background1.png";
		version = 1;
		break;
	case 3:
		mce = "MCE/stage3.mce";
		background = "stpic/background1.png";
		version = 1;
		break;
	case 4:
		mce = "MCE/stage4.mce";
		background = "stpic/background2.png";
		version = 2;
		break;
	case 5:
		mce = "MCE/stage5.mce";
		background = "stpic/background2.png";
		version = 2;
		break;
	case 6:
		mce = "MCE/stage6.mce";
		background = "stpic/background2.png";
		version = 2;
		break;
	case 7:
		mce = "MCE/stage7.mce";
		background = "stpic/background3.png";
		version = 3;
		break;
	case 8:
		mce = "MCE/stage8.mce";
		background = "stpic/background3.png";
		version = 3;
		break;
	case 9:
		mce = "MCE/stage9.mce";
		background = "stpic/background3.png";
		version = 3;
		break;
	}

	if (version != 3) {//重力
		g = 1;
	}
	else {
		g = 0;
	}

	
	chip = "MCE/chip.png";
	chip2 = "MCE/chip2.png";
	player = "stpic/player.png";
	killer = "stpic/killer.png";
	trap = "stpic/trap.png";
	stone = "stpic/stone.png";
	ufo = "stpic/ufo.png";
	fat = "stpic/fat.png";
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
	for (int i = 0; i < 50; i++) {
		U[i].x = 800;
		U[i].y = 800;
		U[i].flag = false;
		U[i].turn = true;
	}
	for (int i = 0; i < 20; i++) {
		F[i].x = 800;
		F[i].y = 800;
		F[i].flag = false;
	}


	scrolX = 0;
}

void CSGame::Loop() {
	d = 375 - (x - scrolX);
	x += vx;
	y += vy;
	vy += g;
	if (vy > 15) {
		vy = 15;
	}
	for (int i = 0; i < 20; i++) {
		if (life == true) {
			K[i].x -= 5;
		}
		else {}
	}
	for (int i = 0; i < 20; i++) {
		if (life == true) {
			F[i].x -= 5;
		}
		else {}
	}

	for (int i = 0; i < 50; i++) {
		if (life == true) {
			if (U[i].turn == true) {
				U[i].y += 7;
				if (U[i].y + U[i].height > 560) {
					U[i].turn = false;
				}
			}
			else {
				U[i].y -= 7;
				if (U[i].y < 40) {
					U[i].turn = true;
				}
			}
		}
	}

	vx = 0;

	//ゲームオーバー
	if (x + jWidth < scrolX) {
		life = false;
	}


	for (int i = 0; i < 20; i++) {
		if (K[i].flag == true && (((x > K[i].x && x < K[i].x + k.width) || (x + jWidth > K[i].x && x + jWidth < K[i].x + k.width)) && ((y > K[i].y && y < K[i].y + k.height) || (y + jHeight > K[i].y && y + jHeight < K[i].y + k.height)))) {
			life = false;
		}
	}


	for (int i = 0; i < 20; i++) {
		if (F[i].flag == true && (((x > F[i].x && x < F[i].x + f.width) || (x + jWidth > F[i].x && x + jWidth < F[i].x + f.width)) && ((y > F[i].y && y < F[i].y + f.height) || (y + jHeight > F[i].y && y + jHeight < F[i].y + f.height)))) {
			life = false;
		}
	}

	for (int i = 0; i < 50; i++) {
		if (T[i].flag == true && (((x > T[i].x && x < T[i].x + t.width) || (x + jWidth > T[i].x && x + jWidth < T[i].x + t.width)) && ((y > T[i].y && y < T[i].y + t.height) || (y + jHeight > T[i].y && y + jHeight < T[i].y + t.height)))) {
			life = false;

		}
	}

		for (int i = 0; i < 50; i++) {
			if (S[i].flag == true && (((x > S[i].x && x < S[i].x + s.width) || (x + jWidth > S[i].x && x + jWidth < S[i].x + s.width)) && ((y > S[i].y && y < S[i].y + s.height) || (y + jHeight > S[i].y && y + jHeight < S[i].y + s.height)))) {
				life = false;
			}
		}

		for (int i = 0; i < 50; i++) {
			if (U[i].flag == true && (((x > U[i].x && x < U[i].x + u.width) || (x + jWidth > U[i].x && x + jWidth < U[i].x + u.width)) && ((y > U[i].y && y < U[i].y + u.height) || (y + jHeight > U[i].y && y + jHeight < U[i].y + u.height)))) {
				life = false;
			}
		}

		if (life == true) {
			if (version == 3) {
				if (vy > 0) {
					vy -= 1;
					if (vy < 0) {
						vy = 0;
					}
				}
				if (vy < 0) {
					vy += 1;
					if (vy > 0) {
						vy += 0;
					}
				}
				if (Input.GetKeyDown(Input.key.UP)) {
					vy = -8;
				}
				if (Input.GetKeyDown(Input.key.DOWN)) {
					vy = 8;
				}
			}
			else {
			
				if (y > 600 - jHeight) {
					vy = 0;
					y = 600 - jHeight;
					jumpf = 2;
				}
				if (Input.GetKeyEnter(Input.key.UP) && jumpf > 0) {
					--jumpf;
					vy = -15;
				}
			}
		}
		else
		{
			if (Input.GetKeyEnter(Input.key.SPACE)) {
				Game.FlipScene(new CSTitle(), Flip::CROSS_FADE, 10);
			}
			if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
				life = true;
				Game.FlipScene(new CSGame(stage), Flip::CROSS_FADE, 30);
			}
		}

		if (autoMove) {
			if (life == true) {
				vx = 5;
				scrolX += 5;
			}
			else {
				vx = 0;
				vy = 0;
			}
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
			Game.FlipScene(new CSComplete(stage), Flip::CROSS_FADE, 8);
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

		for (int i = 0; i < 20; i++) {
			if (F[i].x + F[i].width < scrolX) {
				F[i].flag = false;
			}
		}

		for (int i = 0; i < 50; i++) {
			if (U[i].x + U[i].width < scrolX) {
				U[i].flag = false;
			}
		}

		for (int i = 0; i < 50; i++) {
			if (T[i].x + T[i].width < scrolX) {
				T[i].flag = false;
			}
		}

		for (int i = 0; i < 50; i++) {
			if (S[i].x + S[i].width < scrolX) {
				S[i].flag = false;
			}
		}



		if (version == 1) {
			for (int i = 0; i < mce.GetWidth(); i++) {
				for (int j = 0; j < mce.GetHeight(); j++) {
					if (mce.Get(mce.layer.B, i, j) == 1 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 5 - d) {
						for (int I = 0; I < 20; I++) {
							if (K[I].flag == false) {
								K[I].x = i * 40;
								K[I].y = j * 40;
								K[I].flag = true;
								break;
							}
						}
					}
				}
			}
		}
		if (version == 2) {
			for (int i = 0; i < mce.GetWidth(); i++) {
				for (int j = 0; j < mce.GetHeight(); j++) {
					if (mce.Get(mce.layer.B, i, j) == 1 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 5 - d) {
						for (int I = 0; I < 20; I++) {
							if (F[I].flag == false) {
								F[I].x = i * 40;
								F[I].y = j * 40;
								F[I].flag = true;
								break;
							}
						}
					}
				}
			}
		}
		if (version == 3) {
			for (int i = 0; i < mce.GetWidth(); i++) {
				for (int j = 0; j < mce.GetHeight(); j++) {
					if (mce.Get(mce.layer.B, i, j) == 1 && i * 40 -scrolX>= 1200 - d && i * 40 - scrolX<= 1200 + 5 - d) {
						for (int I = 0; I < 50; I++) {
							if (U[I].flag == false) {
								U[I].x = i * 40;
								U[I].y = j * 40;
								U[I].flag = true;
								break;
							}
						}
					}
				}
			}
		}
		

		if (version == 1 || 2 && version != 3) {
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
		}
		if (version == 3) {
			for (int i = 0; i < mce.GetWidth(); i++) {
				for (int j = 0; j < mce.GetHeight(); j++) {
					if (mce.Get(mce.layer.C, i, j) == 1 && i * 40 - scrolX >= 800 && i * 40 - scrolX <= 800) {
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
		}
	}


void CSGame::Draw() {
	background(0, 0);


	player(x - scrolX, y);
	for (int i = 0; i < 50; i++) {
		if (T[i].flag == true) {
			trap(T[i].x - scrolX, T[i].y);
		}
	}
	for (int i = 0; i < 20; i++) {
		if (K[i].flag == true) {
			killer(K[i].x - scrolX, K[i].y, true);
		}
	}
	for (int i = 0; i < 20; i++) {
		if (F[i].flag == true) {
			fat(F[i].x - scrolX, F[i].y);
		}
	}
	for (int i = 0; i < 50; i++) {
		if (S[i].flag == true) {
			stone(S[i].x - scrolX, S[i].y);
		}
	}
	for (int i = 0; i < 50; i++) {
		if (U[i].flag == true) {
			ufo(U[i].x - scrolX, U[i].y);
		}
	}



	if (version ==0 || 1 || 2 && version != 3) {
		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.A, i, j) == 1) {
					chip(i * 40 - scrolX, j * 40);
				}
			}
		}
	}
	else {
		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.A, i, j) == 1) {
					chip2(i * 40 - scrolX, j * 40);
				}
			}
		}
	}

		
	
		if (life == false) {
			DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
			gameover();

		}
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