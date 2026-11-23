#include <stdio.h>
#include <string.h>
#include "header.h"

#include <windows.h>
#include <locale.h>

void afficherMenu(){
    // affiche le menu

    printf("========== suivi de consommation ==========\n");
    printf("1. Ajouter une consommation\n");
    printf("2. Afficher le resumé du jour\n");
    printf("0. Quitter\n");     
}

Consommation initConsommation(){
    Consommation c = {0,0,0,0,0,0,0};

    return c;


}

Consommation ajoutConsommation(Consommation c){

    int choix = -1;

    while (choix < 1 || choix > 7){
        printf("quelle catégorie voulez vous modifiez ?\n\n");
        printf("1. Eau💧\n");
        printf("2. café☕\n");
        printf("3. Bonbons🍬\n");
        printf("4. gâteau🍰\n");
        printf("5. Légumes🥦\n");
        printf("6. Fruits🍎\n");
        printf("7. protéines🍗\n");

        printf("votre choix: ");
        scanf("%d", &choix);
    }

    int quantite = -1;

    while (quantite < 0){
        printf("donnez la quantité: ");
        scanf("%d", &quantite);
    }

    switch (choix)
    {
    case 1:
        c.eau += quantite;
        break;
    case 2:
        c.cafe += quantite;
        break;
    case 3:
        c.bonbons += quantite;
        break;
    case 4:
        c.gateaux += quantite;
        break;
    case 5:
        c.legumes += quantite;
        break;
    case 6:
        c.fruits += quantite;
        break;
    case 7:
        c.proteines += quantite;
        break;
    default:
        break;
    }

    return c;

}
