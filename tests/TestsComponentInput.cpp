/*
** EPITECH PROJECT, 2025
** TestsComponentInput.cpp
** File description:
** TestsComponentInput.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "../include/ComponentInput.hpp"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(ComponentInput, compute, .init=redirect_all_std)
{
    nts::ComponentInput componentInput("Input");

    cr_assert_eq(componentInput.compute(0), nts::UNDEFINED);
}

Test(ComponentInput, setValue, .init=redirect_all_std)
{
    nts::ComponentInput componentInput("Input");

    componentInput.setValue(nts::TRUE);
    cr_assert_eq(componentInput.compute(0), nts::TRUE);
}
