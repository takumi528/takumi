#include "item.h"

extern Player& GetPlayer();
extern CEnemyManager& GetEnemyManager();
extern CWeaponManager& GetWeaponManager();
extern CMap& GetMap();
extern CScrol& GetScrol();

int eneX, eneY, eneDrop;
int koeneflag, koeneDrop;
extern int fixcount;
extern int fixdelete;

//[]内は種類数
extern int parts[30];//部品
//以下は装備、flagはそれぞれを作成できるかどうか
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
	DrawCircle(x - scrX, y - scrY, R, BLACK, true);
	//explain(x - scrX - 50, y - scrY - 30);
}

void CItem2::Draw() {
	DrawCircle(x - scrX, y - scrY, R, BLACK, true);
}

void CItem3::Draw() {
	DrawCircle(x - scrX, y - scrY, R, RED, true);
}

void CItem::Loop() {
	if (Get() == true) {
	//	if (Input.GetKeyEnter(Input.key.LSHIFT)) {
			parts[1] += drop;
			fixdelete++;
			deleteFlag = true;
	//	}
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
	koeneflag = false;
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
	if (koeneflag == true) {//固定時のドロップアイテムの出現
		switch (koeneDrop) {
		case 0:
		default:
			item.push_back(new CItem(scrX + 300, scrY + 300, 10, rand() % 4 + 3));
			break;
		}
	}
	if (eneX >= 0) {//自由行動時のドロップアイテムの出現
		switch (eneDrop) {
		case 0:
		default:
			item.push_back(new CItem2(eneX, eneY, 5, rand() % 4 + 3));
			break;
		case 1:
			item.push_back(new CItem3(eneX, eneY, 5, rand() % 4 + 3));
			break;
		}
	}
	eneX = -10;
	eneY = -10;
	eneDrop = -10;
	koeneflag = false;
	koeneDrop = -10;
}

void CItemManager::DIsappear() {
	for (auto i = item.begin(); i != item.end(); i++) {
		(*i)->Disappear();
	}
}