#include <SDL/SDL.h>
#include "texte.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
//liberer memoir a chaque fois on quitte un stage

void initText(Text *A)
{

	A->position.x=200;
	A->position.y=0;
// couleur jaune
	A->textColor.r=0;
	A->textColor.g=0;
	A->textColor.b=0;

	A->font = TTF_OpenFont( "police.TTF", 180 );

}

void initTextf(Text *A)
{

	A->position.x=150;
	A->position.y=85;
// couleur jaune
	A->textColor.r=0;
	A->textColor.g=0;
	A->textColor.b=0;

	A->font = TTF_OpenFont( "police.TTF", 100 );

}

void freeText(Text A)
{
		SDL_FreeSurface(A.surfaceTexte);
}
void displayText(Text t,SDL_Surface *screen)
{
t.surfaceTexte = TTF_RenderText_Solid(t.font, "menu" , t.textColor );
SDL_BlitSurface(t.surfaceTexte, NULL, screen,&t.position);
}
