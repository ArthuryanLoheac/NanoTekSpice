/*
** EPITECH PROJECT, 2025
** TestsComponentFactory.cpp
** File description:
** TestsComponentFactory.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "ComponentFactory.hpp"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Factory, createComponent, .init = redirect_all_std)
{
    nts::ComponentFactory factory;

    cr_assert_eq(factory.createComponent("input")->getName(), "input");
    cr_assert_eq(factory.createComponent("output")->getName(), "output");
    cr_assert_eq(factory.createComponent("true")->getName(), "true");
    cr_assert_eq(factory.createComponent("false")->getName(), "false");
    cr_assert_eq(factory.createComponent("clock")->getName(), "clock");
    cr_assert_eq(factory.createComponent("and")->getName(), "and");
    cr_assert_eq(factory.createComponent("or")->getName(), "or");
    cr_assert_eq(factory.createComponent("xor")->getName(), "xor");
    cr_assert_eq(factory.createComponent("not")->getName(), "not");
    cr_assert_eq(factory.createComponent("4001")->getName(), "4001");
    cr_assert_eq(factory.createComponent("4011")->getName(), "4011");
    cr_assert_eq(factory.createComponent("4030")->getName(), "4030");
    cr_assert_eq(factory.createComponent("4071")->getName(), "4071");
    cr_assert_eq(factory.createComponent("4081")->getName(), "4081");
    // cr_assert_eq(factory.createComponent("4069")->getName(), "4069");
}

Test(Factory, createComponent_invalid, .init = redirect_all_std)
{
    nts::ComponentFactory factory;

    cr_assert_throw(factory.createComponent("invalid"), std::invalid_argument);
}
