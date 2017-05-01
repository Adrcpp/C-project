/*
** ennemy_a.c for my_ftl in /home/adrien/PISCINE/DEVC/my_ftl/src
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Fri Nov 11 08:43:04 2016 CESARO Adrien
** Last update Fri Nov 11 14:40:57 2016 CESARO Adrien
*/
#include <unistd.h>
#include <stdlib.h>
#include "ftl.h"
#include "game_cycle.h"
#include "rand.h"
#include "ennemy_a.h"
#include "rules.h"
#include "my_string.h"
#include "my_put_nbr.h"
#include "container.h"

void		critical(t_game *game)
{
  int	prob;

  prob = randm();
  if ((prob <= 33) && is_ok("weapon", game->ship))
    {
      free(game->ship->weapon->system_state);
      game->ship->weapon->system_state = my_strdup("Offline");
      my_putstr_color("red", "[CRITICAL STIKE] armement H.S !!\n");
    }
  else if ((prob > 33 && prob <= 66) && is_ok("nav", game->ship))
    {
      free(game->ship->nav->system_state);
      game->ship->nav->system_state = my_strdup("Offline");;
      my_putstr_color("red", "[CRITICAL STIKE] detecteur H.S !!\n");
    }
  else if ((prob > 66) && is_ok("drive", game->ship))
    {
      free(game->ship->drive->system_state);
      game->ship->drive->system_state = my_strdup("Offline");
      my_putstr_color("red", "[CRITICAL STIKE] Moteur H.S !!\n");
    }
  game->ennemy->hp -= game->ship->weapon->damage;
}

void		prompt(t_game *game)
{
    my_putstr_color("blue", "|  HP :  ");
    my_put_nbr(game->ennemy->hp);
    my_putstr("\n");
    my_putstr_color("blue", "|  damage :  ");
    my_put_nbr(game->ennemy->attack);
    my_putstr("\n");
}

void		free_game(t_game *game)
{
  t_freight	*freight;

  freight = game->ship->container->first;
  while (game->ship->container->nb_elem > 0)
    {
      if (game->ship->container->last != game->ship->container->first)
	freight = freight->next;
      del_freight_from_container(game->ship, game->ship->container->first);
    }
  free(game->ship->container);
  free(game->ship->nav->system_state);
  free(game->ship->nav);
  free(game->ship->drive->system_state);
  free(game->ship->drive);
  free(game->ship->weapon->system_state);
  free(game->ship->weapon);
  free(game->ship);
  free(game->ennemy);
  free(game);
}


void	ennemy_down(t_game *game)
{
  int	prob;

  prob = randm();
  my_putstr_color("green","Ennemis detruit !!\n PV :");
  my_put_nbr(game->ship->hull);
  my_putstr("\n");
  game->alive = -1;
  game->count_ennemy += 1;
  if (prob >= 0 && prob <= 50)
    {
      my_putstr_color("red","-1 d'energie \n");
      game->ship->drive->energy -= 1;
    }
}
