##
## Makefile for libmy_02 in /home/adrien/PISCINE/libmy_02/cesaro_a/libmy_02
## 
## Made by CESARO Adrien
## Login   <cesaro_a@etna-alternance.net>
## 
## Started on  Tue Oct 25 20:11:07 2016 CESARO Adrien
## Last update Thu Feb 23 22:11:55 2017 CESARO Adrien
##
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = libmy_extended.a

SRC = 	my_putchar.c \
	my_isneg.c \
	my_put_nbr.c \
        my_swap.c \
	my_putstr.c \
        my_strlen.c \
	my_getnbr.c \
	my_strcpy.c \
	my_strncpy.c \
	my_strcmp.c \
	my_strncmp.c \
        my_strcat.c \
	my_strncat.c \
	my_strstr.c \
	my_strdup.c \
	my_str_to_wordtab.c \
	my_linked_list.c \
	my_linked_list2.c \
	parser.c \
	args_to_list.c \
	args_to_list2.c \
	logger.c \
	logger2.c \


OBJ = 		$(SRC:.c=.o)


$(NAME):	$(OBJ)
		ar r $(NAME) $(OBJ)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:			clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all
