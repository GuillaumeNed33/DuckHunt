#include "gestionScore.h"

/****************** Nom de la fonction **********************
* initTabCan
******************** Auteur , Dates *************************
* Nom/Date : VIOLA
* 2/12/2015
********************* Description ***************************
* initialise le tableau qui nous sert à l'affichage des icones des canards
* pour qu'ils soit tous blanc
*********************** Entrées *****************************
* tabCan est le tableau qu'on rempli,
* x est l'entier qui correspond à la taille de la première dimension du tableau
* y est l'entier qui correspond à la taille de la deuxième dimension du tableau
*********************** Sorties *****************************
* Rien
************************************************************/
void initTabCan(int tabCan[][2],int x,int y)
{
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
            tabCan[i][j]=0;
    }
}

/****************** Nom de la fonction **********************
* remplirTabCan
******************** Auteur , Dates *************************
* Nom/Date : VIOLA
* 2/12/2015
********************* Description ***************************
* remplit le tableau qui sert à l'affichage des icones des canards
* -1 pour un canard manqué et donc rouge
* 1 pour un canard touché et donc vert
*********************** Entrées *****************************
* tuer et tuer2 sont les booléens qui sont vrai si le canard est mort
* round correspond au numéro du round
* tabCan est le tableau à 2 dimensions dont on se sert pour l'affichage des icones de canards
* tir est l'entier qui contient le nombre de tir restant
*********************** Sorties *****************************
* Rien
************************************************************/
void remplirTabCan(bool tuer, bool tuer2, int round, int tabCan[][2], int tir)
{
    round--;
    //Rempli le tableau selon differentes conditions
    if(tir==0 && !tuer && !tuer2)
    {
        tabCan[round][0]=-1;
        tabCan[round][1]=-1;
    }
    else if(tir==0 && !tuer && tuer2)
    {
        tabCan[round][0]=-1;
    }
    else if(tir==0 && tuer && !tuer2)
    {
        tabCan[round][1]=-1;
    }

    if(tuer)
    {
        tabCan[round][0]=1;
    }
    if(tuer2)
    {
        tabCan[round][1]=1;
    }
}
/****************** Nom de la fonction **********************
* afficheScoreCan
******************** Auteur , Dates *************************
* Nom/Date : NEDELEC
* 2/12/2015
********************* Description ***************************
* affiche les icones des canards blanc tant que le niveau n'est pas fini et qu'ils ne sont pas touché
* vert si ils sont touchés
* rouge si ils ne sont pas touchés à la fin du round
*********************** Entrées *****************************
* tabCan est le tableau à 2 dimensions dont on se sert pour l'affichage des icones de canards
* screen est la surface sur laquelle on affiche les icones
* canard score est la surface qui contient les images des icones des canards
*********************** Sorties *****************************
* Rien
************************************************************/
void afficheScoreCan(int TabCan[][2], SDL_Surface* &screen, SDL_Surface* canardScore)
{
    SDL_Rect lectureInit, lectureTouche, lectureRate;

    lectureInit.x=9;
    lectureInit.y=8;
    lectureInit.w=21;
    lectureInit.h=21;

    lectureRate.x=33;
    lectureRate.y=8;
    lectureRate.w=21;
    lectureRate.h=21;

    lectureTouche.x=57;
    lectureTouche.y=8;
    lectureTouche.w=21;
    lectureTouche.h=21;

    if(TabCan[0][0]==0)
    {
        applySurface(202,675,canardScore,screen,&lectureInit);
    }
    else if(TabCan[0][0]==1)
    {
        applySurface(202,675,canardScore,screen,&lectureTouche);
    }
    else
    {
        applySurface(202,675,canardScore,screen,&lectureRate);
    }

    if(TabCan[0][1]==0)
    {
        applySurface(232,675,canardScore,screen,&lectureInit);
    }
    else if(TabCan[0][1]==1)
    {
        applySurface(232,675,canardScore,screen,&lectureTouche);
    }
    else
    {
        applySurface(232,675,canardScore,screen,&lectureRate);
    }

    if(TabCan[1][0]==0)
    {
        applySurface(262,675,canardScore,screen,&lectureInit);
    }
    else if(TabCan[1][0]==1)
    {
        applySurface(262,675,canardScore,screen,&lectureTouche);
    }
    else
    {
        applySurface(262,675,canardScore,screen,&lectureRate);
    }

    if(TabCan[1][1]==0)
    {
        applySurface(292,675,canardScore,screen,&lectureInit);
    }
    else if(TabCan[1][1]==1)
    {
        applySurface(292,675,canardScore,screen,&lectureTouche);
    }
    else
    {
        applySurface(292,675,canardScore,screen,&lectureRate);
    }

    if(TabCan[2][0]==0)
    {
        applySurface(322,675,canardScore,screen,&lectureInit);
    }
    else if(TabCan[2][0]==1)
    {
        applySurface(322,675,canardScore,screen,&lectureTouche);
    }
    else
    {
        applySurface(322,675,canardScore,screen,&lectureRate);
    }

    if(TabCan[2][1]==0)
    {
        applySurface(352,675,canardScore,screen,&lectureInit);
    }
    else if(TabCan[2][1]==1)
    {
        applySurface(352,675,canardScore,screen,&lectureTouche);
    }
    else
    {
        applySurface(352,675,canardScore,screen,&lectureRate);
    }

    if(TabCan[3][0]==0)
    {
        applySurface(382,675,canardScore,screen,&lectureInit);
    }
    else if(TabCan[3][0]==1)
    {
        applySurface(382,675,canardScore,screen,&lectureTouche);
    }
    else
    {
        applySurface(382,675,canardScore,screen,&lectureRate);
    }

    if(TabCan[3][1]==0)
    {
        applySurface(412,675,canardScore,screen,&lectureInit);
    }
    else if(TabCan[3][1]==1)
    {
        applySurface(412,675,canardScore,screen,&lectureTouche);
    }
    else
    {
        applySurface(412,675,canardScore,screen,&lectureRate);
    }

    if(TabCan[4][0]==0)
    {
        applySurface(442,675,canardScore,screen,&lectureInit);
    }
    else if(TabCan[4][0]==1)
    {
        applySurface(442,675,canardScore,screen,&lectureTouche);
    }
    else
    {
        applySurface(442,675,canardScore,screen,&lectureRate);
    }

    if(TabCan[4][1]==0)
    {
        applySurface(472,675,canardScore,screen,&lectureInit);
    }
    else if(TabCan[4][1]==1)
    {
        applySurface(472,675,canardScore,screen,&lectureTouche);
    }
    else
    {
        applySurface(472,675,canardScore,screen,&lectureRate);
    }

}

