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
#include "../include/Component4081.hpp"
#include "../include/ComponentInput.hpp"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Component4081, defaultStat, .init=redirect_all_std)
{
    nts::Component4081 component4081("4081");

    component4081.setNotComputed();
    cr_assert_eq(component4081.compute(0), nts::UNDEFINED);
    component4081.setNotComputed();
    cr_assert_eq(component4081.compute(1), nts::UNDEFINED);
    component4081.setNotComputed();
    cr_assert_eq(component4081.compute(2), nts::UNDEFINED);
    component4081.setNotComputed();
    cr_assert_eq(component4081.compute(3), nts::UNDEFINED);
}

Test(Component4081, firstTrue, .init=redirect_all_std)
{
    nts::Component4081 component4081("4081");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");

    component4081.setLink(1, componentTrue1, 1);
    component4081.setLink(2, componentTrue2, 1);

    component4081.setNotComputed();
    cr_assert_eq(component4081.compute(0), nts::TRUE);
    component4081.setNotComputed();
    cr_assert_eq(component4081.compute(1), nts::UNDEFINED);
    component4081.setNotComputed();
    cr_assert_eq(component4081.compute(2), nts::UNDEFINED);
    component4081.setNotComputed();
    cr_assert_eq(component4081.compute(3), nts::UNDEFINED);
}


Test(Component4081, SecondTrue, .init=redirect_all_std)
{
    nts::Component4081 component4081("4081");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");

    component4081.setLink(5, componentTrue1, 1);
    component4081.setLink(6, componentTrue2, 1);

    component4081.setNotComputed();
    cr_assert_eq(component4081.compute(0), nts::UNDEFINED);
    component4081.setNotComputed();
    cr_assert_eq(component4081.compute(1), nts::TRUE);
    component4081.setNotComputed();
    cr_assert_eq(component4081.compute(2), nts::UNDEFINED);
    component4081.setNotComputed();
    cr_assert_eq(component4081.compute(3), nts::UNDEFINED);
}
