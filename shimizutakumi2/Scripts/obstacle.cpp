#include "obstacle.h"

CObstacle::CObstacle() {}

CObstacle::CObstacle(int x, int y, int r) {
	this->x = x;
	this->y = y;
	this->R = r;
 	deleteFlag = false;
}

void CObstacle::Draw() {
	DrawCircle(x - scrX, y - scrY, R, BLACK, true);
}

void CObstacle::Loop() {

}

void CObstacle::Disappear() {
	deleteFlag = true;
}

bool CObstacle::GetDeleteFlag() {
	return deleteFlag;
}

int CObstacle::GetX() {
	return x;
}

int CObstacle::GetY() {
	return y;
}

int CObstacle::GetR() {
	return R;
}

CObstacleManager::CObstacleManager() {

}

void CObstacleManager::Draw() {
	for (auto i = obstacle.begin(); i != obstacle.end(); i++) {
		(*i)->Draw();
	}
}

void CObstacleManager::Loop() {
	for (auto i = obstacle.begin(); i != obstacle.end(); i++) {
		if ((*i)->GetDeleteFlag()) {
			i = obstacle.erase(i);
		}
	}
	for (auto i = obstacle.begin(); i != obstacle.end(); i++) {
		(*i)->Loop();
	}
}

bool CObstacleManager::Hit(int x, int y, int R) {
	for (auto i = obstacle.begin(); i != obstacle.end(); i++) {
		if (((*i)->GetX() - x)*((*i)->GetX() - x) + ((*i)->GetY() - y)*((*i)->GetY() - y) < ((*i)->GetR() + R)*((*i)->GetR() + R)) {
			return true;
		}
	}
}

void CObstacleManager::Appear() {
	for (int i = 0; i < mce.GetWidth(); i++) {
		for (int j = 0; j < mce.GetHeight(); j++) {
			if (mce.Get(mce.layer.B, i, j) == 2) {
				obstacle.push_back(new CObstacle(i * 40, j * 40, 30));
				mce.Get(mce.layer.B, i, j) = 0;
			}
		}
	}
}

void CObstacleManager::Disappear() {
	for (auto i = obstacle.begin(); i != obstacle.end(); i++) {
	
	}
}