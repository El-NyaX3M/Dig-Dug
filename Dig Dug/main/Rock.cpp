#include "Rock.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

Rock::Rock() {
    
}

void Rock::setr() {
    do {
        x = rand() % 51 + 2;
        y = rand() % 24 + 3;
    } while ((x >= 23 && x <= 27) && (y >= 3 && y <= 16));
}
void Rock::gotoxy(int _x, int _y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = _x;
    dwPos.Y = _y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void Rock::spr(int _grind[57][29]) {
    printf("\033[1;35m");
    gotoxy(x, y); printf("%c%c%c", 220, 220, 220);
    gotoxy(x, y + 1); printf("ewe");

    _grind[x][y - 1] = id;
    _grind[x + 1][y - 1] = id;
    _grind[x + 2][y - 1] = id;
    _grind[x][y] = id;
    _grind[x + 1][y] = id;
    _grind[x + 2][y] = id;
}

void Rock::ers(int _grind[57][29]) {
    gotoxy(x, y); printf("   ");
    gotoxy(x, y + 1); printf("   ");

    _grind[x][y - 1] = 0;
    _grind[x + 1][y - 1] = 0;
    _grind[x + 2][y - 1] = 0;
    _grind[x][y] = 0;
    _grind[x + 1][y] = 0;
    _grind[x + 2][y] = 0;
}

void Rock::check(int _grind[57][29]) {
    if (active == false) {
        if ((_grind[x][y + 1] != 1 && _grind[x][y + 1] != 8) && (_grind[x + 1][y + 1] != 1 && _grind[x + 1][y + 1] != 8) && (_grind[x + 2][y + 1] != 1 && _grind[x + 2][y + 1] != 8)) {
            count++;
            if (count > 20) {
                fall(_grind);
            }

        }
        if (((_grind[x][y + 1] == 1 || _grind[x][y + 1] == 8) || (_grind[x + 1][y + 1] == 1 || _grind[x + 1][y + 1] == 8) || (_grind[x + 2][y + 1] == 1 || _grind[x + 2][y + 1] == 8)) && count > 20) {
            count1++;
            if (count1 > 20) {
                ers(_grind);
                active = true;
            }
        }
    }
}

void Rock::fall(int _grind[57][29]) {
    ers(_grind);
    y++;
    spr(_grind);

}


