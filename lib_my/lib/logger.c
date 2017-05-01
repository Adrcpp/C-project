/*
** logger.c for libmy_extended in /home/adrien/PISCINE/DEVC/test/cesaro_a/lib
** 
** Made by CESARO Adrien
** Login   <cesaro_a@etna-alternance.net>
** 
** Started on  Wed Feb 22 09:10:34 2017 CESARO Adrien
** Last update Thu Feb 23 19:46:51 2017 CESARO Adrien
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "libmy_extended.h"

void		logger(t_logger *t, char *msg)
{
  time_t	rawtime;
  struct	tm *timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  fprintf(t->f, "[%s]: %s %s\n", t->level, asctime(timeinfo), msg);
}

t_logger	*log_config(char *level, char *filename, char *add)
{
  t_logger	*logger;

  if ((logger = malloc(sizeof(t_logger))) == NULL)
      return (NULL);
  logger->level = my_strdup(level);
  logger->filename = my_strdup(filename);
  logger->f = fopen(logger->filename, add);
  logger->info = info;
  logger->debug = debug;
  logger->warning = warning;
  logger->error = error;
  return (logger);
}

void		close_log(t_logger *logger)
{
  free(logger->level);
  free(logger->filename);
  fclose(logger->f);
  free(logger);
}
