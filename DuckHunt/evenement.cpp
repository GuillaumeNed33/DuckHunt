#include "evenement.h"

Uint8 *keystates = SDL_GetKeyState( NULL );

/****************** Nom de la fonction **********************
* gestionMenu
******************** Auteur , Dates *************************
* Nom/Date : VIOLA / NEDELEC
* 2/12/2015
********************* Description ***************************
* Gere les evenements (touche clavier, ect...) liés au menu
*********************** Entrées *****************************
* Une variable d'évênement pour gerer chaque evenement
* Un entier selecteur pour faire le choix des modes
* Des booleens correspondants aux differents modes du jeu.
* Un booleen correspondant à la fin du jeu (la fenetre)
* (tous les booleens sont initialisés comme faux).
*********************** Sorties *****************************
* Rien
************************************************************/
void gestionMenu(SDL_Event &event, int &selecteurMenu, bool &modeNormal,bool & modeSurprise, bool &bestScore,bool &quitter)
{

    while(SDL_PollEvent(&event))
    {
        if(event.type==SDL_QUIT)
            quitter=true;

        if(keystates[SDLK_DOWN]&& selecteurMenu<3)
        {
            selecteurMenu++;
        }
        if(keystates[SDLK_UP]&& selecteurMenu>0)
        {
            selecteurMenu--;
        }

        if(keystates[SDLK_RETURN] || keystates[SDLK_KP_ENTER])
        {
            if(selecteurMenu==0)
            {
                modeNormal=true;
            }
            if(selecteurMenu==1)
            {
                modeSurprise=true;
            }
            if(selecteurMenu==2)
            {
                bestScore=true;
            }
            if(selecteurMenu==3)
            {
                quitter=true;
            }
        }
    }
}

/****************** Nom de la fonction **********************
* gestionMeilleurScore
******************** Auteur , Dates *************************
* Nom/Date : VIOLA
* 2/12/2015
********************* Description ***************************
* Gere les evenements liés à la phase des meilleurs scores
*********************** Entrées *****************************
* event est la variable d'évênement pour gerer chaque evenement
* bestScore est le booléen qui gère l'affichage du mode meilleurScore, tant qu'il est vrai on affiche
* quitter est un booleen correspondant à la fin du jeu (la fenetre)
* mode est un entier qui permet de changer l'affichage du tableau de score suivant le mode(surprise ou normal)
*********************** Sorties *****************************
* Rien
************************************************************/
void gestionMeilleurScore(SDL_Event &event,bool &bestScore,bool &quitter, int &mode)
{
    while(SDL_PollEvent(&event))
    {
        if(event.type==SDL_QUIT)
        {
            quitter=true;
        }
        if(keystates[SDLK_ESCAPE])
        {
            bestScore=false;
        }
        if(keystates[SDLK_LEFT] || keystates[SDLK_RIGHT])
        {
            mode*=-1;
        }
    }
}

/****************** Nom de la fonction **********************
* gestionModeNormal
******************** Auteur , Dates *************************
* Nom/Date : VIOLA / NEDELEC
* 2/12/2015
********************* Description ***************************
* Gere les evenements (touche clavier, clic, ect...) liés au
* jeu classique
*********************** Entrées *****************************
* Une variable d'évênement pour gerer chaque evenement
* Un booleen correspondant à la fin du jeu (la fenetre)
* modeNormal est le booléen qui gère l'affichage du mode normal, tant qu'il est vrai on joue
* modeNormalRegle est le booléen qui gère l'affichage des règles, tant qu'il est vrai on affiche
* 2 canards de la structure "canard"
* un entier "tir" pour compter le nombre de tirs restants
*********************** Sorties *****************************
* Rien
************************************************************/
void gestionModeNormal(SDL_Event &event, bool &quitter, bool &modeNormal, bool &modeNormalRegle, canard &can, canard &can2,int &tir)
{
    while(SDL_PollEvent(&event))
    {
        if(event.type==SDL_QUIT)
        {
            quitter=true;
        }
        if(keystates[SDLK_ESCAPE])
        {
            modeNormal=false;
            modeNormalRegle=false;
        }
        if(event.type==SDL_MOUSEBUTTONDOWN)
        {
            if(event.button.button==SDL_BUTTON_LEFT && tir>0)
            {
                if(can2.posX<=event.button.x && event.button.x<=(can2.posX+can.w) && can2.posY<=event.button.y && event.button.y<=(can2.posY+can.h))
                {
                    can2.tuer=true;
                }
                else if(can.posX<=event.button.x && event.button.x<=(can.posX+can.w) && can.posY<=event.button.y && event.button.y<=(can.posY+can.h))
                {
                    can.tuer=true;
                }
                tir--;
            }
        }
    }
}

