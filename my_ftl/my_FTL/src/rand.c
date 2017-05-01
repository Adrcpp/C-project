/*
** rand.c for my_ftl in /home/adrien/PISCINE/DEVC/my_ftl/src
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Wed Nov  9 09:50:28 2016 CESARO Adrien
** Last update Thu Nov 10 23:46:05 2016 CESARO Adrien
*/
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "rand.h"

int	randm()
{
  int	retnbr;

  retnbr = (rand() % 100) + 1;

  return (retnbr);
}

int	random_custom(int a)
{
  int	retnbr;

  srand(time(NULL));
  retnbr = (rand() % a) + 1;

  return (retnbr);
}
