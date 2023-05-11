#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"
//void init_background_jeux(Image *Backg);
int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_VIDEO);
    atexit(SDL_Quit);
   Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) ;
 
         Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1000) ;
 
    Mix_Music *music = Mix_LoadMUS("images/son/Trailer Bros - The World is Yours (Epic Powerful Cinematic Orchestral).mp3");
 
   Mix_PlayMusic(music, 1); 
    int done = 0;
    SDL_Surface *screen;
    screen = SDL_SetVideoMode(1250, 666, 32, SDL_HWSURFACE | SDL_RESIZABLE);
    if (!screen)
    {
        printf("unable to set 1250x666 %s\n", SDL_GetError());
        return 1;
    }


    SDL_Event event;
    Uint32 t_prev1, t_prev2,t_prev3;
    Image temp_background;
    //init_background_jeux(&temp_background);
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

    while (!done)
    {

        SDL_PollEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            done = 1;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_RIGHT:
                player1.direction = 0;
                player1.action = 1;

                break;
            case SDLK_LEFT:
                player1.direction = 1;
                player1.action = 1;
                break;
            case SDLK_UP:
                player1.saut = 1;
                break;
                         if(multiplayer==1){
          case SDLK_d:
                player2.direction = 0;
                player2.action = 1;

                break;
            case SDLK_q:
                player2.direction = 1;
                player2.action = 1;
                break;
            case SDLK_z:
                player2.saut = 1;
                break;}

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
                         if(multiplayer==1){
           case SDLK_d:
                player2.action = 0;

                break;
            case SDLK_q:
                player2.action = 0;

                break;
            case SDLK_z:
                player2.saut = 0;
                break;   }          
            }
            break;
        }

        if (SDL_GetTicks() - t_prev1 > 20)
        {

            //afficher(temp_background, screen);
           saut(&player1);
            MovePerso(&player1);
            animerPerso(&player1);
 
             afficher_perso(player1, screen);
                    afficher_newscore(player1.score, screen, player1.scoreimg,168);
            if(multiplayer==1){
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
        if(multiplayer){
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
       

        SDL_Flip(screen); 
    }
}

