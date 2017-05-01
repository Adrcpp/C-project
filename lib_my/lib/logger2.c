/*
** logger2.c for libmy_extended in /home/adrien/PISCINE/DEVC/test/cesaro_a/lib
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Wed Feb 22 11:06:22 2017 CESARO Adrien
** Last update Thu Feb 23 17:18:29 2017 CESARO Adrien
*/
#include <unistd.h>
#include <stdlib.h>
#include "libmy_extended.h"

void		debug(t_logger *t, char *msg)
{
  logger(t, msg);
}

void		info(t_logger *t, char *msg)
{
  char *lvl;

  lvl = t->level;
  if (my_strcmp(lvl, "WARNING") == 0
      && my_strcmp(lvl, "ERROR") == 0
      && my_strcmp(lvl, "INFO") == 0)
      logger(t, msg);
}

void		warning(t_logger *t, char *msg)
{
  char *lvl;

  lvl = t->level;
  if (my_strcmp(lvl, "WARNING") == 0
      && my_strcmp(lvl, "ERROR") == 0)
    logger(t, msg);
}

void	        error(t_logger *t, char *msg)
{
  char *lvl;

  lvl = t->level;
  if (my_strcmp(lvl, "ERROR") == 0)
    logger(t, msg);
}
