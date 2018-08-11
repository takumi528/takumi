#pragma once

#include "Suken.h"

bool Yes();
bool No();
bool Right();
bool Left();
bool Up();
bool Down();

class CSHome :public CScene {
	//～変数宣言～
	Graph back;
	int chose;

	//初期化　画像のロードなども
	void Start();
	//処理　毎フレーム呼ばれる
	void Loop();
	//描画　毎フレーム呼ばれる
	void Draw();
	//後片付け	必要なら使おう
	void End();

public:
	CSHome();
};

class CSStageSelect :public CScene {
	//～変数宣言～
	int select;

	//初期化　画像のロードなども
	void Start();
	//処理　毎フレーム呼ばれる
	void Loop();
	//描画　毎フレーム呼ばれる
	void Draw();
	//後片付け	必要なら使おう
	void End();

public:
	CSStageSelect();
};

class CSHelp :public CScene {
	//～変数宣言～
	int num;
	Graph back[2];

	//初期化　画像のロードなども
	void Start();
	//処理　毎フレーム呼ばれる
	void Loop();
	//描画　毎フレーム呼ばれる
	void Draw();
	//後片付け	必要なら使おう
	void End();

public:
	CSHelp();
};