/*
** EPITECH PROJECT, 2025
** TestsComponentOr.cpp
** File description:
** TestsComponentOr.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "../include/ComponentTrue.hpp"
#include "../include/ComponentFalse.hpp"
#include "../include/ComponentOr.hpp"
#include "../include/ComponentInput.hpp"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(ComponentOr, compute_or_true, .init=redirect_all_std)
{
    nts::ComponentOr componentOr("or");
    nts::ComponentTrue componentTrue("1");

    componentOr.setLink(1, componentTrue, 1);
    componentOr.setLink(2, componentTrue, 1);
    componentOr.setNotComputed();
    cr_assert_eq(componentOr.compute(0), nts::TRUE);
}

Test(ComponentOr, compute_or_false, .init=redirect_all_std)
{
    nts::ComponentOr componentOr("or");
    nts::ComponentFalse componentFalse("1");

    componentOr.setLink(1, componentFalse, 1);
    componentOr.setLink(2, componentFalse, 1);
    componentOr.setNotComputed();
    cr_assert_eq(componentOr.compute(0), nts::FALSE);
}

Test(ComponentOr, compute_or_UNDEFINED, .init=redirect_all_std)
{
    nts::ComponentOr componentOr("or");
    nts::ComponentTrue componentTrue("1");
    nts::ComponentInput componentInput("2");

    componentOr.setLink(1, componentTrue, 1);
    componentOr.setLink(2, componentInput, 1);
    componentOr.setNotComputed();
    cr_assert_eq(componentOr.compute(0), nts::TRUE);
}

Test(ComponentOr, compute_or_NoLink, .init=redirect_all_std)
{
    nts::ComponentOr componentOr("or");

    componentOr.setNotComputed();
    cr_assert_eq(componentOr.compute(0), nts::UNDEFINED);
}

Test(ComponentOr, compute_or_AutoLink, .init=redirect_all_std)
{
    nts::ComponentOr componentOr("or");

    componentOr.setLink(3, componentOr, 2);
    componentOr.setNotComputed();
    cr_assert_eq(componentOr.compute(0), nts::UNDEFINED);
}

Test(ComponentOr, compute_or_AutoLinkFalse, .init=redirect_all_std)
{
    nts::ComponentOr componentOr("or");
    nts::ComponentFalse componentFalse("1");

    componentOr.setLink(3, componentOr, 2);
    componentOr.setLink(1, componentFalse, 1);
    componentOr.setNotComputed();
    cr_assert_eq(componentOr.compute(0), nts::UNDEFINED);
}

Test(ComponentOr, compute_or_double_AutoLink, .init=redirect_all_std)
{
    nts::ComponentOr componentOr("or");
    nts::ComponentOr componentOr2("or2");

    componentOr.setLink(3, componentOr2, 2);
    componentOr2.setLink(3, componentOr, 1);
    componentOr2.setNotComputed();
    componentOr.setNotComputed();
    cr_assert_eq(componentOr.compute(0), nts::UNDEFINED);
}

Test(ComponentOr, compute_or_double_AutoLink2, .init=redirect_all_std)
{
    nts::ComponentOr componentOr("or");
    nts::ComponentOr componentOr2("or2");

    componentOr.setLink(3, componentOr2, 2);
    componentOr2.setLink(3, componentOr, 1);
    componentOr2.setNotComputed();
    componentOr.setNotComputed();
    cr_assert_eq(componentOr2.compute(0), nts::UNDEFINED);
}
