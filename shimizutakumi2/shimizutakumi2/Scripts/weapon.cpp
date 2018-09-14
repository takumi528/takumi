
#include "weapon.h"
extern CPlayer& GetPlayer();
extern CMap& GetMap();
extern CEnemyManager& GetEnemyManager();
extern CScrol& GetScrol();
extern CPossession& GetPossession();
extern CWeaponManager& GetWeaponManager();



CWeapon::CWeapon() {

}

CEweapon::CEweapon() {

}

CWeapon::CWeapon(int x,int y,int v,int R,int power,int direction) {
	this->x = x;
	this->y = y;
	this->v = v;
	this->R = R;
	this->power = power;
	this->direction = direction;
	deleteFlag = false;
}

CWeapon2::CWeapon2(int x, int y, int width, int height, int v, int power, int direction) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->v = v;
	this->power = power;
	this->R = 0;
	this->direction = direction;
	deleteFlag = false;
}

CWeapon3::CWeapon3(int width, int power) {
	this->width = width;
	this->power = power;
	this->R = 0;
	deleteFlag = false;
}

CWeapon4::CWeapon4(int x, int y, int v, int R, int power, int explodecount, int direction) {
	this->x = x;
	this->y = y;
	this->v = v;
	this->R = R;
	this->power = power;
	this->direction = direction;
	this->explodecount = explodecount;
	deleteFlag = false;
	karix = GetPlayer().GetX();
	kariy = GetPlayer().GetY();
	reach = false;
}

CEweapon::CEweapon(int x, int y, int v, int power, int direction) {
	this->x = x;
	this->y = y;
	this->v = v;
	this->power = power;
	this->direction = direction;
	deleteFlag = false;
}


void CWeapon::Move() {
		switch (direction) {
		case 0:
		default:
			y -= v;
			break;
		case 1:
			x += v;
			break;
		case 2:
			y += v;
			break;
		case 3:
			x -= v;
			break;
		case -10:
			y -= v * 0.8;
			x -= v * 0.5;
			break;
		case 10:
			y -= v * 0.8;
			x += v * 0.5;
			break;
		case -9:
			y -= v * 0.5;
			x += v * 0.8;
			break;
		case 11:
			y += v * 0.5;
			x += v * 0.8;
			break;
		case -8:
			y += v * 0.8;
			x += v * 0.5;
			break;
		case 12:
			y += v * 0.8;
			x -= v * 0.5;
			break;
		case -7:
			y += v * 0.5;
			x -= v * 0.8;
			break;
		case 13:
			y -= v * 0.5;
			x -= v * 0.8;
		}
}

void CWeapon2::Move() {
	switch (direction) {
	case 0:
	default:
		y -= v;
		break;
	case 1:
		x += v;
		break;
	case 2:
		y += v;
		break;
	case 3:
		x -= v;
		break;
	}
}

void CWeapon3::Move() {}

void CWeapon4::Move() {
	if (kariy > y) {
		kariy -= v;
	}
	if (kariy < y) {
		kariy += v;
	}
	if (karix > x) {
		karix -= v;
	}
	if (karix < x) {
		karix += v;
	}
}

void CEweapon::Move() {
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
	if (y - GetScrol().GetScrY() < -100 || x - GetScrol().GetScrX() < -100 || y - GetScrol().GetScrY() > 700 || x - GetScrol().GetScrX() > 700 || Disappear() == true) {
		deleteFlag = true;
	}
}

void CWeapon2::Loop() {
	if (y + height - GetScrol().GetScrY() < 0) {
		deleteFlag = true;
	}
}

void CWeapon3::Loop() {
	if (GetWeaponManager().GetBeamflag() == false || Input.GetKeyExit(Input.key.Z)) {
		deleteFlag = true;
	}
}

void CWeapon4::Loop() {
	if (kariy == y && karix == x) {
		reach = true;
	}
	if (reach == true && explodecount > 0) {
		explodecount--;
	}
	if (reach == true && explodecount <= 0) {
		deleteFlag = true;
	}
}

void CEweapon::Loop() {
	if (y - GetScrol().GetScrY() < 0 || Disappear() == true) {
		deleteFlag = true;
	}
}

