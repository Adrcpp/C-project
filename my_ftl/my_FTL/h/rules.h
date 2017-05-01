/*
** rules.h for my_ftl in /home/adrien/PISCINE/DEVC/my_ftl/h
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Wed Nov  9 14:46:10 2016 CESARO Adrien
** Last update Fri Nov 11 09:36:50 2016 CESARO Adrien
*/
#ifndef _RULES_H_
#define _RULES_H_

typedef	struct s_ok
{
  char	*choice;
  int	(*ptrf)(t_ship*);
}t_ok;

int	is_ok_nav(t_ship *ship);

int	is_ok_drive(t_ship *ship);

int	is_ok_weapon(t_ship *ship);

int	is_ok(char *str, t_ship *ship);

int	test_choice(char *str, t_game *game);

#endif
