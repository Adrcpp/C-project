/*
** game_cycle.c for my_ftl in /home/adrien/PISCINE/DEVC/my_ftl/src
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Wed Nov  9 10:10:42 2016 CESARO Adrien
** Last update Sat Nov 12 10:12:10 2016 CESARO Adrien
*/
#include <unistd.h>
#include <stdlib.h>
#include "ftl.h"
#include "my_string.h"
#include "game_cycle.h"
#include "system_control.h"
#include "container.h"
#include "menu.h"
#include "rand.h"
#include "my_put_nbr.h"
#include "rules.h"
#include "ennemy_a.h"

int		game(t_ship *ship)
{
  int		eny;
  t_game	*game;
  int		res[2];
  int		prob;

  eny = 0;
  res[0] = 1;
  res[1] = 0;
  game = malloc(sizeof(*game));
  if (!init_game(game))
    return (-2);
  game->ship = ship;
  while (res[0] == 1 && res[1] != -10)
    {
      prob = randm();     
      if ((game->alive == 0) && prob < 30)
	eny = 1;
      if (eny == 1 && (game->alive == 0))
	create_ennemy(game);
      if (game->alive == 1)
	ennemy_attack(game);
      res[1] = menu(game);
      res[0] = condition(ship);
    }
  free_game(game);
  return (res[0]);
}

int		init_game(t_game *game)
{
  t_ennemy	*ennemy;

  game->ennemy = NULL;
  if (game == NULL)
    {
      my_putstr_color("red", "defaillance technique, votre\
vaisseau a explose \n");
      return (-2);
    }
  ennemy = malloc(sizeof(*ennemy));
  if (ennemy == NULL)
    return (-2);
  game->ennemy = ennemy;
  game->alive = 0;
  game->count_ennemy = 0;
  game->detect = 0;
  game->ship = NULL;
  return (1);
}

int		condition(t_ship *ship)
{
  if (ship->hull <= 0)
    return (-1);
  if (ship->drive->energy <= 0)
    return (-2);
  if (ship->nav->sector == 10)
    return 0; 
  return (1);
}

int		create_ennemy(t_game *game)
{
  int		index;

  index = 0;
  game->ennemy->hp = 20;
  game->ennemy->attack = 10;
  if (game->count_ennemy > 0)
    {
      while (game->count_ennemy > index)
	{
	  game->ennemy->hp += (game->ennemy->hp / 2);
	  game->ennemy->attack += (game->ennemy->attack / 2);
	  ++index;
	}
    }
  my_putstr_color("red", "[SYSTEM DETECT] : nouvel ennemi\
 detecté, il nous attaque !\n");
  game->alive = 1;
  prompt(game);
  return (1);
}

int		ennemy_attack(t_game *game)
{
  int		prob;

  prob = randm();
  if ((prob >= 0 && prob <= game->ship->nav->evade))
    {
      my_putstr_color("cyan", "L'attaque ennemis a été esquivé !\n");
      return (1);
    }
  game->ship->hull -= game->ennemy->attack;
  my_putstr_color("red"," L'ennemi vous a touché !\n Degats:");
  my_put_nbr(game->ennemy->attack);
  my_putstr("\n\n");
  prob = randm();
  if (prob >= 0 && prob <= 100)
    critical(game);
  return (0);
}
