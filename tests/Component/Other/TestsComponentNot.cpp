/*
** EPITECH PROJECT, 2025
** TestsComponentNot.cpp
** File description:
** TestsComponentNot.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "ComponentNot.hpp"
#include "ComponentTrue.hpp"
#include "ComponentFalse.hpp"
#include "ComponentInput.hpp"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(ComponentNot, compute, .init=redirect_all_std)
{
    nts::ComponentNot componentNot("not");

    cr_assert_eq(componentNot.compute(0), nts::UNDEFINED);
}

Test(ComponentNot, computeLinkedTrue, .init=redirect_all_std)
{
    nts::ComponentNot componentNot("not");
    nts::ComponentTrue componentTrue("1");
    componentTrue.simulate(1);

    componentNot.setNotComputed();
    componentTrue.setLink(1, componentNot, 1);
    cr_assert_eq(componentNot.compute(0), nts::FALSE);
}

Test(ComponentNot, computeLinkedFalse, .init=redirect_all_std)
{
    nts::ComponentNot componentNot("not");
    nts::ComponentFalse componentFalse("false");

    componentFalse.simulate(1);
    componentNot.setNotComputed();
    componentFalse.setLink(1, componentNot, 1);
    cr_assert_eq(componentNot.compute(0), nts::TRUE);
}

Test(ComponentNot, computeLinkedInput, .init=redirect_all_std)
{
    nts::ComponentNot componentNot("not");
    nts::ComponentInput componentInput("in");

    componentNot.setNotComputed();
    componentInput.setLink(1, componentNot, 1);
    cr_assert_eq(componentNot.compute(0), nts::UNDEFINED);
    componentNot.setNotComputed();
    componentInput.setValue(nts::TRUE);
    cr_assert_eq(componentNot.compute(0), nts::FALSE);
    componentNot.setNotComputed();
    componentInput.setValue(nts::FALSE);
    cr_assert_eq(componentNot.compute(0), nts::TRUE);
}

Test(ComponentNot, setNotComputed, .init=redirect_all_std)
{
    nts::ComponentNot componentNot("not");

    componentNot.setNotComputed();
    cr_assert_eq(componentNot.compute(0), nts::UNDEFINED);
}

Test(ComponentNot, PinUnexisting, .init=redirect_all_std)
{
    nts::ComponentNot componentNot("not");
    nts::ComponentInput componentInput("in");

    componentNot.setNotComputed();
    cr_assert_throw(componentInput.setLink(1, componentNot, 21), nts::AComponent::Errors);
    cr_assert_throw(componentInput.setLink(21, componentNot, 1), nts::AComponent::Errors);
}
