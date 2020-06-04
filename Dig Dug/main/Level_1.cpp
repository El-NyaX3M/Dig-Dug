#include "Level_1.h"
#include "Player.h"
#include "Pooka.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;


Level_1::Level_1() {
    
    for (int y = 0; y < 29; y++) {
        for (int x = 0; x < 56; x++) {
            if (y < 2) {
                level[x][y] = 0;
            }
            else {
                level[x][y] = 1;
            }
        }
    }
}

void Level_1::erase(int x, int y) {
    level[x][y] = 0;
    level[x + 1][y] = 0;
    level[x + 2][y] = 0;
    level[x][y + 1] = 0;
    level[x + 1][y + 1] = 0;
    level[x + 2][y + 1] = 0;
}

void Level_1::print(int x, int y, int id) {
    level[x][y] = id;
    level[x+1][y] = id;
    level[x+2][y] = id;
    level[x][y+1] = id;
    level[x+1][y+1] = id;
    level[x+2][y+1] = id;
}

