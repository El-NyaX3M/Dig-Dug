#pragma once
#include <time.h>
class Rock
{
private:
	int x, y, count = 0, count1 = 0;
	bool active = false;
	int id = 8;
public:
	Rock();

	void setr();
	void gotoxy(int _x, int _y);
	void spr(int _grind[57][29]);
	void ers(int _grind[57][29]);

	void check(int _grind[57][29]);
	void fall(int _grind[57][29]);
	void disap(int _grind[57][29]);
};

