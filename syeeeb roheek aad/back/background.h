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
}Background;
typedef struct 
{
SDL_Surface *bg; 
int direction; 
SDL_Rect posScreen;
SDL_Rect posSprite; 
}sprite;
void initBack(Background * b);					
void afficherBack(Background *b,SDL_Surface *screen);
void scrolling(Background *b,int direction);					
void animerBack (Background* b);
void initanime(sprite *b);
void afficheranim(sprite b, SDL_Surface *screen);
void deplaceranime(sprite *b);
void animerBackground( sprite * b);
void initBack(Background *b);
void initBackg(Background *b);	
void partagepre(SDL_Surface * screen,Background *b);
void partagedeu(SDL_Surface * screen,Background *b);	
#endif
