##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC			=	src/main.c										\
				../error_handing/error_handing.c					\
				../error_handing/check_list_pointer_list.c			\
				src/all_string/create_str.c						\
				src/all_string/modif_str.c						\
				src/lyr_file/lyr_files.c						\
				src/html_file/html_files.c						\
				src/ppm_file/ppm_files.c						\
				src/compress/compress_setence.c

OBJ			=	$(SRC:.c=.o)

NAME		=	antman

LDLIB		=	-L../lib/

LMY			=	-lmy_printf -lmy -lmy_linked_list

CPPFLAGS	=	-I../includes/ -I./include/ -g3

WARNING		=	-Wall -Wextra

$(NAME):	$(OBJ)
	cc -o $@ $^ $(CPPFLAGS) ${LDLIB} ${LMY} ${WARNING}

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests*

re: fclean $(NAME)

unit_tests:	$(OBJ)
		make -C ../lib/my/
		gcc -o $@ $^ tests/test_my_ls.c $(LDLIB) $(LMY) $(CPPFLAGS)\
		--coverage -lcriterion

.PHONY: all clean fclean re
