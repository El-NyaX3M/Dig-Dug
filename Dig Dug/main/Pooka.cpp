#include "Pooka.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <windows.h>

using namespace std;

Pooka::Pooka() {

}

void Pooka::setr(int spd) {
    do {
        x = rand() % 51 + 2;
        y = rand() % 24 + 3;
    } while ((x >= 23 && x <= 27) && (y >= 3 && y <= 16));
    dx = x;
    dy = y;
    /*very important*/ speed = spd;
}
void Pooka::gotoxy(int _x, int _y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = _x;
    dwPos.Y = _y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void Pooka::spr(int _grind[57][29]) {
    if (health == 3) printf("\033[1;32m");
    else if (health == 2) printf("\033[1;33m");
    else if (health == 1)printf("\033[1;31m");
    gotoxy(x, y); printf("UwU");
    gotoxy(x, y + 1); printf("%c%c%c", 223, 186, 223);

    _grind[x][y - 1] = id;
    _grind[x + 1][y - 1] = id;
    _grind[x + 2][y - 1] = id;
    _grind[x][y] = id;
    _grind[x + 1][y] = id;
    _grind[x + 2][y] = id;
}

void Pooka::ers(int _grind[57][29]) {
    gotoxy(x, y); printf("   ");
    gotoxy(x, y + 1); printf("   ");

    _grind[x][y - 1] = 0;
    _grind[x + 1][y - 1] = 0;
    _grind[x + 2][y - 1] = 0;
    _grind[x][y] = 0;
    _grind[x + 1][y] = 0;
    _grind[x + 2][y] = 0;
}

void Pooka::mve(int _grind[57][29]) {
    if (count % speed == 0) {
        do {
            ers(_grind);
            if (count % 7 == 0) {
                int d;
                do {
                    d = rand() % 4 + 1;
                } while (d == 5 - dir);
                dir = d;
            }
            if (dir == 1 && y - 1 > 0 && (_grind[x][y - 2] != 1 && _grind[x + 1][y - 2] != 1 && _grind[x + 2][y - 2] != 1) && (_grind[x][y - 2] != 8 && _grind[x + 1][y - 2] != 8 && _grind[x + 2][y - 2] != 8)) {
                y--;
                if ((_grind[x][y - 2] == 1 || _grind[x + 1][y - 2] == 1 || _grind[x + 2][y - 2] == 1) || (_grind[x][y - 2] == 8 || _grind[x + 1][y - 2] == 8 || _grind[x + 2][y - 2] == 8)) {
                    do {
                        dir = rand() % 4 + 1;
                    } while (dir != 1);
                }
                break;
            }
            else if (dir == 2 && x - 1 > 1 && (_grind[x - 1][y - 1] != 1 && _grind[x - 1][y] != 1) && (_grind[x - 1][y - 1] != 8 && _grind[x - 1][y] != 8)) {
                x--;
                if ((_grind[x - 1][y - 1] == 1 || _grind[x - 1][y] == 1) || (_grind[x - 1][y - 1] == 8 || _grind[x - 1][y] == 8)) {
                    do {
                        dir = rand() % 4 + 1;
                    } while (dir != 2);
                }
                break;
            }
            else if (dir == 3 && x + 2 < 55 && (_grind[x + 3][y - 1] != 1 && _grind[x + 3][y] != 1) && (_grind[x + 3][y - 1] != 8 && _grind[x + 3][y] != 8)) {
                x++;
                if ((_grind[x + 3][y - 1] == 1 || _grind[x + 3][y] != 1) || (_grind[x + 3][y - 1] == 8 || _grind[x + 3][y] == 8)) {
                    do {
                        dir = rand() % 4 + 1;
                    } while (dir != 3);
               }
                break;
            }
            else if (dir == 4 && y + 1 < 27 && (_grind[x][y + 1] != 1 && _grind[x + 1][y + 1] != 1 && _grind[x + 2][y + 1] != 1) && (_grind[x][y + 1] != 8 && _grind[x + 1][y + 1] != 8 && _grind[x + 2][y + 1] != 8)) {
                y++;
                if ((_grind[x][y + 1] == 1 || _grind[x + 1][y + 1] == 1 || _grind[x + 2][y + 1] == 1) || (_grind[x][y + 1] == 8 || _grind[x + 1][y + 1] == 8 || _grind[x + 2][y + 1] == 8)) {
                    do {
                        dir = rand() % 4 + 1;
                    } while (dir != 4);
                }
                break;
            }
            else{
                dir = rand() % 4 + 1;
                break;
            }
            
        } while (true);
        spr(_grind);
    }

    count++;
}

int Pooka::check(int _grind[57][29]) {
    if (alive == true) {
        if (health > 0) {
            mve(_grind);
            active(_grind);
            return 0;
        }
        else {
            ers(_grind);
            if (y < 9) {
                pts *= 1;
            }
            else if (y < 18) {
                pts *= 5;
            }
            else {
                pts *= 10;
            }
            alive = false;
            return pts;
        }
    }
    else {
        return 0;
    }
}

void Pooka::active(int _grind[57][29]) {
    bool help = false;
    for (int b = y - 1; b < y + 1; b++) {
        for (int a = x; a < x + 3; a++) {
            if (_grind[a][b] == 8) {
                health = 0;
                pts += 500;
                help = true;
                break;
            }
            else if (_grind[a][b] == 4) {
                health--;
                help = true;
                break;
            }
        }
        if (help == true) break;
    }
}

void Pooka::restart(int _grind[57][29]) {
    ers(_grind);
    x = dx;
    y = dy;
    health = 3;
}