void CWeapon::Draw() {
	DrawCircle(x - GetScrol().GetScrX(), y - GetScrol().GetScrY(), R, WHITE, true);
}

void CWeapon2::Draw() {
	DrawBox(x - GetScrol().GetScrX(), y - GetScrol().GetScrY(), x - GetScrol().GetScrX() + width, y - GetScrol().GetScrY() + height, WHITE, true);
}

void CWeapon3::Draw() {
	switch (GetPlayer().GetRad(0)) {
	case 0:
	default:
		DrawBox(GetPlayer().GetX() - GetScrol().GetScrX() - width / 2, 0, GetPlayer().GetX() - GetScrol().GetScrX() + width / 2, GetPlayer().GetY() - GetScrol().GetScrY(), WHITE, true);
		break;
	case 1:
		DrawBox(GetPlayer().GetX() - GetScrol().GetScrX(), GetPlayer().GetY() - GetScrol().GetScrY() - width / 2, 600, GetPlayer().GetY() - GetScrol().GetScrY() + width / 2, WHITE, true);
		break;
	case 2:
		DrawBox(GetPlayer().GetX() - GetScrol().GetScrX() - width / 2, GetPlayer().GetY() - GetScrol().GetScrY(), GetPlayer().GetX() - GetScrol().GetScrX() + width / 2, 600, WHITE, true);
		break;
	case 3:
		DrawBox(0, GetPlayer().GetY() - GetScrol().GetScrY() - width / 2, GetPlayer().GetX() - GetScrol().GetScrX(), GetPlayer().GetY() - GetScrol().GetScrY() + width / 2, WHITE, true);
	}
}

void CWeapon4::Draw() {
	DrawCircle(karix - GetScrol().GetScrX(), kariy - GetScrol().GetScrY(), 3, WHITE, true);
	if (reach == true) {
		DrawCircle(x - GetScrol().GetScrX(), y - GetScrol().GetScrY(), R, RED, true);
	}
}

void CEweapon::Draw() {
	DrawCircle(x - GetScrol().GetScrX(), y - GetScrol().GetScrY(), R, WHITE, true);
}

bool CWeapon::Disappear() {
	return GetEnemyManager().WeaponDisappear(x, y, R);
}

bool CEweapon::Disappear() {
	return GetPlayer().EweaponDisappear(x, y, R);
}

double CWeapon::GetX() {
	return x;
}

double CWeapon::GetY() {
	return y;
}

double CWeapon::GetR() {
	return R;
}

double CWeapon::GetWidth() {
	return width;
}

double CWeapon::GetHeight() {
	return height;
}

double CEweapon::GetX() {
	return x;
}

double CEweapon::GetY() {
	return y;
}

double CEweapon::GetR() {
	return R;
}

bool CWeapon::GetDeleteFlag() {
	return deleteFlag;
}
bool CEweapon::GetDeleteFlag() {
	return deleteFlag;
}

int CWeapon::GetPower() {
	return power;
}

int CEweapon::GetPower() {
	return power;
}

bool CWeapon::GetReach() {
	return reach;
}

CWeaponManager::CWeaponManager() {
	count = 0;
	beamflag = true;
	beamflag2 = false;
	throwpower = 0;
}

CEweaponManager::CEweaponManager() {
	count = 0;
}

