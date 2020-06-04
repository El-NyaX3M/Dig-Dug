#pragma once
#include "Player.h"
#include "Pooka.h"

class Level_1
{
private:
	
	int level[56][29];
	int enemies = 3;
	
public:
	

	Level_1();

	void erase(int x, int y);
	void print(int x, int y, int id);

};

