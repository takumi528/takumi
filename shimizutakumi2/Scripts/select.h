#pragma once
#include "Suken.h"

#include "pub.h"
#include "possession.h"
class CSelect {
private:
	Graph background,background3,background31_1,background31_2,background4,background41_1,background41_2,background51,background52,redbar,redbar2,redbar3,blackbox,blackbox2,sozai,seinou,mybag,swordicons,gunicons,armaricons;
	int stage;
	int count;
	int scene;//1:ホーム、2:ステージ選択、3:カスタマイズ、4:アイテム生成、5:ヘルプ
	int sentaku,sentaku3,sentaku31,sentaku4,sentaku41,sentaku5;
	int count2;//キーボードの処理が連続するのを抑える
	bool mybagflag;
public:
	CSelect();
	void Load();
	void Loop();
	void Draw();
	int GetStage();
	int GetScene();
	int GetCount2();
};