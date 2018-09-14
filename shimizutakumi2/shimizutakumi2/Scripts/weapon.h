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
	int direction;//0�`3->player.rad�Ɠ����Arad + 10->�E�΂ߑO�Arad - 10->���΂ߑO

	int explodecount;//�{�����������Ă��鎞��
	bool reach;//�{�������B�����true;
			   //�ȉ��͓����Ă���r���̃{���̍��W(x,y�̓{���̓��B�n�_�̍��W)
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
	bool beamflag;//�r�[���g�������ăV���[�g������false
	bool beamflag2;//�r�[�����o���Ă����true
	int throwpower;//�{���𓊂��鋭��(�{���̓͂��������ϓ�)
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

class CEweapon {//�G�̒e
protected:
	double x, y, v, width, height;
	int R = 3;
	bool deleteFlag;
	int power;
	int direction;//0:���i�A1:�E�΂ߑO�A2:���΂ߑO
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