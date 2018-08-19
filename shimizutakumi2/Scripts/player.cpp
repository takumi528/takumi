#include "Player.h"

Player::Player(int x, int y) :state(this, &Player::Normal), param({5, 1.5, 2, 8, 1}), c(x, y, 0, 0), deco(this, &Player::Deco),swing(60, 20, 20, 5, GetColor(255, 12, 12)) {
	v = 0;
	cnt = 0;
	direc = 0;
	life = 100;
	invincible = 0;

	LoadDivGraph("pho_test/player.png", 48, 8, 6, 40, 40, graph);
	draw.Reset(graph, &c);
	draw.Set(-20, -20, 24);
	drawBase = &draw;
	drawDeco = &deco;
}

void Player::Move() {
	c.x += c.vx;
	c.y += c.vy;
	//if (GetObstacleManager().Hit(x, y, R) == true) {//障害物はマス目管理のほうが軽いので切り替えたほうがいい
	//	x -= vx;
	//	y -= vy;
	//}
	c.vx = 0;
	c.vy = 0;

	//if (x < 0 + R) {//壁との衝突判定は移動完了後に
	//	x = 0 + R;
	//}/*
	//if (x > GetMap().GetWidth() * 40 - R) {
	//	x = GetMap().GetWidth() * 40 - R;
	//}
	//if (y > GetMap().GetHeight() * 40 - R) {
	//	y = GetMap().GetHeight() * 40 - R;
	//}*/
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

	effect.Loop();
	if (state.Main()) {
		cnt = 0;
		drawBase = &draw;
	}
	c.vx += v*cosf(GetRad());
	c.vy += v*sinf(GetRad());

	if (c.y <= 300) {
		state.SetNextState(this, &Player::Clear);
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

void Player::Draw() {
	{
		Graph::Disable d;
		DrawFormatString(0, 0, RED, "%d, %d, %d, %d", c.x, c.y, c.vx, c.vy);//仮
	}
	drawDeco->Draw();
	effect.Draw(c.x, c.y);
}

void Player::Deco() {
	if (invincible % 5 == 0) {
		drawBase->Draw();
	}
}

void Player::HitWall() {
	c.vx = 0;
	c.vy = 0;
}

bool Player::Normal() {
	int buf = GetInputDirec();

	if (buf >= 0) {
		direc = buf;
		v = param.speed;
		++cnt;//好きなタインミングで増やす
	}
	else {
		v = 0;
	}

	direc %= 8;
	
	if (direc == 3 || direc == 4 || direc == 5)
		buf = 0;
	if (direc == 6)
		buf = 8;
	if (direc == 2)
		buf = 16;
	if (direc == 0 || direc == 1 || direc == 7)
		buf = 24;

	if (v != 0)
		buf += (cnt / 8) % 4;

	if (!Input.GetKeyDown(Input.key.LSHIFT)) {
		draw.Set(- 20, - 20, buf);
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
		draw.Set(- 20, - 20, buf + 4);
		if (Input.GetKeyEnter(Input.key.Z)) {
			state.SetNextState(this, &Player::AttackZD);
			return true;
		}
		else if (Input.GetKeyEnter(Input.key.X)) {
			state.SetNextState(this, &Player::AttackXD);
			return true;
		}
		else if (Input.GetKeyEnter(Input.key.LSHIFT)) {//仮
			lastDirec = direc;
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

		int buf = 0;

		direc %= 8;
		if (direc == 3 || direc == 5 || direc == 5)
			buf = 36;
		if (direc == 6)
			buf = 37;
		if (direc == 2)
			buf = 38;
		if (direc == 0 || direc == 1 || direc == 7)
			buf = 39;

		draw.Set(-20, -20, buf);

	}
	else if (cnt - param.stepTime < param.stopTime) {
		if (cnt - param.stepTime == 0) {
			v = 0;
		}
		if (Input.GetKeyEnter(Input.key.LSHIFT)) {
			lastDirec = direc;
			state.SetNextState(this, &Player::Step);
		}
	}
	else {
		state.SetNextState(this, &Player::Normal);
		return true;
	}
	++cnt;
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
	if (cnt < 30 + 10) {
		if (cnt == 0) {
			v = 0;
			swing.Set(GetRad() - DTR(60), GetRad() + DTR(60));
			swing.Attach(&effect);//swingをeffectに登録
		}
		++cnt;
	}
	else {
		state.SetNextState(this, &Player::Normal);
		return true;
	}
	return false;
}

bool Player::AttackZD() {//ダッシュ攻撃未実装の場合
	return AttackZN();
}

bool Player::AttackXD() {//ダッシュ攻撃未実装の場合
	return AttackXN();
}

Circle Player::GetHitBody()const {
	return Circle(c.x + c.vx, c.y + c.vy, R);
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

int Player::GetX()const {
	return c.x;
}

int Player::GetY()const {
	return c.y;
}

int Player::GetR()const {
	return R;
}

int& Player::GetVX() {
	return c.vx;
}

int& Player::GetVY(){
	return c.vy;
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