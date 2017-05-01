#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "rand.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

void		move(SDL_Surface *bg, SDL_Rect pos_ship,
		     SDL_Surface *ship, SDL_Rect pos_bg, SDL_Surface *screen);
SDL_Surface	*load_image(char *str);

void		missile(SDL_Surface *bullet, SDL_Rect pos_bullet,
			SDL_Rect pos_ship);
  
int		main()
{
  SDL_Surface	*screen;
  SDL_Surface	*bg;
  SDL_Surface	*ship;
  SDL_Rect	pos_bg;
  SDL_Rect	pos_ship;

  pos_bg.x = 0;
  pos_bg.y = 0;
  pos_ship.x = 0;
  pos_ship.y = 300;
  screen = NULL;
  bg = NULL;
  ship = NULL;
  
  SDL_Init(SDL_INIT_VIDEO);
  screen = SDL_SetVideoMode(1200, 800, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("FTL", NULL);

  bg = load_image("back.png");
  ship = load_image("ship.png");
  
  SDL_BlitSurface(bg, NULL, screen, &pos_bg);
  SDL_BlitSurface(ship, NULL, screen, &pos_ship);

  SDL_Flip(screen);

  move(bg, pos_ship, ship, pos_bg, screen);
  SDL_FreeSurface(bg);
  SDL_FreeSurface(ship);
  
  SDL_Quit();
  return (0);
}

void		move(SDL_Surface *bg, SDL_Rect pos_ship,
		     SDL_Surface *ship, SDL_Rect pos_bg ,
		     SDL_Surface *screen)
{
  SDL_Event	event;
  int		bool;
  int		bool2;
  SDL_Surface   *text = NULL;
  SDL_Surface   *text2 = NULL;
  SDL_Surface	*bullet;
  SDL_Surface	*bullet2;
  SDL_Surface	*ennemy;
  
  SDL_Rect	pos_bullet;
  SDL_Rect	pos_e;
  SDL_Rect	pos_be;
  SDL_Rect	hp;
  SDL_Rect	hpe;
  int		move;
  int		i;
  int		e_on;
  int		continuer = 1;
  
  int		hp_ship;
  int		hp_e;

  char txhp[20] = "";
  char txhpe[20] = "";

  TTF_Font	*police = NULL;
  SDL_Color     color = {255, 255, 255};
  
  hp.x = 50;
  hp.y = 10;

  hpe.x = 800;
  hpe.y = 10;

  hp_ship = 10;
  hp_e = 500;

  TTF_Init();
  police = TTF_OpenFont("ASMAN.TTF", 50); 
  
  move = 0;
  bool = 0;
  bool2 = 0;
  e_on = 0;
  SDL_EnableKeyRepeat(10, 10);

  pos_e.x = 800;
  pos_e.y = 300;

  bullet = load_image("mine-bullet.png");
  bullet2 = load_image("mine-bullet.png");
  ennemy = load_image("ennemy.png");
  while (continuer)
    {
      SDL_PollEvent(&event);
      switch(event.type)
        {
	case SDL_QUIT:
	  continuer = 0;
	  break;
	case SDL_KEYUP:
	  move = 0;
	  switch(event.key.keysym.sym)
	    {
	    case SDLK_SPACE:
	      if(bool == 0)
		{
		  pos_bullet.x = pos_ship.x + pos_ship.w ;
		  pos_bullet.y = pos_ship.y + (pos_ship.h / 2) ;
		}
		bool = 1;
	      break;
	    }
	case SDL_KEYDOWN:
	  move = 0;
	  switch(event.key.keysym.sym)
	    {
	    case SDLK_ESCAPE:
	      continuer = 0;
	      break;
	    case SDLK_UP:
	      if (move == 0)
		pos_ship.y -= 3;
	      break;
	    case SDLK_DOWN:
	      if (move == 0)
		pos_ship.y += 3;
	      break;  
	    case SDLK_RIGHT:
	      if (move == 0)
		pos_ship.x += 3;
	      break;
	    case SDLK_LEFT:
	      if (move == 0)
		pos_ship.x -= 3;
	      break;
	    }
	  break;
        }
      
      SDL_BlitSurface(bg, NULL, screen, &pos_bg);
      SDL_BlitSurface(ship, NULL, screen, &pos_ship);
      
      if (collision(pos_bullet, pos_e ) == 1)
	{
	  bool = 0;
	  hp_e -= 1;
	  pos_bullet.x = -100;
	}


      if (collision(pos_be, pos_ship) == 1)
	{
	  bool2 = 0;
	  hp_ship -= 1;
	  pos_bullet.x = -100;
	}


      if (hp_e < 0 || hp_ship < 0)
	continuer = 0 ;

      
      if (bool == 1)
	{
	  pos_bullet.x += 10;
	  SDL_BlitSurface(bullet, NULL, screen, &pos_bullet);
	  if ( pos_bullet.x >= 750)
	    bool = 0;
	}

      
      if (e_on == 0)
	{
	  if (random_custom(2) == 1 && pos_e.y < (pos_bg.h - 200))
	    pos_e.y += random_custom(2);
	  else if (10 <= pos_e.y) 
	    {
	      pos_e.y -= random_custom(2);
	    }
	  if (bool2 == 0)
	    {
	      bool2 = 1;
	      pos_be.x = pos_e.x;
	      pos_be.y = pos_e.y + 20;
	    }
	  if (bool2 == 1)
	    {
	      pos_be.x -= 5;
	      SDL_BlitSurface(bullet2, NULL, screen, &pos_be);
	      if (pos_be.x <= 10)
		bool2 = 0;
	    }
	}

      SDL_BlitSurface(ennemy, NULL, screen, &pos_e);
      sprintf(txhpe, "HP Ennemy : %d", hp_e);
      sprintf(txhp, "HP Ship : %d", hp_ship);
      SDL_FreeSurface(text);
      SDL_FreeSurface(text2);
      text = TTF_RenderText_Solid(police, txhpe , color);
      text2 = TTF_RenderText_Solid(police, txhp, color);
      
      SDL_BlitSurface(text, NULL, screen, &hp);
      SDL_BlitSurface(text2, NULL, screen, &hpe);
      SDL_Flip(screen);
    }
}

SDL_Surface	*load_image(char *str)	
{
  SDL_Surface*	optimizedImage = NULL;
  SDL_Surface*	loadedImage = IMG_Load(str);
  
  if (loadedImage != NULL)
    {
      optimizedImage = SDL_DisplayFormatAlpha(loadedImage);
      SDL_FreeSurface(loadedImage);
    }
  return optimizedImage;
}

int		collision(SDL_Rect bullet, SDL_Rect ennemy)
{
  int leftA, leftB;
  int topA, topB;
  int rightA, rightB;
  int bottomA, bottomB;

  leftA = bullet.x;
  topA = bullet.y;
  rightA = bullet.x + bullet.w;
  bottomA = bullet.y + bullet.h;
  
  leftB = ennemy.x;
  topB = ennemy.y;
  rightB = ennemy.x + ennemy.w;
  bottomB = ennemy.y + ennemy.h;
  
  if( bottomA <= topB )
    return 0;
  if( topA >= bottomB )
    return 0;
  if( rightA <= leftB )
    return 0;
  if( leftA >= rightB )
    return 0;
  return 1;
}
