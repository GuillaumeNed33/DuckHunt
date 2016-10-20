#include "canard.h"

/****************** Nom de la fonction **********************
* initCanard
******************** Auteur , Dates *************************
* Nom/Date : VIOLA
* 2/12/2015
********************* Description ***************************
* Initialise les caracteristiques des canards, leurs positions dans la fenetre,
* leurs vitesse de deplacements, et leurs direction de départ,ainsi que tous les booléens que l'on utilisera.
*********************** Entrées *****************************
* Un canard de la structure "canard"
* Un entier representant le niveau pour adapter la vitesse des canards
*********************** Sorties *****************************
* Rien
************************************************************/
void initCanard(canard &can,int lvl)
{
    can.posX = rand()%(SCREEN_WIDTH-100);//position de départ aléatoire
    can.posY = rand()%(SCREEN_HEIGHT-320-100);//position de départ aléatoire
    can.h=TAILLE;
    can.w=TAILLE;
    can.couleur=rand()%3; //couleur des canards
    if(can.couleur==0)
    {
        can.vitesse_x = 2*((lvl*1.0)/2);//vitesse en fonction du niveau
        can.vitesse_y = 2*((lvl*1.0)/2);
    }
    if(can.couleur==1)
    {
        can.vitesse_x = 2.5*((lvl*1.0)/2);
        can.vitesse_y = 2.5*((lvl*1.0)/2);
    }
    if(can.couleur==2)
    {
        can.vitesse_x = 3*((lvl*1.0)/2);
        can.vitesse_y = 3*((lvl*1.0)/2);
    }
    if((rand()%2)<1)//direction de départ aléatoire
    {
        can.vitesse_x*=1;
    }
    else
    {
        can.vitesse_x*=-1;
    }
    if((rand()%2)<1)//direction de départ aléatoire
    {
        can.vitesse_y*=1;
    }
    else
    {
        can.vitesse_y*=-1;
    }
    can.mort=0;
    can.tuer=false;
    can.sorti=false;
    can.scorer=false;
}

