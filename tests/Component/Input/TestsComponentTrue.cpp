/*
** EPITECH PROJECT, 2025
** TestsComponentTrue.cpp
** File description:
** TestsComponentTrue.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "ComponentTrue.hpp"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(ComponentTrue, compute, .init=redirect_all_std)
{
    nts::ComponentTrue componentTrue("1");
    componentTrue.simulate(1);

    cr_assert_eq(componentTrue.compute(0), nts::TRUE);
}
