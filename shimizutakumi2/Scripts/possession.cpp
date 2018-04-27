#include "possession.h"

//flag‚ÍŠ—L‚µ‚Ä‚¢‚é‚©‚Ç‚¤‚©
int parts[30];
int gun[30];
int gunpower[30] = { 1,20,30,20 };
bool gunflag[30];
char gunname[30][20];
int sword[30];
int swordpower[30] = { 1,50 };
bool swordflag[30];
char swordname[30][20] = { "a","‚½‚¾‚ÌŒ•" };
int armar[30];
int armarguard[30];
bool armarflag[30];
//ˆÈ‰º‚Í‚»‚ê‚¼‚ê‚Ì•K—v‘fŞ‚Ìà–¾•¶

int weargun,wearsword,weararmar;//‚Ç‚ê‚ğ‘•”õ‚µ‚Ä‚¢‚é‚©

CPossession::CPossession() {
	for (int i = 1; i <= 25; i++) {
		parts[i] = 0;
		gun[i] = 0;
		gunflag[i] = false;
		sword[i] = 0;
		swordflag[i] = false;
		armar[i] = 0;
		armarflag[i] = false;
	}
	weargun = 0;
	wearsword = 0;
	weararmar = 0;

	parts[1] = 100;

}

void CPossession::Loop() {
	//e‚Ìì¬ğŒ
	if (parts[1] >= 30) {
		gunflag[1] = true;
	}
	else {
		gunflag[1] = false;
	}

	//Œ•‚Ìì¬ğŒ
	if (parts[1] >= 20) {
		swordflag[1] = true;
	}
	else {
		swordflag[1] = false;
	}

	//‘•”õ‚Ìì¬ğŒ
	if (parts[1] >= 40) {
		armarflag[1] = true;
	}
	else {
		armarflag[1] = false;
	}
}

void CPossession::Creategun(int a) {
	switch (a) {
	case 1:
	default:
		if (gunflag[1] == true) {
			parts[1] -= 30;
			gun[1] += 1;
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


void CPossession::Createsword(int a) {
	switch (a) {
	case 1:
	default:
		if (swordflag[1] == true) {
			parts[1] -= 20;
			sword[1] += 1;
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


