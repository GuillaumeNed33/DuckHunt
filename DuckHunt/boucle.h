#ifndef BOUCLE_H
#define BOUCLE_H

#include <sstream>
#include "chien.h"
#include "evenement.h"
#include "gestionFichier.h"
#include "canard.h"
#include "gestionScore.h"
#include "chicken.h"

using namespace std;

void menu(bool &modeNormal, bool &modeSurprise, bool &bestScore, bool &quitter, SDL_Surface *&screen, SDL_Event &event);
void normal(bool &quitter, bool&ModeNormal, bool &bestScore, SDL_Surface* &screen, SDL_Event &event);
void meilleurScore(bool &quitter, bool &bestScore, SDL_Surface* &screen, SDL_Event &event, int score, int mode);
void surprise(bool &quitter, bool &modeSurprise, SDL_Surface* &screen, SDL_Event &event, bool &bestScore);

#endif // BOUCLE_H
