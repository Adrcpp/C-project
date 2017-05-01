/*
** my_strcpy.c for my_strcpy.c in /home/adrien/DEVC/Jour04
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Fri Oct 21 15:56:56 2016 CESARO Adrien
** Last update Tue Oct 25 11:35:41 2016 CESARO Adrien
*/
#include <unistd.h>

char *my_strcpy(char *dest, char *src)
{
  int	index;

  index = 0;
  while (src[index] != '\0')
    {
      dest[index] = src[index];
      ++index;
    }
  dest[index] = '\0';
  
  return (dest);
}
