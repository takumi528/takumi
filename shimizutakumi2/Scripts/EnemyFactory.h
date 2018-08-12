#pragma once

#include "ObjectManager.h"
#include "Enemy.h"

class EnemyFactory :public Factory<Enemy> {
	std::shared_ptr<Enemy> Create(std::vector<int>& index) {
		switch (index[0]) {
		case 0:
		default:
			return std::make_shared<Enemy>(index[1], index[2]);
			break;
		}
	}
};