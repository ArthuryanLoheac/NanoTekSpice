/*
** EPITECH PROJECT, 2025
** TestsComponent4001.cpp
** File description:
** TestsComponent4001.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "ComponentTrue.hpp"
#include "ComponentFalse.hpp"
#include "Component4001.hpp"
#include "ComponentInput.hpp"
#include "ComponentOutput.hpp"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Component4001, defaultStat, .init=redirect_all_std)
{
    nts::Component4001 component4001("4001");

    component4001.setNotComputed();
    cr_assert_eq(component4001.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4001.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4001.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4001.compute(3), nts::UNDEFINED);
}

Test(Component4001, firstTrue, .init=redirect_all_std)
{
    nts::Component4001 component4001("4001");
    nts::ComponentTrue componentTrue1("1");
    componentTrue1.simulate(1);
    nts::ComponentTrue componentTrue2("1");
    componentTrue2.simulate(1);

    component4001.setLink(1, componentTrue1, 1);
    component4001.setLink(2, componentTrue2, 1);

    component4001.setNotComputed();
    cr_assert_eq(component4001.compute(0), nts::FALSE);
    cr_assert_eq(component4001.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4001.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4001.compute(3), nts::UNDEFINED);
}

Test(Component4001, SecondTrue, .init=redirect_all_std)
{
    nts::Component4001 component4001("4001");
    nts::ComponentTrue componentTrue1("1");
    componentTrue1.simulate(1);
    nts::ComponentTrue componentTrue2("1");
    componentTrue2.simulate(1);

    component4001.setLink(5, componentTrue1, 1);
    component4001.setLink(6, componentTrue2, 1);

    component4001.setNotComputed();
    cr_assert_eq(component4001.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4001.compute(1), nts::FALSE);
    cr_assert_eq(component4001.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4001.compute(3), nts::UNDEFINED);
}
Test(Component4001, ThreeTrue, .init=redirect_all_std)
{
    nts::Component4001 component4001("4001");
    nts::ComponentTrue componentTrue1("1");
    componentTrue1.simulate(1);
    nts::ComponentTrue componentTrue2("1");
    componentTrue2.simulate(1);

    component4001.setLink(8, componentTrue1, 1);
    component4001.setLink(9, componentTrue2, 1);

    component4001.setNotComputed();
    cr_assert_eq(component4001.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4001.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4001.compute(2), nts::FALSE);
    cr_assert_eq(component4001.compute(3), nts::UNDEFINED);
}
Test(Component4001, FourTrue, .init=redirect_all_std)
{
    nts::Component4001 component4001("4001");
    nts::ComponentTrue componentTrue1("1");
    componentTrue1.simulate(1);
    nts::ComponentTrue componentTrue2("1");
    componentTrue2.simulate(1);

    component4001.setLink(13, componentTrue1, 1);
    component4001.setLink(12, componentTrue2, 1);

    component4001.setNotComputed();
    cr_assert_eq(component4001.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4001.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4001.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4001.compute(3), nts::FALSE);
}

Test(Component4001, FourTrueInverted_Sens, .init=redirect_all_std)
{
    nts::Component4001 component4001("4001");
    nts::ComponentTrue componentTrue1("1");
    componentTrue1.simulate(1);
    nts::ComponentTrue componentTrue2("1");
    componentTrue2.simulate(1);

    componentTrue1.setLink(1, component4001, 13);
    componentTrue2.setLink(1, component4001, 12);

    component4001.setNotComputed();
    cr_assert_eq(component4001.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4001.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4001.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4001.compute(3), nts::FALSE);
}

Test(Component4001, FourTrueMultiple, .init=redirect_all_std)
{
    nts::Component4001 component4001("4001");
    nts::ComponentTrue componentTrue1("1");
    componentTrue1.simulate(1);
    nts::ComponentTrue componentTrue2("1");
    componentTrue2.simulate(1);
    nts::ComponentFalse componentFalse("f1");

    componentTrue1.setLink(1, component4001, 13);
    componentTrue2.setLink(1, component4001, 12);
    component4001.setLink(1, componentTrue1, 1);
    component4001.setLink(2, componentFalse, 1);

    component4001.setNotComputed();
    cr_assert_eq(component4001.compute(0), nts::FALSE);
    cr_assert_eq(component4001.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4001.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4001.compute(3), nts::FALSE);
}

Test(Component4001, SecondTrueNotComputed, .init=redirect_all_std)
{
    nts::Component4001 component4001("4001");
    nts::ComponentTrue componentTrue1("1");
    componentTrue1.simulate(1);
    nts::ComponentTrue componentTrue2("1");
    componentTrue2.simulate(1);

    component4001.setLink(5, componentTrue1, 1);
    component4001.setLink(6, componentTrue2, 1);

    cr_assert_eq(component4001.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4001.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4001.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4001.compute(3), nts::UNDEFINED);
}

Test(Component4001, TwoComponentLinked, .init=redirect_all_std)
{
    nts::Component4001 component4001("4001");
    nts::Component4001 component4001_2("4001_2");
    nts::ComponentTrue componentTrue("1");
    componentTrue.simulate(1);

    component4001.setLink(1, componentTrue, 1);
    component4001.setLink(2, componentTrue, 1);
    component4001_2.setLink(2, componentTrue, 1);
    component4001_2.setLink(1, component4001, 3);

    component4001.setNotComputed();
    component4001_2.setNotComputed();
    cr_assert_eq(component4001_2.compute(0), nts::FALSE);
}

Test(Component4001, TwoComponentLinked_two, .init=redirect_all_std)
{
    nts::Component4001 component4001("4001");
    nts::Component4001 component4001_2("4001_2");
    nts::ComponentTrue componentTrue("1");
    componentTrue.simulate(1);

    component4001.setLink(5, componentTrue, 1);
    component4001.setLink(6, componentTrue, 1);
    component4001_2.setLink(2, componentTrue, 1);
    component4001_2.setLink(1, component4001, 4);

    component4001.setNotComputed();
    component4001_2.setNotComputed();
    cr_assert_eq(component4001_2.compute(0), nts::FALSE);
}

Test(Component4001, TwoComponentLinked_output, .init=redirect_all_std)
{
    nts::Component4001 component4001("4001");
    nts::Component4001 component4001_2("4001_2");
    nts::ComponentTrue componentTrue("1");
    componentTrue.simulate(1);
    nts::ComponentOutput componentOutput("output");

    component4001.setLink(5, componentTrue, 1);
    component4001.setLink(6, componentTrue, 1);
    component4001_2.setLink(8, componentTrue, 1);
    component4001_2.setLink(9, component4001, 4);
    componentOutput.setLink(1, component4001_2, 10);

    component4001.setNotComputed();
    component4001_2.setNotComputed();
    componentOutput.setNotComputed();
    cr_assert_eq(componentOutput.compute(0), nts::FALSE);
}

Test(Component4001, PinOut_and_PinIn_are_both_IN, .init=redirect_all_std)
{
    nts::Component4001 component4001("4001");
    nts::ComponentTrue componentTrue("t1");

    component4001.setLink(5, componentTrue, 1);
    cr_assert_throw(component4001.setLink(6, component4001, 1), nts::AComponent::Errors);
}

Test(Component4001, PinOut_and_PinIn_are_both_OUT, .init=redirect_all_std)
{
    nts::Component4001 component4001("4001");
    nts::ComponentTrue componentTrue("t1");

    component4001.setLink(5, componentTrue, 1);
    cr_assert_throw(component4001.setLink(3, component4001, 4), nts::AComponent::Errors);
}

Test(Component4001, autoLink, .init=redirect_all_std)
{
    nts::Component4001 component4001("4001");
    nts::ComponentTrue componentTrue("t1");
    componentTrue.simulate(1);

    component4001.setLink(5, componentTrue, 1);
    component4001.setLink(6, component4001, 4);
    component4001.setNotComputed();
    cr_assert_eq(component4001.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4001.compute(1), nts::FALSE);
    cr_assert_eq(component4001.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4001.compute(3), nts::UNDEFINED);
}

Test(Component4001, linkToNoOutput, .init=redirect_all_std)
{
    nts::Component4001 component4001("4001");
    nts::ComponentTrue componentTrue("t1");

    component4001.setLink(5, componentTrue, 1);
    cr_assert_throw(component4001.setLink(7, component4001, 4), nts::AComponent::Errors);
}