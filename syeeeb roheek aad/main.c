#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "background.h"
#include "perso.h"
#include "enemie.h"
#include "map.h"
#include <SDL/SDL.h>
#include "Backg.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include "texte.h"
#include "Buttons.h"
#include "Backg.h"
#include "intro.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
int main(int argc,char *argv[])
{
menu();
    SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
    atexit(SDL_Quit);
    Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) ;

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1000) ;

    Mix_Music *music = Mix_LoadMUS("images/son/Trailer Bros - The World is Yours (Epic Powerful Cinematic Orchestral).mp3");

    Mix_PlayMusic(music, 1);

    SDL_Surface *mask, *perso;

    temps t;
    minimap m, m1 ;
    SDL_Rect camera;
    mask=IMG_Load("mask.jpg");
    perso=IMG_Load("download.png");
    initialiser_temps(&t);
    init_map(&m);
    init_mini(&m1);


    camera.x=0;
    camera.y=0;
    camera.w=800;
    camera.h=600;


    SDL_EnableKeyRepeat(100,10);

    int en=0,e11=0;
    Ennemi E;

    initEnnemi(&E);


    Uint32 t_prev1, t_prev2,t_prev3;
    Image temp_background;
    Personne player1;
    initPerso(&player1);
    initlise_matrice(&player1);
    Personne player2;
    initPerso(&player2);
    initlise_matrice(&player2);

    int multiplayer=1;

    if (TTF_Init() == -1)
    {
        fprintf(stderr, "Failed to initialize SDL_ttf: %s\n", TTF_GetError());
        exit(1);
    }
    player1.newscore = 4000;
    player1.bonus = 1;
    player1.malus = 0;
    player2.newscore = 4000;
    player2.bonus = 0;
    player2.malus = 0;
    initilisation_newscore(&player1.scoreimg);
    initilisation_newscore(&player2.scoreimg);
    player1.action=0;
    int hit=0;
    SDL_Surface *screen=NULL;
    SDL_Event event;
    Mix_Chunk *son;
//*******PARTIE BACK
    int continuer=1;
    Backgroundd back;
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
    initBackk(&back);
    initanime(&b);
    son=Mix_LoadWAV("effet.wav");
    Mix_PlayChannel(-1,son,0);
    while(continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer=0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_RIGHT:
                scrolling(&back,0);
                player1.direction = 0;
                player1.action = 1;
                if (collision_pright(mask,player1.perso.posinscreen)==0)
                    player1.perso.posinscreen.x+=5;

                break;
            case SDLK_DOWN:
                if (collision_pdown(mask,player1.perso.posinscreen)==0)
                    player1.perso.posinscreen.y+=5;
                break;
case SDLK_LEFT:
                if (collision_pleft(mask,player1.perso.posinscreen)==0)
                    player1.perso.posinscreen.x-=5;
                scrolling(&back,1);
                player1.direction = 1;
                player1.action = 1;
                break;
            case SDLK_UP:
                player1.saut = 1;
                if (collision_pup(mask,player1.perso.posinscreen)==0)
                    player1.perso.posinscreen.y-=5;
                break;
            case SDLK_e:
                //ENIGMEE
                if(en!=1)
                    e();
                en=1;
                break;
            case SDLK_r:
                //ENIGME DADOU
                if(e11!=1)
                    e1();
                e11=1;
               // break;
                if(multiplayer==1)
                {
                case SDLK_d:
                    player2.direction = 0;
                    player2.action = 1;

                    break;
                case SDLK_q:
                    player2.direction=1;
                    player2.action = 1;
                    break;
                case SDLK_z:
                    player2.saut = 1;
                    break;
case SDLK_x:
hit=1;
break;
                }

            }
            break;

        case SDL_KEYUP:
            switch (event.key.keysym.sym)
            {
            case SDLK_RIGHT:
                player1.action = 0;

                break;
            case SDLK_LEFT:
                player1.action = 0;
                break;
            case SDLK_UP:
                player1.saut = 0;
                break;
                if(multiplayer==1)
                {
                case SDLK_d:
                    player2.action = 0;

                    break;
                case SDLK_q:
                    player2.action = 0;

                    break;
                case SDLK_z:
                    player2.saut = 0;
                    break;
                }
            }
            break;
        }

                   
        if(en)
            screen = SDL_SetVideoMode(2048, 546, 32, SDL_SWSURFACE);
        if (SDL_GetTicks() - t_prev1 > 20)
        {

            //afficher(temp_background, screen);

            if(multiplayer==1)
            {
                saut(&player2);
                MovePerso(&player2);
                animerPerso(&player2);
                afficher_perso(player2, screen);
                player2.scoreimg.posinscreen.x=1000;
                afficher_newscore(player2.score, screen, player2.scoreimg,1000+168);

            }
            t_prev1 = SDL_GetTicks();

        }
        if (SDL_GetTicks() - t_prev2 > 20)
        {
            if (player1.bonus == 1 && player1.score != player1.newscore)
            {
                player1.score++;
            }
            if (player1.malus == 1 && player1.score != player1.newscore)
            {
                player1.score--;
            }

            t_prev2 = SDL_GetTicks();
        }
        if(multiplayer)
        {
            if (SDL_GetTicks() - t_prev3 > 20)
            {
                if (player2.bonus == 1 && player2.score != player2.newscore)
                {
                    player2.score++;
                }
                if (player2.malus == 1 && player2.score != player2.newscore)
                {
                    player2.score--;
                }

                t_prev3 = SDL_GetTicks();
            }


        }


        /*partagepre(screen,&back);
        partagedeu(screen,&back);*/
        //PARTIE BACK

        afficherBack(&back,screen);
        afficheranim(b,screen);
        animerBackground(&b);
        saut(&player1);
        MovePerso(&player1);
        animerPerso(&player1);
        //PARTIE JOUEUR
        afficher_perso(player1, screen);
        afficher_newscore(player1.score, screen, player1.scoreimg,168);
        //PARTIE MINIMAP
        affichermini(m1,screen);
        MAJMinimap(player1.perso.posinscreen,&m,camera,20);
        MAJMinimap1(player1.perso.posinscreen,&m1,camera,20);
        afficherminimap(m,screen);
        afficher_temps(&t,screen);
       if(hit==0){
            // PARTIE ENNEMIE
            deplacer(&E);
            animerEnnemi(&E);
            afficherEnnemi(E, screen);
            deplacerIA(&E,player1.perso.posinscreen);
            
       

        }
         //if (collision(E.pos,  player1.perso.posinscreen) == 1){

           //        e();
             //      }
        SDL_Flip(screen);

    }
    SDL_Quit;
    return 0;
}

