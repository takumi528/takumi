#include "possession.h"

//flagは作成できるかどうか
int parts[30];
int weapon[30];
bool weaponflag[30];
char weaponname[30][20] = { "a","aa" };
int gunpower[30] = { 1,20,20,10,5,5,10 };
int swordpower[30] = { 1,50,50,50,50,50,50 };
int armar[30];
int armarguard[30];
bool armarflag[30];

int wearweapon, weararmar;//どれを装備しているか

CPossession::CPossession() {
	for (int i = 1; i <= 25; i++) {
		parts[i] = 0;
		weapon[i] = 1;
		weaponflag[i] = false;
		armar[i] = 1;
		armarflag[i] = false;
	}
	wearweapon = 1;
	weararmar = 1;

	parts[1] = 100;

}

void CPossession::Loop() {
	//武器の作成条件
	if (parts[1] >= 30) {
		weaponflag[1] = true;
	}
	else {
		weaponflag[1] = false;
	}

	//装備の作成条件
	if (parts[1] >= 40) {
		armarflag[1] = true;
	}
	else {
		armarflag[1] = false;
	}
}

void CPossession::Createweapon(int a) {
	switch (a) {
	case 1:
	default:
		if (weaponflag[1] == true) {
			parts[1] -= 30;
			weapon[1] += 1;
		}
		break;
	/*case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:*/

	}
}

void CPossession::Createarmar(int a) {
	switch (a) {
	case 1:
	default:
		if (armarflag[1] == true) {
			parts[1] -= 40;
			armar[1] += 1;
		}
		break;
	/*case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:*/
	}
}


void CPossession::Createitem(int a) {
	switch (a) {
	case 1:
	default:
		break;
	case 2:
		break;
	/*case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:*/
	}
}

int CPossession::GetWearweapon() {
	return wearweapon;
}

int CPossession::GetWeararmar() {
	return weararmar;
}

int CPossession::GetGunpower(int a) {
	return gunpower[a];
}

int CPossession::GetSwordpower(int a) {
	return swordpower[a];
}

int CPossession::GetArmarguard(int a) {
	return armarguard[a];
}

int CPossession::GetArmar(int a) {
	return armar[a];
}

int CPossession::GetWeapon(int a) {
	return weapon[a];
}

int CPossession::GetParts(int a){
	return parts[a];
}

bool CPossession::GetArmarflag(int a) {
	return armarflag[a];
}

bool CPossession::GetWeaponflag(int a) {
	return weaponflag[a];
}

void CPossession::PlusParts(int a, int b) {
	parts[a] += b;
}