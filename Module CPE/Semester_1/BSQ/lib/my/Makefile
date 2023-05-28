##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## mon make file
##

SRC			=	my_strlen.c			\
				my_putstr.c			\
				my_putchar.c		\

OBJ			=	$(SRC:.c=.o)

NAME		=	libmy.a

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean :
	rm -f $(NAME)

.PHONY: all clean fclean
