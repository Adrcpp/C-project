/*
** rules.c for my_ftl in /home/adrien/PISCINE/DEVC/my_ftl/src
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Wed Nov  9 14:48:40 2016 CESARO Adrien
** Last update Sat Nov 12 10:15:59 2016 CESARO Adrien
*/
#include <unistd.h>
#include <stdlib.h>
#include "my_string.h"
#include "ftl.h"
#include "game_cycle.h"
#include "rules.h"
#include "system_repair.h"
#include "system_control.h"

static const t_ok tab[] =
  {
    {"nav", &is_ok_nav},
    {"weapon", &is_ok_weapon},
    {"drive", &is_ok_nav},
    {NULL, NULL}
  };

int	is_ok_nav(t_ship *ship)
{
  if (my_strcmp(ship->drive->system_state, "Online") == 0)
    return (1);
  return (0);
}

int	is_ok_drive(t_ship *ship)
{
  if (my_strcmp(ship->nav->system_state, "Online") == 0)
    return (1);
  return (0);
}

int	is_ok_weapon(t_ship *ship)
{
  if (my_strcmp(ship->weapon->system_state, "Online") == 0)
    return (1);
  return (0);
}

int	is_ok(char *str, t_ship *ship)
{
  int	index;

  index = 0;
  while (tab[index].choice != NULL)
    {
      if (my_strcmp(tab[index].choice, str) == 0)
	return (tab[index].ptrf(ship));
      ++index;
    }
  return (0);
}

int	test_choice(char *str, t_game *game)
{
  int	res;

  res = 0;
  if (my_strcmp("repair", str) == 0)
    res = system_repair(game->ship);
  else if (my_strcmp("map", str) == 0)
    res = map(game->ship);
  else if (my_strcmp("exit", str) == 0)
    res = (-10);
  else if (my_strcmp("system", str) == 0)
    res = (system_control(game->ship));
  else if (my_strcmp("stat", str) == 0 )
    res = (stat(game->ship));
  else
    my_putstr_color("red", "[SYSTEM FAILURE] : commande inconnue\n");
  return (res);
}
