#pragma once
class Pooka
{
private:
	int x, y;
	int dx, dy;
	int id = 3;
	int pts = 150;
	int health = 3;

	int dir = 2;
	int speed, count = 0;
	bool alive = true;


public:
	Pooka();
	void gotoxy(int _x, int _y);
	void setr(int spd);
	void spr(int _grind[57][29]);
	void ers(int _grind[57][29]);

	void mve(int _grind[57][29]);
	void active(int _grind[57][29]);
	int check(int _grind[57][29]);
	void restart(int _grind[57][29]);
};

