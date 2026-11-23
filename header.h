#ifndef HEADER 
#define HEADER 

typedef struct Consommation{

    int eau;
    int cafe;
    int bonbons;
    int gateaux;
    int legumes;
    int fruits;
    int proteines; 

} Consommation;

typedef struct Objectif{

    int eau;
    int legumes;
    int fruits;
    int proteines; 

} Objectif;

void afficherMenu();
Consommation initConsommation();
Consommation ajoutConsommation(Consommation c);
void afficherResume(Consommation c);
int humeurBonbons(int quantite);
int humeurlegumes(int quantite);
int humeurFruits(int quantite);
void afficherBarre(int valeur, int max);
void afficherObjectifsEtScore(Consommation c, Objectif o);
void calculerScoreSante(Consommation c, Objectif o);

#endif