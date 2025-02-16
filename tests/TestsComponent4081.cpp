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
#include "../include/ComponentOutput.hpp"

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
    cr_assert_eq(component4081.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4081.compute(2), nts::UNDEFINED);
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
    cr_assert_eq(component4081.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4081.compute(2), nts::UNDEFINED);
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
    cr_assert_eq(component4081.compute(1), nts::TRUE);
    cr_assert_eq(component4081.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4081.compute(3), nts::UNDEFINED);
}
Test(Component4081, ThreeTrue, .init=redirect_all_std)
{
    nts::Component4081 component4081("4081");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");

    component4081.setLink(8, componentTrue1, 1);
    component4081.setLink(9, componentTrue2, 1);

    component4081.setNotComputed();
    cr_assert_eq(component4081.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4081.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4081.compute(2), nts::TRUE);
    cr_assert_eq(component4081.compute(3), nts::UNDEFINED);
}
Test(Component4081, FourTrue, .init=redirect_all_std)
{
    nts::Component4081 component4081("4081");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");

    component4081.setLink(13, componentTrue1, 1);
    component4081.setLink(12, componentTrue2, 1);

    component4081.setNotComputed();
    cr_assert_eq(component4081.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4081.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4081.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4081.compute(3), nts::TRUE);
}

Test(Component4081, FourTrueInverted_Sens, .init=redirect_all_std)
{
    nts::Component4081 component4081("4081");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");

    componentTrue1.setLink(1, component4081, 13);
    componentTrue2.setLink(1, component4081, 12);

    component4081.setNotComputed();
    cr_assert_eq(component4081.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4081.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4081.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4081.compute(3), nts::TRUE);
}

Test(Component4081, FourTrueMultiple, .init=redirect_all_std)
{
    nts::Component4081 component4081("4081");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");
    nts::ComponentFalse componentFalse("f1");

    componentTrue1.setLink(1, component4081, 13);
    componentTrue2.setLink(1, component4081, 12);
    component4081.setLink(1, componentTrue1, 1);
    component4081.setLink(2, componentFalse, 1);

    component4081.setNotComputed();
    cr_assert_eq(component4081.compute(0), nts::FALSE);
    cr_assert_eq(component4081.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4081.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4081.compute(3), nts::TRUE);
}

Test(Component4081, SecondTrueNotComputed, .init=redirect_all_std)
{
    nts::Component4081 component4081("4081");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");

    component4081.setLink(5, componentTrue1, 1);
    component4081.setLink(6, componentTrue2, 1);

    cr_assert_eq(component4081.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4081.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4081.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4081.compute(3), nts::UNDEFINED);
}

Test(Component4081, TwoComponentLinked, .init=redirect_all_std)
{
    nts::Component4081 component4081("4081");
    nts::Component4081 component4081_2("4081_2");
    nts::ComponentTrue componentTrue("t");

    component4081.setLink(1, componentTrue, 1);
    component4081.setLink(2, componentTrue, 1);
    component4081_2.setLink(2, componentTrue, 1);
    component4081_2.setLink(1, component4081, 3);

    component4081.setNotComputed();
    component4081_2.setNotComputed();
    cr_assert_eq(component4081_2.compute(0), nts::TRUE);
}

Test(Component4081, TwoComponentLinked_two, .init=redirect_all_std)
{
    nts::Component4081 component4081("4081");
    nts::Component4081 component4081_2("4081_2");
    nts::ComponentTrue componentTrue("t");

    component4081.setLink(5, componentTrue, 1);
    component4081.setLink(6, componentTrue, 1);
    component4081_2.setLink(2, componentTrue, 1);
    component4081_2.setLink(1, component4081, 4);

    component4081.setNotComputed();
    component4081_2.setNotComputed();
    cr_assert_eq(component4081_2.compute(0), nts::TRUE);
}

Test(Component4081, TwoComponentLinked_output, .init=redirect_all_std)
{
    nts::Component4081 component4081("4081");
    nts::Component4081 component4081_2("4081_2");
    nts::ComponentTrue componentTrue("t");
    nts::ComponentOutput componentOutput("output");

    component4081.setLink(5, componentTrue, 1);
    component4081.setLink(6, componentTrue, 1);
    component4081_2.setLink(8, componentTrue, 1);
    component4081_2.setLink(9, component4081, 4);
    componentOutput.setLink(1, component4081_2, 10);

    component4081.setNotComputed();
    component4081_2.setNotComputed();
    componentOutput.setNotComputed();
    cr_assert_eq(componentOutput.compute(0), nts::TRUE);
}

Test(Component4081, PinOut_and_PinIn_are_both_IN, .init=redirect_all_std)
{
    nts::Component4081 component4081("4081");
    nts::ComponentTrue componentTrue("t1");

    component4081.setLink(5, componentTrue, 1);
    cr_assert_throw(component4081.setLink(6, component4081, 1), nts::AComponent::Errors);
}

Test(Component4081, PinOut_and_PinIn_are_both_OUT, .init=redirect_all_std)
{
    nts::Component4081 component4081("4081");
    nts::ComponentTrue componentTrue("t1");

    component4081.setLink(5, componentTrue, 1);
    cr_assert_throw(component4081.setLink(3, component4081, 4), nts::AComponent::Errors);
}

Test(Component4081, autoLink, .init=redirect_all_std)
{
    nts::Component4081 component4081("4081");
    nts::ComponentTrue componentTrue("t1");

    component4081.setLink(5, componentTrue, 1);
    component4081.setLink(6, component4081, 4);
    component4081.setNotComputed();
    cr_assert_eq(component4081.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4081.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4081.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4081.compute(3), nts::UNDEFINED);
}

Test(Component4081, linkToNoOutput, .init=redirect_all_std)
{
    nts::Component4081 component4081("4081");
    nts::ComponentTrue componentTrue("t1");

    component4081.setLink(5, componentTrue, 1);
    cr_assert_throw(component4081.setLink(7, component4081, 4), nts::AComponent::Errors);
}