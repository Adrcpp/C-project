/*
** air_shed.c for my_ftl in /home/adrien/PISCINE/DEVC/my_ftl
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 09:27:40 2016 CESARO Adrien
** Last update Sat Nov 12 10:05:30 2016 CESARO Adrien
*/
#include <unistd.h>
#include <stdlib.h>
#include "ftl.h"
#include "my_string.h"
#include "my_put_nbr.h"

t_ship			*create_ship()
{
  t_ship		*ship;

  my_putstr_color("cyan", "construction du vaisseau en cours...\n");
  ship = malloc(sizeof(*ship));
  if (ship == NULL)
    {
      my_putstr_color("red", "le vaisseau n'a pas pu etre \
 construit par manque de materiaux.\n");
      return (NULL);
    }
  ship->hull = 50;
  ship->weapon = NULL;
  ship->drive = NULL;
  ship->nav = NULL;
  ship->container = NULL;
  my_putstr_color("green", "amelioration du vaisseau termine!\n");
  return (ship);
}

int			add_weapon_to_ship(t_ship *ship)
{
  t_weapon		*weapon;

  my_putstr_color("cyan", "ajout des armes en cours...\n");
  weapon = malloc(sizeof(*weapon));
  if (weapon == NULL)
    {
      my_putstr_color("red", "votre vaisseau a explose quand \
vous avez tente d'ajouter les armes\n");
      return (-1);
    }
  my_putstr_color("green", "les armes ont été ajouter avec succes!\n");
  weapon->system_state = my_strdup("Online");
  weapon->damage = 10;
  ship->weapon = weapon;
  return (1);
}

int			add_ftl_drive_to_ship(t_ship *ship)
{
  t_ftl_drive		*drive;

  my_putstr_color("cyan", "ajout du reacteur en cours...\n");
  drive = malloc(sizeof(*drive));
  if (drive == NULL)
    {
      my_putstr_color("red", "votre vaisseau a explose lorsque\
 vous avez pose le reacteur\n");
      return (-1);
    }
   my_putstr_color("green", "le reacteur a été ajouter avec succes!\n");
   drive->system_state = my_strdup("Online");
   drive->energy = 10;
   ship->drive = drive;
   return (1);
}

int			add_navigation_tools_to_ship(t_ship *ship)
{
  t_navigation_tools	*nav;

  my_putstr_color("cyan", "ajout des outils de navigations...\n");
  nav = malloc(sizeof(*nav));
  if (nav == NULL)
    {
      my_putstr_color("red", "votre vaisseau a explose lorsque vous\
 avez pose les outils de navigations\n");
      return (-1);
    }
   my_putstr_color("green", "les outils de navigations\
 ont ete ajoutes avec succes!!\n");
   nav->system_state = my_strdup("Online");
   nav->evade = 25;
   nav->sector = 0;
   ship->nav = nav;
   return (1);
}

int			stat(t_ship *ship)
{
  my_putstr_color("cyan", "HP : ");
  my_put_nbr(ship->hull);
  my_putstr("\n");
  my_putstr_color("cyan", "EVADE : ");
  my_put_nbr(ship->nav->evade);
  my_putstr("\n");
  my_putstr_color("cyan", "ENERGY : ");
  my_put_nbr(ship->drive->energy);
  my_putstr("\n");
  return(0);
}
