#include "CSGame.h"

CPlayer player;
CWeaponManager weapon;
CEnemyManager enemy;
CSword sword;
CMap map;
CScrol scrol;
CPause pause;
COver over;
CSelect sel;
CClear clear;
CPub pub;
CItemManager item;
CPossession possession;
CObstacleManager obstacle;
extern int DROP;


void CSGame::Start() {
	scrY = map.GetHeight() * 40 - 600;
	scrX = player.GetX() - 300;
	if (stage == 100) {
		type = 0;
	}
	else {
		type = 1;
		enemy.Disappear();
		item.DIsappear();
	}
	retry = false;
	back = false;
	nextstage = false;
	kakunin = 10;
	map.Set(stage);
	map.Load();
	player.Appear();
	over.Load();
	pause.Load();
	sel.Load();
	clear.Load();
	sword.Load();
}

void CSGame::Loop() {
	pub.Loop();

	switch (stage) {
	case 0:
	default:
		DROP = 0;
		break;
	case 1:
	case 2:
	case 3:
		DROP = rand() % 2;
	}

	if (type == 0) {
		sel.Loop();
		possession.Loop();
		if (sel.GetScene() == 2) {
			if (sel.GetCount2() <= 0) {
				if (Input.GetKeyEnter(Input.key.RETURN)) {
					Game.FlipScene(new CSGame(sel.GetStage()), Flip::FADE_OUT_IN);
				}
			}
		}
	}
	if (retry == true) {
		map.FixReset();
		Game.FlipScene(new CSGame(stage), Flip::FADE_OUT_IN);
		retry = false;
	}
	if (back == true) {
		map.FixReset();
		Game.FlipScene(new CSGame(100), Flip::FADE_OUT_IN);
		back = false;
	}
	if (nextstage == true) {
		map.FixReset();
		Game.FlipScene(new CSGame(stage + 1), Flip::FADE_OUT_IN);
		nextstage = false;
	}
	if (type == 1){
		scrol.Loop();

		enemy.Appear();
		if (scrol.GetFixset() == false) {//ƒXƒNƒ[ƒ‹‚ªŒÅ’è‚³‚ê‚é‚Ü‚Å‚ÌŠÔ‚Í“®‚©‚È‚¢
			item.Set();
			item.Loop();
			player.Move();
			player.Loop();
			weapon.PAttack();
			weapon.Loop();
			weapon.Move();
			sword.Loop();
			sword.PAttack();
			enemy.Move();
			enemy.Loop();
			pub.Loop();
			map.Loop();
			obstacle.Appear();
			obstacle.Loop();
		}
	}
	clear.Loop();
	over.Loop();
	pause.Loop();
}

void CSGame::Draw() {
	if (type == 0) {
		sel.Draw();
	}
	else {
		map.Draw();
		obstacle.Draw();
		sword.Draw();
		player.Draw();
		weapon.Draw();
		item.Draw();
		enemy.Draw();
		pause.Draw();
		if (type == 2) {
			over.Draw();
		}
	    clear.Draw();
	}
	pub.Draw();

}

void CSGame::End() {

}

CWeaponManager GetWeaponManager() {
	return weapon;
}

CPlayer GetPlayer() {
	return player;
}

CSword GetSword() {
	return sword;
}

CEnemyManager GetEnemyManager() {
	return enemy;
}


CScrol GetScrol() {
	return scrol;
}

CMap GetMap() {
	return map;
}

CPause GetPause() {
	return pause;
}

CClear GetClear() {
	return clear;
}

CItemManager GetItemManager() {
	return item;
}

CSelect GetSelect() {
	return sel;
}

CPossession GetPossession() {
	return possession;
}

CObstacleManager GetObstacleManager() {
	return obstacle;
}