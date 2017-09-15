#include "MyScene.h"

const bool autoMove = false;

void CSGame::Start() {
	switch (stage) {//ステージ数
	case 0:
	default:
		mce = "MCE/stage0.mce";
		ver = 0;
		break;
	case 1:
		mce = "MCE/stage1.mce";
		ver = 1;
		break;
	case 2:
		mce = "MCE/stage2.mce";
		ver = 1;
		break;
	case 3:
		mce = "MCE/stage3.mce";
		ver = 1;
		break;
	case 4:
		mce = "MCE/stage4.mce";
		ver = 2;
		break;
	case 5:
		mce = "MCE/stage5.mce";
		ver = 2;
		break;
	case 6:
		mce = "MCE/stage6.mce";
		ver = 2;
		break;
	case 7:
		mce = "MCE/stage7.mce";
		ver = 3;
		break;
	case 8:
		mce = "MCE/stage8.mce";
		ver = 3;
		break;
	case 9:
		mce = "MCE/stage9.mce";
		ver = 3;
		break;
	case 10:
		mce = "MCE/stage10.mce";
		ver = 4;
		break;
	case 11:
		mce = "MCE/stage11.mce";
		ver = 4;
		break;
	case 12:
		mce = "MCE/stage12.mce";
		ver = 4;
		break;
	case 13:
		mce = "MCE/stage13.mce";
		ver = 5;
		break;
	case 14:
		mce = "MCE/stage14.mce";
		ver = 5;
		break;
	case 15:
		mce = "MCE/stage15.mce";
		ver = 5;
		break;
	case 16:
		mce = "MCE/stage16.mce";
		ver = 6;
		break;
	case 17:
		mce = "MCE/stage17.mce";
		ver = 6;
		break;
	case 18:
		mce = "MCE/stage18.mce";
		ver = 6;
		break;
	case 19:
		mce = "MCE/stage19.mce";
		ver = 7;
		break;
	case 20:
		mce = "MCE/stage20.mce";
		ver = 7;
		break;
	case 21:
		mce = "MCE/stage21.mce";
		ver = 7;
		break;
	case 22:
		mce = "MCE/stage22.mce";
		ver = 8;
		break;
	case 23:
		mce = "MCE/stage23.mce";
		ver = 8;
		break;
	case 24:
		mce = "MCE/stage24.mce";
		ver = 8;
		break;
	case 100:
		mce = "MCE/a.mce";
		ver = 100;
		break;
	}

	//上下移動
	/*if (ver == 6) {
		Yflag = true;
	}*/
	//else {
		Yflag = false;
	//}
	life = true;
	x = 375;
	if (Yflag == false) {
		y = 250;
	}
	else {
		y = 3300;
	}

	vy = 0;
	vx = 0;
	wcount = 0;
	d = 0;//中心からの距離
	jumpf = 2;

	

	switch (ver) {//ステージ数
	case 0:
	default:
		player.Set(LoadDivGraph("stpic/player.png", 2, 2, 1, 50, 30), 20);
		background1 = "stpic/background0.png";
		break;
	case 1:
		player.Set(LoadDivGraph("stpic/player.png", 2, 2, 1, 50, 30), 20);
		background1 = "stpic/background1_1.png";
		background2 = "stpic/background1_2.png";
		background3 = "stpic/background1_3.png";
		background4 = "stpic/background1_4.png";
		break;
	case 2:
		player.Set(LoadDivGraph("stpic/player.png", 2, 2, 1, 50, 30), 20);
		background1 = "stpic/background2_1.png";
		background2 = "stpic/background2_2.png";
		background3 = "stpic/background2_3.png";
		background4 = "stpic/background2_4.png";
		background5 = "stpic/background2_5.png";
		break;
	case 3:
		player.Set(LoadDivGraph("stpic/player2.png", 5, 5, 1, 58, 30), 5);
		background1 = "stpic/background3_1.png";
		background2 = "stpic/background3_2.png";
		background3 = "stpic/background3_3.png";
		break;
	case 4:
		player.Set(LoadDivGraph("stpic/player2.png", 5, 5, 1, 58, 30), 5);
		background1 = "stpic/background4.png";
		background2 = "stpic/background4_2.png";
		background3 = "stpic/background4_3.png";
		background4 = "stpic/background4_4.png";
		break;
	case 5:
		player.Set(LoadDivGraph("stpic/player.png", 2, 2, 1, 50, 30), 10);
		background1 = "stpic/background5_1.png";
		background2 = "stpic/background5_2.png";
		background3 = "stpic/background5_3.png";
		break;
	case 6:
		player.Set(LoadDivGraph("stpic/player.png", 2, 2, 1, 50, 30), 10);
		background1 = "stpic/background6_1.png";
		background2 = "stpic/background6_2.png";
		background3 = "stpic/background6_3.png";

		break;
	case 7:
		player.Set(LoadDivGraph("stpic/player.png", 2, 2, 1, 50, 30), 10);
		background1 = "stpic/background7_1.png";
		background2 = "stpic/background7_2.png";
		background3 = "stpic/background7_3.png";
		background4 = "stpic/background7_4.png";
		break;
	case 8:
		player.Set(LoadDivGraph("stpic/player.png", 2, 2, 1, 50, 30), 10);
		background1 = "stpic/background8_1.png";
		background2 = "stpic/background8_2.png";
		break;
	case 100:
		background1 = "stpic/12.5.png";
	}

	if (ver != 7) {//重力
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
	chip5 = "stpic/chip5.png";
	chip6 = "stpic/chip6.png";
	chip7 = "stpic/chip7.png";
	chip8 = "stpic/chip8.png";
	killer = "stpic/killer.png";
	stone = "stpic/stone.png";
	urchin = "stpic/urchin.png";
	fat = "stpic/fat.png";
	gameover = "stpic/over.png";
	one_two = "stpic/1 2.png";
	one_two_two = "stpic/1 2 2.png";
	two_three = "stpic/2 3.png";
	three_four = "stpic/3 4.png";
	three_four_two = "stpic/3 4 2.png";
	four_five = "stpic/4 5.png";
	four_five_two = "stpic/4 5 2.png";
	four_five_three = "stpic/4 5 3.png";
	five_six = "stpic/5 6.png";
	seven_eight = "stpic/7 8.png";
	deadbone = "stpic/deadbone.png";
	bone0 = "stpic/bone0.png";
	player3 = "stpic/player4.png";
	cactus = "stpic/cactus.png";
	cactusleft = "stpic/cactus_left.png";
	cactusright = "stpic/cactus_right.png";
	fireball = "stpic/fireball.png";
	ufo0 = "stpic/ufo0.png";
	ufo02 = "stpic/ufo02.png";
	volcano0 = "stpic/volcano0.png";
	bossbonehand = "stpic/bossbonehand.png";
	bone1.Set(LoadDivGraph("stpic/bone1.png", 7, 7, 1, 30, 50), 8);
	bone2.Set(LoadDivGraph("stpic/bone2.png", 4, 4, 1, 30, 50), 10);
	bird.Set(LoadDivGraph("stpic/bird.png", 4, 4, 1, 50, 30),8);
	trap.Set(LoadDivGraph("stpic/trap.png", 2, 2, 1, 40, 40), 8);
	bat.Set(LoadDivGraph("stpic/bat.png", 4, 4, 1, 40, 80), 6);
	ufo.Set(LoadDivGraph("stpic/ufo.png", 4, 4, 1, 48, 30), 4);
	fish.Set(LoadDivGraph("stpic/fish.png", 4, 4, 1, 55, 20), 8);
	bubble.Set(LoadDivGraph("stpic/bubble.png", 2, 2, 1, 40, 80), 10);
	eel.Set(LoadDivGraph("stpic/eel.png", 4, 4, 1, 150, 40), 8);
	scorpion1.Set(LoadDivGraph("stpic/scorpion1.png", 11, 11, 1, 50, 60), 7);
	scorpion0.Set(LoadDivGraph("stpic/scorpion0.png", 2, 2, 1, 50, 60), 8);
	storm.Set(LoadDivGraph("stpic/storm.png", 2, 2, 1, 800, 600), 4);
	groundfire.Set(LoadDivGraph("stpic/groundfire.png", 13, 13, 1, 40, 80), 8);
	ash.Set(LoadDivGraph("stpic/ash.png", 2, 2, 1, 800, 600), 8);
	volcano1.Set(LoadDivGraph("stpic/volcano1.png", 15, 15, 1, 632, 600), 4);
	volcano2.Set(LoadDivGraph("stpic/volcano2.png", 5, 5, 1, 632, 600), 4);
	fire.Set(LoadDivGraph("stpic/fire.png", 2, 2, 1, 800, 600), 4);
	littlefire.Set(LoadDivGraph("stpic/littlefire.png", 2, 2, 1, 80, 60), 4);
	fireballback.Set(LoadDivGraph("stpic/fireballback.png", 2, 2, 1, 120, 120), 4);
	bossbone.Set(LoadDivGraph("stpic/bossbone.png", 4, 4, 1, 300, 600), 8);
	bossbonehanddamage.Set(LoadDivGraph("stpic/bossbonehanddamage.png", 2, 2, 1, 60, 350), 8);

	for (int i=0; i < 20; i++) {
		K[i].x = 800;
		K[i].y = 800;
		K[i].flag = false;
	}

	for (int i = 0; i < 50; i++) {
		GF[i].x = 800;
		GF[i].y = 800;
		GF[i].flag = false;
	}

	for (int i = 0; i < 50; i++) {
		F3[i].x = 800;
		F3[i].y = 800;
		F3[i].flag = false;
		F3[i].hit = false;
	}

	for (int i = 0; i < 20; i++) {
		S2[i].x = 800;
		S2[i].y = 800;
		S2[i].flag = false;
		S3[i].flag = false;
	}

	for (int i = 0; i < 20; i++) {
		E[i].x = 800;
		E[i].y = 800;
		E[i].flag = false;
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
	for (int i = 0; i < 20; i++) {
		BO1[i].x = 800;
		BO1[i].y = 800;
		BO1[i].flag = false;
		BO1[i].count = -300;
	}
	for (int i = 0; i < 20; i++){
		DB[i].x = 800;
		DB[i].y = 800;
		DB[i].flag = false;
	}
	for (int i = 0; i < 50; i++) {
		C[i].x = 800;
		C[i].y = 800;
		C[i].flag = false;
	}
	for (int i = 0; i < 50; i++) {
		CL[i].x = 800;
		CL[i].y = 800;
		CL[i].flag = false;
	}
	for (int i = 0; i < 50; i++) {
		CR[i].x = 800;
		CR[i].y = 800;
		CR[i].flag = false;
	}
	for (int i = 0; i < 10; i++) {
		V1[i].x = 800;
		V1[i].y = 800;
		V1[i].flag = false;
		V2[i].flag = false;
		V1[i].count = 0;
	}
	for (int i = 0; i < 10; i++) {
		BBH[i].x = 800;
		BBH[i].y = 800;
		BBH[i].flag = false;
	}
	scrolX = 0;
	scrolY = 0;

	fy = 4000;
}

void CSGame::Loop() {
	if (stage == 100) {
		if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
			Game.FlipScene(new CSGame(19));
		}
	}
	if (wcount > 0) {
		wcount -= 1;
	}
	for (int i = 0; i < 10; i++) {
		if (V1[i].count > 0) {
			V1[i].count -= 1;
		}
	}

	d = 375 - (x - scrolX);
	x += vx;
	y += vy;
	vy += g;
	if (Yflag == false) {
		scrolY = 0;
	}
	else {
		scrolY = y - 300;
		if (scrolY < 0) {
			scrolY = 0;
		}
	}

	if (life == true) {
		fy -= 1;
	}



	if (life == true) {
		trap.PlusCount();
		bat.PlusCount();
		player.PlusCount();
		bird.PlusCount();
		ufo.PlusCount();
		fish.PlusCount();
		bubble.PlusCount();
		eel.PlusCount();
		bone1.PlusCount();
		bone2.PlusCount();
		scorpion1.PlusCount();
		scorpion0.PlusCount();
		storm.PlusCount();
		groundfire.PlusCount();
		ash.PlusCount();
		volcano1.PlusCount();
		volcano2.PlusCount();
		fire.PlusCount();
		littlefire.PlusCount();
		fireballback.PlusCount();
		bossbone.PlusCount();
		bossbonehanddamage.PlusCount();
	}
	else {}



	if (y < 0) {
		y += g;
	}
	if (y + jHeight < 0) {
		y = 0 - jHeight;
	}

	if ((ver == 3) || (ver == 4)) {
		if (vy > 7) {
			vy = 7;
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
	for (int i = 0; i < 50; i++) {
		if (life == true) {
			if (F3[i].hit == false) {
				F3[i].x -= 4;
				F3[i].y += 4;
			}
			else {}
		}
		else {}
	}
	for (int I = 0; I < mce.GetWidth(); I++) {
		for (int J = 0; J < mce.GetHeight(); J++) {
			if (mce.Get(mce.layer.A, I, J) != 0 && 7 && 8 && 9 && 10 && 12 && 13 && 14 && 15 && 17 && 19) {
				gUP = J * 40;
				break;
			}
		}
	}

	for (int i = 0; i < 50; i++) {
		if (F3[i].y + f3.height >= gUP) {
			F3[i].hit = true;
		}
	}

	for (int i = 0; i < 20; i++) {
		if (life == true) {
			E[i].x -= 5;
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
			B2[i].x -= 4;
		}
	}
	for (int i = 0; i < 20; i++) {
		if (life == true) {
			B[i].x -= 4;
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
				if (U[i].y + U[i].height > 600) {
					U[i].turn = false;
				}
			}

			else {
				U[i].y -= 5;
				if (U[i].y < 0) {
					U[i].turn = true;
				}
			}
		}
	}

	if (ver == 7) {
		if (y < 0) {
			y = 0;
		}
		if (y + jHeight > 600) {
			y = 600 - jHeight;
		}
	}

	if (stage == 12) {
		if (x > 6425) {
			vy = -5;
		}
	}

	if ((stage == 18) && (x > 6350)) {
		vy = -3;
	}


	vx = 0;

	//ゲームオーバー
	if (ver != 100) {
		if (x + jWidth < 6400) {
			if (x + jWidth < scrolX) {
				life = false;
			}
			if (ver != 7) {
				if (Yflag == false) {
					if (y > 600 - jHeight) {
						if (x < 6400) {
							life = false;
						}
					}
				}
				else {}
			}

			if (ver == 6) {
				if (y + jHeight > fy + 15) {
					life = false;
				}
			}
			for (int i = 0; i < 10; i++) {
				if (BBH[i].flag == true && (((x > BBH[i].x && x < BBH[i].x + bbh.width) || (x + jWidth > BBH[i].x && x + jWidth < BBH[i].x + bbh.width)) && ((y > BBH[i].y && y < BBH[i].y + bbh.height) || (y + jHeight > BBH[i].y && y + jHeight < BBH[i].y + bbh.height)))) {
					life = false;
				}
			}
				for (int i = 0; i < 20; i++) {
					if (K[i].flag == true && (((x > K[i].x && x < K[i].x + k.width) || (x + jWidth > K[i].x && x + jWidth < K[i].x + k.width)) && ((y > K[i].y && y < K[i].y + k.height) || (y + jHeight > K[i].y && y + jHeight < K[i].y + k.height)))) {
						life = false;
					}
				}
				for (int i = 0; i < 20; i++) {
					if (S2[i].flag == true && (((x > S2[i].x && x < S2[i].x + s2.width) || (x + jWidth > S2[i].x && x + jWidth < S2[i].x + s2.width)) && ((y > S2[i].y && y < S2[i].y + s2.height) || (y + jHeight > S2[i].y && y + jHeight < S2[i].y + s2.height)))) {
						life = false;
					}
				}
				for (int i = 0; i < 20; i++) {
					if (E[i].flag == true && (((x > E[i].x && x < E[i].x + e.width) || (x + jWidth > E[i].x && x + jWidth < E[i].x + e.width)) && ((y > E[i].y && y < E[i].y + e.height) || (y + jHeight > E[i].y && y + jHeight < E[i].y + e.height)))) {
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
					if (GF[i].flag == true && (((x > GF[i].x && x < GF[i].x + gf.width) || (x + jWidth > GF[i].x && x + jWidth < GF[i].x + gf.width)) && ((y > GF[i].y && y < GF[i].y + gf.height) || (y + jHeight > GF[i].y && y + jHeight < GF[i].y + gf.height)))) {
						life = false;

					}
				}

				for (int i = 0; i < 50; i++) {
					if (F3[i].flag == true && (((x > F3[i].x && x < F3[i].x + f3.width) || (x + jWidth > F3[i].x && x + jWidth < F3[i].x + f3.width)) && ((y > F3[i].y && y < F3[i].y + f3.height) || (y + jHeight > F3[i].y && y + jHeight < F3[i].y + f3.height)))) {
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
				for (int i = 0; i < 20; i++) {
					if (BO1[i].flag == true && (((x > BO1[i].x && x < BO1[i].x + bo1.width) || (x + jWidth > BO1[i].x && x + jWidth < BO1[i].x + bo1.width)) && ((y > BO1[i].y && y < BO1[i].y + bo1.height) || (y + jHeight > BO1[i].y && y + jHeight < BO1[i].y + bo1.height)))) {
						life = false;
					}
				}
				for (int i = 0; i < 20; i++) {
					if (DB[i].flag == true && (((x > DB[i].x && x < DB[i].x + db.width) || (x + jWidth > DB[i].x && x + jWidth < DB[i].x + db.width)) && ((y > DB[i].y && y < DB[i].y + db.height) || (y + jHeight > DB[i].y && y + jHeight < DB[i].y + db.height)))) {
						life = false;
					}
				}
				for (int i = 0; i < 50; i++) {
					if (C[i].flag == true && (((x > C[i].x && x < C[i].x + c.width) || (x + jWidth > C[i].x && x + jWidth < C[i].x + c.width)) && ((y > C[i].y && y < C[i].y + c.height) || (y + jHeight > C[i].y && y + jHeight < C[i].y + c.height)))) {
						life = false;
					}
				}
				for (int i = 0; i < 50; i++) {
					if (CL[i].flag == true && (((x > CL[i].x && x < CL[i].x + cl.width) || (x + jWidth > CL[i].x && x + jWidth < CL[i].x + cl.width)) && ((y > CL[i].y && y < CL[i].y + cl.height) || (y + jHeight > CL[i].y && y + jHeight < CL[i].y + cl.height)))) {
						life = false;
					}
				}
				for (int i = 0; i < 50; i++) {
					if (CR[i].flag == true && (((x > CR[i].x && x < CR[i].x + cr.width) || (x + jWidth > CR[i].x && x + jWidth < CR[i].x + cr.width)) && ((y > CR[i].y && y < CR[i].y + cr.height) || (y + jHeight > CR[i].y && y + jHeight < CR[i].y + cr.height)))) {
						life = false;
					}
				}
			}
		}
		if (life == true) {
			if (x + jWidth < 6400) {
				if (ver == 7) {
					if (vy > 0) {
						vy -= 1;
						if (vy < 0) {
							vy = 0;
						}
					}
					if (vy < 0) {
						vy += 1;
						if (vy > 0) {
							vy = 0;
						}
					}
					if (Input.GetKeyDown(Input.key.UP)) {
						vy = -7;
					}
					if (Input.GetKeyDown(Input.key.DOWN)) {
						vy = 7;
					}
				}
				else if ((ver == 3) || (ver == 4)) {
					if (Input.GetKeyEnter(Input.key.UP) && jumpf > 0) {
						--jumpf;
						wcount = 10;
					}
					if ((jumpf == 0) || (jumpf == 1)) {
						if (wcount > 0) {
							vy -= 7;
						}
					}
					if (vy < -7) {
						vy = -7;
					}
				}
				else {
					if (Input.GetKeyEnter(Input.key.UP) && jumpf > 0) {
						--jumpf;
						vy = -15;
					}
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
				if (Yflag == false) {
					if (x + jWidth + d < 6400) {
						scrolX += 5;
					}
				}
			}
			else {
				vx = 0;
				vy = 0;
			}
		}
		else {
			if (Input.GetKeyDown(Input.key.RIGHT)) {
				vx += 5;
				if (Yflag == false) {
					scrolX += 5;
				}
			}
			if (Input.GetKeyDown(Input.key.LEFT)) {
				vx -= 5;
				if (Yflag == false) {
					scrolX -= 5;
				}
			}
		}
		if (Yflag == true) {
			if (x > 775) {
				x = 0;
			}
			if (x < 0) {
				x = 775;
			}
		}


		if (x + jWidth > 6400) {
			vx = 5;
		}

		if (x + jWidth == 6800) {
			Game.FlipScene(new CSComplete(stage), Flip::CROSS_FADE, 8);
		}

		if (stage != 100) {
			for (int i = x / 40, endI = (x + 50) / 40, endJ = (y + 30) / 40; i <= endI; ++i) {
				for (int j = y / 40; j <= endJ; ++j) {
					if (mce.Get(mce.layer.A, i, j) != 0) {
						HitBlock(i, j);
					}
				}
			}
		}


		for (int i = 0; i < 20; i++) {
			if (K[i].x + K[i].width < scrolX) {
				K[i].flag = false;
			}
		}

		for (int i = 0; i < 10; i++) {
			if (BBH[i].x + BBH[i].width < scrolX) {
				BBH[i].flag = false;
			}
		}

		for (int i = 0; i < 10; i++) {
			if (V1[i].x + V1[i].width < scrolX) {
				V1[i].flag = false;
				V2[i].flag = false;
			}
		}

		for (int i = 0; i < 20; i++) {
			if (S2[i].x + S2[i].width < scrolX) {
				S2[i].flag = false;
				S3[i].flag = false;
			}
		}

		for (int i = 0; i < 50; i++) {
			if (C[i].x + C[i].width < scrolX) {
				C[i].flag = false;
			}
		}

		for (int i = 0; i < 50; i++) {
			if (GF[i].x + GF[i].width < scrolX) {
				GF[i].flag = false;
			}
		}

		for (int i = 0; i < 50; i++) {
			if (CL[i].x + CL[i].width < scrolX) {
				CL[i].flag = false;
			}
		}

		for (int i = 0; i < 50; i++) {
			if (CR[i].x + CR[i].width < scrolX) {
				CR[i].flag = false;
			}
		}

		for (int i = 0; i < 20; i++) {
			if (E[i].x + E[i].width < scrolX) {
				E[i].flag = false;
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
			if (F3[i].x + F3[i].width < scrolX) {
				F3[i].flag = false;
				F3[i].hit = false;
			}
		}

		for (int i = 0; i < 50; i++) {
			if (S[i].x + S[i].width < scrolX) {
				S[i].flag = false;
			}
		}
		for (int i = 0; i < 20; i++) {
			if (BO1[i].x + BO1[i].width < scrolX) {
				BO1[i].flag = false;
			}
		}
		for (int i = 0; i < 20; i++) {
			if (DB[i].x + DB[i].width < scrolX) {
				DB[i].flag = false;
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
				if (mce.Get(mce.layer.B, i, j) == 6 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 5 - d) {
					for (int I = 0; I < 20; I++) {
						if (E[I].flag == false) {
							E[I].x = i * 40;
							E[I].y = j * 40;
							E[I].flag = true;
							break;
						}
					}
				}
			}
		}

		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.B, i, j) == 8 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 5 - d) {
					for (int I = 0; I < 50; I++) {
						if (F3[I].flag == false) {
							F3[I].x = i * 40;
							F3[I].y = j * 40;
							F3[I].flag = true;
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
				if (mce.Get(mce.layer.C, i, j) == 6 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 5 - d) {
					for (int I = 0; I < 50; I++) {
						if (GF[I].flag == false) {
							GF[I].x = i * 40;
							GF[I].y = j * 40;
							GF[I].flag = true;
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
				if (mce.Get(mce.layer.C, i, j) == 2 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 5 - d) {
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
				if (mce.Get(mce.layer.C, i, j) == 3 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 5 - d) {
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

		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.C, i, j) == 4 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 5 - d) {
					for (int I = 0; I < 20; I++) {
						if (DB[I].flag == false) {
							DB[I].x = i * 40;
							DB[I].y = j * 40 + 10;
							DB[I].flag = true;
							break;
						}
					}
				}
			}
		}

		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.C, i, j) == 5 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 5 - d) {
					for (int I = 0; I < 50; I++) {
						if ((C[I].flag == false) && (CL[I].flag == false) && (CR[I].flag == false)) {
							C[I].x = i * 40;
							CL[I].x = i * 40 - CL[I].width;
							CR[I].x = i * 40 + C[I].width;
							C[I].y = j * 40 - 60;
							CL[I].y = j * 40 - 40;
							CR[I].y = j * 40 - 20;
							C[I].flag = true;
							CL[I].flag = true;
							CR[I].flag = true;
							break;
						}
					}
				}
			}
		}

		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.B, i, j) == 7 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 5 - d) {
					for (int I = 0; I < 20; I++) {
						if (S2[I].flag == false) {
							S2[I].x = i * 40;
							S2[I].y = j * 40 - 20;
							S2[I].flag = true;
							S2[I].count = 150;
							break;
						}
					}
				}
			}
		}
		for (int i = 0; i < 20; i++) {
			if (S2[i].count > 0) {
				S2[i].count -= 1;
			}
		}

		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.B, i, j) == 5 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 5 - d) {
					for (int I = 0; I < 20; I++) {
						if (BO1[I].flag == false) {
							BO1[I].x = i * 40;
							BO1[I].y = j * 40 - 10;
							BO1[I].flag = true;
							BO1[I].count = 140;
							break;

						}
					}
				}
			}
		}
		for (int i = 0; i < 20; i++) {
			if (BO1[i].count > -300) {
				BO1[i].count -= 1;
				if (BO1[i].count < 0) {
					if (life == true) {
						BO1[i].x -= 2;
						if (BO1[i].count >= -20) {
							BO1[i].y -= 5;
						}
						else if (BO1[i].count >= -40) {
							BO1[i].y += 5;
						}
					}
				}
			}
		}
		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.C, i, j) == 7 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 5 - d) {
					for (int I = 0; I < 10; I++) {
						V1[I].x = i * 40;
						V1[I].y = j * 40;
						V1[I].flag = true;
						V2[I].flag = true;
						V1[I].count = 250;
						break;
					}
				}
			}
		}
		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.B, i, j) == 9 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 5 - d) {
					for (int I = 0; I < 10; I++) {
						if (BBH[I].flag == false) {
							BBH[I].x = i * 40;
							BBH[I].y = 600;
							BBH[I].flag = true;
							break;
						}
					}
				}
			}
		}
		for (int i = 0; i < 10; i++) {
			if (BBH[i].flag == true) {
				if (BBH[i].y > 250) {
						BBH[i].y-=3;
				}
				else {
					BBH[i].y = 250;
				}
			}
		}
	}




