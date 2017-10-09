#pragma once

/**
*	@file	MyScene.cpp
*	@brief	シーンクラスの宣言は、ここでしましょう
*	@author	-
*/


#include "Suken.h"

#include "Addons\Window.h"





class CSTitle :public CScene {
	int stage;
	int ver;
	int count;
	Graph back[3];
	Anim number;

	//初期化　画像のロードなども
	void Start();
	//処理　毎フレーム呼ばれる
	void Loop();
	//描画　毎フレーム呼ばれる
	void Draw();
	//後片付け	FlipSceneされた時に呼び出される
	void End();
};

struct Rect {
	int left, right, top, bottom;
	Rect(int left, int right, int top, int bottom):
	left(left),
	right(right),
	top(top),
	bottom(bottom){}
};

struct Killer {
	int x, y;
	bool flag;
	static const int width = 50, height = 30;
};

struct Bird {
	int x, y;
	bool flag;
	static const int width = 40, height = 20;
};

struct Trap {
	int x, y;
	bool flag;
	static const int width = 30, height = 30;
};

struct Stone {
	int x, y;
	bool flag;
	static const int width = 30, height = 30;
};

struct Fat {
	int x, y;
	bool flag;
	static const int width = 70, height = 40;
};

struct Bat {
	int x, y;
	bool flag;
	bool turn;
	static const int width = 30, height = 30;
};

struct Ufo {
	int x, y;
	bool flag;
	bool turn;
	static const int width = 30, height = 20;
};

struct Fish {
	int x, y;
	bool flag;
	static const int width = 40, height = 20;
};

struct Urchin {
	int x, y;
	bool flag;
	static const int width = 35, height = 35;
};

struct Bone1 {
	int x, y;
	int count;
	bool flag;
	static const int width = 30, height = 50;
};

struct Deadbone {
	int x, y;
	int count;
	bool flag;
	static const int width = 30, height = 30;
};


struct Eel {
	int x, y;
	bool flag;
	static const int width = 130, height = 35;
};

struct Cactus {
	int x, y;
	bool flag;
	static const int width = 30, height = 100;
};

struct Cactusleft {
	int x, y;
	bool flag;
	static const int width = 30, height = 50;
};

struct Cactusright {
	int x, y;
	bool flag;
	static const int width = 30, height = 50;
};

struct Scorpion0 {
	int x, y;
	int count;
	bool flag;
	static const int width = 50, height = 60;
};

struct Scorpion1 {
	int x, y;
	int count;
	bool flag;
	static const int width = 50, height = 60;
};

struct Fireball {
	int x, y;
	bool flag,hit;
	static const int width = 40, height = 40;
};

  struct Groundfire {
	  int x, y;
	  bool flag;
	  static const int width = 40, height = 80;
  };

  struct Volcano1 {
	  int x, y;
	  int count;
	  bool flag;
	  static const int width = 632, height = 600;
  };

  struct Volcano2 {
	  int x, y;
	  bool flag;
	  static const int width = 632, height = 600;
  };

  struct Bossbone {
	  int x, y;
	  static const int width = 300, height = 600;
  };

  struct Bossbonehand {
	  int x, y;
	  bool flag;
	  bool damage;
	  static const int width = 60, height = 350;
  };

  struct Battery {
	  int x, y;
	  bool flag;
	  bool get;
	  static const int width = 32, height = 60;
  };

  struct Killbone {
	  int x, y;
	  bool flag;
	  static const int width = 500, height = 60;
  };

  struct Oasis {
	  int x, y;
	  bool flag;
	  static const int width = 40, height = 40;
  };

class CSGame :public CScene {
	//～変数宣言～
	

	Graph killer, chip1_1, chip1_2, chip2_1, chip2_2, chip3, chip4, chip5, chip6, chip7, chip8, background1, background2, background3, background4, background5, stone, gameover, fat, urchin, one_two, one_two_two, two_three, three_four, three_four_two, four_five, four_five_two, four_five_three, five_six, seven_eight, bone0, deadbone, player3, cactus, cactusleft, cactusright, fireball, ufo0, ufo02, volcano0, bossbonehand, light, battery, batterynumber0, batterynumber1,batterynumber2,batterynumber3,killbone,limitgauge;
	Anim bird,trap,bat,player,ufo,fish,bubble,bone1,bone2,eel,scorpion1,scorpion0,version,storm,groundfire,ash,volcano1,volcano2,fire,littlefire,fireballback,bossbone,bossbonehanddamage,bossbonedamage,oasis;
	int x, y, vy, vx, g, d, wcount,fy,lx,ly;
	int scrolX,scrolY;
	int jumpf;
	int stage;
	int ver;
	int gUP;
	int Lcount,batteryf,batterycount;
	int bossbonelife,bossbonedamagecount;
	int limit;
	static const int jWidth = 50, jHeight = 30;
	bool life;
	bool space;
	bool bflag;
	bool Yflag;
	bool Lflag;
	MCE mce;
	Killer k,K[20];
	Trap t, T[50];
	Stone s, S[50];
	Ufo u, U[50];
	Fat f, F[20];
	Bird b, B[20];
	Bat b2, B2[20];
	Fish f2, F2[20];
	Urchin u2, U2[50];
	Eel e, E[20];
	Bone1 bo1, BO1[20];
	Deadbone db, DB[20];
	Cactus c, C[50];
	Cactusleft cl, CL[50];
	Cactusright cr, CR[50];
	Scorpion1 s2, S2[20];
	Scorpion0 s3, S3[20];
	Fireball f3, F3[50];
	Groundfire gf, GF[50];
	Volcano1 v1, V1[10];
	Volcano2 v2, V2[10];
	Bossbone bb;
	Bossbonehand bbh, BBH[10];
	Battery b3, B3[20];
	Killbone kb;
	Oasis o, O[50];
	int test[10];

	//初期化　画像のロードなども
	void Start();
	//処理　毎フレーム呼ばれる
	void Loop();
	//描画　毎フレーム呼ばれる
	void Draw();
	//後片付け	必要なら使おう
	void End();

	void HitBlock(int x1, int y1);
	public:
		CSGame(int stage):stage(stage){}
};

class CSOver :public CScene {
	//～変数宣言～
	int stage;

	//初期化　画像のロードなども
	void Start();
	//処理　毎フレーム呼ばれる
	void Loop();
	//描画　毎フレーム呼ばれる
	void Draw();
	//後片付け	必要なら使おう
	void End();
};


class CSComplete :public CScene {
	//～変数宣言～

	int stage;

	//初期化　画像のロードなども
	void Start();
	//処理　毎フレーム呼ばれる
	void Loop();
	//描画　毎フレーム呼ばれる
	void Draw();
	//後片付け	必要なら使おう
	void End();
public:
	CSComplete(int stage) :stage(stage) {}
};
