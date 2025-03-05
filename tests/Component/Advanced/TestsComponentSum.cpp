/*
** EPITECH PROJECT, 2025
** TestsComponentSum.cpp
** File description:
** TestsComponentSum.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "ComponentTrue.hpp"
#include "ComponentFalse.hpp"
#include "ComponentSum.hpp"
#include "ComponentInput.hpp"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(ComponentSum, compute_sum_000, .init=redirect_all_std)
{
    nts::ComponentSum componentSum("and");
    nts::ComponentTrue componentTrue("1");
    nts::ComponentFalse componentFalse("2");

    componentFalse.simulate(1);
    componentSum.setLink(1, componentFalse, 1);
    componentSum.setLink(2, componentFalse, 1);
    componentSum.setLink(3, componentFalse, 1);
    componentSum.setNotComputed();
    cr_assert_eq(componentSum.compute(0), nts::FALSE);
    cr_assert_eq(componentSum.compute(1), nts::FALSE);
}

Test(ComponentSum, compute_sum_100, .init=redirect_all_std)
{
    nts::ComponentSum componentSum("and");
    nts::ComponentTrue componentTrue("1");
    nts::ComponentFalse componentFalse("2");

    componentFalse.simulate(1);
    componentSum.setLink(1, componentTrue, 1);
    componentSum.setLink(2, componentFalse, 1);
    componentSum.setLink(3, componentFalse, 1);
    componentSum.setNotComputed();
    cr_assert_eq(componentSum.compute(0), nts::FALSE);
    cr_assert_eq(componentSum.compute(1), nts::TRUE);
}

Test(ComponentSum, compute_sum_011, .init=redirect_all_std)
{
    nts::ComponentSum componentSum("and");
    nts::ComponentTrue componentTrue("1");
    nts::ComponentFalse componentFalse("2");

    componentFalse.simulate(1);
    componentSum.setLink(1, componentFalse, 1);
    componentSum.setLink(2, componentTrue, 1);
    componentSum.setLink(3, componentTrue, 1);
    componentSum.setNotComputed();
    cr_assert_eq(componentSum.compute(0), nts::TRUE);
    cr_assert_eq(componentSum.compute(1), nts::FALSE);
}

Test(ComponentSum, compute_sum_111, .init=redirect_all_std)
{
    nts::ComponentSum componentSum("and");
    nts::ComponentTrue componentTrue("1");
    nts::ComponentFalse componentFalse("2");

    componentSum.setLink(1, componentTrue, 1);
    componentSum.setLink(2, componentTrue, 1);
    componentSum.setLink(3, componentTrue, 1);
    componentSum.setNotComputed();
    cr_assert_eq(componentSum.compute(0), nts::TRUE);
    cr_assert_eq(componentSum.compute(1), nts::TRUE);
}
