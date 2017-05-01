/*
** args_to_list2.c for libmy_extended in /home/adrien/PISCINE/DEVC/test/cesaro_a/lib
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Thu Feb 23 15:27:11 2017 CESARO Adrien
** Last update Thu Feb 23 19:43:48 2017 CESARO Adrien
*/
#include <unistd.h>
#include <stdlib.h>
#include "libmy_extended.h"

int	verif_opt(char *argv[], int i, int argc)
{
  while (i < argc)
    {
      if (is_option(argv[i]) == 0)
	{
	  my_putstr("\nUsage : parser [-h] [-option]");
	  return (0);
	}
      else
	{
	  if(!is_valid(argv[i]))
	    {
	      my_putstr("\nUsage : parser [-h] [-option]");
	      return (0);
	    }
	  if ((i + 1 < argc) && is_valid_opt(argv[i])
	      && is_option(argv[i + 1]) == 0)
	      ++i;
	}
      ++i;
    }
   return (1);
}

int	is_option(char *str)
{
  if (str[0] == 45)
    return (1);
  return (0);  
}
