#include "Object.h"

suken::CObject::CObject() {
	deleteFlag = false;
}

void suken::CObject::Delete() {
	deleteFlag = true;
}

bool suken::CObject::GetDeleteFlag() {
	return deleteFlag;
}