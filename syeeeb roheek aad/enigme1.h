#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#define SCREEN_W 1202 
#define SCREEN_H 902 


typedef struct 
{
	SDL_Surface* image[96]; 
	SDL_Surface *back_GO, *back_vic;
	SDL_Rect PosBack;
        int CUR_IM, PR_IM; 
	SDL_Surface *ImNormal, *ImMod; 
	SDL_Rect PosImNormal, PosImMod; 
	int RepJUST; 
	Mix_Music *music_jeu, *music_vic, *music_lose; 
}enigme;

void initialiserEnigme(enigme* e); 
void afficherEnigme(enigme e, SDL_Surface* screen); 
void animerEnigme(enigme* e); 
void genererEnigme(enigme *e); 
void freeEnigme(enigme e); 
int RANDOM(int min, int max); 









