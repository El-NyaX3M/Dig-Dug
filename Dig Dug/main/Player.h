#pragma once
class Player
{
private:
	int x, y;
public:
	Player(int _x, int _y);

	void spr();
	void ers();
	void mve();

	void startAnim();
};

