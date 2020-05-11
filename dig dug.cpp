// dig dug.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include "dig dug.h"

using namespace std;


void gotoxy(int x, int y) {

    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;

    SetConsoleCursorPosition(hCon, dwPos);
    
}

void RemoveCursor() {
    HANDLE hOut;
    CONSOLE_SCREEN_BUFFER_INFO SBInfo;
    COORD NewSBSize;
    int Status;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfo(hOut, &SBInfo);
    NewSBSize.X = SBInfo.dwSize.X - 2;
    NewSBSize.Y = SBInfo.dwSize.Y;

    Status = SetConsoleScreenBufferSize(hOut, NewSBSize);

}




int main()
{
    bool juego_terminado = false;
    int x = 20;
    int y = 20;
    //RemoveCursor();

    while (!juego_terminado) {
        
        gotoxy(x, y); printf("*");
        if (_kbhit()) {

            char tecla = _getch();
            gotoxy(x, y); printf("*");
            if (tecla == 'a') x--;
            if (tecla == 'd') x++;
            if (tecla == 'w') y--;
            if (tecla == 's') y++;
            
        }

        
        system("cls");


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
