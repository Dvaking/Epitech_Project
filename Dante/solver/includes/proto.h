/*
** EPITECH PROJECT, 2023
** proto.h
** File description:
** proto
*/

#ifndef PROTO_H_
    #define PROTO_H_

    #include <stdbool.h>
    #include "open_and_closed_lists.h"

    int solver(char const *path);
    char **load_file_in_mem(char const *filepath);
    char **my_spliter(char const *str, char separator);
    int distance(point_s point1, point_s point2);
    int add_node_end(box_list_s **list, box_s box);
    box_list_s *create_list(box_s box);
    box_list_s *find_lowest_f_cost_in_open(box_list_s *open);
    box_list_s *find_lowest_h_cost_in_open(box_list_s *open);
    void delete_node(box_list_s **head, box_list_s *node_deleted);
    int a_star(box_list_s *open, box_list_s *closed,
    char **map, point_s end_place);
    box_s edit_box(point_s actual_place, char **map,
    box_list_s *parent);
    int check_neighbour(box_list_s **open, char **map,
    box_list_s *current);
    box_list_s *free_node(box_list_s *list);
    int draw_road(box_list_s *closed, char **map);

#endif /* !PROTO_H_ */
