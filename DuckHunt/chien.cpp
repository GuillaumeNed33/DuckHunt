#include "chien.h"

/****************** Nom de la fonction **********************
* faireRireLeChien
******************** Auteur , Dates *************************
* Nom/Date : VIOLA
* 2/12/2015
********************* Description ***************************
* Animation du chien qui rit
*********************** Entrées *****************************
* Un SDL_Rect correspondant à la position ou le chien apparait
* Un SDL_Surface correspondant à la surface sur laquelle on applique l'animation
* Un SDL_Surface correspondant à la surface de la feuille de sprite
* Un SDL_Surface correspondant à la surface de l'image de fond appliquée en dernière (Le Blit)
* Un booleen indiquant à quel moment le chien peut redescendre
* Un entier compteur pour l'enchainement des images.
* Un booleen indiquant la fin d'une phase de jeu pour lancer l'animation.
*********************** Sorties *****************************
* retourne un booléen qui vaut vrai tant que le chien n'a pas fini de rire
************************************************************/
bool faireRireLeChien(SDL_Rect &chienQuiRit, SDL_Surface* &screen, SDL_Surface* sprite, SDL_Surface* terrain, bool &descendre, int cpt,bool &fin)
{
    SDL_Rect lectureChienQuiRit, lectureChienQuiRitBis;
    lectureChienQuiRit.x=580;
    lectureChienQuiRit.y=24;
    lectureChienQuiRit.h=78;
    lectureChienQuiRit.w=58;

    lectureChienQuiRitBis.x=642;
    lectureChienQuiRitBis.y=24;
    lectureChienQuiRitBis.h=78;
    lectureChienQuiRitBis.w=58;

    if(chienQuiRit.y<=SCREEN_HEIGHT/2+65)// quand le chien arrive à cette hauteur il se stope une demi secondes avant de descendre
    {
        descendre=true;
        SDL_Delay(500);
    }
    if(descendre && chienQuiRit.y>=SCREEN_HEIGHT/2+130)// quand le chien arrive en bas, il s'arrete.
    {
        descendre=false;
        fin=true;
    }

    if(!descendre)
    {
        if(cpt%2==0)// tout les tours de boucle on change l'affichage du chien pour donner l'impression qu'il rit
        {
            applySurface(chienQuiRit.x,chienQuiRit.y,sprite,screen,&lectureChienQuiRit);
        }
        else
        {
            applySurface(chienQuiRit.x,chienQuiRit.y,sprite,screen,&lectureChienQuiRitBis);
        }
        chienQuiRit.y-=4;
    }

    if(descendre)
    {
        if(cpt%2==0)// tout les tours de boucle on change l'affichage du chien pour donner l'impression qu'il rit
        {
            applySurface(chienQuiRit.x,chienQuiRit.y,sprite,screen,&lectureChienQuiRit);
        }
        else
        {
            applySurface(chienQuiRit.x,chienQuiRit.y,sprite,screen,&lectureChienQuiRitBis);
        }
        chienQuiRit.y+=4;
    }
    applySurface(0,0,terrain,screen,NULL);// on applique le terrain par dessus pour que le chien soit bien derrière
    if(fin)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/****************** Nom de la fonction **********************
* faireMarcherLeChien
******************** Auteur , Dates *************************
* Nom/Date : VIOLA
* 2/12/2015
********************* Description ***************************
* Animation du chien qui marche au debut de chaque niveau
*********************** Entrées *****************************
* Un SDL_Rect correspondant à la position ou le chien apparait
* Un SDL_Surface correspondant à la surface sur laquelle on applique l'animation
* Un SDL_Surface correspondant à la surface de la feuille de sprite
* Un SDL_Surface correspondant à la surface de l'image de fond appliquée en dernière (Le Blit)
* Un booleen indiquant que l'animation peut commencer.
* Un entier compteur pour l'enchainement des images du chien.
*********************** Sorties *****************************
* Rien
************************************************************/
void faireMarcherLeChien(SDL_Rect &chienQuiMarche, SDL_Surface* &screen, SDL_Surface* sprite, SDL_Surface* terrain, bool &debut, int cpt)
{
    SDL_Rect lectureChienQuiMarche,lectureChienQuiMarche2,lectureChienQuiMarche3,lectureChienQuiMarche4,lectureChienQuiMarche5, lectureChienQuiMarche6;

    lectureChienQuiMarche.w=106;
    lectureChienQuiMarche.h=80;
    lectureChienQuiMarche.x=8;
    lectureChienQuiMarche.y=10;

    lectureChienQuiMarche2.w=110;
    lectureChienQuiMarche2.h=80;
    lectureChienQuiMarche2.x=120;
    lectureChienQuiMarche2.y=10;

    lectureChienQuiMarche3.w=102;
    lectureChienQuiMarche3.h=86;
    lectureChienQuiMarche3.x=240;
    lectureChienQuiMarche3.y=6;

    lectureChienQuiMarche4.w=106;
    lectureChienQuiMarche4.h=80;
    lectureChienQuiMarche4.x=348;
    lectureChienQuiMarche4.y=12;

    lectureChienQuiMarche5.w=104;
    lectureChienQuiMarche5.h=86;
    lectureChienQuiMarche5.x=462;
    lectureChienQuiMarche5.y=6;

    lectureChienQuiMarche6.w=106;
    lectureChienQuiMarche6.h=96;
    lectureChienQuiMarche6.x=10;
    lectureChienQuiMarche6.y=120;

    SDL_Rect lectureChienQuiSaute, lectureChienQuiSaute2;

    lectureChienQuiSaute.w=70;
    lectureChienQuiSaute.h=92;
    lectureChienQuiSaute.x=130;
    lectureChienQuiSaute.y=112;

    lectureChienQuiSaute2.w=66;
    lectureChienQuiSaute2.h=74;
    lectureChienQuiSaute2.x=214;
    lectureChienQuiSaute2.y=140;

    if(debut && chienQuiMarche.x<=(SCREEN_WIDTH-200)/2)// le chien marche jusqu'a ce point
    {
        switch (cpt%5) { // un compteur pour changer l'affichage à tous les tours de boucle et ainsi donner l'impression que le chien marche

        case 0:
            applySurface(chienQuiMarche.x,chienQuiMarche.y,sprite,screen,&lectureChienQuiMarche);
            break;

        case 1:
            applySurface(chienQuiMarche.x,chienQuiMarche.y,sprite,screen,&lectureChienQuiMarche2);
            break;

        case 2:
            applySurface(chienQuiMarche.x,chienQuiMarche.y,sprite,screen,&lectureChienQuiMarche3);
            break;

        case 3:
            applySurface(chienQuiMarche.x,chienQuiMarche.y,sprite,screen,&lectureChienQuiMarche4);
            break;

        case 4:
            applySurface(chienQuiMarche.x,chienQuiMarche.y,sprite,screen,&lectureChienQuiMarche5);
            break;
        }
        chienQuiMarche.x+=20;
        SDL_Delay(60);
    }
    else if(debut && chienQuiMarche.y==SCREEN_HEIGHT/2+150 && chienQuiMarche.x<=(SCREEN_WIDTH-160)/2)//le chien s'arrete et lève la tête
    {
        applySurface(chienQuiMarche.x,chienQuiMarche.y,sprite,screen,&lectureChienQuiMarche6);
        chienQuiMarche.x+=20;
        SDL_Flip(screen);
        SDL_Delay(750);
    }
    else if(debut && chienQuiMarche.y>=(SCREEN_HEIGHT-400)/2 && chienQuiMarche.x<=SCREEN_WIDTH/2+25)//le chien saute
    {
        chienQuiMarche.x+=20;
        chienQuiMarche.y-=30;
        applySurface(chienQuiMarche.x,chienQuiMarche.y,sprite,screen,&lectureChienQuiSaute);
    }
    else if(debut && chienQuiMarche.x>=(SCREEN_WIDTH)/2+25)// le chien redescent
    {
        chienQuiMarche.x+=10;
        chienQuiMarche.y+=30;

        applySurface(chienQuiMarche.x,chienQuiMarche.y,sprite,screen,&lectureChienQuiSaute2);
        applySurface(0,0,terrain,screen,NULL);

        if(chienQuiMarche.y>=SCREEN_HEIGHT)
        {
            debut=false;
        }
    }
}

/****************** Nom de la fonction **********************
* dernierCanard
******************** Auteur , Dates *************************
* Nom/Date : VIOLA
* 2/12/2015
********************* Description ***************************
* Indique quel est le dernier canard touché pour que le chien apparaisse aux coordonnées correspondantes
*********************** Entrées *****************************
* Un canard de la structure du même nom
* Un second canard de la structure du même nom
* Un entier dernier pour indiquer lequel est le dernier touché.
*********************** Sorties *****************************
* Rien
************************************************************/
void dernierCanard(canard can,canard can2,int &dernier )
{
    if(can.tuer && !can2.tuer)// si le premier canard tué est le canard 1 alors le dernier sera donc le 2
    {
        dernier=2;
    }
    else if(can2.tuer && !can.tuer)// si le premier canard tué est le canard 2 alors le dernier sera donc le 1
    {
        dernier=1;
    }
    //cette fonction initialise dernier qui est un entier qui ne nous servira que si les deux canards sont tués.
}

/****************** Nom de la fonction **********************
* faireRamasserLeChien
******************** Auteur , Dates *************************
* Nom/Date : VIOLA
* 2/12/2015
********************* Description ***************************
* le chien rammasse le ou les canards tué(s) à la fin du round
* il apparait à la position du dernier canard tué
*********************** Entrées *****************************
* Un SDL_Rect correspondant à la position ou le chien apparait
* Un SDL_Surface correspondant à la surface sur laquelle on applique l'animation
* Un SDL_Surface correspondant à la surface de la feuille de sprite
* Un SDL_Surface correspondant à la surface de l'image de fond appliquée en dernière (Le Blit)
* Un booleen indiquant à quel moment le chien peut redescendre
* Un entier compteur pour l'enchainement des images.
* Un booleen indiquant si l'animation est terminée ou non.
* Les 2 canards appartenant à la structures "canard"
* 2 booleens qui verifient si les 2 canards sont en vies ou non.
* Un entier "dernier" indiquant quel est le dernier canard tué.
*********************** Sorties *****************************
* Rien
************************************************************/
void faireRamasserLeChien(SDL_Rect &chienQuiRamasse, SDL_Surface* &screen, SDL_Surface* sprite, SDL_Surface* terrain, bool &descendre, int cpt,bool &fin,canard can, canard can2,int dernier)
{
    SDL_Rect lecture1,lecture11,lecture12,lecture13,lecture2,lecture22,lecture23,lecture3,lecture33;

    lecture1.x=491;
    lecture1.y=133;
    lecture1.w=86;
    lecture1.h=78;

    lecture11.x=582;
    lecture11.y=134;
    lecture11.w=112;
    lecture11.h=78;

    lecture12.x=1160;
    lecture12.y=134;
    lecture12.w=112;
    lecture12.h=78;

    lecture13.x=811;
    lecture13.y=135;
    lecture13.w=112;
    lecture13.h=78;

    lecture2.x=308;
    lecture2.y=130;
    lecture2.w=86;
    lecture2.h=78;

    lecture22.x=697;
    lecture22.y=135;
    lecture22.w=112;
    lecture22.h=78;

    lecture23.x=930;
    lecture23.y=134;
    lecture23.w=112;
    lecture23.h=78;

    lecture3.x=399;
    lecture3.y=131;
    lecture3.w=86;
    lecture3.h=78;

    lecture33.x=1045;
    lecture33.y=134;
    lecture33.w=112;
    lecture33.h=78;

    if(chienQuiRamasse.y<=SCREEN_HEIGHT/2+50)// le  chien monte jusqu'à cette limite
    {
        descendre=true;
        SDL_Delay(500);
    }
    if(descendre && chienQuiRamasse.y>=SCREEN_HEIGHT/2+130)// le chien descend jusqu'à cette limite
    {
        descendre=false;
        fin=true;
    }

    if(can.tuer && !can2.tuer)//si on a tué que le canard 1 le chien le rammasse
    {
        if(!descendre)
        {

            chienQuiRamasse.y--;
        }

        if(descendre)
        {
            chienQuiRamasse.y++;
        }

        if(can.posX<=lecture1.w/2)//pour ne pas que l'affichage du chien sorte de l'écran
        {
            can.posX=lecture1.w/2;
        }
        else if(can.posX>=SCREEN_WIDTH-(lecture1.w/2))
        {
            can.posX=SCREEN_WIDTH-(lecture1.w/2);
        }

        switch (can.couleur%3) { // on affiche l'image du chien qui ramasse avec la bonne couleur du canard
        case 0:
            applySurface(can.posX-lecture1.w/2,chienQuiRamasse.y,sprite,screen,&lecture1);
            break;
        case 1:
            applySurface(can.posX-lecture1.w/2,chienQuiRamasse.y,sprite,screen,&lecture2);
            break;
        case 2:
            applySurface(can.posX-lecture1.w/2,chienQuiRamasse.y,sprite,screen,&lecture3);
            break;
        }
    }
    if(!can.tuer && can2.tuer)//si on a tué que le canard 2 le chien le rammasse
    {
        if(!descendre)
        {

            chienQuiRamasse.y--;
        }

        if(descendre)
        {
            chienQuiRamasse.y++;
        }

        if(can2.posX<=lecture1.w/2)//pour ne pas que l'affichage du chien sorte de l'écran
        {
            can2.posX=lecture1.w/2;
        }
        else if(can2.posX>=SCREEN_WIDTH-(lecture1.w/2))
        {
            can2.posX=SCREEN_WIDTH-(lecture1.w/2);
        }

        switch (can2.couleur%3) {// on affiche l'image du chien qui ramasse avec la bonne couleur du canard
        case 0:
            applySurface(can2.posX-(lecture1.w/2),chienQuiRamasse.y,sprite,screen,&lecture1);
            break;
        case 1:
            applySurface(can2.posX-lecture2.w/2,chienQuiRamasse.y,sprite,screen,&lecture2);
            break;
        case 2:
            applySurface(can2.posX-(lecture3.w/2),chienQuiRamasse.y,sprite,screen,&lecture3);
            break;
        }
    }
    if(can.tuer && can2.tuer)// si on a tué les 2 canards le chien les ramasse
    {
        if(!descendre)
        {

            chienQuiRamasse.y--;
        }

        if(descendre)
        {
            chienQuiRamasse.y++;
        }
        int canDer;

        if(dernier==1)// on utilise dernier pour faire afficher le chien au coordonnées du dernier canard
        {
            if(can.posX<=lecture11.w/2)//pour ne pas que l'affichage du chien sorte de l'écran
            {
                canDer=lecture11.w/2;
            }
            else if(can.posX>=SCREEN_WIDTH-(lecture11.w/2))
            {
                canDer=SCREEN_WIDTH-(lecture11.w/2);
            }
            else
            {
                canDer=can.posX;
            }
        }
        else if(dernier==2)// on utilise dernier pour faire afficher le chien au coordonnées du dernier canard
        {
            if(can2.posX<=lecture11.w/2)//pour ne pas que l'affichage du chien sorte de l'écran
            {
                canDer=lecture11.w/2;
            }
            else if(can2.posX>=SCREEN_WIDTH-(lecture11.w/2))
            {
                canDer=SCREEN_WIDTH-(lecture11.w/2);
            }
            else
            {
                canDer=can2.posX;
            }
        }

        switch (can.couleur%3) { // on affiche l'image du chien qui ramasse avec la bonne couleur du canard
        case 0:
            switch (can2.couleur%3) {
            case 0:
                applySurface(canDer-(lecture11.w/2),chienQuiRamasse.y,sprite,screen,&lecture11);
                break;
            case 1:
                applySurface(canDer-(lecture11.w/2),chienQuiRamasse.y,sprite,screen,&lecture12);
                break;
            case 2:
                applySurface(canDer-(lecture11.w/2),chienQuiRamasse.y,sprite,screen,&lecture13);
                break;
            }
            break;
        case 1:
            switch (can2.couleur%3) {
            case 0:
                applySurface(canDer-(lecture11.w/2),chienQuiRamasse.y,sprite,screen,&lecture12);
                break;
            case 1:
                applySurface(canDer-(lecture11.w/2),chienQuiRamasse.y,sprite,screen,&lecture22);
                break;
            case 2:
                applySurface(canDer-(lecture11.w/2),chienQuiRamasse.y,sprite,screen,&lecture23);
                break;
            }
            break;
        case 2:
            switch (can2.couleur%3) {
            case 0:
                applySurface(canDer-(lecture11.w/2),chienQuiRamasse.y,sprite,screen,&lecture13);
                break;
            case 1:
                applySurface(canDer-(lecture11.w/2),chienQuiRamasse.y,sprite,screen,&lecture23);
                break;
            case 2:
                applySurface(canDer-(lecture11.w/2),chienQuiRamasse.y,sprite,screen,&lecture33);
                break;
            }
            break;
        }
    }
    applySurface(0,0,terrain,screen,NULL);
}
