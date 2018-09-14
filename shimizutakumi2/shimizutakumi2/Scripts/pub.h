#pragma once
#include "Suken.h"
#include "scrol.h"
#include "map.h"

extern MCE mce;

class CPub {
private:
	int type; //0->タイトル,1->操作画面,2->ゲームオーバー,3->ポーズ画面,4->ゲームクリア
	bool retry;
	bool back;
	bool nextstage;
	int kakunin;//デバッグ用、値を代入すると左下にOKと出力
public:
	void Loop();
	void Draw();
	int GetType();
	bool GetRetry();
	bool GetBack();
	bool GetNextstage();
	//以下は各信号の切り替え、1でtrueに、0でfalseに
	void Changeretry(int a);
	void Changeback(int a);
	void Changenextstage(int a);
	void Changetype(int a);
};