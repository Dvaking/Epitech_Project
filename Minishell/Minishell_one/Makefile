##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC			=	src/main.c									\
				src/minishell_one.c							\
				src/toolbox/take_env.c						\
				src/toolbox/take_entry.c					\
				src/toolbox/starting.c						\
				src/toolbox/free.c							\
				src/all_tab/reduce_tab.c					\
				src/all_tab/enlarge_tab.c					\
				src/all_tab/modif_tab.c						\
				src/all_command/command.c					\
				src/all_command/command_checker.c			\
				src/all_command/env.c						\
				src/all_command/cd.c						\
				src/all_command/unsetenv_setenv.c			\
				src/all_cd/move_in_folder.c					\
				src/error_handing/check_argc_argv.c

OBJ			=	$(SRC:.c=.o)

NAME		=	mysh

LDLIB		=	-L./lib/

LMY			=	-lmy

CPPFLAGS	=	-I./includes/ -ggdb3

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
