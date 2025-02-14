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
#include "../include/ComponentNand.hpp"
#include "../include/ComponentInput.hpp"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(ComponentNand, compute_and_true, .init=redirect_all_std)
{
    nts::ComponentNand componentNand("and");
    nts::ComponentTrue componentTrue("1");

    componentNand.setLink(1, componentTrue, 1);
    componentNand.setLink(2, componentTrue, 1);
    componentNand.setNotComputed();
    cr_assert_eq(componentNand.compute(0), nts::FALSE);
}

Test(ComponentNand, compute_and_false, .init=redirect_all_std)
{
    nts::ComponentNand componentNand("and");
    nts::ComponentTrue componentTrue("1");
    nts::ComponentFalse componentFalse("1");

    componentNand.setLink(1, componentTrue, 1);
    componentNand.setLink(2, componentFalse, 1);
    componentNand.setNotComputed();
    cr_assert_eq(componentNand.compute(0), nts::TRUE);
}

Test(ComponentNand, compute_and_UNDEFINED, .init=redirect_all_std)
{
    nts::ComponentNand componentNand("and");
    nts::ComponentTrue componentTrue("1");
    nts::ComponentInput componentInput("2");

    componentNand.setLink(1, componentTrue, 1);
    componentNand.setLink(2, componentInput, 1);
    componentNand.setNotComputed();
    cr_assert_eq(componentNand.compute(0), nts::UNDEFINED);
}

Test(ComponentNand, compute_and_NoLink, .init=redirect_all_std)
{
    nts::ComponentNand componentNand("and");

    componentNand.setNotComputed();
    cr_assert_eq(componentNand.compute(0), nts::UNDEFINED);
}

Test(ComponentNand, compute_and_AutoLink, .init=redirect_all_std)
{
    nts::ComponentNand componentNand("and");

    componentNand.setLink(3, componentNand, 2);
    componentNand.setNotComputed();
    cr_assert_eq(componentNand.compute(0), nts::UNDEFINED);
}

Test(ComponentNand, compute_and_AutoLinkFalse, .init=redirect_all_std)
{
    nts::ComponentNand componentNand("and");
    nts::ComponentFalse componentFalse("1");

    componentNand.setLink(3, componentNand, 2);
    componentNand.setLink(1, componentFalse, 1);
    componentNand.setNotComputed();
    cr_assert_eq(componentNand.compute(0), nts::TRUE);
}

Test(ComponentNand, compute_and_double_AutoLink, .init=redirect_all_std)
{
    nts::ComponentNand componentNand("and");
    nts::ComponentNand componentNand2("and2");

    componentNand.setLink(3, componentNand2, 2);
    componentNand2.setLink(3, componentNand, 1);
    componentNand2.setNotComputed();
    componentNand.setNotComputed();
    cr_assert_eq(componentNand.compute(0), nts::UNDEFINED);
}


Test(ComponentNand, compute_and_double_AutoLink2, .init=redirect_all_std)
{
    nts::ComponentNand componentNand("and");
    nts::ComponentNand componentNand2("and2");

    componentNand.setLink(3, componentNand2, 2);
    componentNand2.setLink(3, componentNand, 1);
    componentNand2.setNotComputed();
    componentNand.setNotComputed();
    cr_assert_eq(componentNand2.compute(0), nts::UNDEFINED);
}
