/*
** EPITECH PROJECT, 2025
** TestsComponent4011.cpp
** File description:
** TestsComponent4011.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "ComponentTrue.hpp"
#include "ComponentFalse.hpp"
#include "Component4011.hpp"
#include "ComponentInput.hpp"
#include "ComponentOutput.hpp"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Component4011, defaultStat, .init=redirect_all_std)
{
    nts::Component4011 component4011("4011");

    component4011.setNotComputed();
    cr_assert_eq(component4011.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4011.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4011.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4011.compute(3), nts::UNDEFINED);
}

Test(Component4011, firstTrue, .init=redirect_all_std)
{
    nts::Component4011 component4011("4011");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");

    component4011.setLink(1, componentTrue1, 1);
    component4011.setLink(2, componentTrue2, 1);

    component4011.setNotComputed();
    cr_assert_eq(component4011.compute(0), nts::FALSE);
    cr_assert_eq(component4011.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4011.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4011.compute(3), nts::UNDEFINED);
}

Test(Component4011, SecondTrue, .init=redirect_all_std)
{
    nts::Component4011 component4011("4011");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");

    component4011.setLink(5, componentTrue1, 1);
    component4011.setLink(6, componentTrue2, 1);

    component4011.setNotComputed();
    cr_assert_eq(component4011.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4011.compute(1), nts::FALSE);
    cr_assert_eq(component4011.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4011.compute(3), nts::UNDEFINED);
}
Test(Component4011, ThreeTrue, .init=redirect_all_std)
{
    nts::Component4011 component4011("4011");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");

    component4011.setLink(8, componentTrue1, 1);
    component4011.setLink(9, componentTrue2, 1);

    component4011.setNotComputed();
    cr_assert_eq(component4011.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4011.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4011.compute(2), nts::FALSE);
    cr_assert_eq(component4011.compute(3), nts::UNDEFINED);
}
Test(Component4011, FourTrue, .init=redirect_all_std)
{
    nts::Component4011 component4011("4011");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");

    component4011.setLink(13, componentTrue1, 1);
    component4011.setLink(12, componentTrue2, 1);

    component4011.setNotComputed();
    cr_assert_eq(component4011.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4011.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4011.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4011.compute(3), nts::FALSE);
}

Test(Component4011, FourTrueInverted_Sens, .init=redirect_all_std)
{
    nts::Component4011 component4011("4011");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");

    componentTrue1.setLink(1, component4011, 13);
    componentTrue2.setLink(1, component4011, 12);

    component4011.setNotComputed();
    cr_assert_eq(component4011.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4011.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4011.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4011.compute(3), nts::FALSE);
}

Test(Component4011, FourTrueMultiple, .init=redirect_all_std)
{
    nts::Component4011 component4011("4011");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");
    nts::ComponentFalse componentFalse("f1");

    componentTrue1.setLink(1, component4011, 13);
    componentTrue2.setLink(1, component4011, 12);
    component4011.setLink(1, componentTrue1, 1);
    component4011.setLink(2, componentFalse, 1);

    component4011.setNotComputed();
    cr_assert_eq(component4011.compute(0), nts::TRUE);
    cr_assert_eq(component4011.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4011.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4011.compute(3), nts::FALSE);
}

Test(Component4011, SecondTrueNotComputed, .init=redirect_all_std)
{
    nts::Component4011 component4011("4011");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");

    component4011.setLink(5, componentTrue1, 1);
    component4011.setLink(6, componentTrue2, 1);

    cr_assert_eq(component4011.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4011.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4011.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4011.compute(3), nts::UNDEFINED);
}

Test(Component4011, TwoComponentLinked, .init=redirect_all_std)
{
    nts::Component4011 component4011("4011");
    nts::Component4011 component4011_2("4011_2");
    nts::ComponentTrue componentTrue("t");

    component4011.setLink(1, componentTrue, 1);
    component4011.setLink(2, componentTrue, 1);
    component4011_2.setLink(2, componentTrue, 1);
    component4011_2.setLink(1, component4011, 3);

    component4011.setNotComputed();
    component4011_2.setNotComputed();
    cr_assert_eq(component4011_2.compute(0), nts::TRUE);
}

Test(Component4011, TwoComponentLinked_two, .init=redirect_all_std)
{
    nts::Component4011 component4011("4011");
    nts::Component4011 component4011_2("4011_2");
    nts::ComponentTrue componentTrue("t");

    component4011.setLink(5, componentTrue, 1);
    component4011.setLink(6, componentTrue, 1);
    component4011_2.setLink(2, componentTrue, 1);
    component4011_2.setLink(1, component4011, 4);

    component4011.setNotComputed();
    component4011_2.setNotComputed();
    cr_assert_eq(component4011_2.compute(0), nts::TRUE);
}

Test(Component4011, TwoComponentLinked_output, .init=redirect_all_std)
{
    nts::Component4011 component4011("4011");
    nts::Component4011 component4011_2("4011_2");
    nts::ComponentTrue componentTrue("t");
    nts::ComponentOutput componentOutput("output");

    component4011.setLink(5, componentTrue, 1);
    component4011.setLink(6, componentTrue, 1);
    component4011_2.setLink(8, componentTrue, 1);
    component4011_2.setLink(9, component4011, 4);
    componentOutput.setLink(1, component4011_2, 10);

    component4011.setNotComputed();
    component4011_2.setNotComputed();
    componentOutput.setNotComputed();
    cr_assert_eq(componentOutput.compute(0), nts::TRUE);
}

Test(Component4011, PinOut_and_PinIn_are_both_IN, .init=redirect_all_std)
{
    nts::Component4011 component4011("4011");
    nts::ComponentTrue componentTrue("t1");

    component4011.setLink(5, componentTrue, 1);
    cr_assert_throw(component4011.setLink(6, component4011, 1), nts::AComponent::Errors);
}

Test(Component4011, PinOut_and_PinIn_are_both_OUT, .init=redirect_all_std)
{
    nts::Component4011 component4011("4011");
    nts::ComponentTrue componentTrue("t1");

    component4011.setLink(5, componentTrue, 1);
    cr_assert_throw(component4011.setLink(3, component4011, 4), nts::AComponent::Errors);
}

Test(Component4011, autoLink, .init=redirect_all_std)
{
    nts::Component4011 component4011("4011");
    nts::ComponentTrue componentTrue("t1");

    component4011.setLink(5, componentTrue, 1);
    component4011.setLink(6, component4011, 4);
    component4011.setNotComputed();
    cr_assert_eq(component4011.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4011.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4011.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4011.compute(3), nts::UNDEFINED);
}

Test(Component4011, linkToNoOutput, .init=redirect_all_std)
{
    nts::Component4011 component4011("4011");
    nts::ComponentTrue componentTrue("t1");

    component4011.setLink(5, componentTrue, 1);
    cr_assert_throw(component4011.setLink(7, component4011, 4), nts::AComponent::Errors);
}