#pragma once
#include "Player.h"
#include "Pooka.h"
#include "Rock.h"

class Grind
{
private:
	int grind[57][29];
	int enemies = 3, enemiesL, rocks = 3;
	int level = 1;
	int lives = 3, score = 0;
	int spd = 15;
	Player dig;
	Rock rock[3];
	Pooka pooka[100];
	bool die = false;
	

public:
	Grind();
	
	void map();
	void start();
	void restart();
	void nextlevel();
	bool play();
};

