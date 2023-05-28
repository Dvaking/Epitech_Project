##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC			=	src/main.c					\
				src/entry_value.c			\
				src/linked_list.c			\
				src/find_and_sort.c			\
				src/protection.c			\
				src/fonction/swap.c			\
				src/fonction/rotate.c		\
				src/fonction/push.c			\

OBJ			=	$(SRC:.c=.o)

NAME		=	push_swap

LDLIB		=	-L./lib/

LMY			=	-lmy

CPPFLAGS	=	-I./includes/ -ggdb3

$(NAME):	$(OBJ)
		make -C lib/my/
		cc -o $@ $^ $(CPPFLAGS) $(LDLIB) $(LMY)

all: $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C lib/my

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my
	rm -f unit_tests*

re: fclean $(NAME)

unit_tests:	$(OBJ)
		gcc -o $@ $^ tests/*.c $(CPPFLAGS)\
		--coverage -lcriterion

.PHONY: all clean fclean re
