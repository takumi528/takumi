#include "Player.h"

Player::Player(int x, int y) :state(this, &Player::Normal), param({5, 1.5, 2, 8, 1}) {
	this->x = x;
	this->y = y;
	x = 400;
	y = 300;
	vx = 0;
	vy = 0;
	v = 0;
	cnt = -1;
	life = 100;
	invincible = 0;
}

void Player::Move() {
	vx += v*cosf(GetRad());
	vy += v*sinf(GetRad());
	x += vx;
	y += vy;
	//if (GetObstacleManager().Hit(x, y, R) == true) {//障害物はマス目管理のほうが軽いので切り替えたほうがいい
	//	x -= vx;
	//	y -= vy;
	//}
	vx = 0;
	vy = 0;

	if (x < 0 + R) {//壁との衝突判定は移動完了後に
		x = 0 + R;
	}/*
	if (x > GetMap().GetWidth() * 40 - R) {
		x = GetMap().GetWidth() * 40 - R;
	}
	if (y > GetMap().GetHeight() * 40 - R) {
		y = GetMap().GetHeight() * 40 - R;
	}*/
}

void Player::Loop() {

	//ちなみに
	//right = Input.GetKeyDown(Input.key.RIGHT);
	//と
	//if (Input.GetKeyDown(Input.key.RIGHT)) {
	//	right = true;
	//}
	//else {
	//	right = false;
	//}
	//は同じ。
	//GetKeyDown()はbool型を返す関数だから。
	++cnt;
	if (state.Main()) {
		cnt = -1;
		lastDirec = direc;
	}


	if (y <= 300) {
	//	state.SetNextState(this, &Player::Clear);
	}

	//if (invincible <= 0) {
	//	if (Hit() != 0) {//当たり判定は外部に出すべき
	//		life -= GetEnemyManager().GerPower();
	//		invincible = 60;
	//	}
	//	if (Hit() == 1) {
	//		y += GetEnemyManager().GetKnock();
	//	}
	//	else if (Hit() == 2) {
	//		y -= GetEnemyManager().GetKnock();
	//	}
	//}

	if (invincible > 0) {
		invincible--;
	}

	//仮
	if (life <= 0) {
		life = 0;
	}

	//if (GetMap().GetFix() == true) {
	//	if (x > GetMap().GetFixX() + 600 - R) {
	//		x = GetMap().GetFixX() + 600 - R;
	//	}
	//	if (x < GetMap().GetFixX() + R) {
	//		x = GetMap().GetFixX() + R;
	//	}
	//	if (y > GetMap().GetFixY() + 600 - R) {
	//		y = GetMap().GetFixY() + 600 - R;
	//	}
	//	if (y < GetMap().GetFixY() + R) {
	//		y = GetMap().GetFixY() + R;
	//	}
	//}
}

void Player::Draw(int scrX, int scrY) {
	DrawFormatString(0, 0, RED, "%d", y);//仮
	if (invincible % 5 == 0) {
		DrawCircle(x + scrX, y + scrY, R, RED, true);
		DrawCircle(x + 3*cosf(GetRad()) + scrX, y + 3 * sinf(GetRad()) + scrY, 3, WHITE, true);
	}

	//	DrawFormatString(100, 0, BLUE, "%d", vx);
}

bool Player::Normal() {
	int buf = GetInputDirec();

	if (buf >= 0) {
		direc = buf;
		v = param.speed;
	}
	else {
		v = 0;
	}

	if (!Input.GetKeyDown(Input.key.LSHIFT)) {
		if (Input.GetKeyEnter(Input.key.Z)) {
			state.SetNextState(this, &Player::AttackZN);
			return true;
		}
		else if (Input.GetKeyEnter(Input.key.X)) {
			state.SetNextState(this, &Player::AttackXN);
			return true;
		}
		
	}
	else {
		v *= param.dushRate;
		if (Input.GetKeyEnter(Input.key.Z)) {
			state.SetNextState(this, &Player::AttackZD);
			return true;
		}
		else if (Input.GetKeyEnter(Input.key.X)) {
			state.SetNextState(this, &Player::AttackXD);
			return true;
		}
		else if (Input.GetKeyEnter(Input.key.LSHIFT)) {//仮
			state.SetNextState(this, &Player::Step);
			return true;
		}
	}
	return false;
}

bool Player::Step() {
	if (cnt == 0) {
		direc = lastDirec;
		v = param.speed * param.stepRate;
	}
	else if (cnt - param.stepTime < param.stopTime) {
		if (cnt - param.stepTime == 0) {
			v = 0;
		}
		if (Input.GetKeyEnter(Input.key.LSHIFT)) {
			state.SetNextState(this, &Player::Step);
		}
	}
	else {
		state.SetNextState(this, &Player::Normal);
		return true;
	}
	return false;
}

bool Player::Clear() {
	direc = 0;
	v = 3;
	return false;
}

bool Player::AttackZN() {
	state.SetNextState(this, &Player::Normal);
	return true;
}

bool Player::AttackXN() {
	state.SetNextState(this, &Player::Normal);
	return true;
}

bool Player::AttackZD() {//ダッシュ攻撃未実装の場合
	return AttackZN();
}

bool Player::AttackXD() {//ダッシュ攻撃未実装の場合
	return AttackXN();
}

int Player::GetX()const {
	return x;
}

int Player::GetY()const {
	return y;
}

int Player::GetV()const {
	return v;
}

int Player::GetR()const {
	return R;
}

int Player::GetLife()const {
	return life;
}

int Player::Hit() {
//	return GetEnemyManager().PHit(x, y, R);
	return 0;
}

bool Player::GetItem(int x,int y,int R) {
	if ((x - this->x)*(x - this->x) + (y - this->y)*(y - this->y) <= (R + this->R)*(R + this->R)) {
		return true;
	}
	return false;
}

bool Player::EweaponDisappear(int x, int y, int R) {
	if ((x - this->x)*(x - this->x) + (y - this->y)*(y - this->y) <= (R + this->R)*(R + this->R)) {
		return true;
	}
	return false;
}

int Player::GetInputDirec() {
	if (Input.GetKeyDown(Input.key.UP)) {
		if (Input.GetKeyDown(Input.key.RIGHT)) {
			return 1;
		}
		else if (Input.GetKeyDown(Input.key.LEFT)) {
			return 7;
		}
		else {
			return 0;
		}
	}
	else if(Input.GetKeyDown(Input.key.DOWN)) {
		if (Input.GetKeyDown(Input.key.RIGHT)) {
			return 3;
		}
		else if (Input.GetKeyDown(Input.key.LEFT)) {
			return 5;
		}
		else {
			return 4;
		}
	}
	else {
		if (Input.GetKeyDown(Input.key.RIGHT)) {
			return 2;
		}
		else if (Input.GetKeyDown(Input.key.LEFT)) {
			return 6;
		}
		else {
			return -1;
		}
	}
}

int Player::GetRelativeDirec() {
	int buf = GetInputDirec();
	if (buf < 0)
		return 0;
	return buf - direc;
}

float Player::GetRad() {
	return ((float)(direc - 2)) * DX_PI / 4.f;
}