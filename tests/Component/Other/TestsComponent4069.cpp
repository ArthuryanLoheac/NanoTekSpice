/*
** EPITECH PROJECT, 2025
** TestsComponent4069.cpp
** File description:
** TestsComponent4069.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "Component4069.hpp"
#include "ComponentTrue.hpp"
#include "ComponentFalse.hpp"
#include "ComponentInput.hpp"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Component4069, defaultStat, .init=redirect_all_std)
{
    nts::Component4069 component4069("4069");

    component4069.setNotComputed();
    cr_assert_eq(component4069.compute(0), nts::UNDEFINED);
    cr_assert_eq(component4069.compute(1), nts::UNDEFINED);
    cr_assert_eq(component4069.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4069.compute(3), nts::UNDEFINED);
    cr_assert_eq(component4069.compute(4), nts::UNDEFINED);
    cr_assert_eq(component4069.compute(5), nts::UNDEFINED);
}

Test(Component4069, compute, .init=redirect_all_std)
{
    nts::Component4069 component4069("4069");
    nts::ComponentInput componentInput1("input1");
    nts::ComponentInput componentInput2("input2");
    nts::ComponentInput componentInput3("input3");
    nts::ComponentInput componentInput4("input4");

    componentInput1.setLink(1, component4069, 1);
    componentInput2.setLink(1, component4069, 3);
    componentInput3.setLink(1, component4069, 9);
    componentInput4.setLink(1, component4069, 11);

    componentInput1.setValue(nts::TRUE);
    componentInput2.setValue(nts::FALSE);
    componentInput3.setValue(nts::TRUE);
    componentInput4.setValue(nts::FALSE);

    component4069.setNotComputed();
    cr_assert_eq(component4069.compute(0), nts::FALSE);
    cr_assert_eq(component4069.compute(1), nts::TRUE);
    cr_assert_eq(component4069.compute(2), nts::UNDEFINED);
    cr_assert_eq(component4069.compute(3), nts::FALSE);
    cr_assert_eq(component4069.compute(4), nts::TRUE);
    cr_assert_eq(component4069.compute(5), nts::UNDEFINED);
}

Test(Component4069, errorCase, .init=redirect_all_std)
{
    nts::Component4069 component4069("4069");
    nts::ComponentTrue componentTrue("1");
    componentTrue.simulate(1);
    nts::ComponentFalse componentFalse("false");

    cr_assert_eq(component4069.pinOutToInternPin(0), 0);
    cr_assert_eq(component4069.pinOutToInternPin(2), 2);

    component4069.setNotComputed();
    cr_assert_throw(component4069.setLink(0, component4069, 0), nts::AComponent::Errors);
}
