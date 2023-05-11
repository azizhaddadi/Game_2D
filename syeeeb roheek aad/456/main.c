#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "enemie.h"

int main()
{

  SDL_Init(SDL_INIT_VIDEO);
  SDL_Surface *screen;
  screen = SDL_SetVideoMode(1000, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

  SDL_WM_SetCaption("entite secondaire", NULL);
  SDL_Rect posperso;

  posperso.x = 150;
  posperso.y = 400;
  posperso.h = 100;
  posperso.w = 100;

  Ennemi E;

  SDL_Event event;
  SDL_Surface *background;
  SDL_Surface *persotest;
  SDL_Surface *persotest1;

  initEnnemi(&E);
  int running = 1;
  background = IMG_Load("gamebackground.jpg");
  persotest = IMG_Load("persotest.png");
  persotest1 = IMG_Load("persotest1.png");

  while (running)
  {

    while (SDL_PollEvent(&event))
    {

      switch (event.type)
      {
      case SDL_QUIT:

        running = 0;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {

        case SDLK_LEFT:
          posperso.x -= 100;

          break;
        case SDLK_RIGHT:
          posperso.x += 100;

          break;
        case SDLK_UP:
          posperso.y -= 100;
          break;
        case SDLK_DOWN:
          posperso.y += 100;
          break;
        }
        break;
      }
    }

    SDL_BlitSurface(background, NULL, screen, NULL);
    SDL_BlitSurface(persotest, NULL, screen, &posperso);

    deplacer(&E);
    animerEnnemi(&E);
    afficherEnnemi(E, screen);
    deplacerIA(&E,posperso);
    if (collision(E.pos, posperso) == 1)
    {
      printf("1\n");
      SDL_BlitSurface(persotest1, NULL, screen, &posperso);
    }
    else
      printf("0\n");

    SDL_Flip(screen);
    //SDL_Delay(100);
  }
  TTF_Quit();
}
