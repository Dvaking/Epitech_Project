/*
** EPITECH PROJECT, 2023
** test_criterion
** File description:
** test.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "proto.h"
#include <stdbool.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(map, map_basic) {
    char *str = "*****XX****X********XXXX\n\
XX******XX***XXXXX***XXX\n\
XX***XXXX**XXXXX****XXXX\n\
XX***XXXXXXXXXXXXXX****X\n\
*****XXXXXX****XX***XXXX\n\
XX*************XXXX*****";
    char **map = my_spliter(str, '\n');
    bool result = verify_map(map, str);
    cr_assert_eq(result, true);
}

Test(map, not_same_line_size) {
    char *str = "*****XX****X********XXXX\n\
XX******XX***XXXXX***XX\n\
XX***XXXX**XXXXX****XXXX\n\
XX***XXXXXXXXXXXXXX****X\n\
*****XXXXXX****XX***XXXX\n\
XX*************XXXX*****";
    char **map = my_spliter(str, '\n');
    bool result = verify_map(map, str);
    cr_assert_eq(result, false);
}

Test(map, invalid_char) {
    char *str = "A***XX****X********XXXX\n\
XX******XX***XXXXX***XXX\n\
XX***XXXX**XXXXX****XXXX\n\
XX***XXXXXXXXXXXXXX****X\n\
*****XXXXXX****XX***XXXX\n\
XX*************XXXX*****";
    char **map = my_spliter(str, '\n');
    bool result = verify_map(map, str);
    cr_assert_eq(result, false);
}

Test(map, litle_map) {
    char *str = "**\n**";
    char **map = my_spliter(str, '\n');
    bool result = verify_map(map, str);
    cr_assert_eq(result, true);
}

Test(map, wall_on_end) {
    char *str = "**\n*X";
    char **map = my_spliter(str, '\n');
    bool result = verify_map(map, str);
    cr_assert_eq(result, false);
}

Test(map, wall_on_entry) {
    char *str = "X*\n**";
    char **map = my_spliter(str, '\n');
    bool result = verify_map(map, str);
    cr_assert_eq(result, false);
}

Test(map, return_line) {
    char *str = "*\n**\n";
    char **map = my_spliter(str, '\n');
    bool result = verify_map(map, str);
    cr_assert_eq(result, false);
}

Test(map, null_map) {
    bool result = verify_map(NULL, NULL);
    cr_assert_eq(result, false);
}

Test(load_file, null_buffer) {
    char **result = load_file_in_mem(NULL);
    cr_assert_eq(result, NULL);
}

Test(solver_program, null_path) {
    int result = solver(NULL);
    cr_assert_eq(result, 84);
}
