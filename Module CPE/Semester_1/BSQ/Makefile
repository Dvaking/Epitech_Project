##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC			=	src/bsq.c				\
				src/protection.c		\
				src/protection2.c		\
				src/copy_in_tab.c		\
				src/redirection.c		\
				src/find_square.c		\
				src/no_square.c			\
				src/display_tab.c		\
				src/bigger_square.c		\
				src/special_cas.c		\
				src/generation_map.c

OBJ			=	$(SRC:.c=.o)

NAME		=	bsq

LDLIB		=	-L./lib/

LMY			=	-lmy

CPPFLAGS	=	-I./includes/

$(NAME):	$(OBJ)
	make -C lib/my/
	gcc -o $@ $^ $(CPPFLAGS) ${LDLIB} ${LMY}
all: $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf lib/my/*.o

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests*
	rm -f lib/libmy.a

re: fclean $(NAME)

unit_tests:	$(OBJ)
		make -C lib/my/
		gcc -o $@ $^ tests/test_my_ls.c $(LDLIB) $(LMY) $(CPPFLAGS)\
		--coverage -lcriterion

.PHONY: all clean fclean re