/****************** Nom de la fonction **********************
* showCanard
******************** Auteur , Dates *************************
* Nom/Date : Nédélec
* 2/12/2015
********************* Description ***************************
* Affiche les sprites de canard a la position des canards et
* les modifient selon leurs mouvements, en affectant la hauteur et la largeur des canards à chaque changement d'image
*********************** Entrées *****************************
* Un canard de la structure "canard"
* Un SDL_Surface sur lequel on applique l'image du canard
* Un SDL_Surface contenant l'image de la feuille de sprites
* Un SDL_Surface contenant l'image des points de chaque canard
* Un entier compteur qui nous sert pour faire une alternace d'image
*********************** Sorties *****************************
* Rien
************************************************************/
void showCanard(canard &can, SDL_Surface *&s,SDL_Surface *sprite,SDL_Surface* points,int cpt)
{   
    SDL_Rect LectureCan; //Nos cadres de lectures de la surface sprite
    SDL_Rect LectureCan2;
    SDL_Rect LectureCan3;
    SDL_Rect Lecture2Can;
    SDL_Rect Lecture2Can2;
    SDL_Rect Lecture2Can3;
    SDL_Rect Lecture3Can;
    SDL_Rect Lecture3Can2;
    SDL_Rect Lecture3Can3;
    SDL_Rect LectureTouche;
    SDL_Rect LectureTouche2;
    SDL_Rect LectureTouche3;
    SDL_Rect LectureTombe;
    SDL_Rect LectureTombe2;
    SDL_Rect LectureTombe3;
    SDL_Rect Lecture2Tombe;
    SDL_Rect Lecture2Tombe2;
    SDL_Rect Lecture2Tombe3;
    SDL_Rect LecturePoints1;
    SDL_Rect LecturePoints2;
    SDL_Rect LecturePoints3;

    LectureCan.x =20;
    LectureCan.y =230;
    LectureCan.w =54;
    LectureCan.h =62;

    LectureCan2.x =82;
    LectureCan2.y =234;
    LectureCan2.w =64;
    LectureCan2.h =58;

    LectureCan3.x =150;
    LectureCan3.y =234;
    LectureCan3.w =50;
    LectureCan3.h =62;


    Lecture2Can.x =20;
    Lecture2Can.y =316;
    Lecture2Can.w =54;
    Lecture2Can.h =62;

    Lecture2Can2.x =82;
    Lecture2Can2.y =320;
    Lecture2Can2.w =64;
    Lecture2Can2.h =58;

    Lecture2Can3.x =150;
    Lecture2Can3.y =320;
    Lecture2Can3.w =50;
    Lecture2Can3.h =62;

    Lecture3Can.x =16;
    Lecture3Can.y =402;
    Lecture3Can.w =54;
    Lecture3Can.h =62;

    Lecture3Can2.x =78;
    Lecture3Can2.y =406;
    Lecture3Can2.w =64;
    Lecture3Can2.h =58;

    Lecture3Can3.x =146;
    Lecture3Can3.y =406;
    Lecture3Can3.w =50;
    Lecture3Can3.h =62;

    LectureTouche.x=456;
    LectureTouche.y=250;
    LectureTouche.w=62;
    LectureTouche.h=58;

    LectureTouche2.x=452;
    LectureTouche2.y=330;
    LectureTouche2.w=62;
    LectureTouche2.h=58;

    LectureTouche3.x=448;
    LectureTouche3.y=416;
    LectureTouche3.w=62;
    LectureTouche3.h=58;

    LectureTombe.x=538;
    LectureTombe.y=246;
    LectureTombe.w=36;
    LectureTombe.h=62;

    LectureTombe2.x=532;
    LectureTombe2.y=328;
    LectureTombe2.w=36;
    LectureTombe2.h=62;

    LectureTombe3.x=530;
    LectureTombe3.y=412;
    LectureTombe3.w=36;
    LectureTombe3.h=62;

    Lecture2Tombe.x=586;
    Lecture2Tombe.y=246;
    Lecture2Tombe.w=36;
    Lecture2Tombe.h=62;

    Lecture2Tombe2.x=580;
    Lecture2Tombe2.y=328;
    Lecture2Tombe2.w=36;
    Lecture2Tombe2.h=62;

    Lecture2Tombe3.x=578;
    Lecture2Tombe3.y=412;
    Lecture2Tombe3.w=36;
    Lecture2Tombe3.h=62;

    LecturePoints3.x=8;
    LecturePoints3.y=10;
    LecturePoints3.w=28;
    LecturePoints3.h=14;

    LecturePoints2.x=8;
    LecturePoints2.y=26;
    LecturePoints2.w=28;
    LecturePoints2.h=14;

    LecturePoints1.x=8;
    LecturePoints1.y=42;
    LecturePoints1.w=28;
    LecturePoints1.h=14;

    if(!can.tuer)
    {
        //Gestion affichage selon la couleur
        switch(can.couleur%3) {
        case 0:
            switch(cpt%3) {
            case 0:
                can.w=LectureCan.w;
                can.h=LectureCan.h;
                applySurface(can.posX,can.posY,sprite,s,&LectureCan);
                break;
            case 1:
                can.w=LectureCan2.w;
                can.h=LectureCan2.h;
                applySurface(can.posX,can.posY,sprite,s,&LectureCan2);
                break;
            case 2 :
                can.w=LectureCan3.w;
                can.h=LectureCan3.h;
                applySurface(can.posX,can.posY,sprite,s,&LectureCan3);
                break;
            }
            break;

        case 1:
            switch(cpt%3) {
            case 0:
                can.w=Lecture2Can.w;
                can.h=Lecture2Can.h;
                applySurface(can.posX,can.posY,sprite,s,&Lecture2Can);
                break;
            case 1:
                can.w=Lecture2Can2.w;
                can.h=Lecture2Can2.h;
                applySurface(can.posX,can.posY,sprite,s,&Lecture2Can2);
                break;
            case 2 :
                can.w=Lecture2Can3.w;
                can.h=Lecture2Can3.h;
                applySurface(can.posX,can.posY,sprite,s,&Lecture2Can3);
                break;
            }
            break;

        case 2:
            switch(cpt%3) {
            case 0:
                can.w=Lecture3Can.w;
                can.h=Lecture3Can.h;
                applySurface(can.posX,can.posY,sprite,s,&Lecture3Can);

                break;
            case 1:
                can.w=Lecture3Can2.w;
                can.h=Lecture3Can2.h;
                applySurface(can.posX,can.posY,sprite,s,&Lecture3Can2);
                break;
            case 2 :
                can.w=Lecture3Can3.w;
                can.h=Lecture3Can3.h;
                applySurface(can.posX,can.posY,sprite,s,&Lecture3Can3);
                break;
            }
            break;
        }

        can.mort=cpt;
    }
    //Affichage quand le canard est touche
    else if(can.tuer && can.mort>=cpt-5)
    {
        switch(can.couleur%3) {
        case 0:
            applySurface(can.posX,can.posY,sprite,s,&LectureTouche);
            applySurface(can.posX+60,can.posY,points,s,&LecturePoints1);
            break;
        case 1:
            applySurface(can.posX,can.posY,sprite,s,&LectureTouche2);
            applySurface(can.posX+60,can.posY,points,s,&LecturePoints2);
            break;
        case 2 :
            applySurface(can.posX,can.posY,sprite,s,&LectureTouche3);
            applySurface(can.posX+60,can.posY,points,s,&LecturePoints3);
            break;
        }
    }
    //Affichage de la chute
    else
    {
        switch(can.couleur%3) {
        case 0:
            switch (cpt%2) {
            case 0:
                applySurface(can.posX,can.posY,sprite,s,&LectureTombe);
                break;
            case 1:
                applySurface(can.posX,can.posY,sprite,s,&Lecture2Tombe);
                break;
            }
            break;
        case 1:
            switch (cpt%2) {
            case 0:
                applySurface(can.posX,can.posY,sprite,s,&LectureTombe2);
                break;
            case 1:
                applySurface(can.posX,can.posY,sprite,s,&Lecture2Tombe2);
                break;
            }
            break;
        case 2 :
            switch (cpt%2) {
            case 0:
                applySurface(can.posX,can.posY,sprite,s,&LectureTombe3);
                break;
            case 1:
                applySurface(can.posX,can.posY,sprite,s,&Lecture2Tombe3);
                break;
            }
            break;
        }
    }
}

