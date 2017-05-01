/*
** my_strncmp.c for my_strncmp.c in /home/adrien/DEVC/Jour04
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Fri Oct 21 17:04:10 2016 CESARO Adrien
** Last update Sun Oct 23 16:37:00 2016 CESARO Adrien
*/
#include <unistd.h>

int	my_strncmp(char *s1, char *s2, int n)
{
  int	index;

  --n;
  index = 0;
  while (s1[index] != '\0' && n != 0 && (s1[index] == s2[index]))
    {
      if (s2[index] == '\0')
	return (1);
      ++index;
      --n;	
    }
  if (s1[index] < s2[index])
    return (-1);
  else if (s1[index] > s2[index])
    return (1);
  else
    return (0);
}
