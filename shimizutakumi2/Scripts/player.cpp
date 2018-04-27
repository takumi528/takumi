#include "player.h"
#include "over.h"

extern CMap GetMap();
extern CEnemyManager GetEnemyManager();
extern CWeaponManager GetWeaponManager();

CPlayer::CPlayer() {
}

void CPlayer::Appear() {
	x = 200;
	y = 350 + GetMap().GetHeight() * 40 - 600;
	v = 5;
	life = 100;
	invincible = 0;
}

void CPlayer::Move() {
	if (y > 300) {
		if (y - R > 0) {
			if (Input.GetKeyDown(Input.key.UP)) {
				y -= v;
			}
		}
		if (y + R < GetMap().GetHeight() * 40) {
			if (Input.GetKeyDown(Input.key.DOWN)) {
				y += v;
			}
		}
		if (x - R > 0) {
			if (Input.GetKeyDown(Input.key.LEFT)) {
				x -= v;
			}
		}
		if (x + R < GetMap().GetWidth() * 40) {
			if (Input.GetKeyDown(Input.key.RIGHT)) {
				x += v;
			}
		}
	}
	else {
		y -= 3;
	}
}

void CPlayer::Loop() {
	if (invincible <= 0) {
		if (Hit() != 0) {
			life -= GetEnemyManager().GerPower();
			invincible = 60;
		}
		if (Hit() == 1) {
			y += GetEnemyManager().GetKnock();
		}
		else if (Hit() == 2) {
			y -= GetEnemyManager().GetKnock();
		}
	}

	if (invincible > 0) {
		invincible--;
	}
	//‰¼
	if (life <= 0) {
		life = 0;
	}
}


void CPlayer::Draw() {
	DrawFormatString(0, 0, RED, "%d", y);//‰¼
	if (invincible % 5 == 0) {
		DrawCircle(x, y + mapY, R, RED, true);
	}
}

int CPlayer::GetX() {
	return x;
}

int CPlayer::GetY() {
	return y;
}

int CPlayer::GetV() {
	return v;
}

int CPlayer::GetLife() {
	return life;
}

int CPlayer::Hit() {
	return GetEnemyManager().PHit(x, y, R);
}

bool CPlayer::GetItem(int x,int y,int R) {
	if ((x - this->x)*(x - this->x) + (y - this->y)*(y - this->y) <= (R + this->R)*(R + this->R)) {
		return true;
	}
	return false;
}