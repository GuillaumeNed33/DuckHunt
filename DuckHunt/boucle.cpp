#include "boucle.h"


/****************** Nom de la fonction **********************
* menu
******************** Auteur , Dates *************************
* Nom/Date : Nedelec/Viola
* 12/11/2015
********************* Description ***************************
* Boucle qui gère le menu
*********************** Entrées *****************************
* modeNormal est le booléen qui va servir à lancer le mode Normal
* modeSurprise est le booléen qui va servir à lancer le mode Surprise
* bestScore est le booléen qui va servir à lancer le mode Meilleur Score
* quitter et le booléen qui servira à fermer la fenetre
* screen est la surface qui sert d'écran
* event est le sdl_event qui servira à recuperer les evenenements du clavier et de la souris
*********************** Sorties *****************************
* pas de sortie
************************************************************/
void menu( bool &modeNormal,bool &modeSurprise, bool &bestScore,bool &quitter, SDL_Surface* &screen,SDL_Event &event)
{
    /*** INITIALISATION ***/

    int selecteurMenu=0;

    TTF_Font *fonts;
    TTF_Font *fonts2;
    TTF_Font *font_choix;

    SDL_Color textColor;
    textColor.r = 0;
    textColor.g = 0;
    textColor.b = 0;

    int fontSize=50;
    int fontSize2=20;
    int choixSize=35;

    string police="font/duck_hunt.ttf";
    fonts = TTF_OpenFont(police.c_str(),fontSize);
    fonts2 = TTF_OpenFont(police.c_str(),fontSize2);
    font_choix = TTF_OpenFont(police.c_str(),choixSize);
    TTF_SetFontStyle(fonts, TTF_STYLE_UNDERLINE);

    SDL_Surface* fondMenu=loadedImage("sprites/menu.bmp");
    SDL_Surface* fondMenu_chicken=loadedImage("sprites/ferme/menu_poulet.bmp");
    SDL_Surface* fondMenu_classement=loadedImage("sprites/menu_classement.bmp");
    SDL_Surface* fondMenu_exit=loadedImage("sprites/menu_exit.bmp");

    /*** BOUCLE ***/

    while(!quitter && !modeNormal && !modeSurprise && !bestScore)
    {
        applySurface(0,0,fondMenu,screen,NULL);
        ostringstream mssg, mssg2, choix, choix2,choix3, choixQuit;

        if(selecteurMenu==0)
        {
            applySurface(0,0, fondMenu, screen,NULL);
            mssg << "DUCK_HUNT";
            mssg2 << "IUT DE BORDEAUX 2015";
            choix << "--> Mode Classique";
            choix2 << "    Mode Surprise";
            choix3 << "    Meilleurs Scores";
            choixQuit << "    Quitter le jeu";
        }
        if(selecteurMenu==1)
        {
            applySurface(0,0, fondMenu_chicken, screen,NULL);
            mssg << "CHICKEN_HUNT";
            mssg2 << "IUT DE BORDEAUX 2015";
            choix << "    Mode Classique";
            choix2 << "--> Mode Surprise";
            choix3 << "    Meilleurs Scores";
            choixQuit << "    Quitter le jeu";
        }
        if(selecteurMenu==2)
        {
            applySurface(0,0, fondMenu_classement, screen,NULL);
            mssg << "DUCK_HUNT";
            mssg2 << "IUT DE BORDEAUX 2015";
            choix << "    Mode Classique";
            choix2 << "    Mode Surprise";
            choix3 << "--> Meilleurs Scores";
            choixQuit << "    Quitter le jeu";
        }
        if(selecteurMenu==3)
        {
            applySurface(0,0, fondMenu_exit, screen,NULL);
            mssg << "DUCK_HUNT";
            mssg2 << "IUT DE BORDEAUX 2015";
            choix << "    Mode Classique";
            choix2 << "    Mode Surprise";
            choix3 << "    Meilleurs Scores";
            choixQuit << "--> Quitter le jeu";
        }

        //affichage des fontes
        showMessageScreen(mssg.str(), 200,30 ,fonts,fontSize,textColor,screen);
        showMessageScreen(mssg2.str(), 110,110 ,fonts2,fontSize2,textColor,screen);
        showMessageScreen(choix.str(), 110, 185, font_choix, choixSize, textColor, screen);
        showMessageScreen(choix2.str(), 110, 260, font_choix, choixSize, textColor, screen);
        showMessageScreen(choix3.str(), 110, 335, font_choix, choixSize, textColor, screen);
        showMessageScreen(choixQuit.str(), 110, 410, font_choix, choixSize, textColor, screen);

        gestionMenu(event,selecteurMenu,modeNormal,modeSurprise,bestScore,quitter); //fonction pour gerer es evenements relatifs au menu

        SDL_Flip(screen); //Rafraichir l'image
    }
    //Liberation de la memoire
    SDL_FreeSurface(fondMenu);
    SDL_FreeSurface(fondMenu_chicken);
    SDL_FreeSurface(fondMenu_classement);
    SDL_FreeSurface(fondMenu_exit);
    TTF_CloseFont(fonts);
    TTF_CloseFont(fonts2);
    TTF_CloseFont(font_choix);
}


