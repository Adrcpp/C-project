/*
** my_strcat.c for my_strcat.c in /home/adrien/DEVC/Jour04
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Fri Oct 21 17:34:01 2016 CESARO Adrien
** Last update Tue Oct 25 12:39:30 2016 CESARO Adrien
*/
#include <unistd.h>

char	*my_strcat(char *dest, char *src)
{
  int	index;
  int	count;

  index = 0;
  count = 0;
  while (dest[count] != '\0')
    ++count;
  while (src[index] != '\0')
    {
      dest[count] = src[index];
      ++index;
      ++count;
    }
  dest[count] = '\0';
  return (dest);
}
