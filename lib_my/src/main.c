/*
** main.c for libmy_extended in /home/adrien/PISCINE/DEVC/libmy_extended
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Wed Jan 11 09:30:31 2017 CESARO Adrien
** Last update Thu Feb 23 21:54:17 2017 CESARO Adrien
*/
#include <unistd.h>
#include <stdlib.h>
#include "../lib/libmy_extended.h"

t_logger	*xlog = NULL;

int		main(int argc, char *argv[])
{
  t_list	*list;
  t_list	*tmp;

  int i = 0;
  int arr[] = {0,1,2,3,4,5,6,7,8,9};
  list = NULL;
  xlog  = log_config("ERROR", "./test.log", "a");
  my_putstr("\nTest n°1 Liblist:\n ");
  while (i < 10)
    {
      if(push(&list, &arr[i], NULL) == -1)
	{
	  return 0;
	}
      ++i;
    }
  tmp = list;
  if (tmp)
    {
      while (tmp)
	{  
	  my_putstr("\nDATA : ");
	  my_put_nbr(*(int *)tmp->data);
	  my_putstr(" index : "); 
	  my_put_nbr(tmp->index);
	  my_putstr("\n");
	  tmp = tmp->next;
	  delete(&list, 0);
	}
    }
  my_putstr("\n ");
  my_putstr("\n------------------------------\n ");
  my_putstr("\nTest n°2 Parse:\n\n ");
  list = args_to_list(argc, argv); 
  tmp = list;
  if (tmp)
    {
      my_putstr("\n\n Effacement des arguments .. ");
      while (tmp)
	{  
	  my_putstr("\n");
	  if (tmp->data)
	    my_putstr(tmp->data);
	  my_putstr(" index : "); 
	  my_put_nbr(tmp->index);
	  my_putstr("\n");
	  tmp = tmp->next;
	  delete(&list, 0);
	}
    }
  if (!xlog)
    return (0);
  xlog->error(xlog, "error not found");
  close_log(xlog);
  return (0);
}
