#include "possession.h"

//flag‚Íì¬‚Å‚«‚é‚©‚Ç‚¤‚©
int parts[30];
int weapon[30];
bool weaponflag[30];
char weaponname[30][20] = {"a","aa"};
int gunpower[30] = { 1,20,30,20 };
int swordpower[30] = { 1,50 };
int armar[30];
int armarguard[30];
bool armarflag[30];

int wearweapon,weararmar;//‚Ç‚ê‚ğ‘•”õ‚µ‚Ä‚¢‚é‚©

CPossession::CPossession() {
	for (int i = 1; i <= 25; i++) {
		parts[i] = 0;
		weapon[i] = 0;
		weaponflag[i] = false;
		armar[i] = 0;
		armarflag[i] = false;
	}
	wearweapon = 1;
	weararmar = 1;

	parts[1] = 100;

}

void CPossession::Loop() {
	//•Ší‚Ìì¬ğŒ
	if (parts[1] >= 30) {
		weaponflag[1] = true;
	}
	else {
		weaponflag[1] = false;
	}

	//‘•”õ‚Ìì¬ğŒ
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


