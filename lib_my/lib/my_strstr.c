/*
** my_strstr.c for my_strstr.c in /home/adrien/DEVC/Jour04
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Sat Oct 22 19:36:38 2016 CESARO Adrien
** Last update Thu Oct 27 11:28:23 2016 CESARO Adrien
*/
#include <unistd.h>

int	compare(char *str, char *dest);

char	*my_strstr(char *str, char *to_find)
{
  int	index;
  int	flag;

  flag = -1;
  index = 0;
  while (str[index] != '\0')
    {
      if (str[index] == to_find[0])
	{
	  flag = compare(&str[index], &to_find[0]);
	  if (flag == 0)
	    {
	      return &str[index];
	    }
	}
      ++index;
    }
  return (NULL);
}

int	compare(char *str, char *dest)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && (dest[i] == str[i]))
    {
      if (dest[i + 1] == '\0')
	return (0);
      ++i;
    }
  return (1);
}
