#include <iostream>
#include <cstdlib>
#include <SDL/SDL.h>
#include "boucle.h"

using namespace std;

int main ()
{
    bool quitter=false;
    bool modeNormal=false;
    bool modeSurprise=false;
    bool bestScore=false;
    int score=-1;

    SDL_Surface* screen;
    SDL_Event event;
    TTF_Init();

    srand(time(NULL)); //permet de generer un nouveau nombre aleatoire à chaque execution.

    screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_SWSURFACE| SDL_DOUBLEBUF); //Initialise la fenetre
    SDL_WM_SetCaption("Duck Hunt", NULL);

    SDL_EnableKeyRepeat(10,500); //Pouvoir rester appuyer sur les fleches dans le menu.

    while(!quitter) //boucle pour faire tourner le programme tant qu'on ne quitte pas.
    {
        menu(modeNormal,modeSurprise,bestScore,quitter,screen,event); //lance le menu de jeu

        if(modeNormal)
        {
            normal(quitter,modeNormal,bestScore,screen,event); //lance le mode classique
        }
        if(modeSurprise)
        {
            surprise(quitter, modeSurprise, screen, event,bestScore); //lance le mode surprise
        }
        if(bestScore)
        {
            meilleurScore(quitter,bestScore,screen,event,score,1); //lance les meilleurs scores
        }
    }
    SDL_FreeSurface(screen); //Libere la surface "screen"
    TTF_Quit();
    SDL_Quit();
    return EXIT_SUCCESS;
}
