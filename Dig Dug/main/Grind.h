#pragma once
#include "Player.h"
#include "Pooka.h";

class Grind
{
private:
	int grind[57][29];
	int enemies;
	Player dig;
	

public:
	Grind();
	
	void map();
	void start();
	void play();
};

