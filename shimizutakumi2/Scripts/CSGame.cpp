#include "MyScene.h"
#include "MyTask.h"

#include <sstream>//文字列の連結ができます

class TestScrolTask :public Task {
public:
	TestScrolTask(Scrol* scrol) :scrol(scrol) {

	}
	void Main() {
		if (Input.GetKeyEnter(Input.key.RETURN)) {
			if (!scrol->SetFix(400, 400))
				scrol->RemoveFix();
		}
	}

private:
	Scrol *scrol;
};

CSGame::CSGame(int stage) :stage(stage) {
	
}

void CSGame::Start() {
	std::stringstream ss;
	ss << "MCE/stage" << stage << ".mce";
	int px = 0, py = 0;
	map.Set(ss.str().c_str(), px, py);
	player.reset(new Player(px, py));

	enemy.SetFactory(new EnemyFactory());

	task.RegisterTask(new ScrolTask(&scrol, player.get(), &map));
	task.RegisterTask(new LoadMapTask(&map, &scrol, &enemy));
	task.RegisterTask(new HitTask(player.get(), &enemy, &map));
	task.RegisterTask(new TestScrolTask(&scrol));
}

void CSGame::Loop() {
	enemy.Update();
	
	player->Loop();

	task.Main();

	player->Move();

	if (Input.GetKeyEnter(Input.key.BACK))
		Game.FlipScene(new CSHome());
}

void CSGame::Draw() {
	int x = scrol.GetScrX();
	int y = scrol.GetScrY();
	Graph::SetShift(x, y);//Graphを使った描画の座標をすべてずらせます。
	map.Draw(x, y);
	enemy.Do(&Enemy::Draw);
	player->Draw();
	Graph::SetShift(0, 0);
}

void CSGame::End() {

}