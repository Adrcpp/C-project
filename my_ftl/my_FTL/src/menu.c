/*
** menu.c for my_ftl in /home/adrien/PISCINE/DEVC/my_ftl/src
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Wed Nov  9 09:25:58 2016 CESARO Adrien
** Last update Sat Nov 12 11:03:52 2016 CESARO Adrien
*/
#include <unistd.h>
#include <stdlib.h>
#include "ftl.h"
#include "game_cycle.h"
#include "system_repair.h"
#include "menu.h"
#include "my_string.h"
#include "rules.h"
#include "my_put_nbr.h"
#include "ennemy_a.h"
#include "container_zone.h"
#include "rand.h"
#include "container.h"
#include "system_control.h"


static const t_menu tab[] = {
  {"attack", &attack},
  {"detect", &detect},
  {"jump", &jump},
  {"getbonus", &getbonus},
  {NULL, NULL}};

int	menu(t_game *game)
{
  char	*str;
  int	index;
  int	res;

  index = 0;
  my_putstr_color("cyan", "1 - attack\t\t2 - detect\n\
3 - jump\t\t4 - getbonus\n5 - repair\t\t6 - map\n7 - stat\t\t8 - system\
\n9 - exit\n\n\nAction ~ $>>");
  str = readline();
  while (tab[index].choice != NULL)
    {
      if (my_strcmp(tab[index].choice, str) == 0)
	{
	  free (str);
	  my_putstr_color("clear","");
	  return  res = tab[index].ptrf(game);
	}
      ++index;
    }
  my_putstr_color("clear","");
  res = test_choice(str, game);
  free (str);
  return (res);
}

int	attack(t_game *game)
{
  if (!(is_ok("weapon", game->ship)))
    {
      my_putstr_color("red","[SYSTEM FAILURE] Weapon H.S\n");
      return (0);
    }
  if (game->alive <= 0)
    {
      my_putstr_color("red","[SYSTEM FAILURE] Pas d'ennemis\
 a proximite\n");
      return (0);
    }
  prompt(game);
  game->ennemy->hp -= game->ship->weapon->damage;
  if (game->ennemy->hp <= 0)
    ennemy_down(game);
  return (0);
}

int	detect(t_game *game)
{
  if (!(is_ok("nav", game->ship)))
    {
      	my_putstr_color("red","[SYSTEM FAILURE] Detecteur H.S\n");
      return (0);
    }
  if (game->detect == 1)
    {
      my_putstr_color("blue", "La zone a deja ete detecte\n");
      return (0);
    }
    if (game->alive == 1)
    {
      my_putstr_color("blue", " Ennemis present\n");
      return (0);
    } 
  container_zone(game);
  my_putstr_color("green", "Container chargé de 10 éléments\n\n");
  game->detect = 1;
  return (0);
}

int	jump(t_game *game)
{
  if (!(is_ok("drive", game->ship)))
    {
      my_putstr_color("red","[SYSTEM ERROR] Moteur H.S, impossible\
de quitter la zone\n");
      return (0);
    }
  if (game->alive == 1)
    {
      my_putstr_color("red","[SYSTEM ERROR] Presence ennemis\
decollage impossible !\n");
      return (0);
    }
  my_putstr_color("green","Chargement de la puissance\
 pour le saut PRL\nJUMP !\n");
  game->ship->nav->sector += 1;
  game->ship->drive->energy -= 1;
  game->alive = 0;
  game->detect = 0;
  return (0);
}

int	getbonus(t_game *game)
{
  if (game->ship->container->first == NULL)
    {
      my_putstr_color("blue","Container vide ..\n");
      return (0);
    }
  get_bonus(game->ship);
  return (0);
}
