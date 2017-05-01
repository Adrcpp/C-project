##
## Makefile for libmy_extended in /home/adrien/PISCINE/DEVC/test
## 
## Made by CESARO Adrien
## Login   <cesaro_a@etna-alternance.net>
## 
## Started on  Fri Feb  3 13:29:17 2017 CESARO Adrien
## Last update Thu Feb 23 19:42:22 2017 CESARO Adrien
##

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
NAME = parser

SRC= 		main.c

SUBLIB=		./lib/

SUBSRC=		./src/

subsystem=	$(MAKE) $(CFLAGS) -C $(SUBLIB)

OBJ=		$(SUBSRC)$(SRC:.c=.o)

$(NAME):	$(OBJ) 
		$(subsystem)
		$(CC) $(OBJ)  $(SUBLIB)libmy_extended.a -o $(NAME)

all:		$(NAME)

.PHONY:		all

clean:
		$(MAKE) clean -C $(SUBLIB)
		$(RM) $(OBJ)

fclean:			clean
		$(RM) $(NAME)

re:		fclean all
