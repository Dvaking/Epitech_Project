##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## mon make file
##

SRC			=	my_strlen.c					\
	  			my_strncmp.c				\
				char_to_int.c				\
				tab_generator.c

OBJ			=	$(SRC:.c=.o)

NAME		=	libmy.a

CPPFLAGS 	=	-g3

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

.PHONY: all clean fclean
