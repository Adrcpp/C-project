/*
** parser.c for libmy_extended in /home/adrien/PISCINE/DEVC/libmy_extended
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Sun Jan 22 19:46:22 2017 CESARO Adrien
** Last update Thu Feb 23 16:42:43 2017 CESARO Adrien
*/
#include <unistd.h>
#include <stdlib.h>
#include "libmy_extended.h"

static char *valid_args[] = {"-name", "-h", "-host", NULL};
static char *valid_args_opt[] = {"-name", "-host", NULL};

int		name(void* name)
{
  if (name == NULL)
    {
      my_putstr("\n\n NAME (DEFAULT) : Root ");
      my_putstr("\n\n--------------------------\n");
      return (0);
    }
  my_putstr("\n\n NAME (argument added) >>>>>> : ");
  my_putstr(name);
  my_putstr("\n\n--------------------------\n");
  return (0);
}

int		help()
{
  my_putstr("\nUsage : parser [-h] [-option]");
  my_putstr("\n-h    : help");
  my_putstr("\n-name : name the server (default: root)");
  my_putstr("\n-host : give a host (default : localhost)");
  my_putstr("\n\n--------------------------\n");
  return (0);
}

int		host(void* str)
{
  if (str == NULL)
    {
      my_putstr("\n\n HOST (DEFAULT) : Localhost ");
      my_putstr("\n\n--------------------------\n");
      return (0);
    }
  my_putstr("\n\n HOST  (argument added) : ");
  my_putstr(str);
  my_putstr("\n\n--------------------------\n");
  return (0);
}


int		is_valid(void* str)
{
  int		i;

  i = 0;
  while (valid_args[i] != NULL)
    {
      if (my_strcmp(valid_args[i], str) == 0)
	{
	  valid_args[i] = "";
	  return (1);
	}
      ++i;
    }
  return (0);
}

int		is_valid_opt(void* str)
{
  int		i;

  i = 0;
  while (valid_args_opt[i] != NULL)
    {
      if (my_strcmp(valid_args_opt[i], str) == 0)
	{
	  valid_args_opt[i] = "";
	  return (1);
	}
      ++i;
    }
  return (0);
}
