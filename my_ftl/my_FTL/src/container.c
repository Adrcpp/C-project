/*
** container.c for my_ftl in /home/adrien/PISCINE/DEVC/my_ftl/src
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 16:35:01 2016 CESARO Adrien
** Last update Sat Nov 12 10:10:37 2016 CESARO Adrien
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_string.h"
#include "ftl.h"
#include "container.h"

int		add_container_to_ship(t_ship *ship)
{
  t_container	*container;
  
  my_putstr_color("cyan", "ajout du container en cours...\n");
  container = malloc(sizeof(*container));
  if (container == NULL)
    {
      my_putstr_color("red", "votre vaisseau a explose lorsque\
 vous avez pose le container\n");
      return (0);
    } 
  container->first = NULL;
  container->last = NULL;
  container->nb_elem = 0;
  ship->container = container;
  my_putstr_color("green", "le container a ete ajoute avec succes!\n");
  return (1); 
}

void		add_freight_to_container(t_ship *ship, t_freight *freight)
{
  t_freight	*tmp;
  my_putstr_color("green", freight->item);
  my_putstr("\n");
  if ((ship->container)->first == NULL)
    {
      ship->container->first = freight;
      ship->container->last = freight;
      ship->container->first->next = NULL;
      ship->container->first->prev = NULL;
      ship->container->last->next = NULL;
      ship->container->last->prev = NULL;
    }
  else
    {
      tmp = ship->container->last;
      ship->container->last->next = freight;
      ship->container->last = freight;
      ship->container->last->prev = tmp;
      ship->container->last->next = NULL;
    }
  (ship->container)->nb_elem += 1;
}

void		del_freight_from_container(t_ship *ship, t_freight *freight)
{
  t_freight	*tmpfreight;

  if (ship->container->first != NULL && freight != NULL)
    {
      if (freight == ship->container->first)
	{
	  if (ship->container->first->next != NULL)
	    {
	      tmpfreight = ship->container->first->next;
	      ship->container->first = tmpfreight;
	    }
	  ship->container->first->prev = NULL;
	}
      else
	{
	  tmpfreight = freight->prev;
	  tmpfreight->next = freight->next;
	}
      free(freight->item);
      free(freight);
      ship->container->nb_elem -= 1;
    }
}

void		get_bonus(t_ship *ship)
{
  t_freight	*list;

  list = ship->container->first;
  while (ship->container->nb_elem > 0)
    {
      if (my_strcmp(list->item, "attackbonus") == 0)
	{
	  my_putstr_color("green", "Bonus d'attaque : +5\n");
	  ship->weapon->damage += 5;
	}
      if (my_strcmp(list->item, "evadebonus") == 0)
	{
	  my_putstr_color("green", "Bonus d'evasion : +3\n");
	  ship->nav->evade += 3;
	}
      if (my_strcmp(list->item, "energy") == 0)
	{
	  my_putstr_color("green", "Bonus d'energie : +1\n");
	  ship->drive->energy += 1;
	}
      if (my_strcmp(list->item, "scrap") == 0)
	  my_putstr_color("cyan", "debris inutile\n");
      if (ship->container->last != ship->container->first)
	list = list->next;
      del_freight_from_container(ship, ship->container->first);
    }
  ship->container->first = NULL;
}
