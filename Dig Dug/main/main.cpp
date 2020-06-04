#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "Player.h"
#include "Grind.h"

using namespace std;
//Tools for the game
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
void printdd(int y) {
    char a = 178;
    int x = 18;
    printf("\033[0;33m");
    gotoxy(x, y); printf("%c%c%c%c   %c%c%c%c%c%c %c%c%c%c\n", a, a, a, a, a, a, a, a, a, a, a, a, a, a);
    gotoxy(x, y + 1); printf("%c%c  %c%c   %c%c   %c%c\n", a, a, a, a, a, a, a, a);
    gotoxy(x, y + 2); printf("%c%c  %c%c   %c%c   %c%c  %c%c\n", a, a, a, a, a, a, a, a, a, a);
    gotoxy(x, y + 3); printf("%c%c%c%c   %c%c%c%c%c%c %c%c%c%c%c%c\n\n", a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);

    gotoxy(x, y + 5); printf("%c%c%c%c   %c%c  %c%c %c%c%c%c\n", a, a, a, a, a, a, a, a, a, a, a, a);
    gotoxy(x, y + 6); printf("%c%c  %c%c %c%c  %c%c %c%c\n", a, a, a, a, a, a, a, a, a, a);
    gotoxy(x, y + 7); printf("%c%c  %c%c %c%c  %c%c %c%c  %c%c\n", a, a, a, a, a, a, a, a, a, a, a, a);
    gotoxy(x, y + 8); printf("%c%c%c%c   %c%c%c%c%c%c %c%c%c%c%c%c", a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);

}
void erasedd(int y) {
    int x = 18;
    gotoxy(x, y); printf("                                            ");
    gotoxy(x, y + 1); printf("                                            ");
    gotoxy(x, y + 2); printf("                                            ");
    gotoxy(x, y + 3); printf("                                            ");

    gotoxy(x, y + 5); printf("                                            ");
    gotoxy(x, y + 6); printf("                                            ");
    gotoxy(x, y + 7); printf("                                            ");
    gotoxy(x, y + 8); printf("                                            ");

}
//---

//Internal stuff for the game as menu 'n other related things
    //Cursor: Es el puntero del menu
int cursor() {
    int select = 0, x = 1;
    printf("\033[0;36m");
    gotoxy(15, 10 + (x * 3)); printf("*>");
    while (select == 0) {
        if (_kbhit()) {
            char key = _getch();
            gotoxy(15, 10 + (x*3)); printf("  ");
            if (key == 13) {
                select = x;
                printf("\033[0;32m");
                gotoxy(15, 10 + (x * 3)); printf("*>");
            }
            if (key == 72 && x - 1 > 0) x--;
            if (key == 80 && x + 1 < 4) x++;
            gotoxy(15, 10 + (x * 3)); printf("*>");
        }
    }
    gotoxy(15, 10 + (x * 3)); printf("  ");
    return select;
}
    //Help: Es el menu de como jugar
int help() {
    return 0;
}
    //Credits: El menu de los creditos y la informacion necesaria
int credits() {
    return 0;
}
    //Menu: Es el menu principal
void menu() {
    int select = 0;
    for (int y = 30; y > 1; y--) {
        erasedd(y);
        printdd(y-1);
        gotoxy(0, 0);
        Sleep(150);
    } 
    gotoxy(11, 11); cout << "-------------------------------------";
    while (select != 1) {
        printf("\033[0m");
        gotoxy(40, 9); cout << "OwO. version";
        gotoxy(18, 13); printf("Start Diggin'");
        gotoxy(18, 16); printf("How To Dig");
        gotoxy(18, 19); printf("Digger Credits");
        
        select = cursor();
        switch (select) {
        case 1:
            gotoxy(18, 13); printf("Start Diggin'");
            printf("\033[0;36m");
            Sleep(150);
            break;
        case 2:
            printf("\033[0;36m");
            gotoxy(18, 16); printf("How To Dig");
            Sleep(150);
            help();
            break;
        case 3:
            printf("\033[0;36m");
            gotoxy(18, 19); printf("Digger Credits");
            Sleep(150);
            break;
        }
    }
}


//THE GAME
    //Main: Aqui es donde el codigo se compila
int main()
{
    Grind game;
    HideCursor();
    bool gameOver = false;
    Player dig();
    menu();
    game.start();
    while (!gameOver) {
        
        game.play();
        Sleep(30);
    }
}
//-------

