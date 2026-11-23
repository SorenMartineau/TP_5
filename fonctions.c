#include <stdio.h>
#include <string.h>
#include "header.h"

#include <windows.h>
#include <locale.h>

void afficherMenu(){

    printf("========== suivi de consommation ==========\n");
    printf("1. Ajouter une consommation\n");
    printf("2. Afficher le resumé du jour\n");
    printf("3. Afficher les objectifs et le score\n");
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

void afficherBarre(int valeur, int max){
    if (max <= 0){
        max = 1;
    }
    if (valeur < 0){
        printf("valeur trop petite\n");
        return;
    }
    else if (valeur > max){
        printf("valeur trop grande\n");
        return;
    }

    int case_pleines = (valeur*10)/max;

    for (int i = 0; i < case_pleines; i++){
        printf("█");
    }
    for (case_pleines; case_pleines < 10; case_pleines++){
        printf("▒");
    }

    printf("\n");


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
    int max = 10;

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

    printf("Eau      : %d 💧    ", c.eau);
    afficherBarre(c.eau, max);
    printf("café     : %d ☕    ", c.cafe);
    afficherBarre(c.cafe, max);
    printf("Bonbons  : %d 🍬 %s ", c.bonbons, face_bonbons);
    afficherBarre(c.bonbons, max);
    printf("gâteau   : %d 🍰    ", c.gateaux);
    afficherBarre(c.gateaux, max);
    printf("Légumes  : %d 🥦 %s ", c.legumes, face_legumes);
    afficherBarre(c.legumes, max);
    printf("Fruits   : %d 🍎 %s ", c.fruits, face_fruits);
    afficherBarre(c.fruits, max);
    printf("protéines: %d 🍗    ", c.proteines);
    afficherBarre(c.proteines, max);

    printf("====================================\n\n");    

}

void calculerScoreSante(Consommation c, Objectif o){

    int score = 50;

    if (c.eau >= o.eau){
        score += 10;
    }
    if (c.legumes >= o.legumes){
        score += 10;
    }
    if (c.fruits >= o.fruits){
        score += 10;
    }
    if (c.proteines >= o.proteines){
        score += 10;
    }

    if (c.bonbons > 5){
        if (c.bonbons > 20){
            score -= 15;
        }
        else{
            score -= c.bonbons-5;
        }
    }

    if (c.cafe > 3){
        if (c.cafe > 13){
            score -= 20;
        }
        else{
            score -= 2*c.cafe-6;
        }
    }

    if (score < 0){
        score = 0;
    }
    else if (score > 100){
        score = 100;
    }

    printf("score de sante du jour: %d/100\n", score);

}

void afficherObjectifsEtScore(Consommation c, Objectif o){


    char check[100];

    printf("========== Objectifs du jour ==========\n");

    if (c.eau >= o.eau){
        strcpy(check,"✅");
    }
    else{
        strcpy(check,"❌"); 
    }

    printf("Eau      : %d %s\n", o.eau, check);

    if (c.legumes >= o.legumes){
        strcpy(check,"✅");
    }
    else{
        strcpy(check,"❌"); 
    }

    printf("Légumes  : %d %s\n", o.legumes, check);

    if (c.fruits >= o.fruits){
        strcpy(check,"✅");
    }
    else{
        strcpy(check,"❌"); 
    }

    printf("Fruits   : %d %s\n", o.fruits, check);

    if (c.proteines >= o.proteines){
        strcpy(check,"✅");
    }
    else{
        strcpy(check,"❌"); 
    }

    printf("protéines: %d %s\n", o.proteines, check);

    calculerScoreSante(c, o);
    printf("====================================\n\n");    

}