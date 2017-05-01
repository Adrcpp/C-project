/*
** system_control.h for my_ftl in /home/adrien/PISCINE/DEVC/my_ftl/h
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Tue Nov  8 11:12:24 2016 CESARO Adrien
** Last update Thu Nov 10 19:16:06 2016 CESARO Adrien
*/
#ifndef _SYSTEM_CONTROL_H
#define _SYSTEM_CONTROL_H

void	ftl_drive_system_check(t_ship *ship);

void	navigation_tools_system_check(t_ship *ship);

void	weapon_system_check(t_ship *ship);

int	system_control(t_ship *ship);

#endif
