/*
** screen.c for my_ftl in /home/adrien/PISCINE/DEVC/my_ftl/src
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Thu Nov 10 22:45:11 2016 CESARO Adrien
** Last update Sat Nov 12 10:05:07 2016 CESARO Adrien
*/
#include <unistd.h>
#include <stdlib.h>
#include "ftl.h"
#include "my_string.h"
#include "screen.h"
#include "my_put_nbr.h"

void		prompt_ftl()
{
  my_putstr("\033[2J");
  my_putstr("\033[H");
  my_putstr_color("green", " ===========================\
==============================| \n");
  my_putstr_color("green", " .___  ___. ____    ____  \
   _______ .___________. __ \n");
  my_putstr_color("green", " |   \\/   | \\   \\  /   \
/    |   ____||           ||  | \n");
  my_putstr_color("green", " |  \\  /  |  \\   \\/   /  \
   |  |__   `---|  |----`|  | \n");
  my_putstr_color("green", " |  |\\/|  |   \\_    _/   \
   |   __|      |  |     |  | \n");;
  my_putstr_color("green", " |  |  |  |     |  |      \
  |  |         |  |     |  `----. \n");
  my_putstr_color("green", " |__|  |__|     |__|     \
   |__|         |__|     |_______| \n\n");
  my_putstr_color("green", " ===========================\
==============================| \n\n\n");
}

void		victory()
{
  my_putstr("\033[2J");
  my_putstr("\033[H");
  my_putstr_color("green", "\n██╗   ██╗██╗ ██████╗████████╗\
 ██████╗ ██████╗ ██╗   ██\n");
  my_putstr_color("green", "██║   ██║██║██╔════╝╚══██╔══╝\
██╔═══██╗██╔══██╗╚██╗ ██╔╝\n");
  my_putstr_color("green", "██║   ██║██║██║        ██║  \
 ██║   ██║██████╔╝ ╚████╔╝\n");
  my_putstr_color("green", "╚██╗ ██╔╝██║██║        ██║ \
  ██║   ██║██╔══██╗  ╚██╔╝ \n");
  my_putstr_color("green", " ╚████╔╝ ██║╚██████╗   ██║ \
  ╚██████╔╝██║  ██║   ██║ \n");
  my_putstr_color("green", "  ╚═══╝  ╚═╝ ╚═════╝   ╚═╝  \
  ╚═════╝ ╚═╝  ╚═╝   ╚═╝ \n");
}

int		map(t_ship *ship)
{
  int		i;
  char		str[20];
  char		*str2;

  i = 0;
  str2 = "\t\tX | \n\0";
  my_putstr_color("blue", " Secteur :");
  my_put_nbr(ship->nav->sector);
  while (ship->nav->sector > i)
    {
      str[i] = 32;
      str[i + 1] = 32;
      str[i + 2] = 32;
      ++i;
    }
  if (ship->nav->sector >= 6)
    str2 = "\tX | \n\0";
  str[i] = '>';
  str[i + 1] = '\0';
  screen_map();
  my_putstr_color("green", str);
  my_putstr_color("green", str2);
  my_putstr_color("green", "|            S10  | \n");
  my_putstr_color("green", "|                 | \n");
  my_putstr_color("green", "|_________________| \n");
  return (0);
}

void		out_energy()
{
  my_putstr_color("clr", "Vous n'avez plus d'energie.... \
vous flotte sans fin\n"); 
}

void		gameover()
{
  my_putstr_color("red", "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼ \n");
  my_putstr_color("red", "███▀▀▀██┼███▀▀▀███┼███▀█▄█▀███┼██▀▀▀ \n");
  my_putstr_color("red", "██┼┼┼┼██┼██┼┼┼┼┼██┼██┼┼┼█┼┼┼██┼██┼┼┼ \n");
  my_putstr_color("red", "██┼┼┼▄▄▄┼██▄▄▄▄▄██┼██┼┼┼▀┼┼┼██┼██▀▀▀ \n");
  my_putstr_color("red", "██┼┼┼┼██┼██┼┼┼┼┼██┼██┼┼┼┼┼┼┼██┼██┼┼┼ \n");
  my_putstr_color("red", "███▄▄▄██┼██┼┼┼┼┼██┼██┼┼┼┼┼┼┼██┼██▄▄▄ \n");
  my_putstr_color("red", "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼ \n");
  my_putstr_color("red", "███▀▀▀███┼▀███┼┼██▀┼██▀▀▀┼██▀▀▀▀██▄┼ \n");
  my_putstr_color("red", "██┼┼┼┼┼██┼┼┼██┼┼██┼┼██┼┼┼┼██┼┼┼┼┼██┼ \n");
  my_putstr_color("red", "██┼┼┼┼┼██┼┼┼██┼┼██┼┼██▀▀▀┼██▄▄▄▄▄▀▀┼ \n");
  my_putstr_color("red", "██┼┼┼┼┼██┼┼┼██┼┼█▀┼┼██┼┼┼┼██┼┼┼┼┼██┼ \n");
  my_putstr_color("red", "███▄▄▄███┼┼┼─▀█▀┼┼─┼██▄▄▄┼██┼┼┼┼┼██▄ \n");
  my_putstr_color("red", "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼ \n");
}
