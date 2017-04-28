#include "Game.h"

suken::CGame::CGame():CScene(false) {}

void suken::CGame::Init(CScene* scene) {
	flip = nullptr;
	mode = nullptr;
	flag = 0;
	now.Reset(scene);
	if (now) {
		now->Start();
	}
}

void suken::CGame::Init(CScene* scene, Flip flip) {
	mode = nullptr;
	flag = 0;
	next.Reset(scene);
	if (next) {
		next->Start();
	}
	flag |= isFliping;//bit���Z�@�t���O�I��
	this->flip = new Flip(flip);
}

void suken::CGame::FlipScene(CScene* scene) {
	next.Reset(scene);
	flag |= isNextFlip;//bit���Z�@�t���O�I��
	flag &= ~isFliping;
	flip = nullptr;
}

void suken::CGame::FlipScene(CScene* scene, const char* ruleGraph, unsigned char speed, unsigned char gradate) {
	next.Reset(scene);
	flag |= isNextFlip;//bit���Z�@�t���O�I��
	flip = new Flip(Flip::DEFAULT, ruleGraph, "", speed, gradate);
}

void suken::CGame::FlipScene(CScene* scene, const char* ruleGraph, const char* ruleGraph2, unsigned char speed, unsigned char gradate) {
	next.Reset(scene);
	flag |= isNextFlip;//bit���Z�@�t���O�I��
	flip = new Flip(Flip::DEFAULT, ruleGraph, ruleGraph2, speed, gradate);
}

void suken::CGame::FlipScene(CScene* scene, Flip::Type flipType, unsigned char speed) {
	next.Reset(scene);
	flag |= isNextFlip;//bit���Z�@�t���O�I��
	flip = new Flip(flipType, "", "", speed);
}

suken::CScene::Debug suken::CGame::Debug() {
	return debug;
}

void suken::CGame::DrawNowLoading() {
	screen.Draw();
	loadingAnim.Draw(loadingPosX, loadingPosY);
}

bool suken::CGame::FlipTransition() {
	SetDrawBright(nullptr);
	bool flagBuf = false;
	DrawMode buf(DX_BLENDMODE_NOBLEND,255,255,255,255);
	if (now) {
		flagBuf = flip->Draw(screen, nextScreen, now->mode, next->mode);
	}
	else {
		flagBuf = flip->Draw(screen, nextScreen, &buf, next->mode);
	}
	return flagBuf;
}