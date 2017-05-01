/*
** container.h for my_ftl in /home/adrien/PISCINE/DEVC/my_ftl/h
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 16:36:26 2016 CESARO Adrien
** Last update Sat Nov 12 10:07:43 2016 CESARO Adrien
*/
#ifndef _CONTAINER_H_
#define _CONTAINER_H_

int	add_container_to_ship(t_ship *ship);

void	add_freight_to_container(t_ship *ship, t_freight *freight);

void	del_freight_from_container(t_ship *ship, t_freight *freight);

void	get_bonus(t_ship *ship);

#endif
