##
## EPITECH PROJECT, 2022
## Makefile project
## File description:
## compile the project and the lib
##

SRC	= 	my_printf.c 				\
		flag_c.c 					\
		flag_d.c 					\
		flag_i.c 					\
		flag_o.c 					\
		flag_s.c 					\
		flag_f.c 					\
		flag_n.c 					\
		flag_e.c 					\
		flag_u.c 					\
		flag_x.c 					\
		flag_x_maj.c 				\
		flag_percentage.c 			\
		flag_f_maj.c 				\
		flag_e_maj.c 				\
		count_digit.c 				\
		find_flag.c 				\
		my_strlen.c 				\
		my_put_nbr.c 				\
		my_putchar.c 				\
		my_str_isalpha.c 			\
		my_str_isnum.c 				\
		my_getnbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy_printf.a

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

re: clean all

.PHONY: all clean fclean re
