#include "item.h"

extern CPlayer& GetPlayer();
extern CEnemyManager& GetEnemyManager();
extern CWeaponManager& GetWeaponManager();
extern CMap& GetMap();
extern CScrol& GetScrol();
extern CPossession& GetPossession();


CItem::CItem() {

}

CItem::CItem(int x, int y, int R, int drop) {
	this->x = x;
	this->y = y;
	this->R = R;
	deleteFlag = false;
	this->drop = drop;
	explain = "stpic/explain.png";
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
	DrawCircle(x - GetScrol().GetScrX(), y - GetScrol().GetScrY(), R, BLACK, true);
	//explain(x - GetScrol().GetScrX() - 50, y - GetScrol().GetScrY() - 30);
}

void CItem2::Draw() {
	DrawCircle(x - GetScrol().GetScrX(), y - GetScrol().GetScrY(), R, BLACK, true);
}

void CItem3::Draw() {
	DrawCircle(x - GetScrol().GetScrX(), y - GetScrol().GetScrY(), R, RED, true);
}

void CItem::Loop() {
	if (Get() == true) {
	//	if (Input.GetKeyEnter(Input.key.LSHIFT)) {
		GetPossession().PlusParts(1, drop);
			GetMap().FixReset2();
			deleteFlag = true;
	//	}
	}
}

void CItem2::Loop() {
	if (Get() == true) {
		GetPossession().PlusParts(1, drop);
		deleteFlag = true;
	}
}

void CItem3::Loop() {
	if (Get() == true) {
		GetPossession().PlusParts(2, drop);
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
}

void CItemManager::Draw() {
	for (auto i = item.begin(); i != item.end(); i++) {
		(*i)->Draw();
	}

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
	if (GetEnemyManager().GetDkoflag() == true && GetEnemyManager().GetFixcount() <= 0) {//固定時のドロップアイテムの出現
		switch (GetEnemyManager().GetDdrop()) {
		case 0:
		default:
			item.push_back(new CItem(GetScrol().GetScrX() + 300, GetScrol().GetScrY() + 300, 10, rand() % 4 + 3));
			break;
		}
	}
	else {
		if (GetEnemyManager().GetDx() >= 0) {//自由行動時のドロップアイテムの出現
			switch (GetEnemyManager().GetDdrop()) {
			case 0:
			default:
				item.push_back(new CItem2(GetEnemyManager().GetDx(), GetEnemyManager().GetDy(), 5, rand() % 4 + 3));
				break;
			case 1:
				item.push_back(new CItem3(GetEnemyManager().GetDx(), GetEnemyManager().GetDy(), 5, rand() % 4 + 3));
				break;
			}
		}
	}
}

void CItemManager::DIsappear() {
	for (auto i = item.begin(); i != item.end(); i++) {
		(*i)->Disappear();
	}
}