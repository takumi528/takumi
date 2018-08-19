#include "Enemy.h"

#include "Suken.h"

#include "Graphics.h"

extern CWeaponManager& GetWeaponManager();
extern CSword& GetSword();
extern MCE mce;
extern Player& GetPlayer();
extern CMap& GetMap();
extern CItemManager& GetItemManager();

extern int eneX,eneY,eneDrop;//死んだときの敵の座標とドロップアイテム情報の受け渡し,item.cppで使用
extern int koeneflag, koeneDrop;//↑の固定時の敵バージョン
extern int gunpower[30];
extern int swordpower[30];
extern int armarguard[30];
extern int weararmar, wearweapon;
int DROP;//CSGameでステージごとに設定

extern int fixcount;//mapで宣言

Enemy::Enemy() :Enemy(100, 100) {}

Enemy::Enemy(int x, int y)
	:state(this, &Enemy::Normal), draw(this, &Enemy::NormalD) {
	this->x = x;
	this->y = y;

	r = 20;
	life = 20;
	maxLife = 20;

	cnt = -1;
	v = 0;
	vx = 0;
	vy = 0;
	direc = 4;
}

void Enemy::Loop() {
	++cnt;
	if (state.Main()) {
		cnt = -1;
	}
	vx = v*cosf(GetRad());
	vy = v*sinf(GetRad());
}

void Enemy::Move() {
	x += vx;
	y += vy;

	vx = 0;
	vy = 0;
}

void Enemy::Draw() {
	Deco();
}

void Enemy::DrawBase() {
	draw.Draw();
}

Circle Enemy::GetHitBody()const {
	return Circle(x + vx, y + vy, r);
}

void Enemy::Deco() {

	DrawBase();

	DrawBox(x - r * 1.5, y - r - 15, x - r * 1.5 + life * r * 3 / maxLife, y - r - 5, WHITE, true);
}

void Enemy::NormalD() {
	DrawCircle(x, y, r, BLUE, true);
}

float Enemy::GetRad() {
	return ((float)(direc - 2)) * DX_PI / 4.f;
}


