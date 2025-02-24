/*
** EPITECH PROJECT, 2025
** TestsComponentCircuit.cpp
** File description:
** TestsComponentCircuit.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "ComponentTrue.hpp"
#include "ComponentClock.hpp"
#include "ComponentInput.hpp"
#include "ComponentOutput.hpp"
#include "Circuit.hpp"

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
    circuit.getComponent("true").setLink(1, circuit.getComponent("output"), 1);
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

    circuit.addComponent(std::make_unique<nts::ComponentInput>("c"));
    circuit.addComponent(std::make_unique<nts::ComponentInput>("a"));
    circuit.addComponent(std::make_unique<nts::ComponentInput>("b"));
    circuit.setValue("a", nts::Tristate::TRUE);
    circuit.setValue("b", nts::Tristate::FALSE);
    circuit.setValue("c", nts::Tristate::TRUE);
    circuit.addComponent(std::make_unique<nts::ComponentOutput>("output"));
    circuit.getComponent("b").setLink(1, circuit.getComponent("output"), 1);
    circuit.simulate(1);
    circuit.display();
    cr_assert_stdout_eq_str("tick: 1\n"
        "input(s):\n"
        "a: 1\n"
        "b: 0\n"
        "c: 1\n"
        "output(s):\n"
        "output: 0\n"
    );
}

Test(Circuit, SortOrderPrint_clock, .init=redirect_all_std)
{
    nts::Circuit circuit;

    circuit.addComponent(std::make_unique<nts::ComponentClock>("c"));
    circuit.addComponent(std::make_unique<nts::ComponentClock>("a"));
    circuit.addComponent(std::make_unique<nts::ComponentClock>("b"));
    circuit.setValue("a", nts::Tristate::TRUE);
    circuit.setValue("b", nts::Tristate::FALSE);
    circuit.setValue("c", nts::Tristate::TRUE);
    circuit.addComponent(std::make_unique<nts::ComponentOutput>("output"));
    circuit.getComponent("b").setLink(1, circuit.getComponent("output"), 1);
    circuit.simulate(1);
    circuit.display();
    cr_assert_stdout_eq_str("tick: 1\n"
        "input(s):\n"
        "output(s):\n"
        "output: 1\n"
    );
}

Test(Circuit, CatchNotExisting, .init=redirect_all_std)
{
    nts::Circuit circuit;

    circuit.addComponent(std::make_unique<nts::ComponentClock>("c"));
    circuit.addComponent(std::make_unique<nts::ComponentClock>("a"));

    cr_assert_throw(circuit.setValue("b", nts::Tristate::TRUE), nts::Circuit::Errors);
}

Test(Circuit, CatchExisting, .init=redirect_all_std)
{
    nts::Circuit circuit;

    circuit.addComponent(std::make_unique<nts::ComponentClock>("a"));
    cr_assert_throw(circuit.addComponent(std::make_unique<nts::ComponentClock>("a")), nts::Circuit::Errors);

}

Test(Circuit, CatchNotExisting2, .init=redirect_all_std)
{
    nts::Circuit circuit;

    circuit.addComponent(std::make_unique<nts::ComponentClock>("c"));
    circuit.addComponent(std::make_unique<nts::ComponentClock>("a"));

    cr_assert_throw(circuit.getComponent("b"), nts::Circuit::Errors);
}