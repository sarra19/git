#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

//define
#define LARGEUR 1017
#define HAUTEUR 508
#define bpp 32

//variables
SDL_Surface *screen=NULL;
SDL_Event event={0};
SDL_Surface* paysage=NULL;
SDL_Rect paysage_rect={0,0,0,0};//x,y,w,h



//******
int main()
{	
	Uint32 color=0;
	int running=1;

	int now=0;
	int ex=0;
	int periodeFps=33; //33ms soit fps=30 img/s
	int dt=0;
	float delta_s=0;
	//init
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
/*
//bpp?
const SDL_VideoInfo* pinfo=SDL_GetVideoInfo();
int ecran_w=pinfo->current_w;
int ecran_h=pinfo->current_h; 
int bpp=pinfo->vfmt->BitsPerPixel;

printf("ecran_w= %d, ecran_h = %d ,bpp=%d \n",ecran_w,ecran_h,bpp);*/
//


	screen = SDL_SetVideoMode(LARGEUR,HAUTEUR,32,SDL_HWSURFACE);
	SDL_WM_SetCaption("PANDEMIC",NULL);

	//color
	color=SDL_MapRGB(screen->format,0,0,0);//rgb

	//paysage
	paysage=IMG_Load("./assets/images/backcoro.png");
	


	SDL_Surface* tmp=NULL;
	
	tmp=IMG_Load("./assets/images/backcoro.png");
	paysage=SDL_DisplayFormat(tmp);
//image adapter ou fenetre ou non?
//SDL_DisplayFormatAlpha(tmp)::: pour faire le transparence

SDL_FreeSurface(tmp);


//rect

	SDL_GetClipRect(paysage,& paysage_rect);
	paysage_rect.x=0;
	paysage_rect.y=0;
	printf("x=%d,y=%d,w=%d,h=%d \n",paysage_rect.x,paysage_rect.y,paysage_rect.w,paysage_rect.h);



	//boucle
	while(running)
{
	now=SDL_GetTicks();
	dt=now-ex;
	if(dt > periodeFps)
  {
	//printf("now = %d \n",now);
	//printf("dt = %d \n",dt);
	delta_s=dt/1000.0;
	printf("delta = %.4f \n",delta_s);


	
	
	SDL_PollEvent(& event);
	switch(event.type)
	{
	case SDL_QUIT:
	running=0;
	break;

	//
	case SDL_KEYDOWN:
	if (event.key.keysym.sym==SDLK_SPACE)
	{
	running=0;
	
	}
	break;
	
	//
	case SDL_KEYUP:
	break;

	default:
	break;
	}



	//traitement evt 
	//color
	SDL_FillRect(screen,NULL,color);
	SDL_BlitSurface(paysage,NULL,screen,& paysage_rect);
	

	//flip
	SDL_Flip(screen);
	ex = now;
  }
	else
	{
	SDL_Delay(periodeFps - dt);
	}
}

//
SDL_FreeSurface(paysage);
//SDL_Delay(5000);

//quit
SDL_Quit();//sup screen
return EXIT_SUCCESS;


}
