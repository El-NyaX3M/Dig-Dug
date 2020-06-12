#include "Grind.h"
#include "Player.h"
#include "Pooka.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
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
    srand(time(NULL));
    for (int y = 0; y < 29; y++) {
        for (int x = 0; x < 57; x++) {
            if (y < 2) grind[x][y] = 0;
            else grind[x][y] = 1;
        }
    }
}
void Grind::map() {
    gotoxyg(0, 0); printf("Lv. %d", level);
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
    enemiesL = enemies;
    dig.spr(grind, 77);
    dig.startAnim(grind);
    dig.spr(grind, 75);
    for (int a = 0; a < rocks; a++) {
        Rock r;
        r.setr();
        rock[a] = r;
        rock[a].spr(grind);
    }
    for (int a = 0; a < enemies; a++) {
        Pooka p;
        p.setr(spd);
        pooka[a] = p;
        rock[a].spr(grind);
    }
}

bool Grind::play() {
    bool check = false;
    if (lives == 0) return true;
    gotoxyg(17, 0); printf("%d", score);
    gotoxyg(49, 0); printf("%d", lives);
    
    for (int a = 0; a < rocks; a++) {
        rock[a].check(grind);
    }       
    for (int a = 0; a < enemies; a++) {
        int shelp = score;
        score += pooka[a].check(grind);
        if (shelp != score) enemiesL--;
    }
    check = dig.die(grind);
    if (check == true) {
        lives--;
        dig.danim();
        restart();
    }
    if (enemiesL == 0) nextlevel();
    return false;
}

void Grind::restart() {
    for (int a = 0; a < enemies; a++) {
        pooka[a].restart(grind);   
    }
    dig.restart(grind);
}

void Grind::nextlevel() {
    level++;
    for (int y = 0; y < 29; y++) {
        for (int x = 0; x < 57; x++) {
            if (y < 2) grind[x][y] = 0;
            else grind[x][y] = 1;
        }
    }
    if (spd > 2) spd--;
    map();
    enemies++;
    if (level % 2 == 1) rocks++;
    dig.setxy();
    start();

}