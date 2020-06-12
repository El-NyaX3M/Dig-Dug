#pragma once
#include "Player.h"

class Attack
{
private:
	int h, i;
	int id = 4;
public:
	Attack(int _h, int _i);
	void gotoxy(int x, int y);
	void spr(int _grind[57][29], char _key, int x, int y);
	void ers(int _grind[57][29], char _key, int x, int y);

	bool doatk(int _grind[57][29], char _key, int x, int y);

};

