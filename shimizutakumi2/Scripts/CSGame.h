#pragma once

#include "Suken.h"
#include "player.h"
#include "weapon.h"
#include "enemy.h"
#include "sword.h"
#include "map.h"
#include "scrol.h"
#include "pause.h"
#include "over.h"
#include "select.h"
#include "pub.h"
#include "clear.h"
#include "item.h"
#include "possession.h"
#include "obstacle.h"

class CSGame :public CScene {
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
	CSGame(int stage):stage(stage) {}
};