/*
** my_strncat.c for my_strncat.c in /home/adrien/DEVC/Jour04
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Fri Oct 21 17:34:01 2016 CESARO Adrien
** Last update Tue Oct 25 12:45:03 2016 CESARO Adrien
*/
#include <unistd.h>

char	*my_strncat(char *dest, char *src, int n)
{
  int	index;
  int	count;

  index = 0;
  count = 0;
  while (dest[count] != '\0')
    ++count;
  while (src[index] != '\0' && n > 0)
    {
      dest[count] = src[index];
      ++index;
      ++count;
      --n;
    }
  dest[count] = '\0';
  return (dest);
}
