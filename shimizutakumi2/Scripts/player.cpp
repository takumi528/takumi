#include "player.h"
#include "over.h"

extern CMap& GetMap();
extern CEnemyManager& GetEnemyManager();
extern CWeaponManager& GetWeaponManager();
extern CObstacleManager& GetObstacleManager();

CPlayer::CPlayer() :state(this, &CPlayer::Normal), param({5, 1.5, 3, 5, 1}) {

}

void CPlayer::Appear() {
	x = 800;
	y = 350 + GetMap().GetHeight() * 40 - 600;
	cnt = -1;
	v = 0;
	life = 100;
	invincible = 0;
}

void CPlayer::Move() {
	float vx = v*cosf(GetRad());
	float vy = v*sinf(GetRad());
	x += vx;
	y += vy;
	if (GetObstacleManager().Hit(x, y, R) == true) {//��Q���̓}�X�ڊǗ��̂ق����y���̂Ő؂�ւ����ق�������
		x -= vx;
		y -= vy;
	}

	if (x < 0 + R) {//�ǂƂ̏Փ˔���͈ړ��������
		x = 0 + R;
	}
	if (x > GetMap().GetWidth() * 40 - R) {
		x = GetMap().GetWidth() * 40 - R;
	}
	if (y > GetMap().GetHeight() * 40 - R) {
		y = GetMap().GetHeight() * 40 - R;
	}
}

void CPlayer::Loop() {

	//���Ȃ݂�
	//right = Input.GetKeyDown(Input.key.RIGHT);
	//��
	//if (Input.GetKeyDown(Input.key.RIGHT)) {
	//	right = true;
	//}
	//else {
	//	right = false;
	//}
	//�͓����B
	//GetKeyDown()��bool�^��Ԃ��֐�������B
	++cnt;
	if (state.Main()) {
		cnt = -1;
		lastDirec = direc;
	}


	if (y <= 300) {
		state.SetNextState(this, &CPlayer::Clear);
	}

	if (invincible <= 0) {
		if (Hit() != 0) {//�����蔻��͊O���ɏo���ׂ�
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

	//��
	if (life <= 0) {
		life = 0;
	}

	if (GetMap().GetFix() == true) {//�X�N���[���ʒu�͈ړ��������Ă���̂ق����������A������O�ɁB
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
}

void CPlayer::Draw() {
	DrawFormatString(0, 0, RED, "%d", y);//��
	if (invincible % 5 == 0) {
		DrawCircle(x - scrX, y - scrY, R, RED, true);
		DrawCircle(x + 3*cosf(GetRad()) - scrX, y + 3 * sinf(GetRad()) - scrY, 3, WHITE, true);
	}

	//	DrawFormatString(100, 0, BLUE, "%d", vx);
}

bool CPlayer::Normal() {
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
			state.SetNextState(this, &CPlayer::AttackZN);
			return true;
		}
		else if (Input.GetKeyEnter(Input.key.X)) {
			state.SetNextState(this, &CPlayer::AttackXN);
			return true;
		}
		
	}
	else {
		v *= param.dushRate;
		if (Input.GetKeyEnter(Input.key.Z)) {
			state.SetNextState(this, &CPlayer::AttackZD);
			return true;
		}
		else if (Input.GetKeyEnter(Input.key.X)) {
			state.SetNextState(this, &CPlayer::AttackXD);
			return true;
		}
		else if (Input.GetKeyEnter(Input.key.LSHIFT)) {//��
			state.SetNextState(this, &CPlayer::Step);
			return true;
		}
	}
	return false;
}

bool CPlayer::Step() {
	if (cnt == 0) {
		direc = lastDirec;
		v = param.speed * param.stepRate;
	}
	else if (cnt - param.stepTime < param.stopTime) {
		if (cnt - param.stepTime == 0) {
			v = 0;
		}
		if (Input.GetKeyEnter(Input.key.LSHIFT)) {
			state.SetNextState(this, &CPlayer::Step);
		}
	}
	else {
		state.SetNextState(this, &CPlayer::Normal);
		return true;
	}
	return false;
}

bool CPlayer::Clear() {
	direc = 0;
	v = 3;
	return false;
}

bool CPlayer::AttackZN() {
	state.SetNextState(this, &CPlayer::Normal);
	return true;
}

bool CPlayer::AttackXN() {
	state.SetNextState(this, &CPlayer::Normal);
	return true;
}

bool CPlayer::AttackZD() {//�_�b�V���U���������̏ꍇ
	return AttackZN();
}

bool CPlayer::AttackXD() {//�_�b�V���U���������̏ꍇ
	return AttackXN();
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

int CPlayer::GetR() {
	return R;
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

bool CPlayer::EweaponDisappear(int x, int y, int R) {
	if ((x - this->x)*(x - this->x) + (y - this->y)*(y - this->y) <= (R + this->R)*(R + this->R)) {
		return true;
	}
	return false;
}

int CPlayer::GetInputDirec() {
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

int CPlayer::GetRelativeDirec() {
	int buf = GetInputDirec();
	if (buf < 0)
		return 0;
	return buf - direc;
}

float CPlayer::GetRad() {
	return ((float)(direc - 2)) * DX_PI / 4.f;
}