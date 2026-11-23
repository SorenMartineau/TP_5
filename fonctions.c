#include <stdio.h>
#include <string.h>
#include "header.h"

#include <windows.h>
#include <locale.h>

void afficherMenu(){
    // affiche le menu

    printf("========== GESTION DES NOTES ==========\n");
    printf("1. Ajouter une consommation\n");
    printf("2. Afficher le resumé du jour\n");
    printf("0. Quitter\n");     
}