/*
** my_getnbr.c for my_getnbr.c in /home/adrien/PISCINE/DEVC/Jour05/cesaro_a/my_getnbr
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Tue Oct 25 18:23:00 2016 CESARO Adrien
** Last update Wed Oct 26 13:20:27 2016 CESARO Adrien
*/
#include <unistd.h>

int	my_detectsign(char c);

int	my_detectnbr(char c);

int	char_to_int(char *s1, int index, int sign);

int	zero_nbr(int i);

int	my_getnbr(char *str)
{
  int	index;
  int	index2;
  int	sign;
  char	temp[50];
  int	flag;

  index = 0;
  index2 = 0;
  sign = 1;
  flag = 0;
  temp[0] = 0;
  while (str[index] != '\0' && flag != 1)
    {
      if(my_detectnbr(str[index]) == 0 && my_detectsign(str[index]) == 0
	 && str[index] != 43 )
	return (0);
      if (my_detectsign(str[index]) == 1)
	sign *=-1;
      if (my_detectnbr(str[index]) == 1)
	{
	  while (my_detectnbr(str[index]) == 1 && str[index] !='\0')
	    {
	      temp[index2] = str[index];
	      ++index;
	      ++index2;
	    }
	  flag = 1;
	  temp[index2] = '\0';
	} 
      ++index;
    }
  return (char_to_int(temp, index2, sign));
}

int	zero_nbr(int i)
{
  int	zero;

  zero = 1;
  while (i > 0)
    {
      zero *= 10;
      --i;
    }
  return (zero);
}

int	char_to_int(char *s1, int index, int sign)
{
  int	calc;
  int	i;
  int	retnbr;

  retnbr = 0;
  i = 0;
  calc = 0;
  while (s1[i] != '\0')
    {
      calc = s1[i] - 48;
      calc *= zero_nbr(index - 1);
      ++i;
      --index;
      retnbr += calc;
      calc = 0;
    }
  return (retnbr * sign);
}

int	my_detectsign(char c)
{
  if (c == '-')
    return (1);
  else
    return (0);
}

int	my_detectnbr(char c)
{
  if (c >= 48 && c <= 57)
    return (1);
  else
    return (0);
}
