#include "player.h"
#include "over.h"

extern CMap GetMap();
extern CEnemyManager GetEnemyManager();
extern CWeaponManager GetWeaponManager();

CPlayer::CPlayer() {
}

void CPlayer::Appear() {
	x = 800;
	y = 350 + GetMap().GetHeight() * 40 - 600;
	v = 5;
	life = 100;
	invincible = 0;
	stopcount = 0;
	kaihiL = 0;
	kaihiR = 0;
	kaihiU = 0;
	kaihiD = 0;
	right = false;
	left = false;
	up = false;
	down = false;
}

void CPlayer::Move() {
	if (y > 300) {
		if (stopcount <= 0) {
			if (up == true) {
				y -= v;
			}
			if (down == true) {
				y += v;
			}
			if (left == true) {
				x -= v;
			}
			if (right == true) {
				x += v;
			}

			if (Input.GetKeyEnter(Input.key.LSHIFT)) {
				if (up == true) {
					if (right == true && left == false) {
						kaihiU = 20;
						kaihiR = 20;
						stopcount = 10;
					}
					else if (left == true && right == false) {
						kaihiU = 20;
						kaihiL = 20;
						stopcount = 10;
					}
					else {
						kaihiU = 20;
					}
				}
				else if (down == true) {
					if (right == true && left == false) {
						kaihiD = 20;
						kaihiR = 20;
						stopcount = 10;
					}
					else if (left == true && right == false) {
						kaihiD = 20;
						kaihiL = 20;
						stopcount = 10;
					}
					else {
						kaihiD = 20;
					}
				}
				else {
					if (right == true && left == false) {
						kaihiR = 20;
						stopcount = 10;
					}
					else if (left == true && right == false) {
						kaihiL = 20;
						stopcount = 10;
					}
				}
			}
		}
	}
	else {
		y -= 3;
	}

}

void CPlayer::Loop() {
	if (Input.GetKeyDown(Input.key.RIGHT)) {
		right = true;
	}
	else {
		right = false;
	}
	if (Input.GetKeyDown(Input.key.LEFT)) {
		left = true;
	}
	else {
		left = false;
	}
	if (Input.GetKeyDown(Input.key.UP)) {
		up = true;
	}
	else {
		up = false;
	}
	if (Input.GetKeyDown(Input.key.DOWN)) {
		down = true;
	}
	else {
		down = false;
	}

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

	if (stopcount > 0) {
		stopcount--;
	}

	x -= kaihiL;
	x += kaihiR;
	y -= kaihiU;
	y += kaihiD;
	if (kaihiL > 0) {
		kaihiL -= 2;
	}
	if (kaihiR > 0) {
		kaihiR -= 2;
	}
	if (kaihiU > 0) {
		kaihiU -= 2;
	}
	if (kaihiD > 0) {
		kaihiD -= 2;
	}
	//��
	if (life <= 0) {
		life = 0;
	}

	if (GetMap().GetFix() == true) {
		if (x > GetMap().GetFixX() + 600 - R) {
			x = GetMap().GetFixX() + 600 - R;
		}
		if (x < GetMap().GetFixX() + R) {
			x = GetMap().GetFixX() + R;
		}
		if (y > GetMap().GetFixY() + 600 - R) {
			y = GetMap().GetFixY() + 600 - R;
		}
		if (y < GetMap().GetFixY() + R) {
			y = GetMap().GetFixY() + R;
		}
	}

	if (x < 0 + R) {
		x = 0 + R;
	}
	if (x > GetMap().GetWidth() * 40 - R) {
		x = GetMap().GetWidth() * 40 - R;
	}
	if (y > GetMap().GetHeight() * 40 - R) {
		y = GetMap().GetHeight() * 40 - R;
	}
}


void CPlayer::Draw() {
	DrawFormatString(0, 0, RED, "%d", y);//��
	if (invincible % 5 == 0) {
		DrawCircle(x - scrX, y - scrY, R, RED, true);
	}

	DrawFormatString(100, 0, BLUE, "%d", scrY);
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

int CPlayer::GetKaihiU() {
	return kaihiU;
}

int CPlayer::GetKaihiD() {
	return kaihiD;
}