/****************** Nom de la fonction **********************
* gestionModeSurprise
******************** Auteur , Dates *************************
* Nom/Date : VIOLA / NEDELEC
* 2/12/2015
********************* Description ***************************
* Gere les evenements (touche clavier, clic, ect...) liés au
* jeu secondaire
*********************** Entrées *****************************
* Une variable d'évênement pour gerer chaque evenement
* Un booleen correspondant à la fin de la fenetre
* modeSurprise est le booléen qui gère l'affichage du mode de jeu surprise, tant qu'il est vrai on joue
* modeSurpriseRegle est le booléen qui gère l'affcihage des regles, tant qu'il est vrai on affiche
* le sdl_rect du bucket
* les 5 poulets
* curseurX et Y sont des entiers utilisés pour le positionnement du viseur, on les utilise pour maintenir l'affichage du viseur même si on bouge le bucket.
*********************** Sorties *****************************
* Rien
************************************************************/
void gestionModeSurprise(SDL_Event &event, bool &quitter, bool &modeSurprise, bool &modeSurpriseRegle,SDL_Rect &bucketPos, chicken &c ,chicken &c2 , chicken &c3,  chicken &c4,  chicken &c5, int &curseurX, int &curseurY)
{
    while(SDL_PollEvent(&event))
    {
        if(event.type==SDL_QUIT)
        {
            quitter=true;
        }
        if(keystates[SDLK_ESCAPE])
        {
            modeSurprise=false;
            modeSurpriseRegle=false;
        }
        //Deplacement bucket gauche
        if(keystates[SDLK_LEFT] && bucketPos.x>0)
        {
            bucketPos.x-=6;
        }
        //Deplacement bucket droite
        if(keystates[SDLK_RIGHT] && bucketPos.x<SCREEN_WIDTH-bucketPos.w)
        {
            bucketPos.x+=6;
        }
        if(event.type==SDL_MOUSEBUTTONDOWN)
        {
            if(event.button.button==SDL_BUTTON_LEFT)
            {
                //Pour tuer les canards
                if(c3.x<=event.button.x && event.button.x<=(c3.x+c3.w) && c3.y<=event.button.y && event.button.y<=(c3.y+c3.h))
                {
                    c3.tuer=true;
                }
                else if(c2.x<=event.button.x && event.button.x<=(c2.x+c2.w) && c2.y<=event.button.y && event.button.y<=(c2.y+c2.h))
                {
                    c2.tuer=true;
                }
                else if(c.x<=event.button.x && event.button.x<=(c.x+c.w) && c.y<=event.button.y && event.button.y<=(c.y+c.h))
                {
                    c.tuer=true;
                }
                else if(c4.x<=event.button.x && event.button.x<=(c4.x+c4.w) && c4.y<=event.button.y && event.button.y<=(c4.y+c4.h))
                {
                    c4.tuer=true;
                }
                else if(c5.x<=event.button.x && event.button.x<=(c5.x+c5.w) && c5.y<=event.button.y && event.button.y<=(c5.y+c5.h))
                {
                    c5.tuer=true;
                }
            }
        }
        if(event.type==SDL_MOUSEMOTION)
        {
            curseurX=event.button.x;
            curseurY=event.button.y;
        }
    }
}

/****************** Nom de la fonction **********************
* gestionRegleJeu
******************** Auteur , Dates *************************
* Nom/Date : Nédélec
* 2/12/2015
********************* Description ***************************
* Gere les evenements liés à la phase des règles du jeu
*********************** Entrées *****************************
* Une variable d'évênement pour gerer chaque evenement
* Un booleen correspondant à la fin du jeu (la fenetre)
* Un booleen correspondant à la phase des règles
* Un booleen correspondant à la phase de jeu qui suit les règles
*********************** Sorties *****************************
* Rien
************************************************************/
void gestionRegleJeu(SDL_Event &event, bool &quitter, bool &modeRegle, bool &modeNormal)
{
    while(SDL_PollEvent(&event))
    {
        if(event.type==SDL_QUIT)
        {
            quitter=true;
        }
        if(keystates[SDLK_ESCAPE])
        {
            modeNormal=false;
        }
        if(keystates[SDLK_RETURN])
        {
            modeRegle=false;
            modeNormal=true;
        }
    }
}
