#include "sword.h"

CPlayer GetPlayer();
CMap GetMap();

CSword::CSword() {
	x = 800;
	y = 800;
	count = 0;
	damage = 0;
	flag = false;
}

void CSword::Set(int x, int y) {
	this->x = x;
	this->y = y;
}

void CSword::Appear(int x,int y) {
	Set(x, y);
	count = 1;
	flag = true;
}

void CSword::PAttack() {
	if (count <= 0) {
		if (Input.GetKeyEnter(Input.key.SPACE)) {
			Appear(GetPlayer().GetX(), GetPlayer().GetY());
		}
	}
}

void CSword::Loop() {
	if (damage > 0) {
		damage--;
	}
	if (count > 0) {
		this->x = GetPlayer().GetX();
		this->y = GetPlayer().GetY();
		count--;
	}
	else {
		flag = false;
	}
}

void CSword::Draw() {
	if (flag == true) {
		DrawCircle(x, y + mapY, R, PURPLE, true);
	}
}

bool CSword::Hit(int x,int y,int r) {
	if (flag == true) {
		if(damage <= 0){
			if ((x - this->x)*(x - this->x) + (y - this->y)*(y - this->y) <= (r + this->R)*(r + this->R)) {
				if (y <= this->y) {
					damage = 5;
				}
			}
		}
	}
	if (damage > 0) {
		return true;
	}
	return false;
}

int CSword::GetPower() {
	return power;
}

int CSword::GetKnock() {
	return knock;
}