void CSGame::Draw() {

	if ((ver == 0) || (ver == 100)) {
		background1(0, 0);
	}
	else {
		background5(0 - scrolX * 0.2, 0);
		background4(0 - scrolX * 0.4, 0);
		background3(0 - scrolX * 0.6, 0);
		background2(0 - scrolX * 0.8, 0);
		background1(0 - scrolX, 0);
	}

		for (int i = 0; i < 10; i++) {
			if (V1[i].flag == true) {
				if (V1[i].count > 42) {
					volcano0(V1[i].x - scrolX, V1[i].y - scrolY);
				}
				else if (V1[i].count > 0) {
					volcano1(V1[i].x - scrolX, V1[i].y - scrolY, false, false);
				}
				else {
					volcano2(V1[i].x - scrolX, V1[i].y - scrolY, false, false);
				}
			}
		}

/*	for (int i = 0; i < 10; i++) {
		if (V1[i].flag == true) {
			if (x < V1[i].x + 200) {
				volcano0(V1[i].x - scrolX, V1[i].y - scrolY);
			}
			else if (x < V1[i].x + 400) {
				volcano1(V1[i].x - scrolX, V1[i].y - scrolY, false, false);
			}
			else {
				volcano2(V1[i].x - scrolX, V1[i].y - scrolY, false, false);
			}
		}
	}*/



	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 7) {
				one_two(i * 40 - scrolX, j * 40 - scrolY);
			}
		}
	}
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 8) {
				two_three(i * 40 - scrolX, j * 40 - scrolY);
			}
		}
	}
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 12) {
				three_four(i * 40 - scrolX, j * 40 - scrolY);
			}
		}
	}
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 14) {
				four_five(i * 40 - scrolX, j * 40 - scrolY);
			}
		}
	}
	if (stage != 100) {
		if ((stage == 12) && (x > 6425)) {
			player3(x - scrolX, y + 20 - scrolY);
		}
		else {
			if (ver != 5) {
					player(x - scrolX, y - scrolY, false, false);
			}
			else {
				player(x - scrolX, y - scrolY, false, false);
			}
		}
	}
	if ((ver == 3) || (ver == 4)) {
		bubble(x - scrolX - 40, y - 40 - scrolY, false, false);
	}

	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 10) {
				one_two_two(i * 40 - scrolX, j * 40 - scrolY);
			}
		}
	}
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 13) {
				three_four_two(i * 40 - scrolX, j * 40 - scrolY);
			}
		}
	}
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 15) {
				four_five_two(i * 40 - scrolX, j * 40 - scrolY);
			}
		}
	}
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 15) {
				four_five_three(i * 40 - scrolX, j * 40 - scrolY);
			}
		}
	}
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 17) {
				five_six(i * 40 - scrolX, j * 40 - scrolY);
			}
		}
	}
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j)== 19){
				seven_eight(i * 40 - scrolX, j * 40 - scrolY);
			}
		}
	}




	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 1) {
				chip1_1(i * 40 - scrolX, j * 40 - scrolY);
			}
		}
	}
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 2) {
				chip1_2(i * 40 - scrolX, j * 40 - scrolY);
			}
		}
	}
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 3) {
				chip2_1(i * 40 - scrolX, j * 40 - scrolY);
			}
		}
	}
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 4) {
				chip2_2(i * 40 - scrolX, j * 40 - scrolY);
			}
		}
	}
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 5) {
				chip3(i * 40 - scrolX, j * 40 - scrolY);
			}
		}
	}
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 6) {
				chip4(i * 40 - scrolX, j * 40 - scrolY);
			}
		}
	}
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 11) {
				chip5(i * 40 - scrolX, j * 40 - scrolY);
			}
		}
	}
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 16) {
				chip6(i * 40 - scrolX, j * 40 - scrolY);
			}
		}
	}
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 20) {
				chip8(i * 40 - scrolX, j * 40 - scrolY);
			}
		}
	}
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.A, i, j) == 18) {
				chip7(i * 40 - scrolX, j * 40 - scrolY);
			}
		}
	}
	
	for (int i = 0; i < 50; i++) {
		if (T[i].flag == true) {
			trap(T[i].x - scrolX, T[i].y - scrolY , false, false);
		}
	}
	for (int i = 0; i < 50; i++) {
		if (U2[i].flag == true) {
			urchin(U2[i].x - scrolX - scrolY, U2[i].y);
		}
	}
	for (int i = 0; i < 20; i++) {
		if (K[i].flag == true) {
			killer(K[i].x - scrolX, K[i].y - scrolY, true);
		}
	}
	for (int i = 0; i < 20; i++) {
		if (E[i].flag == true) {
			eel(E[i].x - scrolX, E[i].y - scrolY, false, false);
		}
	}
	for (int i = 0; i < 20; i++) {
		if (DB[i].flag == true) {
			deadbone(DB[i].x - scrolX, DB[i].y - scrolY);
		}
	}
	for (int i = 0; i < 50; i++) {
		if (C[i].flag == true) {
			cactus(C[i].x - scrolX, C[i].y - scrolY);
		}
	}
	for (int i = 0; i < 50; i++) {
		if (CL[i].flag == true) {
			cactusleft(CL[i].x - scrolX, CL[i].y - scrolY);
		}
	}
	for (int i = 0; i < 50; i++) {
		if (CR[i].flag == true) {
			cactusright(CR[i].x - scrolX, CR[i].y - scrolY);
		}
	}
	for (int i = 0; i < 50; i++) {
		if (F3[i].flag == true) {
			if (F3[i].hit == false) {
				fireball(F3[i].x - scrolX, F3[i].y - scrolY);
				fireballback(F3[i].x - 40 - scrolX, F3[i].y - 40 - scrolY,false,false);
			}
			else {
				littlefire(F3[i].x - 20 - scrolX, F3[i].y - scrolY,false,false);
			}
		}

	}
	for (int i = 0; i < 50; i++) {
		if (GF[i].flag == true) {
			groundfire(GF[i].x - scrolX, GF[i].y - 40 - scrolY, false, false);
		}
	}
	for (int i = 0; i < 20; i++) {
		if (F2[i].flag == true) {
			fish(F2[i].x - scrolX, F2[i].y - scrolY, false, false);
		}
	}
	for (int i = 0; i < 20; i++) {
		if (B[i].flag == true) {
			bird(B[i].x - scrolX, B[i].y - scrolY, false, false);
		}
	}
	for (int i = 0; i < 20; i++) {
		if (F[i].flag == true) {
			fat(F[i].x - scrolX, F[i].y - scrolY);
		}
	}
	for (int i = 0; i < 20; i++) {
		if (B2[i].flag == true) {
			bat(B2[i].x - scrolX, B2[i].y - scrolY, false, false);
		}
	}
	for (int i = 0; i < 50; i++) {
		if (S[i].flag == true) {
			stone(S[i].x - scrolX, S[i].y - scrolY);
		}
	}
	for (int i = 0; i < 50; i++) {
		if (U[i].flag == true) {
			ufo(U[i].x - scrolX, U[i].y - scrolY, false, false);
		}
	}
	for (int i = 0; i < 20; i++) {
		if (S2[i].count > 0) {
			scorpion0(S2[i].x - scrolX, S2[i].y - scrolY, false, false);
		}
		else {
			scorpion1(S2[i].x - scrolX, S2[i].y - scrolY, false, false);
		}
	}
	for (int i = 0; i < 20; i++) {
		if (BO1[i].flag == true) {
			if (BO1[i].count >= 40) {
				bone0(BO1[i].x - scrolX, BO1[i].y - scrolY);
			}
			else if ((BO1[i].count >= 0) && (BO1[i].count < 40)) {
				bone1(BO1[i].x - scrolX, BO1[i].y - scrolY, false, false);
			}
			else {
				bone2(BO1[i].x - scrolX, BO1[i].y - scrolY, false, false);
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		bossbonehand(BBH[i].x - scrolX, BBH[i].y - scrolY);
	}
	if (ver == 4) {
		if (scrolX < 5500) {
			bossbone(0, 0, false, false);
		}
		else {
			bossbone(5500 - scrolX, 0, false, false);
		}
	}



	if ((stage == 18) && (x >= 6300)) {
		ufo0(x - 25 - scrolX, y - 150 - scrolY);
	}
	else if ((stage == 18) && (x + jWidth >= 5500)) {
		ufo02(6300 - 25 - scrolX, y - 150 - scrolY);
	}

	if (ver == 5) {
		storm(0, 0, false, false);
	}
	if (ver == 6) {
		ash(0, 0, false, false);
	}
	/*if (ver == 6) {
		fire(0, fy - scrolY, false, false);
	}*/



		if (life == false) {
			DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
			gameover();
		}
		DrawBox(6395 - scrolX, 0 - scrolY, 6400 - scrolX, 600,RED,true);
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