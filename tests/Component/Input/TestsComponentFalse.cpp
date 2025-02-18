/*
** EPITECH PROJECT, 2025
** TestsComponentFalse.cpp
** File description:
** TestsComponentFalse.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "ComponentFalse.hpp"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(ComponentFalse, compute, .init=redirect_all_std)
{
    nts::ComponentFalse componentFalse("false");

    cr_assert_eq(componentFalse.compute(0), nts::FALSE);
}
