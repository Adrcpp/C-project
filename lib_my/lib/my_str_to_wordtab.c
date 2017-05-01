/*
** my_str_to_wordtab.c for my_str_to_wordtab.c in /home/adrien/PISCINE/DEVC/Jour07/cesaro_a/my_str_to_wordtab
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Mon Oct 24 22:59:31 2016 CESARO Adrien
** Last update Thu Oct 27 12:41:39 2016 CESARO Adrien
*/
#define MY_WDTAB

#include <unistd.h>
#include <stdlib.h>

int	nbr_words(char *str);

int	my_detect_char(char c);

char	*word_cut(char *str);

char	**my_str_to_wordtab(char *str)
{
  int	index;
  char	**args;
  char	*temp;
  int	i;

  i = 0;
  index = 0;
  args = malloc((nbr_words(str) + 1) * sizeof(char*));
  while (str[index] != '\0')
    {
      if (my_detect_char(str[index]) == 1)
	{
	  temp = word_cut(&str[index]);
	  while (my_detect_char(str[index]) == 1 && str[index] != '\0')
	    ++index;
	  --index;
	  args[i] = temp;
	  ++i;
	}
      ++index;
    }
  args[i] = NULL;
  return (args);
}

int	nbr_words(char *str)
{
  int	index;
  int	nb;

  index = 0;
  nb = 0;
  while (str[index] != '\0')
    {
      if (my_detect_char(str[index]) == 1)
	{ 
	  while (my_detect_char(str[index]) != 0 && str[index] != '\0')
	    ++index;
	  --index;
	  ++nb;
	}
      ++index;
    }
  return (nb);
}

int	my_strcount(char *str)
{
  int	index;

  index = 0;
  while (my_detect_char(str[index]) == 1 || str[index] != '\0')
    {
      ++index;
    }
  return (index + 1);
}

int	my_detect_char(char c)
{
  if ( ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
      || (c >= 48 && c <= 57) )
      return 1;
  return 0;
}

char	*word_cut(char *str)
{
  int	i;
  int	j;
  char *dup;

  i = 0;
  j = 0;
  while (my_detect_char(str[i]) == 1 && str[i] != '\0')
    ++i;
  dup = malloc(sizeof(char) * i + 1);
  while (i > j)
    {
      dup[j] = str[j];
      ++j;
    }
  dup[j] = '\0';
  return (dup);
}
