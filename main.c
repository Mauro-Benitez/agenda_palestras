#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Usuario.h"
#include <conio.h>
#include <locale.h>
#define col 3



////////////////////////////////////////////////////////

//Função de saida do programa
void sair (){

gotoxy(col,28);printf("Encerrando o programa...");
sleep(2);
system("cls");
system(" taskkill /f /im projetopim.exe");
}


/////////////////////////////////////////////////////////////////
//COR DA LETRA
enum {  BLACK,
        BLUE,
        GREEN,
        CYAN,
        RED,
        MAGENTA,
        BROWN,
        LIGHTGRAT,
        DARKGRAY,
        LIGHTBLUE,
        LIGHTGREEN,
        LIGHTCYAN,
        LIGHTRED,
        LIGHTMAGENTA,
        YELLOW,
        WHITE,
  };


//////////////////////////////////////////////////////////
//COR DO FUNDO
enum {  _BLACK = 0,
        _BLUE = 16,
        _GREEN=32,
        _CYAN=48,
        _RED=64,
        _MAGENTA=80,
        _BROWN=96,
        _LIGHTGRAT=112,
        _DARKGRAY=128,
        _LIGHTBLUE=144,
        _LIGHTGREEN=160,
        _LIGHTCYAN=176,
        _LIGHTRED=192,
        _LIGHTMAGENTA=208,
        _YELLOW=224,
        _WHITE=240,
};

/////////////////////////////////////////////////////////
//COR DO TEXTO E DO FUNDO
void textColor (int letras , int fundo){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),letras + fundo);
}

///////////////////////////////////////////////////////////
//POSIÇAO X(coluna) E Y(linha)
void gotoxy(int x, int y){
    HANDLE hCon;
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon, dwPos);




}


int main()
{

    //system("mode con:cols=450 lines=100");

    system("color 06");
    setlocale (LC_ALL, "");
    //gotoxy(55,1);printf("--------------------------");
    gotoxy(55,2);printf("Bem-vindo ao FREE PELESTRA");
    //gotoxy(55,3);printf("--------------------------");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("               \t\t\tFFFFFFFFFFFFFF     PPPPPPPPPP                 \n");
    printf("               \t\t\tF::::::::::::F     P:::::::::PP                     \n");
    printf("               \t\t\tF:::FFFFFFFFFF     P:::::::::::P                 \n");
    printf("               \t\t\tF:::F              P::::::::::::P                      \n");
    printf("               \t\t\tF:::F              P::::::::::::P                    \n");
    printf("               \t\t\tF:::F              P::::::::::::P                      \n");
    printf("  \t\t=============\tF:::FFFFFFFFFF     P:::::::::::P =============\t                 \n");
    printf("  \t\t=============\tF::::::::::::F     P::::::::::P  =============\t              \n");
    printf("               \t\t\tF::::::::::::F     P:::::::P                \n");
    printf("               \t\t\tF:::FFFFFFFFFF     P::::P              \n");
    printf("               \t\t\tF:::F              P::::P                    \n");
    printf("               \t\t\tF:::F              P::::P                \n");
    printf("               \t\t\tF:::F              P::::P                    \n");
    printf("               \t\t\tF:::F              P::::P                    \n");
    printf("               \t\t\tFFFFF              PPPPPP                   \n");



    int op;
    gotoxy(80,32);printf("*By 3GDM VISION*");
    //gotoxy(55,29);printf("------------------------------------");
    //gotoxy(55,27);printf("------------------------------------");
    gotoxy(col,20);printf("--------------------------");
    gotoxy(col,21);printf("[1]Iniciar    [3]Sair ");
    gotoxy(col,23);printf("[2]Administração          ");
    gotoxy(col,24);printf("--------------------------");
    gotoxy(col,26);printf("Selecione: ");
    gotoxy(14,26);scanf("%d", &op);


    switch(op){

    case 1:
        gotoxy(col,28);printf ("Carregando...");
        sleep(2);
        system("cls");
        log ();
        break;

    case 2:
        gotoxy(col,28);printf("Carregando...");
        sleep(2);
        system ("cls");
        log_adm ();
        break;

    case 3:

        sair();
        break;

    default:
        gotoxy(col,28);printf("Número Inválido...");
        sleep(1);
        system("cls");
        main();


    }
    return 0;

}
