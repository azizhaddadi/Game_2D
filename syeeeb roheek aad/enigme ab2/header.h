#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<time.h>
#include<string.h>

typedef struct 
{
	SDL_Surface *imag[6],*anim[20],*sprite;   
	SDL_Surface *b;
	SDL_Surface *answer,*answer1 ;
SDL_Surface *keyboard;
	SDL_Rect  posanswer, posscore, posimage, posbackground,posanim;
	char solution1;
}enigme;

void affich_enigme1(enigme e,char *nomficher);
void animer(SDL_Surface *screen,enigme *e);
int initEnigme();



#endif
