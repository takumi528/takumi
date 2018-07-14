#include "pub.h"

extern CMap GetMap();

MCE mce;

int type; //0->タイトル,1->操作画面,2->ゲームオーバー,3->ポーズ画面,4->ゲームクリア
bool retry;
bool back;
bool nextstage;
int scrY;
int scrX;
int kakunin;//デバッグ用、値を代入すると左下にOKと出力

void CPub::Loop() {
	if (kakunin > 0) {
		kakunin--;
	}
}

void CPub::Draw() {
	if (kakunin > 0) {
		DrawFormatString(0, 500, RED, "OK");
	}
}
