#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "map.h"


void init_map(minimap *m)
{ m -> map = IMG_Load("background_17.png");
  m-> minibonhomme = IMG_Load("download.png");
  m->positionmap.x =100;
  m->positionmap.y =0;
}

void MAJMinimap(SDL_Rect pos_joueur,  minimap * m, SDL_Rect camera, int redimensionnement)
{
  SDL_Rect pos_joueurABS;
  pos_joueurABS.x = 0;
  pos_joueurABS.y = 0;
  pos_joueurABS.x = pos_joueur.x + camera.x;
  pos_joueurABS.y = pos_joueur.y + camera.y;
  m->posminibonhomme.x=(pos_joueurABS.x * redimensionnement/100)+250;
  m->posminibonhomme.y=(pos_joueurABS.y * redimensionnement/100)+21;
}

void afficherminimap(minimap m, SDL_Surface * screen)
{
  SDL_BlitSurface(m.minibonhomme,NULL,screen,&m.posminibonhomme);
}








void init_mini(minimap *m1)
{ m1 -> map = IMG_Load("background_1_28.png");
  m1-> minibonhomme = IMG_Load("download.png");
  m1->positionmap.x =500;
  m1->positionmap.y =50;
  m1->posminibonhomme.x =700;
  m1->posminibonhomme.y =50;
}


void MAJMinimap1(SDL_Rect pos_joueur,  minimap * m1, SDL_Rect camera, int redimensionnement)
{
  SDL_Rect pos_joueurABS;
  pos_joueurABS.x = 0;
  pos_joueurABS.y = 0;
  pos_joueurABS.x = pos_joueur.x + camera.x;
  pos_joueurABS.y = pos_joueur.y + camera.y;
  m1->posminibonhomme.x=(pos_joueurABS.x * redimensionnement/100)+250;
  m1->posminibonhomme.y=(pos_joueurABS.y * redimensionnement/100)+21;
}

void affichermini(minimap m1, SDL_Surface * screen)
{
  SDL_BlitSurface(m1.map,NULL,screen,&m1.positionmap);
}









void initialiser_temps(temps *t)
{
 t->texte = NULL; 
 t->position.x=0;
   t->position.y=100;
     t->police = NULL;
  t->police = TTF_OpenFont("ACaslonPro-Semibold.otf", 40);
    strcpy( t->entree,"");
(t->secondesEcoulees)=0;
time(&(t->t1)); 



}


void afficher_temps(temps *t,SDL_Surface *ecran)
{	
SDL_Color couleurBlanche= {0, 0, 0};

    	time(&(t->t2));

		t->secondesEcoulees = t->t2 - t->t1;

        t->min=((t->secondesEcoulees/60)%60);
	t->sec= ((t->secondesEcoulees)%60);

	 sprintf(t->entree,"%02d:%02d",t->min,t->sec);
        t->texte = TTF_RenderUTF8_Solid(t->police, t->entree, couleurBlanche);
      

SDL_BlitSurface(t->texte, NULL, ecran, &(t->position)); 
  


 
	
}

void free_temps(temps *t,SDL_Surface *ecran)
{SDL_FreeSurface(t->texte);
 TTF_CloseFont(t->police);
}





SDL_Color GetPixel(SDL_Surface *pSurface ,int x,int y)
{
    SDL_Color color;
    Uint32 col=0;
    char *pPosition = (char *) pSurface -> pixels;
    pPosition+=(pSurface->pitch *y);
    pPosition+=(pSurface ->format->BytesPerPixel *x);
    memcpy (&col,pPosition,pSurface ->format ->BytesPerPixel);

SDL_GetRGB(col,pSurface -> format,&color.r ,&color.g ,&color.b);
return (color);
}



int collision_pright(SDL_Surface *mask , SDL_Rect pos_joueur )
{  SDL_Color col,colp;
SDL_Rect pos[8];
int collision = 0;
int i,w,h;

col.r=0;
col.g=0;
col.b=0;

w=44;
h=70;


pos[5].x = pos_joueur.x +w;
pos[5].y = pos_joueur.y;



pos[6].x = pos_joueur.x +w;
pos[6].y = pos_joueur.y+ h/2;



pos[7].x = pos_joueur.x +w;
pos[7].y = pos_joueur.y +h;



for (i =5;(i < 8)&&(collision == 0); i++)
{
    colp = GetPixel(mask,pos[i].x ,pos[i].y);
    if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
    collision = 1;
}


return (collision);
}









int collision_pleft(SDL_Surface *mask, SDL_Rect pos_joueur)
{
SDL_Color col,colp;
SDL_Rect pos[8];
int collision = 0;
int i,w,h;
col.r=0;
col.g=0;
col.b=0;


w=44;
h=70;


pos[0].x = pos_joueur.x;
pos[0].y = pos_joueur.y;

pos[1].x = pos_joueur.x;
pos[1].y = pos_joueur.y + h /2;

pos[2].x = pos_joueur.x;
pos[2].y = pos_joueur.y + h;


for (i =0;(i < 3)&&(collision == 0); i++)
{
col = GetPixel(mask,pos[i].x ,pos[i].y);
if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
collision = 1;
}
    return (collision);
}


int collision_pup(SDL_Surface *mask, SDL_Rect pos_joueur)
{
SDL_Color col,colp;
SDL_Rect pos;
int collision = 0;
int i,w,h;
col.r=0;
col.g=0;
col.b=0;


w=44;
h=70;



pos.x = pos_joueur.x + w/2;
pos.y = pos_joueur.y;

col = GetPixel(mask,pos.x ,pos.y);


if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))   collision = 1;


return (collision);
}




int collision_pdown(SDL_Surface *mask, SDL_Rect pos_joueur)
{
SDL_Color col,colp;
SDL_Rect pos;
int collision = 0;
int i,w,h;
col.r=0;
col.g=0;
col.b=0;


w=44;
h=70;



pos.x = pos_joueur.x+ w /2;
pos.y = pos_joueur.y +h;


col = GetPixel(mask,pos.x ,pos.y);

if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b)) collision = 1;

return (collision);
}

