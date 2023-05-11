#include "header.h"

#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include<SDL/SDL_image.h>

#include<time.h>
#include<string.h>





//Print the designated string at the specified coordinates
void printText(char *c, int x, int y, SDL_Surface * screen , TTF_Font *font){


SDL_Color fColor;
        fColor.r = 255;
        fColor.g = 255;
        fColor.b = 255;

SDL_Surface *fontSurface;
        fontSurface = TTF_RenderText_Solid(font,c , fColor );
	SDL_Rect fontRect;

        fontRect.x = x;
        fontRect.y = y;
        SDL_BlitSurface(fontSurface, NULL, screen, &fontRect);
        SDL_Flip(screen);
}

int rr(int lower, int upper)
{


  printf ("Random Number: %d\n", rand() %100);
 
    return (rand() %
        (upper - lower + 1)) + lower;
}
 
int calc_deux (int x1, int x2, int op)
{
if (op == 0)
	return x1+x2;
if (op == 1)
	return x1-x2;

else return x1*x2;
}
int calc_valeur(int x1, int x2, int x3, int op1, int op2)
{
if (op1 == 2 && op2 != 2)
return calc_deux(calc_deux(x1,x2,op1),x3, op2);
else if (op2 == 2 && op1 != 2)
return calc_deux(x1,calc_deux(x2,x3,op2),op1);	
else {
 int total =  x1;
	if (op1 == 0 ) total+=x2;
	else if (op1  == 1) total -=x2;
	else if (op1 == 2)total*=x2;
	else total/=x2;

	if (op2 == 0 ) total+=x3;
	else if (op2  == 1) total -=x3;
	else if (op2 == 2)total*=x3;
	else total/=x3;
return total;
}

//else return calc_deux(x1, calc_deux(x2,x3, op2), op1);
}