void CWeaponManager::Appear(int x,int y) {
	switch (GetPossession().GetWearweapon()) {
	case 1:
	default:
		weapon.push_back(new CWeapon(x, y, 10, 3, 1, GetPlayer().GetRad(0)));
		count = 5;
		break;
	case 2:
		weapon.push_back(new CWeapon(x, y, 10, 3, 1, GetPlayer().GetRad(0)));
		weapon.push_back(new CWeapon(x, y, 10, 3, 1, GetPlayer().GetRad(0) + 10));
		weapon.push_back(new CWeapon(x, y, 10, 3, 1, GetPlayer().GetRad(0) - 10));
		count = 5;
		break;
	case 3:
		weapon.push_back(new CWeapon(x, y - 10, 10, 3, 1, GetPlayer().GetRad(0)));
		weapon.push_back(new CWeapon(x - 10, y, 10, 3, 1, GetPlayer().GetRad(0)));
		weapon.push_back(new CWeapon(x + 10, y, 10, 3, 1, GetPlayer().GetRad(0)));
		count = 5;
		break;
	case 4:
		switch (GetPlayer().GetRad(0)) {
		case 0:
		default:
			weapon.push_back(new CWeapon2(x - 4, y - 30, 8, 30, 15, 1, GetPlayer().GetRad(0)));
			count = 10;
			break;
		case 1:
			weapon.push_back(new CWeapon2(x + 15, y - 4, 30, 8, 15, 1, GetPlayer().GetRad(0)));
			count = 10;
			break;
		case 2:
			weapon.push_back(new CWeapon2(x - 4, y + 15, 8, 30, 15, 1, GetPlayer().GetRad(0)));
			count = 10;
			break;
		case 3:
			weapon.push_back(new CWeapon2(x - 30, y - 4, 30, 8, 15, 1, GetPlayer().GetRad(0)));
			count = 10;
		}
		break;
	case 5:
		weapon.push_back(new CWeapon3(18, 1));
		break;
	case 6:
		switch (GetPlayer().GetRad(0)) {
		case 0:
		default:
			weapon.push_back(new CWeapon4(x, y - throwpower, 6, 80, 1, 50, GetPlayer().GetRad(0)));
			break;
		case 1:
			weapon.push_back(new CWeapon4(x + throwpower, y, 6, 80, 1, 50, GetPlayer().GetRad(0)));
			break;
		case 2:
			weapon.push_back(new CWeapon4(x, y + throwpower, 6, 80, 1, 50, GetPlayer().GetRad(0)));
			break;
		case 3:
			weapon.push_back(new CWeapon4(x - throwpower, y, 6, 80, 1, 50, GetPlayer().GetRad(0)));
			break;
		}
	}
}

