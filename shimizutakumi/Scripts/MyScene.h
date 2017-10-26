#pragma once

/**
*	@file	MyScene.cpp
*	@brief	シーンクラスの宣言は、ここでしましょう
*	@author	-
*/


#include "Suken.h"

#include "Addons\Window.h"

enum {
	M_JUMP,
	M_GET,
	M_OVER,
	M_SELECT,
};



class CSTitle :public CScene {
	int stage;
	int ver;
	int count;
	int select;
	int clear;
	CData save;
	Graph back;
	Anim number,player;

	//初期化　画像のロードなども
	void Start();
	//処理　毎フレーム呼ばれる
	void Loop();
	//描画　毎フレーム呼ばれる
	void Draw();
	//後片付け	FlipSceneされた時に呼び出される
	void End();
public:
	CSTitle();
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
	static const int width = 45, height = 25;
};

struct Trap {
	int x, y;
	bool flag;
	static const int width = 30, height = 30;
};

struct Stone {
	int x, y;
	bool flag;
	static const int width = 35, height = 35;
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
	static const int width = 35, height = 35;
};

struct Ufo {
	int x, y;
	bool flag;
	bool turn;
	static const int width = 35, height = 25;
};

struct Fish {
	int x, y;
	bool flag;
	static const int width = 40, height = 12;
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
	static const int width = 27, height = 43;
};

struct Deadbone {
	int x, y;
	int count;
	bool flag;
	static const int width = 27, height = 27;
};


struct Eel {
	int x, y;
	bool flag;
	static const int width = 135, height = 35;
};

struct Cactus {
	int x, y;
	bool flag;
	static const int width = 30, height = 90;
};

struct Cactusleft {
	int x, y;
	bool flag;
	static const int width = 30, height = 45;
};

struct Cactusright {
	int x, y;
	bool flag;
	static const int width = 25, height = 45;
};

struct Scorpion0 {
	int x, y;
	int count;
	bool flag;
	static const int width = 45, height = 60;
};

struct Scorpion1 {
	int x, y;
	int count;
	bool flag;
	static const int width = 45, height = 60;
};

struct Fireball {
	int x, y;
	bool flag,hit;
	static const int width = 35, height = 35;
};

  struct Groundfire {
	  int x, y;
	  bool flag;
	  static const int width = 37, height = 80;
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
	  static const int width = 50, height = 350;
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

  struct Rightufo {
	  int x, y;
	  bool flag;
	  static const int width = 35, height = 27;
  };

  struct Leftufo {
	  int x, y;
	  bool flag;
	  static const int width = 35, height = 27;
  };

  struct Upufo {
	  int x, y;
	  bool flag;
	  static const int width = 35, height = 27;
  };

  struct Downufo {
	  int x, y;
	  bool flag;
	  static const int width = 35, height = 27;
  };

  struct Rightupufo {
	  int x, y;
	  bool flag;
	  static const int width = 35, height = 27;
  };

  struct Rightdownufo {
	  int x, y;
	  bool flag;
	  static const int width = 35, height = 27;
  };

  struct Ufo2 {
	  int x, y;
	  bool flag;
	  int move, turn;
	  static const int width = 35, height = 27;
  };

  struct BosshandU {
	  int x, y;
	  bool flag;
	  bool damage;
	  static const int width = 45, height = 780;
  };

  struct BosshandD {
	  int x, y;
	  bool flag;
	  bool damage;
	  static const int width = 45, height = 780;
  };

  struct BosshandR {
	  int x, y;
	  bool flag;
	  int v;
	  static const int width = 50, height = 50;
  };

  struct BosshandL {
	  int x, y;
	  bool flag;
	  int v;
	  static const int width = 50, height = 50;
  };

  struct BosshandUR {
	  int x, y;
	  bool flag;
	  int v,vy;
	  static const int width = 50, height = 50;
  };

  struct BosshandUL {
	  int x, y;
	  bool flag;
	  int v,vy;
	  static const int width = 50, height = 50;
  };

  struct BosshandDR {
	  int x, y;
	  bool flag;
	  int v,vy;
	  static const int width = 50, height = 50;
  };

  struct BosshandDL {
	  int x, y;
	  bool flag;
	  int v, vy;
	  static const int width = 50, height = 50;
  };

  struct Missile {
	  int x, y;
	  bool flag;
	  static const int width = 30, height = 40;
  };

  struct Missileshot {
	  int x, y;
	  bool flag;
	  int v;
	  static const int width = 50, height = 30;
  };
class CSGame :public CScene {
	//～変数宣言～
	

	Graph killer, chip1_1, chip1_2, chip2_1, chip2_2, chip3, chip4, chip5, chip6, chip7, chip8, background1, background2, background3, background4, background5, stone, gameover, fat, urchin, one_two, one_two_two, two_three, three_four, three_four_two, four_five, four_five_two, four_five_three, five_six, seven_eight_one,seven_eight_two, bone0, deadbone, player3, cactus, cactusleft, cactusright, fireball, ufo0, ufo02, volcano0, bossbonehand, light, battery, batterynumber0, batterynumber1,batterynumber2,batterynumber3,killbone,limitgauge,rufo,lufo,uufo,dufo,ruufo,rdufo,ufo2,bosshandU,bosshandD,bosshandR,bosshandL,bosshandUR,bosshandUL,bosshandDR,bosshandDL,bosshandR2,bosshandL2,bosshandUR2,bosshandUL2,bosshandDR2,bosshandDL2,bosshandshadow1,bosshandshadow2,bosshandshadow3,bosshandshadow4,bosshandshadow5,missile,missileshot,bosslifebar;
	Anim bird,trap,bat,player,ufo,fish,bubble,bone1,bone2,eel,scorpion1,scorpion0,version,storm,groundfire,ash,volcano1,volcano2,fire,littlefire,fireballback,bossbone,bossbonehanddamage,bossbonedamage,oasis,turnplayer,boss,back8_1,back8_2;
	int x, y, vy, vx, g, d, wcount,fy,lx,ly;
	int scrolX,scrolY;
	int jumpf;
	int stage;
	int ver;
	int gUP;
	int overM;
	int Lcount,batteryf,batterycount;
	int bossbonelife,bossbonedamagecount;
	int limit;
	int missilecount;
	int bosslife;
	static const int jWidth = 50, jHeight = 30;
	bool life;
	bool space;
	bool bflag;
	bool Yflag;
	bool Lflag;
	bool jturn;
	MCE mce;
	Killer k,K[20];
	Trap t, T[50];
	Stone s, S[100];
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
	Rightufo ru, RU[50];
	Leftufo lu, LU[50];
	Upufo uu, UU[50];
	Downufo du, DU[50];
	Rightupufo ruu, RUU[50];
	Rightdownufo rdu, RDU[50];
	Ufo2 u3, U3[50];
	BosshandR bhr, BHR[20];
	BosshandL bhl, BHL[20];
	BosshandUR bhur, BHUR[20];
	BosshandUL bhul, BHUL[20];
	BosshandDR bhdr, BHDR[20];
	BosshandDL bhdl, BHDL[20];
	BosshandU bhu, BHU[20];
	BosshandD bhd, BHD[20];
	Missile m, M[20];
	Missileshot ms, MS[20];
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
