##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile navy
##

SRC			=	create_x_numb.c				\
	  			create_i_numb.c

OBJ			=	$(SRC:.c=.o)

NAME		=	libnavy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../

clean:
	rm -f $(OBJ)
	rm -f ../libnavy.a

fclean: clean
re:		fclean all

.PHONY: all clean fclean
