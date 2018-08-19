#pragma once

#include "Suken.h"

#include "Easing.h"
#include "Graphics.h"

class Effect {//���X�g�\���ł��B��Ԉُ������ōČ����܂�
public:
	Effect() :b(nullptr), f(nullptr) {}

	Effect(Effect* ptr) {//�������G�t�F�N�g���X�g�ɒǉ����܂�
		Attach(ptr);//�R���X�g���N�^���ł͉��z�֐��͌Ăяo����Ȃ�
	}

	virtual ~Effect() {
		if (f != nullptr) {
			f->Purge();
		}
	}

	virtual void Loop() {
		if (f != nullptr)
			f->Loop();//�`��
	};

	virtual void Draw(int x, int y) {
		if (f != nullptr)
			f->Draw(x, y);//�`��
	};

	virtual void Attach(Effect *ptr) {
		Purge();
		b = ptr;
		if (b != nullptr) {
			f = b->f;
			b->f = this;
		}
		if (f != nullptr)
			f->b = this;
	}

	virtual void Purge() {
		if (b != nullptr)
			b->SetForward(f);
		if (f != nullptr)
			f->SetBehind(b);
		f = nullptr;
		b = nullptr;
	}

	void SetForward(Effect *f) {
		this->f = f;
	}
	void SetBehind(Effect *b) {
		this->b = b;
	}

	Effect *b, *f;
};

class TempEffect:public Effect {//����new�ō쐬�BParge�Ŏ��Q����G�t�F�N�g�ł�
public:
	TempEffect(Effect* ptr):Effect(ptr){}

	void Attach(Effect *ptr)final {}//�֎~

	void Purge() {//���Q����̂ŁALoop()�̈�ԍŌ�Ŏ��s
		if(b != nullptr)
			b->SetForward(f);
		if (f != nullptr)
			f->SetBehind(b);
		f = nullptr;
		b = nullptr;
		delete this;		//���Q
	}
};

class SwingEff:public Effect {
public:
	SwingEff(int r1, int r2, int time, int after, int color) :cnt(0), r1(r1), r2(r2), time(time), after(after), begin(0), end(0), color(color) {
		LoadDivGraph("pho_test/swordEff.png", num, num, 1, 320 / num, 40, graph);
	}

	void Reset(int r1, int r2, int time, int after) {
		this->r1 = r1;
		this->r2 = r2;
		this->time = time;
		this->after = after;
	}

	void Set(float begin, float end) {
		cnt = 0;
		this->begin = begin;
		this->end = end;
	}

	void Loop() {
		++cnt;
		if (cnt == time + after)
			Purge();
	}

	void Draw(int x, int y) {
		if (f != nullptr)
			f->Draw(x, y);

		float b, e;
		if (end - begin >= 0) {
			b = begin + easing::InOutQuad(min(cnt + 1, time), time, 0, abs(end - begin));
			e = begin + easing::InOutQuad(max(cnt - after, 0), time, 0, abs(end - begin));
		}
		else {
			b = begin - easing::InOutQuad(min(cnt + 1, time), time, 0, abs(end - begin));
			e = begin - easing::InOutQuad(max(cnt - after, 0), time, 0, abs(end - begin));
		}
		float radB = b;
		float radE;
		DrawBright bright(color);//�������؂��Ɠ����ɕ`����@�����ɖ߂�
		DrawBlendMode mode(DrawBlendMode::ADD);//��

		for (int i = 0; i < num; ++i) {
			radE = e + (b - e)*(num - i - 1) / num;
			graph[i].DrawModi(x + (int)(cosf(radE)*r1), y + (int)(sinf(radE)*r1), x + (int)(cosf(radB)*r1), y + (int)(sinf(radB)*r1), x + (int)(cosf(radB)*r2), y + (int)(sinf(radB)*r2), x + (int)(cosf(radE)*r2), y + (int)(sinf(radE)*r2));
			radB = radE;
		}
	}

private:
	static const int num = 8;
	Graph graph[num];
	int cnt;
	int r1;//�����ق��̔��a
	int r2;//�Z���ق��̔��a
	int time;//�U������
	int after;//�U����d������(�c���̂̂��鎞��)
	unsigned int color;//�c���̐F
	float begin, end;//���̊J�n/�I���p�x
};