/*
** my_putchar.c for my_putchar.c in /home/adrien/DEVC/Jour01
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Mon Oct 17 12:09:48 2016 CESARO Adrien
** Last update Mon Oct 17 18:55:19 2016 CESARO Adrien
*/
#include <unistd.h>

void	my_putchar(char c)
{
  write (1, &c, 1);
}
