##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##
SRC     =       src/my_printf.c	\
				src/my_conversions.c	\
				src/float_cvrs.c 	\
				src/cvrs_ouxxmaj.c 	\
				src/my_get_convrs.c 	\
				src/print_padding.c		\
				src/my_put_nbr2.c	\
				src/my_strlen.c	\
				src/my_putstr.c		\
				src/my_putchar.c 	\
				src/my_put_nbr.c 	\
				src/my_compute_power_rec.c	\
				src/my_put_float_nbr.c	\
				src/my_strcmp.c			\
				src/my_put_sci_nbr.c		\
				src/my_putnbr_base.c	\
				src/my_strcat.c		\
				src/my_strdup.c		\
				src/my_getnbr.c		\
				src/my_strncmp.c

OBJ	=	$(SRC:.c=.o)

NAME    =       libmy_printf.a

CFLAGS = -I./include

all: 	libmy_printf.a

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../${NAME}
re:		fclean all

.PHONY: all clean fclean re
