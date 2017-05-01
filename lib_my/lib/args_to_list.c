/*
** arg_to_list for libmy_extended in /home/adrien/PISCINE/DEVC/libmy_extended
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Wed Jan 11 09:30:31 2017 CESARO Adrien
** Last update Thu Feb 23 16:56:44 2017 CESARO Adrien
*/
#include <unistd.h>
#include <stdlib.h>
#include "libmy_extended.h"

static char *valid_args[] = {"-name", "-h", "-host", NULL};
static t_ok added[100];

t_list		*args_to_list(int argc, char *argv[])
{
  t_list	*list;
  int		i;
  t_list	*tmp;
  
  i = 0;
  list = NULL;
  if (argc == 1)
    {
      my_putstr("\nUsage : parser [-h] [-option]");
      return (0);
    }
  if (!verif_opt(argv, 1, argc))
    return (0);
  if (!add_to_list(argv, 1, argc, &list))
    return (0);
  my_putstr("\n Appel des fonctions enregistrées : \n");
  while (added[i].choice != NULL)
    {
      my_putstr("\n Nom de la fonction : ");
      my_putstr(added[i].choice);
      tmp = search_by_index(&list, i);
      tmp ? added[i].ptrf(tmp->data) : added[i].ptrf(NULL);
      ++i;
    }
  return (list);
}

int		add_to_list(char *argv[], int i, int argc, t_list **list)
{
  char		*arg;
  int		index;

  index = 0;
  while (i < argc)
    {
      if ((i + 1 < argc) && is_option(argv[i + 1]) == 0)
	{
	  arg = my_strdup(argv[i + 1]);
	  push(list, arg, free_string);
	  add_function(index, argv[i]);
	  ++i;
	}
      if(is_option(argv[i]))
	{
	  push(list, NULL, NULL);
	  add_function(index, argv[i]);
	}
      ++index;
      ++i;
    }
  added[index + 1] = tabfct[3];
  return (1);
}

void		add_function(int index, char *opt)
{
  int		i;

  i = 0;
  while (valid_args[i] != NULL)
    {
      if (my_strcmp(valid_args[i], opt) == 0)
	added[index] = tabfct[i];
      ++i;
    }
}
