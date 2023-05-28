##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC			=	src/main.c												\
				src/load_file_in_mem.c									\
				src/solver.c											\
				src/my_spliter.c										\
				src/lists/create_list.c									\
				src/lists/add_node_end.c								\
				src/lists/delete_node.c									\
				src/algorithm_functions/calcule_distance.c				\
				src/algorithm_functions/find_lowest_f_cost_in_open.c	\
				src/a_star.c											\
				src/check_neighbour.c									\
				src/lists/free_node.c									\
				src/draw_road.c

SRC_TEST	=	src/load_file_in_mem.c									\
				src/solver.c											\
				src/my_spliter.c										\
				src/lists/create_list.c									\
				src/lists/add_node_end.c								\
				src/lists/delete_node.c									\
				src/algorithm_functions/calcule_distance.c				\
				src/algorithm_functions/find_lowest_f_cost_in_open.c	\
				src/A_star.c											\
				src/check_neighbour.c									\
				src/lists/free_node.c									\
				src/draw_road.c

OBJ			=	$(SRC:.c=.o)

NAME		=	solver

LDLIB		=	-L./lib/

LMY			=	-lmy

CPPFLAGS	=	-I./includes/
LCRITER		= -lcriterion

$(NAME): $(OBJ)
	make -C lib/my/
	gcc -o $@ $^ $(CPPFLAGS) ${LDLIB} ${LMY} -lm

all: $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C lib/my/

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests*
	make fclean -C lib/my/

re: fclean $(NAME)

tests_run:	$(SRC_TEST)
	make -C lib/my/
	gcc -o unit_tests $(SRC_TEST) tests/tests.c --coverage -lcriterion \
	$(CPPFLAGS)
	./unit_tests

.PHONY: all clean fclean re unit_tests
