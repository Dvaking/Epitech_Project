/*
** EPITECH PROJECT, 2023
** test_criterion
** File description:
** test.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "proto_generator.h"
#include "proto_lib_generator.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(check_argc_argv, test_argv, .init = redirect_all_std) {
    char **tab = tab_generator(2, 1);
    int return_value = check_argc_argv(2, tab);
    cr_assert_eq(return_value, -1);
}

// Passes if Expression is true
//cr_assert ( Expression , FormatString , ...) ;

// Passes if Expression is false
//cr_assert_not ( Expression , FormatString , ...) ;

// Passes if Actual == Expected
//cr_assert_eq ( Actual , Expected , FormatString , ...) ;

// Passes if Actual != Expected
//cr_assert_neq ( Actual , Expected , FormatString , ...) ;
