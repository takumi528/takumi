#include "pub.h"

extern CMap& GetMap();

MCE mce;


void CPub::Loop() {
	if (kakunin > 0) {
		kakunin--;
	}
}

void CPub::Draw() {
	if (kakunin > 0) {
		DrawFormatString(0, 500, RED, "OK");
	}
}

int CPub::GetType() {
	return  type;
}

bool CPub::GetBack() {
	return back;
}

bool CPub::GetNextstage() {
	return nextstage;
}

bool CPub::GetRetry() {
	return retry;
}

void CPub::Changeback(int a) {
	if (a == 1) {
		back = true;
	}
	else {
		back = false;
	}
}

void CPub::Changeretry(int a) {
	if (a == 1) {
		retry = true;
	}
	else {
		retry = false;
	}
}

void CPub::Changenextstage(int a) {
	if (a == 1) {
		nextstage = true;
	}
	else {
		nextstage = false;
	}
}

void CPub::Changetype(int a) {
	type = a;
}