#pragma once

class BaseSword {//基礎ソードクラス

};

class CSword {
private:
//	Anim sword;
	int x, y;
	int R;
	const int power = 1;
	const int knock = 10;
public:
	CSword();
	void Load();
	void Appear(int x,int y);
	void PAttack();
	void Set(int x, int y);
	void Loop();
	void Draw();
	int count;
	int damage;
	bool flag;
	bool Hit(int x, int y, int r);
	int GetPower();
	int GetKnock();
};
