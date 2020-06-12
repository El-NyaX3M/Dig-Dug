#pragma once
#include "Attack.h"
#include "Kougeki.h"
class Player
{
private:
	int x = 0, y = 1;
	int dx, dy;
	Kougeki attack;
	int id = 2;
	char _key = 75;
	bool ded = false;
	bool doinAtk = false;
public:
	Player();
	void spr(int _grind[57][29], char _key);
	void ers(int _grind[57][29]);

	void mve(int _grind[57][29]);
	void datk(int _grind[57][29]);
	bool die(int _grind[57][29]);
	void restart(int _grind[57][29]);
	void setxy();
	void danim();
	
	void startAnim(int _grind[57][29]);
};

