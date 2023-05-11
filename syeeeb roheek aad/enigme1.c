#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include "enigme1.h"

void initialiserEnigme(enigme* e)
{
	e->image[0]=IMG_Load("animation/1.jpg"); 
	e->image[1]=IMG_Load("animation/2.jpg");
	e->image[2]=IMG_Load("animation/3.jpg");
	e->image[3]=IMG_Load("animation/4.jpg");
	e->image[4]=IMG_Load("animation/5.jpg");
	e->image[5]=IMG_Load("animation/6.jpg");
	e->image[6]=IMG_Load("animation/7.jpg");
	e->image[7]=IMG_Load("animation/8.jpg");
	e->image[8]=IMG_Load("animation/9.jpg");
	e->image[9]=IMG_Load("animation/10.jpg");
	e->image[10]=IMG_Load("animation/11.jpg");
	e->image[11]=IMG_Load("animation/12.jpg");
	e->image[12]=IMG_Load("animation/13.jpg");
	e->image[13]=IMG_Load("animation/14.jpg");
	e->image[14]=IMG_Load("animation/15.jpg");
	e->image[15]=IMG_Load("animation/16.jpg");
	e->image[16]=IMG_Load("animation/17.jpg");
	e->image[17]=IMG_Load("animation/18.jpg");
	e->image[18]=IMG_Load("animation/19.jpg");
	e->image[19]=IMG_Load("animation/20.jpg");
	e->image[20]=IMG_Load("animation/21.jpg");
	e->image[21]=IMG_Load("animation/22.jpg");
	e->image[22]=IMG_Load("animation/23.jpg");
	e->image[23]=IMG_Load("animation/24.jpg");
	e->image[24]=IMG_Load("animation/25.jpg");
	e->image[25]=IMG_Load("animation/26.jpg");
	e->image[26]=IMG_Load("animation/27.jpg");
	e->image[27]=IMG_Load("animation/28.jpg");
	e->image[28]=IMG_Load("animation/29.jpg");
	e->image[29]=IMG_Load("animation/30.jpg");
	e->image[30]=IMG_Load("animation/31.jpg"); 
	e->image[31]=IMG_Load("animation/32.jpg");
	e->image[32]=IMG_Load("animation/33.jpg");
	e->image[33]=IMG_Load("animation/34.jpg");
	e->image[34]=IMG_Load("animation/35.jpg");
	e->image[35]=IMG_Load("animation/36.jpg");
	e->image[36]=IMG_Load("animation/37.jpg");
	e->image[37]=IMG_Load("animation/38.jpg");
	e->image[38]=IMG_Load("animation/39.jpg");
	e->image[39]=IMG_Load("animation/40.jpg");
	e->image[40]=IMG_Load("animation/41.jpg");
	e->image[41]=IMG_Load("animation/42.jpg");
	e->image[42]=IMG_Load("animation/43.jpg");
	e->image[43]=IMG_Load("animation/44.jpg");
	e->image[44]=IMG_Load("animation/45.jpg");
	e->image[45]=IMG_Load("animation/46.jpg");
	e->image[46]=IMG_Load("animation/47.jpg");
	e->image[47]=IMG_Load("animation/48.jpg");
	e->image[48]=IMG_Load("animation/49.jpg");
	e->image[49]=IMG_Load("animation/50.jpg");
	e->image[50]=IMG_Load("animation/51.jpg");
	e->image[51]=IMG_Load("animation/52.jpg");
	e->image[52]=IMG_Load("animation/53.jpg");
	e->image[53]=IMG_Load("animation/54.jpg");
	e->image[54]=IMG_Load("animation/55.jpg");
	e->image[55]=IMG_Load("animation/56.jpg");
	e->image[56]=IMG_Load("animation/57.jpg");
	e->image[57]=IMG_Load("animation/58.jpg");
	e->image[58]=IMG_Load("animation/59.jpg");
	e->image[59]=IMG_Load("animation/60.jpg");
	e->image[60]=IMG_Load("animation/61.jpg"); 
	e->image[61]=IMG_Load("animation/62.jpg");
	e->image[62]=IMG_Load("animation/63.jpg");
	e->image[63]=IMG_Load("animation/64.jpg");
	e->image[64]=IMG_Load("animation/65.jpg");
	e->image[65]=IMG_Load("animation/66.jpg");
	e->image[66]=IMG_Load("animation/67.jpg");
	e->image[67]=IMG_Load("animation/68.jpg");
	e->image[68]=IMG_Load("animation/69.jpg");
	e->image[69]=IMG_Load("animation/70.jpg");
	e->image[70]=IMG_Load("animation/71.jpg");
	e->image[71]=IMG_Load("animation/72.jpg");
	e->image[72]=IMG_Load("animation/73.jpg");
	e->image[73]=IMG_Load("animation/74.jpg");
	e->image[74]=IMG_Load("animation/75.jpg");
	e->image[75]=IMG_Load("animation/76.jpg");
	e->image[76]=IMG_Load("animation/77.jpg");
	e->image[77]=IMG_Load("animation/78.jpg");
	e->image[78]=IMG_Load("animation/79.jpg");
	e->image[79]=IMG_Load("animation/80.jpg");
	e->image[80]=IMG_Load("animation/81.jpg");
	e->image[81]=IMG_Load("animation/82.jpg");
	e->image[82]=IMG_Load("animation/83.jpg");
	e->image[83]=IMG_Load("animation/84.jpg");
	e->image[84]=IMG_Load("animation/85.jpg");
	e->image[85]=IMG_Load("animation/86.jpg");
	e->image[86]=IMG_Load("animation/87.jpg");
	e->image[87]=IMG_Load("animation/88.jpg");
	e->image[88]=IMG_Load("animation/89.jpg");
	e->image[89]=IMG_Load("animation/90.jpg");
	e->image[90]=IMG_Load("animation/91.jpg");
	e->image[91]=IMG_Load("animation/92.jpg");
	e->image[92]=IMG_Load("animation/93.jpg");
	e->image[93]=IMG_Load("animation/94.jpg");
	e->image[94]=IMG_Load("animation/95.jpg");
	e->image[95]=IMG_Load("animation/96.jpg");


	e->back_GO=IMG_Load("win VS LOSE/GO"); 
	e->back_vic=IMG_Load("win VS LOSE/victoire"); 
	
	e->PosBack.x=0; 
	e->PosBack.y=0;
	
	e->PosImNormal.x=50; 
	e->PosImNormal.y=200;
	
	e->PosImMod.x=850; 
	e->PosImMod.y=200;
	
        e->CUR_IM=0; 
	e->PR_IM=-1; 
	
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	e->music_jeu=Mix_LoadMUS("music/music.mp3"); 
	e->music_vic=Mix_LoadMUS("music/MAGIC SYSTEM - Magic In The Air Feat. Chawki [Clip Officiel].mp3"); 
	e->music_lose=Mix_LoadMUS("music/Bruit de rire.mp3"); 
	

}

