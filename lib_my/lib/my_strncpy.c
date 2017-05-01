/*
** my_strncpy.c for my_strncpy.c in /home/adrien/DEVC/Jour04
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Fri Oct 21 16:15:56 2016 CESARO Adrien
** Last update Tue Oct 25 11:50:00 2016 CESARO Adrien
*/
#include <unistd.h>

char *my_strncpy(char *dest, char *src, int n)
{
  int	index;

  index = 0;
  while (src[index] != '\0' && n > 0)
    {
      dest[index] = src[index];
      --n;
      ++index;
    }
  --index;
  while (n > 0)
    {
      dest[index] = '\0';
      ++index;
      --n;
    }
  return (dest);
}
