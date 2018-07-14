
#include "weapon.h"
extern CPlayer GetPlayer();
extern CMap GetMap();
extern CEnemyManager GetEnemyManager();

extern int Wsignal;
extern int wearweapon;


CWeapon::CWeapon() {

}

CWeapon::CWeapon(int x,int y,int v,int power,int direction) {
	this->x = x;
	this->y = y;
	this->v = v;
	this->power = power;
	this->direction = direction;
	deleteFlag = false;
}


void CWeapon::Move() {
	if (direction == 0) {
		y -= v;
	}
	if (direction == 1) {
		y -= v;
		x += v / 2;
	}
	if (direction == 2) {
		y -= v;
		x -= v / 2;
	}
}

void CWeapon::Loop() {
	if (y - scrY < 0 || Disappear() == true) {
		deleteFlag = true;
	}
}

void CWeapon::Draw() {
	DrawCircle(x - scrX, y - scrY, R, WHITE, true);
}

bool CWeapon::Disappear() {
	return GetEnemyManager().WeaponDisappear(x, y, R);
}

int CWeapon::GetX() {
	return x;
}

int CWeapon::GetY() {
	return y;
}

int CWeapon::GetR() {
	return R;
}

bool CWeapon::GetDeleteFlag() {
	return deleteFlag;
}

int CWeapon::GetPower() {
	return power;
}

CWeaponManager::CWeaponManager() {
	count = 0;
}

void CWeaponManager::Appear(int x,int y) {
	if (wearweapon == 3) {
		weapon.push_back(new CWeapon(x, y, 10, 1, 0));
		weapon.push_back(new CWeapon(x, y, 10, 1, 1));
		weapon.push_back(new CWeapon(x, y, 10, 1, 2));
	}
	else {
		weapon.push_back(new CWeapon(x, y, 10, 1, 0));
	}
}

void CWeaponManager::Move() {
	for (auto i = weapon.begin(); i != weapon.end();) {
		if ((*i)->GetDeleteFlag() == true) {
			i = weapon.erase(i);
		}
		else {
			i++;
		}
	}
	for (auto i = weapon.begin(); i != weapon.end(); i++) {
		(*i)->Move();
	}
}

void CWeaponManager::Draw() {
	for (auto i = weapon.begin(); i != weapon.end(); i++) {
		(*i)->Draw();
	}
}

void CWeaponManager::Loop() {
	for (auto i = weapon.begin(); i != weapon.end(); i++) {
		(*i)->Loop();
	}

	if (count > 0) {
		count--;
	}
}

bool CWeaponManager::Hit(int x, int y,int r) {
	for (auto i = weapon.begin(); i != weapon.end(); i++) {
			if ((x - (*i)->GetX())*(x - (*i)->GetX()) + (y - (*i)->GetY())*(y - (*i)->GetY()) <= (r + (*i)->GetR()) * (r + (*i)->GetR())) {
				return true;
		}
	}
	return false;
}


void CWeaponManager::PAttack() {
	if (Input.GetKeyDown(Input.key.Z)) {
		if (count <= 0) {
			Appear(GetPlayer().GetX(), GetPlayer().GetY());
			count = 5;
		}
	}

}

int CWeaponManager::GetPower() {
	for (auto i = weapon.begin(); i != weapon.end(); i++) {
		return (*i)->GetPower();
	}
}