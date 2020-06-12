#pragma once
class Kougeki
{
private:
	int c = 0;
	int id = 4;
public:
	Kougeki();
	void gotoxy(int x, int y);
	void spr(int _grind[57][29], char _key, int x, int y);
	void ers(int _grind[57][29], char _key, int x, int y);

	bool doatk(int _grind[57][29], char _key, int x, int y);

};

