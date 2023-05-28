##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## mon make file
##

SRC			=	my_strncmp.c				\
				split_my_str.c				\
				my_str_isalpha.c			\
				my_str_isnum.c				\
				is_alpha_num.c				\
				my_strlen.c					\
				my_str_to_word_array.c		\
				my_getnbr.c					\
				str_to_int.c				\
				my_strcmp.c					\
				str_to_tab.c

OBJ			=	$(SRC:.c=.o)

NAME		=	libmy.a

CFLAGS += -g3 -I..//includes/

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)
	rm -f unit_tests*

.PHONY: all clean fclean
