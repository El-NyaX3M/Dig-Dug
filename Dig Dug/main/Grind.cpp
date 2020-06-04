#include "Grind.h"
#include "Player.h"
#include "Pooka.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
using namespace std;

void gotoxyg(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}
Grind::Grind() {
    for (int y = 0; y < 29; y++) {
        for (int x = 0; x < 57; x++) {
            if (y < 2) grind[x][y] = 0;
            else grind[x][y] = 1;
        }
    }
    
}
void Grind::map() {
    gotoxyg(8, 0); cout << "SCOWORE: ";
    gotoxyg(40, 0); cout << "LIVEWES: ";
    gotoxyg(1, 3);
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
        gotoxyg(1, y + 3);
    }
    gotoxyg(26, 15); printf("   ");
    gotoxyg(26, 16); printf("   ");
    
}
void Grind::start() {
    map();
    dig.spr(grind, 77);
	dig.startAnim(grind);
	dig.spr(grind, 75);
}

void Grind::play() {
	dig.mve(grind);
}