/****************** Nom de la fonction **********************
* normal
******************** Auteur , Dates *************************
* Nom/Date : Nedelec/Viola
* 12/11/2015
********************* Description ***************************
* Boucle qui gère le mode de jeu Normal
*********************** Entrées *****************************
* modeNormal est le booléen qui va servir à lancer le mode Normal, tant qu'il reste vrai on joue, sinon on reviens au menu
* bestScore est le booléen qui va servir à lancer le mode Meilleur Score à la fin de la partie
* quitter et le booléen qui servira à fermer la fenetre
* screen est la surface qui sert d'écran
* event est le sdl_event qui servira à recuperer les evenenement du clavier et de la souris
*********************** Sorties *****************************
* pas de sortie
************************************************************/
void normal(bool &quitter, bool &modeNormal,bool &bestScore, SDL_Surface* &screen, SDL_Event &event)
{
    /*** INITIALISATION ***/

    TTF_Font *fontNiveau;
    TTF_Font *fontScore;
    TTF_Font *escape;

    SDL_Color textColor;
    textColor.r = 0;
    textColor.g = 0;
    textColor.b = 0;

    SDL_Color textColorEscape;
    textColorEscape.r = 255;
    textColorEscape.g = 0;
    textColorEscape.b = 0;

    int fontSize=50;
    int fontSize2=30;

    SDL_Color textColorScore;
    textColorScore.r = 255;
    textColorScore.g = 255;
    textColorScore.b = 255;

    string police="font/duck_hunt.ttf";
    fontNiveau = TTF_OpenFont(police.c_str(),fontSize);
    fontScore = TTF_OpenFont(police.c_str(),fontSize2);
    escape = TTF_OpenFont(police.c_str(),fontSize);

    SDL_Surface* fond=loadedImage("sprites/backGame.bmp");//charge du disque dur vers la RAM
    SDL_Surface* sprite=loadedImageWithColorkey("sprites/duck.bmp",228,255,0);
    SDL_Surface* terrain=loadedImageWithColorkey("sprites/backGameBlit.bmp",0,0,0);
    SDL_Surface* regle=loadedImage("sprites/regle.bmp");
    SDL_Surface* canardScore=loadedImage("sprites/hit.bmp");
    SDL_Surface* cartouche0=loadedImageWithColorkey("sprites/shot0.bmp",0,0,0);
    SDL_Surface* cartouche1=loadedImageWithColorkey("sprites/shot1.bmp",0,0,0);
    SDL_Surface* cartouche2=loadedImageWithColorkey("sprites/shot2.bmp",0,0,0);
    SDL_Surface* cartouche3=loadedImageWithColorkey("sprites/shot3.bmp",0,0,0);
    SDL_Surface* points=loadedImageWithColorkey("sprites/points.bmp",0,0,0);
    SDL_Surface* curseur =loadedImageWithColorkey("sprites/viseur.bmp", 0,0,0);

    SDL_Rect  chienQuiRit;
    SDL_Rect chienQuiMarche,chienQuiRamasse;

    chienQuiRit.x=SCREEN_WIDTH/2+20;
    chienQuiRit.y=SCREEN_HEIGHT/2+130;
    chienQuiRit.h=78;
    chienQuiRit.w=58;

    chienQuiRamasse.y=SCREEN_HEIGHT/2+130;

    bool modeNormalRegle=true;
    bool descendre=false;//sert pour faire rire le chien
    bool finRound=false;
    int tir=3;
    int round=1; //represente les vague de canard sur un niveau
    bool debut=true;
    bool rire=false;//sert pour fixer un sdl_delay différent quand le chien rigole.
    bool finChien=false;//vrai tant que le chien fait une action (rire ou ramasser)
    int cpt=0,cptcan=0;//compteurs, le second est en fonction du premier pour avoir une incrémentation moins rapide et faire battre les ailes des canards moins vite.
    int lvl=1;
    int scoreCan;//nombre de canard tué au cours du niveau
    int score=0;
    int dernier;//indique le dernier carnard tué au cours du round
    int tabCan[5][2]; //tableau de canard 5 vague de 2
    initTabCan(tabCan,5,2);

    canard can, can2;

    /*** BOUCLE ***/

    while(!quitter && modeNormal)//boucle de jeu
    {
        if(modeNormalRegle)
        {
            applySurface(0,0,regle,screen,NULL);
            gestionRegleJeu(event,quitter,modeNormalRegle, modeNormal); //gere les evenements depuis l'affichage des regles du jeu
            SDL_Flip(screen); //Rafraichis l'image
        }

        if(!modeNormalRegle)
        {
            ostringstream niveau;
            niveau << "Niveau " << lvl;
            applySurface(0,0,fond,screen,NULL);
            ostringstream info;
            info << "CANARDS ECHAPPES";

            if(debut)
            {
                if(cpt==0)//pour inialiser la position de départ du chien seulement au premier tour de boucle.
                {
                    chienQuiMarche.x=0;
                    chienQuiMarche.y=SCREEN_HEIGHT/2+150;
                }

                showMessageScreen(niveau.str(), 300, 200, fontNiveau, fontSize, textColor, screen);
                faireMarcherLeChien(chienQuiMarche,screen,sprite, terrain, debut,cpt);
                initCanard(can,lvl);
                initCanard(can2,lvl);
                initTabCan(tabCan,5,2);
            }
            cpt++;

            if(!debut)
            {
                moveCanard(can,tir,cptcan); //deplacements des canards
                moveCanard(can2,tir,cptcan);
                showCanard(can, screen, sprite,points, cptcan); //affichage des canards
                showCanard(can2, screen, sprite,points, cptcan);

                applySurface(0,0,terrain,screen,NULL);

                if(tir==0)
                {
                    finRound=true;
                    scoreCan=attributScoreCanard(tabCan,5,2);//affecte le nombre de canard tué

                }
                if(can.tuer && can.tuer)
                {
                    finRound=true;
                    scoreCan=attributScoreCanard(tabCan,5,2);//affecte le nombre de canard tué
                }
                if(!can.tuer)
                {
                    changerDirectionCanard(cpt,can); //direction aleatoire
                }
                if(!can2.tuer)
                {
                    changerDirectionCanard(cpt,can2);
                }

                remplirTabCan(can.tuer,can2.tuer,round,tabCan,tir);//rempli un tableau qui va nous servir pour l'affichage des icones(balnc,vert,rouge) des canards

                dernierCanard(can,can2,dernier);//indique le dernier canard tuer, de sorte à ce que le chien qui ramasse se place aux coordonnées de ce dernier.

                ostringstream Ascore;

                Ascore << score;

                if(can.tuer && !can.scorer)//pour que le score ne soit incrémenté qu'une seule fois.
                {
                    compteScore(score,can);
                    can.scorer=true;
                }

                if(can2.tuer && !can2.scorer)
                {
                    compteScore(score,can2);
                    can2.scorer=true;
                }

                if(finRound && !can.tuer && !can2.tuer && round<5 && can.sorti && can2.sorti)//si à la fin du round (tant que ce n'est pas le dernier) on a loupé les 2 canards, le  chien rigole.
                {
                    showMessageScreen(info.str(), 200,50 ,escape,fontSize,textColorEscape,screen);
                    rire=faireRireLeChien(chienQuiRit,screen,sprite,terrain, descendre, cpt,finChien);
                    if(finChien)
                    {
                        initCanard(can,lvl);
                        initCanard(can2,lvl);
                        tir=3;
                        finRound=false;
                        round++;
                        finChien=false;
                    }
                }
                else if(finRound && round<5 && can.sorti && can2.sorti)//si à la fin du round (tant que ce n'est pas le dernier) le  chien ramasse le ou les canards.
                {

                    faireRamasserLeChien(chienQuiRamasse,screen,sprite,terrain, descendre, cpt,finChien,can,can2,dernier);
                    if(finChien)
                    {
                        initCanard(can,lvl);
                        initCanard(can2,lvl);
                        tir=3;
                        finRound=false;
                        round++;
                        finChien=false;
                    }
                }
                else if(finRound && !can.tuer && !can2.tuer && can.sorti && can2.sorti && round==5 && scoreCan<canardMinimum)//à la fin du niveau (round==5), si on a raté les 2 canards et si il y a moins de 6 canards tués sur l'ensemble du niveau,
                {                                                                                                            //le chien rigole et on affiche game over puis le joueur est automatiquement redirigé vers la page meilleurs scores.
                    rire=faireRireLeChien(chienQuiRit,screen,sprite,terrain, descendre, cpt,finChien);
                    showMessageScreen("GAME OVER",300,200,fontNiveau,fontSize,textColor,screen);
                    if(!rire)
                    {
                        modeNormal=false;
                        bestScore=true;
                        meilleurScore(quitter,bestScore,screen,event,score,1);  //le dernier attribut est un car on est dans le mode normal
                    }
                }
                else if(finRound && can.sorti && can2.sorti && round==5 && scoreCan<canardMinimum)//à la fin du niveau (round==5), si on a tué moins de 6 canards le chien ramasse et on affiche game over
                {                                                                                 //puis le joueur est automatiquement redirigé vers la page meilleurs scores.
                    faireRamasserLeChien(chienQuiRamasse,screen,sprite,terrain, descendre, cpt,finChien,can,can2,dernier);
                    showMessageScreen("GAME OVER",300,200,fontNiveau,fontSize,textColor,screen);
                    if(finChien)
                    {
                        finChien=false;
                        modeNormal=false;
                        bestScore=true;
                        meilleurScore(quitter,bestScore,screen,event,score,1);
                    }
                }
                else if(finRound && !can.tuer && !can2.tuer && round==5 && scoreCan>=canardMinimum && can.sorti && can2.sorti)//à la fin du niveau (round==5), si on a raté les 2 canards du dernier round et si on a tué plus de 6 canards sur l'ensemble du niveau
                {                                                                                                             //le chien rigole, puis on lance le niveau 2.
                    showMessageScreen(info.str(), 200,50 ,escape,fontSize,textColorEscape,screen);
                    rire=faireRireLeChien(chienQuiRit,screen,sprite,terrain, descendre, cpt,finChien);
                    if(finChien)
                    {
                        finChien=false;
                        lvl++;
                        round=1;
                        tir=3;
                        finRound=false;
                        debut=true;// permet de relancer un nouveau niveau
                        cpt=0;
                    }
                }
                else if(finRound && round==5 && scoreCan>=canardMinimum && can.sorti && can2.sorti)//à la fin du niveau (round==5), si on a raté les 2 canards du dernier round et si on a tué plus de 6 canards sur l'ensemble du niveau
                {                                                                                  //le chien ramasse et on lance un nouveau niveau

                    faireRamasserLeChien(chienQuiRamasse,screen,sprite,terrain, descendre, cpt,finChien,can,can2,dernier);
                    if(finChien)
                    {
                        finChien=false;
                        lvl++;
                        round=1;
                        tir=3;
                        finRound=false;
                        debut=true;//permet de relancer un nouveau niveau
                        cpt=0;
                    }
                }

                showMessageScreen(Ascore.str(),595,670,fontScore,fontSize2,textColorScore,screen);
                afficheScoreCan(tabCan,screen,canardScore);//affiche les petites icones de canards (rouge,vert,blanc).
                afficheCartouche(tir,screen,cartouche0,cartouche1,cartouche2,cartouche3); //affiche les icones des cartouches
            }

            if(cpt%3==0)
            {
                cptcan++;//compteur pour le battement d'aile des canards
            }

            gestionModeNormal(event,quitter,modeNormal, modeNormalRegle,can,can2,tir); //gère les évenements du clavier et de la souris

            if(debut)
                SDL_Delay(75);//Pour que le chien marche correctement
            else if(rire)
            {
                SDL_Delay(50);//Pour que le chien rigole correctement
            }
            else
            {
                SDL_Delay(15);
                SDL_ShowCursor(SDL_DISABLE);//efface l'affichage du curseur souris que l'on remplace par le viseur

                if(event.button.x<=SCREEN_WIDTH && event.button.x>0 && event.button.y>0 && event.button.y<=SCREEN_HEIGHT)
                    applySurface((event.button.x)-15,(event.button.y)-17, curseur, screen,NULL); //affichage de la cible sur le curseur
            }
            SDL_Flip(screen);
        }
    }
    //Liberation de la memoire
    SDL_FreeSurface(fond);
    SDL_FreeSurface(sprite);
    SDL_FreeSurface(terrain);
    SDL_FreeSurface(regle);
    SDL_FreeSurface(canardScore);
    SDL_FreeSurface(cartouche0);
    SDL_FreeSurface(cartouche1);
    SDL_FreeSurface(cartouche2);
    SDL_FreeSurface(cartouche3);
    SDL_FreeSurface(points);
    SDL_FreeSurface(curseur);
    TTF_CloseFont(fontNiveau);
    TTF_CloseFont(fontScore);
    TTF_CloseFont(escape);
}

