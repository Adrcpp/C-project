/*
** my_isneg.c for my_isneg.c in /home/adrien/cesaro_a
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Mon Oct 17 19:46:18 2016 CESARO Adrien
** Last update Mon Oct 17 23:53:14 2016 CESARO Adrien
*/
#include <unistd.h>

int	my_isneg(int n)
{
  if (n < 0)
    return (0);
  else
    return (1);
}
