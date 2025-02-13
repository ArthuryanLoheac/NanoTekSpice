/*
** EPITECH PROJECT, 2025
** TestsComponentTrue.cpp
** File description:
** TestsComponentTrue.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "../include/ComponentTrue.hpp"
#include "../include/ComponentClock.hpp"
#include "../include/ComponentInput.hpp"
#include "../include/ComponentOutput.hpp"
#include "../include/Circuit.hpp"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Circuit, True_Output, .init=redirect_all_std)
{
    nts::Circuit circuit;

    circuit.addComponent(std::make_unique<nts::ComponentTrue>("true"));
    circuit.addComponent(std::make_unique<nts::ComponentOutput>("output"));
    circuit.getComponent("true")->setLink(1, *circuit.getComponent("output"), 1);
    circuit.simulate(1);
    circuit.display();
    cr_assert_stdout_eq_str("tick: 1\ninput(s):\noutput(s):\noutput: 1\n");
}

Test(Circuit, compute, .init=redirect_all_std)
{
    nts::Circuit circuit;

    cr_assert_eq(circuit.compute(1), nts::Tristate::NOTCOMPUTED);
}

Test(Circuit, SortOrderPrint, .init=redirect_all_std)
{
    nts::Circuit circuit;
    nts::ComponentInput *a;

    circuit.addComponent(std::make_unique<nts::ComponentInput>("c"));
    circuit.addComponent(std::make_unique<nts::ComponentInput>("a"));
    circuit.addComponent(std::make_unique<nts::ComponentInput>("b"));
    a = dynamic_cast<nts::ComponentInput *>(circuit.getComponent("a").get());
    a->setValue(nts::Tristate::TRUE);
    a = dynamic_cast<nts::ComponentInput *>(circuit.getComponent("b").get());
    a->setValue(nts::Tristate::FALSE);
    a = dynamic_cast<nts::ComponentInput *>(circuit.getComponent("c").get());
    a->setValue(nts::Tristate::TRUE);
    circuit.addComponent(std::make_unique<nts::ComponentOutput>("output"));
    circuit.getComponent("b")->setLink(1, *circuit.getComponent("output"), 1);
    circuit.simulate(1);
    circuit.display();
    cr_assert_stdout_eq_str("tick: 1\n"
    "input(s):\n"
    "a: 1\n"
    "b: 0\n"
    "c: 1\n"
    "output(s):\n"
    "output: 0\n");
}