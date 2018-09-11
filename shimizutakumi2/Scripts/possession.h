#pragma once
#include "Suken.h"

#include "pub.h"


class CPossession {
private:
public:
	CPossession();
	void Createweapon(int a);
	void Createarmar(int a);
	void Createitem(int a);
	void Loop();
	int GetWearweapon();
	int GetWeararmar();
	int GetGunpower(int a);
	int GetSwordpower(int a);
	int GetArmarguard(int a);
	int GetArmar(int a);
	int GetWeapon(int a);
	int GetParts(int a);
	bool GetArmarflag(int a);
	bool GetWeaponflag(int a);
	void PlusParts(int a, int b);
};
