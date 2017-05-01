/*
** my_strdup.c for my_strdup.c in /home/adrien/PISCINE/DEVC/Jour07/cesaro_a/my_strdup
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Mon Oct 24 22:41:24 2016 CESARO Adrien
** Last update Fri Feb  3 13:26:01 2017 CESARO Adrien
*/
#include <unistd.h>
#include <stdlib.h>

int	my_strlen(char *s1);

char	*my_strdup(char *str)
{
  int	count;
  char	*strdup;
  int	index;

  count = my_strlen(str);
  index = 0;
  strdup = malloc(sizeof(char) * (count + 1));
  while (count > index)
    {
      strdup[index] = str[index];
      ++index;
    }
  strdup[index] = '\0';
  return (strdup);
}
