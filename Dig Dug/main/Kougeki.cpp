#include "Kougeki.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;
 
Kougeki::Kougeki() {

}

void Kougeki::gotoxy(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void Kougeki::spr(int _grind[57][29], char _key, int x, int y) {
    printf("\033[0;32m");
    if (_key == 75 && x - 1 > 1 && (_grind[x - 1][y] != 1 && _grind[x - 1][y] != 8)) {
        //x--;
        gotoxy(x - 1, y + 1); printf("*");
        _grind[x - 1][y] = id;
        if (x - 2 > 1 && (_grind[x - 2][y] != 1 && _grind[x - 2][y] != 8)) {
            gotoxy(x - 2, y + 1); printf("*");
            _grind[x - 2][y] = id;
            if (x - 3 > 1 && (_grind[x - 3][y] != 1 && _grind[x - 3][y] != 8)) {
                gotoxy(x - 3, y + 1); printf("*");
                _grind[x - 3][y] = id;
            }
        }
    }

    if (_key == 77 && x + 2 < 55 && (_grind[x + 3][y] != 1 && _grind[x + 3][y] != 8)) {
        //x++;
        gotoxy(x + 3, y + 1); printf("*");
        _grind[x + 3][y] = id;
        if (x + 3 < 55 && (_grind[x + 4][y] != 1 && _grind[x + 4][y] != 8)) {
            gotoxy(x + 4, y + 1); printf("*");
            _grind[x + 4][y] = id;
            if (x + 4 < 55 && (_grind[x + 5][y] != 1 && _grind[x + 5][y] != 8)) {
                gotoxy(x + 5, y + 1); printf("*");
                _grind[x + 5][y] = id;
            }
        }
    }

    if (_key == 72 && y - 1 > 0 && (_grind[x + 1][y - 2] != 1 && _grind[x + 1][y - 2] != 8)) {
        //y--;
        gotoxy(x + 1, y - 1); printf("*");
        _grind[x + 1][y - 2] = id;
        if (y - 2 > 0 && (_grind[x + 1][y - 3] != 1 && _grind[x + 1][y - 3] != 8)) {
            gotoxy(x + 1, y - 2); printf("*");
            _grind[x + 1][y - 3] = id;
            if (y - 3 > 0 && (_grind[x + 1][y - 4] != 1 && _grind[x + 1][y - 4] != 8)) {
                gotoxy(x + 1, y - 3); printf("*");
                _grind[x + 1][y - 4] = id;
            }
        }
    }

    if (_key == 80 && y + 1 < 27 && (_grind[x + 1][y + 1] != 1 && _grind[x + 1][y + 1] != 8)) {
        //y++;
        gotoxy(x + 1, y + 2); printf("*");
        _grind[x + 1][y + 1] = id;
        if (y + 2 < 27 && (_grind[x + 1][y + 2] != 1 && _grind[x + 1][y + 2] != 8)) {
            gotoxy(x + 1, y + 3); printf("*");
            _grind[x + 1][y + 2] = id;
            if (y + 3 < 27 && (_grind[x + 1][y + 3] != 1 && _grind[x + 1][y + 3] != 8)) {
                gotoxy(x + 1, y + 4); printf("*");
                _grind[x + 1][y + 3] = id;
            }
        }
    }
}

void Kougeki::ers(int _grind[57][29], char _key, int x, int y) {
    if (_key == 75 && x - 1 > 1 && _grind[x - 1][y] == 4) {
        //x--;
        gotoxy(x - 1, y + 1); printf(" ");
        _grind[x - 1][y] = 0;
        if (x - 2 > 1 && _grind[x - 2][y] == 4) {
            gotoxy(x - 2, y + 1); printf(" ");
            _grind[x - 2][y] = 0;
            if (x - 3 > 1 && _grind[x - 3][y] == 4) {
                gotoxy(x - 3, y + 1); printf(" ");
                _grind[x - 3][y] = 0;
            }
        }
    }
    if (_key == 77 && x + 2 < 55 && _grind[x + 3][y] == 4) {
        //x++;
        gotoxy(x + 3, y + 1); printf(" ");
        _grind[x + 3][y] = 0;
        if (x + 3 < 55 && _grind[x + 4][y] == 4) {
            gotoxy(x + 4, y + 1); printf(" ");
            _grind[x + 4][y] = 0;
            if (x + 4 < 55 && _grind[x + 5][y] == 4) {
                gotoxy(x + 5, y + 1); printf(" ");
                _grind[x + 5][y] = 0;
            }
        }
    }
    if (_key == 72 && y - 1 > 0 && _grind[x + 1][y - 2] == 4) {
        //y--;
        gotoxy(x + 1, y - 1); printf(" ");
        _grind[x + 1][y - 2] = 0;
        if (y - 2 > 0 && _grind[x + 1][y - 3] == 4) {
            gotoxy(x + 1, y - 2); printf(" ");
            _grind[x + 1][y - 3] = 0;
            if (y - 3 > 0 && _grind[x + 1][y - 4] == 4) {
                gotoxy(x + 1, y - 3); printf(" ");
                _grind[x + 1][y - 4] = 0;
            }
        }

    }
    if (_key == 80 && y + 1 < 27 && _grind[x + 1][y + 1] == 4) {
        //y++;
        gotoxy(x + 1, y + 2); printf(" ");
        _grind[x + 1][y + 1] = 0;

        if (y + 2 < 27 && _grind[x + 1][y + 2] == 4) {
            gotoxy(x + 1, y + 3); printf(" ");
            _grind[x + 1][y + 2] = 0;

            if (y + 3 < 27 && _grind[x + 1][y + 3] == 4) {
                gotoxy(x + 1, y + 4); printf(" ");
                _grind[x + 1][y + 3] = 0;
            }
        }
    }
}

bool Kougeki::doatk(int _grind[57][29], char _key, int x, int y) {
   
    if (c == 0) {
        spr(_grind, _key, x, y);
        c ++;
        Sleep(80);
        return true;
    }
    else if (c == 1) {
        
        ers(_grind, _key, x, y);
        c = 0;
        return false;
    }
    
}