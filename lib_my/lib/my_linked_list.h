/*
** my_linked_list.h for libmy_extended in /home/adrien/PISCINE/DEVC/libmy_extended
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Wed Jan 11 09:32:15 2017 CESARO Adrien
** Last update Wed Jan 25 16:20:21 2017 CESARO Adrien
*/
#ifndef _MY_LINKED_LIST_H_
#define _MY_LINKED_LIST_H_

typedef		struct s_list t_list;
struct		s_list
{
  void		*data;
  int		index;
  t_list	*next;
  t_list	*prev;
};

void		my_putchar(char c);
void		my_putchar(char c);
void		my_putstr(char *str);
t_list		*create_list(t_list *newlist);
void		delete_list(t_list *list);
int		push(t_list **list, void *val);
t_list		*search_by_index(t_list **list, int index);
void		delete(t_list **list, int index);
t_list		*search_by_value(t_list **list, void *search);
void		reindex(t_list **list);
  
void	write_nbr(int  i, int n);
void	special();
void	test_nbr(int i, int n, int *tab);
void	my_putchar(char c);
void	my_put_nbr(int n);

int	my_strcmp(char *s1, char *s2);

int	my_strlen(char *s1);
char	*my_strdup(char *str);
#endif
