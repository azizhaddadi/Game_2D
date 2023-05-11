#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"
void initPerso(Personne *p)

{
    p->nombredevie = 3;
    p->perso.posinscreen.x = 100;
    p->perso.posinscreen.y = 405;
    p->perso.posinscreen.w = 100;
    p->perso.posinscreen.h = 100;

    p->deplacerhaut=0;
    p->i=0;
    p->j=0;
    p->score=100;
    p->direction = 0;
    p->action=0;
}
void afficher(Imagee p, SDL_Surface *screen)
{
    SDL_BlitSurface(p.img, &p.posfromimg, screen, &p.posinscreen);
}
void afficher_perso(Personne p, SDL_Surface *screen)
{
    SDL_BlitSurface(p.images[p.i][p.j], NULL, screen, &p.perso.posinscreen);
}
void animerPerso(Personne *p)
{

    if(p->action==1)
    {
        p->i=p->direction;
        if ( p->j  > 13)  p->j = -1;
        p->j+=1;
    }

    else if (p->action==0)
    {
        p->acceleration=0;
        p->i=p->direction+2;

        if ( p->j > 13)  p->j = -1;
        p->j += 1;
    }
}
void MovePerso(Personne *p)
{

    if(p->action)
    {

        if(p->perso.posinscreen.x<1100&&p->direction==0)
        {
            p->perso.posinscreen.x+=(10+p->acceleration);
            if(p->acceleration<10) p->acceleration+=1;
        }
        else if(p->perso.posinscreen.x>0&&p->direction==1)
        {
            p->perso.posinscreen.x-=15;

        }


    }
}
void saut(Personne* p)
{
    if(p->saut&&p->perso.posinscreen.y==405)
    {
        p->deplacerhaut=1;
    }
    if(p->deplacerhaut==1)
    {
        p->perso.posinscreen.y-=10;
    }
    if(p->perso.posinscreen.y<320-(p->acceleration*6)&&p->deplacerhaut==1 ) 
    {
        p->deplacerhaut=0;
    }
    if(p->deplacerhaut==0&&p->perso.posinscreen.y<405)
    {
        p->perso.posinscreen.y+=20;
    }


}
void initilisation_newscore(Imagee *c)
{
    c->img = IMG_Load("images/new score.png");
    if (c->img == NULL)
    {
        fprintf(stderr, "error loding won img %s\n", TTF_GetError());
        return;
    }

    c->posinscreen.h = c->img->h;
    c->posinscreen.w = c->img->w;
    c->posinscreen.x = 0;
    c->posinscreen.y = 10;
}
void afficher_newscore(int score, SDL_Surface *screen, Imagee c,int x)
{


    char scoreStr[10];



    TTF_Font *font = TTF_OpenFont("ded.TTF", 28);
    if (font == NULL)
    {
        printf("Failed to load font: %s\n", TTF_GetError());
        exit(1);
    }
    SDL_Color color = { 0, 0, 0};

    SDL_snprintf(scoreStr, sizeof(scoreStr), "%d", score);

    SDL_Surface *scoresurface = TTF_RenderText_Solid(font, scoreStr, color);


    SDL_Rect destRect = { x, 57, 0, 0 };




    SDL_BlitSurface(c.img, NULL, screen, &c.posinscreen);
    SDL_BlitSurface(scoresurface, NULL, screen, &destRect);


    SDL_FreeSurface(scoresurface);
    TTF_CloseFont(font);

}

void initlise_matrice(Personne* p)
{

    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i <= 14; i++)
        {
            char filename[50];
            sprintf(filename, "images/personnage/sprite%d_%d.png", j, i);

            p->images[j][i] = IMG_Load(filename);
            if (p->images[j][i] == NULL)
            {
                printf("Error loading image: %s\n", SDL_GetError());
            }
        }
    }
}

