#ifndef CHICKEN_H
#define CHICKEN_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <SDL/SDL.h>
#include "image.h"

using namespace std;

const int tailleChicken=100;

struct chicken {
    int x;//coordonnées x,y
    int y;//coordonnées y
    int w;//largeur
    int h;//hauteur
    float vitesse_x;
    float vitesse_y;
    int mort;// entier qui prend valeur fixe lors de la mort du canard et qui nous sert à gérer une petite pause au moment où on tue le canard
    bool tuer;// vrai quand on tue  le canard
    bool sorti;// vrai quand le poulet n'est plus visible a l'écran
    bool entreDansLeBucket; //sert à incrémenter le score une seule fois
    bool dansLeBucket; // vrai quand le poulet est dans le bucket
    bool scorer;// bolléen qui nous permet d'ajouter le score lié au canard 1 seule fois.
};

void initChicken(chicken &c);
void showChicken(chicken &c, SDL_Surface* &screen, SDL_Surface*  chickenFly, SDL_Surface* point_touche,SDL_Surface* point_bucket,SDL_Surface* fail,int cpt);
void moveChicken(chicken &c, int cpt);
void garderChickenDansBucket(chicken &c, SDL_Rect bucket);
void changerDirectionChicken(int cpt,chicken &c);

#endif // CHICKEN_H

