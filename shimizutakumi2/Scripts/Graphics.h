#pragma once

#include <DxLib.h>

class DrawBright {
public:
	DrawBright(int r, int g, int b) {
		DxLib::GetDrawBright(&R, &G, &B);
		float k = 1.f / 255;
		DxLib::SetDrawBright((int)(r*R*k), (int)(g*G*k), (int)(b*B*k));
	}
	~DrawBright() {
		DxLib::SetDrawBright(R, G, B);
	}
private:
	int R, G, B;
};

class DrawMode {
public:
	enum BlendMode {
		NOBLEND = 0,		// ノーブレンド
		ALPHA = 1,			// αブレンド
		ADD = 2,			// 加算ブレンド
		SUB = 3,			// 減算ブレンド
		MUL = 4,			// 乗算ブレンド
		XOR = 6,			// XORブレンド =  ソフトウエアレンダリングモードでのみ有効
		INVDESTCOLOR = 9,	// 描画先の色の反転値を掛ける
		INVSRC = 10,		// 描画元の色を反転する
		MULA = 11,			// アルファチャンネル考慮付き乗算ブレンド
		ALPHA_X4 = 12,		// αブレンドの描画元の輝度を最大４倍にできるモード
		ADD_X4 = 13,		// 加算ブレンドの描画元の輝度を最大４倍にできるモード
		HALF_ADD = 15		// 半加算ブレンド
	};
	DrawMode(BlendMode mode, int value = 255) {
		DxLib::GetDrawBlendMode(&m, &v);
		DxLib::SetDrawBlendMode((int)mode, value);
	}
	~DrawMode() {
		DxLib::SetDrawBlendMode(m, v);
	}
private:
	int m, v;
};