#include "chicken.h"

/****************** Nom de la fonction **********************
* initChicken
******************** Auteur , Dates *************************
* Nom/Date : VIOLA
* 2/12/2015
********************* Description ***************************
* Initialise les caracteristiques des poulets, leur positions dans la fenetre,
* leur vitesse de deplacements, et leur direction de départ,ainsi que tous les booléens que l'on utilisera.
*********************** Entrées *****************************
* "c" est le poulet qui va être initialisé
*********************** Sorties *****************************
* Rien
************************************************************/
void initChicken(chicken &c)
{
    c.x = rand()%(SCREEN_WIDTH-100);//position de départ aléatoire
    c.y = rand()%(SCREEN_HEIGHT-320-100);//position de départ aléatoire
    c.h=tailleChicken;
    c.w=tailleChicken;
    if((rand()%2)<1)//direction de départ aléatoire
    {
        c.vitesse_x=1;
    }
    else
    {
        c.vitesse_x=-1;
    }
    if((rand()%2)<1)//direction de départ aléatoire
    {
        c.vitesse_y=1;
    }
    else
    {
        c.vitesse_y=-1;
    }
    c.mort=0;
    c.tuer=false;
    c.sorti=false;
    c.entreDansLeBucket=false;
    c.dansLeBucket=false;
    c.scorer=false;
}

/****************** Nom de la fonction **********************
* showChicken
******************** Auteur , Dates *************************
* Nom/Date : VIOLA
* 2/12/2015
********************* Description ***************************
* Affiche les sprites de poulet a la position des poulets et
* les modifient selon leurs mouvements, en affectant la hauteur et la largeur des poulets à chaque changement d'image
*********************** Entrées *****************************
* "c" est le poulet qui est géré
* screen est la surface sur laquelle on affiche le canard
* chickenFly est la surface qui contient les sprites des poulets
* point_touche est la surface qui contient les images des points quand on tue le poulet
* point_bucket est la surface qui contient les images des points quand on récupère le poulet dans le bucket
* fail est la surface qui contient l'image de "fail" quand on manque la récupération du poulet dans le bucket
* cpt est un entier qui nous sert de compteur pour faire une alternance d'affichage d'image
*********************** Sorties *****************************
* Rien
************************************************************/
void showChicken(chicken &c, SDL_Surface* &screen, SDL_Surface*  chickenFly, SDL_Surface* point_touche,SDL_Surface* point_bucket,SDL_Surface* fail,int cpt)
{
    SDL_Rect lectureVol,lectureVol2,lectureVol3;
    SDL_Rect LectureCuisse , LectureTouche;

    LectureCuisse.x=169;
    LectureCuisse.y=82;
    LectureCuisse.w=29;
    LectureCuisse.h=63;

    LectureTouche.x=250;
    LectureTouche.y=340;
    LectureTouche.w=107;
    LectureTouche.h=110;

    lectureVol.x=30;
    lectureVol.y=224;
    lectureVol.w=85;
    lectureVol.h=105;

    lectureVol2.x=143;
    lectureVol2.y=226;
    lectureVol2.w=94;
    lectureVol2.h=109;

    lectureVol3.x=262;
    lectureVol3.y=226;
    lectureVol3.w=92;
    lectureVol3.h=114;

    if(c.tuer==false)
    {
        switch(cpt%3)
        {
        case 0:
            c.w=lectureVol.w;
            c.h=lectureVol.h;
            applySurface(c.x,c.y,chickenFly,screen,&lectureVol);
            break;
        case 1:
            c.w=lectureVol2.w;
            c.h=lectureVol2.h;
            applySurface(c.x,c.y,chickenFly,screen,&lectureVol2);
            break;
        case 2:
            c.w=lectureVol3.w;
            c.h=lectureVol3.h;
            applySurface(c.x,c.y,chickenFly,screen,&lectureVol3);
            break;
        }
        c.mort=cpt;
    }
    else if(c.tuer && c.mort>=cpt-2)//stop le poulet pendant 2 tours lorsque il est touché
    {

        applySurface(c.x,c.y,chickenFly,screen,&LectureTouche);
        applySurface(c.x+80,c.y,point_touche,screen,NULL);
    }
    //Affichage quand on rate une cuisse
    else if(c.tuer && c.y>SCREEN_HEIGHT-270 && !c.dansLeBucket)
    {
        applySurface(c.x,SCREEN_HEIGHT-330,fail,screen,NULL);
    }
    //Affichage quand on recupere une cuisse
    else if(c.tuer && c.y>SCREEN_HEIGHT-270 && c.dansLeBucket)
    {
        applySurface(c.x,SCREEN_HEIGHT-330,point_bucket,screen,NULL);
    }
    //Affichage cuisse
    else
    {
        c.w=LectureCuisse.w;
        c.h=LectureCuisse.h;
        applySurface(c.x,c.y,chickenFly,screen,&LectureCuisse);
    }

}

