#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "background.h"
int main(int argc,char *argv[])
{
SDL_Surface *screen=NULL;
SDL_Event event; 
Mix_Chunk *son;  

int continuer=1;
Background back;
sprite b; 
TTF_Init(); 
SDL_Init(SDL_INIT_AUDIO); 
Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096); 
if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_RESIZABLE)!=0)
{
 printf("erreur %s",SDL_GetError());
 return -1;
}
screen = SDL_SetVideoMode(2048, 546, 32, SDL_SWSURFACE); 
SDL_WM_SetCaption("Background", NULL);
if(screen==NULL) 
{
printf("erreur : %s",SDL_GetError());
SDL_Quit();
}
initBack(&back);
initanime(&b); 
son=Mix_LoadWAV("effet.wav"); 
Mix_PlayChannel(-1,son,0); 
while(continuer) 
{
 while(SDL_PollEvent(&event))
 { 
  switch(event.type) 
   {
   case SDL_QUIT:
   continuer=0;	
   case SDL_KEYDOWN: 
      switch(event.key.keysym.sym) 
      {
        case SDLK_RIGHT: 
        scrolling(&back,0);
        SDL_Flip(screen);
        break; 
        case SDLK_LEFT: 
        scrolling(&back,1);
        SDL_Flip(screen);
        break; 
        default: 
        break; 

}
case SDL_KEYUP:
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        SDL_Flip(screen);
                        break;
                    case SDLK_RIGHT:
                         SDL_Flip(screen);
                        break;
             }
                break;
break; 
}
} 
/*partagepre(screen,&back);
partagedeu(screen,&back);*/
afficherBack(&back,screen);
afficheranim(b,screen);
animerBackground(&b);
SDL_Flip(screen);

}
SDL_FreeSurface(back.bg); 
Mix_FreeChunk(son);
SDL_Quit;
return 0;
}
		
          
