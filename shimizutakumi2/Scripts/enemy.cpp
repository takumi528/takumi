
#include "enemy.h"

extern CWeaponManager GetWeaponManager();
extern CSword GetSword();
extern MCE mce;
extern CPlayer GetPlayer();
extern CMap GetMap();
extern CItemManager GetItemManager();

extern int eneX,eneY,eneDrop;
extern int gunpower[30];
extern int swordpower[30];
extern int armarguard[30];
extern int weararmar, weargun, wearsword;
int DROP;//CSGameでステージごとに設定

CEnemy::CEnemy() {}

CEnemy::CEnemy(int x,int y,int v,int R, int power,int knock,int life) {
	this->x = x;
	this->y = y;
	this->v = v;
	this->R = R;
	this->power = power;
	this->knock = knock;
	this->life = life;
	this->maxlife = life;
	deleteFlag = false;
	drop = DROP;
}

CEnemy0::CEnemy0(int x, int y, int v, int R, int power, int knock, int life) {
	this->x = x;
	this->y = y;
	this->v = v;
	this->R = R;
	this->power = power;
	this->knock = knock;
	this->life = life;
	this->maxlife = life;
	deleteFlag = false;
	drop = 1;
}

CEnemy2::CEnemy2(int x, int y, int v, int R, int power, int knock, int life) {
	this->x = x;
	this->y = y;
	this->v = v;
	this->R = R;
	this->power = power;
	this->knock = knock;
	this->life = life;
	this->maxlife = life;
	deleteFlag = false;
	drop = DROP;
	if (x < 300) {
		turn = false;
	}
	else {
		turn = true;
	}
}

CEnemy3::CEnemy3(int x, int y, int v, int R, int power, int knock, int life) {
	this->x = x;
	this->y = y;
	this->v = v;
	this->R = R;
	this->power = power;
	this->knock = knock;
	this->life = life;
	this->maxlife = life;
	deleteFlag = false;
	drop = DROP;
}


void CEnemy::Move() {
		y += v;
}

void CEnemy0::Move() {}

void CEnemy2::Move() {
	if (turn == false) {
		x += v;
    }
	else {
		x -= v;
	}

	if (x > 600 - R) {
		turn = true;
	}
	if (x < 0 + R) {
		turn = false;
	}
}

void CEnemy3::Move() {
	if (x < GetPlayer().GetX()) {
		x += v;
	}
	if (x > GetPlayer().GetX()) {
		x -= v;
	}
	if (y < GetPlayer().GetY()) {
		y += v;
	}
	if (y > GetPlayer().GetY()) {
		y -= v;
	}
}

void CEnemy::Loop() {
		if (WHit() == true) {
			life -= GetWeaponManager().GetPower() * gunpower[weargun];
		}
		if (SHit() == true) {
			life -= GetSword().GetPower() * swordpower[wearsword];
			y -= GetSword().GetKnock();
		}
		if (life <= 0) {
		eneX = x;
		eneY = y;
		eneDrop = drop;
			deleteFlag = true;
		}
		if (y > GetMap().GetHeight() * 40) {
			deleteFlag = true;
		}
}

void CEnemy0::Loop() {
	if (WHit() == true) {
		life -= GetWeaponManager().GetPower() * gunpower[weargun];
	}
	if (SHit() == true) {
		life -= GetSword().GetPower() * swordpower[wearsword];
		y -= GetSword().GetKnock();
	}
	if (life <= 0) {
		eneX = x;
		eneY = y;
		eneDrop = drop;
		deleteFlag = true;
	}
	if (y > GetPlayer().GetY() + 1000) {
		deleteFlag = true;
	}
}

void CEnemy2::Loop() {
	if (WHit() == true) {
		life -= GetWeaponManager().GetPower() * gunpower[weargun];
	}
	if (SHit() == true) {
		life -= GetSword().GetPower() * swordpower[wearsword];
		y -= GetSword().GetKnock();
	}
	if (life <= 0) {
		eneX = x;
		eneY = y;
		eneDrop = drop;
		deleteFlag = true;
	}
	if (y > GetPlayer().GetY() + 1000) {
		deleteFlag = true;
	}
}

void CEnemy3::Loop() {
	if (WHit() == true) {
		life -= GetWeaponManager().GetPower() * gunpower[weargun];
	}
	if (SHit() == true) {
		life -= GetSword().GetPower() * swordpower[wearsword];
		y -= GetSword().GetKnock();
	}
	if (life <= 0) {
		eneX = x;
		eneY = y;
		eneDrop = drop;
		deleteFlag = true;
	}
	if (y > GetPlayer().GetY() + 1000) {
		deleteFlag = true;
	}
}

bool CEnemy::WHit() {
		return GetWeaponManager().Hit(x, y, R);
}

bool CEnemy::SHit() {
		return GetSword().Hit(x, y, R);
}

void CEnemy::Draw() {
		if (WHit() == false && SHit() == false) {
			DrawCircle(x, y + mapY, R, BLUE, true);
		}
		else {
			DrawCircle(x, y + mapY, R, GREEN, true);
		}
		DrawBox(x - R * 1.5, y + mapY - R - 15, x - R * 1.5 + life * R * 3 / maxlife, y + mapY - R - 5, WHITE, true);
}

