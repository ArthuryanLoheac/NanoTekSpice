/*
** EPITECH PROJECT, 2025
** TestsComponentAnd.cpp
** File description:
** TestsComponentAnd.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "ComponentTrue.hpp"
#include "ComponentFalse.hpp"
#include "ComponentAnd.hpp"
#include "ComponentInput.hpp"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(ComponentAnd, compute_and_true, .init=redirect_all_std)
{
    nts::ComponentAnd componentAnd("and");
    nts::ComponentTrue componentTrue("1");

    componentAnd.setLink(1, componentTrue, 1);
    componentAnd.setLink(2, componentTrue, 1);
    componentAnd.setNotComputed();
    cr_assert_eq(componentAnd.compute(0), nts::TRUE);
}

Test(ComponentAnd, compute_and_false, .init=redirect_all_std)
{
    nts::ComponentAnd componentAnd("and");
    nts::ComponentTrue componentTrue("1");
    nts::ComponentFalse componentFalse("1");

    componentAnd.setLink(1, componentTrue, 1);
    componentAnd.setLink(2, componentFalse, 1);
    componentAnd.setNotComputed();
    cr_assert_eq(componentAnd.compute(0), nts::FALSE);
}

Test(ComponentAnd, compute_and_UNDEFINED, .init=redirect_all_std)
{
    nts::ComponentAnd componentAnd("and");
    nts::ComponentTrue componentTrue("1");
    nts::ComponentInput componentInput("2");

    componentAnd.setLink(1, componentTrue, 1);
    componentAnd.setLink(2, componentInput, 1);
    componentAnd.setNotComputed();
    cr_assert_eq(componentAnd.compute(0), nts::UNDEFINED);
}

Test(ComponentAnd, compute_and_NoLink, .init=redirect_all_std)
{
    nts::ComponentAnd componentAnd("and");

    componentAnd.setNotComputed();
    cr_assert_eq(componentAnd.compute(0), nts::UNDEFINED);
}

Test(ComponentAnd, compute_and_AutoLink, .init=redirect_all_std)
{
    nts::ComponentAnd componentAnd("and");

    componentAnd.setLink(3, componentAnd, 2);
    componentAnd.setNotComputed();
    cr_assert_eq(componentAnd.compute(0), nts::UNDEFINED);
}

Test(ComponentAnd, compute_and_AutoLinkFalse, .init=redirect_all_std)
{
    nts::ComponentAnd componentAnd("and");
    nts::ComponentFalse componentFalse("1");

    componentAnd.setLink(3, componentAnd, 2);
    componentAnd.setLink(1, componentFalse, 1);
    componentAnd.setNotComputed();
    cr_assert_eq(componentAnd.compute(0), nts::FALSE);
}

Test(ComponentAnd, compute_and_double_AutoLink, .init=redirect_all_std)
{
    nts::ComponentAnd componentAnd("and");
    nts::ComponentAnd componentAnd2("and2");

    componentAnd.setLink(3, componentAnd2, 2);
    componentAnd2.setLink(3, componentAnd, 1);
    componentAnd2.setNotComputed();
    componentAnd.setNotComputed();
    cr_assert_eq(componentAnd.compute(0), nts::UNDEFINED);
}


Test(ComponentAnd, compute_and_double_AutoLink2, .init=redirect_all_std)
{
    nts::ComponentAnd componentAnd("and");
    nts::ComponentAnd componentAnd2("and2");

    componentAnd.setLink(3, componentAnd2, 2);
    componentAnd2.setLink(3, componentAnd, 1);
    componentAnd2.setNotComputed();
    componentAnd.setNotComputed();
    cr_assert_eq(componentAnd2.compute(0), nts::UNDEFINED);
}