void CEweaponManager::Appear(int x, int y) {
	if (GetPossession().GetWearweapon() == 3) {
		eweapon.push_back(new CEweapon(x, y, 10, 1, 0));
		eweapon.push_back(new CEweapon(x, y, 10, 1, 1));
		eweapon.push_back(new CEweapon(x, y, 10, 1, 2));
	}
	else {
		eweapon.push_back(new CEweapon(x - 5, y, 10, 1, 0));
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

void CEweaponManager::Move() {
	for (auto i = eweapon.begin(); i != eweapon.end();) {
		if ((*i)->GetDeleteFlag() == true) {
			i = eweapon.erase(i);
		}
		else {
			i++;
		}
	}
	for (auto i = eweapon.begin(); i != eweapon.end(); i++) {
		(*i)->Move();
	}
}

void CWeaponManager::Draw() {
	for (auto i = weapon.begin(); i != weapon.end(); i++) {
		(*i)->Draw();
	}
	if (GetPossession().GetWearweapon() == 5) {
		if (beamflag == true) {
			DrawBox(GetPlayer().GetX() - GetScrol().GetScrX() - 50, GetPlayer().GetY() - GetScrol().GetScrY() + GetPlayer().GetR() + 10, GetPlayer().GetX() - GetScrol().GetScrX() - 50 + (100 - count), GetPlayer().GetY() - GetScrol().GetScrY() + GetPlayer().GetR() + 20, WHITE, true);
		}
		else {
			DrawBox(GetPlayer().GetX() - GetScrol().GetScrX() - 50, GetPlayer().GetY() - GetScrol().GetScrY() + GetPlayer().GetR() + 10, GetPlayer().GetX() - GetScrol().GetScrX() - 50 + (100 - count), GetPlayer().GetY() - GetScrol().GetScrY() + GetPlayer().GetR() + 20, RED, true);
		}
	}
	if (GetPossession().GetWearweapon() == 6) {
		DrawBox(GetPlayer().GetX() - GetScrol().GetScrX() - 50, GetPlayer().GetY() - GetScrol().GetScrY() + GetPlayer().GetR() + 10, GetPlayer().GetX() - GetScrol().GetScrX() - 50 + throwpower / 3, GetPlayer().GetY() - GetScrol().GetScrY() + GetPlayer().GetR() + 20, WHITE, true);
	}
	DrawFormatString(0, 300, BLUE, "%d", GetPlayer().GetRad(0));
}

void CEweaponManager::Draw() {
	for (auto i = eweapon.begin(); i != eweapon.end(); i++) {
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
	/*if (Input.GetKeyExit(Input.key.Z)) {
		beamflag = false;
	}*/
	if (GetPossession().GetWearweapon() == 5) {
		if (count <= 0) {
			beamflag = true;
		}
		if (count >= 100) {
			beamflag = false;
		}
	}
	if (GetPossession().GetWearweapon() == 6) {
		if (Input.GetKeyDown(Input.key.Z)) {
			if (throwpower < 300) {
				throwpower += 6;
			}
		}
	}
}

void CEweaponManager::Loop() {
	for (auto i = eweapon.begin(); i != eweapon.end(); i++) {
		(*i)->Loop();
	}

	if (count > 0) {
		count--;
	}
}

bool CWeaponManager::Hit(int x, int y,int r) {
	for (auto i = weapon.begin(); i != weapon.end(); i++) {
		if (GetPossession().GetWearweapon() == 1 || GetPossession().GetWearweapon() == 2 || GetPossession().GetWearweapon() == 3) {
			if ((x - (*i)->GetX())*(x - (*i)->GetX()) + (y - (*i)->GetY())*(y - (*i)->GetY()) <= (r + (*i)->GetR()) * (r + (*i)->GetR())) {
				return true;
			}
		}
		else if(GetPossession().GetWearweapon() == 4){
			if (((*i)->GetX() > x - r && (*i)->GetX() < x + r && (*i)->GetY() > y - r && (*i)->GetY() < y + r) || ((*i)->GetX() > x - r - (*i)->GetWidth() && (*i)->GetX() < x + r - (*i)->GetWidth() && (*i)->GetY() > y - r && (*i)->GetY() < y + r) || ((*i)->GetX() > x - r && (*i)->GetX() < x + r && (*i)->GetY() > y - r - (*i)->GetHeight() && (*i)->GetY() < y + r - (*i)->GetHeight()) || ((*i)->GetX() > x - r - (*i)->GetWidth() && (*i)->GetX() < x + r - (*i)->GetWidth() && (*i)->GetY() > y - r - (*i)->GetHeight() && (*i)->GetY() < y + r - (*i)->GetHeight())) {
				return true;
			}
			else if (((*i)->GetX() > x - r && (*i)->GetX() < x + r && (*i)->GetY() < y - r && (*i)->GetY() > y - r - (*i)->GetHeight()) || ((*i)->GetX() > x - r - (*i)->GetWidth() && (*i)->GetX() < x + r - (*i)->GetWidth() && (*i)->GetY() < y - r && (*i)->GetY() > y - r - (*i)->GetHeight())) {
				return true;
			}
		}
		else if (GetPossession().GetWearweapon() == 5) {
			/*if (y <= GetPlayer().GetY()) {
				if (((GetPlayer().GetX() > x - r + (*i)->GetWidth() / 2) && (GetPlayer().GetX() < x + r + (*i)->GetWidth() / 2)) || ((GetPlayer().GetX() > x - r - (*i)->GetWidth() / 2) && (GetPlayer().GetX() < x + r - (*i)->GetWidth() / 2))) {
					return true;
				}
				else if (GetPlayer().GetX() <= x - r + (*i)->GetWidth() / 2 && GetPlayer().GetX() >= x + r - (*i)->GetWidth() / 2) {
					return true;
				}
			}*/
			switch (GetPlayer().GetRad(0)) {
			case 0:
			default:
				if (y <= GetPlayer().GetY()) {
					if (((x > GetPlayer().GetX() - (*i)->GetWidth() / 2 - r) && (x < GetPlayer().GetX() + (*i)->GetWidth() / 2 - r)) || ((x > GetPlayer().GetX() - (*i)->GetWidth() / 2 + r) && (x < GetPlayer().GetX() + (*i)->GetWidth() / 2 + r))) {
						return true;
					}
					else if (x < GetPlayer().GetX() - (*i)->GetWidth() / 2 + r && x > GetPlayer().GetX() + (*i)->GetWidth() / 2 - r) {
						return true;
					}
				}
				break;
			case 1:
				if (x >= GetPlayer().GetX()) {
					if (((y > GetPlayer().GetY() - (*i)->GetWidth() / 2 - r) && (y < GetPlayer().GetY() + (*i)->GetWidth() / 2 - r)) || ((y > GetPlayer().GetY() - (*i)->GetWidth() / 2 + r) && (y < GetPlayer().GetY() + (*i)->GetWidth() / 2 + r))) {
						return true;
					}
					else if (y < GetPlayer().GetY() - (*i)->GetWidth() / 2 + r && y > GetPlayer().GetY() + (*i)->GetWidth() / 2 - r) {
						return true;
					}
				}
				break;
			case 2:
				if (y >= GetPlayer().GetY()) {
					if (((x > GetPlayer().GetX() - (*i)->GetWidth() / 2 - r) && (x < GetPlayer().GetX() + (*i)->GetWidth() / 2 - r)) || ((x > GetPlayer().GetX() - (*i)->GetWidth() / 2 + r) && (x < GetPlayer().GetX() + (*i)->GetWidth() / 2 + r))) {
						return true;
					}
					else if (x < GetPlayer().GetX() - (*i)->GetWidth() / 2 + r && x > GetPlayer().GetX() + (*i)->GetWidth() / 2 - r) {
						return true;
					}
				}
				break;
			case 3:
				if (x <= GetPlayer().GetX()) {
					if (((y > GetPlayer().GetY() - (*i)->GetWidth() / 2 - r) && (y < GetPlayer().GetY() + (*i)->GetWidth() / 2 - r)) || ((y > GetPlayer().GetY() - (*i)->GetWidth() / 2 + r) && (y < GetPlayer().GetY() + (*i)->GetWidth() / 2 + r))) {
						return true;
					}
					else if (y < GetPlayer().GetY() - (*i)->GetWidth() / 2 + r && y > GetPlayer().GetY() + (*i)->GetWidth() / 2 - r) {
						return true;
					}
				}
				break;
			}
		}
		else if (GetPossession().GetWearweapon() == 6) {
			if ((*i)->GetReach() == true) {
				if ((x - (*i)->GetX())*(x - (*i)->GetX()) + (y - (*i)->GetY())*(y - (*i)->GetY()) <= (r + (*i)->GetR()) * (r + (*i)->GetR())) {
					return true;
				}
			
			}
		}
	}
	return false;
}

bool CEweaponManager::Hit(int x, int y, int r) {
	for (auto i = eweapon.begin(); i != eweapon.end(); i++) {
		if ((x - (*i)->GetX())*(x - (*i)->GetX()) + (y - (*i)->GetY())*(y - (*i)->GetY()) <= (r + (*i)->GetR()) * (r + (*i)->GetR())) {
			return true;
		}
	}
	return false;
}

void CWeaponManager::PAttack() {
//	if (Input.GetKeyDown(Input.key.Z)) {
		if (GetPossession().GetWearweapon() == 5) {
			if (beamflag == true) {
				if (beamflag2 == false) {
					beamflag2 = true;
					Appear(GetPlayer().GetX(), GetPlayer().GetY());
				}
				count += 2;
			}
		}
		else if(GetPossession().GetWearweapon() != 6){
			if (count <= 0) {
				Appear(GetPlayer().GetX(), GetPlayer().GetY());
			}
		}
	//}
	//if (Input.GetKeyExit(Input.key.Z)) {
		if (GetPossession().GetWearweapon() == 6) {
			Appear(GetPlayer().GetX(), GetPlayer().GetY());
			throwpower = 0;
		}
	//}
	beamflag2 = false;
}

int CWeaponManager::GetPower() {
	for (auto i = weapon.begin(); i != weapon.end(); i++) {
		return (*i)->GetPower();
	}
}

int CEweaponManager::GetPower() {
	for (auto i = eweapon.begin(); i != eweapon.end(); i++) {
		return (*i)->GetPower();
	}
}

bool CWeaponManager::GetBeamflag() {
	return beamflag;
}