//
//CEnemy::CEnemy() {}
//
//CEnemy::CEnemy(int x,int y,int v,int R, int power,int knock,int life) {//直進
//	this->x = x;
//	this->y = y;
//	this->v = v;
//	this->R = R;
//	this->power = power;
//	this->knock = knock;
//	this->life = life;
//	this->maxlife = life;
//	deleteFlag = false;
//	drop = DROP;
//}
//
//CEnemy0::CEnemy0(int x, int y, int v, int R, int power, int knock, int life) {//チュートリアル
//	this->x = x;
//	this->y = y;
//	this->v = v;
//	this->R = R;
//	this->power = power;
//	this->knock = knock;
//	this->life = life;
//	this->maxlife = life;
//	deleteFlag = false;
//	drop = 1;
//}
//
//CEnemy2::CEnemy2(int x, int y, int v, int R, int power, int knock, int life) {//横移動
//	this->x = x;
//	this->y = y;
//	this->v = v;
//	this->R = R;
//	this->power = power;
//	this->knock = knock;
//	this->life = life;
//	this->maxlife = life;
//	deleteFlag = false;
//	drop = DROP;
//	if (x < scrX + 300) {
//		turn = 1;
//	}
//	else {
//		turn = -1;
//	}
//	turncount = 0;
//}
//
//CEnemy3::CEnemy3(int x, int y, int v, int R, int power, int knock, int life) {//追跡(固)
//	this->x = x;
//	this->y = y;
//	this->v = v;
//	this->R = R;
//	this->power = power;
//	this->knock = knock;
//	this->life = life;
//	this->maxlife = life;
//	deleteFlag = false;
//	drop = DROP;
//	vx = 0;
//	vy = 0;
//	leftGo = false;
//	upGo = false;
//	Gocount = 0;
//}
//
//
//void CEnemy::Move() {
//		y += v;
//}
//
//void CEnemy0::Move() {}
//
//void CEnemy2::Move() {
//	if (turn == 1) {
//		x += v;
//    }
//	else {
//		x -= v;
//	}
//
//	if (turncount < 150) {
//		turncount++;
//	}
//	else {
//		turn *= -1;
//		turncount = 0;
//	}
//
//	if (x < 0 + R) {
//		x = 0 + R + 5;
//		turncount = 150;
//	}
//	if (x > mce.GetWidth() * 40 - R) {
//		x = mce.GetWidth() * 40 - R - 5;
//		turncount = 150;
//	}
//}
//
//void CEnemy3::Move() {
//	if (GetMap().GetFix() == true) {
//		if(Gocount <= 0){
//			if (x < GetPlayer().GetX()) {
//				leftGo = false;
//			}
//			else {
//				leftGo = true;
//			}
//			if (y < GetPlayer().GetY()) {
//				upGo = false;
//			}
//			else {
//				upGo = true;
//			}
//			Gocount = rand() % 30 + 30;
//		}
//		else {
//			Gocount--;
//		}
//		if (leftGo == true) {
//			if (vx > -2) {
//				vx--;
//			}
//		}
//		else {
//			if (vx < 2) {
//				vx++;
//			}
//		}
//		if (upGo == true) {
//			if (vy > -2) {
//				vy--;
//			}
//		}
//		else {
//			if (vy < 2) {
//				vy++;
//			}
//		}
//	}
//	x += vx;
//	y += vy;
//	
//}
//
//void CEnemy::Loop() {
//		if (WHit() == true) {
//			life -= GetWeaponManager().GetPower() * gunpower[wearweapon];
//		}
//		if (SHit() == true) {
//			life -= GetSword().GetPower() * swordpower[wearweapon];
//			y -= GetSword().GetKnock();
//		}
//		if (life <= 0) {
//		eneX = x;
//		eneY = y;
//		eneDrop = drop;
//		deleteFlag = true;
//		}
//		if (y > GetMap().GetHeight() * 40) {
//			deleteFlag = true;
//		}
//}
//
//void CEnemy0::Loop() {
//	if (WHit() == true) {
//		life -= GetWeaponManager().GetPower() * gunpower[wearweapon];
//	}
//	if (SHit() == true) {
//		life -= GetSword().GetPower() * swordpower[wearweapon];
//		y -= GetSword().GetKnock();
//	}
//	if (life <= 0) {
//		eneX = x;
//		eneY = y;
//		eneDrop = drop;
//		deleteFlag = true;
//	}
//	if (y > GetPlayer().GetY() + 1000) {
//		deleteFlag = true;
//	}
//}
//
//void CEnemy2::Loop() {
//	if (WHit() == true) {
//		life -= GetWeaponManager().GetPower() * gunpower[wearweapon];
//	}
//	if (SHit() == true) {
//		life -= GetSword().GetPower() * swordpower[wearweapon];
//		y -= GetSword().GetKnock();
//	}
//	if (life <= 0) {
//		eneX = x;
//		eneY = y;
//		eneDrop = drop;
//		deleteFlag = true;
//	}
//	if (y > GetPlayer().GetY() + 1000) {
//		deleteFlag = true;
//	}
//}
//
//void CEnemy3::Loop() {
//	if (WHit() == true) {
//		life -= GetWeaponManager().GetPower() * gunpower[wearweapon];
//	}
//	if (SHit() == true) {
//		life -= GetSword().GetPower() * swordpower[wearweapon];
//		y -= GetSword().GetKnock();
//	}
//	if (life <= 0) {
//		if (fixcount == 1) {
//			GetMap().FixReset2();
//			koeneflag = true;
//		}
//		fixcount--;
//		eneX = x;
//		eneY = y;
//		eneDrop = drop;
//		deleteFlag = true;
//	}
//	if (x < scrX || x > scrX + 600 || y < scrY || y > scrY + 600) {
//		deleteFlag = true;
//	}
//	if (GetMap().GetFix() == true) {
//		if (x < GetMap().GetFixX() + R) {
//			x = GetMap().GetFixX() + R;
//		}
//		if (x > GetMap().GetFixX() + 600 - R) {
//			x = GetMap().GetFixX() + 600 - R;
//		}
//		if (y < GetMap().GetFixY() + R) {
//			y = GetMap().GetFixY() + R;
//		}
//		if (y > GetMap().GetFixY() + 600 - R) {
//			y = GetMap().GetFixY() + 600 - R;
//		}
//	}
//}
//
//bool CEnemy::WHit() {
//		return GetWeaponManager().Hit(x, y, R);
//}
//
//bool CEnemy::SHit() {
//		return GetSword().Hit(x, y, R);
//}
//
//void CEnemy::Draw() {
//		if (WHit() == false && SHit() == false) {
//			DrawCircle(x - scrX, y - scrY, R, BLUE, true);
//		}
//		else {
//			DrawCircle(x - scrX, y - scrY, R, GREEN, true);
//		}
//		DrawBox(x - R * 1.5 - scrX, y - scrY - R - 15, x - R * 1.5 - scrX + life * R * 3 / maxlife, y - scrY - R - 5, WHITE, true);
//
//}
//
//void CEnemy0::Draw() {
//	if (WHit() == false && SHit() == false) {
//		DrawCircle(x - scrX, y - scrY, R, WHITE, true);
//	}
//	else {
//		DrawCircle(x - scrX, y - scrY, R, GREEN, true);
//	}
//	DrawBox(x - R * 1.5 - scrX, y - scrY - R - 15, x - R * 1.5 - scrX + life * R * 3 / maxlife , y - scrY - R - 5, WHITE, true);
//}
//
//void CEnemy2::Draw() {
//	if (WHit() == false && SHit() == false) {
//		DrawCircle(x - scrX, y - scrY, R, RED, true);
//	}
//	else {
//		DrawCircle(x - scrX, y - scrY, R, GREEN, true);
//	}
//	DrawBox(x - R * 1.5 - scrX, y - scrY - R - 15, x - R * 1.5 - scrX + life * R * 3 / maxlife, y - scrY - R - 5, WHITE, true);
//}
//
//void CEnemy3::Draw() {
//	if (WHit() == false && SHit() == false) {
//		DrawCircle(x - scrX, y - scrY, R, BLACK, true);
//	}
//	else {
//		DrawCircle(x - scrX, y - scrY, R, GREEN, true);
//	}
//	DrawBox(x - R * 1.5 - scrX, y - scrY - R - 15, x - R * 1.5 - scrX + life * R * 3 / maxlife, y - scrY - R - 5, WHITE, true);
//}
//
//int CEnemy::GetX() {
//	return x;
//}
//
//int CEnemy::GetY() {
//	return y;
//}
//
//int CEnemy::GetR() {
//	return R;
//}
//
//bool CEnemy::GetDeleteFlag() {
//	return deleteFlag;
//}
//
//int CEnemy::GetPower() {
//	return power;
//}
//
//int CEnemy::GetKnock() {
//	return knock;
//}
//
//void CEnemy::Disappear() {
//	deleteFlag = true;
//}
//
//int CEnemy::GetDrop() {
//	return drop;
//}
//
//CEnemyManager::CEnemyManager() {
//
//}
//
//void CEnemyManager::Appear() {
//
//	for (int i = 0; i < mce.GetWidth(); i++) {
//		for (int j = 0; j < mce.GetHeight(); j++) {
//			if (mce.Get(mce.layer.A, i, j) == 1 && j * 40 > GetPlayer().GetY() - 630 && i * 40 < GetPlayer().GetX() + 330 && i * 40 > GetPlayer().GetX() - 330) {
//				enemy.push_back(new CEnemy0(i * 40, j * 40, 2, 20, 10, 50, 200));
//				fixcount++;
//				mce.Get(mce.layer.A, i, j) = 0;
//			}
//		}
//	}
//	for (int i = 0; i < mce.GetWidth(); i++) {
//		for (int j = 0; j < mce.GetHeight(); j++) {
//			if (mce.Get(mce.layer.A, i, j) == 2 && j * 40 > GetPlayer().GetY() - 630 && i * 40 < GetPlayer().GetX() + 330 && i * 40 > GetPlayer().GetX() - 330) {
//				enemy.push_back(new CEnemy(i * 40, j * 40, 2, 20, 10, 50, 200));
//				mce.Get(mce.layer.A, i, j) = 0;
//			}
//		}
//	}
//	for (int i = 0; i < mce.GetWidth(); i++) {
//		for (int j = 0; j < mce.GetHeight(); j++) {
//			if (mce.Get(mce.layer.A, i, j) == 3 && j * 40 > GetPlayer().GetY() - 630 && i * 40 < GetPlayer().GetX() + 330 && i * 40 > GetPlayer().GetX() - 330) {
//				enemy.push_back(new CEnemy2(i * 40, j * 40, 4, 20, 10, 50, 200));
//				mce.Get(mce.layer.A, i, j) = 0;
//			}
//		}
//	}
//	for (int i = 0; i < mce.GetWidth(); i++) {
//		for (int j = 0; j < mce.GetHeight(); j++) {
//			if (GetMap().GetFix() == true) {
//				if (mce.Get(mce.layer.A, i, j) == 4 && i * 40 > scrX && i * 40 < scrX + 600 && j * 40 > scrY && j * 40 < scrY + 600) {
//					enemy.push_back(new CEnemy3(i * 40, j * 40, 2, 20, 10, 50, 200));
//					fixcount++;
//					mce.Get(mce.layer.A, i, j) = 0;
//				}
//			}
//		}
//	}
//}
//
//
//void CEnemyManager::Loop() {
//	for (auto i = enemy.begin(); i != enemy.end(); i++) {
//		(*i)->Loop();
//	}
//}
//
//void CEnemyManager::Move() {
//	for (auto i = enemy.begin(); i != enemy.end();) {
//		if ((*i)->GetDeleteFlag()) {
//			i = enemy.erase(i);
//		}
//		else {
//			i++;
//		}
//	}
//	for (auto i = enemy.begin(); i != enemy.end(); i++) {
//		(*i)->Move();
//	}
//}
//
//void CEnemyManager::Draw() {
//	for (auto i = enemy.begin(); i != enemy.end(); i++) {
//		(*i)->Draw();
//	}
//}
//
//bool CEnemyManager::WeaponDisappear(int x, int y, int r) {
//	for (auto i = enemy.begin(); i != enemy.end(); i++) {
//		if ((x - (*i)->GetX())*(x - (*i)->GetX()) + (y - (*i)->GetY())*(y - (*i)->GetY()) <= (r + (*i)->GetR()) * (r + (*i)->GetR())) {
//			return true;
//		}
//	}
//	return false;
//}
//
//int CEnemyManager::PHit(int x, int y, int r) {
//	for (auto i = enemy.begin(); i != enemy.end(); i++) {
//		if ((x - (*i)->GetX())*(x - (*i)->GetX()) + (y - (*i)->GetY())*(y - (*i)->GetY()) <= (r + (*i)->GetR()) * (r + (*i)->GetR())) {
//			if (y >= (*i)->GetY()) {
//				return 1;
//			}
//			else if (y < (*i)->GetY()) {
//				return 2;
//			}
//		}
//	}
//	return 0;
//}
//
//int CEnemyManager::GerPower() {
//	for (auto i = enemy.begin(); i != enemy.end(); i++) {
//		return (*i)->GetPower();
//	}
//}
//
//int CEnemyManager::GetKnock() {
//	for (auto i = enemy.begin(); i != enemy.end(); i++) {
//		return (*i)->GetKnock();
//	}
//}
//
//void CEnemyManager::Disappear() {
//	for (auto i = enemy.begin(); i != enemy.end(); i++) {
//		(*i)->Disappear();
//	}
//}
