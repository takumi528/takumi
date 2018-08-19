#pragma once
#include "Suken.h"
#include "select.h"


class CSTitle :public CScene {
	Graph graph;

	//初期化　画像のロードなども
	void Start();
	//処理　毎フレーム呼ばれる
	void Loop();
	//描画　毎フレーム呼ばれる
	void Draw();
	//後片付け	FlipSceneされた時に呼び出される
	void End();
};