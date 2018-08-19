#include "Collision.h"

bool Sector::Hit(Circle* c) {
	return JudgeHit(*c, *this);
}