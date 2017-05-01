/*
** my_putstr.c for my_putstr.c in /home/adrien/DEVC/Jour03
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Thu Oct 20 11:39:57 2016 CESARO Adrien
** Last update Thu Oct 20 11:51:31 2016 CESARO Adrien
*/
#include <unistd.h>

void	my_putchar(char c);

void	my_putstr(char *str)
{
  int	index;

  index = 0;
  while (*(str + index) != '\0')
    {
      my_putchar(*(str + index));
      ++index;
    }
}
