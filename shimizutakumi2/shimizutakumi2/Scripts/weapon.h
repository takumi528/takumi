#pragma once
#include "Suken.h"
#include "player.h"
#include "enemy.h"
#include "scrol.h"
#include "pub.h"
#include "item.h"
#include "possession.h"



class CWeapon {
protected:
	double x, y, v, width, height;
	int R;
	bool deleteFlag;
	int power;
	int direction;//0～3->player.radと同じ、rad + 10->右斜め前、rad - 10->左斜め前

	int explodecount;//ボムが爆発している時間
	bool reach;//ボムが到達するとtrue;
			   //以下は投げている途中のボムの座標(x,yはボムの到達地点の座標)
	double karix;
	double kariy;
public:
	CWeapon();
	CWeapon(int x,int y,int v,int R, int power, int direction);
	virtual void Move();
	virtual void Loop();
	virtual void Draw();
	bool Disappear();
	double GetX();
	double GetY();
	double GetR();
	double GetWidth();
	double GetHeight();
	bool GetDeleteFlag();
	bool GetReach();
	int GetPower();
};

class CWeapon2 :public CWeapon {
private:
public:
	CWeapon2(int x, int y, int width, int heght, int v, int power, int direction);
	void Move();
	void Draw();
	void Loop();
};

class CWeapon3 :public CWeapon {
private:
public:
	CWeapon3(int width, int power);
	void Move();
	void Draw();
	void Loop();
};

class CWeapon4 :public CWeapon {
private:
public:
	CWeapon4(int x, int y, int v, int R, int power, int explodecount,int direction);
	void Move();
	void Draw();
	void Loop();
};

class CWeaponManager {
private:
	std::list<CWeapon*> weapon;
	bool beamflag;//ビーム使いすぎてショートしたらfalse
	bool beamflag2;//ビームを出している間true
	int throwpower;//ボムを投げる強さ(ボムの届く距離が変動)
public:
	CWeaponManager();
	void Appear(int x,int y);
	void Move();
	void Draw();
	void Loop();
	int count;
	bool Hit(int x, int y,int r);
	void PAttack();
	int GetPower();
	bool GetBeamflag();
};

class CEweapon {//敵の弾
protected:
	double x, y, v, width, height;
	int R = 3;
	bool deleteFlag;
	int power;
	int direction;//0:直進、1:右斜め前、2:左斜め前
public:
	CEweapon();
	CEweapon(int x, int y, int v, int power, int direction);
	virtual void Move();
	virtual void Loop();
	virtual void Draw();
	bool Disappear();
	double GetX();
	double GetY();
	double GetR();
	bool GetDeleteFlag();
	int GetPower();
};

class CEweaponManager {
private:
	std::list<CEweapon*> eweapon;
public:
	CEweaponManager();
	void Appear(int x, int y);
	void Move();
	void Draw();
	void Loop();
	int count;
	bool Hit(int x, int y, int r);
	//void PAttack();
	int GetPower();


};