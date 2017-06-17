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
	int version;
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
	static const int width = 50, height = 30;
};

struct Trap {
	int x, y;
	bool flag;
	static const int width = 40, height = 40;
};

struct Stone {
	int x, y;
	bool flag;
	static const int width = 40, height = 40;
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
	static const int width = 40, height = 40;
};

struct Ufo {
	int x, y;
	bool flag;
	bool turn;
	static const int width = 40, height = 30;
};

struct Fish {
	int x, y;
	bool flag;
	static const int width = 50, height = 20;
};

struct Urchin {
	int x, y;
	bool flag;
	static const int width = 40, height = 40;
};


class CSGame :public CScene {
	//～変数宣言～
	

	Graph killer, chip1_1,chip1_2,chip2_1,chip2_2,chip3,chip4,background,stone,gameover,fat,urchin,one_two;
	Anim bird,trap,bat,player,ufo,fish,bubble;
	int x, y, vy, vx, g, d;
	int scrolX;
	int jumpf;
	int stage;
	int version;
	static const int jWidth = 50, jHeight = 30;
	bool life;
	bool space;
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
