#ifndef CANARD_H
#define CANARD_H

#include "image.h"

const int TAILLE=50;

struct canard {
    int posX;  //coordonnées x,y
    int posY;
    int w;      //largeur
    int h;      //hauteur
    int couleur;
    float vitesse_x;
    float vitesse_y;
    int mort; // entier qui prend valeur fixe lors de la mort du canard et qui nous sert à gérer une petite pause au moment où on tue le canard
    bool tuer; // vrai quand on tue  le canard
    bool sorti; // vrai quand le canard n'est plus visible a l'écran
    bool scorer; // bolléen qui nous permet d'ajouter le score lié au canard 1 seule fois.
};


void initCanard(canard &can, int lvl);

void showCanard(canard &can, SDL_Surface *&s, SDL_Surface *sprite, SDL_Surface* points, int cpt);

void moveCanard(canard &can,int tir,int cpt);

void changerDirectionCanard(int cpt,canard &c);

#endif // CANARD_H
