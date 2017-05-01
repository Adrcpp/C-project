/*
** my_linked_list.c for libmy_extended in 
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Wed Jan 11 09:23:59 2017 CESARO Adrien
** Last update Thu Feb 23 21:43:51 2017 CESARO Adrien
*/
#include <unistd.h>
#include <stdlib.h>
#include "libmy_extended.h"

t_list *create_list(t_list *newlist)
{
  newlist = malloc(sizeof(*newlist));
  if (newlist == NULL)
    return (NULL);
  newlist->next = NULL;
  newlist->prev = NULL;
  newlist = NULL;
  return (newlist);
}

void	free_string(void *data)
{
  free(data);
}

int		push(t_list **list, void *val, free_function fn)
{
  t_list	*tmp;
  t_list	*new_element;
  int		index;

  index = 1;
  list != NULL ? (tmp = (*list)) : (tmp = NULL);
  if ((new_element = malloc(sizeof(t_list))) == NULL)
    return (-1);
  new_element->next = NULL;
  new_element->prev = NULL ;
  new_element->index = 0;
  new_element->data = val;
  new_element->fn = fn;
  if (tmp == NULL)
    {
      *list = new_element;
      return 1;
    }
  while (tmp->next != NULL)
    {
      ++index;
      tmp = tmp->next;
    }
  new_element->index = index;
  new_element->prev = tmp;
  tmp->next = new_element;
  return 0;
}

void		delete(t_list **list, int index)
{
  t_list	*tmp;
  int		bool;

  bool = 0;
  if ((tmp = search_by_index(list, index)))
    {
      if (tmp->next)
	{
	  bool = 1;
	  if (tmp->prev)
	    {
	      tmp->next->prev = tmp->prev;
	      tmp->prev->next = tmp->next;
	    }
	  else
	    tmp->next->prev = NULL;
	  *list = tmp->next;
	}
      if (tmp->fn)
	tmp->fn(tmp->data);
      free(tmp);
      if(bool)
	reindex(list);
    }
}

void		reindex(t_list **list)
{
  t_list	*tmp;
  int		i;

  tmp = NULL;
  if (list)
    tmp = (*list);
  i = 0;
  while (tmp != NULL)
    {
      tmp->index = i;
      my_putstr("Reindex: ");
      my_put_nbr(tmp->index);
      my_putstr("\n");
      tmp = tmp->next;
      ++i;
    }
}
