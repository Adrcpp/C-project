/*
** container_zone.c for my_ftl in /home/adrien/PISCINE/DEVC/my_ftl/src
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Wed Nov  9 19:14:45 2016 CESARO Adrien
** Last update Fri Nov 11 11:49:48 2016 CESARO Adrien
*/
#include <unistd.h>
#include <stdlib.h>
#include "ftl.h"
#include "game_cycle.h"
#include "container.h"
#include "my_string.h"
#include "container_zone.h"
#include "rand.h"

void		container_zone(t_game *game)
{  
  int		index;

  index = 10;
  while (index != 0)
    {
      new_random_freight(game);
      --index;
    }
}

int		new_random_freight(t_game *game)
{
  t_freight	*freight;
  int		prob;
  int		prob2;

  freight = malloc(sizeof(*freight));
  if (freight != NULL)
    {
      prob = randm();
      prob2 = randm();
      if(prob >= 0 && prob < 30)
	{
	  if (prob2 >= 0 && prob2 < 33)
	    freight->item = my_strdup("evadebonus");
	  else if (prob2 >= 33 && prob2 < 66)
	    freight->item = my_strdup("attackbonus");
	  else if (prob2 >= 66 && prob2 < 99)
	    freight->item = my_strdup("energy");
	  else
	    freight->item = my_strdup("scrap");
	}
      else
	freight->item = my_strdup("scrap");
      add_freight_to_container(game->ship, freight);
      return (1);
    }
  return (0);
}
