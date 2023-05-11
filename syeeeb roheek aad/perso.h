#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <SDL/SDL_mixer.h>


typedef struct Imagee
{
	SDL_Rect posfromimg;  
	SDL_Rect posinscreen; 
	SDL_Surface *img;	  
} Imagee;

typedef struct Personne
{
	int nombredevie;
	int direction;
	int action;
	int saut;
	int deplacerhaut;
	int acceleration;
	int score;
	Imagee scoreimg;
	int bonus;
	int malus;
	int newscore;
	SDL_Surface *images[4][15]; 
	Imagee perso; 
    int i,j;
} Personne;
 




void animerPerso(Personne *p);
void MovePerso(Personne *p);
void saut(Personne *p);
void afficher_perso(Personne p, SDL_Surface *screen);
void afficher_newscore(int score, SDL_Surface *screen, Imagee c,int x) ;
void afficher(Imagee p, SDL_Surface *screen);
void initilisation_newscore(Imagee *c);
void initlise_matrice(Personne* p);
void initPerso(Personne *p);
