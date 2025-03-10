/*
** EPITECH PROJECT, 2025
** TestsComponentClock.cpp
** File description:
** TestsComponentClock.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "ComponentClock.hpp"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(ComponentClock, simulate, .init=redirect_all_std)
{
    nts::ComponentClock componentClock("Clock");

    componentClock.simulate(2);
    cr_assert_eq(componentClock.compute(0), nts::UNDEFINED);
    componentClock.setValue(nts::TRUE);
    componentClock.simulate(2);
    cr_assert_eq(componentClock.compute(0), nts::TRUE);
    componentClock.simulate(1);
    cr_assert_eq(componentClock.compute(0), nts::FALSE);
}

Test(ComponentClock, compute, .init=redirect_all_std)
{
    nts::ComponentClock componentClock("Clock");

    cr_assert_eq(componentClock.compute(0), nts::UNDEFINED);
}

Test(ComponentClock, setValue, .init=redirect_all_std)
{
    nts::ComponentClock componentClock("Clock");

    componentClock.setValue(nts::TRUE);
    cr_assert_eq(componentClock.compute(0), nts::TRUE);
}
