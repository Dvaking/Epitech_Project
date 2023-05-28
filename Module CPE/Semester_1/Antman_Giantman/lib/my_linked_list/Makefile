##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC			=	add_node_end.c				\
				count_nodes.c				\
				create_list.c				\
				free_list.c					\
				my_strlen.c					\
				print_node.c				\
				swap_first_nodes.c			\
				free_array.c				\
				my_word_array_to_list.c		\
				load_file_in_mem.c

OBJ			=	$(SRC:.c=.o)

NAME		=	libmy_linked_list.a

CPPFLAGS	=	-I./include/

$(NAME): $(OBJ)
	ar rc $@ $^
	mv ${NAME} ../

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

re: fclean all

.PHONY: all re fclean clean
