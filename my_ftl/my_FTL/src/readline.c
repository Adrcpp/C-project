/*
** Cette fonction permet de récuper une ligne
** de moins de 50 caractères sur l'entrée standard.
** La fonction ne prend pas de paramètre et renvoit une chaîne
** allouée (pensez a free()).
*/
#include	<stdlib.h>
#include	<unistd.h>
#include	"my_string.h"
#include	"ftl.h"
#include	"system_repair.h"

char		*readline(void)
{
  ssize_t	ret;
  char		*buff;

  if ((buff = malloc((50 + 1) * sizeof(char))) == NULL)
    return (NULL);
  if ((ret = read(0, buff, 50)) > 1)
    {
      buff[ret - 1] = '\0';
      return (buff);
    }
  free(buff);
  return (NULL);
}

void	my_putchar(const char c)
{
  write(1, &c, 1);
}

void	screen_map()
{
  my_putstr_color("green", "\n _________________  \n");
  my_putstr_color("green", "|                 | \n");
  my_putstr_color("green", "|                 | \n");
  my_putstr_color("green", "|");
}


int	test_repair(char *str, t_ship *ship)
{
  int	index;

  index = 0;
  while (tabfct[index].rep != NULL)
    {
      if (my_strcmp(tabfct[index].rep, str) == 0)
	return (tabfct[index].ptrfct(ship));
      ++index;
    }
  if (my_strcmp(str, "exit") == 0)
    return (1);
  return (0);
}
