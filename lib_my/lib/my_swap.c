/*
** my_swap.c for my_swap.c in /home/adrien/DEVC/Jour03
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Thu Oct 20 14:01:42 2016 CESARO Adrien
** Last update Thu Oct 20 14:12:35 2016 CESARO Adrien
*/
#include <unistd.h>

void	my_swap(int *a, int *b)
{
  int	temp;

  temp = *a;
  *a = *b;
  *b = temp;
}
