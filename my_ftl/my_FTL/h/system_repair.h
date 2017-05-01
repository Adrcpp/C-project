/*
** system_repair.h for my_ftl in /home/adrien/PISCINE/DEVC/my_ftl/h
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Tue Nov  8 14:35:49 2016 CESARO Adrien
** Last update Sat Nov 12 10:18:09 2016 CESARO Adrien
*/
#ifndef _SYSTEM_REPAIR_H
#define _SYSTEM_REPAIR_H

int	ftl_drive_system_repair(t_ship *ship);

int	navigation_tools_system_repair(t_ship *ship);

int	weapon_system_repair(t_ship *ship);

int	system_repair(t_ship *ship);

static const t_repair_command tabfct[] =
  {
    {"moteur", &ftl_drive_system_repair},
    {"navigation", &navigation_tools_system_repair},
    {"weapon", &weapon_system_repair},
    {NULL,NULL}
  };

#endif