void CEnemy0::Draw() {
	if (WHit() == false && SHit() == false) {
		DrawCircle(x, y + mapY, R, WHITE, true);
	}
	else {
		DrawCircle(x, y + mapY, R, GREEN, true);
	}
	DrawBox(x - R * 1.5, y + mapY - R - 15, x - R * 1.5 + life * R * 3 / maxlife , y + mapY - R - 5, WHITE, true);
}

void CEnemy2::Draw() {
	if (WHit() == false && SHit() == false) {
		DrawCircle(x, y + mapY, R, RED, true);
	}
	else {
		DrawCircle(x, y + mapY, R, GREEN, true);
	}
	DrawBox(x - R * 1.5, y + mapY - R - 15, x - R * 1.5 + life * R * 3 / maxlife, y + mapY - R - 5, WHITE, true);
}

void CEnemy3::Draw() {
	if (WHit() == false && SHit() == false) {
		DrawCircle(x, y + mapY, R, BLACK, true);
	}
	else {
		DrawCircle(x, y + mapY, R, GREEN, true);
	}
	DrawBox(x - R * 1.5, y + mapY - R - 15, x - R * 1.5 + life * R * 3 / maxlife, y + mapY - R - 5, WHITE, true);
}

int CEnemy::GetX() {
	return x;
}

int CEnemy::GetY() {
	return y;
}

int CEnemy::GetR() {
	return R;
}

bool CEnemy::GetDeleteFlag() {
	return deleteFlag;
}

int CEnemy::GetPower() {
	return power;
}

int CEnemy::GetKnock() {
	return knock;
}

void CEnemy::Disappear() {
	deleteFlag = true;
}

int CEnemy::GetDrop() {
	return drop;
}

CEnemyManager::CEnemyManager() {

}

void CEnemyManager::Appear() {
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.B, i, j) == 1 && j * 40 < GetPlayer().GetY() - 600 && j * 40 > GetPlayer().GetY() - 606) {
				enemy.push_back(new CEnemy0(i * 40, j * 40, 2, 20, 10, 50, 4));
				mce.Get(mce.layer.B, i, j) = 0;
			}
		}
	}
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.B, i, j) == 2 && j * 40 < GetPlayer().GetY() - 600 && j * 40 > GetPlayer().GetY() - 606) {
				enemy.push_back(new CEnemy(i * 40, j * 40, 2, 20, 10, 50, 200));
				mce.Get(mce.layer.B, i, j) = 0;
			}
		}
	}
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.B, i, j) == 3 && j * 40 < GetPlayer().GetY() - 600 && j * 40 > GetPlayer().GetY() - 606) {
				enemy.push_back(new CEnemy2(i * 40, j * 40, 4, 20, 10, 50, 200));
				mce.Get(mce.layer.B, i, j) = 0;
			}
		}
	}
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.B, i, j) == 4 && j * 40 < GetPlayer().GetY() - 600 && j * 40 > GetPlayer().GetY() - 606) {
				enemy.push_back(new CEnemy3(i * 40, j * 40, 2, 20, 10, 50, 200));
				mce.Get(mce.layer.B, i, j) = 0;
			}
		}
	}
}

void CEnemyManager::Loop() {
	for (auto i = enemy.begin(); i != enemy.end(); i++) {
		(*i)->Loop();
	}
}

void CEnemyManager::Move() {
	for (auto i = enemy.begin(); i != enemy.end();) {
		if ((*i)->GetDeleteFlag()) {
			i = enemy.erase(i);
		}
		else {
			i++;
		}
	}
	for (auto i = enemy.begin(); i != enemy.end(); i++) {
		(*i)->Move();
	}
}

void CEnemyManager::Draw() {
	for (auto i = enemy.begin(); i != enemy.end(); i++) {
		(*i)->Draw();
	}
}

bool CEnemyManager::WeaponDisappear(int x, int y, int r) {
	for (auto i = enemy.begin(); i != enemy.end(); i++) {
		if ((x - (*i)->GetX())*(x - (*i)->GetX()) + (y - (*i)->GetY())*(y - (*i)->GetY()) <= (r + (*i)->GetR()) * (r + (*i)->GetR())) {
			return true;
		}
	}
	return false;
}

int CEnemyManager::PHit(int x, int y, int r) {
	for (auto i = enemy.begin(); i != enemy.end(); i++) {
		if ((x - (*i)->GetX())*(x - (*i)->GetX()) + (y - (*i)->GetY())*(y - (*i)->GetY()) <= (r + (*i)->GetR()) * (r + (*i)->GetR())) {
			if (y >= (*i)->GetY()) {
				return 1;
			}
			else if (y < (*i)->GetY()) {
				return 2;
			}
		}
	}
	return 0;
}

int CEnemyManager::GerPower() {
	for (auto i = enemy.begin(); i != enemy.end(); i++) {
		return (*i)->GetPower();
	}
}

int CEnemyManager::GetKnock() {
	for (auto i = enemy.begin(); i != enemy.end(); i++) {
		return (*i)->GetKnock();
	}
}

void CEnemyManager::Disappear() {
	for (auto i = enemy.begin(); i != enemy.end(); i++) {
		(*i)->Disappear();
	}
}