/****************** Nom de la fonction **********************
* surprise
******************** Auteur , Dates *************************
* Nom/Date : Nedelec/Viola
* 12/11/2015
********************* Description ***************************
* Boucle qui gère le mode de jeu Normal
*********************** Entrées *****************************
* modeSurprise est le booléen qui va servir à lancer le mode Suprise, tant qu'il reste vrai on joue, sinon on reviens au menu
* bestScore est le booléen qui va servir à lancer le mode Meilleur Score à la fin de la partie
* quitter et le booléen qui servira à fermer la fenetre
* screen est la surface qui sert d'écran
* event est le sdl_event qui servira à recuperer les evenenement du clavier et de la souris
*********************** Sorties *****************************
* pas de sortie
************************************************************/
void surprise(bool &quitter, bool &modeSurprise, SDL_Surface* &screen, SDL_Event &event, bool &bestScore)
{
    /*** INITIALISATION ***/

    SDL_Surface *regle=loadedImage("sprites/ferme/regle_poulet.bmp");
    SDL_Surface *fondSurprise=loadedImage("sprites/ferme/backGame.bmp");
    SDL_Surface *fondBlit=loadedImageWithColorkey("sprites/ferme/backGameBlit.bmp", 0,0,0);
    SDL_Surface *bucket=loadedImageWithColorkey("sprites/ferme/bucket.bmp",252,255,0);        //Nous avons choisi d'employer 2 images bucket pour rendre plus réaliste l'entrée de la cuisse dans le bucket.
    SDL_Surface *bucket2=loadedImageWithColorkey("sprites/ferme/bucket2.bmp",252,255,0);
    SDL_Surface *ChickenFly=loadedImageWithColorkey("sprites/ferme/poulet.bmp",255,255,255);
    SDL_Surface* curseur =loadedImageWithColorkey("sprites/viseur.bmp", 0,0,0);
    SDL_Surface* shoot=loadedImageWithColorkey("sprites/ferme/shot.bmp",0,0,0);
    SDL_Surface* point_touche=loadedImageWithColorkey("sprites/ferme/point_touche.bmp",0,0,0);
    SDL_Surface* point_bucket=loadedImageWithColorkey("sprites/ferme/point_bucket.bmp",0,0,0);
    SDL_Surface* fail=loadedImageWithColorkey("sprites/ferme/fail.bmp",0,0,0);

    TTF_Font *fontScore;
    TTF_Font *fin;
    int fontSizeFin=55;
    int fontSizeScore=30;

    string police="font/duck_hunt.ttf";
    fontScore = TTF_OpenFont(police.c_str(),fontSizeScore);
    fin = TTF_OpenFont(police.c_str(),fontSizeFin);

    SDL_Color textColorScore;
    textColorScore.r = 255;
    textColorScore.g = 255;
    textColorScore.b = 255;

    SDL_Color textColorFin;
    textColorFin.r = 255;
    textColorFin.g = 0;
    textColorFin.b = 0;

    SDL_Rect bucketPos;
    bucketPos.w=100;
    bucketPos.x=SCREEN_WIDTH/2-bucketPos.w/2;
    bucketPos.y=480;

    chicken chicken1,chicken2,chicken3, chicken4, chicken5;

    int cpt=0, cptcan=0; //Deux compteurs
    int score=0;
    bool modeSurpriseRegle=true;
    bool debut=true;

    int timer=30;

    int curseurX, curseurY;//Ces variables nous servent pour maintenir l'affichage du curseur même lorsque on bouge le bucket.

    SDL_EnableKeyRepeat(10,10);

    /*** BOUCLE ***/

    while(!quitter && modeSurprise)
    {
        if(modeSurpriseRegle)//affiche les règles tant qu'on appuie pas sur entrée
        {
            applySurface(0,0,regle,screen,NULL);
            gestionRegleJeu(event,quitter,modeSurpriseRegle,modeSurprise); //gere les evenements depuis l'affichage des regles du jeu

        }
        else
        {
            if(debut)
            {
                //initialisation des poulets au début de la session de jeu
                initChicken(chicken1);
                initChicken(chicken2);
                initChicken(chicken3);
                initChicken(chicken4);
                initChicken(chicken5);
                debut=false;
            }
            ostringstream Ascore, Atimer, mes_fin;
            Ascore << score;
            applySurface(0,0,fondSurprise,screen,NULL);
            mes_fin << "";


            if(cpt%200==199)
                timer--;

            if(timer==0)
            {
                Atimer << "TEMPS ECOULE !!!";
                mes_fin << "TERMINEE !!!";
            }
            else if(timer<0)
            {
                modeSurprise=false;
                bestScore=true;
                SDL_EnableKeyRepeat(10,500);
                meilleurScore(quitter,bestScore,screen,event,score,-1);
            }
            else
                Atimer << "Temps restant: " << timer << "s";

            applySurface(0,0,fondBlit,screen,NULL);
            applySurface(bucketPos.x,bucketPos.y,bucket2,screen,NULL);

            //mouvement des canards et affichage
            moveChicken(chicken1,cptcan);
            showChicken(chicken1,screen,ChickenFly,point_touche,point_bucket,fail,cptcan);

            moveChicken(chicken2,cptcan);
            showChicken(chicken2,screen,ChickenFly,point_touche,point_bucket,fail,cptcan);

            moveChicken(chicken3,cptcan);
            showChicken(chicken3,screen,ChickenFly,point_touche,point_bucket,fail,cptcan);

            moveChicken(chicken4,cptcan);
            showChicken(chicken4,screen,ChickenFly,point_touche,point_bucket,fail,cptcan);

            moveChicken(chicken5,cptcan);
            showChicken(chicken5,screen,ChickenFly,point_touche,point_bucket,fail,cptcan);

            gestionModeSurprise(event,quitter,modeSurprise,modeSurpriseRegle,bucketPos, chicken1,chicken2,chicken3,chicken4,chicken5,curseurX,curseurY); //gere les evenements liés au mode de jeu secondaire

            recuperChicken(bucketPos,chicken1);
            recuperChicken(bucketPos,chicken2);
            recuperChicken(bucketPos,chicken3);
            recuperChicken(bucketPos,chicken4);
            recuperChicken(bucketPos,chicken5);

            //Gere le score lié au bucket
            atttributScoreBucket(score,chicken1.entreDansLeBucket);
            atttributScoreBucket(score,chicken2.entreDansLeBucket);
            atttributScoreBucket(score,chicken3.entreDansLeBucket);
            atttributScoreBucket(score,chicken4.entreDansLeBucket);
            atttributScoreBucket(score,chicken5.entreDansLeBucket);


            if(chicken1.entreDansLeBucket)
            {
                chicken1.dansLeBucket=true;
            }
            if(chicken2.entreDansLeBucket)
            {
                chicken2.dansLeBucket=true;
            }
            if(chicken3.entreDansLeBucket)
            {
                chicken3.dansLeBucket=true;
            }
            if(chicken4.entreDansLeBucket)
            {
                chicken4.dansLeBucket=true;
            }
            if(chicken5.entreDansLeBucket)
            {
                chicken5.dansLeBucket=true;
            }

            // Pour réinitialisé les poulets
            chicken1.entreDansLeBucket=false;
            chicken2.entreDansLeBucket=false;
            chicken3.entreDansLeBucket=false;
            chicken4.entreDansLeBucket=false;
            chicken5.entreDansLeBucket=false;

            //Amelioration de l'affichage
            garderChickenDansBucket(chicken1,bucketPos);
            garderChickenDansBucket(chicken2,bucketPos);
            garderChickenDansBucket(chicken3,bucketPos);
            garderChickenDansBucket(chicken4,bucketPos);
            garderChickenDansBucket(chicken5,bucketPos);

            //Gere le score lié aux poulets touchés
            if(chicken1.tuer && !chicken1.scorer)
            {
                attributScoreChicken(score,chicken1.tuer);
                chicken1.scorer=true;
            }
            if(chicken2.tuer && !chicken2.scorer)
            {
                attributScoreChicken(score,chicken2.tuer);
                chicken2.scorer=true;
            }
            if(chicken3.tuer && !chicken3.scorer)
            {
                attributScoreChicken(score,chicken3.tuer);
                chicken3.scorer=true;
            }
            if(chicken4.tuer && !chicken4.scorer)
            {
                attributScoreChicken(score,chicken4.tuer);
                chicken4.scorer=true;
            }
            if(chicken5.tuer && !chicken5.scorer)
            {
                attributScoreChicken(score,chicken5.tuer);
                chicken5.scorer=true;
            }

            if(chicken1.tuer || chicken2.tuer || chicken3.tuer || chicken4.tuer || chicken5.tuer)
            {
                if(!chicken1.dansLeBucket && !chicken2.dansLeBucket && !chicken3.dansLeBucket && !chicken4.dansLeBucket && !chicken5.dansLeBucket)
                {
                    //permet de rendre plus réaliste l'entrée de la cuisse dans le bucket
                    //la cuisse passe bien derrière l'herbe ainsi.
                    //Cela marche tant qu'il n'y a pas une cuisse dans le bucket en même temps qu'une cuisse derrière l'herbe.
                    //C'est un cas rare et nous n'avons pas trouvé comment y remédier. Et nous préferons rendre réaliste l'entrée de la cuisse dans le bucket.
                    applySurface(0,0,fondBlit,screen,NULL);
                    applySurface(bucketPos.x,bucketPos.y,bucket2,screen,NULL);
                }
            }

            if(chicken1.sorti==true)// dès qu'un poulet est mort et a disparu soit dans le bucket soit dans l'herbe, on le réinitialise
            {
                initChicken(chicken1);
            }
            if(chicken2.sorti==true)
            {
                initChicken(chicken2);
            }
            if(chicken3.sorti==true)
            {
                initChicken(chicken3);
            }
            if(chicken4.sorti==true)
            {
                initChicken(chicken4);
            }
            if(chicken5.sorti==true)
            {
                initChicken(chicken5);
            }

            changerDirectionChicken(cpt,chicken1);//permet un déplacement aléatoire des poulets
            changerDirectionChicken(cpt,chicken2);
            changerDirectionChicken(cpt,chicken3);
            changerDirectionChicken(cpt,chicken4);
            changerDirectionChicken(cpt,chicken5);

            applySurface(bucketPos.x,bucketPos.y,bucket,screen,NULL);
            applySurface(65,660,shoot,screen,NULL);

            //Affichage du curseur en cible
            SDL_ShowCursor(SDL_DISABLE);
            if(curseurX<=SCREEN_WIDTH && curseurX>0 && curseurY>0 && curseurY<=SCREEN_HEIGHT)
                applySurface((curseurX)-15,(curseurY)-17, curseur, screen,NULL);

            showMessageScreen(Ascore.str(),595,670,fontScore,fontSizeScore,textColorScore,screen);
            showMessageScreen(Atimer.str(),190,670,fontScore,fontSizeScore,textColorScore,screen);
            showMessageScreen(mes_fin.str(),300, 100, fin, fontSizeFin,textColorFin,screen);
        }
        SDL_Flip(screen);

        cpt++;
        if(cpt%20==0)
        {
            cptcan++;
        }
        SDL_Delay(2);
    }
    //Liberation de la memoire
    SDL_EnableKeyRepeat(10,500);
    SDL_FreeSurface(regle);
    SDL_FreeSurface(fondSurprise);
    SDL_FreeSurface(fondBlit);
    SDL_FreeSurface(bucket);
    SDL_FreeSurface(bucket2);
    SDL_FreeSurface(ChickenFly);
    SDL_FreeSurface(curseur);
    SDL_FreeSurface(shoot);
    SDL_FreeSurface(point_bucket);
    SDL_FreeSurface(point_touche);
    SDL_FreeSurface(fail);
    TTF_CloseFont(fontScore);
    TTF_CloseFont(fin);
}

