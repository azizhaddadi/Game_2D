#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "map.h"


int main()
{
TTF_Init();
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen , *mask, *perso;
screen=SDL_SetVideoMode (900,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
temps t;
minimap m , m1 ;
SDL_Rect posperso,camera;
SDL_Event event;
mask=IMG_Load("mask.jpg");
perso=IMG_Load("hero.png");
initialiser_temps(&t);
init_map(&m);
init_mini(&m1);
posperso.x=0;
posperso.y=0;


camera.x=0;
camera.y=0;
camera.w=800;
camera.h=600;
int continuer=1;

SDL_EnableKeyRepeat(100,10);


while(continuer)
{
    
while(SDL_PollEvent(&event))
	{

		switch(event.type)
		{
		case SDL_QUIT:

			continuer=0;
		break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
                case SDLK_LEFT:
                 
                    if (collision_pleft(mask,posperso)==0)   posperso.x-=5;
                    
                    
                 
                    
                break;
                case SDLK_RIGHT:
                   if (collision_pright(mask,posperso)==0)
                      posperso.x+=5;
                   
                   
                    
                break;
                case SDLK_UP:
                     if (collision_pup(mask,posperso)==0)
                     posperso.y-=5;
                break;  
                case SDLK_DOWN:
                if (collision_pdown(mask,posperso)==0)
                     posperso.y+=5;
                break;  

            }
            break;
            
        }
    }  
     
     


     
MAJMinimap(posperso,&m,camera,20);
MAJMinimap1(posperso,&m1,camera,20);
SDL_BlitSurface(mask,NULL,screen,NULL);

afficherminimap(m,screen);
affichermini(m1,screen);
SDL_BlitSurface(perso,NULL,screen,&posperso);






afficher_temps(&t,screen);
SDL_Flip(screen);
SDL_Delay(50);



}

}
