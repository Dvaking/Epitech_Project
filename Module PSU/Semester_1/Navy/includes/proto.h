/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-marc.mendia
** File description:
** proto
*/

#ifndef PROTO_H_
    #define PROTO_H_
    #include "struct.h"

        /* all_tab/ */
    int check_player_tab(char **tab, char *attack);
    char **generate_tab(void);
    void modif_tab_hit_miss(char **tab_neutral, char *entry, int i);

        /* signal/ */
    int connection_player1(void);
    int connection_player2(int pid_enemy);
    int send_signal(char **binary_tab, char *entry, int pid);
    char *get_signal(char **binary_tab);
    char *signal_to_char(char *reception, char **binary_tab);
    void *hit_or_not(char **tab_neutral, char *entry);
    int check_loose(int boat, int pid);
    int check_win(void);

        /* display/ */
    void display_all(char **tab, char **tab_neutral);
    int display_player1(char **binary_tab, char **tab, char **tab_neutral);
    int display_player2(char **binary_tab, char **tab, char **tab_neutral,
    int pid);

        /* player_1/ */
    int player_one(char **av, char **binary_tab, all_player_t *all_player);

        /* player_2/ */
    int player_two(char **av, char **binary_tab, all_player_t *all_player);

        /* toolbox/ */
    void help(char **av);
    char **generation_map(t_player *p1, int a);
    char *take_entry(void);
    void modification_tab_check_hit_or_miss(char **tab,
    char *reception, int pid, int *boat);

        /* binary/ */
    char *letter_tab(int i);
    char *number_tab(int i);

        /* file/ */
    int check_file(char **av, int n);
    int char_to_int(char *str);

        /* libnavy/ */
    int create_i_numb(char letter);
    int create_x_numb(char letter);

        /* boat/ */
    int check_point(char **tab, int i, int count);
    int check_collision(char **tab);
    int check_line(t_player *p1);
    void create_struct_boat1(char *line, int i, t_player *p1);
    static t_player *create_5_boat(char *line, int i, t_player *p1);
    void create_struct_boat2(char *line, int i, t_player *my_player2);
    static t_player *create_5_boat(char *line, int i, t_player *my_player2);

#endif /* !PROTO_H_ */
