#include "MyScene.h"

const bool autoMove = true;

void CSGame::Start() {
	life = true;
	x = 375;
    y = 250;

	vy = 0;
	vx = 0;

	d = 0;//中心からの距離
	jumpf = 2;

	switch (stage) {
	case 0:
	default:
		mce = "MCE/stage0.mce";
		version = 0;
		break;
	case 1:
		mce = "MCE/stage1.mce";
		version = 1;
		break;
	case 2:
		mce = "MCE/stage2.mce";
		version = 1;
		break;
	case 3:
		mce = "MCE/stage3.mce";
		version = 1;
		break;
	case 4:
		mce = "MCE/stage4.mce";
		version = 2;
		break;
	case 5:
		mce = "MCE/stage5.mce";
		version = 2;
		break;
	case 6:
		mce = "MCE/stage6.mce";
		version = 2;
		break;
	case 7:
		mce = "MCE/stage7.mce";
		version = 3;
		break;
	case 8:
		mce = "MCE/stage8.mce";
		version = 3;
		break;
	case 9:
		mce = "MCE/stage9.mce";
		version = 3;
		break;
	case 10:
		mce = "MCE/stage10.mce";
		version = 4;
		break;
	case 11:
		mce = "MCE/stage11.mce";
		version = 4;
		break;
	case 12:
		mce = "MCE/stage12.mce";
		version = 4;
		break;
	}

	switch (version) {
	case 0:
	default:
		player.Set(LoadDivGraph("stpic/player.png", 2, 2, 1, 50, 30), 20);
		background = "stpic/background0.png";
		break;
	case 1:
		player.Set(LoadDivGraph("stpic/player.png", 2, 2, 1, 50, 30), 20);
		background = "stpic/background1.png";
		break;
	case 2:
		player.Set(LoadDivGraph("stpic/player.png", 2, 2, 1, 50, 30), 20);
		background = "stpic/background2.png";
		break;
	case 3:
		player.Set(LoadDivGraph("stpic/player.png", 2, 2, 1, 50, 30), 20);
		background = "stpic/background3.png";
		break;
	case 4:
		player.Set(LoadDivGraph("stpic/player4.png", 2, 2, 1, 58, 30), 10);
		background = "stpic/background4.png";
		break;
	}

	if (version != 3) {//重力
		g = 1;
	}
	else {
		g = 0;
	}

	
	chip1_1 = "stpic/chip1_1.png";
	chip1_2 = "stpic/chip1_2.png";
	chip2_1 = "stpic/chip2_1.png";
	chip2_2 = "stpic/chip2_2.png";
	chip3 = "stpic/chip3.png";
	chip4 = "stpic/chip4.png";
	killer = "stpic/killer.png";
	stone = "stpic/stone.png";
	urchin = "stpic/urchin.png";
	fat = "stpic/fat.png";
	gameover = "stpic/over.png";
	one_two = "stpic/1 2.png";
	bird.Set(LoadDivGraph("stpic/bird.png", 4, 4, 1, 50, 30),8);
	trap.Set(LoadDivGraph("stpic/trap.png", 2, 2, 1, 40, 40), 8);
	bat.Set(LoadDivGraph("stpic/bat.png", 4, 4, 1, 40, 80), 6);
	ufo.Set(LoadDivGraph("stpic/ufo.png", 4, 4, 1, 48, 30), 4);
	fish.Set(LoadDivGraph("stpic/fish.png", 4, 4, 1, 55, 20), 8);
	bubble.Set(LoadDivGraph("stpic/bubble.png", 2, 2, 1, 40, 80), 10);

	for (int i=0; i < 20; i++) {
		K[i].x = 800;
		K[i].y = 800;
		K[i].flag = false;
	}

	for (int i = 0; i < 20; i++) {
		F[i].x = 800;
		F[i].y = 800;
		F[i].flag = false;
	}

	for (int i = 0; i < 50; i++) {
		U2[i].x = 800;
		U2[i].y = 800;
		U2[i].flag = false;
	}

	for (int i = 0; i < 20; i++) {
		B[i].x = 800;
		B[i].y = 800;
		B[i].flag = false;
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
		F2[i].x = 800;
		F2[i].y = 800;
		F2[i].flag = false;
	}  
	for (int i = 0; i < 20; i++) {
		B2[i].x = 800;
		B2[i].y = 800;
		B2[i].flag = false;
		B2[i].turn = true;
	}


	scrolX = 0;
}

