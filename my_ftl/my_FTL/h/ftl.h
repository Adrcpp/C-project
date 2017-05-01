/*
** ftl.h for my_ftl in /home/adrien/PISCINE/DEVC/my_ftl
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 09:16:40 2016 CESARO Adrien
** Last update Sat Nov 12 10:08:22 2016 CESARO Adrien
*/
#ifndef _FTL_H_
#define _FTL_H_

typedef			struct s_freight t_freight;

struct s_freight
{
  char			*item;
  t_freight		*next;
  t_freight		*prev;
};

typedef			struct s_container
{
  t_freight		*first;
  t_freight		*last;
  int			nb_elem;
  
}t_container;

typedef			struct s_navigation_tools
{
  char			*system_state;
  int			sector;
  int			evade;
}t_navigation_tools;

typedef			struct s_ftl_drive
{
  char			*system_state;
  int			energy;
}t_ftl_drive;

typedef			struct s_weapon
{
  char			*system_state;
  int			damage;
}t_weapon;

typedef			struct s_ship
{
  int			hull;
  t_weapon		*weapon;
  t_ftl_drive		*drive;
  t_navigation_tools	*nav;
  t_container		*container;
}t_ship;

typedef			struct s_repair_command
{
  char			*rep;
  int			(*ptrfct)(t_ship*);
}t_repair_command;

t_ship			*create_ship();

char			*readline(void);

int			add_weapon_to_ship(t_ship *ship);

int			add_ftl_drive_to_ship(t_ship *ship);

int			add_navigation_tools_to_ship(t_ship *ship);

void			prompt_ftl();

void			out_energy();

void			gameover();

int			map(t_ship *ship);

void			victory();

int			stat(t_ship *ship);

void			my_putchar(const char c);

void			screen_map();

int			test_repair(char *str, t_ship *ship);

#endif

