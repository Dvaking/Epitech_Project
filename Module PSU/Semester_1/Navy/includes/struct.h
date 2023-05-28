/*
** EPITECH PROJECT, 2023
** struct
** File description:
** struct
*/

#ifndef MYSTRUCT_
    #define MYSTRUCT_
    #include <signal.h>

    typedef struct player t_player;
    struct player {
        int x2;
        int i2;
        int x2f;
        int i2f;
        int x3;
        int i3;
        int x3f;
        int i3f;
        int x4;
        int i4;
        int x4f;
        int i4f;
        int x5;
        int i5;
        int x5f;
        int i5f;
    };
    typedef struct all_player {
        t_player *p1;
        t_player *p2;
    } all_player_t;

    typedef struct variable_global {
        __pid_t pid_player2;
        int I;
        int hit_or_not;
        int win_or_not;
    } variable_global_t;

#endif /* MYSTRUCT */
