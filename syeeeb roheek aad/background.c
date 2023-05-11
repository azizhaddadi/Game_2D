#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "background.h"
void initBackk (Backgroundd *b)
{
b->bg=NULL;
b->pos1.x=0;
b->pos1.y=0;
b->pos1.w=2048;
b->pos1.h=512;
b->pos2.x=0;
b->pos2.y=0;
b->pos2.w=2048;
b->pos2.h=512;
b->bg=IMG_Load("background.png");
}
void afficherBack(Backgroundd *b,SDL_Surface *screen)
{
SDL_BlitSurface(b->bg,&(b->pos1),screen,NULL);
}
void scrolling(Backgroundd *b,int direction)
{
if(direction==0) {
b->pos1.x+=30; 
b->pos2.x+=30; 
if(b->pos1.x>=2048) 
{
   b->pos1.x=0; 
   b->pos2.x=0;
 }
}
else if(direction==1) 
{ 
b->pos1.x-=30; 
b->pos2.x-=30; 
if(b->pos1.x<=0){
   b->pos1.x=0; 
   b->pos2.x=0;
}
}
}
void initanime(sprite *b)
{
    b->bg=IMG_Load("clouds.png");
    b->posSprite.x=0;
    b->posSprite.y=0;
    b->posSprite.h=408/3;
    b->posSprite.w=612/3;
} 
void animerBackground(sprite * b)
{
  (*b).posSprite.y=(b->direction)*(b->posSprite.h);
          
          if ((*b).posSprite.x==612-b->posSprite.w)
               {
                (*b).posSprite.x=0;
                 SDL_Delay(100);
               }
          else 
          
              {
               (*b).posSprite.x+=b->posSprite.w;
                SDL_Delay(100);
               }
}
void afficheranim(sprite b, SDL_Surface *screen)
{
  SDL_BlitSurface(b.bg, &b.posSprite, screen, &b.posScreen);  
}



