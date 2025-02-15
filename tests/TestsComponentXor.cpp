/*
** EPITECH PROJECT, 2025
** TestsComponentTrue.cpp
** File description:
** TestsComponentTrue.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "../include/ComponentTrue.hpp"
#include "../include/ComponentFalse.hpp"
#include "../include/ComponentXor.hpp"
#include "../include/ComponentInput.hpp"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(ComponentXor, compute_and_true, .init=redirect_all_std)
{
    nts::ComponentXor componentXor("and");
    nts::ComponentTrue componentTrue("1");

    componentXor.setLink(1, componentTrue, 1);
    componentXor.setLink(2, componentTrue, 1);
    componentXor.setNotComputed();
    cr_assert_eq(componentXor.compute(0), nts::FALSE);
}

Test(ComponentXor, compute_and_false, .init=redirect_all_std)
{
    nts::ComponentXor componentXor("and");
    nts::ComponentTrue componentTrue("1");
    nts::ComponentFalse componentFalse("1");

    componentXor.setLink(1, componentTrue, 1);
    componentXor.setLink(2, componentFalse, 1);
    componentXor.setNotComputed();
    cr_assert_eq(componentXor.compute(0), nts::TRUE);
}

Test(ComponentXor, compute_and_UNDEFINED, .init=redirect_all_std)
{
    nts::ComponentXor componentXor("and");
    nts::ComponentTrue componentTrue("1");
    nts::ComponentInput componentInput("2");

    componentXor.setLink(1, componentTrue, 1);
    componentXor.setLink(2, componentInput, 1);
    componentXor.setNotComputed();
    cr_assert_eq(componentXor.compute(0), nts::UNDEFINED);
}

Test(ComponentXor, compute_and_NoLink, .init=redirect_all_std)
{
    nts::ComponentXor componentXor("and");

    componentXor.setNotComputed();
    cr_assert_eq(componentXor.compute(0), nts::UNDEFINED);
}

Test(ComponentXor, compute_and_AutoLink, .init=redirect_all_std)
{
    nts::ComponentXor componentXor("and");

    componentXor.setLink(3, componentXor, 2);
    componentXor.setNotComputed();
    cr_assert_eq(componentXor.compute(0), nts::UNDEFINED);
}

Test(ComponentXor, compute_and_AutoLinkFalse, .init=redirect_all_std)
{
    nts::ComponentXor componentXor("and");
    nts::ComponentFalse componentFalse("1");

    componentXor.setLink(3, componentXor, 2);
    componentXor.setLink(1, componentFalse, 1);
    componentXor.setNotComputed();

    cr_assert_eq(componentXor.compute(0), nts::UNDEFINED);
}

Test(ComponentXor, compute_and_double_AutoLink, .init=redirect_all_std)
{
    nts::ComponentXor componentXor("and");
    nts::ComponentXor componentXor2("and2");

    componentXor.setLink(3, componentXor2, 2);
    componentXor2.setLink(3, componentXor, 1);
    componentXor2.setNotComputed();
    componentXor.setNotComputed();
    cr_assert_eq(componentXor.compute(0), nts::UNDEFINED);
}


Test(ComponentXor, compute_and_double_AutoLink2, .init=redirect_all_std)
{
    nts::ComponentXor componentXor("and");
    nts::ComponentXor componentXor2("and2");

    componentXor.setLink(3, componentXor2, 2);
    componentXor2.setLink(3, componentXor, 1);
    componentXor2.setNotComputed();
    componentXor.setNotComputed();
    cr_assert_eq(componentXor2.compute(0), nts::UNDEFINED);
}
