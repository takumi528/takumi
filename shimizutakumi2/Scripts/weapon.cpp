
#include "weapon.h"
extern CPlayer GetPlayer();
extern CMap GetMap();
extern CEnemyManager GetEnemyManager();

extern int Wsignal;
extern int weargun;

int Pown1, Pown2, Pown3, Pown4;

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
	if (y + mapY < 0 || Disappear() == true) {
		deleteFlag = true;
	}
}

void CWeapon::Draw() {
	DrawCircle(x, y + mapY, R, WHITE, true);
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

CWeapon2::CWeapon2(int x, int y, int v, int power, int direction) {
	this->x = x;
	this->y = y;
	this->v = v;
	this->power = power;
	this->direction = direction;
	deleteFlag = false;
}

void CWeapon2::Draw() {
	DrawCircle(x, y + mapY, R, BLACK, true);
}

CWeaponManager::CWeaponManager() {
	count = 0;
	change = 1;
	Pown1 = 0;
	Pown2 = 0;
	Pown3 = 0;
	Pown4 = 0;
}

void CWeaponManager::Appear(int x,int y) {
	if (weargun == 3) {
		if (change == 1) {
			weapon.push_back(new CWeapon(x, y, 10, 1, 0));
			weapon.push_back(new CWeapon(x, y, 10, 1, 1));
			weapon.push_back(new CWeapon(x, y, 10, 1, 2));
		}
		else if (change == 2) {
			weapon.push_back(new CWeapon2(x, y, 10, 2, 0));
			weapon.push_back(new CWeapon2(x, y, 10, 2, 1));
			weapon.push_back(new CWeapon2(x, y, 10, 2, 2));
		}
	}
	else {
		if (change == 1) {
			weapon.push_back(new CWeapon(x, y, 10, 1, 0));
		}
		else if (change == 2) {
			weapon.push_back(new CWeapon2(x, y, 10, 2, 0));
		}
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
	DrawFormatString(400, 0, RED, "%d", Pown1);//‰¼
}

void CWeaponManager::Loop() {
	for (auto i = weapon.begin(); i != weapon.end(); i++) {
		(*i)->Loop();
	}
	if(Input.GetKeyEnter(Input.key.NUM1)){
		change = 1;
	}
	if (Input.GetKeyEnter(Input.key.NUM2)) {
		change = 2;
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
			switch (change) {
			case 1:
				if (Pown1 > 0) {
					Appear(GetPlayer().GetX(), GetPlayer().GetY());
					count = 5;
					Pown1--;
				}
				break;
			case 2:
				if (Pown2 > 0) {
					Appear(GetPlayer().GetX(), GetPlayer().GetY());
					count = 5;
					Pown2--;
				}
				break;
			case 3:
				if (Pown3 > 0) {
					Appear(GetPlayer().GetX(), GetPlayer().GetY());
					count = 5;
					Pown3--;
				}
				break;
			case 4:
				if (Pown4 > 0) {
					Appear(GetPlayer().GetX(), GetPlayer().GetY());
					count = 5;
					Pown4--;
				}
			}
		}
	}
}

int CWeaponManager::GetPower() {
	for (auto i = weapon.begin(); i != weapon.end(); i++) {
		return (*i)->GetPower();
	}
}

int CWeaponManager::GetChange() {
	return change;
}

int GetPown1() {
	return Pown1;
}
int GetPown2() {
	return Pown2;
}
int GetPown3() {
	return Pown3;
}
int GetPown4() {
	return Pown4;
}