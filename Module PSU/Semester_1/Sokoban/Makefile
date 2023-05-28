##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC			=	src/sokoban.c			\
				src/tab.c				\
				src/map_size.c			\
				src/condition_move.c	\
				src/free_destroy.c		\
				src/move_box.c			\
				src/move_player.c		\
				src/windows.c			\
				src/display.c			\
				src/protection.c

OBJ			=	$(SRC:.c=.o)

NAME		=	my_sokoban

LNCURS		=	-lncurses

LDLIB		=	-L./lib/

LMY			=	-lmy

CPPFLAGS	=	-I./includes/ -ggdb3

$(NAME):	$(OBJ)
		make -C lib/my/
		cc -o $@ $^ $(CPPFLAGS) $(LNCURS) $(LDLIB) $(LMY)

all: $(NAME)

clean:
	rm -f $(OBJ)
	rm -rf lib/my/*.o

fclean: clean
	rm -f $(NAME)
	rm -f lib/libmy.a
	rm -f unit_tests*

re: fclean $(NAME)

unit_tests:	$(OBJ)
		gcc -o $@ $^ tests/*.c $(CPPFLAGS)\
		--coverage -lcriterion

.PHONY: all clean fclean re
