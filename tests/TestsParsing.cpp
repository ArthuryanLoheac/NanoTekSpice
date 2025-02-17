/*
** EPITECH PROJECT, 2025
** TestsComponentTrue.cpp
** File description:
** TestsComponentTrue.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/Parsing.hpp"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(parseFile, valid, .init=redirect_all_std)
{
    cr_assert_eq(parseFile("../tests/Exemple/nts_single/and.nts"), 0);
}

Test(parseFile, Invalid, .init=redirect_all_std)
{
    cr_assert_throw(parseFile("invalid_file"), std::invalid_argument);
}
