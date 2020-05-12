// dig dug.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <cstdio>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"


void gotoxy(int x, int y) {

    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;

    SetConsoleCursorPosition(hCon, dwPos);
    
}





class Jugador {
    int x;
    int y;

    public:
        Jugador(int _x, int _y) : x(_x), y(_y) {};
        void imprimir();
        void borrar();
        void mover();
};

    





void Jugador::imprimir() {
    // esto solamente es para checar las cordenadas del jugador
    // asi que se puede quitar despues (me refiero al cout)
    //cout << "x: " << x << " y: " << y << endl;

    gotoxy(x, y); printf("%c%c%c", 201,205,187);
    //gotoxy(x, y+1); printf("%c%c%c", 186,00,186);
    gotoxy(x, y+1); printf("%c%c%c", 200,205,188);
}


void Jugador::borrar() {
    gotoxy(x, y); printf("   ");
    gotoxy(x, y+1); printf("   ");
    gotoxy(x, y+2); printf("   ");
}



void Jugador::mover() {
    // si se cambian las dimenciones solo modificar las variables 
    // altura y anchor
    int altura = 26;
    int anchor = 60;
        if (_kbhit()) {

                char tecla = _getch();
                borrar();
                if (tecla == 'a' && x > 2) x--;
                if (tecla == 'd' && x+2 < anchor-1) x++;
                if (tecla == 'w' && y > 3) y--;
                if (tecla == 's' && y+2 < altura-2) y++;
                imprimir();
        }
}


void marco() {
    int aumento = 4;
    // primera linea
    for (int i = 1; i < 61; i++) {
        if (i == 1) {
            gotoxy(i, 3); printf("%c", 201);
        }
        if (i < 60) {
            gotoxy(i + 1, 3); printf("%c", 205);
        }
        if (i == 60) {
            gotoxy(i, 3); printf("%c", 187);
        }
    }
    // ultima linea
    for (int i = 1; i < 61; i++) {
        if (i == 1) {
            gotoxy(i, 23); printf("%c", 200);
        }
        if (i < 60) {
            gotoxy(i + 1, 23); printf("%c", 205);
        }
        if (i == 60) {
            gotoxy(i, 23); printf("%c", 188);
        }
    }
    // laterales
    for (int i = 1; i < 20; i++) {
        gotoxy(1, aumento); printf("%c", 186);
        gotoxy(60, aumento); printf("%c", 186);
        aumento++;
       


    }


}

int main()
{
    bool juego_terminado = false;
    Jugador cordenada(7, 7);
    cordenada.imprimir();


    marco();
    while (!juego_terminado) {
       
        marco();
        cordenada.imprimir();
        cordenada.mover();
        marco();

        Sleep(40);
        //system("cls");

        
    }
    
    
    
 }

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
