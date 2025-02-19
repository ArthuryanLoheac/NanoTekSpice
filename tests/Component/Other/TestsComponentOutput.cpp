/*
** EPITECH PROJECT, 2025
** TestsComponentOutput.cpp
** File description:
** TestsComponentOutput.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "ComponentOutput.hpp"
#include "ComponentTrue.hpp"
#include "ComponentInput.hpp"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(ComponentOutput, compute, .init=redirect_all_std)
{
    nts::ComponentOutput componentOutput("out");

    cr_assert_eq(componentOutput.compute(0), nts::UNDEFINED);
}

Test(ComponentOutput, computeLinkedTrue, .init=redirect_all_std)
{
    nts::ComponentOutput componentOutput("out");
    nts::ComponentTrue componentTrue("true");

    componentOutput.setNotComputed();
    componentTrue.setLink(1, componentOutput, 1);
    cr_assert_eq(componentOutput.compute(0), nts::TRUE);
}

Test(ComponentOutput, componentInput, .init=redirect_all_std)
{
    nts::ComponentOutput componentOutput("out");
    nts::ComponentInput componentInput("in");

    componentOutput.setNotComputed();
    componentInput.setLink(1, componentOutput, 1);
    cr_assert_eq(componentOutput.compute(0), nts::UNDEFINED);
    componentOutput.setNotComputed();
    componentInput.setValue(nts::TRUE);
    cr_assert_eq(componentOutput.compute(0), nts::TRUE);
}

Test(ComponentOutput, setNotComputed, .init=redirect_all_std)
{
    nts::ComponentOutput componentOutput("out");

    componentOutput.setNotComputed();
    cr_assert_eq(componentOutput.compute(0), nts::UNDEFINED);
}

Test(ComponentOutput, AlreadyLinked, .init=redirect_all_std)
{
    nts::ComponentOutput componentOutput("out");
    nts::ComponentInput componentInput("in");
    nts::ComponentInput componentInput2("in2");

    componentOutput.setNotComputed();
    componentInput.setLink(1, componentOutput, 1);
    cr_assert_throw(componentInput2.setLink(1, componentOutput, 1), nts::AComponent::Errors);
    cr_assert_throw(componentOutput.setLink(1, componentInput2, 1), nts::AComponent::Errors);
}

Test(ComponentOutput, PinUnexisting, .init=redirect_all_std)
{
    nts::ComponentOutput componentOutput("out");
    nts::ComponentInput componentInput("in");

    componentOutput.setNotComputed();
    cr_assert_throw(componentInput.setLink(1, componentOutput, 21), nts::AComponent::Errors);
    cr_assert_throw(componentInput.setLink(21, componentOutput, 1), nts::AComponent::Errors);
}