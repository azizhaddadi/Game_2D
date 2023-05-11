#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include "enigme.h"

void main()
{
	SDL_Surface* screen;
	enigme e;
	SDL_Event event;
	int boucle = 1;
        int ecran=1; 
    	SDL_Init(SDL_INIT_EVERYTHING);
    	screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    	
    	
	initialiserEnigme(&e);
	genererEnigme(&e);
	Mix_PlayMusic(e.music_jeu, -1);
	while (boucle==1)
	{
                if(ecran==1) 
                { 
			animerEnigme(&e);
			afficherEnigme(e,screen);
                }
		if(ecran==2) 
		{
			SDL_BlitSurface(e.back_vic, NULL, screen, &e.PosBack); 
	                SDL_Flip(screen);
			Mix_PlayMusic(e.music_vic, 0); 
			SDL_Delay(500);
			boucle=0;
		}
		if(ecran==3) 
		{
			SDL_BlitSurface(e.back_GO, NULL, screen, &e.PosBack); 
			SDL_Flip(screen);
			Mix_PlayMusic(e.music_lose, 0); 
			SDL_Delay(500);
			boucle=0;
		}
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT :
					boucle = 0;
					break;
				case SDL_KEYDOWN:
				{
					switch (event.key.keysym.sym)
					{
						case SDLK_ESCAPE :
							boucle = 0;
							break;
						case SDLK_p :
							if (e.RepJUST==0) 
							   ecran=2;
							else ecran=3;
							break;
						case SDLK_a :
							if (e.RepJUST==1) 
							   ecran=2;
							else ecran=3;
							break;
						case SDLK_z :
							if (e.RepJUST==2) 
							  ecran=2;
							else ecran=3;
							break;
						case SDLK_e :
							if (e.RepJUST==3) 
							  ecran=2;
							else ecran=3;
							break;
						case SDLK_r :
							if (e.RepJUST==4) 
							   ecran=2;
							else ecran=3;
							break;
						case SDLK_t :
							if (e.RepJUST==5) 
							   ecran=2;
							else ecran=3;
							break;
						case SDLK_y:
							if (e.RepJUST==6) 
							   ecran=2;
							else ecran=3;
							break;
						case SDLK_u :
							if (e.RepJUST==7)  
							  ecran=2;
							else ecran=3;
							break;
						case SDLK_i :
							if (e.RepJUST==8)  
							   ecran=2;
							else ecran=3;
							break;
						case SDLK_o :
							if (e.RepJUST==9) 
							   ecran=2;
							else ecran=3;
							break;
						
					}

				}
			} 
                }
		SDL_Flip(screen);
		SDL_Delay(40);
	}
	freeEnigme(e);
}
