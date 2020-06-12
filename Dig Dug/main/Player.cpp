#include "Player.h"
#include "Attack.h"
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
    printf("\033[1;36m");
    gotxy(x, y); printf("%c%c%c", 79, 119, 79);
    gotxy(x, y + 1); printf("%c%c%c", 167, 84, 167);

    if (_key == 75 && _grind[x - 1][y] != 1 && _grind[x - 1][y] != 8) {
        gotxy(x - 1, y + 1); printf("\033[0;36m"); printf("*");
    }
    if (_key == 77 && _grind[x + 3][y] != 1 && _grind[x + 3][y] != 8) {
        gotxy(x + 3, y + 1); printf("\033[0;36m"); printf("*");
    }
    if (_key == 72 && y - 1 != 0 && _grind[x + 1][y - 2] != 1 && _grind[x + 1][y - 2] != 8) {
        gotxy(x + 1, y - 1); printf("\033[0;36m"); printf("*");
    }
    if (_key == 80 && _grind[x + 1][y + 1] != 1 && _grind[x + 1][y + 1] != 8) {
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
    if (_grind[x - 1][y] != 1 && _grind[x - 1][y] != 8) {
        gotxy(x - 1, y + 1); printf(" ");
    }
    if (_grind[x + 3][y] != 1 && _grind[x + 3][y] != 8) {
        gotxy(x + 3, y + 1); printf(" ");
    }
    if (_grind[x + 1][y - 2] != 1 && _grind[x + 1][y - 2] != 8) {
        gotxy(x + 1, y - 1); printf(" ");
    }
    if (_grind[x + 1][y + 1] != 1 && _grind[x + 1][y + 1] != 8) {
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
    if (doinAtk == false){
        if (_kbhit()) {
            ers(_grind);

            char key = _getch();
            if (key == 75 && x - 1 > 1 && _grind[x - 1][y] != 8 && _grind[x - 1][y - 1] != 8) {
                x--;
                _key = 75;
            }
            if (key == 77 && x + 2 < 55 && _grind[x + 3][y] != 8 && _grind[x + 3][y - 1] != 8) {
                x++;
                _key = 77;
            }
            if (key == 72 && y - 1 > 0 && _grind[x + 1][y - 2] != 8 && _grind[x][y - 2] != 8 && _grind[x + 2][y - 2] != 8) {
                y--;
                _key = 72;
            }
            if (key == 80 && y + 1 < 27 && _grind[x + 1][y + 1] != 8 && _grind[x][y + 1] != 8 && _grind[x + 2][y + 1] != 8) {
                y++;
                _key = 80;
            }
            if (key == 'x') {
                doinAtk = true;
            }

        }
    }
    else{
        doinAtk = attack.doatk(_grind, _key, x, y);
    }
    
    spr(_grind, _key);

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
    dx = x; dy = y;
}

void Player::restart(int _grind[57][29]) {
    ers(_grind);
    x = 26;
    y = 15;
    spr(_grind, 77);
}
void Player::setxy() {
    x = 0;
    y = 1;

}
bool Player::die(int _grind[57][29]) {
    bool help = false;
    for (int b = y - 1; b < y + 1; b++) {
        for (int a = x; a < x + 3; a++) {
            if (_grind[a][b] == 8) {
                help = true;
                break;
            }
            else if (_grind[a][b] == 3) {
                help = true;
                break;
            }
        }
        if (help == true) return true;
    }
    mve(_grind);
    return false;
}

void Player::danim() {
    Sleep(200);
    printf("\033[1;36m");
    gotxy(x, y); printf("XwX");
    Sleep(160);
    for (int a = 0; a < 5; a++) {
        if (a % 2 == 0) {
            gotxy(x, y); printf(" * ");
            gotxy(x, y + 1); printf("* *");
            Sleep(120);
        }
        else {
            gotxy(x, y); printf("* *");
            gotxy(x, y + 1); printf(" * ");
            Sleep(120);
        }
    }
}