void affich_enigme1(enigme e,char *nomficher)
{
TTF_Init();

char str[20];

srand ( time(NULL) );
        TTF_Font *font = TTF_OpenFont("Montserrat-Regular.ttf", 30);


int i1 = rr(1,18);


int l1 = rr(1,18);


int k1= rr(1,18);
while (l1 == i1)
	l1 = rr(1,18);
while (k1 == i1 || k1 == l1)
	k1 = rr(1,18);
int kop1 = rr(0,2);
int k2 = rr(1,18);
int kop2 = rr(0,2);
int k3 = rr(1,18);


 SDL_Surface *fruits[19];
 SDL_Surface *operands[4];

operands[0] = IMG_Load("terminer/plus.png");
operands[1] = IMG_Load("terminer/moin.png");
operands[2] = IMG_Load("terminer/fois.png"); 
operands[3] = IMG_Load("terminer/egal.png");


fruits[0] = IMG_Load("terminer/2.png");
fruits[1] = IMG_Load("terminer/4.png");
fruits[2] = IMG_Load("terminer/6.png"); 
fruits[3] = IMG_Load("terminer/8.png");
fruits[4] = IMG_Load("terminer/10.png");
fruits[5] = IMG_Load("terminer/12.png"); 
fruits[6] = IMG_Load("terminer/14.png");

fruits[7] = IMG_Load("terminer/16.png");
fruits[8] = IMG_Load("terminer/20.png");
fruits[9] = IMG_Load("terminer/24.png"); 
fruits[10] = IMG_Load("terminer/28.png");
fruits[11] = IMG_Load("terminer/30.png");
fruits[12] = IMG_Load("terminer/32.png"); 
fruits[13] = IMG_Load("terminer/40.png");

fruits[14] = IMG_Load("terminer/45.png");
fruits[15] = IMG_Load("terminer/50.png");
fruits[16] = IMG_Load("terminer/55.png"); 
fruits[17] = IMG_Load("terminer/60.png");
fruits[18] = IMG_Load("terminer/65.png");

SDL_Surface *screen=NULL;
 
int x1 = 3;
  
int isMouse = 1;


SDL_Event event;

 if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    printf("unable to set Initialize SDL : %s/n", SDL_GetError());
    
  }
	//800 900
  screen = SDL_SetVideoMode(1280, 853, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

  if (screen == NULL)
  {
    printf("unable to set  video mode : %s/n", SDL_GetError());
    
  } 


e.keyboard = IMG_Load("clavier.png");
e.posbackground.x = 0;
  e.posbackground.y = 0;
SDL_BlitSurface(e.keyboard, NULL, screen, &e.posbackground);
SDL_Flip(screen);
int done_keyboard = 1; 


while (SDL_WaitEvent(&event)&& (done_keyboard==1))
	
  {

switch (event.type)
    {
    case SDL_QUIT:
    {
    done_keyboard=0;
    SDL_Quit();
    break;
     }
						
    case SDL_MOUSEBUTTONDOWN:
    {
if((event.motion.x>220)&&(event.motion.x<370)&&(event.motion.y>130)&&(event.motion.y<270))
    	{
	isMouse = 1;
    done_keyboard=0;

	}
if((event.motion.x>860)&&(event.motion.x<1200)&&(event.motion.y>130)&&(event.motion.y<270))
    	{
	isMouse = 0;
done_keyboard=0;
	}
break;}
}


}




  e.b = IMG_Load("b.jpg"); 
  printf("program here \n");
  e.imag[1] = IMG_Load("1.png");

  e.imag[2] = IMG_Load("100.png");
  e.imag[3] = IMG_Load("50.png");
  e.imag[4] = IMG_Load("30.png");
  e.imag[5] = IMG_Load("0.png");
  //e.imag[0] = IMG_Load("0.png");


e.posbackground.x = 0;
  e.posbackground.y = 0;
  e.posscore.x = 0;
  e.posscore.y = 0;
 
  e.posimage.x = 195;
  e.posimage.y =300;

SDL_BlitSurface(e.b, NULL, screen, &e.posbackground);
SDL_Flip(screen);
SDL_BlitSurface(e.imag[1], NULL, screen, &e.posimage);
SDL_Flip(screen);


// fonction 1
e.posimage.x = 200;
  e.posimage.y =330;

SDL_BlitSurface(fruits[i1], NULL, screen, &e.posimage);
e.posimage.x =250;
SDL_BlitSurface(operands[0], NULL, screen, &e.posimage);
e.posimage.x =300;
SDL_BlitSurface(fruits[i1], NULL, screen, &e.posimage);
e.posimage.x =350;
SDL_BlitSurface(operands[0], NULL, screen, &e.posimage);
e.posimage.x =400;
SDL_BlitSurface(fruits[i1], NULL, screen, &e.posimage);

e.posimage.x =450;
SDL_BlitSurface(operands[3], NULL, screen, &e.posimage);

   int total1 = calc_valeur(i1,i1,i1,0,0);
sprintf(str, "%d", total1);
    printText(str, 480,330, screen,font);
SDL_Flip(screen);



// fonction 2


e.posimage.x = 200;
  e.posimage.y =370;

SDL_BlitSurface(fruits[i1], NULL, screen, &e.posimage);
e.posimage.x =250;
SDL_BlitSurface(operands[0], NULL, screen, &e.posimage);
e.posimage.x =300;
SDL_BlitSurface(fruits[l1], NULL, screen, &e.posimage);
e.posimage.x =350;
SDL_BlitSurface(operands[0], NULL, screen, &e.posimage);
e.posimage.x =400;
SDL_BlitSurface(fruits[l1], NULL, screen, &e.posimage);

e.posimage.x =450;
SDL_BlitSurface(operands[3], NULL, screen, &e.posimage);

   int total2 = calc_valeur(i1,l1,l1,0,0);
sprintf(str, "%d", total2);

    printText(str, 480,370, screen,font);



// fonction 3


e.posimage.x = 200;
  e.posimage.y =410;

//SDL_BlitSurface(fruits[k1], NULL, screen, &e.posimage);

//e.posimage.x =250;
//SDL_BlitSurface(operands[kop1], NULL, screen, &e.posimage);
e.posimage.x =300;
SDL_BlitSurface(fruits[k1], NULL, screen, &e.posimage);
e.posimage.x =350;
SDL_BlitSurface(operands[kop2], NULL, screen, &e.posimage);
e.posimage.x =400;
SDL_BlitSurface(fruits[l1], NULL, screen, &e.posimage);

e.posimage.x =450;
SDL_BlitSurface(operands[3], NULL, screen, &e.posimage);

   int total3 = calc_deux(k1,l1,kop2);
printf("random values %d %d %d \n",i1,l1,k1);
sprintf(str, "%d", total3);
    printText(str, 480,410, screen,font);
SDL_Flip(screen);

// question

e.posimage.x = 200;
  e.posimage.y =450;

SDL_BlitSurface(fruits[i1], NULL, screen, &e.posimage);
e.posimage.x =250;
SDL_BlitSurface(operands[kop1], NULL, screen, &e.posimage);
e.posimage.x =300;
SDL_BlitSurface(fruits[l1], NULL, screen, &e.posimage);
e.posimage.x =350;
SDL_BlitSurface(operands[kop2], NULL, screen, &e.posimage);
e.posimage.x =400;
SDL_BlitSurface(fruits[k1], NULL, screen, &e.posimage);

e.posimage.x =450;
SDL_BlitSurface(operands[3], NULL, screen, &e.posimage);

   int total4 = calc_valeur(i1,l1,k1,kop1,kop2);

sprintf(str, "%d", total3);
    printText("?", 480,450, screen,font);
srand ( time(NULL) );
int correctPosition =rr(0,3);
srand ( time(NULL) );
int randomAnswer1 = rr(total4-20, total4+20);
while (randomAnswer1 == total4)
	randomAnswer1 = rr(total4-20, total4+20);

int randomAnswer2 = rr(total4-30, total4+30);
while (randomAnswer2 == total4 || randomAnswer2 == randomAnswer1)
	randomAnswer2 = rr(total4-20, total4+20);
int randomAnswer3 = rr(total4-10, total4+10);
while (randomAnswer3 == total4 || randomAnswer3 == randomAnswer2 || randomAnswer3 == randomAnswer1)
	randomAnswer3 = rr(total4-20, total4+20);

int randomAnswer4 = rr(total4-10, total4+10);
while (randomAnswer4 == total4 || randomAnswer4 == randomAnswer3 || randomAnswer4 == randomAnswer2 || randomAnswer4 == randomAnswer1)
	randomAnswer4 = rr(total4-20, total4+20);
if (correctPosition == 0)
{
sprintf(str, "%d", total4);

}
else 
{
sprintf(str, "%d", randomAnswer1);
}
    printText(str, 480,520, screen,font);
if (correctPosition == 1)
{
sprintf(str, "%d", total4);
}
else 
{
sprintf(str, "%d", randomAnswer2);
}
    printText(str, 480,590, screen,font);
if (correctPosition == 2)
{
sprintf(str, "%d", total4);
}

else 
{
sprintf(str, "%d", randomAnswer3);
}
    printText(str, 480,670, screen,font);

if (correctPosition == 3)
{
sprintf(str, "%d", total4);
}

else 
{
sprintf(str, "%d", randomAnswer4);
}
    printText(str, 480,750, screen,font);

printf("RANDOM ANSWERS %d %d %d \n ", randomAnswer1, randomAnswer2, randomAnswer3);
sprintf(str, "%d", total2);
printf("CORRENT ANSER : %d \n",total4);
sprintf(str, "%d", total4);


sprintf(str, "%d", total1);

SDL_Flip(screen);
SDL_Flip(screen);

  printf("1.png here \n");
    
   int done = 1; 


FILE* correct;
correct =  fopen("correct", "w+");
  printf("1.png here \n");
if (correct == NULL)
    {
       printf("le fichier n'exister pas");
       
    }

        SDL_BlitSurface(e.answer, NULL, screen, &e.posanswer);
        SDL_Flip(screen);
if (correct !=NULL)
{
char juste[5];

fscanf(correct,"%s",juste);


do{


while (SDL_WaitEvent(&event)&& (done==1))
	
  {



switch (event.type)
    {
    printText("test", 500,600, screen, font);
    case SDL_QUIT:
    {
    done=0;
    SDL_Quit();
    break;
    } 
						
    case SDL_MOUSEBUTTONUP:
    {
	if (isMouse == 1)
{
    	if((event.motion.x>206)&&(event.motion.x<546)&&(event.motion.y>520)&&(event.motion.y<569))
    	{
    		
    	  
    	if (correctPosition == 0){
	
    	   
	e.answer = IMG_Load("RightAnswer.png");
       e.posanswer.x = 190;
        e.posanswer.y = 0;
    SDL_BlitSurface(e.answer, NULL, screen, &e.posanswer);
        SDL_Flip(screen);
    animer(screen,&e);
}
else {//e.answer1 = IMG_Load("wrong answer ques1.png");
   	e.answer = IMG_Load("WrongAnswer.png");
x1 = x1 - 1;}
        e.posanswer.x = 190;
        e.posanswer.y = 0;
        SDL_BlitSurface(e.answer, NULL, screen, &e.posanswer);
        SDL_Flip(screen);
        SDL_Flip(screen);
	
	
    	}
    	
    	if((event.motion.x>206)&&(event.motion.x<546)&&(event.motion.y>600)&&(event.motion.y<650))
    	{
    	  
    	if (correctPosition == 1){
	e.answer = IMG_Load("RightAnswer.png");
       e.posanswer.x = 190;
        e.posanswer.y = 0;
    SDL_BlitSurface(e.answer, NULL, screen, &e.posanswer);
        SDL_Flip(screen);
       animer(screen,&e);
}
else {
   	e.answer = IMG_Load("WrongAnswer.png");
	 x1 = x1 - 1;}
        e.posanswer.x = 190;
        e.posanswer.y = 0;
        SDL_BlitSurface(e.answer, NULL, screen, &e.posanswer);
        SDL_Flip(screen);
        SDL_Flip(screen);

    	}
    	
    	if((event.motion.x>206)&&(event.motion.x<546)&&(event.motion.y>680)&&(event.motion.y<730))
    	{
    	if (correctPosition == 2){
    	e.answer = IMG_Load("RightAnswer.png");
       e.posanswer.x = 190;
        e.posanswer.y = 0;
    SDL_BlitSurface(e.answer, NULL, screen, &e.posanswer);
        SDL_Flip(screen);
        animer(screen,&e);
}
else {
   	e.answer = IMG_Load("WrongAnswer.png");
        x1 = x1 - 1;}

        e.posanswer.x = 190;
        e.posanswer.y = 0;
        SDL_BlitSurface(e.answer, NULL, screen, &e.posanswer);
        SDL_Flip(screen);

        SDL_Flip(screen);

    	}
    	if((event.motion.x>206)&&(event.motion.x<546)&&(event.motion.y>760)&&(event.motion.y<810))
    	{
	if (correctPosition == 3){
    	e.answer = IMG_Load("RightAnswer.png");
       e.posanswer.x = 190;
        e.posanswer.y = 0;
    SDL_BlitSurface(e.answer, NULL, screen, &e.posanswer);
        SDL_Flip(screen);
        animer(screen,&e);
}
else {
   	e.answer = IMG_Load("WrongAnswer.png");
        x1 = x1 - 1;}

        e.posanswer.x = 190;
        e.posanswer.y = 0;
        SDL_BlitSurface(e.answer, NULL, screen, &e.posanswer);

      

     
	
    	}
    	
    }
}
    case SDL_KEYDOWN:
    {
	if (isMouse == 0)
{

      if ((event.key.keysym.sym == SDLK_a))
      {
    	  
    	if (correctPosition == 0){
	e.answer = IMG_Load("RightAnswer.png");
      e.posanswer.x = 190;
        e.posanswer.y = 0;
    SDL_BlitSurface(e.answer, NULL, screen, &e.posanswer);
        SDL_Flip(screen);
    animer(screen,&e);
}
else {e.answer1 = IMG_Load("wrong answer ques1.png");
   	e.answer = IMG_Load("WrongAnswer.png");
x1 = x1 - 1;}
        e.posanswer.x = 190;
        e.posanswer.y = 0;
        SDL_BlitSurface(e.answer, NULL, screen, &e.posanswer);
        SDL_Flip(screen);
        SDL_Flip(screen);
	
	

     
        
       
      }

      if ((event.key.keysym.sym == SDLK_b))
      {

       if (correctPosition == 1){
	e.answer = IMG_Load("RightAnswer.png");
      e.posanswer.x = 190;
        e.posanswer.y = 0;
    SDL_BlitSurface(e.answer, NULL, screen, &e.posanswer);
        SDL_Flip(screen);
        animer(screen,&e);
}
else {
   	e.answer = IMG_Load("WrongAnswer.png");
        x1 = x1 - 1;}

        e.posanswer.x = 190;
        e.posanswer.y = 0;
        SDL_BlitSurface(e.answer, NULL, screen, &e.posanswer);
        SDL_Flip(screen);
        SDL_Flip(screen);
	
        
        
      }

      if ((event.key.keysym.sym == SDLK_c))
      {
if (correctPosition == 2){
      e.posanswer.x = 190;
        e.posanswer.y = 0;
    	e.answer = IMG_Load("RightAnswer.png");
    SDL_BlitSurface(e.answer, NULL, screen, &e.posanswer);
        SDL_Flip(screen);
        animer(screen,&e);
}
else {
  	e.answer = IMG_Load("WrongAnswer.png");
        x1 = x1 - 1;}

        e.posanswer.x = 190;
        e.posanswer.y = 0;
        SDL_BlitSurface(e.answer, NULL, screen, &e.posanswer);
        SDL_Flip(screen);
         SDL_Flip(screen);
	
        
      }
      if (event.key.keysym.sym == SDLK_d)
      {
	if (correctPosition != 3){
  	e.answer = IMG_Load("WrongAnswer.png");
        x1 = x1 - 1;

        e.posanswer.x = 190;
        e.posanswer.y = 0;
        SDL_BlitSurface(e.answer, NULL, screen, &e.posanswer);
        SDL_Flip(screen);
         SDL_Flip(screen);
	  } 
	  
       else{
         e.posanswer.x = 190;
        e.posanswer.y = 0;
    	e.answer = IMG_Load("RightAnswer.png");
    SDL_BlitSurface(e.answer, NULL, screen, &e.posanswer);
        SDL_Flip(screen);
        animer(screen,&e);
	  }
	
	
      }
}
      if (event.key.keysym.sym == SDLK_ESCAPE)
      {
        done = 0;
	SDL_Quit();

      }
      break;
    }
    }

    if (x1 == 3)
    {
      SDL_BlitSurface(e.imag[2], NULL, screen, &e.posscore);
      SDL_Flip(screen);
    }
    if (x1 == 2)
    {
      SDL_BlitSurface(e.imag[3], NULL, screen, &e.posscore);
      SDL_Flip(screen);
    }
    if (x1 == 1)
    {
      SDL_BlitSurface(e.imag[4], NULL, screen, &e.posscore);
      SDL_Flip(screen);
    }
    if (x1 <= 0)
    {

    	e.posanswer.x = 0;
        e.posanswer.y = 190;
      SDL_BlitSurface(e.imag[5], NULL, screen, &e.posscore);

      SDL_Flip(screen);
  e.posanswer.x = 190;
        e.posanswer.y = 0;
e.answer = IMG_Load("R.png");
        SDL_BlitSurface(e.answer, NULL, screen, &e.posanswer);
        SDL_Flip(screen);
char correctValue[40];
sprintf(correctValue, "%d", total4);
 TTF_Font *correctFont = TTF_OpenFont("Montserrat-Regular.ttf", 80);
printText(correctValue, 320,150, screen,correctFont);


SDL_Delay(3000);
	done=0;
	SDL_Quit();
    }
  }
}  while (done==1);}

fclose(correct);

    
  
  SDL_FreeSurface(e.imag[1]);
	SDL_FreeSurface(e.imag[2]);
	SDL_FreeSurface(e.imag[3]);
	SDL_FreeSurface(e.imag[4]);
	SDL_FreeSurface(e.imag[5]);
	SDL_FreeSurface(e.imag[0]);
	SDL_FreeSurface(e.keyboard);
  SDL_FreeSurface(e.b);
SDL_FreeSurface(e.answer);

  


}






