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

void afficherMenu();
Consommation initConsommation();
Consommation ajoutConsommation(Consommation c);

#endif