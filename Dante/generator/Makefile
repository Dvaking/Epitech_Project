##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC			=	src/main.c								\
				src/generator.c							\
				src/toolbox/free.c						\
				src/toolbox/perfect_or_not.c			\
				src/error_handing/check_argc_argv.c		\
				src/all_tab/create_tab_and_fill_it.c	\
				src/all_tab/take_data.c					\
				src/all_tab/imperfect_tab.c				\
				src/all_tab/add_way.c					\
				src/all_tab/create_tab_int.c			\
				src/all_tab/display_tab.c				\
				src/maze/create_maze.c					\
				src/maze/move_condition.c

OBJ			=	$(SRC:.c=.o)

NAME		=	generator

LDLIB		=	-L./lib/

LMY			=	-lmy

CPPFLAGS	=	-I./includes/ -g3

LCRITER		= -lcriterion

$(NAME): $(OBJ)
	make -C lib/my/
	gcc -o $@ $^ $(CPPFLAGS) ${LDLIB} ${LMY}

all: $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C lib/my/

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests*
	make fclean -C lib/my/

re: fclean $(NAME)

unit_tests:	$(SRC)
	make -C lib/my/
	gcc -o unit_tests $^ tests/test.c $(LDLIB) $(LMY) $(CPPFLAGS) \
	--coverage -lcriterion
	./unit_tests
	gcovr --exclude tests/

.PHONY: all clean fclean re unit_tests
