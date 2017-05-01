/*
** my_strcmp.c for my_strcmp.c in /home/adrien/DEVC/Jour04
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Fri Oct 21 16:35:14 2016 CESARO Adrien
** Last update Sun Oct 23 16:20:11 2016 CESARO Adrien
*/
#include <unistd.h>

int	my_strcmp(char *s1, char *s2)
{
  int	index;

  index = 0;
  while (s1[index] != '\0' && s1[index] == s2[index])
    {
      if (s2[index] == '\0')
	return (1);
      ++index;
    }
  if (s1[index] < s2[index])
    return (-1);
  else if (s1[index] > s2[index])
    return (1);
  else
     return (0);
}
