#pragma once
#include "Suken.h"

#include "pub.h"


class CPossession {
private:
public:
	CPossession();
	void Creategun(int a);
	void Createsword(int a);
	void Createarmar(int a);
	void Createitem(int a);
	char *swordname(int a);
	void Loop();
};
