/*
** main.c for my_ftl in 
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Thu Nov 10 22:51:39 2016 CESARO Adrien
** Last update Sat Nov 12 10:12:17 2016 CESARO Adrien
*/
#include <unistd.h>
#include "ftl.h"
#include "container.h"
#include "game_cycle.h"

int		main()
{
  t_ship	*test;
  int		res;

  prompt_ftl();
  res = -1;
  test = create_ship();
  if (test != NULL)
    {
      res = add_weapon_to_ship(test);
      res = add_ftl_drive_to_ship(test);
      res = add_navigation_tools_to_ship(test);
      res = add_container_to_ship(test);
    }
  if (res != -1)
    res = game(test);
  if (res == 0)
    victory();
  if (res == -1)
    gameover();
  if (res == -2)
    out_energy();
  return 0;
}

