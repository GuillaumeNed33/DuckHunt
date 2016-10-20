#include "gestionFichier.h"

/****************** Nom de la fonction **********************
* LireMeilleurScore
******************** Auteur , Dates *************************
* Nom/Date : VIOLA
* 2/12/2015
********************* Description ***************************
* Lecture du fichier contenant les meilleurs scores et
* rempli le tableau avec les valeurs lues
*********************** Entrées *****************************
* "fichier" est la chaine de caractère qui contient le nom du fichier qui va être lu
* "meilleurScore" est un tableau de chaines de caractères qui reçoit les meilleurs scores
*********************** Sorties *****************************
* Rien
************************************************************/
void LireMeilleurScore(string fichier,string meilleurScore[])
{
    int i=0;
    fstream f;

    f.open(fichier.c_str(), ios::in); //Ouverture en lecture

    if(f.fail()) //En cas d'echec d'ouverture
    {
        cerr << "ouverture en lecture impossible" << endl;
        exit(EXIT_FAILURE);
    }

    while(!f.eof()) //Lecture du fichier tant que l'on est pas à la fin de celui-ci
    {
        f >> meilleurScore[i];
        i++;
    }
    f.close(); //Fermeture
}


/****************** Nom de la fonction **********************
* changerMeilleurScore
******************** Auteur , Dates *************************
* Nom/Date : VIOLA
* 2/12/2015
********************* Description ***************************
* Insère un score dans le fichier qui contient les meilleurs scores si il fait parti des meilleurs scores
*
*********************** Entrées *****************************
* "fichier" est la chaine de caractères qui contient le nom du fichier qui va être lu
* "score" est le score du joueur, on l'écrira dans le fichier si jamais il fait parti des meilleurs scores
*********************** Sorties *****************************
* Rien
************************************************************/
void changerMeilleurScore(string fichier, int score)
{
    fstream f,f2;
    int tmp,i=0;

    f.open(fichier.c_str(), ios:: in); //Ouverture en lecture
    f2.open("fichierTampon.txt", ios::out);//fichier intermédiaire en ecriture

    if(f.fail())
    {
        cerr << "ouverture en lecture impossible" << endl;
        exit(EXIT_FAILURE);
    }
    if(f2.fail())
    {
        cerr << "ouverture en ecriture impossible" << endl;
        exit(EXIT_FAILURE);
    }
    while(!f.eof() && tmp>score)
    {
        f >> tmp;
        if(tmp>score)
        {
            f2 << tmp << endl; //on copie le fichier meilleur score dans un fichier tampon tant qu'on est pas arriver à la fin du fichier meilleur score et tant que le score du joueur n'est pas  supérieur à un score du tableau
        }
    }
    if(!f.eof())
    {
        f2 << score << endl;//si on est pas arrivé à la fin du fichier meilleur score on copie le score du joueur dans le fichier tampon
        f2 << tmp << endl;
    }
    while(!f.eof())
    {
        f >> tmp;
        f2 << tmp << endl;// tant qu'on est pas arrivé à la fin du fichier on continue à copier le fichier meilleur score dans le fichier tampon

        i++;

    }


    f.close();
    f2.close();

    i=0;

    f.open(fichier.c_str(), ios::out);
    f2.open("fichierTampon.txt", ios::in);

    if(f2.fail())
    {
        cerr << "ouverture en lecture impossible" << endl;
        exit(EXIT_FAILURE);
    }
    if(f.fail())
    {
        cerr << "ouverture en ecriture impossible" << endl;
        exit(EXIT_FAILURE);
    }
    while(!f2.eof() && i<5)// i<5 parce qu'il n'y a que 5 meilleurs scores
    {
        f2 >> tmp;
        f << tmp << endl; //on copie le fichier tampon dans le fichier meilleur score en effaçant ce qu'il y avait au préalable.
        i++;
    }

    f.close();
    f2.close();
}
