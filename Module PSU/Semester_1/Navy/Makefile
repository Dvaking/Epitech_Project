##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC			=	src/main.c										\
				src/all_signals/connection_signal.c 			\
				src/all_signals/send_signal.c	 				\
				src/all_signals/get_signal.c 					\
				src/all_signals/signal_to_char.c				\
				src/all_signals/win_lose_hit_miss.c				\
				src/all_players/map1.c							\
				src/all_players/map2.c							\
				src/all_players/check_line.c					\
				src/all_players/check_collision.c				\
				src/player_1/player_one.c						\
				src/player_2/player_two.c						\
				src/toolbox/help.c								\
				src/toolbox/generation_map.c					\
				src/toolbox/take_entry.c						\
				src/toolbox/tab_hit_miss.c						\
				src/display/display_all.c						\
				src/display/display_player1.c					\
				src/display/display_player2.c					\
				src/all_tab/generate_tab.c						\
				src/all_tab/modif_tab_hit_miss.c		\
				src/file/check_file.c

OBJ			=	$(SRC:.c=.o)

NAME		=	navy

LDLIB		=	-L./lib/

LMY			=	-lmy -lmy_printf -lnavy

CPPFLAGS	=	-I./includes/ -g3

WARNING		=	-Wall -Wextra

$(NAME):	$(OBJ)
	make -C lib/my/
	make -C lib/my_navy/
	make -C lib/my_printf/
	cc -o $@ $^ $(CPPFLAGS) ${LDLIB} ${LMY}

all: $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C lib/my
	make clean -C lib/my_navy
	make clean -C lib/my_printf

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests*
	make fclean -C lib/my
	make fclean -C lib/my_navy
	make fclean -C lib/my_printf

re: fclean $(NAME)

unit_tests:	$(SRC)
	make -C lib/my/
	gcc -o unit_tests $^ tests/test.c $(LDLIB) $(LMY) $(CPPFLAGS) \
	--coverage -lcriterion
	./unit_tests
	gcovr --exclude tests/

.PHONY: all clean fclean re