/****************** Nom de la fonction **********************
* moveChicken
******************** Auteur , Dates *************************
* Nom/Date : VIOLA / NEDELEC
* 2/12/2015
********************* Description ***************************
* Gère les déplacements des poulets en les faisant rebondir sur les bords de la fenetre, au niveau de l'herbe.
* Elle les fait également s'arreter quand ils sont touchés puis tomber.
*********************** Entrées *****************************
* "c" est le poulet qui est géré
* cpt est un entier qui nous sert de compteur pour faire s'arreter le poulet quand il est touché
*********************** Sorties *****************************
* Rien
************************************************************/
void moveChicken(chicken &c,int cpt)
{

    c.x+=c.vitesse_x;
    c.y+=c.vitesse_y;

    if(!c.tuer)
    {
        //Rebondis quand un poulet touche les murs
        if(c.x+c.w>SCREEN_WIDTH)
        {
            c.vitesse_x*=-1;
        }

        if(c.x<10)
        {
            c.vitesse_x*=-1;
        }

        if(c.y<10)
        {
            c.vitesse_y*=-1;
        }

        if(c.y+c.h>SCREEN_HEIGHT-280)
        {
            c.vitesse_y*=-1;
        }

    }
    //Quand poulet est touché
    else if (c.tuer && c.y<SCREEN_HEIGHT-c.h-185)
    {
        //Touché = arret du poulet
        if(c.mort>=cpt-2)
        {
            c.vitesse_x=0;
            c.vitesse_y=0;
        }
        //Chute du poulet
        else
        {
            c.vitesse_x=0;
            c.vitesse_y=3;
        }
    }
    else
    {
        c.vitesse_x=0;
        c.vitesse_y=0;
        c.sorti=true;
    }
}

/****************** Nom de la fonction **********************
* garderChickenDansBucket
******************** Auteur , Dates *************************
* Nom/Date : VIOLA
* 2/12/2015
********************* Description ***************************
* Sert à conserver la cuisse du poulet à l'intérieur du bucket à partir du moment où elle a commencé à y entrer.
* Cela permet de conserver l'affichage de la cuisse à l'intérieur du bucket.
*********************** Entrées *****************************
* "c" est le poulet qui est géré
* bucket est le sdl_rect qui contient les données de position, largeur et hauteur du bucket
*********************** Sorties *****************************
* Rien
************************************************************/
void garderChickenDansBucket(chicken &c, SDL_Rect bucket)
{
    if(c.dansLeBucket)
    {
        if(c.x<bucket.x+20)
        {
            c.x=bucket.x+20;
        }
        else if(bucket.x+bucket.w-c.w-20<c.x)
        {
            c.x=bucket.x+bucket.w-c.w-20;
        }
    }
}

/****************** Nom de la fonction **********************
* changerDirectionCanard
******************** Auteur , Dates *************************
* Nom/Date : VIOLA
* 2/12/2015
********************* Description ***************************
* Rend les déplacements des poulets aléatoires en changeant leur direction de façon aléatoire tous les 200 tours de boucle.
*********************** Entrées *****************************
* cpt est un entier qui va nous servir de compteur pour changer la direction des poulets tous les 200 tours de boucle
* "c" est le poulet qui est géré
*********************** Sorties *****************************
* Rien
************************************************************/
void changerDirectionChicken(int cpt,chicken &c)
{
    if(cpt%200==199)
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
