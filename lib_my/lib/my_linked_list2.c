/*
** my_linked_list2.c for libmy_extended in /home/adrien/PISCINE/DEVC/test/cesaro_a/lib
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Sat Feb 11 19:04:48 2017 CESARO Adrien
** Last update Wed Feb 15 13:50:09 2017 CESARO Adrien
*/
#include <unistd.h>
#include <stdlib.h>
#include "libmy_extended.h"

t_list		*search_by_index(t_list **list, int index)
{
  t_list	*tmp;

  tmp = *list;
  while (tmp)
    {
      if (index == tmp->index)
	return tmp;
      tmp = tmp->next;
    }
  return (NULL);
}

t_list		*search_by_value(t_list **list, void *search)
{
  t_list	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (my_strcmp(search, (tmp)->data) == 0)
	return tmp;
      tmp = tmp->next;
    }
  return (NULL);
}
