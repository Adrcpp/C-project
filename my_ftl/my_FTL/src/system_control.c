/*
** system_control.c for my_ftl in /home/adrien/PISCINE/DEVC/my_ftl/src
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Tue Nov  8 11:11:46 2016 CESARO Adrien
** Last update Thu Nov 10 19:15:11 2016 CESARO Adrien
*/
#include "ftl.h"
#include "system_control.h"
#include "my_string.h"

void	ftl_drive_system_check(t_ship *ship)
{
  my_putstr_color("cyan", "verification du reacteur en cours...\n");
  if (my_strcmp(ship->drive->system_state, "Online") != 0)
    my_putstr_color("red", "reacteur hors service!\n");
  else
    my_putstr_color("green", "reacteur OK!\n");
}

void	navigation_tools_system_check(t_ship *ship)
{
  my_putstr_color("cyan", "verification du systeme de navigation\
 en cours...\n");
  if (my_strcmp(ship->nav->system_state, "Online") != 0)
    my_putstr_color("red", "systeme de navigation hors service!\n");
  else
    my_putstr_color("green", "systeme de navigation OK!\n");
}

void	weapon_system_check(t_ship *ship)
{
  my_putstr_color("cyan", "verification du systeme \
d'armement en cours...\n");
  if (my_strcmp(ship->weapon->system_state, "Online") != 0)
    my_putstr_color("red", "systeme d'armement hors service!\n");
  else
    my_putstr_color("green", "systeme d'armement OK!\n");
}

int	 system_control(t_ship *ship)
{
  ftl_drive_system_check(ship);
  navigation_tools_system_check(ship);
  weapon_system_check(ship);
  return (0);
}