void genererEnigme(enigme *e)
{
	int nb,RepJUST; 
	char normale[100], modifiee[100]; 
	FILE* fichier;
	nb=RANDOM(1,3); 
	switch (nb)
	{
		case 1 :
		{
			strcpy(normale,"diff/1/normal");
			strcpy(modifiee,"diff/1/mod");
			fichier=fopen("diff/1/nb_diff.txt","r");	
			fscanf(fichier,"%d",&RepJUST);
			break;
		}
		case 2 :
		{
			strcpy(normale,"diff/2/normal");
			strcpy(modifiee,"diff/2/mod");
			fichier=fopen("diff/2/nb_diff.txt","r");	
			fscanf(fichier,"%d",&RepJUST);
			break;
		}
		case 3 :
		{
			strcpy(normale,"diff/3/normal");
			strcpy(modifiee,"diff/3/mod");
			fichier=fopen("diff/3/nb_diff.txt","r");	
			fscanf(fichier,"%d",&RepJUST);
			break;
		}
		
	}
	e->ImNormal=IMG_Load(normale); 
	e->ImMod=IMG_Load(modifiee); 
	e->RepJUST=RepJUST; 
}
void animerEnigme(enigme* e)
{
	if (e->CUR_IM==95) 
	{
		e->PR_IM=e->CUR_IM; 
		e->CUR_IM--; 
	}
	else if (e->CUR_IM==0) 
		{
			e->PR_IM=e->CUR_IM; 
			e->CUR_IM++; 
		}
    	else if (e->CUR_IM > e->PR_IM) 
		{
			e->PR_IM=e->CUR_IM; 
			e->CUR_IM++;
		}
    	else 
	{
		e->PR_IM=e->CUR_IM;		
		e->CUR_IM--;
	}
}

void afficherEnigme(enigme e, SDL_Surface* screen)
{
	SDL_BlitSurface(e.image[e.CUR_IM], NULL, screen, &e.PosBack); 
	SDL_BlitSurface(e.ImNormal, NULL, screen, &e.PosImNormal); 
	SDL_BlitSurface(e.ImMod, NULL, screen, &e.PosImMod); 
}

int RANDOM(int min, int max) 
{
    srand(time(NULL)); 
    return (min + rand() % (max - min + 1));
}