void animer(SDL_Surface *screen,enigme *e)
{
int i;

e->posanim.x=140;
e->posanim.y=200;  
SDL_Event event;
int done=1;

  

e->anim[0] = IMG_Load("up1.png");
e->anim[1] = IMG_Load("up2.png");
e->anim[2] = IMG_Load("up3.png"); 
e->anim[3] = IMG_Load("up4.png");
e->anim[4] = IMG_Load("up5.png");
e->anim[5] = IMG_Load("up6.png"); 
e->anim[6] = IMG_Load("up7.png");
e->anim[7] = IMG_Load("up8.png");
e->anim[8] = IMG_Load("up9.png"); 
e->anim[9] = IMG_Load("up10.png");
e->anim[10] = IMG_Load("up11.png");
e->anim[11] = IMG_Load("up12.png"); 
e->anim[12] = IMG_Load("up13.png");
e->anim[13] = IMG_Load("up14.png");
e->anim[14] = IMG_Load("up15.png"); 
e->anim[15] = IMG_Load("up16.png");
e->anim[16] = IMG_Load("up17.png");
e->anim[17] = IMG_Load("up18.png"); 
e->anim[18] = IMG_Load("up19.png");
e->anim[19] = IMG_Load("up20.png");
for(i=0;i<20;i++){  

	SDL_BlitSurface (e->anim[i],NULL,screen,&(e->posanim));
	SDL_Flip(screen);
	SDL_Delay(300);

if(i==20)
{
SDL_Delay(1000);
SDL_Quit();
i=0;
}

}
	SDL_FreeSurface(e->anim[0]);
	SDL_FreeSurface(e->anim[1]);
	SDL_FreeSurface(e->anim[2]);
	SDL_FreeSurface(e->anim[3]);
	SDL_FreeSurface(e->anim[4]);
	SDL_FreeSurface(e->anim[5]);
	SDL_FreeSurface(e->anim[6]);
	SDL_FreeSurface(e->anim[7]);
	SDL_FreeSurface(e->anim[8]);
	SDL_FreeSurface(e->anim[9]);
        SDL_FreeSurface(e->anim[10]);
	SDL_FreeSurface(e->anim[11]);
	SDL_FreeSurface(e->anim[12]);
	SDL_FreeSurface(e->anim[13]);
	SDL_FreeSurface(e->anim[14]);
        SDL_FreeSurface(e->anim[15]);
	SDL_FreeSurface(e->anim[16]);
	SDL_FreeSurface(e->anim[17]);
	SDL_FreeSurface(e->anim[18]);
	SDL_FreeSurface(e->anim[19]);
        SDL_FreeSurface(e->anim[20]);

SDL_Delay(1500);

	SDL_Quit();


}
void e1()
{
 
SDL_Surface *screen=NULL;
 
enigme e;


 

affich_enigme1(e, NULL);
}
