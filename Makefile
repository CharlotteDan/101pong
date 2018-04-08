##
## EPITECH PROJECT, 2017
## makefile 101pong
## File description:
## makefile
##

SRC	=	src/101pong.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	101pong

CFLAGS +=	-Wall -Wextra -Iinclude

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -L. -lm

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all re clean fclean
