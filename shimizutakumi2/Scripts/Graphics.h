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
		NOBLEND = 0,		// �m�[�u�����h
		ALPHA = 1,			// ���u�����h
		ADD = 2,			// ���Z�u�����h
		SUB = 3,			// ���Z�u�����h
		MUL = 4,			// ��Z�u�����h
		XOR = 6,			// XOR�u�����h =  �\�t�g�E�G�A�����_�����O���[�h�ł̂ݗL��
		INVDESTCOLOR = 9,	// �`���̐F�̔��]�l���|����
		INVSRC = 10,		// �`�挳�̐F�𔽓]����
		MULA = 11,			// �A���t�@�`�����l���l���t����Z�u�����h
		ALPHA_X4 = 12,		// ���u�����h�̕`�挳�̋P�x���ő�S�{�ɂł��郂�[�h
		ADD_X4 = 13,		// ���Z�u�����h�̕`�挳�̋P�x���ő�S�{�ɂł��郂�[�h
		HALF_ADD = 15		// �����Z�u�����h
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