#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

#include <string>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

const int SCREEN_WIDTH=750;
const int SCREEN_HEIGHT=761;
const int SCREEN_BPP=32;

using namespace std;

const int tailleMS=5;
typedef ostringstream TFont[tailleMS];

SDL_Surface* loadedImage(string filename);

SDL_Surface* loadedImageWithColorkey(string filename, int r, int g, int b);

void applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);

void showMessageScreen(string message,int x,int y,TTF_Font *font,int fontSize,SDL_Color textColor,SDL_Surface* &screen);

#endif // IMAGE_H_INCLUDED
