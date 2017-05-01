/*
** my_strlen.c for my_strlen.c in /home/adrien/DEVC/Jour03/cesaro_a
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Thu Oct 20 12:11:19 2016 CESARO Adrien
** Last update Fri Oct 21 16:28:09 2016 CESARO Adrien
*/
#include <unistd.h>

void	my_putchar(char c);

int	my_strlen(char *str)
{
  int	index;

  index = 0;
  while (*(str + index) != '\0')
    ++index;
  return (index);
}
