#pragma once
#include "Suken.h"
#include "player.h"
#include "map.h"

//ŒÅ’è’†‚Ímap‚Åˆ—

class CScrol {
private:
	bool fixset;//ƒXƒNƒ[ƒ‹‚ªŒÅ’è‚³‚ê‚æ‚¤‚Æ‚µ‚Ä‚¢‚é‚Æ‚«‚Ítrue
	int scrX;
	int scrY;
public:
	CScrol();
	void Loop();
	void ScrSet();//CSGame‚Åscr‚ğ‰Šú‰»
	bool GetFixset();
	int GetScrX();
	int GetScrY();
};