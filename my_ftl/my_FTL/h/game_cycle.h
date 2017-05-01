/*
** game_cycle.h for my_ftl in /home/adrien/PISCINE/DEVC/my_ftl/h
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Wed Nov  9 10:10:42 2016 CESARO Adrien
** Last update Fri Nov 11 09:13:35 2016 CESARO Adrien
*/
#ifndef _GAME_CYCLE_H_
#define _GAME_CYCLE_H_

typedef		struct s_ennemy
{
  int		hp;
  int		attack;
}t_ennemy;

typedef		struct s_game
{
  int		count_ennemy;
  int		alive;
  int		detect;
  t_ennemy	*ennemy;
  t_ship	*ship;
}t_game;

int		game(t_ship *ship);

int		condition(t_ship *ship);

int		init_game(t_game *game);

int		create_ennemy(t_game *game);

int		ennemy_attack(t_game *game);

#endif
