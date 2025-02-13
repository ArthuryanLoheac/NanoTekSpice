/*
** EPITECH PROJECT, 2025
** TestsComponentTrue.cpp
** File description:
** TestsComponentTrue.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "../include/ComponentTrue.hpp"
#include "../include/ComponentOutput.hpp"
#include "../include/Circuit.hpp"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Circuit, compute, .init=redirect_all_std)
{
    nts::Circuit circuit;

    circuit.addComponent(std::make_unique<nts::ComponentTrue>("true"));
    circuit.addComponent(std::make_unique<nts::ComponentOutput>("output"));
    circuit.getComponent("true").setLink(1, circuit.getComponent("output"), 1);
    circuit.simulate(1);
    circuit.display();
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\noutput(s):\noutput: 1\n");
}
