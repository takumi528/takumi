#include "MyScene.h"
#include "MyTask.h"

#include <sstream>//•¶Žš—ñ‚Ì˜AŒ‹‚ª‚Å‚«‚Ü‚·

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
	
	task.RegisterTask(new ScrolTask(&scrol, player.get(), &map));
//	task.RegisterTask(new TestScrolTask(&scrol));
}

void CSGame::Loop() {
	player->Loop();
	player->Move();
	task.Main();
	if (Input.GetKeyEnter(Input.key.BACK))
		Game.FlipScene(new CSHome());
}

void CSGame::Draw() {
	int x = scrol.GetScrX();
	int y = scrol.GetScrY();
	map.Draw(x, y);
	player->Draw(x, y);
}

void CSGame::End() {

}