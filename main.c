#include <stdio.h>
#include <string.h>
#include "header.h"

#include <windows.h>
#include <locale.h>
// A METTRE DANS LE MAIN :



int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    setlocale(LC_ALL, ".UTF-8"); // ou ".65001" si ".UTF-8" ne passe pas

    Consommation c = initConsommation();

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
    }



    return 0;
}