#pragma once

/**
*	@file	MyScene.cpp
*	@brief	シーンクラスの宣言は、ここでしましょう
*	@author	-
*/

#include "Suken.h"

#include "Addons\Window.h"

class CSTitle :public CScene {
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

class CSGame :public CScene {
	//～変数宣言～
	Graph player;
	Graph killer,killer2, chip;
	int x, y, vy, vx, g, kx, ky, kx2, ky2;
	int scrolX;
	int jumpf;
	const int jWidth = 50, jHeight = 30;
	const int kWidth = 50, kHeight = 30;
	MCE mce;

	//初期化　画像のロードなども
	void Start();
	//処理　毎フレーム呼ばれる
	void Loop();
	//描画　毎フレーム呼ばれる
	void Draw();
	//後片付け	必要なら使おう
	void End();

	void HitBlock(int x1, int y1);
};

class CSOver :public CScene {
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