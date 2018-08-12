#pragma once

#include "Suken.h"
#include <memory>

#include "Task.h"
#include "ObjectManager.h"

#include "MyObject.h"

class CSGame :public CScene {
	//～変数宣言～
	int stage;
	TaskManager task;
	std::unique_ptr<Player> player;//ユニーク＿ポインタを使っています
	ObjectManager<Enemy> enemy;
	Map map;
	Scrol scrol;

	//初期化　画像のロードなども
	void Start();
	//処理　毎フレーム呼ばれる
	void Loop();
	//描画　毎フレーム呼ばれる
	void Draw();
	//後片付け	必要なら使おう
	void End();

public:
	CSGame(int stage);
};