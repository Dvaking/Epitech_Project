##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## mon make file
##

SRC			=	my_putchar.c				\
	  			my_put_nbr.c				\
	  			my_putstr.c					\
	  			my_revstr.c					\
				my_strlen.c

OBJ			=	$(SRC:.c=.o)

NAME		=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

.PHONY: all clean fclean
