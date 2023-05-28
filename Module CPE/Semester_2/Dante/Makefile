##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

NAME	=	project_dante

$(NAME):
	make -C solver/
	make -C generator/

all: $(NAME)

clean:
	make clean -C solver/
	make clean -C generator/

fclean:
	make fclean -C solver/
	make fclean -C generator/

re: fclean $(NAME)

tests_run:	$(OBJ)
		make -C solver/
		make -C generator/
		gcc -o $@ $^ tests/test_my_ls.c $(LDLIB) $(LMY) $(CPPFLAGS)\
		--coverage -lcriterion

.PHONY: all clean fclean re
