#pragma once
class Player
{
private:
	int x = 0, y = 1;
	int id = 2;
public:
	Player();

	void spr(int _grind[57][29], char _key);
	void ers(int _grind[57][29]);
	void mve(int _grind[57][29]);
	void attk(int _grind[57][29], char _key);
	void startAnim(int _grind[57][29]);
};

