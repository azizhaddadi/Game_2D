#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <time.h>

typedef struct temps
{
SDL_Surface *texte;
 SDL_Rect position;

    TTF_Font *police ;

 char entree[100]; 
 int secondesEcoulees; 
SDL_Color couleurBlanche;
time_t t1,t2;
int min, sec;
}temps;

void initialiser_temps(temps *t);
void afficher_temps(temps *t, SDL_Surface *ecran);
void free_temps(temps *t,SDL_Surface *ecran);

typedef struct
{SDL_Surface *map;
SDL_Surface  *minibonhomme;
SDL_Rect positionmap;
SDL_Rect posminibonhomme;
}minimap;


void init_map(minimap *m); 
void MAJMinimap(SDL_Rect pos_joueur,  minimap * m, SDL_Rect camera, int redimensionnement); 
void afficherminimap (minimap m, SDL_Surface * screen);

void init_mini(minimap *m1);
void MAJMinimap1(SDL_Rect pos_joueur,  minimap * m1, SDL_Rect camera, int redimensionnement);
void affichermini(minimap m1, SDL_Surface * screen);












SDL_Color GetPixel(SDL_Surface *pSurface , int x,int y); 
int collision_pright(SDL_Surface *mask , SDL_Rect pos_joueur ); 
int collision_pleft(SDL_Surface *mask , SDL_Rect pos_joueur ); 
int collision_pup(SDL_Surface *mask , SDL_Rect pos_joueur );
int collision_pdown(SDL_Surface *mask , SDL_Rect pos_joueur );
#endif // MAP_H_INCLUDED