void CSGame::Loop() {
	d = 375 - (x - scrolX);
	x += vx;
	y += vy;
	vy += g;
	if (life ==true) {
		trap.PlusCount();
		bat.PlusCount();
		player.PlusCount();
		bird.PlusCount();
		ufo.PlusCount();
		fish.PlusCount();
		bubble.PlusCount();
	}
	else {}

	if (y < 0) {
		y += g;
	}
	if (y + jHeight < 0) {
		y = 0 - jHeight;
	}

	if (version == 4) {
		if (vy > 6) {
			vy = 6;
		}
	}
	else if (vy > 15) {
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
			F2[i].x -= 5;
		}
		else {}
	}
	for (int i = 0; i < 20; i++) {
		if (life == true) {
			B2[i].x -= 5;
		}
	}
		for (int i = 0; i < 20; i++) {
			if (life == true) {
				B[i].x -= 5;
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
					U[i].y += 5;
					if (U[i].y + U[i].height > 560) {
						U[i].turn = false;
					}
				}

				else {
					U[i].y -= 5;
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
		if (y > 600 - jHeight) {
			life = false;
		}
	
		for (int i = 0; i < 20; i++) {
			if (K[i].flag == true && (((x > K[i].x && x < K[i].x + k.width) || (x + jWidth > K[i].x && x + jWidth < K[i].x + k.width)) && ((y > K[i].y && y < K[i].y + k.height) || (y + jHeight > K[i].y && y + jHeight < K[i].y + k.height)))) {
				life = false;
			}
		}

		for (int i = 0; i < 20; i++) {
			if (F2[i].flag == true && (((x > F2[i].x && x < F2[i].x + f2.width) || (x + jWidth > F2[i].x && x + jWidth < F2[i].x + f2.width)) && ((y > F2[i].y && y < F2[i].y + f2.height) || (y + jHeight > F2[i].y && y + jHeight < F2[i].y + f2.height)))) {
				life = false;
			}
		}

		for (int i = 0; i < 20; i++) {
			if (B2[i].flag == true && (((x > B2[i].x && x < B2[i].x + b2.width) || (x + jWidth > B2[i].x && x + jWidth < B2[i].x + b2.width)) && ((y > B2[i].y + 40 && y < B2[i].y + b2.height + 40) || (y + jHeight > B2[i].y + 40 && y + jHeight < B2[i].y + b2.height + 40)))) {
				life = false;
			}
		}

		for (int i = 0; i < 20; i++) {
			if (B[i].flag == true && (((x > B[i].x && x < B[i].x + b.width) || (x + jWidth > B[i].x && x + jWidth < B[i].x + b.width)) && ((y > B[i].y && y < B[i].y + b.height) || (y + jHeight > B[i].y && y + jHeight < B[i].y + b.height)))) {
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
			if (U2[i].flag == true && (((x > U2[i].x && x < U2[i].x + u2.width) || (x + jWidth > U2[i].x && x + jWidth < U2[i].x + u2.width)) && ((y > U2[i].y && y < U2[i].y + u2.height) || (y + jHeight > U2[i].y && y + jHeight < U2[i].y + u2.height)))) {
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
					vy = -7;
				}
				if (Input.GetKeyDown(Input.key.DOWN)) {
					vy = 7;
				}
			}
			else if (version == 4){
				if (Input.GetKeyEnter(Input.key.UP) && jumpf > 0) {
					--jumpf;
					vy = -20;
					
				}
			}
			else {
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
				if (mce.Get(mce.layer.A, i, j) != 0) {
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
			if (F2[i].x + F2[i].width < scrolX) {
				F2[i].flag = false;
			}
		}
		for (int i = 0; i < 20; i++) {
			if (B2[i].x + B2[i].width < scrolX) {
				B2[i].flag = false;
			}
		}

		for (int i = 0; i < 20; i++) {
			if (B[i].x + B[i].width < scrolX) {
				B[i].flag = false;
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
			if (U2[i].x + U2[i].width < scrolX) {
				U2[i].flag = false;
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



		
			for (int i = 0; i < mce.GetWidth(); i++) {
				for (int j = 0; j < mce.GetHeight(); j++) {
					if (mce.Get(mce.layer.B, i, j) == 1 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 5 - d) {
						for (int I = 0; I < 20; I++) {
							if (B[I].flag == false) {
								B[I].x = i * 40;
								B[I].y = j * 40;
								B[I].flag = true;
								break;
						}
					}
				}
			}
		}
		
			for (int i = 0; i < mce.GetWidth(); i++) {
				for (int j = 0; j < mce.GetHeight(); j++) {
					if (mce.Get(mce.layer.B, i, j) == 2 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 5 - d) {
						for (int I = 0; I < 20; I++) {
							if (B2[I].flag == false) {
								B2[I].x = i * 40;
								B2[I].y = j * 40;
								B2[I].flag = true;
								break;
							}
						}
					}
				}
			}

			for (int i = 0; i < mce.GetWidth(); i++) {
				for (int j = 0; j < mce.GetHeight(); j++) {
					if (mce.Get(mce.layer.B, i, j) == 4 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 5 - d) {
						for (int I = 0; I < 20; I++) {
							if (F2[I].flag == false) {
								F2[I].x = i * 40;
								F2[I].y = j * 40;
								F2[I].flag = true;
								break;
							}
						}
					}
				}
			}
	
	
			for (int i = 0; i < mce.GetWidth(); i++) {
				for (int j = 0; j < mce.GetHeight(); j++) {
					if (mce.Get(mce.layer.B, i, j) == 3 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 5 - d) {
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
			for (int i = 0; i < mce.GetWidth(); i++) {
				for (int j = 0; j < mce.GetHeight(); j++) {
					if (mce.Get(mce.layer.C, i, j) == 2 && i * 40 - scrolX >= 800 && i * 40 - scrolX <= 800) {
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
			for (int i = 0; i < mce.GetWidth(); i++) {
				for (int j = 0; j < mce.GetHeight(); j++) {
					if (mce.Get(mce.layer.C, i, j) == 3 && i * 40 - scrolX >= 800 && i * 40 - scrolX <= 800) {
						for (int I = 0; I < 50; I++) {
							if (U2[I].flag == false) {
								U2[I].x = i * 40;
								U2[I].y = j * 40;
								U2[I].flag = true;
								break;
							}
						}
					}
				}
			}
		}



void CSGame::Draw() {
	background(0, 0);

	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 7) {
				one_two(i * 40 - scrolX, j * 40);
			}
		}
	}

	if (y < 600 - jHeight) {
		player(x - scrolX, y,false,false);
	}
	if (version == 4) {
		bubble(x - scrolX - 40, y - 40, false, false);
	}

	for (int i = 0; i < 50; i++) {
		if (T[i].flag == true) {
			trap(T[i].x - scrolX, T[i].y,false,false);
		}
	}
	for (int i = 0; i < 50; i++) {
		if (U2[i].flag == true) {
			urchin(U2[i].x - scrolX, U2[i].y);
		}
	}
	for (int i = 0; i < 20; i++) {
		if (K[i].flag == true) {
			killer(K[i].x - scrolX, K[i].y, true);
		}
	}
	for (int i = 0; i < 20; i++) {
		if (F2[i].flag == true) {
			fish(F2[i].x - scrolX, F2[i].y, false, false);
		}
	}
	for (int i = 0; i < 20; i++) {
		if (B[i].flag == true) {
			bird(B[i].x - scrolX, B[i].y, false, false);
		}
	}
	for (int i = 0; i < 20; i++) {
		if (F[i].flag == true) {
			fat(F[i].x - scrolX, F[i].y);
		}
	}
	for (int i = 0; i < 20; i++) {
		if (B2[i].flag == true) {
			bat(B2[i].x - scrolX, B2[i].y, false, false);
		}
	}
	for (int i = 0; i < 50; i++) {
		if (S[i].flag == true) {
			stone(S[i].x - scrolX, S[i].y);
		}
	}
	for (int i = 0; i < 50; i++) {
		if (U[i].flag == true) {
			ufo(U[i].x - scrolX, U[i].y, false, false);
		}
	}


	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 1) {
				chip1_1(i * 40 - scrolX, j * 40);
			}
		}
	}
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 2) {
				chip1_2(i * 40 - scrolX, j * 40);
			}
		}
	}
		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.A, i, j) == 3) {
					chip2_1(i * 40 - scrolX, j * 40);
				}
			}
		}
		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.A, i, j) == 4) {
					chip2_2(i * 40 - scrolX, j * 40);
				}
			}
		}
		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.A, i, j) == 5) {
					chip3(i * 40 - scrolX, j * 40);
				}
			}
		}
		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.A, i, j) == 6) {
					chip4(i * 40 - scrolX, j * 40);
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