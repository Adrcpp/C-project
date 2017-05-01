/*
** my_string.h for my_ftl in /home/adrien/PISCINE/DEVC/my_ftl/h
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 11:41:40 2016 CESARO Adrien
** Last update Sat Nov 12 10:08:58 2016 CESARO Adrien
*/
#ifndef _MY_STRING_H_
#define _MY_STRING_H_

typedef	      	struct s_color t_color;

int		my_strlen(const char *str);

void		my_putstr(const char *str);

int		my_strcmp(const char *s1, const char *s2);

char		*my_strdup(const char *str);

void		my_putstr_color(const char *color, const char *str);

#endif
