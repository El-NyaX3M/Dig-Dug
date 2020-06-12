#include "Attack.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;

Attack::Attack(int _h, int _i) {
    h = _h;
    i = _i;
}

void Attack::gotoxy(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void Attack::spr(int _grind[57][29], char _key, int x, int y) {
    if (_key == 75 && x - 1 > 1 && (_grind[x - h][y] != 1 && _grind[x - h][y] != 8)) {
        //x--;
        gotoxy(x - h, y + 1); printf("*");
        _grind[x - h][y] = id;
    }
    if (_key == 77 && x + 2 < 55 && (_grind[x + h + 2][y] != 1 && _grind[x + h + 2][y] != 8)) {
        //x++;
        gotoxy(x + h + 2, y + 1); printf("*");
        _grind[x + h + 2][y] = id;
    }
    if (_key == 72 && y - 1 > 0 && (_grind[x + 1][y - h - 1] != 1 && _grind[x + 1][y - h - 1] != 8)) {
        //y--;
        gotoxy(x + 1, y - h); printf("*");
        _grind[x + 1][y - h - 1] = id;
    }
    if (_key == 80 && y + 1 < 27 && (_grind[x + h][y + h] != 1 && _grind[x + 1][y + h] != 8)) {
        //y++;
        gotoxy(x + 1, y + h + 1); printf("*");
        _grind[x + 1][y + h] = id;
    }
}

void Attack::ers(int _grind[57][29], char _key, int x, int y) {
    if (_key == 75 && x - 1 > 1) {
        //x--;
        gotoxy(x - i, y + 1); printf(" ");
        _grind[x - i][y] = 0;
    }
    if (_key == 77 && x + 2 < 55) {
        //x++;
        gotoxy(x + i + 2, y + 1); printf(" ");
        _grind[x + i + 2][y] = 0;
    }
    if (_key == 72 && y - 1 > 0) {
        //y--;
        gotoxy(x + 1, y - i); printf(" ");
        _grind[x + 1][y - i - 1] = 0;
    }
    if (_key == 80 && y + 1 < 27) {
        //y++;
        gotoxy(x + 1, y + i + 1); printf(" ");
        _grind[x + 1][y + i] = 0;
    }
}

bool Attack::doatk(int _grind[57][29], char _key, int x, int y) {
    if (h < 2) {
        spr(_grind, _key, x, y);
        return true;
    }
    else if (i > 0) {
        ers(_grind, _key, x, y);
        return true;
    }
    else {
        return false;
    }
}