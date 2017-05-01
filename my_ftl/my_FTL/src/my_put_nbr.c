/*
** my_put_nbr.c for my_put_nbr.c in /home/adrien/DEVC/Jour05
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Sat Oct 22 15:04:21 2016 CESARO Adrien
** Last update Sat Nov 12 10:13:24 2016 CESARO Adrien
*/
#include <unistd.h>
#include "my_put_nbr.h"

void	my_put_nbr(int n)
{
  int	nbr;
  int	i;

  i = 0;
  if (n == -2147483648)
    special();
  else if (n < 0)
    {
      n *= -1;
      my_putchar(45);
    }
   if (n >= 0 && n <= 9)
      my_putchar(48 + n);
  else
    {
      nbr = n;
      while (nbr > 0)
	{
	  nbr /= 10;
	  ++i;
	}
    }
  write_nbr(i, n);
}
void	write_nbr(int i, int n)
{
  int	tab[i];

  test_nbr(i, n, tab);
  while (i > 0)
    {
      my_putchar(tab[i - 1] + 48);
      --i;
    }
}

void	test_nbr(int i, int n, int *tab)
{
  int	tmp;
  int	tmp2;
  int	index;

  index = 0;
  while (i > 0)
    {
      tmp = n / 10;
      tmp2 = n - (tmp * 10);
      tab[index] = tmp2;
      --i;
      ++index;
      n = n / 10;
    }
}

void	special()
{
  my_putchar('-');
  my_putchar('2');
  my_putchar('1');
  my_putchar('4');
  my_putchar('7');
  my_putchar('4');
  my_putchar('8');
  my_putchar('3');
  my_putchar('6');
  my_putchar('4');
  my_putchar('8');
}
