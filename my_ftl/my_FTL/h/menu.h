/*
** menu.h for my_ftl in /home/adrien/PISCINE/DEVC/my_ftl/h
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Wed Nov  9 09:27:06 2016 CESARO Adrien
** Last update Wed Nov  9 14:10:58 2016 CESARO Adrien
*/
#ifndef _MENU_H_
#define _MENU_H_

typedef		struct s_menu
{
  char		*choice;
  int		(*ptrf)(t_game*);
}t_menu;

int		menu(t_game *game);

int		jump(t_game *game);

int		attack(t_game *game);

int		detect(t_game *game);

int		getbonus(t_game *game);

#endif
