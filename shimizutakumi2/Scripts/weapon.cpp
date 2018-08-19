
#include "weapon.h"
extern Player& GetPlayer();
extern CMap& GetMap();
extern CEnemyManager& GetEnemyManager();

extern int Wsignal;
extern int wearweapon;

bool beamflag;//ビーム使いすぎてショートしたらfalse
bool beamflag2;//ビームを出している間true
int throwpower;//ボムを投げる強さ(ボムの届く距離が変動)

//CWeapon::CWeapon() {
//
//}
//
//CEweapon::CEweapon() {
//
//}
//
//CWeapon::CWeapon(int x,int y,int v,int R,int power,int direction) {
//	this->x = x;
//	this->y = y;
//	this->v = v;
//	this->R = R;
//	this->power = power;
//	this->direction = direction;
//	deleteFlag = false;
//}
//
//CWeapon2::CWeapon2(int x, int y, int width, int height, int v, int power) {
//	this->x = x;
//	this->y = y;
//	this->width = width;
//	this->height = height;
//	this->v = v;
//	this->power = power;
//	this->R = 0;
//	deleteFlag = false;
//}
//
//CWeapon3::CWeapon3(int width, int power) {
//	this->width = width;
//	this->power = power;
//	this->R = 0;
//	deleteFlag = false;
//}
//
//CWeapon4::CWeapon4(int x, int y, int v, int R, int power, int explodecount) {
//	this->x = x;
//	this->y = y;
//	this->v = v;
//	this->R = R;
//	this->power = power;
//	this->explodecount = explodecount;
//	deleteFlag = false;
////	karix = GetPlayer().GetX();
//	kariy = GetPlayer().GetY();
//	reach = false;
//}
//
//CEweapon::CEweapon(int x, int y, int v, int power, int direction) {
//	this->x = x;
//	this->y = y;
//	this->v = v;
//	this->power = power;
//	this->direction = direction;
//	deleteFlag = false;
//}
//
//
//void CWeapon::Move() {
//	if (direction == 0) {
//		y -= v;
//	}
//	if (direction == 1) {
//		y -= v * 0.8;
//		x += v * 0.5;
//	}
//	if (direction == 2) {
//		y -= v * 0.8;
//		x -= v * 0.5;
//	}
//}
//
//void CWeapon2::Move() {
//	y -= v;
//}
//
//void CWeapon3::Move() {}
//
//void CWeapon4::Move() {
//	if (kariy > y) {
//		kariy -= v;
//	}
//	if (kariy < y) {
//		kariy = y;
//	}
//}
//
//void CEweapon::Move() {
//	if (direction == 0) {
//		y -= v;
//	}
//	if (direction == 1) {
//		y -= v;
//		x += v / 2;
//	}
//	if (direction == 2) {
//		y -= v;
//		x -= v / 2;
//	}
//}
//
//void CWeapon::Loop() {
//	if (y - scrY < 0 || Disappear() == true) {
//		deleteFlag = true;
//	}
//}
//
//void CWeapon2::Loop() {
//	if (y + height - scrY < 0) {
//		deleteFlag = true;
//	}
//}
//
//void CWeapon3::Loop() {
//	if (beamflag == false || Input.GetKeyExit(Input.key.Z)) {
//		deleteFlag = true;
//	}
//}
//
//void CWeapon4::Loop() {
//	if (kariy == y) {
//		reach = true;
//	}
//	if (reach == true && explodecount > 0) {
//		explodecount--;
//	}
//	if (reach == true && explodecount <= 0) {
//		deleteFlag = true;
//	}
//}
//
//void CEweapon::Loop() {
//	if (y - scrY < 0 || Disappear() == true) {
//		deleteFlag = true;
//	}
//}
//
//void CWeapon::Draw() {
//	DrawCircle(x - scrX, y - scrY, R, WHITE, true);
//}
//
//void CWeapon2::Draw() {
//	DrawBox(x - scrX, y - scrY, x - scrX + width, y - scrY + height, WHITE, true);
//}
//
//void CWeapon3::Draw() {
////	DrawBox(GetPlayer().GetX() - scrX - width / 2, 0, GetPlayer().GetX() - scrX + width / 2, GetPlayer().GetY() - scrY, WHITE, true);
//}
//
//void CWeapon4::Draw() {
//	DrawCircle(karix - scrX, kariy - scrY, 3, WHITE, true);
//	if (reach == true) {
//		DrawCircle(x - scrX, y - scrY, R, RED, true);
//	}
//}
//
//void CEweapon::Draw() {
//	DrawCircle(x - scrX, y - scrY, R, WHITE, true);
//}
//
//bool CWeapon::Disappear() {
//	return GetEnemyManager().WeaponDisappear(x, y, R);
//}
//
//bool CEweapon::Disappear() {
//	return GetPlayer().EweaponDisappear(x, y, R);
//}
//
//double CWeapon::GetX() {
//	return x;
//}
//
//double CWeapon::GetY() {
//	return y;
//}
//
//double CWeapon::GetR() {
//	return R;
//}
//
//double CWeapon::GetWidth() {
//	return width;
//}
//
//double CWeapon::GetHeight() {
//	return height;
//}
//
//double CEweapon::GetX() {
//	return x;
//}
//
//double CEweapon::GetY() {
//	return y;
//}
//
//double CEweapon::GetR() {
//	return R;
//}
//
//bool CWeapon::GetDeleteFlag() {
//	return deleteFlag;
//}
//bool CEweapon::GetDeleteFlag() {
//	return deleteFlag;
//}
//
//int CWeapon::GetPower() {
//	return power;
//}
//
//int CEweapon::GetPower() {
//	return power;
//}
//
//bool CWeapon::GetReach() {
//	return reach;
//}
//
//CWeaponManager::CWeaponManager() {
//	count = 0;
//	beamflag = true;
//	beamflag2 = false;
//	throwpower = 0;
//}
//
//CEweaponManager::CEweaponManager() {
//	count = 0;
//}
//
//void CWeaponManager::Appear(int x,int y) {
//	switch (wearweapon) {
//	case 1:
//	default:
//		weapon.push_back(new CWeapon(x, y, 10, 3, 1, 0));
//		count = 5;
//		break;
//	case 2:
//		weapon.push_back(new CWeapon(x, y, 10, 3, 1, 0));
//		weapon.push_back(new CWeapon(x, y, 10, 3, 1, 1));
//		weapon.push_back(new CWeapon(x, y, 10, 3, 1, 2));
//		count = 5;
//		break;
//	case 3:
//		weapon.push_back(new CWeapon(x, y - 10, 10, 3, 1, 0));
//		weapon.push_back(new CWeapon(x - 10, y, 10, 3, 1, 0));
//		weapon.push_back(new CWeapon(x + 10, y, 10, 3, 1, 0));
//		count = 5;
//		break;
//	case 4:
//		weapon.push_back(new CWeapon2(x - 4, y - 30, 8, 30, 15, 1));
//		count = 10;
//		break;
//	case 5:
//		weapon.push_back(new CWeapon3(18, 1));
//		break;
//	case 6:
//		weapon.push_back(new CWeapon4(x, y - throwpower, 10, 80, 1, 50));
//		break;
//	}
//}
//
//void CEweaponManager::Appear(int x, int y) {
//	if (wearweapon == 3) {
//		eweapon.push_back(new CEweapon(x, y, 10, 1, 0));
//		eweapon.push_back(new CEweapon(x, y, 10, 1, 1));
//		eweapon.push_back(new CEweapon(x, y, 10, 1, 2));
//	}
//	else {
//		eweapon.push_back(new CEweapon(x - 5, y, 10, 1, 0));
//	}
//}
//
//void CWeaponManager::Move() {
//	for (auto i = weapon.begin(); i != weapon.end();) {
//		if ((*i)->GetDeleteFlag() == true) {
//			i = weapon.erase(i);
//		}
//		else {
//			i++;
//		}
//	}
//	for (auto i = weapon.begin(); i != weapon.end(); i++) {
//		(*i)->Move();
//	}
//}
//
//void CEweaponManager::Move() {
//	for (auto i = eweapon.begin(); i != eweapon.end();) {
//		if ((*i)->GetDeleteFlag() == true) {
//			i = eweapon.erase(i);
//		}
//		else {
//			i++;
//		}
//	}
//	for (auto i = eweapon.begin(); i != eweapon.end(); i++) {
//		(*i)->Move();
//	}
//}
//
//void CWeaponManager::Draw() {
//	for (auto i = weapon.begin(); i != weapon.end(); i++) {
//		(*i)->Draw();
//	}
//	if (wearweapon == 5) {
//		if (beamflag == true) {
////			DrawBox(GetPlayer().GetX() - scrX - 50, GetPlayer().GetY() - scrY + GetPlayer().GetR() + 10, GetPlayer().GetX() - scrX - 50 + (100 - count), GetPlayer().GetY() - scrY + GetPlayer().GetR() + 20, WHITE, true);
//		}
//		else {
////			DrawBox(GetPlayer().GetX() - scrX - 50, GetPlayer().GetY() - scrY + GetPlayer().GetR() + 10, GetPlayer().GetX() - scrX - 50 + (100 - count), GetPlayer().GetY() - scrY + GetPlayer().GetR() + 20, RED, true);
//		}
//	}
//	if (wearweapon == 6) {
////		DrawBox(GetPlayer().GetX() - scrX - 50, GetPlayer().GetY() - scrY + GetPlayer().GetR() + 10, GetPlayer().GetX() - scrX - 50 + throwpower / 3, GetPlayer().GetY() - scrY + GetPlayer().GetR() + 20, WHITE, true);
//	}
//	DrawFormatString(0, 300, BLUE, "%d", count);
//}
//
//void CEweaponManager::Draw() {
//	for (auto i = eweapon.begin(); i != eweapon.end(); i++) {
//		(*i)->Draw();
//	}
//}
//
//void CWeaponManager::Loop() {
//	for (auto i = weapon.begin(); i != weapon.end(); i++) {
//		(*i)->Loop();
//	}
//
//	if (count > 0) {
//		count--;
//	}
//	/*if (Input.GetKeyExit(Input.key.Z)) {
//		beamflag = false;
//	}*/
//	if (wearweapon == 5) {
//		if (count <= 0) {
//			beamflag = true;
//		}
//		if (count >= 100) {
//			beamflag = false;
//		}
//	}
//	if (wearweapon == 6) {
//		if (Input.GetKeyDown(Input.key.Z)) {
//			if (throwpower < 300) {
//				throwpower += 6;
//			}
//		}
//	}
//}
//
//void CEweaponManager::Loop() {
//	for (auto i = eweapon.begin(); i != eweapon.end(); i++) {
//		(*i)->Loop();
//	}
//
//	if (count > 0) {
//		count--;
//	}
//}
//
//bool CWeaponManager::Hit(int x, int y,int r) {
//	for (auto i = weapon.begin(); i != weapon.end(); i++) {
//		if (wearweapon == 1 || wearweapon == 2 || wearweapon == 3) {
//			if ((x - (*i)->GetX())*(x - (*i)->GetX()) + (y - (*i)->GetY())*(y - (*i)->GetY()) <= (r + (*i)->GetR()) * (r + (*i)->GetR())) {
//				return true;
//			}
//		}
//		else if(wearweapon == 4){
//			if (((*i)->GetX() > x - r && (*i)->GetX() < x + r && (*i)->GetY() > y - r && (*i)->GetY() < y + r) || ((*i)->GetX() > x - r - (*i)->GetWidth() && (*i)->GetX() < x + r - (*i)->GetWidth() && (*i)->GetY() > y - r && (*i)->GetY() < y + r) || ((*i)->GetX() > x - r && (*i)->GetX() < x + r && (*i)->GetY() > y - r - (*i)->GetHeight() && (*i)->GetY() < y + r - (*i)->GetHeight()) || ((*i)->GetX() > x - r - (*i)->GetWidth() && (*i)->GetX() < x + r - (*i)->GetWidth() && (*i)->GetY() > y - r - (*i)->GetHeight() && (*i)->GetY() < y + r - (*i)->GetHeight())) {
//				return true;
//			}
//			else if (((*i)->GetX() > x - r && (*i)->GetX() < x + r && (*i)->GetY() < y - r && (*i)->GetY() > y - r - (*i)->GetHeight()) || ((*i)->GetX() > x - r - (*i)->GetWidth() && (*i)->GetX() < x + r - (*i)->GetWidth() && (*i)->GetY() < y - r && (*i)->GetY() > y - r - (*i)->GetHeight())) {
//				return true;
//			}
//		}
//		else if (wearweapon == 5) {
//			if (y <= GetPlayer().GetY()) {
////				if (((GetPlayer().GetX() > x - r + (*i)->GetWidth() / 2) && (GetPlayer().GetX() < x + r + (*i)->GetWidth() / 2)) || ((GetPlayer().GetX() > x - r - (*i)->GetWidth() / 2) && (GetPlayer().GetX() < x + r - (*i)->GetWidth() / 2))) {
//					return true;
//				}
//				else if (GetPlayer().GetX() <= x - r + (*i)->GetWidth() / 2 && GetPlayer().GetX() >= x + r - (*i)->GetWidth() / 2) {
//					return true;
//				}
//			}
//		}
//		else if (wearweapon == 6) {
//			if ((*i)->GetReach() == true) {
//				if ((x - (*i)->GetX())*(x - (*i)->GetX()) + (y - (*i)->GetY())*(y - (*i)->GetY()) <= (r + (*i)->GetR()) * (r + (*i)->GetR())) {
//					return true;
//				}
//			
//			}
//		}
//	}
//	return false;
//}
//
//bool CEweaponManager::Hit(int x, int y, int r) {
//	for (auto i = eweapon.begin(); i != eweapon.end(); i++) {
//		if ((x - (*i)->GetX())*(x - (*i)->GetX()) + (y - (*i)->GetY())*(y - (*i)->GetY()) <= (r + (*i)->GetR()) * (r + (*i)->GetR())) {
//			return true;
//		}
//	}
//	return false;
//}
//
//void CWeaponManager::PAttack() {
//	if (Input.GetKeyDown(Input.key.Z)) {
//		if (wearweapon == 5) {
//			if (beamflag == true) {
//				if (beamflag2 == false) {
//					beamflag2 = true;
////					Appear(GetPlayer().GetX(), GetPlayer().GetY());
//				}
//				count += 2;
//			}
//		}
//		else if(wearweapon != 6){
//			if (count <= 0) {
////				Appear(GetPlayer().GetX(), GetPlayer().GetY());
//			}
//		}
//	}
//	if (Input.GetKeyExit(Input.key.Z)) {
//		if (wearweapon == 6) {
////			Appear(GetPlayer().GetX(), GetPlayer().GetY());
//			throwpower = 0;
//		}
//	}
//	beamflag2 = false;
//}
//
//int CWeaponManager::GetPower() {
//	for (auto i = weapon.begin(); i != weapon.end(); i++) {
//		return (*i)->GetPower();
//	}
//}
//
//int CEweaponManager::GetPower() {
//	for (auto i = eweapon.begin(); i != eweapon.end(); i++) {
//		return (*i)->GetPower();
//	}
//}