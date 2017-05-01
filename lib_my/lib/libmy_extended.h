/* 
** libmy_extended.h for libmy_extended in /home/adrien/PISCINE/DEVC/libmy/cesaro_a/libmy-finale
**   
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
**   
** Started on  Wed Jan 25 09:01:05 2017 CESARO Adrien
** Last update Thu Feb 23 21:51:15 2017 CESARO Adrien
*/
#ifndef _LIBMY_EXTENDED_H_
#define _LIBMY_EXTENDED_H_
#include <stdio.h>

typedef		void (*free_function)(void *);
typedef		struct s_list t_list;

struct		s_list
{
  void		*data;
  int		index;
  free_function fn;
  t_list	*next;
  t_list	*prev;
};

typedef		struct s_ok
{
  char		*choice;
  int		(*ptrf)(void*);
}t_ok;

int		is_valid(void* str);
int		name(void*);
int		help();
int		host(void*);
void		add_function(int index, char *opt);
t_list		*args_to_list(int argc, char *argv[]);
int		is_valid_opt(void* str);
int		verif_opt(char *argv[], int i, int argc);
int		add_to_list(char *arg[], int i, int argc, t_list **list);
t_list		*create_list(t_list *newlist);
int		push(t_list **list, void *val, free_function fn);
t_list		*search_by_index(t_list **list, int index);
void		delete(t_list **list, int index);
t_list		*search_by_value(t_list **list, void *search);
void		reindex(t_list **list);
void		free_string(void *data);
int		my_detectsign(char c);
int		my_detectnbr(char c);
int		char_to_int(char *s1, int index, int sign);
int		zero_nbr(int i);
int		my_getnbr(char *str);
int		my_isneg(int n);
void		my_putchar(char c);
void		write_nbr(int i, int n);
void		special();
void		test_nbr(int i, int n, int *tab);
void		my_put_nbr(int n);
void		my_putstr(char *str);
char		*my_strcat(char *dest, char *src);
int		my_strcmp(char *s1, char *s2);
char		*my_strcpy(char *dest, char *src);
int		my_strlen(char *s1);
char		*my_strdup(char *str);
char		*my_strncat(char *dest, char *src, int n);
int		my_strncmp(char *s1, char *s2, int n);
char		*my_strncpy(char *dest, char *src, int n);
int		compare(char *str, char *dest);
char		*my_strstr(char *str, char *to_find);
int		nbr_words(char *str);
int		my_detect_char(char c);
char		*word_cut(char *str);
char		**my_str_to_wordtab(char *str);
void		my_swap(int *a, int *b);
int		is_option(char *str);

static const t_ok tabfct[] = {
  {"-name", &name},
  {"-h", &help},
  {"-host", &host},
  {NULL,NULL}
};

typedef		struct s_logger t_logger;
struct s_logger
{
  char		*level;
  FILE		*f;
  char		*filename;
  void		(*debug)(t_logger*, char*);
  void		(*info)(t_logger*, char*);
  void		(*warning)(t_logger*, char*);
  void		(*error)(t_logger*, char*);
};

void		logger(t_logger *t, char *msg);
void		debug(t_logger *t, char*);
void		info(t_logger *t, char*);
void		warning(t_logger *t, char*);
void	        error(t_logger *t, char*);
t_logger	*log_config(char *level, char *filename, char *add);
void		close_log(t_logger *logger);
extern 		t_logger *xlog;
#endif