/****************** Nom de la fonction **********************
* meilleurScore
******************** Auteur , Dates *************************
* Nom/Date : Nedelec/Viola
* 12/11/2015
********************* Description ***************************
* Boucle qui gère l'e mode de jeu Normal'affichage des meilleurs score
*********************** Entrées *****************************
* bestScore est le booléen qui va servir à lancer le mode Meilleur Score. Tant qu'il reste vrai on reste dans les meilleurs scores,sinon on revient au menu
* quitter et le booléen qui servira à fermer la fenetre
* screen est la surface qui sert d'écran
* event est le sdl_event qui servira à recuperer les evenenement du clavier et de la souris
* score est un entier qui contient le score du jour seulement si la fonction meilleurScore est lancée à la fin d'une partie. Si elle est lancée depuis le menu, score vaut -1.
* mode est un entier qui nous sert à determiner si la fonction est appelé depuis le mode Normal ou depuis le mode Surprise pour avoir l'affichage correspondant.
* (Si il il est lancé depuis le mode Normal, il est positif, sinon par le mode surprise, il est négatif)
*********************** Sorties *****************************
* pas de sortie
************************************************************/
void meilleurScore(bool &quitter, bool &bestScore,SDL_Surface* &screen,SDL_Event &event,int score,int mode)
{
    /*** INITIALISATION ***/

    TTF_Font *fonts;
    TTF_Font *fonts2;
    TTF_Font *fontscore;

    SDL_Color textColor;
    textColor.r = 0;
    textColor.g = 0;
    textColor.b = 0;

    SDL_Color textColor2;
    textColor2.r = 255;
    textColor2.g = 255;
    textColor2.b = 255;

    int fontSize=20;
    int fontSize2=25;
    int fontSizeScore=25;

    string police="font/duck_hunt.ttf";
    fonts = TTF_OpenFont(police.c_str(),fontSize);
    fonts2 = TTF_OpenFont(police.c_str(),fontSize2);
    fontscore = TTF_OpenFont(police.c_str(),fontSizeScore);

    SDL_Surface* fondMeilleurScore=loadedImage("sprites/menu_classement.bmp");

    const int tailleMS=5;
    string meilleurScoreNormal[tailleMS];
    string meilleurScoreSurprise[tailleMS];

    ostringstream tonScore;

    if(score>0)
    {
        if(mode>0)
        {
            tonScore << "Ton score mode Normal: " << score;
            changerMeilleurScore("meilleurScoreNormal.txt",score);
        }
        else
        {
            tonScore << "Ton score mode Surprise: " << score;
            changerMeilleurScore("meilleurScoreSurprise.txt",score);
        }
    }

    LireMeilleurScore("meilleurScoreNormal.txt",meilleurScoreNormal);//on lit le fichier des meilleurs scores du mode normal et on remplit le tableau meilleurScoreNormal
    LireMeilleurScore("meilleurScoreSurprise.txt",meilleurScoreSurprise);//on lit le fichier des meilleurs scores du mode surprise et on remplit le tableau meilleurScoreSurprise

    /*** BOUCLE ***/

    while(!quitter && bestScore)
    {
        applySurface(0,0,fondMeilleurScore,screen,NULL);
        if(score>=0)
        {
            showMessageScreen(tonScore.str(),20,20,fontscore,fontSizeScore,textColor,screen);//affiche le score du joueur à la fin de sa partie.
        }
        ostringstream mes, mes2, mes3, mes4, mes5;

        if(mode>0){
            mes << meilleurScoreNormal[0];
            mes2 << meilleurScoreNormal[1];
            mes3 << meilleurScoreNormal[2];
            mes4 << meilleurScoreNormal[3];
            mes5 << meilleurScoreNormal[4];

            showMessageScreen("Meilleurs scores | mode normal",200,250,fonts,fontSize,textColor,screen);
            showMessageScreen(mes.str(),360,280,fonts,fontSize,textColor,screen);
            showMessageScreen(mes2.str(),360,310,fonts,fontSize,textColor,screen);
            showMessageScreen(mes3.str(),360,340,fonts,fontSize,textColor,screen);
            showMessageScreen(mes4.str(),360,370,fonts,fontSize,textColor,screen);
            showMessageScreen(mes5.str(),360,400,fonts,fontSize,textColor,screen);
            showMessageScreen("APPUYER SUR ECHAP ",400,470,fonts2,fontSize2,textColor2,screen);
            showMessageScreen("POUR RETOURNER AU MENU",340,505,fonts2,fontSize2,textColor2,screen);
            showMessageScreen("Utiliser les fleches directionnelle",10, 115, fonts2, fontSize2, textColor2, screen);
            showMessageScreen("pour changer de mode de jeu", 45, 140,fonts2, fontSize2, textColor2, screen);
        }
        else
        {
            mes << meilleurScoreSurprise[0];
            mes2 << meilleurScoreSurprise[1];
            mes3 << meilleurScoreSurprise[2];
            mes4 << meilleurScoreSurprise[3];
            mes5 << meilleurScoreSurprise[4];

            showMessageScreen("Meilleurs scores | mode surprise",200,250,fonts,fontSize,textColor,screen);
            showMessageScreen(mes.str(),360,280,fonts,fontSize,textColor,screen);
            showMessageScreen(mes2.str(),360,310,fonts,fontSize,textColor,screen);
            showMessageScreen(mes3.str(),360,340,fonts,fontSize,textColor,screen);
            showMessageScreen(mes4.str(),360,370,fonts,fontSize,textColor,screen);
            showMessageScreen(mes5.str(),360,400,fonts,fontSize,textColor,screen);
            showMessageScreen("APPUYER SUR ECHAP ",400,470,fonts2,fontSize2,textColor2,screen);
            showMessageScreen("POUR RETOURNER AU MENU",340,505,fonts2,fontSize2,textColor2,screen);
            showMessageScreen("Utiliser les fleches directionnelle",10, 115, fonts2, fontSize2, textColor2, screen);
            showMessageScreen("pour changer de mode de jeu", 45, 140,fonts2, fontSize2, textColor2, screen);
        }

        gestionMeilleurScore(event,bestScore,quitter,mode);//gère les évenement souris et clavier.
        SDL_Flip(screen);
    }
    //Liberation de la memoire
    SDL_FreeSurface(fondMeilleurScore);
    TTF_CloseFont(fonts);
    TTF_CloseFont(fonts2);
    TTF_CloseFont(fontscore);

}
