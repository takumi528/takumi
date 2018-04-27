#include "item.h"

extern CPlayer GetPlayer();
extern CEnemyManager GetEnemyManager();
extern CWeaponManager GetWeaponManager();

int eneX, eneY, eneDrop;
extern 	int Pown1, Pown2, Pown3, Pown4;//‚»‚ê‚¼‚ê‚Ì’e‚ÌŠ—L”

//[]“à‚Íí—Ş”
extern int parts[30];//•”•i
//ˆÈ‰º‚Í‘•”õAflag‚Í‚»‚ê‚¼‚ê‚ğì¬‚Å‚«‚é‚©‚Ç‚¤‚©
extern int gun[30];
extern bool gunflag[30];
extern int sword[30];
extern bool swordflag[30];
extern int armar[30];
extern bool armarflag[30];

CItem::CItem() {

}

CItem::CItem(int x, int y, int R, int drop) {
	this->x = x;
	this->y = y;
	this->R = R;
	deleteFlag = false;
	this->drop = drop;
}

CItem2::CItem2(int x, int y, int R, int drop) {
	this->x = x;
	this->y = y;
	this->R = R;
	deleteFlag = false;
	this->drop = drop;
}

CItem3::CItem3(int x, int y, int R, int drop) {
	this->x = x;
	this->y = y;
	this->R = R;
	deleteFlag = false;
	this->drop = drop;
}

void CItem::Draw() {
	DrawCircle(x, y + mapY, R, WHITE, true);
}

void CItem2::Draw() {
	DrawCircle(x, y + mapY, R, BLACK, true);
}

void CItem3::Draw() {
	DrawCircle(x, y + mapY, R, RED, true);
}

void CItem::Loop() {
	if (Get() == true) {
		Pown1 += drop;
		deleteFlag = true;
	}
}

void CItem2::Loop() {
	if (Get() == true) {
		parts[1] += drop;
		deleteFlag = true;
	}
}

void CItem3::Loop() {
	if (Get() == true) {
		parts[2] += drop;
		deleteFlag = true;
	}
}

bool CItem::Get() {
	return GetPlayer().GetItem(x, y, R);
}

bool CItem::GetDeleteFlag() {
	return deleteFlag;
}

void CItem::Disappear() {
	deleteFlag = true;
}

CItemManager::CItemManager() {
	eneX = -10;
	eneY = -10;
	eneDrop = -10;
}

void CItemManager::Draw() {
	for (auto i = item.begin(); i != item.end(); i++) {
		(*i)->Draw();
	}
	DrawFormatString(400, 100, BLACK, "%d", parts[1]);
}

void CItemManager::Loop() {
	for (auto i = item.begin(); i != item.end(); i++) {
		(*i)->Loop();
	}
	for (auto i = item.begin(); i != item.end();) {
		if ((*i)->GetDeleteFlag() == true) {
			i = item.erase(i);
		}
		else {
			i++;
		}
	}
}

void CItemManager::Set() {
	if (eneX >= 0) {
		if (eneDrop == 0) {
			item.push_back(new CItem(eneX, eneY, 5, rand() % 4 + 3));
		}
		else {
			item.push_back(new CItem2(eneX, eneY, 5, rand() % 4 + 3));
		}
	}
	eneX = -10;
	eneY = -10;
	eneDrop = -10;
}

void CItemManager::DIsappear() {
	for (auto i = item.begin(); i != item.end(); i++) {
		(*i)->Disappear();
	}
}