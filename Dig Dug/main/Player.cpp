#include "Player.h"
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

Player::Player(int _x, int _y) {
    x = _x;
    y = _y;
}

void Player::spr() {
    gotxy(x, y); printf("%c%c%c", 79, 119, 79);
    gotxy(x, y + 1); printf("%c%c%c", 167, 84, 167);
}

void Player::ers() {
    gotxy(x, y); printf("   ");
    gotxy(x, y + 1); printf("   ");
}

void Player::mve() {
    if (_kbhit()) {
        char key = _getch();

        ers();
        if (key == 75 && x-1 > 1) x--;
        if (key == 77 && x+2 < 55) x++;
        if (key == 72 && y-1 > 0) y--;
        if (key == 80 && y+1 < 27) y++;
        spr();

    }
}

void Player::startAnim() {
    for (int a = x; a < 26; a++) {
        ers();
        x++;
        spr();
        Sleep(100);
    }
    for (int a = y; a< 15; a++) {
        ers();
        y++;
        spr();
        Sleep(100);
    }
}