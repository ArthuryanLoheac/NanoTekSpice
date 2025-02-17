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
#include "../include/Component4030.hpp"
#include "../include/ComponentInput.hpp"
#include "../include/ComponentOutput.hpp"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Component4030, defaultStat, .init=redirect_all_std)
{
    nts::Component4030 component4030("4030");

    component4030.setNotComputed();
    cr_assert_eq(component4030.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4030.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4030.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4030.compute(3), nts::UNDEFINED);
}

Test(Component4030, firstTrue, .init=redirect_all_std)
{
    nts::Component4030 component4030("4030");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");

    component4030.setLink(1, componentTrue1, 1);
    component4030.setLink(2, componentTrue2, 1);

    component4030.setNotComputed();
    cr_assert_eq(component4030.compute(0), nts::FALSE);
    cr_assert_eq(component4030.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4030.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4030.compute(3), nts::UNDEFINED);
}

Test(Component4030, SecondTrue, .init=redirect_all_std)
{
    nts::Component4030 component4030("4030");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");

    component4030.setLink(5, componentTrue1, 1);
    component4030.setLink(6, componentTrue2, 1);

    component4030.setNotComputed();
    cr_assert_eq(component4030.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4030.compute(1), nts::FALSE);
    cr_assert_eq(component4030.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4030.compute(3), nts::UNDEFINED);
}
Test(Component4030, ThreeTrue, .init=redirect_all_std)
{
    nts::Component4030 component4030("4030");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");

    component4030.setLink(8, componentTrue1, 1);
    component4030.setLink(9, componentTrue2, 1);

    component4030.setNotComputed();
    cr_assert_eq(component4030.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4030.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4030.compute(2), nts::FALSE);
    cr_assert_eq(component4030.compute(3), nts::UNDEFINED);
}
Test(Component4030, FourTrue, .init=redirect_all_std)
{
    nts::Component4030 component4030("4030");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");

    component4030.setLink(13, componentTrue1, 1);
    component4030.setLink(12, componentTrue2, 1);

    component4030.setNotComputed();
    cr_assert_eq(component4030.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4030.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4030.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4030.compute(3), nts::FALSE);
}

Test(Component4030, FourTrueInverted_Sens, .init=redirect_all_std)
{
    nts::Component4030 component4030("4030");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");

    componentTrue1.setLink(1, component4030, 13);
    componentTrue2.setLink(1, component4030, 12);

    component4030.setNotComputed();
    cr_assert_eq(component4030.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4030.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4030.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4030.compute(3), nts::FALSE);
}

Test(Component4030, FourTrueMultiple, .init=redirect_all_std)
{
    nts::Component4030 component4030("4030");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");
    nts::ComponentFalse componentFalse("f1");

    componentTrue1.setLink(1, component4030, 13);
    componentTrue2.setLink(1, component4030, 12);
    component4030.setLink(1, componentTrue1, 1);
    component4030.setLink(2, componentFalse, 1);

    component4030.setNotComputed();
    cr_assert_eq(component4030.compute(0), nts::TRUE);
    cr_assert_eq(component4030.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4030.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4030.compute(3), nts::FALSE);
}

Test(Component4030, SecondTrueNotComputed, .init=redirect_all_std)
{
    nts::Component4030 component4030("4030");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");

    component4030.setLink(5, componentTrue1, 1);
    component4030.setLink(6, componentTrue2, 1);

    cr_assert_eq(component4030.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4030.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4030.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4030.compute(3), nts::UNDEFINED);
}

Test(Component4030, TwoComponentLinked, .init=redirect_all_std)
{
    nts::Component4030 component4030("4030");
    nts::Component4030 component4030_2("4030_2");
    nts::ComponentTrue componentTrue("t");

    component4030.setLink(1, componentTrue, 1);
    component4030.setLink(2, componentTrue, 1);
    component4030_2.setLink(2, componentTrue, 1);
    component4030_2.setLink(1, component4030, 3);

    component4030.setNotComputed();
    component4030_2.setNotComputed();
    cr_assert_eq(component4030_2.compute(0), nts::TRUE);
}

Test(Component4030, TwoComponentLinked_two, .init=redirect_all_std)
{
    nts::Component4030 component4030("4030");
    nts::Component4030 component4030_2("4030_2");
    nts::ComponentTrue componentTrue("t");

    component4030.setLink(5, componentTrue, 1);
    component4030.setLink(6, componentTrue, 1);
    component4030_2.setLink(2, componentTrue, 1);
    component4030_2.setLink(1, component4030, 4);

    component4030.setNotComputed();
    component4030_2.setNotComputed();
    cr_assert_eq(component4030_2.compute(0), nts::TRUE);
}

Test(Component4030, TwoComponentLinked_output, .init=redirect_all_std)
{
    nts::Component4030 component4030("4030");
    nts::Component4030 component4030_2("4030_2");
    nts::ComponentTrue componentTrue("t");
    nts::ComponentOutput componentOutput("output");

    component4030.setLink(5, componentTrue, 1);
    component4030.setLink(6, componentTrue, 1);
    component4030_2.setLink(8, componentTrue, 1);
    component4030_2.setLink(9, component4030, 4);
    componentOutput.setLink(1, component4030_2, 10);

    component4030.setNotComputed();
    component4030_2.setNotComputed();
    componentOutput.setNotComputed();
    cr_assert_eq(componentOutput.compute(0), nts::TRUE);
}

Test(Component4030, PinOut_and_PinIn_are_both_IN, .init=redirect_all_std)
{
    nts::Component4030 component4030("4030");
    nts::ComponentTrue componentTrue("t1");

    component4030.setLink(5, componentTrue, 1);
    cr_assert_throw(component4030.setLink(6, component4030, 1), nts::AComponent::Errors);
}

Test(Component4030, PinOut_and_PinIn_are_both_OUT, .init=redirect_all_std)
{
    nts::Component4030 component4030("4030");
    nts::ComponentTrue componentTrue("t1");

    component4030.setLink(5, componentTrue, 1);
    cr_assert_throw(component4030.setLink(3, component4030, 4), nts::AComponent::Errors);
}

Test(Component4030, autoLink, .init=redirect_all_std)
{
    nts::Component4030 component4030("4030");
    nts::ComponentTrue componentTrue("t1");

    component4030.setLink(5, componentTrue, 1);
    component4030.setLink(6, component4030, 4);
    component4030.setNotComputed();
    cr_assert_eq(component4030.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4030.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4030.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4030.compute(3), nts::UNDEFINED);
}

Test(Component4030, linkToNoOutput, .init=redirect_all_std)
{
    nts::Component4030 component4030("4030");
    nts::ComponentTrue componentTrue("t1");

    component4030.setLink(5, componentTrue, 1);
    cr_assert_throw(component4030.setLink(7, component4030, 4), nts::AComponent::Errors);
}