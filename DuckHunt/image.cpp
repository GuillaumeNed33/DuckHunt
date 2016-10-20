#include "image.h"

/****************** Nom de la fonction **********************
* loadedImage
******************** Auteur , Dates *************************
* Nom/Date : Fonction fournise par l'IUT (projet pong)
* 12/11/2015
********************* Description ***************************
* Chargement d'une image en entière
*********************** Entrées *****************************
* le chemin du fichier image que l'on souhaite charger
*********************** Sorties *****************************
* SDL_Surface
************************************************************/
SDL_Surface* loadedImage(string filename)
{
    //Declaration des surfaces
    SDL_Surface* loadedImage=NULL;
    SDL_Surface* optimizedImage=NULL;

    loadedImage=SDL_LoadBMP(filename.c_str()); //Charge une image au format BMP

    if(loadedImage!=NULL) //Si une image a bien été chargée
    {
        optimizedImage=SDL_DisplayFormat(loadedImage);//Converti l'image au meme format que la fenetre avec les bits par pixels correspondant.

        SDL_FreeSurface(loadedImage); //Liberation de la memoire
    }

    return optimizedImage;
}

/****************** Nom de la fonction **********************
* loadedImageWithColorkey
******************** Auteur , Dates *************************
* Nom/Date :   Fonction fournise par l'IUT (projet pong)
* 12/11/2015
********************* Description ***************************
* Chargement d'une image entière en mettant une couleur en
* transparence.
*********************** Entrées *****************************
* le chemin du fichier image que l'on souhaite charger
* avec la couleur a mettre en transparence.
*********************** Sorties *****************************
* SDL_Surface
************************************************************/
SDL_Surface* loadedImageWithColorkey(string filename, int r, int g, int b)
{
    //Declaration des surfaces
    SDL_Surface* loadedImage= NULL;
    SDL_Surface* optimizedImage= NULL;

    loadedImage=IMG_Load(filename.c_str()); //Charge une image au format quelconque

    if (loadedImage!=NULL) //Si une image a bien été chargé
    {
        optimizedImage= SDL_DisplayFormat(loadedImage); //Converti l'image au meme format que la fenetre avec les bits par pixels correspondant.

        SDL_FreeSurface(loadedImage); //Liberation de la memoire de la surface loadedImage
        if(optimizedImage!=NULL) //Si l'optimisation de l'image a bien été réalisée
        {
            Uint32 colorkey=SDL_MapRGB(optimizedImage->format,r,g,b); //Permet de retourner la valeur des pixel rgb, dans le meme format de la surface

            SDL_SetColorKey(optimizedImage,SDL_SRCCOLORKEY, colorkey); //Application de la transparence à partir de l'image optimiséé
                                                                       //SDL_SRCCOLORKEY verifie que le colorkey est bien utilisé lorsqu'on blittera une surface
                                                                       //colorkey --> couleur a mettre en transparence
        }
    }

    return optimizedImage;

}

/****************** Nom de la fonction **********************
* applySurface
******************** Auteur , Dates *************************
* Nom/Date :  Fonction fournise par l'IUT (projet pong)
* 12/11/2015
********************* Description ***************************
* Affiche un SDL_Surface dessus un autre SDL_Surface.
*********************** Entrées *****************************
* Coordonnées x et y pour le "collage" de l'image.
* Le SDL_Surface a coller et celui sur lequel on va coller
* l'image.
* Un SDL_Rect (facultatif), comprenant un rectangle de lecture
* pour le SDL_Surface a coller.
*********************** Sorties *****************************
* Ne renvoie rien.
************************************************************/
void applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
{
    SDL_Rect offset;
    offset.x=x; //Valeur x du rectangle ou l'image va etre affichée
    offset.y=y; //Valeur y du rectangle ou l'image va etre affichée
    SDL_BlitSurface(source,clip,destination,&offset);//Colle l'image source sur la surface destination aux coordonnées definie par offset
                                                     //clip --> Rectangle de lecture défini par le developpeur (facultatif)
}

/****************** Nom de la fonction **********************
* showMessageScreen
******************** Auteur , Dates *************************
* Nom/Date : Fonction fournise par l'IUT (projet pong)
* 12/11/2015
********************* Description ***************************
* Affiche un texte (une fonte) sur un SDL_Surface
*********************** Entrées *****************************
* le message à afficher
* les coordonnees x et y où afficher le message.
* La fonte correspondante au message.
* La taille de la fonte.
* La couleur de la fonte.
* Le SDL_Surface sur lequel la fonte est affichée.
*********************** Sorties *****************************
* Rien
************************************************************/
void showMessageScreen(string message,int x,int y,TTF_Font *font,int fontSize,SDL_Color textColor,SDL_Surface* &screen)
{
    //initialisation
    string mot="";
    string space=" ";
    int i=0,j;
    SDL_Surface *mes=NULL;

    j = message.find(space);
    while( j != string::npos )
    {
        mot=message.substr(i,j-i); // mot prend la valeur du message de l'utilisateur
        if(mot != "")
        {
            mes=TTF_RenderText_Solid(font,mot.c_str(),textColor); //Creation de la fonte
            applySurface(x,y,mes,screen,NULL); //Collage du message
            x+=mes->w;
            SDL_FreeSurface(mes);  //Liberation de la memoire de la surface mes
        }
        x+=fontSize;
        i=j+1;
        j = message.find(space,i);
    }

    mot=message.substr(i);
    mes=TTF_RenderText_Solid(font,mot.c_str(),textColor); //Creer la fonte avec les couleurs correspondantes
    applySurface(x,y,mes,screen,NULL); //Coller la fonte dans la fenetre
    SDL_FreeSurface(mes); //Liberation de la memoire de la surface mes
}
