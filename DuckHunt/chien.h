#ifndef CHIEN_H
#define CHIEN_H


#include "canard.h"

bool faireRireLeChien(SDL_Rect &chienQuiRit, SDL_Surface* &screen, SDL_Surface* sprite, SDL_Surface* terrain, bool &descendre, int cpt, bool &finRound);

void faireMarcherLeChien(SDL_Rect &chienQuiMarche, SDL_Surface* &screen, SDL_Surface* sprite, SDL_Surface *terrain, bool &debut, int cpt);

void dernierCanard(canard can, canard can2, int &dernier );

void faireRamasserLeChien(SDL_Rect &chienQuiRamasse, SDL_Surface* &screen, SDL_Surface* sprite, SDL_Surface* terrain, bool &descendre, int cpt,bool &fin,canard can, canard can2,int dernier);

#endif // CHIEN_H
