/*
** EPITECH PROJECT, 2025
** TestsComponentTrue.cpp
** File description:
** TestsComponentTrue.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "../include/ComponentOutput.hpp"
#include "../include/ComponentTrue.hpp"
#include "../include/ComponentInput.hpp"

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
    componentOutput.setLink(1, componentTrue, 1);
    cr_assert_eq(componentOutput.compute(0), nts::TRUE);
}

Test(ComponentOutput, componentInput, .init=redirect_all_std)
{
    nts::ComponentOutput componentOutput("out");
    nts::ComponentInput componentInput("in");

    componentOutput.setNotComputed();
    componentOutput.setLink(1, componentInput, 1);
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