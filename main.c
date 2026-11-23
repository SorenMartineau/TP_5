#include <stdio.h>
#include <string.h>
#include "header.h"

#include <windows.h>
#include <locale.h>



int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    setlocale(LC_ALL, ".UTF-8");

    Consommation c = initConsommation();
    Objectif o = {8,5,3,2};

    int choix = -1;
    while (choix != 0){
        afficherMenu();
        printf("votre choix: ");
        scanf("%d", &choix);
        printf("\n");

        if (choix == 1){
            c = ajoutConsommation(c);
        }
        else if (choix == 2){
            afficherResume(c);
        }
        else if (choix == 3){
            afficherObjectifsEtScore(c, o);
        }
    }



    return 0;
}