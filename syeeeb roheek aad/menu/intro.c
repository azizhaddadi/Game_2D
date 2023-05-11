#include "intro.h"
#define SCREEN_W 800
#define SCREEN_H 533
void intro(SDL_Surface *ecran)
{
	SDL_Surface *logo=NULL, *coat=NULL;
	SDL_Rect poslogo;
	poslogo.x=0;
	poslogo.y=0;
	int i=0;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Event event;
	logo=IMG_Load ("intro_logo.png");
	coat=IMG_Load ("intro_coat.png");
	ecran= SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_RESIZABLE);
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

	
	while (i!=128)
	{
		SDL_SetAlpha (logo, SDL_SRCALPHA, i);
		SDL_BlitSurface(logo, NULL, ecran, &poslogo);
		SDL_Flip(ecran);
		i++;
		while (SDL_PollEvent(&event))
		switch(event.type)
		 {
		 	case SDL_KEYDOWN:
		 	switch (event.key.keysym.sym)
		 	{
		 		case SDLK_ESCAPE:
		 		i=128;
		 		break;
		 	}
		 }
	}
	
	i=0;
		while (i!=128)
	{
		SDL_SetAlpha (coat, SDL_SRCALPHA, i);
		SDL_BlitSurface(coat, NULL,ecran, &poslogo);
		SDL_Flip(ecran);
		i++;
		while (SDL_PollEvent(&event))
		switch(event.type)
		{
		 	case SDL_KEYDOWN:
		 	switch (event.key.keysym.sym)
		 	{
		 		case SDLK_ESCAPE:
		 		i=128;
		 		break;
		 	}
		 }
	}
	
	SDL_FreeSurface(logo);
	SDL_FreeSurface(coat);
}
