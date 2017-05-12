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
	const int width = 50, height = 30;
};

struct Trap {
	int x, y;
	bool flag;
	const int width = 40, height = 40;
};

class CSGame :public CScene {
	//～変数宣言～
	

	Graph player;
	Graph killer, chip,background,trap;
	int x, y, vy, vx, g;
	int scrolX;
	int jumpf;
	int stage;
	const int jWidth = 50, jHeight = 30;
	MCE mce;
	Killer  k,K[20];
	Trap t, T[50];
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

public:
	CSOver(int stage) :stage(stage) {}
};


class CSComplete :public CScene {
	//～変数宣言～

	//初期化　画像のロードなども
	void Start();
	//処理　毎フレーム呼ばれる
	void Loop();
	//描画　毎フレーム呼ばれる
	void Draw();
	//後片付け	必要なら使おう
	void End();
};
