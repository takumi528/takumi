#include "MyScene.h"

const bool autoMove = true;
const bool invincible = false;

void CSGame::Start() {
	switch (stage) {//ステージ数
	case 0:
	default:
		mce = "stpic/stage0.mce";
		ver = 0;
		break;
	case 1:
		mce = "stpic/stage1.mce";
		ver = 1;
		break;
	case 2:
		mce = "stpic/stage2.mce";
		ver = 1;
		break;
	case 3:
		mce = "stpic/stage3.mce";
		ver = 1;
		break;
	case 4:
		mce = "stpic/stage4.mce";
		ver = 2;
		break;
	case 5:
		mce = "stpic/stage5.mce";
		ver = 2;
		break;
	case 6:
		mce = "stpic/stage6.mce";
		ver = 2;
		break;
	case 7:
		mce = "stpic/stage7.mce";
		ver = 3;
		break;
	case 8:
		mce = "stpic/stage8.mce";
		ver = 3;
		break;
	case 9:
		mce = "stpic/stage9.mce";
		ver = 3;
		break;
	case 10:
		mce = "stpic/stage10.mce";
		ver = 4;
		break;
	case 11:
		mce = "stpic/stage11.mce";
		ver = 4;
		break;
	case 12:
		mce = "stpic/stage12.mce";
		ver = 4;
		break;
	case 13:
		mce = "stpic/stage13.mce";
		ver = 5;
		break;
	case 14:
		mce = "stpic/stage14.mce";
		ver = 5;
		break;
	case 15:
		mce = "stpic/stage15.mce";
		ver = 5;
		break;
	case 16:
		mce = "stpic/stage16.mce";
		ver = 6;
		break;
	case 17:
		mce = "stpic/stage17.mce";
		ver = 6;
		break;
	case 18:
		mce = "stpic/stage18.mce";
		ver = 6;
		break;
	case 19:
		mce = "stpic/stage19.mce";
		ver = 7;
		break;
	case 20:
		mce = "stpic/stage20.mce";
		ver = 7;
		break;
	case 21:
		mce = "stpic/stage21.mce";
		ver = 7;
		break;
	case 22:
		mce = "stpic/stage22.mce";
		ver = 8;
		break;
	case 23:
		mce = "stpic/stage23.mce";
		ver = 8;
		break;
	case 24:
		mce = "stpic/stage24.mce";
		ver = 9;
		break;
	case 100:
		mce = "stpic/a.mce";
		ver = 100;
		break;
	case 101:
		mce = "stpic/a.mce";
		ver = 101;
		break;
	case 102:
		mce = "stpic/a.mce";
		ver = 102;
		break;
	case 103:
		mce = "stpic/a.mce";
		ver = 103;
		break;
	case 104:
		mce = "stpic/a.mce";
		ver = 104;
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
	lx = 0;
	ly = 0;
	jturn = false;
	overM = 0;

	

	switch (ver) {//ステージ数
	case 0:
	default:
		player.Set(LoadDivGraph("stpic/player.png", 2, 2, 1, 50, 30), 20);
		background1 = "stpic/background0.png";
		Music.Load(M_VER, "stpic/ver0.mp3");
		break;
	case 1:
		player.Set(LoadDivGraph("stpic/player.png", 2, 2, 1, 50, 30), 20);
		background1 = "stpic/background1_1.png";
		background2 = "stpic/background1_2.png";
		background3 = "stpic/background1_3.png";
		background4 = "stpic/background1_4.png";
		Music.Load(M_VER, "stpic/ver1.mp3");
		break;
	case 2:
		player.Set(LoadDivGraph("stpic/player.png", 2, 2, 1, 50, 30), 20);
		background1 = "stpic/background2_1.png";
		background2 = "stpic/background2_2.png";
		background3 = "stpic/background2_3.png";
		background4 = "stpic/background2_4.png";
		background5 = "stpic/background2_5.png";
		Music.Load(M_VER, "stpic/ver2.mp3");
		break;
	case 3:
		player.Set(LoadDivGraph("stpic/player2.png", 5, 5, 1, 58, 30), 5);
		background1 = "stpic/background3_1.png";
		background2 = "stpic/background3_2.png";
		background3 = "stpic/background3_3.png";
		Music.Load(M_VER, "stpic/ver3.mp3");
		break;
	case 4:
		player.Set(LoadDivGraph("stpic/player2.png", 5, 5, 1, 58, 30), 5);
		background1 = "stpic/background4.png";
		background2 = "stpic/background4_2.png";
		background3 = "stpic/background4_3.png";
		background4 = "stpic/background4_4.png";
		Music.Load(M_VER, "stpic/ver4.mp3");
		break;
	case 5:
		player.Set(LoadDivGraph("stpic/player.png", 2, 2, 1, 50, 30), 10);
		background1 = "stpic/background5_1.png";
		background2 = "stpic/background5_2.png";
		background3 = "stpic/background5_3.png";
		Music.Load(M_VER, "stpic/ver5.mp3");
		break;
	case 6:
		player.Set(LoadDivGraph("stpic/player.png", 2, 2, 1, 50, 30), 10);
		background1 = "stpic/background6_1.png";
		background2 = "stpic/background6_2.png";
		background3 = "stpic/background6_3.png";
		Music.Load(M_VER, "stpic/ver6.mp3");

		break;
	case 7:
		player.Set(LoadDivGraph("stpic/player.png", 2, 2, 1, 50, 30), 10);
		background1 = "stpic/background7_1.png";
		background2 = "stpic/background7_2.png";
		background3 = "stpic/background7_3.png";
		background4 = "stpic/background7_4.png";
		Music.Load(M_VER, "stpic/ver7.mp3");
		break;
	case 8:
		player.Set(LoadDivGraph("stpic/player.png", 2, 2, 1, 50, 30), 10);
		background1 = "stpic/ufoback.png";
		if (stage == 22) {
			Music.Load(M_VER, "stpic/stage22.mp3");
		}
		else if (stage == 23); {
			Music.Load(M_VER, "stpic/stage23.mp3");
		}
		break;
	case 9:
		player.Set(LoadDivGraph("stpic/player.png", 2, 2, 1, 50, 30), 10);
		background1 = "stpic/backgroundend.png";
		Music.Load(M_VER, "stpic/ver1.mp3");
		break;
	case 100:
		background1 = "stpic/18.5.png";
		break;
	case 101:
		background1 = "stpic/9.5.png";
		break;
	case 102:
		background1 = "stpic/12.5.png";
		break;
	case 103:
		background1 = "stpic/21.5.png";
		break;
	case 104:
		background1 = "stpic/22.5.png";
	}



	if ((ver == 7) || (ver == 8)) {//重力
		g = 0;
	}
	else {
		g = 1;
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
	seven_eight_one = "stpic/7 8 1.png";
	seven_eight_two = "stpic/7 8 2.png";
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
	light = "stpic/light.png";
	battery = "stpic/battery.png";
	batterynumber0 = "stpic/batterynumber0.png";
	batterynumber1 = "stpic/batterynumber1.png";
	batterynumber2 = "stpic/batterynumber2.png";
	batterynumber3 = "stpic/batterynumber3.png";
	killbone = "stpic/killbone.png";
	limitgauge = "stpic/limitgauge.png";
	rufo = "stpic/activeufo.png";
	lufo = "stpic/activeufo.png";
	uufo = "stpic/activeufo.png";
	dufo = "stpic/activeufo.png";
	ruufo = "stpic/activeufo.png";
	rdufo = "stpic/activeufo.png";
	bosshandU = "stpic/bosshandU.png";
	bosshandUdamage = "stpic/bosshandUdamage.png";
	bosshandD = "stpic/bosshandD.png";
	bosshandDdamage = "stpic/bosshandDdamage.png";
	bosshandR = "stpic/bosshand.png";
	bosshandL = "stpic/bosshand.png";
	bosshandUR = "stpic/bosshand.png";
	bosshandUL = "stpic/bosshand.png";
	bosshandDR = "stpic/bosshand.png";
	bosshandDL = "stpic/bosshand.png";
	bosshandR2 = "stpic/bosshandRR.png";
	bosshandL2 = "stpic/bosshandLL.png";
	bosshandUR2 = "stpic/bosshandRU.png";
	bosshandUL2 = "stpic/bosshandLU.png";
	bosshandDR2 = "stpic/bosshandRD.png";
	bosshandDL2 = "stpic/bosshandLD.png";
	bosshandshadow1 = "stpic/bosshandshadow1.png";
	bosshandshadow2 = "stpic/bosshandshadow2.png";
	bosshandshadow3 = "stpic/bosshandshadow3.png";
	bosshandshadow4 = "stpic/bosshandshadow4.png";
	bosshandshadow5 = "stpic/bosshandshadow5.png";
	missile = "stpic/missile.png";
	missileshot = "stpic/missileshot.png";
	bosslifebar = "stpic/bosslifebar.png";
	missilemeter = "stpic/missilemeter.png";
	missilemeter2 = "stpic/missilemeter2.png";
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
	bossbonedamage.Set(LoadDivGraph("stpic/bossbonedamage.png", 4, 4, 1, 300, 600), 8);
	oasis.Set(LoadDivGraph("stpic/oasis.png", 2, 2, 1, 40, 40), 4);
	turnplayer.Set(LoadDivGraph("stpic/turnplayer.png", 2, 2, 1, 50, 30), 10);
	boss.Set(LoadDivGraph("stpic/boss.png", 2, 2, 1, 800, 600), 20);
	back8_1.Set(LoadDivGraph("stpic/background8_1.png", 8, 8, 1, 800, 600), 8);
	back8_2.Set(LoadDivGraph("stpic/background8_2.png", 8, 8, 1, 800, 600), 8);

	for (int i = 0; i < 50; i++) {
		RU[i].x = 800;
		RU[i].y = 800;
		RU[i].flag = false;
	}

	for (int i = 0; i < 50; i++) {
		LU[i].x = 800;
		LU[i].y = 800;
		LU[i].flag = false;
	}

	for (int i = 0; i < 50; i++) {
		UU[i].x = 800;
		UU[i].y = 800;
		UU[i].flag = false;
	}

	for (int i = 0; i < 50; i++) {
		DU[i].x = 800;
		DU[i].y = 800;
		DU[i].flag = false;
	}

	for (int i = 0; i < 50; i++) {
		RUU[i].x = 800;
		RUU[i].y = 800;
		RUU[i].flag = false;
	}

	for (int i = 0; i < 50; i++) {
		RDU[i].x = 800;
		RDU[i].y = 800;
		RDU[i].flag = false;
	}

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

	for (int i = 0; i < 100; i++) {
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
		BBH[i].damage = false;
	}
	for (int i = 0; i < 20; i++) {
		B3[i].x = 800;
		B3[i].y = 800;
		B3[i].flag = false;
		B3[i].get = false;
	}
	for (int i = 0; i < 50; i++) {
		O[i].x = 800;
		O[i].y = 800;
		O[i].flag = false;
	}
	for (int i = 0; i < 20; i++) {
		BHU[i].x = 800;
		BHU[i].y = 800;
		BHU[i].flag = false;
		BHU[i].damagecount = 0;
	}
	for (int i = 0; i < 20; i++) {
		BHD[i].x = 800;
		BHD[i].y = 800;
		BHD[i].flag = false;
		BHD[i].damagecount = 0;
	}
	for (int i = 0; i < 20; i++) {
		BHR[i].x = 800;
		BHR[i].y = 800;
		BHR[i].v = 0;
		BHR[i].flag = false;
	}
	for (int i = 0; i < 20; i++) {
		BHL[i].x = 800;
		BHL[i].y = 800;
		BHL[i].v = 0;
		BHL[i].flag = false;
	}
	for (int i = 0; i < 20; i++) {
		BHUR[i].x = 800;
		BHUR[i].y = 800;
		BHUR[i].v = 0;
		BHUR[i].vy = 0;
		BHUR[i].flag = false;
	}
	for (int i = 0; i < 20; i++) {
		BHUL[i].x = 800;
		BHUL[i].y = 800;
		BHUL[i].v = 0;
		BHUL[i].vy = 0;
		BHUL[i].flag = false;
	}
	for (int i = 0; i < 20; i++) {
		BHDR[i].x = 800;
		BHDR[i].y = 800;
		BHDR[i].v = 0;
		BHDR[i].vy = 0;
		BHDR[i].flag = false;
	}
	for (int i = 0; i < 20; i++) {
		BHDL[i].x = 800;
		BHDL[i].y = 800;
		BHDL[i].v = 0;
		BHDL[i].vy = 0;
		BHDL[i].flag = false;
	}
	for (int i = 0; i < 20; i++) {
		M[i].x = 800;
		M[i].y = 800;
		M[i].flag = false;
	}
	for (int i = 0; i < 20; i++) {
		MS[i].x = 800;
		MS[i].y = 800;
		MS[i].flag = false;
	}

	kb.x = 800;
	kb.y = y;
	kb.flag = false;
	scrolX = 0;
	scrolY = 0;
	Lflag = false;
	Lcount = 0;
	batterycount = 0;
	missilecount = 0;
	fy = 4000;
	bb.x = 0;
	bossbonedamagecount = 0;
	limit = 500;
	bosslife = 5000;

	if (stage == 10) {
		bossbonelife = 3;
	}
	if (stage == 11) {
		bossbonelife = 4;
	}
	if (stage == 12) {
		bossbonelife = 3;
	}
}

void CSGame::Loop() {
	if (life == true) {
		Music.PlayLoop(M_VER);
	}
	
	if (stage == 100) {
		if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
			Game.FlipScene(new CSGame(19));
			Music.Play(M_SELECT);
		}
	}
	if (stage == 101) {
		if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
			Game.FlipScene(new CSGame(10));
			Music.Play(M_SELECT);
		}
	}
	if (stage == 102) {
		if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
			Game.FlipScene(new CSGame(13));
			Music.Play(M_SELECT);
		}
	}
	if (stage == 103) {
		if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
			Game.FlipScene(new CSGame(22));
			Music.Play(M_SELECT);
		}
	}
	if (stage == 104) {
		if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
			Game.FlipScene(new CSGame(23));
			Music.Play(M_SELECT);
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
	if (bossbonedamagecount > 0) {
		bossbonedamagecount -= 1;
	}

	if (ver == 5) {
		if (limit > 0) {
			if (x + jWidth < 6400) {
				if (life == true) {
					limit -= 1;
				}
			}
		}
	}
	d = 375 - (x - scrolX);
	x += vx;
	y += vy;
	vy += g;
	lx = x + jWidth;
	ly = y - 25;
	if (life == true) {
		kb.x += 12;
	}
	kb.y = y;

	if (life == false) {
		if (overM < 2) {
			overM++;
		}
	}
	if (overM < 2) {
		if (life == false) {
			Music.Play(M_OVER);
		}
	}
	if (life == true) {
		overM = 0;
	}
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

	if (ver == 4) {
		if (Lcount > 0) {
			Lflag = true;
			Lcount -= 1;
		}
		else {
			Lflag = false;
		}
		if (batterycount > 0) {
			if (Input.GetKeyEnter(Input.key.SPACE)) {
				Lcount = 20;
				batterycount -= 2;
				Music.Play(M_BATTERY);
			}
		}
	}
	if (missilecount > 0) {
		if (Input.GetKeyEnter(Input.key.SPACE)) {
			for (int i = 0; i < 20; i++) {
				if (MS[i].flag == false) {
					MS[i].flag = true;
					MS[i].x = x;
					MS[i].y = y;
					break;
				}
			}
			Music.Play(M_MISSILE);
			missilecount -= 2;
		}
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
		bossbonedamage.PlusCount();
		oasis.PlusCount();
		boss.PlusCount();
		if (x < 6400) {
			back8_1.PlusCount();
		}
		back8_2.PlusCount();
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

	for (int i = 0; i < 50; i++) {
		if (life == true) {
			RU[i].x += 14;
		}
	}
	for (int i = 0; i < 50; i++) {
		if (life == true) {
			LU[i].x -= 4;
		}
	}
	for (int i = 0; i < 50; i++) {
		if (life == true) {
			UU[i].x -= 4;
			UU[i].y -= 8;
		}
	}
	for (int i = 0; i < 50; i++) {
		if (life == true) {
			DU[i].x -= 4;
			DU[i].y += 8;
		}
	}
	for (int i = 0; i < 50; i++) {
		if (life == true) {
			RUU[i].x += 14;
			RUU[i].y -= 8;
		}
	}
	for (int i = 0; i < 50; i++) {
		if (life == true) {
			RDU[i].x += 14;
			RDU[i].y += 8;
		}
	}
	for (int i = 0; i < 20; i++) {
		if (life == true) {
			K[i].x -= 4;
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
	if (life == true) {
		if (bossbonelife > 0) {
			if (bossbonelife > 0) {
				if (bb.x < 5900) {
					bb.x += 5;
				}
			}
			else {}
		}
		else {}
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

	for (int i = 0; i < 20; i++) {
		if (life == true) {
			if (BHU[i].y > 300) {
				BHU[i].y -= 10;
			}
		}
		if (BHU[i].damagecount > 0) {
			BHU[i].damagecount--;
		}
	}
	for (int i = 0; i < 20; i++) {
		if (life == true) {
			if (BHD[i].y + BHD[i].height < 300) {
				BHD[i].y += 10;
			}
		}
		if (BHD[i].damagecount > 0) {
			BHD[i].damagecount--;
		}
	}
	
	for (int i = 0; i < 20; i++) {
		if (life == true) {
			BHR[i].x += BHR[i].v * 0.8;
		}
		else {}
	}
	for (int i = 0; i < 20; i++) {
		if (life == true) {
			BHL[i].x += BHL[i].v * 0.8;
		}
		else {}
	}
	for (int i = 0; i < 20; i++) {
		if (life == true) {
			BHUR[i].x += BHUR[i].v * 0.8;
			BHUR[i].y += BHUR[i].vy * 0.4;
		}
		else {}
	}
	for (int i = 0; i < 20; i++) {
		if (life == true) {
			BHUL[i].x += BHUL[i].v * 0.8;
			BHUL[i].y += BHUL[i].vy * 0.4;
		}
		else {}
	}
	for (int i = 0; i < 20; i++) {
		if (life == true) {
			BHDR[i].x += BHDR[i].v * 0.8;
			BHDR[i].y += BHDR[i].vy * 0.4;
		}
		else {}
	}
	for (int i = 0; i < 20; i++) {
		if (life == true) {
			BHDL[i].x += BHDL[i].v * 0.8;
			BHDL[i].y += BHDL[i].vy * 0.4;
		}
		else {}
	}
	for (int i = 0; i < 20; i++) {
		if (life == true) {
			MS[i].x += 10;
		}
	}

	if (ver == 7 || 8) {
		if (y < 0) {
			y = 0;
		}
		if (y + jHeight > 600) {
			y = 600 - jHeight;
		}
	}

	//特別な移動
	if (stage == 12) {
		if (x > 6425) {
			vy = -5;
		}
	}

	if ((stage == 18) && (x > 6350)) {
		vy = -3;
	}

	if (stage == 21) {
		if (x > 6300) {
			vy = -5;
		}
	}


	vx = 0;


	for (int i = 0; i < 20; i++) {
		if (B3[i].flag == true && (((x > B3[i].x && x < B3[i].x + b3.width) || (x + jWidth > B3[i].x && x + jWidth < B3[i].x + b3.width)) && ((y > B3[i].y && y < B3[i].y + b3.height) || (y + jHeight > B3[i].y && y + jHeight < B3[i].y + b3.height)))) {
			B3[i].x = 0 - scrolX;
			batterycount += 2;
			Music.Play(M_GET);
		}
	}
	for (int i = 0; i < 20; i++) {
		if (M[i].flag == true && (((x > M[i].x && x < M[i].x + m.width) || (x + jWidth > M[i].x && x + jWidth < M[i].x + m.width)) && ((y > M[i].y && y < M[i].y + m.height) || (y + jHeight > M[i].y && y + jHeight < M[i].y + m.height)))) {
			M[i].x = 0 - scrolX;
			if (missilecount < 16) {
				missilecount += 2;
			}
			Music.Play(M_GET);
		}
	}
	for (int i = 0; i < 50; i++) {
		if (O[i].flag == true && (((x > O[i].x && x < O[i].x + o.width) || (x + jWidth > O[i].x && x + jWidth < O[i].x + o.width)) && ((y > O[i].y && y < O[i].y + o.height) || (y + jHeight > O[i].y && y + jHeight < O[i].y + o.height)))) {
			if (limit < 498) {
				limit += 3;
			}
		}
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if ((MS[i].flag == true) && (BHU[j].flag == true) && (((MS[i].x > BHU[j].x && MS[i].x < BHU[j].x + bhu.width) || (MS[i].x + ms.width > BHU[j].x && MS[i].x + ms.width < BHU[j].x + bhu.width)) && ((MS[i].y > BHU[j].y && MS[i].y < BHU[j].y + bhu.height) || (MS[i].y + ms.height > BHU[j].y && MS[i].y + ms.height < BHU[j].y + bhu.height)))) {
				bosslife -= 300;
				MS[i].flag = false;
				BHU[j].damagecount = 20;
				Music.Play(M_DAMAGE);
			}
		}
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if ((MS[i].flag == true) && (BHD[j].flag == true) && (((MS[i].x > BHD[j].x && MS[i].x < BHD[j].x + bhd.width) || (MS[i].x + ms.width > BHD[j].x && MS[i].x + ms.width < BHD[j].x + bhd.width)) && ((MS[i].y > BHD[j].y && MS[i].y < BHD[j].y + bhd.height) || (MS[i].y + ms.height > BHD[j].y && MS[i].y + ms.height < BHD[j].y + bhd.height)))) {
				bosslife -= 300;
				MS[i].flag = false;
				BHD[j].damagecount = 20;
				Music.Play(M_DAMAGE);
			}
		}
	}

	//ゲームオーバー
	if (invincible == false) {
		if (ver == 5) {
			if (limit == 0) {
				life = false;
				Music.Delete(M_VER);
			}
		}
		if (kb.flag == true) {
			if ((x > kb.x) && (x < kb.x + kb.width)) {
				life = false;
				Music.Delete(M_VER);
			}
		}

		if ((ver != 100) && (ver != 101) && (ver != 102) && (ver != 103) && (ver != 104)) {
			if ((ver != 8 && x + jWidth < 6400) || (ver == 8)) {
				if (x + jWidth < scrolX) {
					life = false;
					Music.Delete(M_VER);
				}
				if ((ver != 7) && (ver != 8)) {
					if (Yflag == false) {
						if (y >= 600 - jHeight) {
							if (x < 6400) {
								life = false;
								Music.Delete(M_VER);
							}
						}
					}
					else {}
				}

				if (ver == 6) {
					if (y + jHeight > fy + 15) {
						life = false;
						Music.Delete(M_VER);
					}
				}




				for (int i = 0; i < 10; i++) {
					if (BBH[i].damage == false) {
						if (BBH[i].flag == true && (((x > BBH[i].x + 5 && x < BBH[i].x + bbh.width) || (x + jWidth > BBH[i].x + 5 && x + jWidth < BBH[i].x + bbh.width)) && ((y > BBH[i].y + 15 && y < BBH[i].y + bbh.height) || (y + jHeight > BBH[i].y + 15 && y + jHeight < BBH[i].y + bbh.height)))) {
							life = false;
							Music.Delete(M_VER);
						}
					}
				}

				for (int i = 0; i < 50; i++) {
					if (RU[i].flag == true && (((x > RU[i].x + 5 && x < RU[i].x + ru.width) || (x + jWidth > RU[i].x + 5 && x + jWidth < RU[i].x + ru.width)) && ((y > RU[i].y + 3 && y < RU[i].y + ru.height) || (y + jHeight > RU[i].y + 3 && y + jHeight < RU[i].y + ru.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}
				for (int i = 0; i < 50; i++) {
					if (LU[i].flag == true && (((x > LU[i].x + 5 && x < LU[i].x + lu.width) || (x + jWidth > LU[i].x + 5 && x + jWidth < LU[i].x + lu.width)) && ((y > LU[i].y + 3 && y < LU[i].y + lu.height) || (y + jHeight > LU[i].y + 3 && y + jHeight < LU[i].y + lu.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}
				for (int i = 0; i < 50; i++) {
					if (UU[i].flag == true && (((x > UU[i].x + 5 && x < UU[i].x + uu.width) || (x + jWidth > UU[i].x + 5 && x + jWidth < UU[i].x + uu.width)) && ((y > UU[i].y + 3 && y < UU[i].y + uu.height) || (y + jHeight > UU[i].y + 3 && y + jHeight < UU[i].y + uu.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}
				for (int i = 0; i < 50; i++) {
					if (DU[i].flag == true && (((x > DU[i].x + 5 && x < DU[i].x + du.width) || (x + jWidth > DU[i].x + 5 && x + jWidth < DU[i].x + du.width)) && ((y > DU[i].y + 3 && y < DU[i].y + du.height) || (y + jHeight > DU[i].y + 3 && y + jHeight < DU[i].y + du.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}
				for (int i = 0; i < 50; i++) {
					if (RUU[i].flag == true && (((x > RUU[i].x + 5 && x < RUU[i].x + ruu.width) || (x + jWidth > RUU[i].x + 5 && x + jWidth < RUU[i].x + ruu.width)) && ((y > RUU[i].y + 3 && y < RUU[i].y + ruu.height) || (y + jHeight > RUU[i].y + 3 && y + jHeight < RUU[i].y + ruu.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}
				for (int i = 0; i < 50; i++) {
					if (RDU[i].flag == true && (((x > RDU[i].x + 5 && x < RDU[i].x + rdu.width) || (x + jWidth > RDU[i].x + 5 && x + jWidth < RDU[i].x + rdu.width)) && ((y > RDU[i].y + 3 && y < RDU[i].y + rdu.height) || (y + jHeight > RDU[i].y + 3 && y + jHeight < RDU[i].y + rdu.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}

				for (int i = 0; i < 20; i++) {
					if (K[i].flag == true && (((x > K[i].x && x < K[i].x + k.width) || (x + jWidth > K[i].x && x + jWidth < K[i].x + k.width)) && ((y > K[i].y && y < K[i].y + k.height) || (y + jHeight > K[i].y && y + jHeight < K[i].y + k.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}
				for (int i = 0; i < 20; i++) {
					if (S2[i].flag == true && (((x > S2[i].x + 5 && x < S2[i].x + s2.width) || (x + jWidth > S2[i].x + 5 && x + jWidth < S2[i].x + s2.width)) && ((y > S2[i].y + 20 && y < S2[i].y + s2.height) || (y + jHeight > S2[i].y + 20 && y + jHeight < S2[i].y + s2.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}
				for (int i = 0; i < 20; i++) {
					if (E[i].flag == true && (((x > E[i].x + 15 && x < E[i].x + e.width) || (x + jWidth > E[i].x + 15 && x + jWidth < E[i].x + e.width)) && ((y > E[i].y + 5 && y < E[i].y + e.height) || (y + jHeight > E[i].y + 5 && y + jHeight < E[i].y + e.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}

				for (int i = 0; i < 20; i++) {
					if (F2[i].flag == true && (((x > F2[i].x + 5 && x < F2[i].x + f2.width) || (x + jWidth > F2[i].x + 5 && x + jWidth < F2[i].x + f2.width)) && ((y > F2[i].y + 4 && y < F2[i].y + f2.height) || (y + jHeight > F2[i].y + 4 && y + jHeight < F2[i].y + f2.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}

				for (int i = 0; i < 20; i++) {
					if (B2[i].flag == true && (((x > B2[i].x + 5 && x < B2[i].x + b2.width) || (x + jWidth > B2[i].x + 5 && x + jWidth < B2[i].x + b2.width)) && ((y > B2[i].y + 5 + 40 && y < B2[i].y + b2.height + 40) || (y + jHeight > B2[i].y + 5 + 40 && y + jHeight < B2[i].y + b2.height + 40)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}

				for (int i = 0; i < 20; i++) {
					if (B[i].flag == true && (((x > B[i].x + 5 && x < B[i].x + b.width) || (x + jWidth > B[i].x + 5 && x + jWidth < B[i].x + b.width)) && ((y > B[i].y + 5 && y < B[i].y + b.height) || (y + jHeight > B[i].y + 5 && y + jHeight < B[i].y + b.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}


				for (int i = 0; i < 20; i++) {
					if (F[i].flag == true && (((x > F[i].x && x < F[i].x + f.width) || (x + jWidth > F[i].x && x + jWidth < F[i].x + f.width)) && ((y > F[i].y && y < F[i].y + f.height) || (y + jHeight > F[i].y && y + jHeight < F[i].y + f.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}

				for (int i = 0; i < 50; i++) {
					if (T[i].flag == true && (((x > T[i].x && x < T[i].x + t.width) || (x + jWidth > T[i].x && x + jWidth < T[i].x + t.width)) && ((y > T[i].y && y < T[i].y + t.height) || (y + jHeight > T[i].y && y + jHeight < T[i].y + t.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}

				for (int i = 0; i < 50; i++) {
					if (GF[i].flag == true && (((x > GF[i].x + 3 && x < GF[i].x + gf.width) || (x + jWidth > GF[i].x + 3 && x + jWidth < GF[i].x + gf.width)) && ((y > GF[i].y && y < GF[i].y + gf.height) || (y + jHeight > GF[i].y && y + jHeight < GF[i].y + gf.height)))) {
						life = false;
						Music.Delete(M_VER);

					}
				}

				for (int i = 0; i < 50; i++) {
					if (F3[i].flag == true && (((x > F3[i].x + 5 && x < F3[i].x + f3.width) || (x + jWidth > F3[i].x + 5 && x + jWidth < F3[i].x + f3.width)) && ((y > F3[i].y + 5 && y < F3[i].y + f3.height) || (y + jHeight > F3[i].y + 5 && y + jHeight < F3[i].y + f3.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}

				for (int i = 0; i < 50; i++) {
					if (U2[i].flag == true && (((x > U2[i].x + 5 && x < U2[i].x + u2.width) || (x + jWidth > U2[i].x + 5 && x + jWidth < U2[i].x + u2.width)) && ((y > U2[i].y + 5 && y < U2[i].y + u2.height) || (y + jHeight > U2[i].y + 5&& y + jHeight < U2[i].y + u2.height)))) {
						life = false;
						Music.Delete(M_VER);

					}
				}

				for (int i = 0; i < 100; i++) {
					if (S[i].flag == true && (((x > S[i].x + 10 && x < S[i].x + s.width) || (x + jWidth > S[i].x + 10 && x + jWidth < S[i].x + s.width)) && ((y >= S[i].y + 10 && y <= S[i].y + s.height) || (y + jHeight >= S[i].y + 10 && y + jHeight <= S[i].y + s.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}

				for (int i = 0; i < 50; i++) {
					if (U[i].flag == true && (((x > U[i].x && x < U[i].x + u.width) || (x + jWidth > U[i].x && x + jWidth < U[i].x + u.width)) && ((y > U[i].y && y < U[i].y + u.height) || (y + jHeight > U[i].y && y + jHeight < U[i].y + u.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}
				for (int i = 0; i < 20; i++) {
					if (BO1[i].flag == true && (((x > BO1[i].x + 3 && x < BO1[i].x + bo1.width) || (x + jWidth > BO1[i].x + 3 && x + jWidth < BO1[i].x + bo1.width)) && ((y > BO1[i].y + 5 && y < BO1[i].y + bo1.height) || (y + jHeight > BO1[i].y + 5 && y + jHeight < BO1[i].y + bo1.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}
				for (int i = 0; i < 20; i++) {
					if (DB[i].flag == true && (((x > DB[i].x && x < DB[i].x + db.width) || (x + jWidth > DB[i].x && x + jWidth < DB[i].x + db.width)) && ((y > DB[i].y && y < DB[i].y + db.height) || (y + jHeight > DB[i].y && y + jHeight < DB[i].y + db.height)))) {
						life = false;
						Music.Delete(M_VER); 
					}
				}
				for (int i = 0; i < 50; i++) {
					if (C[i].flag == true && (((x > C[i].x && x < C[i].x + c.width) || (x + jWidth > C[i].x && x + jWidth < C[i].x + c.width)) && ((y > C[i].y + 10 && y < C[i].y + c.height) || (y + jHeight > C[i].y + 10 && y + jHeight < C[i].y + c.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}
				for (int i = 0; i < 50; i++) {
					if (CL[i].flag == true && (((x > CL[i].x + 5 && x < CL[i].x + cl.width) || (x + jWidth > CL[i].x + 5 && x + jWidth < CL[i].x + cl.width)) && ((y > CL[i].y + 5 && y < CL[i].y + cl.height) || (y + jHeight > CL[i].y + 5 && y + jHeight < CL[i].y + cl.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}
				for (int i = 0; i < 50; i++) {
					if (CR[i].flag == true && (((x > CR[i].x && x < CR[i].x + cr.width) || (x + jWidth > CR[i].x && x + jWidth < CR[i].x + cr.width)) && ((y > CR[i].y + 5 && y < CR[i].y + cr.height) || (y + jHeight > CR[i].y + 5 && y + jHeight < CR[i].y + cr.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}
				for (int i = 0; i < 20; i++) {
					if (BHU[i].flag == true && (((x > BHU[i].x + 5 && x < BHU[i].x + bhu.width) || (x + jWidth > BHU[i].x + 5 && x + jWidth < BHU[i].x + bhu.width)) && ((y > BHU[i].y + 20 && y < BHU[i].y + bhu.height) || (y + jHeight > BHU[i].y + 20 && y + jHeight < BHU[i].y + bhu.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}
				for (int i = 0; i < 20; i++) {
					if (BHD[i].flag == true && (((x > BHD[i].x + 5 && x < BHD[i].x + bhd.width) || (x + jWidth > BHD[i].x + 5 && x + jWidth < BHD[i].x + bhd.width)) && ((y > BHD[i].y + 20 && y < BHD[i].y + bhd.height) || (y + jHeight > BHD[i].y + 20 && y + jHeight < BHD[i].y + bhd.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}
				for (int i = 0; i < 20; i++) {
					if (BHR[i].flag == true && (((x > BHR[i].x + 10 && x < BHR[i].x + bhr.width) || (x + jWidth > BHR[i].x + 10 && x + jWidth < BHR[i].x + bhr.width)) && ((y > BHR[i].y + 10 && y < BHR[i].y + bhr.height) || (y + jHeight > BHR[i].y + 10 && y + jHeight < BHR[i].y + bhr.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}
				for (int i = 0; i < 20; i++) {
					if (BHL[i].flag == true && (((x > BHL[i].x + 10 && x < BHL[i].x + bhl.width) || (x + jWidth > BHL[i].x + 10 && x + jWidth < BHL[i].x + bhl.width)) && ((y > BHL[i].y + 10 && y < BHL[i].y + bhl.height) || (y + jHeight > BHL[i].y + 10 && y + jHeight < BHL[i].y + bhl.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}
				for (int i = 0; i < 20; i++) {
					if (BHUR[i].flag == true && (((x > BHUR[i].x + 10 && x < BHUR[i].x + bhur.width) || (x + jWidth > BHUR[i].x + 10 && x + jWidth < BHUR[i].x + bhur.width)) && ((y > BHUR[i].y + 10 && y < BHUR[i].y + bhur.height) || (y + jHeight > BHUR[i].y + 10 && y + jHeight < BHUR[i].y + bhur.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}
				for (int i = 0; i < 20; i++) {
					if (BHUL[i].flag == true && (((x > BHUL[i].x + 10 && x < BHUL[i].x + bhul.width) || (x + jWidth > BHUL[i].x + 10 && x + jWidth < BHUL[i].x + bhul.width)) && ((y > BHUL[i].y + 10 && y < BHUL[i].y + bhul.height) || (y + jHeight > BHUL[i].y + 10 && y + jHeight < BHUL[i].y + bhul.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}
				for (int i = 0; i < 20; i++) {
					if (BHDR[i].flag == true && (((x > BHDR[i].x + 10 && x < BHDR[i].x + bhdr.width) || (x + jWidth > BHDR[i].x + 10 && x + jWidth < BHDR[i].x + bhdr.width)) && ((y > BHDR[i].y + 10 && y < BHDR[i].y + bhdr.height) || (y + jHeight > BHDR[i].y + 10 && y + jHeight < BHDR[i].y + bhdr.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}
				for (int i = 0; i < 20; i++) {
					if (BHDL[i].flag == true && (((x > BHDL[i].x + 10 && x < BHDL[i].x + bhdl.width) || (x + jWidth > BHDL[i].x + 10 && x + jWidth < BHDL[i].x + bhdl.width)) && ((y > BHDL[i].y + 10 && y < BHDL[i].y + bhdl.height) || (y + jHeight > BHDL[i].y + 10 && y + jHeight < BHDL[i].y + bhdl.height)))) {
						life = false;
						Music.Delete(M_VER);
					}
				}
			}
		}
	}

		if (life == true) {
			if ((stage != 23 && x + jWidth < 6400) || (stage == 23)) {
				if ((ver == 7) || (ver == 8)) {
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
						Music.Play(M_JUMP);
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
						Music.Play(M_JUMP);
					}
				}
			}
		}
		else
		{
			if (Input.GetKeyEnter(Input.key.SPACE)) {
				Game.FlipScene(new CSTitle(), Flip::CROSS_FADE, 10);
				Music.Play(M_SELECT);
			}
			if (Input.GetKeyEnter(Input.key.NUMPADENTER)) {
				life = true;
				Music.Play(M_SELECT);
				Game.FlipScene(new CSGame(stage), Flip::CROSS_FADE, 30);
			}
		}


		if (autoMove) {
			if (life == true) {
				if (stage == 22 && x > 6400) {}
				else {
					vx = 5;
				}
				if (Yflag == false) {
					if ((stage != 24) && (stage != 23)) {
						if (x + jWidth + d < 6400) {
							scrolX += 5;
						}
					}
					else if (stage == 24){
							if (x + jWidth + d < 4600) {
								scrolX += 5;
							}
					}
					else if (stage == 23) {
						if (x + jWidth + d < 7600) {
							scrolX += 5;
						}
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

		/*if ((stage == 22) || (stage == 23)) {
			if (life == true) {
				if (Input.GetKeyDown(Input.key.RIGHT)) {
					vx += 5;
					if (jturn == true) {
						jturn = false;
					}
				}
				if (Input.GetKeyDown(Input.key.LEFT)) {
					vx -= 5;
					if (jturn == false) {
						jturn = true;
					}
				}
			}
		}*/


		/*if (x + jWidth > 6400) {
			vx = 5;
		}*/
		if (x + jWidth == 6800) {
			if ((stage != 100) && (stage != 101) && (stage != 102) && (stage != 103) && (stage != 104) && (stage != 22) && (stage != 23)) {
				Game.FlipScene(new CSComplete(stage), Flip::CROSS_FADE, 8);
				Music.Delete(M_VER);
				Music.Play(M_COMPLETE);
			}
			else if (stage == 23) {}
		}
		if (stage == 22 && x + jWidth == 6400) {
			Game.FlipScene(new CSGame(104), Flip::CROSS_FADE, 8);
			Music.Delete(M_VER);
		}
			
		if (stage == 23) {
			if (bosslife <= 0) {
				Game.FlipScene(new CSComplete(stage), Flip::CROSS_FADE, 8);
				Music.Play(M_COMPLETE);
				Music.Delete(M_VER);
			}
		}
		if (stage == 24) {
			if (x + jWidth == 5000) {
				Game.FlipScene(new CSTitle(), Flip::CROSS_FADE, 8);
				Music.Delete(M_VER);
			}
		}

		if ((stage != 100) && (stage != 101) && (stage != 102) && (stage != 103) && (stage != 104)) {
			for (int i = x / 40, endI = (x + 50) / 40, endJ = (y + 30) / 40; i <= endI; ++i) {
				for (int j = y / 40; j <= endJ; ++j) {
					if (mce.Get(mce.layer.A, i, j) != 0) {
						HitBlock(i, j);
					}
				}
			}
		}


		for (int i = 0; i < 50; i++) {
			if (RU[i].x + RU[i].width < scrolX) {
				RU[i].flag = false;
			}
		}
		for (int i = 0; i < 50; i++) {
			if (LU[i].x + LU[i].width < scrolX) {
				LU[i].flag = false;
			}
		}
		for (int i = 0; i < 50; i++) {
			if (UU[i].x + UU[i].width < scrolX) {
				UU[i].flag = false;
			}
		}
		for (int i = 0; i < 50; i++) {
			if (DU[i].x + DU[i].width < scrolX) {
				DU[i].flag = false;
			}
		}
		for (int i = 0; i < 50; i++) {
			if (RUU[i].x + RUU[i].width < scrolX) {
				RUU[i].flag = false;
			}
		}
		for (int i = 0; i < 50; i++) {
			if (RDU[i].x + RDU[i].width < scrolX) {
				RDU[i].flag = false;
			}
		}

		for (int i = 0; i < 20; i++) {
			if (K[i].x + K[i].width < scrolX) {
				K[i].flag = false;
			}
		}

		for (int i = 0; i < 50; i++) {
			if (O[i].x + o.width < scrolX) {
				O[i].flag = false;
			}
		}

		for (int i = 0; i < 20; i++) {
			if (B3[i].x + B3[i].width < scrolX) {
				B3[i].flag = false;
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

		for (int i = 0; i < 100; i++) {
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
		for (int i = 0; i < 20; i++) {
			if (BHU[i].x + BHU[i].width < scrolX) {
				BHU[i].flag = false;
			}
		}
		for (int i = 0; i < 20; i++) {
			if (BHD[i].x + BHD[i].width < scrolX) {
				BHD[i].flag = false;
			}
		}
		for (int i = 0; i < 20; i++) {
			if (BHR[i].x + BHR[i].width > 800 + scrolX) {
				BHR[i].flag = false;
				BHR[i].v = 0;
			}
		}
		for (int i = 0; i < 20; i++) {
			if (BHL[i].x + BHL[i].width < scrolX) {
				BHL[i].flag = false;
				BHL[i].v = 0;
			}
		}
		for (int i = 0; i < 20; i++) {
			if (BHUR[i].x + BHUR[i].width > 800 + scrolX) {
				BHUR[i].flag = false;
				BHUR[i].v = 0;
				BHUR[i].vy = 0;
			}
		}
		for (int i = 0; i < 20; i++) {
			if (BHUL[i].x + BHUL[i].width < scrolX) {
				BHUL[i].flag = false;
				BHUL[i].v = 0;
				BHUL[i].vy = 0;
			}
		}
		for (int i = 0; i < 20; i++) {
			if (BHDR[i].x + BHDR[i].width > 800 + scrolX) {
				BHDR[i].flag = false;
				BHDR[i].v = 0;
				BHDR[i].vy = 0;
			}
		}
		for (int i = 0; i < 20; i++) {
			if (BHDL[i].x + BHDL[i].width < scrolX) {
				BHDL[i].flag = false;
				BHDL[i].v = 0;
				BHDL[i].vy = 0;
			}
		}
		for (int i = 0; i < 20; i++) {
			if (M[i].x + M[i].width < scrolX) {
				M[i].flag = false;
			}
		}
		for (int i = 0; i < 20; i++) {
			if (MS[i].x + MS[i].width > 800 + scrolX) {
				MS[i].flag = false;
			}
		}


		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.B, i, j) == 10 && i * 40 - scrolX <= 0 && i * 40 - scrolX >= 0 - 2) {
					for (int I = 0; I < 50; I++) {
						if (RU[I].flag == false) {
							RU[I].x = i * 40;
							RU[I].y = j * 40;
							RU[I].flag = true;
							break;
						}
					}
				}
			}
		}
		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.B, i, j) == 11 && i * 40 - scrolX >= 1200 && i * 40 - scrolX <= 1200 + 2) {
					for (int I = 0; I < 50; I++) {
						if (LU[I].flag == false) {
							LU[I].x = i * 40;
							LU[I].y = j * 40;
							LU[I].flag = true;
							break;
						}
					}
				}
			}
		}
		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.B, i, j) == 12 && i * 40 - scrolX >= 800 && i * 40 - scrolX <= 800 + 2) {
					for (int I = 0; I < 50; I++) {
						if (UU[I].flag == false) {
							UU[I].x = i * 40;
							UU[I].y = j * 40;
							UU[I].flag = true;
							break;
						}
					}
				}
			}
		}
		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.B, i, j) == 13 && i * 40 - scrolX >= 800 && i * 40 - scrolX <= 800 + 2) {
					for (int I = 0; I < 50; I++) {
						if (DU[I].flag == false) {
							DU[I].x = i * 40;
							DU[I].y = j * 40;
							DU[I].flag = true;
							break;
						}
					}
				}
			}
		}
		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.B, i, j) == 14 && i * 40 - scrolX <= 0 && i * 40 - scrolX >= 0 - 2) {
					for (int I = 0; I < 50; I++) {
						if (RUU[I].flag == false) {
							RUU[I].x = i * 40;
							RUU[I].y = j * 40;
							RUU[I].flag = true;
							break;
						}
					}
				}
			}
		}
		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.B, i, j) == 15 && i * 40 - scrolX <= 0 && i * 40 - scrolX >= 0 - 2) {
					for (int I = 0; I < 50; I++) {
						if (RDU[I].flag == false) {
							RDU[I].x = i * 40;
							RDU[I].y = j * 40;
							RDU[I].flag = true;
							break;
						}
					}
				}
			}
		}
		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.B, i, j) == 1 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 2 - d) {
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
				if (mce.Get(mce.layer.C, i, j) == 8 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 2 - d) {
					for (int I = 0; I < 20; I++) {
						if (B3[I].flag == false) {
							B3[I].x = i * 40;
							B3[I].y = j * 40 - 20;
							B3[I].flag = true;
							B3[I].get = false;
							break;
						}
					}
				}
			}
		}

		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.C, i, j) == 9 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 2 - d) {
					for (int I = 0; I < 50; I++) {
						if (O[I].flag == false) {
							O[I].x = i * 40;
							O[I].y = j * 40;
							O[I].flag = true;
							break;
						}
					}
				}
			}
		}

		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.B, i, j) == 6 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 2 - d) {
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
				if (mce.Get(mce.layer.B, i, j) == 8 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 2 - d) {
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
				if (mce.Get(mce.layer.B, i, j) == 2 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 2 - d) {
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
				if (mce.Get(mce.layer.B, i, j) == 4 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 2 - d) {
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
				if (mce.Get(mce.layer.B, i, j) == 3 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 2 - d) {
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
				if (mce.Get(mce.layer.C, i, j) == 6 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 2 - d) {
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
				if (mce.Get(mce.layer.C, i, j) == 2 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 2 - d) {
					for (int I = 0; I < 100; I++) {
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
				if (mce.Get(mce.layer.C, i, j) == 3 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 2 - d) {
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
				if (mce.Get(mce.layer.C, i, j) == 4 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 2 - d) {
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
				if (mce.Get(mce.layer.C, i, j) == 5 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 2 - d) {
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
				if (mce.Get(mce.layer.B, i, j) == 7 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 2 - d) {
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
				if (mce.Get(mce.layer.B, i, j) == 5 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 2 - d) {
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
				if (mce.Get(mce.layer.C, i, j) == 7 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 2 - d) {
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
				if (mce.Get(mce.layer.B, i, j) == 9 && i * 40 - scrolX >= 1200 - d && i * 40 - scrolX <= 1200 + 2 - d) {
					for (int I = 0; I < 10; I++) {
						if (BBH[I].flag == false) {
							BBH[I].x = i * 40;
							BBH[I].y = 600;
							BBH[I].flag = true;
							BBH[I].damage = false;
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
			if ((Lflag == true) && (lx + 150 > BBH[i].x)) {
				BBH[i].damage = true;
			}
			if ((BBH[i].x > lx) && (BBH[i].x < lx + 150) && (Lflag == true)) {
				bossbonedamagecount = 40;
			}
		}
		if ((bossbonedamagecount <= 35) && (bossbonedamagecount >= 35)) {
			bossbonelife -= 1;
		}
		
		if ((ver == 4) && (x == 6300) && (bossbonelife > 0)) {
			kb.flag = true;
			kb.x =scrolX - kb.width;
		}

		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.B, i, j) == 22 && i * 40 - scrolX >= 800 && i * 40 - scrolX <= 800 + 2) {
					for (int I = 0; I < 20; I++) {
						if (BHU[I].flag == false) {
							BHU[I].x = i * 40;
							BHU[I].y = j * 40;
							BHU[I].flag = true;
							break;
						}
					}
				}
			}
		}
		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.B, i, j) == 23 && i * 40 - scrolX >= 800 && i * 40 - scrolX <= 800 + 2) {
					for (int I = 0; I < 20; I++) {
						if (BHD[I].flag == false) {
							BHD[I].x = i * 40;
							BHD[I].y = j * 40 - 800;
							BHD[I].flag = true;
							break;
						}
					}
				}
			}
		}
		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.B, i, j) == 16 && i * 40 - scrolX <= 0 && i * 40 - scrolX >= 0 - 2) {
					for (int I = 0; I < 20; I++) {
						if (BHR[I].flag == false) {
							BHR[I].x = i * 40;
							BHR[I].y = j * 40;
							BHR[I].flag = true;
							break;
						}
					}
				}
			}
		}
		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.B, i, j) == 17 && i * 40 - scrolX >= 800 && i * 40 - scrolX <= 800 + 2) {
					for (int I = 0; I < 20; I++) {
						if (BHL[I].flag == false) {
							BHL[I].x = i * 40;
							BHL[I].y = j * 40;
							BHL[I].flag = true;
							break;
						}
					}
				}
			}
		}
		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.B, i, j) == 18 && i * 40 - scrolX <= 0 && i * 40 - scrolX >= 0 - 2) {
					for (int I = 0; I < 20; I++) {
						if (BHUR[I].flag == false) {
							BHUR[I].x = i * 40;
							BHUR[I].y = j * 40;
							BHUR[I].flag = true;
							break;
						}
					}
				}
			}
		}
		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.B, i, j) == 19 && i * 40 - scrolX >= 800 && i * 40 - scrolX <= 800 + 2) {
					for (int I = 0; I < 20; I++) {
						if (BHUL[I].flag == false) {
							BHUL[I].x = i * 40;
							BHUL[I].y = j * 40;
							BHUL[I].flag = true;
							break;
						}
					}
				}
			}
		}
		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.B, i, j) == 20 && i * 40 - scrolX <= 0 && i * 40 - scrolX >= 0 - 2) {
					for (int I = 0; I < 20; I++) {
						if (BHDR[I].flag == false) {
							BHDR[I].x = i * 40;
							BHDR[I].y = j * 40;
							BHDR[I].flag = true;
							break;
						}
					}
				}
			}
		}
		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.B, i, j) == 21 && i * 40 - scrolX >= 800 && i * 40 - scrolX <= 800 + 2) {
					for (int I = 0; I < 20; I++) {
						if (BHDL[I].flag == false) {
							BHDL[I].x = i * 40;
							BHDL[I].y = j * 40;
							BHDL[I].flag = true;
							break;
						}
					}
				}
			}
		}
		for (int i = 0; i < 20; i++) {
			if (BHR[i].flag == true) {
				BHR[i].v++;
			}
		}
		for (int i = 0; i < 20; i++) {
			if (BHL[i].flag == true) {
				BHL[i].v--;
			}
		}
		for (int i = 0; i < 20; i++) {
			if (BHUR[i].flag == true) {
				BHUR[i].v++;
				BHUR[i].vy--;
			}
		}
		for (int i = 0; i < 20; i++) {
			if (BHUL[i].flag == true) {
				BHUL[i].v--;
				BHUL[i].vy--;
			}
		}
		for (int i = 0; i < 20; i++) {
			if (BHDR[i].flag == true) {
				BHDR[i].v++;
				BHDR[i].vy++;
			}
		}
		for (int i = 0; i < 20; i++) {
			if (BHDL[i].flag == true) {
				BHDL[i].v--;
				BHDL[i].vy++;
			}
		}

		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.C, i, j) == 10 && i * 40 - scrolX >= 800 && i * 40 - scrolX <= 800 + 2) {
					for (int I = 0; I < 20; I++) {
						if (M[I].flag == false) {
							M[I].x = i * 40;
							M[I].y = j * 40;
							M[I].flag = true;
							break;
						}
					}
				}
			}
		}
	}




	void CSGame::Draw() {

		if ((ver == 0) || (ver == 100) || (ver == 101) || (ver == 102) || (ver == 103) || (ver == 104)) {
			background1(0, 0);
		}
		else if (ver == 8) {
			back8_1(0, 0, false, false);
			back8_2(0, 0, false, false);
		}
		else {
			background5(0 - scrolX * 0.2, 0);
			background4(0 - scrolX * 0.4, 0);
			background3(0 - scrolX * 0.6, 0);
			background2(0 - scrolX * 0.8, 0);
			background1(0 - scrolX, 0);
		}

		if (stage == 23) {
			boss(0, 0, false, false);
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
		for (int i = 0; i < mce.GetWidth(); i++) {
			for (int j = 0; j < mce.GetHeight(); j++) {
				if (mce.Get(mce.layer.A, i, j) == 19) {
					seven_eight_two(i * 40 - scrolX, j * 40 - scrolY);
				}
			}
		}
		if ((stage != 100) && (stage != 101) && (stage != 102) && (stage != 103) && (stage != 104)) {
			if ((stage == 12) && (x > 6425)) {
				player3(x - scrolX, y + 20 - scrolY);
			}
			else {
				if (jturn == false) {
					player(x - scrolX, y - scrolY, false, false);
				}
				else {
					turnplayer(x - scrolX, y - scrolY, false, false);
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
				if (mce.Get(mce.layer.A, i, j) == 19) {
					seven_eight_one(i * 40 - scrolX, j * 40 - scrolY);
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
			if (O[i].flag == true) {
				oasis(O[i].x - scrolX, O[i].y - scrolY, false, false);
			}
		}

		for (int i = 0; i < 50; i++) {
			if (T[i].flag == true) {
				trap(T[i].x - scrolX, T[i].y - scrolY, false, false);
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
					fireballback(F3[i].x - 40 - scrolX, F3[i].y - 40 - scrolY, false, false);
				}
				else {
					littlefire(F3[i].x - 20 - scrolX, F3[i].y - scrolY, false, false);
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
		for (int i = 0; i < 100; i++) {
			if (S[i].flag == true) {
				stone(S[i].x - scrolX, S[i].y - scrolY);
			}
		}
		for (int i = 0; i < 50; i++) {
			if (U[i].flag == true) {
				ufo(U[i].x - scrolX, U[i].y - scrolY, false, false);
			}
		}
		for (int i = 0; i < 50; i++) {
			if (RU[i].flag == true) {
				rufo(RU[i].x - scrolX, RU[i].y - scrolY);
			}
		}
		for (int i = 0; i < 50; i++) {
			if (LU[i].flag == true) {
				lufo(LU[i].x - scrolX, LU[i].y - scrolY);
			}
		}
		for (int i = 0; i < 50; i++) {
			if (UU[i].flag == true) {
				uufo(UU[i].x - scrolX, UU[i].y - scrolY);
			}
		}
		for (int i = 0; i < 50; i++) {
			if (DU[i].flag == true) {
				dufo(DU[i].x - scrolX, DU[i].y - scrolY);
			}
		}
		for (int i = 0; i < 50; i++) {
			if (RUU[i].flag == true) {
				ruufo(RUU[i].x - scrolX, RUU[i].y - scrolY);
			}
		}
		for (int i = 0; i < 50; i++) {
			if (RDU[i].flag == true) {
				rdufo(RDU[i].x - scrolX, RDU[i].y - scrolY);
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
			if (BBH[i].damage == false) {
				bossbonehand(BBH[i].x - scrolX, BBH[i].y - scrolY);
			}
			else {
				bossbonehanddamage(BBH[i].x - scrolX, BBH[i].y - scrolY, false, false);
			}
		}

		for (int i = 0; i < 20; i++) {
			if (BHU[i].flag == true) {
				bosshandU(BHU[i].x - scrolX, BHU[i].y, false);
				if (BHU[i].damagecount > 0) {
					bosshandUdamage(BHU[i].x - scrolX, BHU[i].y, false);
				}
			}
		}
		for (int i = 0; i < 20; i++) {
			if (BHD[i].flag == true) {
				bosshandD(BHD[i].x - scrolX, BHD[i].y, false);
				if (BHD[i].damagecount > 0) {
					bosshandDdamage(BHD[i].x - scrolX, BHD[i].y, false);
				}
			}
		}
		for (int i = 0; i < 20; i++) {
			if (BHR[i].flag == true) {
				bosshandshadow1(BHR[i].x - scrolX - 100, BHR[i].y, false);
				bosshandshadow2(BHR[i].x - scrolX - 80, BHR[i].y, false);
				bosshandshadow3(BHR[i].x - scrolX - 60, BHR[i].y, false);
				bosshandshadow4(BHR[i].x - scrolX - 40, BHR[i].y, false);
				bosshandshadow5(BHR[i].x - scrolX - 20, BHR[i].y, false);
				bosshandR(BHR[i].x - scrolX, BHR[i].y, false);
			}
		}
		for (int i = 0; i < 20; i++) {
			if (BHL[i].flag == true) {
				bosshandshadow1(BHL[i].x - scrolX + 100, BHL[i].y, false);
				bosshandshadow2(BHL[i].x - scrolX + 80, BHL[i].y, false);
				bosshandshadow3(BHL[i].x - scrolX + 60, BHL[i].y, false);
				bosshandshadow4(BHL[i].x - scrolX + 40, BHL[i].y, false);
				bosshandshadow5(BHL[i].x - scrolX + 20, BHL[i].y, false);
				bosshandL(BHL[i].x - scrolX, BHL[i].y, false);
			}
		}
		for (int i = 0; i < 20; i++) {
			if (BHUR[i].flag == true) {
				bosshandshadow1(BHUR[i].x - scrolX - 100, BHUR[i].y + 50, false);
				bosshandshadow2(BHUR[i].x - scrolX - 80, BHUR[i].y + 40, false);
				bosshandshadow3(BHUR[i].x - scrolX - 60, BHUR[i].y + 30, false);
				bosshandshadow4(BHUR[i].x - scrolX - 40, BHUR[i].y + 20, false);
				bosshandshadow5(BHUR[i].x - scrolX - 20, BHUR[i].y + 10, false);
				bosshandUR(BHUR[i].x - scrolX, BHUR[i].y, false);
			}
		}
		for (int i = 0; i < 20; i++) {
			if (BHUL[i].flag == true) {
				bosshandshadow1(BHUL[i].x - scrolX + 100, BHUL[i].y + 50, false);
				bosshandshadow2(BHUL[i].x - scrolX + 80, BHUL[i].y + 40, false);
				bosshandshadow3(BHUL[i].x - scrolX + 60, BHUL[i].y + 30, false);
				bosshandshadow4(BHUL[i].x - scrolX + 40, BHUL[i].y + 20, false);
				bosshandshadow5(BHUL[i].x - scrolX + 20, BHUL[i].y + 10, false);
				bosshandUL(BHUL[i].x - scrolX, BHUL[i].y, false);
			}
		}
		for (int i = 0; i < 20; i++) {
			if (BHDR[i].flag == true) {
				bosshandshadow1(BHDR[i].x - scrolX - 100, BHDR[i].y - 50, false);
				bosshandshadow2(BHDR[i].x - scrolX - 80, BHDR[i].y - 40, false);
				bosshandshadow3(BHDR[i].x - scrolX - 60, BHDR[i].y - 30, false);
				bosshandshadow4(BHDR[i].x - scrolX - 40, BHDR[i].y - 20, false);
				bosshandshadow5(BHDR[i].x - scrolX - 20, BHDR[i].y - 10, false);
				bosshandDR(BHDR[i].x - scrolX, BHDR[i].y, false);
			}
		}
		for (int i = 0; i < 20; i++) {
			if (BHDL[i].flag == true) {
				bosshandshadow1(BHDL[i].x - scrolX + 100, BHDL[i].y - 50, false);
				bosshandshadow2(BHDL[i].x - scrolX + 80, BHDL[i].y - 40, false);
				bosshandshadow3(BHDL[i].x - scrolX + 60, BHDL[i].y - 30, false);
				bosshandshadow4(BHDL[i].x - scrolX + 40, BHDL[i].y - 20, false);
				bosshandshadow5(BHDL[i].x - scrolX + 20, BHDL[i].y - 10, false);
				bosshandDL(BHDL[i].x - scrolX, BHDL[i].y, false);
			}
		}

	for (int i = 0; i < 20; i++) {
		if (B3[i].get == false) {
			battery(B3[i].x - scrolX, B3[i].y - scrolY);
		}
	}
	for (int i = 0; i < 20; i++) {
		if (M[i].flag == true) {
			missile(M[i].x - scrolX, M[i].y - scrolY);
		}
	}
	for (int i = 0; i < 20; i++) {
		if (MS[i].flag == true) {
			missileshot(MS[i].x - scrolX, MS[i].y - scrolY);
		}
	}

	if (ver == 4) {
			if (bossbonedamagecount > 0) {
				bossbonedamage(bb.x - scrolX, 0, false, false);
			}
			else {
				bossbone(bb.x - scrolX, 0, false, false);
			}
	}
	if (kb.flag == true) {
		killbone(kb.x - scrolX, kb.y - scrolY);
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

	if (ver == 5) {
		limitgauge(130, 0);
		DrawBox(150, 20, 150 + limit, 60, BLUE, true);
	}
	if (ver == 102) {
		limitgauge(130, 0);
		DrawBox(150, 20, 650, 60, BLUE, true);
	}



	if (Lflag == true) {
		light(lx - scrolX, ly - scrolY);
	}

	if ((stage != 22) && (stage != 23) && (stage != 100) && (stage != 101) && (stage != 102) && (stage != 103) && (stage != 104)) {
		DrawBox(6395 - scrolX, 0 - scrolY, 6400 - scrolX, 600, RED, true);
	}
	if (ver == 4) {
		if (batterycount == 0) {
			batterynumber0(580, 30);
		}
		else if (batterycount == 2) {
			batterynumber1(580, 30);
		}
		else if (batterycount == 4) {
			batterynumber2(580, 30);
		}
		else if (batterycount == 6) {
			batterynumber3(580, 30);
		}
	}
	if (stage == 23) {
		bosslifebar(130, 20, false);
		DrawBox(150, 40, bosslife * 0.1 + 150, 90, BLUE, true);
		missilemeter(x - 23 + 16 - scrolX, y + jHeight + 5);
		DrawBox(x - 23 + 16 - scrolX, y + jHeight + 5, x - 23 + 16 + missilecount * 5 - scrolX, y + jHeight + 27,RED,true);
		missilemeter2(x - 23 - scrolX, y + jHeight + 5);
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