/****************** Nom de la fonction **********************
* attributScoreCanard
******************** Auteur , Dates *************************
* Nom/Date : VIOLA
* 2/12/2015
********************* Description ***************************
*compte le nombre de canards tués au cours du round
*********************** Entrées *****************************
* tabCan est le tableau à 2 dimensions dont on se sert pour l'affichage des icones de canards
* x est l'entier qui correspond à la taille de la première dimension du tableau
* y est l'entier qui correspond à la taille de la deuxième dimension du tableau
*********************** Sorties *****************************
*
************************************************************/
int attributScoreCanard(int TabCan[][2],int x, int y)
{
    int scoreCanard=0;
    for(int i=0; i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            if(TabCan[i][j]==1)
            {
                scoreCanard++;
            }
        }
    }
    return scoreCanard;
}

/****************** Nom de la fonction **********************
* afficheCartouche
******************** Auteur , Dates *************************
* Nom/Date : NEDELEC
* 2/12/2015
********************* Description ***************************
* Affichage du nombres de balles restantes.
*********************** Entrées *****************************
* entier tir correspondant au nombre de tirs restants
* SDL_Surface sur lequel on affiche les images de cartouches
* Le SDL_Surface correspondant a l'image des cartouches
*********************** Sorties *****************************
* Rien
************************************************************/
void afficheCartouche(int tir, SDL_Surface* &screen,SDL_Surface* cartouche0,SDL_Surface* cartouche1,SDL_Surface* cartouche2,SDL_Surface* cartouche3)
{
    if(tir==0)
    {
        applySurface(65,660,cartouche0,screen,NULL);
    }
    else
    {
        switch(tir%3)
        {
        //Affichage des cartouche
        case 0:
            applySurface(65,660,cartouche3,screen,NULL);
            break;
        case 1:
            applySurface(65,660,cartouche1,screen,NULL);
            break;

        case 2:
            applySurface(65,660,cartouche2,screen,NULL);
            break;
        }
    }
}

/****************** Nom de la fonction **********************
* compteScore
******************** Auteur , Dates *************************
* Nom/Date : NEDELEC
* 2/12/2015
********************* Description ***************************
* Calcul le score de l'utilisateur durant le jeu
*********************** Entrées *****************************
* Un entier correspondant au score
* Un canard qui est géré
*********************** Sorties *****************************
* Rien
************************************************************/
void compteScore(int &score, canard can)
{
    if(can.tuer)
    {
        //Point selon la couleur
        switch (can.couleur%3) {
        case 0:
            score+=500;
            break;
        case 1:
            score+=1000;
            break;
        case 2:
            score+=1500;
            break;
        }
    }
}

/****************** Nom de la fonction **********************
* recuperChicken
******************** Auteur , Dates *************************
* Nom/Date : VIOLA
* 2/12/2015
********************* Description ***************************
* Fonction qui determine si le canard est dans le bucket ou non.
* Si la cuisse a donc bien été récupérer pendant sa chute.
*********************** Entrées *****************************
* Un SDL_Rect de la position du Bucket
* Un poulet de la structure "chicken"
*********************** Sorties *****************************
* Rien
************************************************************/
void recuperChicken(SDL_Rect &bucketPos, chicken &c)
{
    if(c.tuer)
    {
        if(bucketPos.x<c.x && c.x<bucketPos.x+(bucketPos.w-c.w)) //Verifie les coordonnes pour dire que la cuisse est bien récupérée
        {
            if(bucketPos.y-3<=c.y+c.h && c.y+c.h<bucketPos.y)
            {
                c.entreDansLeBucket=true;
            }
        }
    }
}

/****************** Nom de la fonction **********************
* atttributScoreBucket
******************** Auteur , Dates *************************
* Nom/Date : NEDELEC
* 2/12/2015
********************* Description ***************************
* Rajoute des points au score si le poulet est bien récupérer dans le bucket.
*********************** Entrées *****************************
* Un entier du score
* Un booleen indiquant si le poulet est bien récupérer dans le bucket.
*********************** Sorties *****************************
* Rien
************************************************************/
void atttributScoreBucket(int &score, bool entreDansLeBucket)
{
    if(entreDansLeBucket)
    {
        score+=1000;
    }
}
/****************** Nom de la fonction **********************
* attributScoreChicken
******************** Auteur , Dates *************************
* Nom/Date : NEDELEC
* 2/12/2015
********************* Description ***************************
* Rajoute des points au score si le poulet est touché par l'utilisateur
*********************** Entrées *****************************
* Un entier du score
* Un booleen indiquant si le poulet a été tué ou non
*********************** Sorties *****************************
* Rien
************************************************************/
void attributScoreChicken(int &score, bool tuer)
{
    if(tuer)
    {
        score+=300;
    }
}
