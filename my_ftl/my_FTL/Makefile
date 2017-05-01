##
## Makefile for my_ftl in /home/adrien/PISCINE/DEVC/my_ftl
## 
## Made by CESARO Adrien
## Login   <cesaro_a@etna-alternance.net>
## 
## Started on  Mon Nov  7 10:03:06 2016 CESARO Adrien
## Last update Sat Nov 12 12:43:57 2016 CESARO Adrien
##
CC = gcc 
CFLAGS = -Wall -Wextra -Werror -I./h/
DIR = ./src/
EXEC = my_ftl
RM = rm -f

SRC =	$(DIR)main.c \
	$(DIR)air_shed.c \
	$(DIR)my_string.c \
	$(DIR)container.c \
	$(DIR)system_control.c \
	$(DIR)system_repair.c \
	$(DIR)readline.c \
	$(DIR)rand.c \
	$(DIR)menu.c \
	$(DIR)game_cycle.c \
	$(DIR)rules.c \
	$(DIR)my_put_nbr.c \
	$(DIR)container_zone.c \
	$(DIR)screen.c \
	$(DIR)ennemy_a.c \


OBJ =		$(SRC:%.c=%.o) 

$(EXEC):	$(OBJ) 
		$(CC) $(OBJ) -o $(EXEC) 

fclean:		clean

clean :
		$(RM) $(OBJ)

all:		$(EXEC)

re :     	fclean all

.PHONY :	clean
