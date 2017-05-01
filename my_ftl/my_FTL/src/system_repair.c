/*
** system_repair.c for my_ftl in /home/adrien/PISCINE/DEVC/my_ftl/src
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Tue Nov  8 14:34:54 2016 CESARO Adrien
** Last update Sat Nov 12 10:16:57 2016 CESARO Adrien
*/
#include <stdlib.h>
#include "my_string.h"
#include "ftl.h"
#include "my_string.h"
#include "system_repair.h"

int	ftl_drive_system_repair(t_ship *ship)
{
  char	*str;

  str = my_strdup("Online");
  my_putstr_color("cyan","reparation du reacteur en cours...\n");
  if (str == NULL)
    {
      free(str);
      my_putstr_color("red","les reparations du reacteur ont echoue\n");
      return (-2);
    }
  free(ship->drive->system_state);
  ship->drive->system_state = str;
  my_putstr_color("green", "reparation termine! \
systeme reacteur OK!\n");
  return (1);
}

int	navigation_tools_system_repair(t_ship *ship)
{
  char	*str;

  str = my_strdup("Online");
  my_putstr_color("cyan","reparation du systeme \
de navigation en cours...\n");
  if (str == NULL)
    {
      free(str);
      my_putstr_color("red","les reparations des \
outils de navigations ont echoue\n");
      return (-2);
    }
  free(ship->nav->system_state);
  ship->nav->system_state = str;
  my_putstr_color("green", "reparation termine! \
systeme de navigation OK!\n");
  return (1);
}

int	weapon_system_repair(t_ship *ship)
{
  char	*str;

  str = my_strdup("Online");
  my_putstr_color("cyan","reparation du \
systeme de navigation en cours ...\n");
  if (str == NULL)
    {
      free(str);
      my_putstr_color("red","les reparations du \
systeme d'armement ont echoue\n");
      return (-2);
    }
  free(ship->weapon->system_state);
  ship->weapon->system_state = str;
  my_putstr_color("green", "reparation termine! \
systeme d'armement OK!\n");
  return (1);
}

int	system_repair(t_ship *ship)
{
  char	*str;

  my_putstr_color("cyan", "1 - moteur\n2 - navigation\n\
3 - weapon\n\n4 - Exit\n\n");
  my_putstr_color("cyan", "repair_system~>");
  str = readline();
  if (str == NULL)
    {
      free(str);
      my_putstr_color("red", "[SYSTEM FAILURE] : le lecteur \
de commande est bloque\n");
      return (1);
    }
  if (test_repair(str, ship))
    {
      free(str);
      return (1);
    }
  my_putstr_color("red", "[SYSTEM FAILURE] : commande \
inconnue\n");
  free(str);
  return (1);
}
