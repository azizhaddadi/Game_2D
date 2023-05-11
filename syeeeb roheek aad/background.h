#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_W 3000
#define SCREEN_H 700
typedef struct  
{
      SDL_Surface *bg,*bg2;  
      SDL_Rect pos1,pos2; 
}Backgroundd;
typedef struct 
{
SDL_Surface *bg; 
int direction; 
SDL_Rect posScreen;
SDL_Rect posSprite; 
}sprite;
void initBackk(Backgroundd * b);					
void afficherBack(Backgroundd *b,SDL_Surface *screen);
void scrolling(Backgroundd *b,int direction);					
void animerBack (Backgroundd* b);
void initanime(sprite *b);
void afficheranim(sprite b, SDL_Surface *screen);
void deplaceranime(sprite *b);
void animerBackground( sprite * b);
void initBack(Backgroundd *b);
void initBackgg(Backgroundd *b);	
void partagepre(SDL_Surface * screen,Backgroundd *b);
void partagedeu(SDL_Surface * screen,Backgroundd *b);	
#endif
