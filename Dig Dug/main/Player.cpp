#include "Player.h"
#include "Level_1.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;


void gotxy(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

Player::Player() {

}

void Player::spr(int _grind[57][29], char _key) {
    gotxy(x, y); printf("%c%c%c", 79, 119, 79);
    gotxy(x, y + 1); printf("%c%c%c", 167, 84, 167);

    if (_key == 75 && _grind[x - 1][y] != 1) {
        gotxy(x - 1, y + 1); printf("\033[0;36m"); printf("*");
    }
    if (_key == 77 && _grind[x + 3][y] != 1) {
        gotxy(x + 3, y + 1); printf("\033[0;36m"); printf("*");
    }
    if (_key == 72 && y - 1 != 0 && _grind[x + 1][y - 2] != 1) {
        gotxy(x + 1, y - 1); printf("\033[0;36m"); printf("*");
    }
    if (_key == 80 && _grind[x + 1][y + 1] != 1) {
        gotxy(x + 1, y + 2); printf("\033[0;36m"); printf("*");
    }
    _grind[x][y - 1] = id;
    _grind[x+1][y - 1] = id;
    _grind[x+2][y - 1] = id;
    _grind[x][y] = id;
    _grind[x+1][y] = id;
    _grind[x+2][y] = id;
}

void Player::ers(int _grind[57][29]) {
    gotxy(x, y); printf("   ");
    gotxy(x, y + 1); printf("   ");
    if (_grind[x - 1][y] != 1) {
        gotxy(x - 1, y + 1); printf(" ");
    }
    if (_grind[x + 3][y] != 1) {
        gotxy(x + 3, y + 1); printf(" ");
    }
    if (_grind[x + 1][y - 2] != 1) {
        gotxy(x + 1, y - 1); printf(" ");
    }
    if (_grind[x + 1][y + 1] != 1) {
        gotxy(x + 1, y + 2); printf(" ");
    }
    _grind[x][y-1] = 0;
    _grind[x + 1][y-1] = 0;
    _grind[x + 2][y-1] = 0;
    _grind[x][y] = 0;
    _grind[x + 1][y] = 0;
    _grind[x + 2][y] = 0;
}

void Player::mve(int _grind[57][29]) {
    if (_kbhit()) {
        char key = _getch();
        char _key = 0;
        ers(_grind);
        if (key == 75 && x - 1 > 1){
            x--;
            _key = key;
        }
        if (key == 77 && x + 2 < 55) {
            x++;
            _key = key;
        }
        if (key == 72 && y - 1 > 0) {
            y--;
            _key = key;
        }
        if (key == 80 && y + 1 < 27) {
            y++;
            _key = key;
        }
        spr(_grind, _key);

    }
}

void Player::attk(int _grind[57][29], char _key) {
    
}

void Player::startAnim(int _grind[57][29]) {
    for (int a = x; a < 26; a++) {
        ers(_grind);
        x++;
        spr(_grind, 77);
        Sleep(100);
    }
    for (int a = y; a< 15; a++) {
        ers(_grind);
        y++;
        spr(_grind, 80);
        Sleep(100);
    }
}