#ifndef EVENEMENT_H
#define EVENEMENT_H

#include "canard.h"
#include "chicken.h"

void gestionMenu(SDL_Event &event, int &selecteurMenu, bool &modeNormalRegle, bool & modeSurprise, bool &bestScore, bool &quitter);

void gestionModeNormal(SDL_Event &event, bool &quitter, bool &modeNormal, bool &modeNormalRegle, canard &can, canard &can2, int &tir);

void gestionMeilleurScore(SDL_Event &event, bool &bestScore, bool &quitter, int &mode);

void gestionRegleJeu(SDL_Event &event, bool &quitter, bool &modeRegle, bool &modeNormal);

void gestionModeSurprise(SDL_Event &event, bool &quitter, bool &modeSurprise, bool &modeSurpriseRegle, SDL_Rect &bucketPos, chicken &c , chicken &c2 , chicken &c3 , chicken &c4, chicken &c5, int &curseurX, int &curseurY);

#endif // EVENEMENT_H
