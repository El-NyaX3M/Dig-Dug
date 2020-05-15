#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "Player.h"

using namespace std;

void gotoxy(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}
void HideCursor() {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 50;
    cci.bVisible = FALSE;

    SetConsoleCursorInfo(hCon, &cci);
}


void map() {
    gotoxy(10, 0); cout << "SCORE: ";
    gotoxy(45, 0); cout << "LIVES: ";
    gotoxy(1, 3);
    for (int y = 0; y < 27; y++) {
        for (int x = 0; x < 56; x++) {
            if (y < 9) {
                printf("\033[10;33m");
                printf("%c", 178);
            }
            else if (y < 18) {
                printf("\033[1;31m");
                printf("%c", 178);
            }
            else {
                printf("\033[0;31m");
                printf("%c", 178);
            }
            
        }
        gotoxy(1, y+3);
    }
}

int main()
{
    HideCursor();
    bool gameOver = false;
    Player dig(0, 1);
    map();
    dig.startAnim();
    while (!gameOver) {
        dig.mve();
        Sleep(30);
    }
}


