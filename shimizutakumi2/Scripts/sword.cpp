#include "sword.h"

Player& GetPlayer();
CMap GetMap();

CSword::CSword() {
	x = 800;
	y = 800;
	damage = 0;
	flag = false;
	count = 0;
	R = 60;
}

void CSword::Load() {
	sword.Set(LoadDivGraph("stpic/swordanim.png", 5, 5, 1, 140, 90), 4);
}

void CSword::Set(int x, int y) {
	this->x = x;
	this->y = y;
}

void CSword::Appear(int x,int y) {
	Set(x, y);
	count = 10;
	flag = true;
}

void CSword::PAttack() {
	if (count <= 0) {
		if (Input.GetKeyEnter(Input.key.X)) {
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
	if (count > 0) {
		sword.PlusCount();
	}
}

void CSword::Draw() {
	if (flag == true) {
		DrawCircle(x - scrX, y - scrY, R, PURPLE, true);
		//sword(x - R - scrX, y - R - scrY, false, true);
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