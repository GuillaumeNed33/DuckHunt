#ifndef GESTIONSCORE_H
#define GESTIONSCORE_H

#include"image.h"
#include"canard.h"
#include "chicken.h"

const int canardMinimum=6;

using namespace std;

void initTabCan(int tabCan[][2], int x, int y);

void remplirTabCan(bool tuer, bool tuer2, int round, int tabCan[][2], int tir);

void afficheScoreCan(int TabCan[][2], SDL_Surface* &screen, SDL_Surface* canardScore);

int attributScoreCanard(int TabCan[][2],int x, int y);

void afficheCartouche(int tir, SDL_Surface* &screen,SDL_Surface* cartouche0,SDL_Surface* cartouche1,SDL_Surface* cartouche2,SDL_Surface* cartouche3);

void compteScore(int &score, canard can);

void recuperChicken(SDL_Rect &bucketPos, chicken &c);

void atttributScoreBucket(int &score, bool entreDansLeBucket);

void attributScoreChicken(int &score, bool tuer);

#endif // GESTIONSCORE_H