/****************** Nom de la fonction **********************
* moveCanard
******************** Auteur , Dates *************************
* Nom/Date : Nédélec
* 2/12/2015
********************* Description ***************************
* Gere les déplacements des canards en les faisant rebondir sur les bords de la fenetre, au niveau de l'herbe.
* Elle les fait également s'arreter quand ils sont touchés puis les fait tomber.
*********************** Entrées *****************************
* Un canard de la structure "canard"
* Un entier pour indiquer le nombre de tir restant
* Un entier compteur pour gerer un arret lorsque le canard est touché
* Un entier mort qui possède la valeur du compteur à laquelle le canard a été touché.
*********************** Sorties *****************************
* Rien
************************************************************/
void moveCanard(canard &can,int tir,int cpt)
{
    can.posX+=can.vitesse_x;
    can.posY+=can.vitesse_y;

    if(!can.tuer && tir!=0)
    {
        //Rebondis contre les murs et contre l'herbe
        if(can.posX+can.w>SCREEN_WIDTH)
        {
            can.vitesse_x*=-1;
        }

        if(can.posX<0)
        {
            can.vitesse_x*=-1;
        }

        if(can.posY<0)
        {
            can.vitesse_y*=-1;
        }

        if(can.posY+can.h>SCREEN_HEIGHT-265)
        {
            can.vitesse_y*=-1;
        }
    }
    //Mouvement de la fuite des canards
    else if(!can.tuer && tir==0)
    {
        can.vitesse_x=8;
        can.vitesse_y=-8;
        if(SCREEN_WIDTH<can.posX && can.posY<0)
        {
            can.sorti=true;
            can.vitesse_x=0;
            can.vitesse_y=0;
        }
    }
    //Mouvement quand le canard est touché
    else if (can.tuer && can.posY<SCREEN_HEIGHT-can.h)
    {
        //Touché
        if(can.mort>=cpt-5)
        {
            can.vitesse_x=0;
            can.vitesse_y=0;
        }
        //Chute
        else
        {
            can.vitesse_x=0;
            can.vitesse_y=4;
        }
    }
    else
    {
        can.vitesse_x=0;
        can.vitesse_y=0;
        can.sorti=true;
    }
}

/****************** Nom de la fonction **********************
* changerDirectionCanard
******************** Auteur , Dates *************************
* Nom/Date : VIOLA
* 2/12/2015
********************* Description ***************************
* Rend les déplacements des canards aléatoires en changeant leur direction de façon aléatoire tous les 100 tours de boucle.
*********************** Entrées *****************************
* cpt est un entier qui va nous servir de compteur pour changer la direction des canards tous les 100 tours de boucle
* Un canard de la structure "canard"
*********************** Sorties *****************************
* Rien
************************************************************/
void changerDirectionCanard(int cpt,canard &c)
{
    if(cpt%100==99)
    {
        if((rand()%2)<1)
        {
            c.vitesse_x*=1;
        }
        else
        {
            c.vitesse_x*=-1;
        }

        if((rand()%2)<1)
        {
            c.vitesse_y*=1;
        }
        else
        {
            c.vitesse_y*=-1;
        }
    }
}
