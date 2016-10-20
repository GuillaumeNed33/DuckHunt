#ifndef GESTIONFICHIER_H
#define GESTIONFICHIER_H

#include <iostream>
#include <fstream>
#include "image.h"

using namespace std;

void LireMeilleurScore(string fichier,string meilleurScore[]);

void changerMeilleurScore(string fichier, int score);

#endif // GESTIONFICHIER_H
