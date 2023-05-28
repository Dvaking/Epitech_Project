##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

NAME	=	project_antman

$(NAME):
	make -C lib/my_linked_list/
	make -C lib/my_printf/
	make -C lib/my/
	make -C antman/
	make -C giantman/

all: $(NAME)

clean:
	make clean -C antman/
	make clean -C giantman/
	make clean -C lib/my_linked_list/
	make clean -C lib/my_printf/
	make clean -C lib/my/

fclean:
	make fclean -C antman/
	make fclean -C giantman/
	make fclean -C lib/my_linked_list/
	make fclean -C lib/my_printf/
	make fclean -C lib/my/

re: fclean $(NAME)

unit_tests:	$(OBJ)
		make -C antman/
		make -C giantman/
		gcc -o $@ $^ tests/test_my_ls.c $(LDLIB) $(LMY) $(CPPFLAGS)\
		--coverage -lcriterion

.PHONY: all clean fclean re