void freeEnigme(enigme e) 
{
	SDL_FreeSurface(e.image[0]);
	SDL_FreeSurface(e.image[1]);
	SDL_FreeSurface(e.image[2]);
	SDL_FreeSurface(e.image[3]);
	SDL_FreeSurface(e.image[4]);
	SDL_FreeSurface(e.image[5]);
	SDL_FreeSurface(e.image[6]);
	SDL_FreeSurface(e.image[7]);
	SDL_FreeSurface(e.image[8]);
	SDL_FreeSurface(e.image[9]);
	SDL_FreeSurface(e.image[10]);
	SDL_FreeSurface(e.image[11]);
	SDL_FreeSurface(e.image[12]);
	SDL_FreeSurface(e.image[13]);
	SDL_FreeSurface(e.image[14]);
	SDL_FreeSurface(e.image[15]);
	SDL_FreeSurface(e.image[16]);
	SDL_FreeSurface(e.image[17]);
	SDL_FreeSurface(e.image[18]);
	SDL_FreeSurface(e.image[19]);
	SDL_FreeSurface(e.image[20]);
	SDL_FreeSurface(e.image[21]);
	SDL_FreeSurface(e.image[22]);
	SDL_FreeSurface(e.image[23]);
	SDL_FreeSurface(e.image[24]);
	SDL_FreeSurface(e.image[25]);
	SDL_FreeSurface(e.image[26]);
	SDL_FreeSurface(e.image[27]);
	SDL_FreeSurface(e.image[28]);
	SDL_FreeSurface(e.image[29]);
	SDL_FreeSurface(e.image[30]);
	SDL_FreeSurface(e.image[31]);
	SDL_FreeSurface(e.image[32]);
	SDL_FreeSurface(e.image[33]);
	SDL_FreeSurface(e.image[34]);
	SDL_FreeSurface(e.image[35]);
	SDL_FreeSurface(e.image[36]);
	SDL_FreeSurface(e.image[37]);
	SDL_FreeSurface(e.image[38]);
	SDL_FreeSurface(e.image[39]);
	SDL_FreeSurface(e.image[40]);
	SDL_FreeSurface(e.image[41]);
	SDL_FreeSurface(e.image[42]);
	SDL_FreeSurface(e.image[43]);
	SDL_FreeSurface(e.image[44]);
	SDL_FreeSurface(e.image[45]);
	SDL_FreeSurface(e.image[46]);
	SDL_FreeSurface(e.image[47]);
	SDL_FreeSurface(e.image[48]);
	SDL_FreeSurface(e.image[49]);
	SDL_FreeSurface(e.image[50]);
	SDL_FreeSurface(e.image[51]);
	SDL_FreeSurface(e.image[52]);
	SDL_FreeSurface(e.image[53]);
	SDL_FreeSurface(e.image[54]);
	SDL_FreeSurface(e.image[55]);
	SDL_FreeSurface(e.image[56]);
	SDL_FreeSurface(e.image[57]);
	SDL_FreeSurface(e.image[58]);
	SDL_FreeSurface(e.image[59]);
	SDL_FreeSurface(e.image[60]);
	SDL_FreeSurface(e.image[61]);
	SDL_FreeSurface(e.image[62]);
	SDL_FreeSurface(e.image[63]);
	SDL_FreeSurface(e.image[64]);
	SDL_FreeSurface(e.image[65]);
	SDL_FreeSurface(e.image[66]);
	SDL_FreeSurface(e.image[67]);
	SDL_FreeSurface(e.image[68]);
	SDL_FreeSurface(e.image[69]);
	SDL_FreeSurface(e.image[70]);
	SDL_FreeSurface(e.image[71]);
	SDL_FreeSurface(e.image[72]);
	SDL_FreeSurface(e.image[73]);
	SDL_FreeSurface(e.image[74]);
	SDL_FreeSurface(e.image[75]);
	SDL_FreeSurface(e.image[76]);
	SDL_FreeSurface(e.image[77]);
	SDL_FreeSurface(e.image[78]);
	SDL_FreeSurface(e.image[79]);
	SDL_FreeSurface(e.image[80]);
	SDL_FreeSurface(e.image[81]);
	SDL_FreeSurface(e.image[82]);
	SDL_FreeSurface(e.image[83]);
	SDL_FreeSurface(e.image[84]);
	SDL_FreeSurface(e.image[85]);
	SDL_FreeSurface(e.image[86]);
	SDL_FreeSurface(e.image[87]);
	SDL_FreeSurface(e.image[88]);
	SDL_FreeSurface(e.image[89]);
	SDL_FreeSurface(e.image[90]);
	SDL_FreeSurface(e.image[91]);
	SDL_FreeSurface(e.image[92]);
	SDL_FreeSurface(e.image[93]);
	SDL_FreeSurface(e.image[94]);
	SDL_FreeSurface(e.image[95]);
	
	SDL_FreeSurface(e.ImNormal);
	SDL_FreeSurface(e.ImMod);
	SDL_FreeSurface(e.back_GO);
	SDL_FreeSurface(e.back_vic);
	Mix_FreeMusic(e.music_jeu);
	Mix_FreeMusic(e.music_vic);
	Mix_FreeMusic(e.music_lose);
}

void e()
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
		SDL_PollEvent(&event);
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
		SDL_Flip(screen);
		SDL_Delay(40);
	}
	freeEnigme(e);
}















