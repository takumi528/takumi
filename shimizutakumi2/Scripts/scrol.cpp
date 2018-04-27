#include "scrol.h"

extern CPlayer GetPlayer();
extern CMap GetMap();

int scr;

CScrol::CScrol() {
}

void CScrol::Loop(){
	if (GetPlayer().GetY() - 300 >= 0) {
		if (GetPlayer().GetY() + scr - (GetMap().GetHeight() * 40 - 600) < 300) {
			scr += GetPlayer().GetV();
		}
	}
	if (GetPlayer().GetY() + 200 <= GetMap().GetHeight() * 40) {
		if (GetPlayer().GetY() + scr - (GetMap().GetHeight() * 40 - 600) > 400) {
			scr -= GetPlayer().GetV();
		}
	}
}