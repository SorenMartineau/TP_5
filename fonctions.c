#include <stdio.h>
#include <string.h>
#include "header.h"

#include <windows.h>
#include <locale.h>

void afficherMenu(){

    printf("========== suivi de consommation ==========\n");
    printf("1. Ajouter une consommation\n");
    printf("2. Afficher le resumé du jour\n");
    printf("0. Quitter\n");     
}

Consommation initConsommation(){
    Consommation c = {0,0,0,0,0,0,0};

    return c;
}

int humeurBonbons(int quantite){
    if (quantite <= 3){
        return 1;
    }
    else if (quantite <= 7){
        return 2;
    }
    else if (quantite <= 12){
        return 3;
    }
    else{
        return 4;
    }
}

int humeurlegumes(int quantite){
    if (quantite <= 0){
        return 1;
    }
    else if (quantite <= 2){
        return 2;
    }
    else{
        return 3;
    }
}

int humeurFruits(int quantite){
    if (quantite <= 1){
        return 1;
    }
    else if (quantite <= 3){
        return 2;
    }
    else{
        return 3;
    }
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
        printf("\n");
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

void afficherResume(Consommation c){

    char face_bonbons[100];
    char face_legumes[100];
    char face_fruits[100];

    switch (humeurBonbons(c.bonbons))
    {
    case 1:
        strcpy(face_bonbons,"😇");
        break;
    case 2:
        strcpy(face_bonbons,"🙂");
        break;
    case 3:
        strcpy(face_bonbons,"😕");
        break;
    case 4:
        strcpy(face_bonbons,"😈");
        break;
    default:
        break;
    }

    switch (humeurlegumes(c.legumes))
    {
    case 1:
        strcpy(face_legumes,"😭");
        break;
    case 2:
        strcpy(face_legumes,"🙂");
        break;
    case 3:
        strcpy(face_legumes,"😎");
        break;
    default:
        break;
    }

    switch (humeurFruits(c.fruits))
    {
    case 1:
        strcpy(face_fruits,"😢");
        break;
    case 2:
        strcpy(face_fruits,"🙂");
        break;
    case 3:
        strcpy(face_fruits,"😃");
        break;
    default:
        break;
    }

    printf("========== Resumé du jour ==========\n");

    printf("Eau      : %d 💧\n", c.eau);
    printf("café     : %d ☕\n", c.cafe);
    printf("Bonbons  : %d 🍬 %s\n", c.bonbons, face_bonbons);
    printf("gâteau   : %d 🍰\n", c.gateaux);
    printf("Légumes  : %d 🥦 %s\n", c.legumes, face_legumes);
    printf("Fruits   : %d 🍎 %s\n", c.fruits, face_fruits);
    printf("protéines: %d 🍗\n", c.proteines);

    printf("====================================\n\n");    

}