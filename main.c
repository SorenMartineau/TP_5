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

    Consommation c;

    int choix = -1;
    while (choix != 0){
        afficherMenu();
        scanf("%d", &choix);

    }
    return 0;
}