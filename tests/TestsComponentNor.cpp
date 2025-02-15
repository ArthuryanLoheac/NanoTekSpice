/*
** EPITECH PROJECT, 2025
** TestsComponentNor.cpp
** File description:
** TestsComponentNor.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "../include/ComponentTrue.hpp"
#include "../include/ComponentFalse.hpp"
#include "../include/ComponentNor.hpp"
#include "../include/ComponentInput.hpp"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(ComponentNor, compute_nor_true, .init=redirect_all_std)
{
    nts::ComponentNor componentNor("nor");
    nts::ComponentFalse componentFalse("1");

    componentNor.setLink(1, componentFalse, 1);
    componentNor.setLink(2, componentFalse, 1);
    componentNor.setNotComputed();
    cr_assert_eq(componentNor.compute(0), nts::TRUE);
}

Test(ComponentNor, compute_nor_false, .init=redirect_all_std)
{
    nts::ComponentNor componentNor("nor");
    nts::ComponentTrue componentTrue("1");

    componentNor.setLink(1, componentTrue, 1);
    componentNor.setLink(2, componentTrue, 1);
    componentNor.setNotComputed();
    cr_assert_eq(componentNor.compute(0), nts::FALSE);
}

Test(ComponentNor, compute_nor_UNDEFINED, .init=redirect_all_std)
{
    nts::ComponentNor componentNor("nor");
    nts::ComponentTrue componentTrue("1");
    nts::ComponentInput componentInput("2");

    componentNor.setLink(1, componentTrue, 1);
    componentNor.setLink(2, componentInput, 1);
    componentNor.setNotComputed();
    cr_assert_eq(componentNor.compute(0), nts::FALSE);
}

Test(ComponentNor, compute_nor_NoLink, .init=redirect_all_std)
{
    nts::ComponentNor componentNor("nor");

    componentNor.setNotComputed();
    cr_assert_eq(componentNor.compute(0), nts::UNDEFINED);
}

Test(ComponentNor, compute_nor_AutoLink, .init=redirect_all_std)
{
    nts::ComponentNor componentNor("nor");

    componentNor.setLink(3, componentNor, 2);
    componentNor.setNotComputed();
    cr_assert_eq(componentNor.compute(0), nts::UNDEFINED);
}

Test(ComponentNor, compute_nor_AutoLinkFalse, .init=redirect_all_std)
{
    nts::ComponentNor componentNor("nor");
    nts::ComponentFalse componentFalse("1");

    componentNor.setLink(3, componentNor, 2);
    componentNor.setLink(1, componentFalse, 1);
    componentNor.setNotComputed();
    cr_assert_eq(componentNor.compute(0), nts::UNDEFINED);
}

Test(ComponentNor, compute_nor_double_AutoLink, .init=redirect_all_std)
{
    nts::ComponentNor componentNor("nor");
    nts::ComponentNor componentNor2("nor2");

    componentNor.setLink(3, componentNor2, 2);
    componentNor2.setLink(3, componentNor, 1);
    componentNor2.setNotComputed();
    componentNor.setNotComputed();
    cr_assert_eq(componentNor.compute(0), nts::UNDEFINED);
}

Test(ComponentNor, compute_nor_double_AutoLink2, .init=redirect_all_std)
{
    nts::ComponentNor componentNor("nor");
    nts::ComponentNor componentNor2("nor2");

    componentNor.setLink(3, componentNor2, 2);
    componentNor2.setLink(3, componentNor, 1);
    componentNor2.setNotComputed();
    componentNor.setNotComputed();
    cr_assert_eq(componentNor2.compute(0), nts::UNDEFINED);
}
